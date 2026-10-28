/* lookup_c.c -- freestanding surface -> dictionary id hash table.
 * The table is produced by tools/gen_lookup.mjs (format "K2KL").
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

int aq_lookup_init(const void *data, unsigned size)
{
    const unsigned char *d = (const unsigned char *)data;
    if (!d || size < 12 || d[0] != 'K' || d[1] != '2' || d[2] != 'K' || d[3] != 'L')
        return 1;
    unsigned count = rd32(d + 4);
    if (count == 0)
        return 1;

    unsigned cap = 16;
    while (cap < count * 2u && cap < (1u << 22))
        cap <<= 1;

    uint32_t *slots = (uint32_t *)malloc((size_t)cap * sizeof(uint32_t));
    if (!slots)
        return 1;
    memset(slots, 0, (size_t)cap * sizeof(uint32_t));

    unsigned maxlen = 1;
    unsigned off = 12;
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

    if (g_lookup.slots)
        free(g_lookup.slots);
    g_lookup.data = d;
    g_lookup.size = size;
    g_lookup.count = count;
    g_lookup.cap = cap;
    g_lookup.maxLen = maxlen;
    g_lookup.slots = slots;
    g_lookup.ready = 1;
    return 0;
}

int aq_lookup_ready(void)
{
    return g_lookup.ready;
}

int aq_lookup_prefix(const uint16_t *key, int units, int *outLen, uint32_t *outId)
{
    if (!g_lookup.ready || !key || units <= 0)
        return 0;
    unsigned cap = (unsigned)units;
    if (cap > g_lookup.maxLen)
        cap = g_lookup.maxLen;
    for (unsigned n = cap; n >= 1; n--) {
        uint32_t h = hash16(key, n);
        unsigned idx = h & (g_lookup.cap - 1);
        while (g_lookup.slots[idx]) {
            unsigned eoff = g_lookup.slots[idx] - 1;
            if (key_eq(g_lookup.data + eoff, key, n)) {
                *outLen = (int)n;
                *outId = rd32(g_lookup.data + eoff + 4);
                return 1;
            }
            idx = (idx + 1) & (g_lookup.cap - 1);
        }
    }
    return 0;
}

#ifndef AQK2K_WASM
#include <stdio.h>
int aq_lookup_load(const char *path)
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
#endif
