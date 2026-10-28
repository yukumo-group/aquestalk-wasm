#!/usr/bin/env python3
"""Generate a C translation unit from Ghidra's decompiled output.

The output is a (close to) mechanical translation of the original
libAqKanji2Koe.so machine code.  It is *not* an emulator: every function is
real C code that clang compiles to native machine code / wasm.

NOTE: the checked-in port/src/decomp.c is authoritative and contains a few
older hand fixes that this generator does not reproduce yet.  If you regenerate
it, diff against git and port any missing fixes before rebuilding.
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
    # Ghidra types the signed 64-bit range test against -2147483649 as
    # `-0x80000001`; in C that literal is unsigned, so the test is always
    # false.  It guards the "same length" branch of the inlined
    # std::u16string::replace calls (NUMK counter suffix normalization).
    text = re.sub(r'\(\(([A-Za-z_]\w*) < 0x80000000\) && \(-0x80000001 < \1\)\) && \(\(int\)\1 == 0\)',
                  r'((long)\1 == 0)', text)
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


def fix_stack_string(fname, body):
    """Keep an inlined std::string temporary in one contiguous AqStr.

    Ghidra split the 32-byte object into `local_68` (p), `local_60` (len) and
    `local_58` (buffer).  A C compiler is free to reorder those stack slots,
    so passing &local_68 as a std::string* reads garbage.  Re-emit them as one
    AqStr; this path is used for English-word transliteration and crashed on
    inputs such as "hello"."""
    if fname != 'FUN_0010d610':
        return body
    body = body.replace(
        '  undefined1 *local_68;\n  ulong local_60;\n  undefined1 local_58 [24];\n',
        '  AqStr local_str;\n')
    body = body.replace(
        '            local_60 = 0;\n'
        '            local_58[0] = 0;\n'
        '            local_80 = (long)uVar6 >> 1;\n'
        '            local_68 = local_58;\n'
        '            FUN_0010c520(local_88,&local_68);\n'
        '            FUN_0010b2c0(plVar9,local_68,local_60 & 0xffffffff);\n'
        '            if (local_68 != local_58) {\n'
        '              operator_delete(local_68);\n'
        '            }\n',
        '            AQSTR_INIT(local_str);\n'
        '            local_80 = (long)uVar6 >> 1;\n'
        '            FUN_0010c520(local_88,(undefined8)(uintptr_t)&local_str);\n'
        '            FUN_0010b2c0(plVar9,AQSTR_DATA(local_str),\n'
        '                         (int)(local_str.len & 0xffffffff));\n'
        '            if (!AQSTR_LOCAL(local_str)) {\n'
        '              operator_delete(AQSTR_DATA(local_str));\n'
        '            }\n')
    return body


def fix_port_specifics(fname, body):
    """Hand-maintained replacements that must survive regeneration."""
    if fname == 'FUN_0010e830':
        # The table stores UTF-16 code units; Ghidra typed the parameter as
        # signed `short`, which never compares equal to values >= 0x8000
        # (e.g. the fullwidth digits 0xff10..0xff19).  That signedness issue
        # disabled the whole <NUMK>/<NUM> pipeline.
        body = body.replace('short param_2', 'ushort param_2')
    if fname == 'FUN_0010b080':
        # Register both MARISA tries used by the port: the master dictionary
        # (kind 0) and the single-character reading dictionary (kind 1).
        old = ('        if (strncmp((char *)*param_1, "AqK2K Ver2 system dic.", 22) == 0)\n'
               '          aq_lookup_register_slot(param_1 + 3);')
        new = ('        if (strncmp((char *)*param_1, "AqK2K Ver2 system dic.", 22) == 0)\n'
               '          aq_lookup_register_slot(param_1 + 3, 0);\n'
               '        else if (strncmp((char *)*param_1, "MICHIGO.DIC", 11) == 0)\n'
               '          aq_lookup_register_slot(param_1 + 3, 1);')
        if old in body:
            body = body.replace(old, new)
    if fname == 'FUN_00116cc0':
        # The decompiled MARISA search is LP64-only; use the precomputed
        # MSTD/MCGD hash tables and enumerate common prefixes shortest-first.
        marker = '  if (*param_1 == 0) {'
        if marker in body:
            shortcut = (
                '  int kind = aq_lookup_slot_kind(param_1);\n'
                '  if (aq_lookup_ready() && kind >= 0) {\n'
                '    uint16_t *q = *(uint16_t **)param_2;\n'
                '    long bytes = *(long *)(param_2 + 8);\n'
                '    long qlen = bytes / 2;\n'
                '    if (*(long *)(param_2 + 0x10) != (long)q || *(long *)(param_2 + 0x18) != bytes) {\n'
                '      *(long *)(param_2 + 0x10) = (long)q;\n'
                '      *(long *)(param_2 + 0x18) = bytes;\n'
                '      *(unsigned int *)(param_2 + 0x20) = 0;\n'
                '    }\n'
                '    int after = (int)(*(unsigned int *)(param_2 + 0x20) / 2);\n'
                '    int mlen = 0;\n'
                '    uint32_t id = 0;\n'
                '    if (aq_lookup_prefix_after(kind, q, (int)qlen, after, &mlen, &id)) {\n'
                '      *(unsigned int *)(param_2 + 0x20) = (unsigned int)(mlen * 2);\n'
                '      *(unsigned int *)(param_2 + 0x24) = id;\n'
                '      return 1;\n'
                '    }\n'
                '    return 0;\n'
                '  }\n')
            body = body.replace(marker, shortcut + marker, 1)
    return body


def fix_numk_suffix(fname, body):
    """Replace the inlined std::u16string::replace in the NUMK counter
    normaliser with the runtime helper.

    Ghidra expanded three `sb.replace(0, sb.size(), L"..." )` calls into
    hundreds of lines of pointer arithmetic.  Besides being hard to follow,
    the overlap branches assume LP64 pointer sizes and corrupt the counter
    string in the wasm32 build.  All three calls replace the whole counter
    reading with a fixed two-character string, which FUN_0010d130 does
    directly."""
    if fname != 'FUN_0010ef60':
        return body
    marker = 'if (((long)lVar11 == 0)) {'
    pos = 0
    chunks = []
    targets = []
    while True:
        idx = body.find(marker, pos)
        if idx < 0:
            break
        line_start = body.rfind('\n', 0, idx) + 1
        brace = body.find('{', idx)
        depth = 1
        j = brace + 1
        in_str = False
        esc = False
        while depth > 0 and j < len(body):
            c = body[j]
            if in_str:
                if esc:
                    esc = False
                elif c == '\\':
                    esc = True
                elif c == '"':
                    in_str = False
            else:
                if c == '"':
                    in_str = True
                elif c == '{':
                    depth += 1
                elif c == '}':
                    depth -= 1
            j += 1
        block = body[idx:j]
        m = re.search(r'&DAT_001182(?:d4|e0|ec)', block)
        if not m:
            raise RuntimeError('NUMK suffix block without target constant')
        target = m.group(0)
        targets.append(target)
        indent = body[line_start:idx]
        chunks.append(body[pos:line_start])
        chunks.append(
            f"{indent}if ((long)lVar11 == 0) {{\n"
            f"{indent}  FUN_0010d130((undefined8 *)&sb,0,sb.len,{target},2);\n"
            f"{indent}  sb.len = 2;\n"
            f"{indent}  AQU16_DATA(sb)[2] = 0;\n"
            f"{indent}  goto LAB_0010f757;\n"
            f"{indent}}}")
        pos = j
    chunks.append(body[pos:])
    if len(targets) != 3:
        raise RuntimeError('expected 3 NUMK suffix replacements, got %d' % len(targets))
    return ''.join(chunks)


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
        body = fix_stack_string(f['name'], body)
        body = fix_port_specifics(f['name'], body)
        body = fix_numk_suffix(f['name'], body)
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
