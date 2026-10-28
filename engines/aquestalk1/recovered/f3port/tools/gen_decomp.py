#!/usr/bin/env python3
"""Generate port/src/decomp.c from Ghidra's decompiler output (decomp/all.c).

This is a mechanical translation, not an emulator: every function below is
ordinary C that clang compiles to native/wasm machine code.  The script
normalises the few Ghidra-specific idioms into portable fixed width C.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
DECOMP = os.path.join(ROOT, 'build', 'decomp-f3', 'all.c')
DATATSV = os.path.join(ROOT, 'build', 'decomp-f3', 'data.tsv')
OUT = os.path.join(ROOT, 'recovered', 'f3port', 'src', 'decomp.c')

# Code that is replaced by hand written C (wasm_api.c) or is pure ELF/PLT glue.
EXCLUDE = {
    0x106000,  # _DT_INIT
    0x106020,  # deregister_tm_clones
    0x1060e0,  # register_tm_clones
    0x106110,  # __do_global_dtors_aux
    0x106080,  # __cxa_finalize PLT stub
    0x106090,  # free PLT stub
    0x1060a0,  # __stack_chk_fail PLT stub
    0x1060b0,  # memcpy PLT stub
    0x1060c0,  # time PLT stub
    0x1060d0,  # malloc PLT stub
    0x106150,  # _FINI_0 (.fini_array)
    0x106190,  # _INIT_0 (.init_array)
    0x110b78,  # _DT_FINI
    0x12a018,  # __gmon_start__
}

# 8 byte slots that hold pointers.  They are declared uint64_t so that both
# the x86-64 build and wasm32 (where a C pointer is 4 bytes) walk the table
# with the original 8 byte stride.
U64_SLOTS = {
    'PTR_DAT_003166a0',
    'PTR_DAT_003166f0',
    'PTR_DAT_003166f8',
}

# pointer valued slots that the recovered code uses as C pointers
PTR_SLOTS = {
    'PTR_DAT_00316fb0': 'unsigned char *',
    'PTR_DAT_00316fd8': 'unsigned char *',
    'PTR_DAT_00316fc8': 'void *',
}

# A few functions are tail call wrappers.  Ghidra modelled them as `void`
# because the value was unused at the call sites it looked at first, but the
# machine code returns the callee's value in eax.  Patch the ones whose result
# is actually consumed (the compiler finds them for us).
MANUAL_FIXES = {
    0x10504a: [
        (r'void FUN_0010504a\(long \*param_1,int param_2\)',
         'ushort FUN_0010504a(long *param_1,int param_2)'),
        (r'FUN_00105136\(\*param_1 \+ \(long\)param_2 \* 4\);\s*return;',
         'return FUN_00105136(*param_1 + (long)param_2 * 4);'),
    ],
    0x10b132: [
        (r'void FUN_0010b132\(undefined8 param_1,undefined8 param_2\)',
         'int FUN_0010b132(undefined8 param_1,undefined8 param_2)'),
        (r'FUN_0010b157\(param_1,param_2\);\s*return;',
         'return FUN_0010b157(param_1,param_2);'),
    ],
    0x108397: [
        (r'void FUN_00108397\(',
         'int FUN_00108397('),
        (r'FUN_00104f65\(param_4,uVar1,param_5\);\s*return;',
         'return FUN_00104f65(param_4,uVar1,param_5);'),
    ],
    0x1082aa: [
        (r'void FUN_001082aa\(',
         'int FUN_001082aa('),
        (r'FUN_00104f65\(param_4,uVar1,param_5\);\s*return;',
         'return FUN_00104f65(param_4,uVar1,param_5);'),
    ],
}

# Per-function rewrites applied to the normalised body.
FUNC_FIXES = {}

# Symbols the decompiler created for unnamed data that is only ever addressed.
UNK_TYPES = {
    '_UNK_00113012': 'uint32_t',
}

TSV_TYPE = {
    'undefined1': 'char',           # byte access, signed like the original cmpb tests
    'undefined2': 'uint16_t',
    'undefined4': 'uint32_t',
    'undefined8': 'uint64_t',
    'pointer': 'uint64_t',
    'undefined *': 'uint64_t',
}


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
    if not os.path.exists(path):
        return types
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        addr, name, typ, length = line.split('\t')
        types[name] = typ
    return types


def split_sig(body):
    idx = body.find('\n{')
    if idx < 0:
        raise RuntimeError('no body: ' + body[:60])
    return body[:idx].strip()


def normalize_types(text):
    # order matters only for the word boundaries; all are whole words
    text = re.sub(r'\bulong\b', 'uint64_t', text)
    text = re.sub(r'\bushort\b', 'uint16_t', text)
    text = re.sub(r'\buint\b', 'uint32_t', text)
    text = re.sub(r'\bbyte\b', 'uint8_t', text)
    text = re.sub(r'\blong\b', 'int64_t', text)
    return text


def fix_bitfields(text):
    """Ghidra renders partial stores to a variable as `x._0_4_ = ...`."""
    widths = {1: 'uint8_t', 2: 'uint16_t', 4: 'uint32_t', 8: 'uint64_t'}

    def repl(m):
        base, off, width = m.group(1), int(m.group(2)), int(m.group(3))
        typ = widths.get(width)
        if typ is None:
            raise SystemExit('unhandled bitfield width %d on %s' % (width, base))
        if off == 0:
            return '(*(%s *)((char *)&(%s)))' % (typ, base)
        return '(*(%s *)((char *)&(%s) + %d))' % (typ, base, off)

    return re.sub(r'([A-Za-z_][A-Za-z0-9_]*)\._(\d+)_(\d+)_', repl, text)


def data_defs(used, datatypes):
    out = ['/* ---- data symbols (backed by the relocated original image) ---- */']
    for s in sorted(used):
        addr = int(s.rsplit('_', 1)[1], 16) - 0x100000
        if s in UNK_TYPES:
            out.append('#define %s (*(%s *)(aq_image + 0x%x))' % (s, UNK_TYPES[s], addr))
            continue
        if s.startswith('PTR_'):
            if s in U64_SLOTS:
                typ = 'uint64_t'
            elif s in PTR_SLOTS:
                typ = PTR_SLOTS[s]
                out.append('#define %s (*(%s *)(aq_image + 0x%x))' % (s, typ, addr))
                continue
            else:
                typ = 'uint64_t'
            out.append('#define %s (*(%s *)(aq_image + 0x%x))' % (s, typ, addr))
            continue
        typ = TSV_TYPE.get(datatypes.get(s, 'undefined1'), 'char')
        if typ == 'char':
            out.append('#define %s (*(char *)(aq_image + 0x%x))  /* byte */' % (s, addr))
        else:
            out.append('#define %s (*(%s *)(aq_image + 0x%x))' % (s, typ, addr))
    return '\n'.join(out)


def main():
    funcs = read_funcs(DECOMP)
    datatypes = load_datatypes(DATATSV)

    kept = []
    for f in funcs:
        if f['addr'] in EXCLUDE or f['addr'] >= 0x300000:
            continue
        if 'DECOMP FAILED' in f['body'] or 'halt_baddata' in f['body']:
            print('skipping bad function', f['name'], flush=True)
            continue
        body = f['body']
        for pat, rep in MANUAL_FIXES.get(f['addr'], ()):
            body, n = re.subn(pat, rep, body)
            if n != 1:
                raise SystemExit('manual fix for %s did not apply (%s)' % (f['name'], pat))
        body = re.sub(r'\b(FUN_[0-9a-f]{8})\(void\)', r'\1()', body)
        # stack-protector canary: in_FS_OFFSET is not a real variable, and the
        # guard read (fs:0x28) is meaningless in the recompiled code.
        body = re.sub(r'\n\s*(?:int64_t|long|undefined8) in_FS_OFFSET;', '', body)
        body = body.replace('*(int64_t *)(in_FS_OFFSET + 0x28)', '0')
        body = body.replace('*(long *)(in_FS_OFFSET + 0x28)', '0')
        for pat, rep in FUNC_FIXES.get(f['addr'], ()):
            body, n = re.subn(pat, rep, body)
            if n == 0:
                print('WARN: fix for %s did not apply: %s' % (f['name'], pat))
        if f['addr'] == 0x109a18:
            # packed int count at +8 / int max at +0xc: the decompiled form
            # aliases the same 8 bytes through int* and int64_t*, so the
            # compiler reuses the stale value.  Rewrite with two ints.
            body = """int FUN_00109a18(int64_t *param_1,undefined8 param_2,uint16_t param_3)
{
  int count = *(int *)((char *)param_1 + 8);
  int max = *(int *)((char *)param_1 + 0xc);
  int64_t tok;

  if (count < max) {
    tok = (int64_t)count * 4 + *param_1;
    FUN_00107502(tok + 2,param_2,2);
    FUN_00109cbc(param_1,tok,0);
    if (param_3 == 0) {
      FUN_00109c64(param_1,tok,0);
    }
    else {
      FUN_00109c64(param_1,tok,(uint16_t)(0x3e8000U / (uint32_t)param_3));
    }
    *(int *)((char *)param_1 + 8) = count + 1;
    return count;
  }
  return -1;
}"""
        if f['addr'] == 0x10c278:
            # Ghidra split a 6-byte stack scratch buffer into separate chars.
            # The compiler does not lay them out adjacently, so rebuild it as
            # one array: local_26..local_21 -> sbuf[0..5].
            body = body.replace('  undefined1 local_26;\n  char local_25;\n  char local_24;\n  char local_23;\n  char local_22;\n  char local_21;',
                                '  char sbuf[6];')
            for old, new in (('local_26', 'sbuf[0]'), ('local_25', 'sbuf[1]'),
                             ('local_24', 'sbuf[2]'), ('local_23', 'sbuf[3]'),
                             ('local_22', 'sbuf[4]'), ('local_21', 'sbuf[5]')):
                body = re.sub(r'\b%s\b' % old, new, body)
        body = fix_bitfields(normalize_types(body))
        kept.append((f['name'], f['addr'], body))

    # Ghidra types tail-call wrappers as `void F(...) { G(...); return; }`.
    # When the caller consumes the result we need G's return type instead.
    retmap = {}
    sig_re = re.compile(r'^(.*?)\b(\w+)\s*\(', re.S)
    for name, addr, body in kept:
        m = sig_re.match(body)
        if m:
            retmap[name] = m.group(1).strip()
    tail_re = re.compile(
        r'^(void)\s+(\w+)\s*\(([^)]*)\)\s*\n\{\s*\n\s*(\w+)\(([^;]*)\);\s*\n\s*return;\s*\n\}',
        re.S)
    fixed = []
    for name, addr, body in kept:
        m = tail_re.match(body.strip())
        if m:
            callee = m.group(4)
            rt = retmap.get(callee, 'void')
            if rt != 'void':
                body = '%s %s(%s)\n{\n  return %s(%s);\n}' % (
                    rt, m.group(2), m.group(3), callee, m.group(5))
                retmap[name] = rt
        fixed.append((name, addr, body))
    kept = fixed

    names = {n for n, _, _ in kept}

    # every FUN_ that is called must be defined
    text = '\n'.join(b for _, _, b in kept)
    called = set(re.findall(r'\b(FUN_[0-9a-f]{8})\s*\(', text))
    missing = sorted(called - names)
    if missing:
        print('missing functions:', missing)

    used = set(re.findall(r'\b(DAT_[0-9a-f]+|PTR_[A-Za-z0-9_]+|_?UNK_[0-9a-f]+)\b', text))

    out = []
    out.append('/* Generated by tools/gen_decomp.py from Ghidra output -- do not edit.')
    out.append(' *')
    out.append(' * Mechanically recovered C implementation of aqtk1_lnx/lib64/f3/libAquesTalk.so.')
    out.append(' * Addresses in symbol names are the original virtual addresses;')
    out.append(' * aq_image mirrors the original address space (see image.c).')
    out.append(' */')
    out.append('#include "shim.h"')
    out.append('')
    out.append(data_defs(used, datatypes))
    out.append('')
    out.append('/* ---- forward declarations ---- */')
    for name, addr, body in kept:
        out.append(split_sig(body) + ';')
    out.append('')
    for name, addr, body in kept:
        out.append('/* %s @ %#x */' % (name, addr))
        out.append(body.rstrip())
        out.append('')

    with open(OUT, 'w', encoding='utf-8') as f:
        f.write('\n'.join(out))

    print('wrote', OUT)
    print('functions:', len(kept), 'data symbols:', len(used))
    print('total lines:', sum(b.count('\n') + 1 for _, _, b in kept))


if __name__ == '__main__':
    main()
