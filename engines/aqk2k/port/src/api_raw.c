/* api_raw.c -- C-only public API for the freestanding wasm build.
 * No embind, no C++ standard library.
 */
#include "shim.h"

typedef struct AqHandle {
    void *sysDic;
    void *userDic;
    void *analyzer;
} AqHandle;

extern int aq_lookup_init(const void *data, unsigned size);
extern void aq_release(void *handle);

static void free_u16(AqU16 *s)
{
    if (s->p && s->p != s->u.buf)
        free(s->p);
}

static void init_u16(AqU16 *s)
{
    s->p = s->u.buf;
    s->len = 0;
    s->u.buf[0] = 0;
}

static int u16_to_utf8(const uint16_t *p, size_t n, char *out, int cap)
{
    size_t o = 0;
    for (size_t i = 0; i < n; i++) {
        unsigned int c = p[i];
        if (c >= 0xD800 && c <= 0xDBFF && i + 1 < n) {
            unsigned int d = p[i + 1];
            if (d >= 0xDC00 && d <= 0xDFFF) {
                c = 0x10000 + ((c - 0xD800) << 10) + (d - 0xDC00);
                i++;
            }
        }
        unsigned char buf[4];
        int len;
        if (c < 0x80) { buf[0] = (unsigned char)c; len = 1; }
        else if (c < 0x800) {
            buf[0] = (unsigned char)(0xC0 | (c >> 6));
            buf[1] = (unsigned char)(0x80 | (c & 0x3F));
            len = 2;
        } else if (c < 0x10000) {
            buf[0] = (unsigned char)(0xE0 | (c >> 12));
            buf[1] = (unsigned char)(0x80 | ((c >> 6) & 0x3F));
            buf[2] = (unsigned char)(0x80 | (c & 0x3F));
            len = 3;
        } else {
            buf[0] = (unsigned char)(0xF0 | (c >> 18));
            buf[1] = (unsigned char)(0x80 | ((c >> 12) & 0x3F));
            buf[2] = (unsigned char)(0x80 | ((c >> 6) & 0x3F));
            buf[3] = (unsigned char)(0x80 | (c & 0x3F));
            len = 4;
        }
        if (o + (size_t)len >= (size_t)cap)
            return -1;
        for (int k = 0; k < len; k++)
            out[o++] = (char)buf[k];
    }
    out[o] = 0;
    return (int)o;
}

void aq_init(void)
{
    aq_init_image();
}

void *aq_alloc(unsigned long n)
{
    return malloc((size_t)n);
}

void aq_free(void *p)
{
    free(p);
}

int aq_set_lookup(const void *data, unsigned size)
{
    return aq_lookup_init(data, size);
}

void *aq_create(const void *sysDic, const void *userDic, int *pErr)
{
    aq_init_image();
    if (!sysDic || !pErr) {
        if (pErr) *pErr = 0x65;
        return 0;
    }
    AqHandle *h = (AqHandle *)malloc(sizeof(AqHandle));
    if (!h) { *pErr = 0x65; return 0; }
    h->sysDic = (void *)sysDic;
    h->userDic = (void *)userDic;
    h->analyzer = operator_new(0x100);
    FUN_0010c650((undefined1 *)h->analyzer);
    int err = (int)FUN_0010c6d0((undefined1 *)h->analyzer, (char *)sysDic,
                                (undefined8)(uintptr_t)userDic);
    if (err != 0) {
        aq_release(h);
        *pErr = err;
        return 0;
    }
    *pErr = 0;
    return h;
}

void aq_release(void *handle)
{
    AqHandle *h = (AqHandle *)handle;
    if (!h)
        return;
    free(h->sysDic);
    free(h->userDic);
    if (h->analyzer) {
        FUN_0010c6a0((undefined1 *)h->analyzer);
        operator_delete(h->analyzer);
    }
    free(h);
}

int aq_convert(void *handle, const char *kanji, char *koe, int nBuf)
{
    AqHandle *h = (AqHandle *)handle;
    if (!h || !kanji || !koe || nBuf <= 0)
        return 0x65;
    koe[0] = 0;
    if (!kanji[0])
        return 0;

    AqU16 in, out;
    memset(&in, 0, sizeof(in));
    FUN_001094c0((long *)&in, (byte *)kanji);
    init_u16(&out);
    int err = (int)FUN_0010cfe0((char *)h->analyzer,
                                (undefined8)(uintptr_t)in.p,
                                (undefined8)(uintptr_t)&out);
    if (err == 0) {
        if (u16_to_utf8(out.p, out.len, koe, nBuf) < 0)
            err = 0x69;
    }
    free_u16(&in);
    free_u16(&out);
    return err;
}

int aq_conv_roman(void *handle, const char *kanji, char *koe, int nBuf)
{
    AqHandle *h = (AqHandle *)handle;
    if (!h || !kanji || !koe || nBuf <= 0)
        return 0x65;
    koe[0] = 0;
    if (!kanji[0])
        return 0;

    AqU16 in, out;
    memset(&in, 0, sizeof(in));
    FUN_001094c0((long *)&in, (byte *)kanji);
    init_u16(&out);
    int err = (int)FUN_0010cfe0((char *)h->analyzer,
                                (undefined8)(uintptr_t)in.p,
                                (undefined8)(uintptr_t)&out);
    if (err == 0) {
        AqStr rom;
        memset(&rom, 0, sizeof(rom));
        FUN_00109e90((long *)&rom, (undefined8 *)&out);
        if (rom.len + 1 <= (size_t)nBuf) {
            for (size_t i = 0; i < rom.len; i++)
                koe[i] = rom.p[i];
            koe[rom.len] = 0;
        } else {
            err = 0x69;
        }
        if (rom.p && rom.p != rom.u.buf)
            free(rom.p);
    }
    free_u16(&in);
    free_u16(&out);
    return err;
}

int aq_set_devkey(const char *key)
{
    aq_init_image();
    if (!key)
        return 1;
    return (int)FUN_0010a600((char *)key);
}
