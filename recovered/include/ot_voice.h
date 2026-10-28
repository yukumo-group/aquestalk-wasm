/*
 * Voice descriptor and the embedded voice registry.
 *
 * The voices are raw dumps of the tables in the Linux libAquesTalk.so builds
 * (see recovered/tools/linux/rawdump.py), so there is no file-backed preset
 * mode any more.  engine 0 is the classic synth path; engine 1 marks the f3
 * build, which has its own token/expander rules in src/f3/.
 */

#pragma once

#include <stdint.h>

#include "ot_frame_data.h"

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
    /* Long-vowel mark in diphone names: '-' in f1..dvd, '.' in f3. */
    int vowel_mark;
    /* Diphone boundary character: ';' in f1..dvd, '.' in f3. */
    int boundary;
    /* Slot duration added to every diphone before 0x3E8000/dur. */
    int dur_base;
    /* dur = dur_base + delta * dur_scale_num / 163 (163 is fixed in the code). */
    int dur_scale_num;
    /* 0 = classic engine, 1 = f3 engine (src/f3/). */
    int engine;
} OtVoice;

enum {
    OT_ENGINE_CLASSIC = 0,
    OT_ENGINE_F3 = 1
};

/* One entry point per embedded voice. */
const OtVoice *ot_voice_f1(void);
const OtVoice *ot_voice_f2(void);
const OtVoice *ot_voice_m1(void);
const OtVoice *ot_voice_m2(void);
const OtVoice *ot_voice_r1(void);
const OtVoice *ot_voice_imd1(void);
const OtVoice *ot_voice_jgr(void);
const OtVoice *ot_voice_dvd(void);
const OtVoice *ot_voice_f3(void);

/* "f1".."dvd", case insensitive.  Returns NULL for an unknown name. */
const OtVoice *ot_voice_by_name(const char *name);
int ot_voice_count(void);
const char *ot_voice_name(int index);

/* The voice used by the public Synthe entry points; f1 until changed. */
const OtVoice *ot_voice_builtin(void);
const OtVoice *ot_voice_current(void);
int ot_voice_select(const char *name);
