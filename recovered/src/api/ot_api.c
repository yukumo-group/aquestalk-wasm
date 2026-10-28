/*
 * Reconstruction of lib64/Open_Talk.dll (x64, image base 0x180000000).
 * Behavior below is translated from Hex-Rays via ida_domain. Places the
 * decompiler dropped a register are marked UNCERTAIN. The diphone expander
 * lives in recovered/src/synth/ot_expand.c.
 */

#include "Open_Talk.h"
#include "ot_internal.h"
#include "ot_data.h"
#include "ot_preset.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* The six exports, UTF conversion, and the SJIS synthesis entry. */

#if defined(_MSC_VER)
#define OT_TIME64() _time64(NULL)
#else
#define OT_TIME64() ((int64_t)time(NULL))
#endif

/* word_180034C18, word_180034C1C, qword_180034C10 */
uint16_t g_dev_mark;
uint16_t g_usr_mark;
uint64_t g_usr_material;

static uint64_t ot_parse_hex(const uint8_t *text)
{
    uint64_t value = 0;
    int digits = 0;

    if (!text) {
        return 0;
    }
    while (*text && digits < 16) {
        uint8_t ch = *text++;
        int nibble;
        if (ch == '-') {
            continue;
        }
        if ((uint8_t)(ch - '0') <= 9) {
            nibble = (int)ch - '0';
        } else if ((uint8_t)(ch - 'A') <= 5) {
            nibble = (int)ch - 55;
        } else {
            nibble = 0;
        }
        value = ((uint64_t)nibble) + (value << 4);
        digits++;
    }
    return value;
}

/* 1391 rounds. v5 is a signed 8-bit truncation of the round index. */
static uint64_t ot_unscramble(uint64_t value)
{
    value ^= 0xD271BA9DF61EED07ull;
    for (unsigned round = 0; round < 0x56Fu; round++) {
        int found = 0;
        unsigned top = (unsigned)(value >> 61);
        for (int j = 0; j < 7; j++) {
            if (ot_key_perm[j] == top) {
                break;
            }
            found++;
        }
        {
            int8_t truncated = (int8_t)(uint8_t)round;
            value = (value << 3) | (uint64_t)((found - truncated - 2) & 7);
        }
    }
    return value;
}

static int ot_utf8_to_sjis_at(const uint8_t *src, uint8_t *dst, int dst_cap)
{
    const uint8_t *start = src;
    int filled = 0;
    if (!src || src[0] == 0 || !dst || dst_cap <= 1) {
        return (int)0xFFFFFFFEu;
    }
    dst[0] = 0;
    while (*src) {
        if (*src < 0x80) {
            if (filled + 2 > dst_cap) {
                return -1;
            }
            dst[filled++] = *src++;
        } else {
            int found = -1;
            int i;
            for (i = 0; i < OT_UTF_COUNT; i++) {
                const uint8_t *rec = ot_utf_map + i * 10;
                if (src[0] == rec[4] && src[1] == rec[5] && src[2] == rec[6]) {
                    found = i;
                    break;
                }
            }
            if (found < 0) {
                return (int)(src - start) + 1;
            }
            if (filled + 3 > dst_cap) {
                return -1;
            }
            dst[filled++] = ot_utf_map[found * 10];
            dst[filled++] = ot_utf_map[found * 10 + 1];
            src += 3;
        }
        dst[filled] = 0;
    }
    return 0;
}

