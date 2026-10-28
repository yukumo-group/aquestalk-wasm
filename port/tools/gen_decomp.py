#!/usr/bin/env python3
"""Generate a C translation unit from Ghidra's decompiled output.

The output is a (close to) mechanical translation of the original
libAqKanji2Koe.so machine code.  It is *not* an emulator: every function is
real C code that clang compiles to native machine code / wasm.
"""
import re
import sys
import os

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
DECOMP = os.path.join(ROOT, 'decomp', 'all.c')
DATATSV = os.path.join(ROOT, 'decomp', 'data.tsv')
OUT = os.path.join(ROOT, 'port', 'src', 'decomp.c')

# Functions provided by hand (api.cpp / shim.c / loader).
API_EXCLUDE = {
    0x109620,  # AqKanji2Koe_Release
    0x109690,  # AqKanji2Koe_Create_Ptr
    0x109740,  # AqKanji2Koe_Convert
    0x109a70,  # AqKanji2Koe_SetDevKey
    0x109a80,  # file loader
    0x109bc0,  # AqKanji2Koe_Create
    0x10a140,  # AqKanji2Koe_ConvRoman
}
THUNKS = {
    0x10d3a0: 'FUN_0010b040',
    0x10d3b0: 'FUN_0010b060',
    0x10d3c0: 'FUN_0010b080',
}
# Called from normal code but decompiled in the cold section.
STUB_EXCLUDE = {0x1088f6, 0x1089f4}


def read_funcs(path):
    src = open(path, encoding='utf-8').read()
    parts = re.split(r'//===== (.*?) @ ([0-9a-f]+) size=(\d+) =====\n', src)
    funcs = []
    for i in range(1, len(parts), 4):
        funcs.append({
            'name': parts[i],
            'addr': int(parts[i + 1], 16),
            'size': int(parts[i + 2]),
            'body': parts[i + 3],
        })
    return funcs


def load_datatypes(path):
    types = {}
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        addr, name, typ, length = line.split('\t')
        types[name] = (typ, int(length))
    return types


def split_sig(body):
    idx = body.find('\n{')
    if idx < 0:
        raise RuntimeError('no body')
    return body[:idx].strip()


def normalize_common(text):
    # names
    text = text.replace('std::__cxx11::string::', 'aqstr_')
    text = text.replace('std::__throw_length_error', 'aq_throw_length_error')
    text = text.replace('std::__throw_logic_error', 'aq_throw_logic_error')
    text = text.replace('std::__throw_out_of_range_fmt', 'aq_throw_out_of_range_fmt')
    text = text.replace('std::exception::~exception', 'aq_exception_dtor')
    text = re.sub(r'\boperator_new__\b', 'aq_new_array', text)
    text = re.sub(r'\boperator_delete__\b', 'aq_delete_array', text)
    text = re.sub(r'\boperator_new___\b', 'aq_new_array', text)
    text = re.sub(r'\boperator_delete___\b', 'aq_delete_array', text)
    # stack canary access
    text = re.sub(r'^\s*long in_FS_OFFSET;\s*$', '', text, flags=re.M)
    # 16-byte zero "compound literal" assignments
    text = re.sub(r'^(\s*)([^\n;]+?) = \(undefined1\s+\[16\]\)0x0;\s*$',
                  lambda m: m.group(1) + 'memset((void *)(%s), 0, 16);' % m.group(2).strip(),
                  text, flags=re.M)
    # bit fields
    def bf(m):
        base, off, width = m.group(1), int(m.group(2)), int(m.group(3))
        if width == 7:
            return '((unsigned long long)(%s) >> 8)' % base
        if width == 6:
            return '((unsigned long long)(%s) >> 16)' % base
        typ = {1: 'undefined1', 2: 'undefined2', 4: 'undefined4', 8: 'undefined8'}[width]
        return '(*(%s *)((char *)&(%s) + %d))' % (typ, base, off)
    text = re.sub(r'([A-Za-z_][A-Za-z0-9_]*(?:\[[^\]]*\])?)\._(\d+)_(\d+)_', bf, text)
    # SSE pshuflw(...,0x1b) -> helper
    text = re.sub(r'\bundefined1 (auVar\d+) \[16\];', r'aq_v16 \1;', text)
    text = re.sub(r'(\w+) = pshuflw\(\1,\1,0x1b\);', r'\1 = aq_pshuflw(\1);', text)
    return text


def fix_string_calls(text, fname):
    # _M_replace_aux: Ghidra lost the last (char) argument.
    if fname == 'FUN_00109e90':
        text = text.replace("aqstr_replace_aux((ulong)&local_68,0,0,'\\x01')",
                            "aqstr_replace_aux((ulong)&local_68,0,0,1,(char)bVar1)")
    if fname == 'FUN_0010b970':
        text = text.replace("aqstr_replace_aux((ulong)param_2,0,param_2[1],'\\x01')",
                            "aqstr_replace_aux((ulong)param_2,0,param_2[1],1,'#')")
        text = text.replace("aqstr_replace_aux((ulong)param_2,uVar20,0,'\\x01')",
                            "aqstr_replace_aux((ulong)param_2,uVar20,0,1,'*')")
    if fname == 'FUN_0010c520':
        text = text.replace("aqstr_replace_aux((ulong)&local_78,local_70,0,'\\x01')",
                            "aqstr_replace_aux((ulong)&local_78,((AqStr *)&local_78)->len,0,1,(char)(sVar2 + 0x20))")
    # _M_mutate: r8 (len2) was 1 in every call site.
    text = re.sub(r'aqstr_mutate\(([^;]*?),0\)', r'aqstr_mutate(\1,1)', text)
    # stale cached length in FUN_0010d4a0
    if fname == 'FUN_0010d4a0':
        text = text.replace('uVar5 = local_60 & 0xffffffff;',
                            'uVar5 = ((AqStr *)&local_68)->len;')
    return text


