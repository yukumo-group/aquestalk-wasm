#!/usr/bin/env python3
"""Generate the wasm32 (Safari-compatible) source tree from the LP64 port.

The original library is LP64.  wasm32 has 32-bit pointers, so we keep all
`long`/`ulong` values (and the AqStr/AqU16 layout) at 64 bits while native
pointers stay 32-bit.  Pointers are stored zero-extended in those 64-bit cells.
This is enough to preserve the original struct offsets on a 32-bit linear
memory.
"""
import os, re, shutil, sys

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.abspath(os.path.join(HERE, '..', 'src'))
OUT = os.path.abspath(os.path.join(HERE, '..', 'build-wasm32', 'gen'))
FILES = ['runtime.c', 'shim.c', 'shim.h', 'cold_stubs.c', 'decomp.c',
         'api_raw.c', 'lookup_c.c', 'image.c']

def transform(name, text):
    if name == 'image.c':
        return text
    text = text.replace('unsigned long long', 'uint64_t')
    text = text.replace('long long', 'int64_t')
    text = text.replace('unsigned long', 'uint64_t')
    text = re.sub(r'\blong\b', 'int64_t', text)
    return text

def main():
    os.makedirs(OUT, exist_ok=True)
    for name in FILES:
        text = open(os.path.join(SRC, name)).read()
        open(os.path.join(OUT, name), 'w').write(transform(name, text))

    # --- shim.h: 64-bit cells for the std::string / u16string layout -------
    p = os.path.join(OUT, 'shim.h')
    s = open(p).read()
    s = s.replace('''typedef struct AqStr {
    char *p;
    size_t len;
    union {
        char buf[16];
        size_t cap;
    } u;
} AqStr;''', '''typedef struct AqStr {
    uint64_t p;
    uint64_t len;
    union {
        char buf[16];
        uint64_t cap;
    } u;
} AqStr;''')
    s = s.replace('''typedef struct AqU16 {
    uint16_t *p;
    size_t len;
    union {
        uint16_t buf[8];
        size_t cap;
    } u;
} AqU16;''', '''typedef struct AqU16 {
    uint64_t p;
    uint64_t len;
    union {
        uint16_t buf[8];
        uint64_t cap;
    } u;
} AqU16;''')
    open(p, 'w').write(s)

    # --- shim.c: access 64-bit pointer cells through casts -----------------
    p = os.path.join(OUT, 'shim.c')
    s = open(p).read()
    s = s.replace('#define AQS(s) ((AqStr *)(s))',
                  '#define AQS(s) ((AqStr *)(s))\n'
                  '#define SP(s) ((char *)(uintptr_t)((AqStr *)(s))->p)\n'
                  '#define SETP(s,v) (((AqStr *)(s))->p = (uint64_t)(uintptr_t)(v))')
    s = s.replace('    s->p = np;', '    SETP(s, np);')
    s = s.replace('s->p', 'SP(s)')
    s = s.replace('size_t aqstr_find(', 'uint64_t aqstr_find(')
    s = s.replace('size_t aqstr_copy(', 'uint64_t aqstr_copy(')
    s = s.replace('(size_t)-1', '(uint64_t)-1')
    open(p, 'w').write(s)

    # --- decomp.c: the rewritten u16string helpers use 64-bit cells --------
    p = os.path.join(OUT, 'decomp.c')
    s = open(p).read()
    for v in ('sb', 'sc', 'sa'):
        s = s.replace(f'{v}.p[', f'((uint16_t *)(uintptr_t){v}.p)[')
        s = s.replace(f'*{v}.p', f'*((uint16_t *)(uintptr_t){v}.p)')
    open(p, 'w').write(s)

    # --- api_raw.c: pointer/size signatures and casts ----------------------
    p = os.path.join(OUT, 'api_raw.c')
    s = open(p).read()
    s = s.replace('void *aq_alloc(uint64_t n)', 'void *aq_alloc(unsigned int n)')
    s = s.replace('koe[i] = rom.p[i];', 'koe[i] = ((char *)(uintptr_t)rom.p)[i];')
    s = s.replace('if (rom.p && rom.p != rom.u.buf)',
                  'if (rom.p && rom.p != (uint64_t)(uintptr_t)rom.u.buf)')
    s = s.replace('free(rom.p);', 'free((void *)(uintptr_t)rom.p);')
    s = s.replace('if (s->p && s->p != s->u.buf)',
                  'if (s->p && s->p != (uint64_t)(uintptr_t)s->u.buf)')
    s = s.replace('free(s->p);', 'free((void *)(uintptr_t)s->p);')
    s = s.replace('u16_to_utf8(out.p, out.len, koe, nBuf)',
                  'u16_to_utf8((const uint16_t *)(uintptr_t)out.p, out.len, koe, nBuf)')
    open(p, 'w').write(s)

    # declarations in shim.h must match the 64-bit npos convention
    p = os.path.join(OUT, 'shim.h')
    s = open(p).read()
    s = s.replace('size_t aqstr_find(', 'uint64_t aqstr_find(')
    s = s.replace('size_t aqstr_copy(', 'uint64_t aqstr_copy(')
    open(p, 'w').write(s)

    print('generated wasm32 sources in', OUT)

if __name__ == '__main__':
    main()
