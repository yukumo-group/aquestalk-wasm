/* lookup_c.c -- freestanding surface -> dictionary id hash table.
 * The table is produced by tools/gen_lookup.mjs.
 *
 * Two tables are stored in one file so the wasm32 build can serve both the
 * master dictionary (MSTD) and the single-character reading dictionary
 * (MCGD) without running the decompiled MARISA search (whose 32-bit pointer
 * arithmetic is not reliable under wasm32).
 *
 *   "K2KL" u32 count, u32 0, entries...              (legacy, MSTD only)
 *   "K2K2" u32 count_mstd, u32 count_mcgd, entries... (MSTD then MCGD)
 *
 * entry: u32 key_len_in_u16, u32 record_id, key_len_in_u16 * u16le key
 */
#include "shim.h"

typedef struct {
    const unsigned char *data;
    unsigned size;
    unsigned count;
    unsigned cap;          /* power of two */
    unsigned maxLen;
    uint32_t *slots;       /* entry offset + 1, 0 = empty */
    int ready;
} Lookup;

static Lookup g_lookup;
static Lookup g_lookup_mcgd;
static void *g_slots[16];
static int g_slot_kind[16];
static int g_nslots;

static uint32_t rd32(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint32_t hash16(const uint16_t *k, unsigned n)
{
    uint32_t h = 2166136261u;
    const unsigned char *p = (const unsigned char *)k;
    for (unsigned i = 0; i < n * 2u; i++) {
        h ^= p[i];
        h *= 16777619u;
    }
    return h;
}

static int key_eq(const unsigned char *entry, const uint16_t *k, unsigned n)
{
    unsigned klen = rd32(entry);
    if (klen != n)
        return 0;
    const uint16_t *ek = (const uint16_t *)(entry + 8);
    for (unsigned i = 0; i < n; i++)
        if (ek[i] != k[i])
            return 0;
    return 1;
}

/* Parse `count` entries starting at `off` and replace *lp.  Returns the byte
 * offset just past the last entry. */
static unsigned lookup_build(Lookup *lp, const unsigned char *d, unsigned size,
                             unsigned off, unsigned count)
{
    if (count == 0)
        return off;

    unsigned cap = 16;
    while (cap < count * 2u && cap < (1u << 22))
        cap <<= 1;

    uint32_t *slots = (uint32_t *)malloc((size_t)cap * sizeof(uint32_t));
    if (!slots)
        return off;
    memset(slots, 0, (size_t)cap * sizeof(uint32_t));

    unsigned maxlen = 1;
    unsigned start = off;
    for (unsigned i = 0; i < count; i++) {
        if (off + 8 > size)
            break;
        unsigned klen = rd32(d + off);
        if (off + 8 + (size_t)klen * 2 > size)
            break;
        const uint16_t *key = (const uint16_t *)(d + off + 8);
        uint32_t h = hash16(key, klen);
        unsigned idx = h & (cap - 1);
        while (slots[idx]) {
            unsigned eoff = slots[idx] - 1;
            if (key_eq(d + eoff, key, klen))
                break;
            idx = (idx + 1) & (cap - 1);
        }
        if (!slots[idx])
            slots[idx] = off + 1;
        if (klen > maxlen)
            maxlen = klen;
        off += 8 + klen * 2;
    }

    if (lp->slots)
        free(lp->slots);
    lp->data = d;
    lp->size = size;
    lp->count = count;
    lp->cap = cap;
    lp->maxLen = maxlen;
    lp->slots = slots;
    lp->ready = 1;
    (void)start;
    return off;
}

int aq_lookup_init(const void *data, unsigned size)
{
    const unsigned char *d = (const unsigned char *)data;
    if (!d || size < 12)
        return 1;
    unsigned off = 12;
    if (d[0] == 'K' && d[1] == '2' && d[2] == 'K' && d[3] == 'L') {
        unsigned count = rd32(d + 4);
        if (count == 0)
            return 1;
        off = lookup_build(&g_lookup, d, size, off, count);
        /* Legacy file: no MCGD table. */
        if (g_lookup_mcgd.slots) {
            free(g_lookup_mcgd.slots);
            g_lookup_mcgd.slots = 0;
        }
        g_lookup_mcgd.ready = 0;
        return 0;
    }
    if (d[0] == 'K' && d[1] == '2' && d[2] == 'K' && d[3] == '2') {
        unsigned mstdCount = rd32(d + 4);
        unsigned mcgdCount = rd32(d + 8);
        if (mstdCount == 0)
            return 1;
        off = lookup_build(&g_lookup, d, size, off, mstdCount);
        if (mcgdCount)
            lookup_build(&g_lookup_mcgd, d, size, off, mcgdCount);
        else
            g_lookup_mcgd.ready = 0;
        return 0;
    }
    return 1;
}

void aq_lookup_register_slot(void *slot, int kind)
{
    if (!slot) return;
    for (int i = 0; i < g_nslots; i++)
        if (g_slots[i] == slot) { g_slot_kind[i] = kind; return; }
    if (g_nslots < 16) {
        g_slots[g_nslots] = slot;
        g_slot_kind[g_nslots] = kind;
        g_nslots++;
    }
}

int aq_lookup_slot_kind(void *slot)
{
    for (int i = 0; i < g_nslots; i++)
        if (g_slots[i] == slot) {
            if (g_slot_kind[i] == 1 && !g_lookup_mcgd.ready)
                return -1;
            return g_slot_kind[i];
        }
    return -1;
}

int aq_lookup_slot_ok(void *slot)
{
    return aq_lookup_slot_kind(slot) >= 0;
}

int aq_lookup_ready(void)
{
    return g_lookup.ready;
}

static Lookup *lookup_for_kind(int kind)
{
    return kind == 1 ? &g_lookup_mcgd : &g_lookup;
}

int aq_lookup_prefix_after(int kind, const uint16_t *key, int units, int after,
                           int *outLen, uint32_t *outId)
{
    Lookup *l = lookup_for_kind(kind);
    if (!l->ready || !key || units <= 0)
        return 0;
    if (after < 0)
        after = 0;
    unsigned cap = (unsigned)units;
    if (cap > l->maxLen)
        cap = l->maxLen;
    for (unsigned n = (unsigned)after + 1; n <= cap; n++) {
        uint32_t h = hash16(key, n);
        unsigned idx = h & (l->cap - 1);
        while (l->slots[idx]) {
            unsigned eoff = l->slots[idx] - 1;
            if (key_eq(l->data + eoff, key, n)) {
                *outLen = (int)n;
                *outId = rd32(l->data + eoff + 4);
                return 1;
            }
            idx = (idx + 1) & (l->cap - 1);
        }
    }
    return 0;
}

int aq_lookup_prefix(const uint16_t *key, int units, int *outLen, uint32_t *outId)
{
    return aq_lookup_prefix_after(0, key, units, 0, outLen, outId);
}

#ifndef AQK2K_WASM

#include <stdio.h>

static int lookup_load_file(const char *path)
{
    FILE *fp = fopen(path, "rb");
    if (!fp) return 1;
    fseek(fp, 0, SEEK_END);
    long n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (n < 12) { fclose(fp); return 1; }
    unsigned char *buf = (unsigned char *)malloc((size_t)n);
    if (!buf) { fclose(fp); return 1; }
    size_t got = fread(buf, 1, (size_t)n, fp);
    fclose(fp);
    if (got != (size_t)n) { free(buf); return 1; }
    return aq_lookup_init(buf, (unsigned)n);
}

int aq_lookup_load(const char *path)
{
    return lookup_load_file(path);
}
#endif
