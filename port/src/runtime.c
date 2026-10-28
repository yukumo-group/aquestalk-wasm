/* runtime.c -- freestanding runtime for the native WebAssembly build.
 *
 * The module is linked with -nostdlib and has *no imports*: this file
 * provides memcpy/memset/memmove and a small boundary-tag allocator on top of
 * the linear memory.  The stack lives below the data segment (wasm-ld default
 * layout), so the heap grows upwards from __heap_base.
 *
 * The same allocator can be built for the host (-DAQ_RT_TEST) to fuzz it.
 */
#include <stddef.h>
#include <stdint.h>

#ifdef AQ_RT_TEST
/* Host unit-test back end: a fixed arena, no wasm builtins. */
static unsigned char rt_arena[32u * 1024u * 1024u];
static unsigned char *rt_base_ptr(void) { return rt_arena + 64; }
static uint32_t rt_capacity(void) { return (uint32_t)sizeof rt_arena - 64u; }
static int rt_mem_grow(uint32_t need) { (void)need; return 0; }
#else
extern unsigned char __heap_base;
static unsigned char *rt_base_ptr(void) { return &__heap_base; }
static uint32_t rt_capacity(void)
{
    uint32_t limit = __builtin_wasm_memory_size(0) * 65536u;
    uint32_t base = (uint32_t)(uintptr_t)&__heap_base;
    return limit > base ? limit - base : 0;
}
static int rt_mem_grow(uint32_t need)
{
    uint32_t have = rt_capacity();
    if (need <= have)
        return 1;
    uint32_t pages = (need - have + 65535u) / 65536u;
    /* returns the previous page count, or -1 on failure */
    if (__builtin_wasm_memory_grow(0, pages) == (size_t)-1)
        return 0;
    return 1;
}
#endif

/* ------------------------------------------------------------------ */
/* mem* (also referenced directly by compiler generated code)         */
/* ------------------------------------------------------------------ */
void *memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    while (n--)
        *d++ = *s++;
    return dst;
}

void *memmove(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    if (d < s) {
        while (n--)
            *d++ = *s++;
    } else if (d > s) {
        d += n;
        s += n;
        while (n--)
            *--d = *--s;
    }
    return dst;
}

void *memset(void *dst, int c, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    while (n--)
        *d++ = (unsigned char)c;
    return dst;
}

void abort(void)
{
    __builtin_trap();
}

/* ------------------------------------------------------------------ */
/* allocator                                                          */
/* ------------------------------------------------------------------ */
/* Block header (8 bytes).  `size` includes the header and has bit 0 set
 * when the block is in use; `prev` is the size of the previous physical
 * block (0 for the first block).  Payloads are 8 byte aligned. */
typedef struct Hdr {
    uint32_t size;
    uint32_t prev;
} Hdr;

typedef struct Free {
    Hdr *next;
    Hdr *prev;
} Free;

#define HDR_SIZE   8u
#define MIN_BLOCK  32u
#define ALIGN8(x)  (((x) + 7u) & ~7u)
#define BSIZE(h)   ((h)->size & ~7u)
#define IS_USED(h) ((h)->size & 1u)
#define PAYLOAD(h) ((void *)((unsigned char *)(h) + HDR_SIZE))

static unsigned char *heap_start;
static unsigned char *heap_end;
static uint32_t last_block_size;
static Hdr *free_head;

static void free_insert(Hdr *h)
{
    Free *f = (Free *)PAYLOAD(h);
    f->prev = 0;
    f->next = free_head;
    if (free_head)
        ((Free *)PAYLOAD(free_head))->prev = h;
    free_head = h;
}

static void free_remove(Hdr *h)
{
    Free *f = (Free *)PAYLOAD(h);
    if (f->prev)
        ((Free *)PAYLOAD(f->prev))->next = f->next;
    else
        free_head = f->next;
    if (f->next)
        ((Free *)PAYLOAD(f->next))->prev = f->prev;
}

static void heap_init(void)
{
    uintptr_t base = (uintptr_t)rt_base_ptr();
    base = (base + 7u) & ~(uintptr_t)7u;
    heap_start = heap_end = (unsigned char *)base;
    last_block_size = 0;
    free_head = 0;
}

static int heap_ensure(uint32_t need)
{
    uint32_t used = (uint32_t)(heap_end - heap_start);
    if (used + need <= rt_capacity())
        return 1;
    if (!rt_mem_grow(used + need + 65536u))
        return 0;
    return used + need <= rt_capacity();
}

void *malloc(size_t n)
{
    if (n > 0xFFFFFF00u)
        return 0;
    if (!heap_start)
        heap_init();

    uint32_t need = ALIGN8((uint32_t)n) + HDR_SIZE;
    if (need < MIN_BLOCK)
        need = MIN_BLOCK;

    for (Hdr *h = free_head; h; h = ((Free *)PAYLOAD(h))->next) {
        uint32_t bs = BSIZE(h);
        if (bs < need)
            continue;
        free_remove(h);
        if (bs - need >= MIN_BLOCK) {
            Hdr *rest = (Hdr *)((unsigned char *)h + need);
            rest->size = bs - need;
            rest->prev = need;
            Hdr *after = (Hdr *)((unsigned char *)rest + (bs - need));
            if ((unsigned char *)after < heap_end)
                after->prev = bs - need;
            free_insert(rest);
            h->size = need | 1u;
        } else {
            h->size = bs | 1u;
            need = bs;
        }
        return PAYLOAD(h);
    }

    if (!heap_ensure(need))
        return 0;
    Hdr *h = (Hdr *)heap_end;
    h->size = need | 1u;
    h->prev = last_block_size;
    heap_end += need;
    last_block_size = need;
    return PAYLOAD(h);
}

void free(void *p)
{
    if (!p)
        return;
    Hdr *h = (Hdr *)((unsigned char *)p - HDR_SIZE);
    if (!IS_USED(h))
        return; /* double free: ignore */

    uint32_t bs = BSIZE(h);
    h->size = bs;

    Hdr *next = (Hdr *)((unsigned char *)h + bs);
    if ((unsigned char *)next < heap_end && !IS_USED(next)) {
        free_remove(next);
        bs += BSIZE(next);
        h->size = bs;
    }

    if (h->prev) {
        Hdr *prev = (Hdr *)((unsigned char *)h - h->prev);
        if (!IS_USED(prev)) {
            free_remove(prev);
            bs += BSIZE(prev);
            prev->size = bs;
            h = prev;
        }
    }

    Hdr *after = (Hdr *)((unsigned char *)h + bs);
    if ((unsigned char *)after < heap_end)
        after->prev = bs;

    if ((unsigned char *)h + bs == heap_end) {
        heap_end = (unsigned char *)h;
        last_block_size = h->prev;
    } else {
        free_insert(h);
    }
}
