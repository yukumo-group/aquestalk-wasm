/* api.cpp -- hand written native API layer (embind removed).
 *
 * The conversion engine itself is the mechanically recompiled C in decomp.c;
 * this file only implements the public AqKanji2Koe ABI around it.
 */
#include "shim.h"

#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cstdio>

#if !defined(__EMSCRIPTEN__)
#include <unistd.h>
#endif

extern "C" void AqKanji2Koe_Release(void *h);
extern "C" int AqKanji2Koe_Convert(void *, const char *, char *, int);

namespace {

struct AqHandle {
    void *sysDic;
    void *userDic;
    void *analyzer;
    bool ownsDictionaries;
};

static void *aq_load_file(const char *path, unsigned int *pSize)
{
    *pSize = 0;
    FILE *fp = fopen(path, "rb");
    if (!fp)
        return nullptr;
    if (fseek(fp, 0, SEEK_END) != 0) { fclose(fp); return nullptr; }
    long n = ftell(fp);
    if (n < 0) { fclose(fp); return nullptr; }
    if (fseek(fp, 0, SEEK_SET) != 0) { fclose(fp); return nullptr; }
    void *p = malloc((size_t)n ? (size_t)n : 1);
    if (!p) { fclose(fp); return nullptr; }
    size_t got = fread(p, 1, (size_t)n, fp);
    fclose(fp);
    if (got != (size_t)n) { free(p); return nullptr; }
    *pSize = (unsigned int)n;
    return p;
}

static void aq_free_u16(AqU16 *s)
{
    if (s->p && s->p != s->u.buf)
        free(s->p);
}

static void aq_init_u16(AqU16 *s)
{
    s->p = s->u.buf;
    s->len = 0;
    s->u.buf[0] = 0;
}

static std::string aq_u16_to_utf8(const uint16_t *p, size_t n)
{
    std::string out;
    out.reserve(n * 3);
    for (size_t i = 0; i < n; i++) {
        uint32_t c = p[i];
        if (c >= 0xD800 && c <= 0xDBFF && i + 1 < n) {
            uint32_t d = p[i + 1];
            if (d >= 0xDC00 && d <= 0xDFFF) {
                c = 0x10000 + ((c - 0xD800) << 10) + (d - 0xDC00);
                i++;
            }
        }
        if (c < 0x80) {
            out.push_back((char)c);
        } else if (c < 0x800) {
            out.push_back((char)(0xC0 | (c >> 6)));
            out.push_back((char)(0x80 | (c & 0x3F)));
        } else if (c < 0x10000) {
            out.push_back((char)(0xE0 | (c >> 12)));
            out.push_back((char)(0x80 | ((c >> 6) & 0x3F)));
            out.push_back((char)(0x80 | (c & 0x3F)));
        } else {
            out.push_back((char)(0xF0 | (c >> 18)));
            out.push_back((char)(0x80 | ((c >> 12) & 0x3F)));
            out.push_back((char)(0x80 | ((c >> 6) & 0x3F)));
            out.push_back((char)(0x80 | (c & 0x3F)));
        }
    }
    return out;
}

static AqHandle *aq_create_from_buffers(void *sysDic, void *userDic, int *pErr,
                                        bool ownsDictionaries)
{
    AqHandle *h = (AqHandle *)calloc(1, sizeof(AqHandle));
    if (!h) {
        if (ownsDictionaries) { free(sysDic); free(userDic); }
        *pErr = 0x65;
        return nullptr;
    }
    h->sysDic = sysDic;
    h->userDic = userDic;
    h->ownsDictionaries = ownsDictionaries;
    h->analyzer = operator_new(0x100);
    FUN_0010c650((undefined1 *)h->analyzer);
    int err = (int)FUN_0010c6d0((undefined1 *)h->analyzer, (char *)sysDic,
                                (undefined8)(uintptr_t)userDic);
    if (err != 0) {
        if (h->ownsDictionaries) {
            free(h->sysDic);
            free(h->userDic);
            h->sysDic = nullptr;
            h->userDic = nullptr;
        }
        AqKanji2Koe_Release(h);
        *pErr = err;
        return nullptr;
    }
    *pErr = 0;
    return h;
}

} // namespace

