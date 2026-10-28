/*
 * OTPR preset loader.
 *
 * Little-endian layout:
 *   char magic[4] = "OTPR"
 *   uint16 version = 1
 *   uint16 chunk_count
 *   repeated chunk_count times:
 *     uint16 id
 *     uint16 reserved (0)
 *     uint32 length
 *     uint8  payload[length]
 *
 * Chunk ids and payload sizes (the whole recovered table, not a slice):
 *   1 formant       int16[25465]
 *   2 symbols       N records, 6 bytes each (a, b, class, count, index).
 *                   N is 209 in the built-in voice; a file may carry another count.
 *   3 phoneme_word  int16[392]
 *   4 period        int16[4096]
 *   5 pulse         int16[0x255]
 *   6 dur_scale     int16[121]
 *   7 dur_key       int16[240]
 *   8 dur_val       int16[1200]
 *   5 may instead be int16[0x87B] when the DLL's pulse limit is 0x87B.
 *   9 constants     uint16 base_pitch, uint16 question_add, uint16 render_mode,
 *                   uint16 dur_base.
 *                   base_pitch is the 0x135 ceiling in the pitch fill.
 *                   question_add is the 6400 added for a closing '?'.
 *                   render_mode 0 is the root sample loop, 1 negates the
 *                   excitation for 8 of every 16 samples and scales by the
 *                   envelope gain (dvd), 2 mutes the excitation when an
 *                   8-sample counter is 0 and scales the same way (jgr).
 * A chunk that is absent keeps the compiled-in table. Files live in
 * recovered/presets/ and are named from the lib64 folder they came from.
 */

#include "ot_preset.h"

#include "ot_data.h"
#include "ot_dur_data.h"
#include "ot_internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Static_assert(sizeof(OtSymbol) == 6, "OtSymbol is a 6-byte DLL record");

typedef struct OtPresetSlot {
    char *path;
    OtVoice voice;
    void *owned[9];
} OtPresetSlot;

static OtPresetSlot g_cache[16];
static int g_cache_n;

static const OtVoice g_builtin = {
    ot_symbols,
    209,
    ot_phoneme_word,
    392,
    ot_formant,
    25476,
    11,
    ot_period,
    ot_pulse,
    ot_dur_scale,
    ot_dur_key,
    ot_dur_val,
    0x255,
    0x135,
    6400,
    0,
    '-',
    ';',
    13248,
    163,
};

const OtVoice *ot_voice_builtin(void)
{
    return &g_builtin;
}

static int ot_chunk_size(unsigned id, uint32_t length)
{
    switch (id) {
    case OT_CHUNK_FORMANT:
        /* f1..dvd use 25476 words, f3 25584; keep the size data driven. */
        if (length < 40000u || length > 60000u || (length & 1u) != 0) {
            return -1;
        }
        return (int)length;
    case OT_CHUNK_SYMBOLS:
        if (length == 0 || length % sizeof(OtSymbol) != 0 || length > 4096u) {
            return -1;
        }
        return (int)length;
    case OT_CHUNK_PHONEME_WORD:
        if (length < 2u || length > 4096u * sizeof(int16_t) || (length & 1u) != 0) {
            return -1;
        }
        return (int)length;
    case OT_CHUNK_PERIOD:
        return length == 4096u * sizeof(int16_t) ? (int)length : -1;
    case OT_CHUNK_PULSE:
        if (length == 0x255u * sizeof(int16_t) || length == 0x87Bu * sizeof(int16_t)) {
            return (int)length;
        }
        return -1;
    case OT_CHUNK_DUR_SCALE:
        return length == 121u * sizeof(int16_t) ? (int)length : -1;
    case OT_CHUNK_DUR_KEY:
        return length == 240u * sizeof(int16_t) ? (int)length : -1;
    case OT_CHUNK_DUR_VAL:
        return length == 1200u * sizeof(int16_t) ? (int)length : -1;
    case OT_CHUNK_CONST:
        return (length == 8u || length == 10u) ? (int)length : -1;
    default:
        return -1;
    }
}

static void ot_slot_clear(OtPresetSlot *slot)
{
    int i;
    free(slot->path);
    slot->path = NULL;
    for (i = 0; i < 9; i++) {
        free(slot->owned[i]);
        slot->owned[i] = NULL;
    }
}