static int ot_utf16_to_sjis(const uint16_t *src, uint8_t *dst, int dst_cap)
{
    const uint16_t *start = src;
    int filled = 0;
    uint16_t ch;
    if (!src || src[0] == 0 || !dst || dst_cap <= 1) {
        return -2;
    }
    dst[0] = 0;
    ch = src[0];
    if (ch == 0xFEFF) {
        src++;
        ch = src[0];
    }
    if (!ch) {
        return -2;
    }
    while (ch) {
        if (ch < 0x80) {
            if (filled + 2 > dst_cap) {
                return -1;
            }
            dst[filled++] = (uint8_t)ch;
        } else {
            int found = -1;
            int i;
            for (i = 0; i < OT_UTF_COUNT; i++) {
                uint16_t unit;
                memcpy(&unit, ot_utf_map + i * 10 + 8, sizeof unit);
                if (unit == ch) {
                    found = i;
                    break;
                }
            }
            if (found < 0) {
                return (int)(src - start) + 1;
            }
            if (filled + 3 > dst_cap) {
                return -1;
            }
            dst[filled++] = ot_utf_map[found * 10];
            dst[filled++] = ot_utf_map[found * 10 + 1];
        }
        dst[filled] = 0;
        src++;
        ch = src[0];
    }
    return 0;
}

static unsigned char *ot_synthesize_sjis(const uint8_t *koe, int speed, int *p_size, const OtVoice *voice)
{
    uint8_t *phonemes = NULL;
    int count = 0;
    int err;
    int period;
    OtPcm pcm;

    memset(&pcm, 0, sizeof pcm);
    err = ot_parse_kana(koe, &phonemes, &count);
    if (err) {
        free(phonemes);
        *p_size = err;
        return NULL;
    }
    period = ot_speed_period(speed);
    /*
     * User-key watermark: the orchestrator tests one bit of the raw key
     * integer. With the field Hex-Rays left at 2048, 2048 & 63 == 0, so
     * this is bit 0. UNCERTAIN if a later store replaces 2048 with the
     * phrase index. The mark seeds the phase (WORD1 of the synth object).
     */
    err = ot_speak(phonemes, count, period, (uint16_t)(g_usr_mark & 0x0FFFu),
                   (uint8_t)(g_usr_material & 1u), &pcm, voice);
    free(phonemes);
    if (err) {
        ot_pcm_clear(&pcm);
        *p_size = err;
        return NULL;
    }
    /* Trailing pad from sub_18000141C when the phrase cursor is exhausted. */
    err = ot_pcm_append(&pcm, 0, 256);
    if (err) {
        ot_pcm_clear(&pcm);
        *p_size = err;
        return NULL;
    }
    ot_write_wav_header(&pcm);
    *p_size = (int)pcm.used;
    return pcm.data;
}

static const OtVoice *ot_voice_for(const char *preset, int *p_size)
{
    int err = 0;
    const OtVoice *voice = ot_voice_from_path(preset, &err);
    if (!voice) {
        *p_size = err ? err : OT_ERR_PRESET;
    }
    return voice;
}

static unsigned char *ot_synthesize_copied(const char *koe, int speed, int *p_size, const char *preset)
{
    const uint8_t *src;
    uint8_t *copy;
    size_t n;
    unsigned char *wav;
    const OtVoice *voice;
    if (!koe || !p_size || koe[0] == 0) {
        return NULL;
    }
    voice = ot_voice_for(preset, p_size);
    if (!voice) {
        return NULL;
    }
    src = (const uint8_t *)koe;
    n = strlen(koe);
    copy = (uint8_t *)malloc(n + 1);
    if (!copy) {
        *p_size = OT_ERR_NOMEM;
        return NULL;
    }
    memcpy(copy, src, n + 1);
    wav = ot_synthesize_sjis(copy, speed, p_size, voice);
    free(copy);
    return wav;
}

unsigned char *__stdcall Open_Talk_Synthe(const char *koe, int iSpeed, int *pSize)
{
    return ot_synthesize_copied(koe, iSpeed, pSize, NULL);
}

unsigned char *__stdcall Open_Talk_Synthe_Preset(const char *koe, int iSpeed, int *pSize,
                                                 const char *presetPath)
{
    return ot_synthesize_copied(koe, iSpeed, pSize, presetPath);
}

unsigned char *__stdcall Open_Talk_Synthe_Utf8(const char *koe, int iSpeed, int *pSize)
{
    return Open_Talk_Synthe_Utf8_Preset(koe, iSpeed, pSize, NULL);
}

