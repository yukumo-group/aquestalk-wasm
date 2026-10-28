#!/usr/bin/env python3
"""Generate the wasm32 (64-bit scalar cells) tree for the Check subset."""
import os, re
HERE=os.path.dirname(os.path.abspath(__file__))
ROOT=os.path.abspath(os.path.join(HERE,'..'))
SRC=os.path.join(ROOT,'src')
OUT=os.path.join(ROOT,'build-wasm32','gen')
FILES=['runtime.c','shim.c','shim.h','decomp_check.c','api_check.c','errors.c','image.c']

def transform(name,text):
    if name=='image.c':
        return text
    text=text.replace('unsigned long long','uint64_t')
    text=text.replace('long long','int64_t')
    text=text.replace('unsigned long','uint64_t')
    text=re.sub(r'\blong\b','int64_t',text)
    return text

def main():
    os.makedirs(OUT,exist_ok=True)
    for n in FILES:
        open(os.path.join(OUT,n),'w').write(transform(n,open(os.path.join(SRC,n)).read()))
    p=os.path.join(OUT,'shim.h'); s=open(p).read()
    s=s.replace('''typedef struct AqStr {
    char *p;
    size_t len;
    union {
        char buf[16];
        size_t cap;
    } u;
} AqStr;''','''typedef struct AqStr {
    uint64_t p;
    uint64_t len;
    union {
        char buf[16];
        uint64_t cap;
    } u;
} AqStr;''')
    s=s.replace('''typedef struct AqU16 {
    uint16_t *p;
    size_t len;
    union {
        uint16_t buf[8];
        size_t cap;
    } u;
} AqU16;''','''typedef struct AqU16 {
    uint64_t p;
    uint64_t len;
    union {
        uint16_t buf[8];
        uint64_t cap;
    } u;
} AqU16;''')
    open(p,'w').write(s)
    p=os.path.join(OUT,'shim.c'); s=open(p).read()
    s=s.replace('#define AQS(s) ((AqStr *)(s))',
                '#define AQS(s) ((AqStr *)(s))\n#define SP(s) ((char *)(uintptr_t)((AqStr *)(s))->p)\n#define SETP(s,v) (((AqStr *)(s))->p = (uint64_t)(uintptr_t)(v))')
    s=s.replace('    s->p = np;','    SETP(s, np);')
    s=s.replace('s->p','SP(s)')
    s=s.replace('size_t aqstr_find(','uint64_t aqstr_find(')
    s=s.replace('size_t aqstr_copy(','uint64_t aqstr_copy(')
    s=s.replace('(size_t)-1','(uint64_t)-1')
    open(p,'w').write(s)
    p=os.path.join(OUT,'shim.h'); s=open(p).read()
    s=s.replace('size_t aqstr_find(','uint64_t aqstr_find(')
    s=s.replace('size_t aqstr_copy(','uint64_t aqstr_copy(')
    open(p,'w').write(s)
    print('generated wasm32 Check tree in',OUT)
if __name__=='__main__':
    main()