def fix_u16string(fname, body):
    """The decompiler split the 8-byte capacity field of a u16string into
    `undefined2 local_X; undefined6 uStack_Y;`.  Make it a proper union."""
    if fname == 'FUN_0010ebc0':
        body = body.replace('  undefined2 local_58;\n  undefined6 uStack_56;\n',
                            '  union { undefined2 lo; undefined8 cap; undefined2 buf[8]; } aq_s;\n')
        body = re.sub(r'\bCONCAT62\(uStack_56,local_58\)', 'aq_s.cap', body)
        body = re.sub(r'\blocal_58\b', 'aq_s.lo', body)
        body = body.replace('aq_s.aq_s', 'aq_s')  # safety
    if fname == 'FUN_0010ef60':
        body = body.replace('  undefined2 local_78;\n  undefined6 uStack_76;\n',
                            '  union { undefined2 lo; undefined8 cap; undefined2 buf[8]; } aq_s;\n')
        body = re.sub(r'\bCONCAT62\(uStack_76,local_78\)', 'aq_s.cap', body)
        body = re.sub(r'\blocal_78\b', 'aq_s.lo', body)
        body = body.replace('CONCAT62((int6)uVar18,0x3c)', '((uVar18 << 16) | 0x3c)')
    return body


def main():
    funcs = read_funcs(DECOMP)
    datatypes = load_datatypes(DATATSV)

    out_funcs = []
    excluded_called = set()
    for f in funcs:
        a = f['addr']
        if a < 0x108540 or (0x108540 <= a < 0x109240) or a >= 0x122000 or a in API_EXCLUDE or a in STUB_EXCLUDE:
            continue
        if a in THUNKS:
            continue
        body = f['body']
        # redirect thunk calls
        for addr, target in THUNKS.items():
            body = body.replace('thunk_%s(' % target, target + '(')
        body = normalize_common(body)
        body = fix_u16string(f['name'], body)
        body = fix_string_calls(body, f['name'])
        # body must end with the closing brace already
        out_funcs.append((f['name'], body))

    # collect data symbols used
    alltext = '\n'.join(b for _, b in out_funcs)
    used_syms = set(re.findall(r'\b(DAT_[0-9a-f]+|_DAT_[0-9a-f]+|PTR_DAT_[0-9a-f]+|'
                               r'PTR_FUN_[0-9a-f]+|PTR_vtable_[0-9a-f]+|'
                               r'PTR_nothrow_[0-9a-f]+|PTR_[0-9a-f]+|'
                               r'PTR_stderr_[0-9a-f]+)\b', alltext))

    # symbol definitions
    defs = []
    emitted = set()
    defs.append('/* ---- data symbols (backed by the relocated original image) ---- */')
    for s in sorted(used_syms):
        emitted.add(s)
        addr = int(s.rsplit('_', 1)[1], 16) - 0x100000
        if s == 'PTR_DAT_00120fd0':
            # GOT pointer to a 2 KiB byte table at VMA 0x196c0
            defs.append('#define PTR_DAT_00120fd0 (*(unsigned char (*)[4096])(aq_image + 0x%x))'
                        % (0x196c0))
            continue
        typ, length = datatypes.get(s, ('undefined1', 1))
        if typ.startswith('pointer') or typ.endswith(' *'):
            defs.append('#define %s (*(undefined **)(aq_image + 0x%x))' % (s, addr))
        elif typ == 'undefined8':
            defs.append('#define %s (*(undefined8 *)(aq_image + 0x%x))' % (s, addr))
        elif typ == 'undefined4':
            defs.append('#define %s (*(undefined4 *)(aq_image + 0x%x))' % (s, addr))
        elif typ == 'undefined2':
            defs.append('#define %s (*(undefined2 *)(aq_image + 0x%x))' % (s, addr))
        else:
            defs.append('#define %s (*(undefined1 *)(aq_image + 0x%x))' % (s, addr))
    # any DAT_ symbols not in the type table -> byte
    for s in sorted(used_syms):
        if s in emitted:
            continue
        if s.startswith('DAT_') and s not in datatypes:
            addr = int(s.rsplit('_', 1)[1], 16) - 0x100000
            defs.append('#define %s (*(undefined1 *)(aq_image + 0x%x))' % (s, addr))

    # prototypes
    protos = []
    for name, body in out_funcs:
        sig = split_sig(body)
        # remove parameter names to keep only types?  Keeping names is fine in C.
        protos.append(sig + ';')

    # patch lost-argument call
    for i, (name, body) in enumerate(out_funcs):
        if name == 'FUN_0010ef60':
            body = body.replace('cVar3 = FUN_0010e830();',
                                'cVar3 = FUN_0010e830(param_1, 0);')
            out_funcs[i] = (name, body)

    with open(OUT, 'w', encoding='utf-8') as f:
        f.write('/* Generated by tools/gen_decomp.py -- do not edit. */\n')
        f.write('#include "shim.h"\n\n')
        f.write('\n'.join(defs) + '\n\n')
        f.write('/* ---- forward declarations ---- */\n')
        f.write('\n'.join(protos) + '\n\n')
        for name, body in out_funcs:
            f.write('/* %s */\n' % name)
            f.write(body)
            if not body.endswith('\n'):
                f.write('\n')
            f.write('\n')

    print('wrote', OUT)
    print('functions:', len(out_funcs))
    print('data symbols:', len(used_syms))


if __name__ == '__main__':
    main()
