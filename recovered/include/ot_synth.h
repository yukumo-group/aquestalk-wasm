/*
 * Types shared by the diphone pipeline: tokens, frames, and phrase chunks.
 */

#pragma once

#include <stdint.h>

#include "ot_voice.h"

enum { OT_TOKEN_MAX = 1024, OT_FRAME_MAX = 26624 };

typedef struct OtToken {
    uint16_t pitch;
    uint8_t a;
    uint8_t b;
} OtToken;

typedef struct OtFrames {
    uint16_t prev_left;
    uint16_t prev_right;
    uint8_t buf[OT_FRAME_MAX];
    uint32_t cursor;
} OtFrames;

/* One prosody chunk. accent is the mora index where phoneme 1 (') was seen. */
struct OtChunk {
    int slot0;
    int n;
    int accent;
    int low;
    int high;
    int scale;
};

/* Arithmetic shift, matching the sar used by the frame expander. */
static inline int ot_asr(int v, int n)
{
    uint32_t u = (uint32_t)v;
    uint32_t r = u >> n;
    if (v < 0) {
        r |= ~0u << (32 - n);
    }
    return (int)r;
}

/* Signed divide by 2^n, rounding toward zero (cdq / and / add / sar). */
static inline int ot_div_pow2(int v, int n)
{
    if (v < 0) {
        v += (1 << n) - 1;
    }
    return ot_asr(v, n);
}

static inline int ot_bittest(uint32_t mask, unsigned bit)
{
    return bit < 32u && ((mask >> bit) & 1u) != 0;
}

static inline int ot_bittest64(uint64_t mask, unsigned bit)
{
    return bit < 64u && ((mask >> bit) & 1u) != 0;
}

int ot_expand_tokens(const OtToken *tok, int ntok, OtFrames *fr, const OtVoice *voice);
int ot_clamped_dur(const OtVoice *voice, int slot, int count, int accent, int nibble, int scale,
                   int next_accent);
void ot_merge_plus(const OtVoice *voice, struct OtChunk *chunks, int nchunk, const int *slot_ph,
                   uint16_t *durs);
int ot_tokens_from_phonemes(const uint8_t *ph, int count, OtToken *tok, int *n, int prosody,
                            const OtVoice *voice);