unsigned char *__stdcall Open_Talk_Synthe_Utf8_Preset(const char *koe, int iSpeed, int *pSize,
                                                      const char *presetPath)
{
    const uint8_t *src;
    size_t n;
    uint8_t *sjis;
    int err;
    unsigned char *wav;
    const OtVoice *voice;
    if (!koe || !pSize || koe[0] == 0) {
        return NULL;
    }
    voice = ot_voice_for(presetPath, pSize);
    if (!voice) {
        return NULL;
    }
    src = (const uint8_t *)koe;
    n = strlen(koe);
    sjis = (uint8_t *)malloc(n + 1);
    if (!sjis) {
        *pSize = OT_ERR_NOMEM;
        return NULL;
    }
    err = ot_utf8_to_sjis_at(src, sjis, (int)n + 1);
    if (err) {
        free(sjis);
        *pSize = err;
        return NULL;
    }
    wav = ot_synthesize_sjis(sjis, iSpeed, pSize, voice);
    free(sjis);
    return wav;
}

unsigned char *__stdcall Open_Talk_Synthe_Utf16(const unsigned short *koe, int iSpeed, int *pSize)
{
    return Open_Talk_Synthe_Utf16_Preset(koe, iSpeed, pSize, NULL);
}

unsigned char *__stdcall Open_Talk_Synthe_Utf16_Preset(const unsigned short *koe, int iSpeed, int *pSize,
                                                       const char *presetPath)
{
    int units = 0;
    uint8_t *sjis;
    int err;
    unsigned char *wav;
    const OtVoice *voice;
    if (!koe || !pSize || koe[0] == 0) {
        return NULL;
    }
    voice = ot_voice_for(presetPath, pSize);
    if (!voice) {
        return NULL;
    }
    while (koe[units]) {
        units++;
    }
    sjis = (uint8_t *)malloc((size_t)units * 2u + 1u);
    if (!sjis) {
        *pSize = OT_ERR_NOMEM;
        return NULL;
    }
    err = ot_utf16_to_sjis(koe, sjis, units * 2 + 1);
    if (err) {
        free(sjis);
        *pSize = err;
        return NULL;
    }
    wav = ot_synthesize_sjis(sjis, iSpeed, pSize, voice);
    free(sjis);
    return wav;
}

void __stdcall Open_Talk_FreeWave(unsigned char *wav)
{
    free(wav);
}

int __stdcall Open_Talk_SetDevKey(const char *key)
{
    uint64_t decoded;
    g_dev_mark = 0;
    decoded = ot_unscramble(ot_parse_hex((const uint8_t *)key));
    if ((uint8_t)decoded == 110 && (uint8_t)(decoded >> 8) >= 0x14u && (uint8_t)(decoded >> 48) == 86) {
        g_dev_mark = (uint16_t)(decoded >> 16);
        return 0;
    }
    return 1;
}

int __stdcall Open_Talk_SetUsrKey(const char *key)
{
    uint64_t raw;
    uint64_t decoded;
    uint8_t kind;
    g_usr_mark = 0;
    g_usr_material = 0;
    raw = ot_parse_hex((const uint8_t *)key);
    decoded = ot_unscramble(raw);
    kind = (uint8_t)decoded;
    if ((kind == 110 || kind == 0xFF)
        && (uint8_t)(decoded >> 8) >= 0x14u
        && (uint8_t)(decoded >> 48) == 23) {
        if (kind == 0xFF) {
            unsigned days = (unsigned)(OT_TIME64() / 86400);
            unsigned pivot = (unsigned)(uint16_t)(decoded >> 16);
            if ((int)days < (int)pivot - 31 || days > pivot + 396) {
                return 1;
            }
        }
        if ((uint16_t)(decoded >> 48) == 1303) {
            g_usr_mark = (uint16_t)(decoded >> 32);
            g_usr_material = raw;
        }
        return 0;
    }
    return 1;
}
