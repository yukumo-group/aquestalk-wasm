/* api.cpp -- public AquesTalk2 API and embind bindings.
 *
 * The synthesis engine itself is the mechanically recompiled C in decomp.c.
 * This file reproduces the original ABI wrappers (which only handle text
 * encoding conversion and buffer allocation) and exposes the library to
 * JavaScript.
 */
#include "shim.h"

#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
#include <emscripten/val.h>
#endif

extern "C" {

/* Conversion helpers recovered from the original library. */
int FUN_00102be4(char *param_1);                       /* SJIS string length       */
char *FUN_00102d33(char *param_1, char *param_2);      /* SJIS strcpy              */
int FUN_001019f0(char *param_1, undefined1 *param_2, int param_3);              /* EUC  -> SJIS */
int FUN_00101b2f(char *param_1, undefined1 *param_2, int param_3);              /* UTF8 -> SJIS */
int FUN_00101c6e(ushort *param_1, undefined1 *param_2, int param_3);            /* UTF16-> SJIS */
int FUN_00101dd6(char *param_1, undefined1 *param_2, int param_3);              /* roman-> SJIS */

/* Core engine: kana (Shift-JIS) -> WAV. */
undefined8 FUN_001012f4(undefined8 koe, undefined2 iSpeed, int *pSize, int64_t phontDat);

} /* extern "C" */

namespace {

inline unsigned char *aq_synthe_core(char *sjis, int speed, int *pSize, void *phont)
{
    aq_init_image();
    return (unsigned char *)FUN_001012f4((undefined8)(uintptr_t)sjis, (undefined2)speed,
                                         pSize, (int64_t)(uintptr_t)phont);
}

} /* namespace */

extern "C" {

/* ------------------------------------------------------------------ */
/* Public ABI -- mirrors the wrapper code of the original shared object */
/* ------------------------------------------------------------------ */

unsigned char *AquesTalk2_Synthe(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    int err = 0;
    void *work = NULL;
    unsigned char *wav = NULL;

    int len = FUN_00102be4((char *)koe);
    if (len != 0) {
        work = malloc((size_t)len + 1);
        if (!work) {
            err = 0x65;
        } else {
            FUN_00102d33((char *)work, (char *)koe);
            wav = aq_synthe_core((char *)work, iSpeed, pSize, phontDat);
        }
    }
    free(work);
    if (err != 0)
        *pSize = err;
    return wav;
}

unsigned char *AquesTalk2_Synthe_Euc(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    int err = 0;
    void *work = NULL;
    unsigned char *wav = NULL;

    int len = FUN_00102be4((char *)koe);
    if (len != 0) {
        work = malloc((size_t)len + 1);
        if (!work) {
            err = 0x65;
        } else {
            err = FUN_001019f0((char *)koe, (undefined1 *)work, len + 1);
            if (err == 0)
                wav = aq_synthe_core((char *)work, iSpeed, pSize, phontDat);
        }
    }
    free(work);
    if (err != 0)
        *pSize = err;
    return wav;
}

unsigned char *AquesTalk2_Synthe_Utf8(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    int err = 0;
    void *work = NULL;
    unsigned char *wav = NULL;

    int len = FUN_00102be4((char *)koe);
    if (len != 0) {
        work = malloc((size_t)len + 1);
        if (!work) {
            err = 0x65;
        } else {
            err = FUN_00101b2f((char *)koe, (undefined1 *)work, len + 1);
            if (err == 0)
                wav = aq_synthe_core((char *)work, iSpeed, pSize, phontDat);
        }
    }
    free(work);
    if (err != 0)
        *pSize = err;
    return wav;
}

unsigned char *AquesTalk2_Synthe_Utf16(const unsigned short *koe, int iSpeed, int *pSize,
                                      void *phontDat)
{
    aq_init_image();
    int err = 0;
    void *work = NULL;
    unsigned char *wav = NULL;

    int len = 0;
    while (koe[len] != 0)
        len++;

    if (len != 0) {
        work = malloc((size_t)len * 2 + 1);
        if (!work) {
            err = 0x65;
        } else {
            err = FUN_00101c6e((ushort *)koe, (undefined1 *)work, len * 2 + 1);
            if (err == 0)
                wav = aq_synthe_core((char *)work, iSpeed, pSize, phontDat);
        }
    }
    free(work);
    if (err != 0)
        *pSize = err;
    return wav;
}

unsigned char *AquesTalk2_Synthe_Roman(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    int err = 0;
    void *work = NULL;
    unsigned char *wav = NULL;

    int len = FUN_00102be4((char *)koe);
    if (len != 0) {
        work = malloc((size_t)len * 2 + 1);
        if (!work) {
            err = 0x65;
        } else {
            err = FUN_00101dd6((char *)koe, (undefined1 *)work, len * 2 + 1);
            if (err == 0)
                wav = aq_synthe_core((char *)work, iSpeed, pSize, phontDat);
        }
    }
    free(work);
    if (err != 0)
        *pSize = err;
    return wav;
}

void AquesTalk2_FreeWave(unsigned char *wav)
{
    free(wav);
}

/* Endianness used by AquesTalk2_Synthe_Utf16 (host order in the original). */
int AquesTalk2_Utf16LittleEndian(void)
{
    const uint16_t one = 1;
    return *(const uint8_t *)&one == 1;
}

} /* extern "C" */