extern "C" {

void *AqKanji2Koe_Create(const char *pathDic, int *pErr)
{
    aq_init_image();
    if (!pathDic || !pErr) {
        if (pErr) *pErr = 0x65;
        return nullptr;
    }
    std::string base(pathDic);
    if (base.empty() || base.back() != '/')
        base += '/';

    unsigned int sysSize = 0, userSize = 0;
    std::string lookupPath = base + "lookup.bin";
    aq_lookup_load(lookupPath.c_str());
    std::string sysPath = base + "aqdic.bin";
    void *sys = aq_load_file(sysPath.c_str(), &sysSize);
    if (!sys) {
        *pErr = 200;
        return nullptr;
    }
    std::string userPath = base + "aq_user.dic";
    void *user = aq_load_file(userPath.c_str(), &userSize);

    /* aq_create_from_buffers takes ownership (and frees on failure). */
    return aq_create_from_buffers(sys, user, pErr, true);
}

void *AqKanji2Koe_Create_Ptr(const void *pSysDic, const void *pUserDic, int *pErr)
{
    aq_init_image();
    if (!pSysDic || !pErr) {
        if (pErr) *pErr = 0x65;
        return nullptr;
    }
    return aq_create_from_buffers((void *)pSysDic, (void *)pUserDic, pErr, false);
}

void AqKanji2Koe_Release(void *h)
{
    AqHandle *a = (AqHandle *)h;
    if (!a)
        return;
    if (a->ownsDictionaries) {
        free(a->sysDic);
        free(a->userDic);
    }
    if (a->analyzer) {
        FUN_0010c6a0((undefined1 *)a->analyzer);
        operator_delete(a->analyzer);
    }
    free(a);
}

int AqKanji2Koe_Convert(void *hAqKanji2Koe, const char *kanji, char *koe, int nBufKoe)
{
    AqHandle *h = (AqHandle *)hAqKanji2Koe;
    if (!h || !kanji || !koe || nBufKoe <= 0)
        return 0x65;
    *koe = 0;
    if (*kanji == 0)
        return 0;

    AqU16 in, out;
    memset(&in, 0, sizeof(in));
    FUN_001094c0((long *)&in, (byte *)kanji);
    aq_init_u16(&out);

    int err = (int)FUN_0010cfe0((char *)h->analyzer,
                                (undefined8)(uintptr_t)in.p,
                                (undefined8)(uintptr_t)&out);
    if (err == 0) {
        std::string s = aq_u16_to_utf8(out.p, out.len);
        if (s.size() < (size_t)nBufKoe) {
            memcpy(koe, s.data(), s.size());
            koe[s.size()] = 0;
        } else {
            err = 0x69;
        }
    }
    aq_free_u16(&in);
    aq_free_u16(&out);
    return err;
}

int AqKanji2Koe_ConvRoman(void *hAqKanji2Koe, const char *kanji, char *koe, int nBufKoe)
{
    AqHandle *h = (AqHandle *)hAqKanji2Koe;
    if (!h || !kanji || !koe || nBufKoe <= 0)
        return 0x65;
    *koe = 0;
    if (*kanji == 0)
        return 0;

    AqU16 in, out;
    memset(&in, 0, sizeof(in));
    FUN_001094c0((long *)&in, (byte *)kanji);
    aq_init_u16(&out);

    int err = (int)FUN_0010cfe0((char *)h->analyzer,
                                (undefined8)(uintptr_t)in.p,
                                (undefined8)(uintptr_t)&out);
    if (err == 0) {
        AqStr rom;
        memset(&rom, 0, sizeof(rom));
        FUN_00109e90((long *)&rom, (undefined8 *)&out);
        if (rom.len + 1 <= (size_t)nBufKoe) {
            memcpy(koe, rom.p, rom.len);
            koe[rom.len] = 0;
        } else {
            err = 0x69;
        }
        if (rom.p && rom.p != rom.u.buf)
            free(rom.p);
    }
    aq_free_u16(&in);
    aq_free_u16(&out);
    return err;
}

int AqKanji2Koe_SetDevKey(const char *devKey)
{
    aq_init_image();
    if (!devKey)
        return 1;
    return (int)FUN_0010a600((char *)devKey);
}

} // extern "C"

/* An optional allocation helper so JS can hand dictionary bytes to
 * AqKanji2Koe_Create_Ptr without relying on Module._malloc. */
extern "C" int AqKanji2Koe_LoadLookup(const char *path)
{
    return aq_lookup_load(path);
}

extern "C" void *AqKanji2Koe_Alloc(unsigned long n)
{
    return malloc((size_t)n);
}


/* Native test driver: reads UTF-8 lines from stdin, writes kana symbols. */
int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <dic_dir> [--roman]\n", argv[0]);
        return 2;
    }
    int err = 0;
    void *h = AqKanji2Koe_Create(argv[1], &err);
    if (!h) {
        fprintf(stderr, "create failed: %d\n", err);
        return 1;
    }
    bool roman = argc > 2 && strcmp(argv[2], "--roman") == 0;
    char line[8192];
    char out[65536];
    while (fgets(line, sizeof(line), stdin)) {
        size_t n = strlen(line);
        while (n && (line[n - 1] == '\n' || line[n - 1] == '\r'))
            line[--n] = 0;
        int r = roman ? AqKanji2Koe_ConvRoman(h, line, out, sizeof(out))
                      : AqKanji2Koe_Convert(h, line, out, sizeof(out));
        if (r != 0) {
            fprintf(stderr, "convert error %d\n", r);
            break;
        }
        printf("%s\n", out);
    }
    AqKanji2Koe_Release(h);
    return 0;
}
