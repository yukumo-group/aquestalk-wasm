/* wasm_api.c -- public AquesTalk2 ABI and the small host-facing API.
 *
 * This replaces the former embind layer: everything is plain C, the wasm
 * module exports these symbols directly and a hand-written JS wrapper calls
 * them.  The five AquesTalk2_* functions mirror the original shared object's
 * wrappers (text encoding conversion + buffer management); the engine itself
 * is decomp.c.
 */
#include "shim.h"

#ifdef __wasm__
#define AQ_EXPORT(name) __attribute__((export_name(#name)))
#else
#define AQ_EXPORT(name)
#endif

/* Conversion helpers recovered from the original library. */
int FUN_00102be4(char *param_1);
char *FUN_00102d33(char *param_1, char *param_2);
int FUN_001019f0(char *param_1, undefined1 *param_2, int param_3);
int FUN_00101b2f(char *param_1, undefined1 *param_2, int param_3);
int FUN_00101c6e(ushort *param_1, undefined1 *param_2, int param_3);
int FUN_00101dd6(char *param_1, undefined1 *param_2, int param_3);

/* Core engine: kana (Shift-JIS) -> WAV. */
undefined8 FUN_001012f4(undefined8 koe, undefined2 iSpeed, int *pSize, int64_t phontDat);

static int aq_last_err;

static unsigned char *aq_synthe_core(char *sjis, int speed, int *pSize, void *phont)
{
    aq_init_image();
    unsigned char *wav = (unsigned char *)(uintptr_t)FUN_001012f4(
        (undefined8)(uintptr_t)sjis, (undefined2)speed, pSize,
        (int64_t)(uintptr_t)phont);
    if (!wav && *pSize != 0)
        aq_last_err = *pSize;
    return wav;
}

/* ------------------------------------------------------------------ */
/* Original ABI                                                       */
/* ------------------------------------------------------------------ */
AQ_EXPORT(AquesTalk2_Synthe)
unsigned char *AquesTalk2_Synthe(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    aq_last_err = 0;

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
    if (err != 0) {
        *pSize = err;
        aq_last_err = err;
    }
    return wav;
}

AQ_EXPORT(AquesTalk2_Synthe_Euc)
unsigned char *AquesTalk2_Synthe_Euc(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    aq_last_err = 0;

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
    if (err != 0) {
        *pSize = err;
        aq_last_err = err;
    }
    return wav;
}

AQ_EXPORT(AquesTalk2_Synthe_Utf8)
unsigned char *AquesTalk2_Synthe_Utf8(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    aq_last_err = 0;

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
    if (err != 0) {
        *pSize = err;
        aq_last_err = err;
    }
    return wav;
}

AQ_EXPORT(AquesTalk2_Synthe_Utf16)
unsigned char *AquesTalk2_Synthe_Utf16(const unsigned short *koe, int iSpeed, int *pSize,
                                      void *phontDat)
{
    aq_init_image();
    aq_last_err = 0;

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
    if (err != 0) {
        *pSize = err;
        aq_last_err = err;
    }
    return wav;
}

AQ_EXPORT(AquesTalk2_Synthe_Roman)
unsigned char *AquesTalk2_Synthe_Roman(const char *koe, int iSpeed, int *pSize, void *phontDat)
{
    aq_init_image();
    aq_last_err = 0;

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
    if (err != 0) {
        *pSize = err;
        aq_last_err = err;
    }
    return wav;
}

AQ_EXPORT(AquesTalk2_FreeWave)
void AquesTalk2_FreeWave(unsigned char *wav)
{
    free(wav);
}

/* ------------------------------------------------------------------ */
/* Host helpers (exported, used by the JS wrapper)                    */
/* ------------------------------------------------------------------ */
AQ_EXPORT(aq_malloc)
void *aq_malloc(size_t n)
{
    return malloc(n);
}

AQ_EXPORT(aq_free)
void aq_free(void *p)
{
    free(p);
}

AQ_EXPORT(aq_last_error)
int aq_last_error(void)
{
    return aq_last_err;
}

AQ_EXPORT(aq_sample_rate)
int aq_sample_rate(void)
{
    return 8000;
}

/* The host needs a stable pointer to the image too (for debugging). */
AQ_EXPORT(aq_image_base)
unsigned char *aq_image_base(void)
{
    return aq_image;
}
