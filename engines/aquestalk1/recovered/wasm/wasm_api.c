/* WebAssembly entry points: a small host API plus the Open_Talk ABI. */
#include "Open_Talk.h"

#include <stddef.h>
#include <stdlib.h>

#ifdef __wasm__
#define AQ_EXPORT(name) __attribute__((export_name(#name)))
#else
#define AQ_EXPORT(name)
#endif

AQ_EXPORT(aq_alloc)
void *aq_alloc(unsigned size)
{
    return malloc(size);
}

AQ_EXPORT(aq_free)
void aq_free(void *p)
{
    free(p);
}

AQ_EXPORT(aq_select_voice)
int aq_select_voice(const char *name)
{
    return Open_Talk_SelectVoice(name);
}

AQ_EXPORT(aq_voice_count)
int aq_voice_count(void)
{
    return Open_Talk_VoiceCount();
}

AQ_EXPORT(aq_voice_name)
const char *aq_voice_name(int index)
{
    return Open_Talk_VoiceName(index);
}

AQ_EXPORT(aq_synthe_utf8)
unsigned char *aq_synthe_utf8(const char *utf8, int speed, int *size)
{
    return Open_Talk_Synthe_Utf8(utf8, speed, size);
}

AQ_EXPORT(aq_free_wave)
void aq_free_wave(unsigned char *wav)
{
    Open_Talk_FreeWave(wav);
}
