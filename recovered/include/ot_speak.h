#pragma once

#include <stdint.h>

#include "ot_preset.h"

typedef struct OtPcm {
    uint8_t *data;
    uint32_t cap;
    uint32_t used;
} OtPcm;

int ot_pcm_append(OtPcm *pcm, int16_t sample, uint32_t count);
int ot_render_sample(uint16_t *state, const int16_t *coeff, int16_t *out, const OtVoice *voice);
void ot_render_prepare(uint16_t *state, const OtVoice *voice);
void ot_formants_to_lpc(const int16_t *formants, int16_t *dst);

/*
 * Turn parsed phoneme bytes into spoken PCM.
 * sub_180003010 builds 4-byte diphone tokens, sub_18000242C expands them
 * into frames, and sub_18000141C renders each frame.
 * Returns 0 or an Open Talk error code (102, 201, 204, ...).
 */
int ot_speak(const uint8_t *phonemes, int count, int period,
             uint16_t phase0, uint8_t noise_flip, OtPcm *pcm, const OtVoice *voice);

/* Expand diphone tokens and render them. Used to audition one voice unit. */
struct OtToken;
int ot_render_tokens(const struct OtToken *tok, int ntok, int period,
                     uint16_t phase0, uint8_t noise_flip, OtPcm *pcm, const OtVoice *voice);
