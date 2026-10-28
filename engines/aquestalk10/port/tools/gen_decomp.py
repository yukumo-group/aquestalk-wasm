#!/usr/bin/env python3
"""Generate port/src/decomp.c from Ghidra's decompiled libAquesTalk10.

This is a mechanical translation, not an emulator: each Ghidra function
becomes a real C function compiled to wasm/native code.  Only the library's
data tables are loaded from the original image (see image.c).

Adjustments needed to turn Ghidra's pseudo-C into compilable LP64-on-wasm32 C:
  * long/ulong -> 64-bit fixed types (wasm32 long is 32-bit)
  * 16-byte struct return of FUN_00106ad0 (only RAX is used by the caller)
  * Ghidra bit-field syntax (x._0_3_) -> typed memory accesses
  * pairs of stack variables that the original code accessed as one 3-byte
    struct (e.g. local_108/local_106) are grouped in an anonymous struct so
    their relative layout is preserved
"""
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
SRC = os.path.join(ROOT, 'decomp', 'all.c')
OUT = os.path.join(ROOT, 'port', 'src', 'decomp.c')
BASE = 0x100000

SKIP = set(range(0x104f28, 0x104fa0))          # init / PLT
SKIP |= {0x104fa0, 0x104fc0, 0x105040}          # entry, frame_dummy, init_array
SKIP |= {0x110820, 0x110858}                    # do_global_dtors_aux, _fini
SKIP |= set(range(0x35d000, 0x35d040))          # external block

# Data symbols whose *value* (not address) is used, with their width.
DATA_TYPE = {
    'DAT_0035cf78': 'undefined2',
    'DAT_0035cf7a': 'undefined2',
    '_UNK_0015724c': 'undefined4',
}


def read_funcs(path):
    src = open(path, encoding='utf-8').read()
    parts = re.split(r'//===== (.*?) @ ([0-9a-f]+) size=(\d+) =====\n', src)
    out = []
    for i in range(1, len(parts), 4):
        out.append({'name': parts[i], 'addr': int(parts[i + 1], 16), 'body': parts[i + 3]})
    return out


def split_head(body):
    m = re.search(r'\n\{\n', body)
    if not m:
        raise RuntimeError('no body')
    return body[:m.start()], body[m.end():]


def fix_types(text):
    # wasm32 long is 32-bit, the original is LP64: use fixed 64-bit types.
    text = re.sub(r'\bulong\b', 'uint64_t', text)
    text = re.sub(r'\blong\b', 'int64_t', text)
    return text


def fix_bitfields(text):
    def repl(m):
        base, off, width = m.group(1), int(m.group(2)), int(m.group(3))
        typ = {1: 'undefined1', 2: 'undefined2', 3: 'uint3', 4: 'undefined4',
               8: 'undefined8'}.get(width, 'undefined%d' % width)
        return '(*(%s *)((char *)&%s + %d))' % (typ, base, off)
    return re.sub(r'\b([A-Za-z_][A-Za-z0-9_]*)\._(\d+)_(\d+)_', repl, text)


def fix_16byte_return(text):
    """FUN_00106ad0 returns {param_1, param_3} in RAX:RDX; callers use RAX."""
    text = text.replace('undefined1  [16] FUN_00106ad0(undefined4 *param_1,int param_2,',
                        'int64_t FUN_00106ad0(undefined4 *param_1,int param_2,')
    text = text.replace('  undefined1 auVar1 [16];\n', '')
    text = re.sub(r'  auVar1\._8_8_ = [^;]+;\n', '', text)
    text = re.sub(r'  auVar1\._0_8_ = ([^;]+);\n', r'  return (int64_t)\1;\n', text)
    text = text.replace('  return auVar1;\n', '')
    return text


def fix_raw_addresses(text):
    # Ghidra occasionally leaves an absolute address as a plain integer
    # (e.g. `+ 0x35a048`) instead of a DAT_ symbol.  Rebase it onto aq_image.
    def repl(m):
        a = int(m.group(0), 16)
        if 0x100000 <= a < 0x35d000:
            return '(int64_t)(aq_image + 0x%x)' % (a - BASE)
        return m.group(0)
    return re.sub(r'0x[0-9a-fA-F]+', repl, text)