static int ot_apply_chunk(OtPresetSlot *slot, unsigned id, const uint8_t *payload, uint32_t length)
{
    int expect = ot_chunk_size(id, length);
    void *copy;
    if (expect < 0 || id < 1 || id > 9) {
        return -1;
    }
    if (slot->owned[id - 1]) {
        return -1;
    }
    copy = malloc(length);
    if (!copy) {
        return -1;
    }
    memcpy(copy, payload, length);
    slot->owned[id - 1] = copy;
    switch (id) {
    case OT_CHUNK_FORMANT:
        slot->voice.formant = (const int16_t *)copy;
        slot->voice.formant_words = (int)(length / sizeof(int16_t));
        break;
    case OT_CHUNK_SYMBOLS: {
        const OtSymbol *recs = (const OtSymbol *)copy;
        int nrec = (int)(length / sizeof(OtSymbol));
        int s;
        int has_dot = 0;
        int has_dash = 0;
        int has_semi = 0;
        slot->voice.symbols = recs;
        slot->voice.symbol_count = nrec;
        for (s = 0; s < nrec; s++) {
            if (recs[s].a == 'a' && recs[s].b == '.') {
                has_dot = 1;
            }
            if (recs[s].a == 'a' && recs[s].b == '-') {
                has_dash = 1;
            }
            if (recs[s].a == ';' && recs[s].b == 'a') {
                has_semi = 1;
            }
        }
        if (has_dot && !has_dash) {
            slot->voice.vowel_mark = '.';
        }
        if (has_dot && !has_semi) {
            slot->voice.boundary = '.';
        }
        break;
    }
    case OT_CHUNK_PHONEME_WORD:
        slot->voice.phoneme_word = (const int16_t *)copy;
        slot->voice.phoneme_word_count = (int)(length / sizeof(int16_t));
        break;
    case OT_CHUNK_PERIOD:
        slot->voice.period = (const int16_t *)copy;
        break;
    case OT_CHUNK_PULSE:
        slot->voice.pulse = (const int16_t *)copy;
        slot->voice.pulse_count = (int)(length / sizeof(int16_t));
        break;
    case OT_CHUNK_DUR_SCALE:
        slot->voice.dur_scale = (const int16_t *)copy;
        break;
    case OT_CHUNK_DUR_KEY:
        slot->voice.dur_key = (const int16_t *)copy;
        break;
    case OT_CHUNK_DUR_VAL:
        slot->voice.dur_val = (const int16_t *)copy;
        break;
    case OT_CHUNK_CONST: {
        uint16_t base;
        uint16_t tail;
        uint16_t mode;
        uint16_t dur_base;
        memcpy(&base, copy, 2);
        memcpy(&tail, (uint8_t *)copy + 2, 2);
        memcpy(&mode, (uint8_t *)copy + 4, 2);
        memcpy(&dur_base, (uint8_t *)copy + 6, 2);
        if (length >= 10u) {
            uint16_t scale;
            memcpy(&scale, (uint8_t *)copy + 8, 2);
            if (scale == 0) {
                return -1;
            }
            slot->voice.dur_scale_num = (int)scale;
        }
        if (mode > 2 || dur_base == 0) {
            return -1;
        }
        slot->voice.base_pitch = (int)base;
        slot->voice.q_tail = (int)tail;
        slot->voice.render_mode = (int)mode;
        slot->voice.dur_base = (int)dur_base;
        break;
    }
    default:
        return -1;
    }
    return 0;
}

static const OtVoice *ot_load_file(const char *path, int *err)
{
    FILE *f;
    long sz;
    uint8_t *buf = NULL;
    OtPresetSlot slot;
    uint16_t version;
    uint16_t count;
    uint32_t pos;
    int i;
    if (g_cache_n >= (int)(sizeof g_cache / sizeof g_cache[0])) {
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    f = fopen(path, "rb");
    if (!f) {
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f);
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    sz = ftell(f);
    if (sz < 8 || sz > 1024 * 1024) {
        fclose(f);
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    if (fseek(f, 0, SEEK_SET) != 0) {
        fclose(f);
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    buf = (uint8_t *)malloc((size_t)sz);
    if (!buf || fread(buf, 1, (size_t)sz, f) != (size_t)sz) {
        free(buf);
        fclose(f);
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    fclose(f);
    memset(&slot, 0, sizeof slot);
    slot.voice = g_builtin;
    if (memcmp(buf, "OTPR", 4) != 0) {
        goto bad;
    }
    memcpy(&version, buf + 4, 2);
    memcpy(&count, buf + 6, 2);
    if (version != 1) {
        goto bad;
    }
    pos = 8;
    for (i = 0; i < (int)count; i++) {
        uint16_t id;
        uint16_t reserved;
        uint32_t length;
        if (pos + 8 > (uint32_t)sz) {
            goto bad;
        }
        memcpy(&id, buf + pos, 2);
        memcpy(&reserved, buf + pos + 2, 2);
        memcpy(&length, buf + pos + 4, 4);
        pos += 8;
        if (reserved != 0 || pos + length > (uint32_t)sz) {
            goto bad;
        }
        if (ot_apply_chunk(&slot, id, buf + pos, length) != 0) {
            goto bad;
        }
        pos += length;
    }
    if (pos != (uint32_t)sz) {
        goto bad;
    }
    free(buf);
    slot.path = (char *)malloc(strlen(path) + 1);
    if (!slot.path) {
        ot_slot_clear(&slot);
        if (err) {
            *err = OT_ERR_PRESET;
        }
        return NULL;
    }
    memcpy(slot.path, path, strlen(path) + 1);
    g_cache[g_cache_n] = slot;
    g_cache_n++;
    return &g_cache[g_cache_n - 1].voice;

bad:
    free(buf);
    ot_slot_clear(&slot);
    if (err) {
        *err = OT_ERR_PRESET;
    }
    return NULL;
}

const OtVoice *ot_voice_from_path(const char *path, int *err)
{
    int i;
    if (!path || path[0] == 0) {
        return &g_builtin;
    }
    for (i = 0; i < g_cache_n; i++) {
        if (strcmp(g_cache[i].path, path) == 0) {
            return &g_cache[i].voice;
        }
    }
    return ot_load_file(path, err);
}
