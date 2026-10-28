/* Minimal freestanding runtime for the raw wasm64 build.
 * Provides the handful of libc entry points used by the recompiled code:
 * memory allocation, string operations, and no-op diagnostics.
 */
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

typedef struct _FILE FILE;

typedef unsigned long size_t64;

extern unsigned char __heap_base;

#define WASM_PAGE 65536u
#define ALIGN16(x) (((x) + 15u) & ~(size_t64)15u)

typedef struct Block {
    size_t64 size;        /* payload size, header excluded */
    struct Block *next;   /* free list link */
} Block;

static Block *free_list;
static size_t64 heap_top;
static size_t64 heap_end;

static void heap_init(void)
{
    if (heap_top)
        return;
    heap_top = ALIGN16((size_t64)(uintptr_t)&__heap_base);
    heap_end = heap_top;
}

static int heap_grow(size_t64 need)
{
    size_t64 have = (size_t64)__builtin_wasm_memory_size(0) * WASM_PAGE;
    size_t64 want = heap_top + need;
    if (want <= have)
        return 1;
    size_t64 pages = (want - have + WASM_PAGE - 1) / WASM_PAGE;
    long r = __builtin_wasm_memory_grow(0, pages);
    if (r < 0)
        return 0;
    heap_end = (size_t64)__builtin_wasm_memory_size(0) * WASM_PAGE;
    return 1;
}

void *malloc(size_t n)
{
    heap_init();
#ifdef AQK2K_LEAK
    size_t64 need = ALIGN16((size_t64)n + sizeof(Block));
    if (need < sizeof(Block) + 16) need = sizeof(Block) + 16;
    if (!heap_grow(need)) return 0;
    Block *b = (Block *)(uintptr_t)heap_top;
    b->size = (size_t64)n;
    b->next = 0;
    heap_top += need;
    return (void *)((unsigned char *)b + sizeof(Block));
#else
    size_t64 need = ALIGN16((size_t64)n + sizeof(Block));
    if (need < sizeof(Block) + 16)
        need = sizeof(Block) + 16;

    Block **pp = &free_list;
    while (*pp) {
        Block *b = *pp;
        if (b->size >= (size_t64)n) {
            *pp = b->next;
            b->size = (size_t64)n;
            return (void *)((unsigned char *)b + sizeof(Block));
        }
        pp = &b->next;
    }
    if (!heap_grow(need))
        return 0;
    Block *b = (Block *)(uintptr_t)heap_top;
    b->size = (size_t64)n;
    b->next = 0;
    heap_top += need;
    return (void *)((unsigned char *)b + sizeof(Block));
#endif
}

void free(void *p)
{
#ifdef AQK2K_LEAK
    (void)p;
    return;
#else
    if (!p)
        return;
    Block *b = (Block *)((unsigned char *)p - sizeof(Block));
    Block **pp = &free_list;
    while (*pp && *pp < b)
        pp = &(*pp)->next;
    b->next = *pp;
    *pp = b;
    /* coalesce adjacent free blocks (best effort, list is address sorted) */
    Block *cur = free_list;
    while (cur && cur->next) {
        unsigned char *end = (unsigned char *)cur + sizeof(Block) + cur->size;
        if (end == (unsigned char *)cur->next) {
            cur->size += sizeof(Block) + cur->next->size;
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
#endif
}

void *calloc(size_t n, size_t m)
{
    size_t64 total = (size_t64)n * m;
    void *p = malloc(total);
    if (p) {
        unsigned char *q = (unsigned char *)p;
        for (size_t64 i = 0; i < total; i++)
            q[i] = 0;
    }
    return p;
}

void *realloc(void *p, size_t n)
{
    if (!p)
        return malloc(n);
    Block *b = (Block *)((unsigned char *)p - sizeof(Block));
    if (b->size >= (size_t64)n)
        return p;
    void *q = malloc(n);
    if (!q)
        return 0;
    unsigned char *src = (unsigned char *)p, *dst = (unsigned char *)q;
    for (size_t64 i = 0; i < b->size; i++)
        dst[i] = src[i];
    free(p);
    return q;
}

/* string routines --------------------------------------------------- */
void *memcpy(void *d, const void *s, size_t n)
{
    unsigned char *dd = (unsigned char *)d;
    const unsigned char *ss = (const unsigned char *)s;
    for (size_t i = 0; i < n; i++) dd[i] = ss[i];
    return d;
}

void *memmove(void *d, const void *s, size_t n)
{
    unsigned char *dd = (unsigned char *)d;
    const unsigned char *ss = (const unsigned char *)s;
    if (dd < ss) {
        for (size_t i = 0; i < n; i++) dd[i] = ss[i];
    } else if (dd > ss) {
        for (size_t i = n; i > 0; i--) dd[i - 1] = ss[i - 1];
    }
    return d;
}

void *memset(void *d, int c, size_t n)
{
    unsigned char *dd = (unsigned char *)d;
    for (size_t i = 0; i < n; i++) dd[i] = (unsigned char)c;
    return d;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    (void)ptr; (void)size; (void)stream;
    return nmemb;
}

int memcmp(const void *a, const void *b, size_t n)
{
    const unsigned char *x = (const unsigned char *)a;
    const unsigned char *y = (const unsigned char *)b;
    for (size_t i = 0; i < n; i++)
        if (x[i] != y[i]) return (int)x[i] - (int)y[i];
    return 0;
}

size_t strlen(const char *s)
{
    size_t n = 0;
    while (s[n]) n++;
    return n;
}

int strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) { a++; b++; }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}

int strncmp(const char *a, const char *b, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        unsigned char ca = (unsigned char)a[i], cb = (unsigned char)b[i];
        if (ca != cb) return (int)ca - (int)cb;
        if (!ca) return 0;
    }
    return 0;
}

char *strcpy(char *d, const char *s)
{
    char *r = d;
    while ((*d++ = *s++)) {}
    return r;
}

/* diagnostics / process termination ------------------------------- */
FILE *stderr = 0;
FILE *stdout = 0;

int fprintf(FILE *stream, const char *fmt, ...)
{
    (void)stream; (void)fmt;
    return 0;
}

int vfprintf(FILE *stream, const char *fmt, va_list ap)
{
    (void)stream; (void)fmt; (void)ap;
    return 0;
}

int fputc(int c, FILE *stream)
{
    (void)stream;
    return c;
}

int puts(const char *s) { (void)s; return 0; }

void abort(void)
{
    __builtin_trap();
}

void exit(int code)
{
    (void)code;
    __builtin_trap();
}

void __stack_chk_fail(void) { __builtin_trap(); }

void __assert_fail(const char *a, const char *b, unsigned int c, const char *d)
{
    (void)a; (void)b; (void)c; (void)d;
    __builtin_trap();
}