def manual_fixes(head, body):
    # FUN_00109390 tail-calls FUN_0010947c and returns its value in EAX,
    # but Ghidra typed it void.  Every caller reads the result.
    body = body.replace(
        '  FUN_0010947c(param_1,*param_1 + (long)param_2 * 4);\n  return;',
        '  return FUN_0010947c(param_1,*param_1 + (long)param_2 * 4);')
    # Ghidra misread two zero-extended byte loads as sign-extended 16-bit
    # elements of the ushort frame struct.  The original is:
    #   FUN_0010b896(p, byte[p+5], byte[p+6]);
    #   FUN_0010daec(p+0x20, byte[p+4], ushort[p+2] >> 1);
    # (see movzx eax,BYTE PTR [rax+0x6] / [rax+0x4] at 0x104d6/0x1050c).
    body = body.replace(
        'FUN_0010b896(param_1,*(undefined1 *)((long)param_2 + 5),(char)param_2[3]);',
        'FUN_0010b896(param_1,*(undefined1 *)((long)param_2 + 5),'
        '*(undefined1 *)((long)param_2 + 6));')
    body = body.replace(
        'FUN_0010daec(param_1 + 0x20,(char)param_2[2],param_2[1] >> 1);',
        'FUN_0010daec(param_1 + 0x20,*(undefined1 *)((char *)param_2 + 4),'
        'param_2[1] >> 1);')

    # SJIS is an unsigned byte pair.  Ghidra compared signed `char` bytes
    # against the unsigned table, so every high-bit (multibyte) character
    # failed to match.  The original does a byte-wise (unsigned) compare.
    body = body.replace(
        'if ((*param_1 == (&DAT_00110960)[(long)(int)local_c * 10]) &&\n'
        '       (param_1[1] == (&DAT_00110961)[(long)(int)local_c * 10])) break;',
        'if (((undefined1)*param_1 == (&DAT_00110960)[(long)(int)local_c * 10]) &&\n'
        '       ((undefined1)param_1[1] == (&DAT_00110961)[(long)(int)local_c * 10])) break;')

    head = head.replace('void FUN_00109390(', 'undefined2 FUN_00109390(')

    # The public key setters and their helpers return the validation result
    # in EAX; Ghidra typed them void because the decompiled wrapper ignored
    # it.  Restore the documented int ABI.
    for helper, impl in (('FUN_0010732c', 'FUN_00106398'),
                         ('FUN_00107346', 'FUN_00106423')):
        head = head.replace('void %s(' % helper, 'undefined8 %s(' % helper)
        body = body.replace('  %s(param_1);\n  return;' % impl,
                            '  return %s(param_1);' % impl)
    for pub, helper in (('AquesTalk_SetDevKey', 'FUN_0010732c'),
                        ('AquesTalk_SetUsrKey', 'FUN_00107346')):
        head = head.replace('void %s(' % pub, 'undefined8 %s(' % pub)
        body = body.replace('  %s(param_1);\n  return;' % helper,
                            '  return %s(param_1);' % helper)
    return head, body


SMALL1 = {'undefined': 1, 'undefined1': 1, 'char': 1, 'byte': 1,
          'bool': 1, 'sbyte': 1}
SMALL2 = {'undefined2': 2, 'short': 2, 'ushort': 2}


def parse_decls(body):
    """Return (decl lines, code) for a function body."""
    if '\n  \n' not in body:
        return None, body
    decl, code = body.split('\n  \n', 1)
    items = []
    for line in decl.split('\n'):
        s = line.strip()
        if not s:
            continue
        if '=' in s or '(*' in s:
            items.append({'line': line, 'name': None, 'size': 0, 'off': None})
            continue
        m = re.match(r'^(.+?)\s+(\w+)\s*(\[[^\]]*\])?;$', s)
        if not m:
            items.append({'line': line, 'name': None, 'size': 0, 'off': None})
            continue
        typ, name, arr = m.group(1).strip(), m.group(2), m.group(3)
        if '*' in typ:
            size = 8
        else:
            base = typ.strip()
            if base in SMALL1:
                size = 1
            elif base in SMALL2:
                size = 2
            elif base in ('undefined4', 'int', 'uint', 'float'):
                size = 4
            elif base in ('undefined8', 'long', 'ulong', 'double', 'uint64_t',
                          'int64_t', 'uintptr_t'):
                size = 8
            elif base == 'uint3':
                size = 3
            else:
                size = 0
        if arr and size:
            size *= int(arr[1:-1])
        mo = re.search(r'^(?:local|uStack|iStack|pStack)_([0-9a-f]+)$', name)
        items.append({'line': line, 'name': name, 'size': size,
                      'off': int(mo.group(1), 16) if mo else None})
    return items, code


