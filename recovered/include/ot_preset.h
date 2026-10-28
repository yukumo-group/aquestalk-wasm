/*
 * Runtime voice preset. The synthesize argument selects this object.
 * NULL fields are not used: ot_voice_builtin() points at the compiled tables,
 * and a loaded file replaces only the chunks it contains.
 */

#pragma once

#include <stdint.h>

#include "ot_frame_data.h"

enum {
    OT_CHUNK_FORMANT = 1,
    OT_CHUNK_SYMBOLS = 2,
    OT_CHUNK_PHONEME_WORD = 3,
    OT_CHUNK_PERIOD = 4,
    OT_CHUNK_PULSE = 5,
    OT_CHUNK_DUR_SCALE = 6,
    OT_CHUNK_DUR_KEY = 7,
    OT_CHUNK_DUR_VAL = 8,
    /* Two uint16 code constants the DLL bakes into immediates, plus a render mode.
     * base_pitch is the 0x135 ceiling in ot_fill_pitch. q_tail is the 6400 added
     * to a closing '?'. render_mode 0 is the root sample loop; 1 negates the
     * excitation for 8 of every 16 samples and applies the envelope gain (dvd);
     * 2 mutes the excitation whenever the 8-sample counter is 0 and applies the
     * same gain (jgr). Absent chunk keeps 309, 6400, and mode 0. */
    OT_CHUNK_CONST = 9
};

typedef struct OtVoice {
    const OtSymbol *symbols;
    int symbol_count;
    const int16_t *phoneme_word;
    int phoneme_word_count;
    const int16_t *formant;
    int formant_words;
    int formant_stride;
    const int16_t *period;
    const int16_t *pulse;
    const int16_t *dur_scale;
    const int16_t *dur_key;
    const int16_t *dur_val;
    int pulse_count;
    int base_pitch;
    int q_tail;
    int render_mode;
    /* Long-vowel mark in diphone names. '-' in the root table, '.' when the
     * loaded symbols have a. and not a- (f3). */
    int vowel_mark;
    /* Diphone boundary character. ';' in the root symbols, '.' when the
     * loaded table has .a and not ;a (f3). */
    int boundary;
    /* Slot duration added to every diphone before 0x3E8000/dur. 13248 in the root. */
    int dur_base;
    /* Per-voice scale for the duration delta: dur = dur_base + delta * dur_scale / 163.
     * 163 in the root (delta unchanged); the Linux voices use 130, 152, 49, 74, 33,
     * 130, 210, 10. The denominator 163 is a code constant, the numerator is baked
     * into each build (Ghidra: FUN_0010d06c, `(delta * M) / 0xa3 + dur_base`). */
    int dur_scale_num;
} OtVoice;

const OtVoice *ot_voice_builtin(void);

/*
 * NULL or "" returns the built-in voice and leaves *err alone.
 * A missing or malformed file returns NULL and sets *err to OT_ERR_PRESET
 * when err is not NULL. Successful loads are cached by the path string.
 */
const OtVoice *ot_voice_from_path(const char *path, int *err);
