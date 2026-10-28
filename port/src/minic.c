/* minic.c -- the tiny freestanding C runtime used by the raw wasm build.
 *
 * The wasm module is linked with -nostdlib (no Emscripten, no WASI).  The
 * engine only needs malloc/free/memcpy/memset/memmove, so a small free-list
 * allocator plus the memory routines is enough.
 */
#include <stddef.h>
#include <stdint.h>

extern unsigned char __heap_base;

void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memmove(void *, const void *, size_t);
int memcmp(const void *, const void *, size_t);

typedef struct Block {
    uint32_t size;          /* total size, including this header */
    uint32_t used;
    struct Block *next;     /* free list link */
    uint32_t pad;
} Block;

#define HDR 16u
#define ALIGN 16u

static Block *free_list;
static uintptr_t heap_top;
static uintptr_t mem_end;

static uintptr_t align_up(uintptr_t p, uintptr_t a)
{
    return (p + a - 1) & ~(a - 1);
}

static int mem_reserve(uintptr_t end)
{
    if (end <= mem_end)
        return 1;
    uint32_t pages = (uint32_t)((end - mem_end + 65535u) >> 16);
    if (__builtin_wasm_memory_grow(0, pages) == (size_t)-1)
        return 0;
    mem_end += (uintptr_t)pages << 16;
    return 1;
}

void *malloc(size_t n)
{
    if (!heap_top) {
        heap_top = align_up((uintptr_t)&__heap_base, ALIGN);
        mem_end = (uintptr_t)__builtin_wasm_memory_size(0) << 16;
    }
    size_t need = align_up(n ? n : 1, ALIGN) + HDR;

    Block **pp = &free_list;
    while (*pp) {
        Block *b = *pp;
        if (b->size >= need) {
            if (b->size - need >= HDR + ALIGN) {
                Block *rest = (Block *)((unsigned char *)b + need);
                rest->size = b->size - (uint32_t)need;
                rest->used = 0;
                rest->next = b->next;
                *pp = rest;
                b->size = (uint32_t)need;
            } else {
                *pp = b->next;
            }
            b->used = 1;
            b->next = 0;
            return (unsigned char *)b + HDR;
        }
        pp = &b->next;
    }

    uintptr_t p = heap_top;
    uintptr_t q = p + need;
    if (!mem_reserve(q))
        return 0;
    heap_top = q;
    Block *b = (Block *)p;
    b->size = (uint32_t)need;
    b->used = 1;
    b->next = 0;
    return (unsigned char *)b + HDR;
}

void free(void *ptr)
{
    if (!ptr)
        return;
    Block *b = (Block *)((unsigned char *)ptr - HDR);
    if (!b->used)
        return;
    b->used = 0;

    /* insert into the address-ordered free list */
    Block **pp = &free_list;
    while (*pp && *pp < b)
        pp = &(*pp)->next;
    b->next = *pp;
    *pp = b;

    /* coalesce with the following block */
    if (b->next && (unsigned char *)b + b->size == (unsigned char *)b->next) {
        b->size += b->next->size;
        b->next = b->next->next;
    }
    /* coalesce with the preceding block */
    if (pp != &free_list) {
        Block *prev = (Block *)((unsigned char *)pp - offsetof(Block, next));
        if ((unsigned char *)prev + prev->size == (unsigned char *)b) {
            prev->size += b->size;
            prev->next = b->next;
        }
    }
}

void *calloc(size_t n, size_t size)
{
    size_t total = n * size;
    void *p = malloc(total);
    if (p)
        memset(p, 0, total);
    return p;
}

__attribute__((noinline, optnone))
void *memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    while (n--)
        *d++ = *s++;
    return dst;
}

__attribute__((noinline, optnone))
void *memset(void *dst, int c, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    while (n--)
        *d++ = (unsigned char)c;
    return dst;
}

__attribute__((noinline, optnone))
void *memmove(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    if (d < s) {
        while (n--)
            *d++ = *s++;
    } else {
        d += n;
        s += n;
        while (n--)
            *--d = *--s;
    }
    return dst;
}

__attribute__((noinline, optnone))
int memcmp(const void *a, const void *b, size_t n)
{
    const unsigned char *x = (const unsigned char *)a;
    const unsigned char *y = (const unsigned char *)b;
    while (n--) {
        if (*x != *y)
            return (int)*x - (int)*y;
        x++; y++;
    }
    return 0;
}

size_t strlen(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return (size_t)(p - s);
}

void abort(void)
{
    __builtin_trap();
}