/* ------------------------------------------------------------------ */
/* embind                                                             */
/* ------------------------------------------------------------------ */
#ifdef __EMSCRIPTEN__

using emscripten::val;

namespace {

val make_js_bytes(const unsigned char *p, size_t n)
{
    val view = val(emscripten::typed_memory_view(n, p));
    /* Uint8Array(view) copies out of the wasm heap before we free. */
    return val::global("Uint8Array").new_(view);
}

int g_last_error = 0;

val take_wav(unsigned char *wav, int size)
{
    if (!wav) {
        g_last_error = size;
        return val::null();
    }
    g_last_error = 0;
    val out = make_js_bytes(wav, (size_t)size);
    AquesTalk2_FreeWave(wav);
    return out;
}

int last_error()
{
    return g_last_error;
}

std::vector<unsigned char> phont_bytes(val phont)
{
    if (phont.isNull() || phont.isUndefined())
        return {};
    return emscripten::convertJSArrayToNumberVector<unsigned char>(phont);
}

val js_synthe(std::string koe, int speed)
{
    int size = 0;
    return take_wav(AquesTalk2_Synthe_Utf8(koe.c_str(), speed, &size, nullptr), size);
}

val js_synthe_phont(std::string koe, int speed, val phont)
{
    std::vector<unsigned char> data = phont_bytes(phont);
    int size = 0;
    return take_wav(AquesTalk2_Synthe_Utf8(koe.c_str(), speed, &size, data.empty() ? nullptr : data.data()), size);
}

val js_synthe_sjis(val koe, int speed, val phont)
{
    std::vector<unsigned char> text = emscripten::convertJSArrayToNumberVector<unsigned char>(koe);
    std::vector<unsigned char> data = phont_bytes(phont);
    text.push_back(0);
    int size = 0;
    return take_wav(AquesTalk2_Synthe((const char *)text.data(), speed, &size, data.empty() ? nullptr : data.data()), size);
}

val js_synthe_euc(val koe, int speed, val phont)
{
    std::vector<unsigned char> text = emscripten::convertJSArrayToNumberVector<unsigned char>(koe);
    std::vector<unsigned char> data = phont_bytes(phont);
    text.push_back(0);
    int size = 0;
    return take_wav(AquesTalk2_Synthe_Euc((const char *)text.data(), speed, &size, data.empty() ? nullptr : data.data()), size);
}

val js_synthe_roman(std::string koe, int speed, val phont)
{
    std::vector<unsigned char> data = phont_bytes(phont);
    int size = 0;
    return take_wav(AquesTalk2_Synthe_Roman(koe.c_str(), speed, &size, data.empty() ? nullptr : data.data()), size);
}

val js_synthe_utf16(val koe, int speed, val phont)
{
    std::vector<unsigned short> text =
        emscripten::convertJSArrayToNumberVector<unsigned short>(koe);
    std::vector<unsigned char> data = phont_bytes(phont);
    text.push_back(0);
    int size = 0;
    return take_wav(AquesTalk2_Synthe_Utf16(text.data(), speed, &size, data.empty() ? nullptr : data.data()), size);
}

} /* namespace */

EMSCRIPTEN_BINDINGS(aquestalk2) {
    emscripten::function("synthe", &js_synthe);
    emscripten::function("syntheWithPhont", &js_synthe_phont);
    emscripten::function("syntheSjis", &js_synthe_sjis);
    emscripten::function("syntheEuc", &js_synthe_euc);
    emscripten::function("syntheRoman", &js_synthe_roman);
    emscripten::function("syntheUtf16", &js_synthe_utf16);
    emscripten::function("lastError", &last_error);
    emscripten::function("utf16LittleEndian", &AquesTalk2_Utf16LittleEndian);
    emscripten::constant("SAMPLE_RATE", 8000);
}

#endif /* __EMSCRIPTEN__ */
