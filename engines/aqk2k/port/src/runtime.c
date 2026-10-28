/* Minimal freestanding runtime for the raw wasm32/wasm64 builds.
 * Provides the handful of libc entry points used by the recompiled code:
 * memory allocation, string operations, and no-op diagnostics.
 *
 * The allocator is a segregated free-list heap: exact 16-byte size classes
 * for small objects and an address-ordered list for large blocks.  It splits
 * larger blocks on allocation and zero-fills reused small blocks (the
 * decompiled code expects fresh objects to be zeroed).  Define AQK2K_LEAK to
 * switch to a simple bump arena for very short-lived workers.
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
    size_t64 size;        /* payload size (16-byte aligned), header excluded */
    struct Block *next;   /* free-list link */
} Block;

/* Segregated free lists.  Bin 0 holds blocks larger than SMALL_MAX (kept in
 * address order); bins 1..128 hold exact 16-byte size classes.  Splitting on
 * allocation keeps fragmentation bounded, and O(1) small-object reuse makes
 * long sessions and large inputs practical (the old single free list scanned
 * every block on every malloc/free). */
#define SMALL_MAX 2048u
#define NUM_BINS 129

static Block *bins[NUM_BINS];
static size_t64 heap_top;
static size_t64 heap_end;
static size_t64 heap_start;

static void heap_init(void)
{
    if (heap_top)
        return;
    heap_top = ALIGN16((size_t64)(uintptr_t)&__heap_base);
    heap_start = heap_top;
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

static int bin_index(size_t64 size)
{
    size &= ~(size_t64)15;
    if (size > SMALL_MAX)
        return 0;
    size_t64 i = size >> 4;
    if (i < 1)
        i = 1;
    if (i >= NUM_BINS)
        i = NUM_BINS - 1;
    return (int)i;
}

static void bin_insert(Block *b)
{
    int i = bin_index(b->size);
    if (i == 0) {
        Block **pp = &bins[0];
        while (*pp && *pp < b)
            pp = &(*pp)->next;
        b->next = *pp;
        *pp = b;
    } else {
        b->next = bins[i];
        bins[i] = b;
    }
}

static Block *bin_fit(size_t64 size)
{
    int start = bin_index(size);
    if (start > 0) {
        if (bins[start]) {
            Block *b = bins[start];
            bins[start] = b->next;
            return b;
        }
        for (int i = start + 1; i < NUM_BINS; i++) {
            if (bins[i]) {
                Block *b = bins[i];
                bins[i] = b->next;
                return b;
            }
        }
    }
    /* Large blocks: first fit in address order. */
    Block **pp = &bins[0];
    while (*pp) {
        if ((*pp)->size >= size) {
            Block *b = *pp;
            *pp = b->next;
            return b;
        }
        pp = &(*pp)->next;
    }
    return 0;
}

void *malloc(size_t n)
{
    heap_init();
#ifdef AQK2K_LEAK
    size_t64 size = ALIGN16((size_t64)n);
    if (size < 16)
        size = 16;
    size_t64 need = sizeof(Block) + size;
    if (!heap_grow(need))
        return 0;
    Block *b = (Block *)(uintptr_t)heap_top;
    b->size = size | 1;
    b->next = 0;
    heap_top += need;
    return (void *)((unsigned char *)b + sizeof(Block));
#else
    size_t64 size = ALIGN16((size_t64)n);
    if (size < 16)
        size = 16;

    Block *b = bin_fit(size);
    if (b) {
        if (b->size >= size + sizeof(Block) + 16) {
            Block *rest = (Block *)((unsigned char *)b + sizeof(Block) + size);
            rest->size = (b->size & ~(size_t64)15) - size - sizeof(Block);
            rest->next = 0;
            bin_insert(rest);
            b->size = size | 1;
        } else {
            b->size = (b->size & ~(size_t64)15) | 1;
        }
        if (size <= SMALL_MAX) {
            /* The decompiled code expects zero-filled small objects; reused
             * large buffers (dictionary blobs, output buffers) are always
             * written before they are read. */
            unsigned char *q = (unsigned char *)b + sizeof(Block);
            for (size_t64 i = 0; i < size; i++) q[i] = 0;
        }
        return (void *)((unsigned char *)b + sizeof(Block));
    }

    size_t64 need = sizeof(Block) + size;
    if (!heap_grow(need))
        return 0;
    b = (Block *)(uintptr_t)heap_top;
    b->size = size | 1;
    b->next = 0;
    heap_top += need;
    /* Freshly grown wasm pages are zero-filled; no clearing needed here. */
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
    if ((size_t64)(uintptr_t)b < heap_start || (size_t64)(uintptr_t)b >= heap_top ||
        !(b->size & 1))
        __builtin_trap();
    b->size &= ~(size_t64)1;
    bin_insert(b);
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
    if ((b->size & ~(size_t64)15) >= (size_t64)n)
        return p;
    void *q = malloc(n);
    if (!q)
        return 0;
    unsigned char *src = (unsigned char *)p, *dst = (unsigned char *)q;
    for (size_t64 i = 0; i < (b->size & ~(size_t64)15); i++)
        dst[i] = src[i];
    free(p);
    return q;
}

/* string routines --------------------------------------------------- */
typedef unsigned long aq_word;

#define AQ_WSZ ((size_t64)sizeof(aq_word))
#define AQ_HASZERO(w) (((w) - (aq_word)0x0101010101010101ULL) & \
                       ~(w) & (aq_word)0x8080808080808080ULL)

