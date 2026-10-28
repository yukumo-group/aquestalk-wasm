/* wasm_api.c -- plain C API exported from the raw wasm module.
 *
 * No Emscripten and no embind.  The module has no imports at all; JS talks
 * to it through these functions and the exported linear memory.
 */
#include "shim.h"

#ifdef __wasm__
#define EXPORT(name) __attribute__((used, visibility("default"))) name
#else
#define EXPORT(name) name
#endif

/* decompiled engine entry points (LP64 ABI uses 64-bit integers) */
extern int64_t AquesTalk_Synthe_Utf8(int64_t voice, const char *koe, int *size);
extern int64_t AquesTalk_Synthe(int64_t voice, const char *koe, int *size);
extern int64_t AquesTalk_Synthe_Utf16(int64_t voice, const unsigned short *koe, int *size);
extern void AquesTalk_FreeWave(unsigned char *wav);
extern int64_t AquesTalk_SetDevKey(int64_t key);
extern int64_t AquesTalk_SetUsrKey(int64_t key);

typedef struct {
    int bas, spd, vol, pit, acc, lmd, fsc;
} AQTK_VOICE;

static void ensure_init(void)
{
    aq_load_image();
}

EXPORT(void) aqtk_init(void)
{
    ensure_init();
}

EXPORT(unsigned int) aqtk_malloc(unsigned int n)
{
    ensure_init();
    return (unsigned int)(uintptr_t)malloc(n ? n : 1);
}

EXPORT(void) aqtk_free(void *p)
{
    free(p);
}

EXPORT(unsigned char *) aqtk_synthe_utf8(const AQTK_VOICE *voice, const char *koe, int *size)
{
    ensure_init();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe_Utf8((int64_t)(uintptr_t)voice, koe, size);
}

EXPORT(unsigned char *) aqtk_synthe_sjis(const AQTK_VOICE *voice, const char *koe, int *size)
{
    ensure_init();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe((int64_t)(uintptr_t)voice, koe, size);
}

EXPORT(unsigned char *) aqtk_synthe_utf16(const AQTK_VOICE *voice,
                                          const unsigned short *koe, int *size)
{
    ensure_init();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe_Utf16((int64_t)(uintptr_t)voice, koe, size);
}

/* Convenience entry point: voice is passed as seven integers so the JS side
 * does not have to know the struct layout. */
EXPORT(unsigned char *) aqtk_synthe_utf8_default(const char *koe, int bas, int spd, int vol,
                                                 int pit, int acc, int lmd, int fsc,
                                                 int *size)
{
    AQTK_VOICE v;
    v.bas = bas; v.spd = spd; v.vol = vol; v.pit = pit;
    v.acc = acc; v.lmd = lmd; v.fsc = fsc;
    ensure_init();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe_Utf8((int64_t)(uintptr_t)&v, koe, size);
}

EXPORT(void) aqtk_free_wave(unsigned char *wav)
{
    if (wav)
        AquesTalk_FreeWave(wav);
}

EXPORT(int) aqtk_set_dev_key(const char *key)
{
    ensure_init();
    return (int)AquesTalk_SetDevKey((int64_t)(uintptr_t)key);
}

EXPORT(int) aqtk_set_usr_key(const char *key)
{
    ensure_init();
    return (int)AquesTalk_SetUsrKey((int64_t)(uintptr_t)key);
}