def group_small_runs(body):
    """Keep runs of small stack slots contiguous.

    The original compiler packed adjacent byte/short locals together and the
    engine passes &first to functions that read 2, 3 or 7 bytes across the
    neighbouring slots (kana codes, prosody records).  C does not guarantee
    the relative order/placement of separate locals, so such runs are put in
    one struct.  Only runs of 1/2-byte members are grouped: their natural
    alignment reproduces the original offsets exactly.
    """
    items, code = parse_decls(body)
    if items is None:
        return body
    named = [x for x in items if x['name'] and x['off'] is not None and x['size']]
    ordered = sorted(named, key=lambda x: -x['off'])
    runs = []
    cur = []
    for x in ordered:
        if cur and cur[-1]['off'] - cur[-1]['size'] == x['off']:
            cur.append(x)
        else:
            if cur:
                runs.append(cur)
            cur = [x]
    if cur:
        runs.append(cur)

    groups = {}
    for r in runs:
        if len(r) < 2 or not all(x['size'] <= 2 for x in r):
            continue
        if not any(('&' + x['name']) in code for x in r):
            continue
        gname = 'aq_s_%x' % r[0]['off']
        for x in r:
            groups[x['name']] = (gname, x)
        r.sort(key=lambda x: -x['off'])       # ascending address
        for x in r:
            g = groups[x['name']][0]
            groups[x['name']] = (g, x, r)

    if not groups:
        return body

    # one struct declaration per group, at the position of its first member
    emitted = set()
    out_decls = []
    for item in items:
        name = item['name']
        if name in groups:
            g, x, members_list = groups[name]
            if g in emitted:
                continue
            emitted.add(g)
            mem = ' '.join(y['line'].strip() for y in members_list)
            out_decls.append('  struct { %s } %s;' % (mem, g))
        else:
            out_decls.append(item['line'])

    for name, (g, _, _) in groups.items():
        code = re.sub(r'\b%s\b' % re.escape(name), '%s.%s' % (g, name), code)
    return '\n'.join(out_decls) + '\n  \n' + code


def data_defs(body):
    syms = sorted(set(re.findall(
        r'\b(?:PTR_[A-Za-z0-9_]+|(?:DAT|UNK|_DAT|_UNK)_[0-9a-fA-F]+)\b', body)))
    lines = ['/* ---- original data symbols (backed by the relocated image) ---- */']
    for s in syms:
        m = re.search(r'_([0-9a-fA-F]+)$', s)
        if not m:
            continue
        off = int(m.group(1), 16) - BASE
        if s.startswith('PTR_'):
            # 8-byte relocation slots.  A plain `undefined *` would be only
            # 4 bytes on wasm32 and every table index would stride wrong.
            lines.append('#define %s (*(uint64_t *)(aq_image + 0x%x))' % (s, off))
            continue
        typ = DATA_TYPE.get(s, 'undefined1')
        lines.append('#define %s (*(%s *)(aq_image + 0x%x))' % (s, typ, off))
    return '\n'.join(lines)


def main():
    funcs = [f for f in read_funcs(SRC) if f['addr'] not in SKIP and f['addr'] < 0x110820]
    out = []
    for f in funcs:
        head, body = split_head(f['body'])
        head, body = manual_fixes(head, body)
        head = fix_raw_addresses(head)
        body = fix_raw_addresses(body)
        head = fix_16byte_return(head)
        body = fix_16byte_return(body)
        body = fix_bitfields(body)
        body = group_small_runs(body)
        # uninitialized incoming stack slot: make it deterministic
        body = re.sub(r'\bin_stack_[0-9a-f]+\b', 'in_stack_unused', body)
        body = body.replace('  undefined8 in_stack_unused;', '  undefined8 in_stack_unused = 0;')
        head = fix_types(head)
        body = fix_types(body)
        out.append((f['name'], head.strip(), body))

    # Ghidra sometimes declares an ignored parameter as (void); drop the
    # arguments at call sites so the C types agree.  The ABI result is
    # identical because the callee never reads them.
    noarg = []
    for name, head, body in out:
        sig = re.sub(r'/\*.*?\*/', '', head, flags=re.S)
        if re.search(r'\b%s\s*\(\s*void\s*\)' % re.escape(name), sig):
            noarg.append(name)
    for i, (name, head, body) in enumerate(out):
        for fn in noarg:
            body = re.sub(r'\b%s\s*\([^()]*\)' % re.escape(fn), '%s()' % fn, body)
        # FUN_00106ad0's third (RDX) argument is unused by the caller; the
        # original call sites simply leave it undefined.
        body = re.sub(r'\bFUN_00106ad0\s*\(([^,()]+),([^,()]+)\)',
                      r'FUN_00106ad0(\1,\2,0)', body)
        out[i] = (name, head, body)

    alltext = '\n'.join(h + '\n' + b for _, h, b in out)
    defs = data_defs(alltext)

    protos = []
    for name, head, body in out:
        sig = re.sub(r'/\*.*?\*/', '', head, flags=re.S).strip()
        protos.append(sig + ';')

    with open(OUT, 'w', encoding='utf-8') as fo:
        fo.write('/* Generated by tools/gen_decomp.py -- do not edit. */\n')
        fo.write('#include "shim.h"\n\n')
        fo.write(defs + '\n\n')
        fo.write('/* ---- forward declarations ---- */\n')
        fo.write('\n'.join(protos) + '\n\n')
        for name, head, body in out:
            fo.write(head + '\n{\n' + body + '\n')
    print('wrote', OUT, 'functions', len(out))

if __name__ == '__main__':
    main()
