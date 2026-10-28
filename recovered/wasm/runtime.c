/*
 * Freestanding runtime for the WebAssembly build: mem*, a small
 * address-ordered first-fit allocator over the linear memory, strlen/strcmp
 * and a time() stub (the license markers are not used here).
 */
#include <stddef.h>
#include <stdint.h>
#include <time.h>

void *memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

void *memmove(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } else if (d > s) {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    }
    return dst;
}

void *memset(void *dst, int c, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    while (n--) {
        *d++ = (unsigned char)c;
    }
    return dst;
}

size_t strlen(const char *s)
{
    const char *p = s;
    while (*p) {
        p++;
    }
    return (size_t)(p - s);
}

int strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}

void abort(void)
{
    __builtin_trap();
}

time_t time(time_t *t)
{
    if (t) {
        *t = 0;
    }
    return 0;
}

/* ------------------------------------------------------------------ */
/* allocator                                                          */
/* ------------------------------------------------------------------ */
typedef struct Hdr {
    uint32_t size; /* payload size, not including this header */
    uint32_t used;
} Hdr;

#define ALIGN8(x) (((x) + 7u) & ~7u)
#define HDR 8u

extern unsigned char __heap_base;
static unsigned char *heap_end;

static Hdr *next_hdr(Hdr *h)
{
    return (Hdr *)((unsigned char *)h + HDR + h->size);
}

static int grow(size_t need)
{
    uint32_t have = (uint32_t)__builtin_wasm_memory_size(0) * 65536u;
    uint32_t end = (uint32_t)(uintptr_t)heap_end;
    if (end + need <= have) {
        return 1;
    }
    uint32_t pages = ((end + (uint32_t)need) - have + 65535u) / 65536u;
    if (__builtin_wasm_memory_grow(0, pages) == (size_t)-1) {
        return 0;
    }
    return 1;
}

static void *alloc_from_bump(size_t need)
{
    Hdr *h;
    if (!heap_end) {
        uintptr_t base = ((uintptr_t)&__heap_base + 7u) & ~(uintptr_t)7u;
        heap_end = (unsigned char *)base;
    }
    if (!grow(HDR + need)) {
        return NULL;
    }
    h = (Hdr *)heap_end;
    h->size = (uint32_t)need;
    h->used = 1;
    heap_end += HDR + need;
    return (unsigned char *)h + HDR;
}

void *malloc(size_t n)
{
    Hdr *h;
    size_t need;
    if (n == 0 || n > 0x7FFFFFFFu) {
        return NULL;
    }
    need = ALIGN8(n);
    if (!heap_end) {
        uintptr_t base = ((uintptr_t)&__heap_base + 7u) & ~(uintptr_t)7u;
        heap_end = (unsigned char *)base;
        return alloc_from_bump(need);
    }
    for (h = (Hdr *)(((uintptr_t)&__heap_base + 7u) & ~(uintptr_t)7u);
         (unsigned char *)h + HDR <= heap_end; h = next_hdr(h)) {
        if (h->used || h->size < need) {
            continue;
        }
        if (h->size >= need + HDR + 8u) {
            Hdr *rest = (Hdr *)((unsigned char *)h + HDR + need);
            rest->size = h->size - (uint32_t)(need + HDR);
            rest->used = 0;
            h->size = (uint32_t)need;
        }
        h->used = 1;
        return (unsigned char *)h + HDR;
    }
    return alloc_from_bump(need);
}

void free(void *ptr)
{
    Hdr *h;
    if (!ptr) {
        return;
    }
    h = (Hdr *)((unsigned char *)ptr - HDR);
    if ((unsigned char *)h < heap_end) {
        h->used = 0;
        /* coalesce with the next block */
        while (1) {
            Hdr *n = next_hdr(h);
            if ((unsigned char *)n + HDR > heap_end || n->used) {
                break;
            }
            h->size += (uint32_t)(HDR + n->size);
        }
        if ((unsigned char *)next_hdr(h) == heap_end) {
            heap_end = (unsigned char *)h;
        }
    }
}

void *realloc(void *ptr, size_t n)
{
    Hdr *h;
    void *nptr;
    if (!ptr) {
        return malloc(n);
    }
    if (!n) {
        free(ptr);
        return NULL;
    }
    h = (Hdr *)((unsigned char *)ptr - HDR);
    if (h->size >= n) {
        return ptr;
    }
    nptr = malloc(n);
    if (!nptr) {
        return NULL;
    }
    memcpy(nptr, ptr, h->size);
    free(ptr);
    return nptr;
}