void *memcpy(void *d, const void *s, size_t n)
{
    unsigned char *dd = (unsigned char *)d;
    const unsigned char *ss = (const unsigned char *)s;

    while (n && ((uintptr_t)dd & (AQ_WSZ - 1))) {
        *dd++ = *ss++;
        n--;
    }
    if (AQ_WSZ == 8) {
        aq_word *dw = (aq_word *)dd;
        const aq_word *sw = (const aq_word *)ss;
        while (n >= 8) {
            *dw++ = *sw++;
            n -= 8;
        }
        dd = (unsigned char *)dw;
        ss = (const unsigned char *)sw;
    } else {
        while (n >= 4) {
            *(unsigned int *)dd = *(const unsigned int *)ss;
            dd += 4; ss += 4; n -= 4;
        }
    }
    while (n--)
        *dd++ = *ss++;
    return d;
}

void *memmove(void *d, const void *s, size_t n)
{
    unsigned char *dd = (unsigned char *)d;
    const unsigned char *ss = (const unsigned char *)s;
    if (dd == ss || n == 0)
        return d;
    if (dd < ss || dd >= ss + n)
        return memcpy(d, s, n);
    /* Overlapping and moving down: copy backwards. */
    dd += n;
    ss += n;
    while (n && ((uintptr_t)dd & (AQ_WSZ - 1))) {
        *--dd = *--ss;
        n--;
    }
    if (AQ_WSZ == 8) {
        aq_word *dw = (aq_word *)dd;
        const aq_word *sw = (const aq_word *)ss;
        while (n >= 8) {
            *--dw = *--sw;
            n -= 8;
        }
        dd = (unsigned char *)dw;
        ss = (const unsigned char *)sw;
    } else {
        while (n >= 4) {
            dd -= 4; ss -= 4;
            *(unsigned int *)dd = *(const unsigned int *)ss;
            n -= 4;
        }
    }
    while (n--)
        *--dd = *--ss;
    return d;
}

void *memset(void *d, int c, size_t n)
{
    unsigned char *dd = (unsigned char *)d;
    unsigned char b = (unsigned char)c;

    while (n && ((uintptr_t)dd & (AQ_WSZ - 1))) {
        *dd++ = b;
        n--;
    }
    if (AQ_WSZ == 8) {
        aq_word w = (aq_word)0x0101010101010101ULL * b;
        aq_word *dw = (aq_word *)dd;
        while (n >= 8) {
            *dw++ = w;
            n -= 8;
        }
        dd = (unsigned char *)dw;
    } else {
        unsigned int w = 0x01010101u * b;
        while (n >= 4) {
            *(unsigned int *)dd = w;
            dd += 4; n -= 4;
        }
    }
    while (n--)
        *dd++ = b;
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
    const char *p = s;
    while ((uintptr_t)p & (AQ_WSZ - 1)) {
        if (!*p)
            return (size_t)(p - s);
        p++;
    }
    for (;;) {
        aq_word w = *(const aq_word *)p;
        if (AQ_HASZERO(w))
            break;
        p += AQ_WSZ;
    }
    while (*p)
        p++;
    return (size_t)(p - s);
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
