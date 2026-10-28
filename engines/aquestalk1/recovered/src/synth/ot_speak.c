/*
 * Phrase driver. Bytes 6..9 end a phrase; the last of them is the next prosody nibble.
 */

#include "ot_speak.h"
#include "ot_synth.h"

#include "ot_internal.h"
#include "ot_frame_data.h"

#include <string.h>

static void ot_blend_lpc(const OtVoice *voice, uint16_t id_a, uint16_t id_b, uint8_t blend, int16_t *lpc)
{
    int slot_a = voice->formant_stride * (int)id_a + 1;
    int slot_b = voice->formant_stride * (int)id_b + 1;
    int16_t tmp[10];
    int i;
    if (slot_a < 0 || slot_a + 10 > voice->formant_words) {
        memset(lpc, 0, 11 * sizeof(int16_t));
        return;
    }
    if (blend == 0 || id_a == id_b || slot_b < 0 || slot_b + 10 > voice->formant_words) {
        ot_formants_to_lpc(voice->formant + slot_a, lpc);
        return;
    }
    for (i = 0; i < 10; i++) {
        int delta = (int)voice->formant[slot_b + i] - (int)voice->formant[slot_a + i];
        int64_t prod = (int64_t)blend * (int64_t)delta;
        int low = (int)prod;
        int byte4 = (int)(uint8_t)((uint64_t)prod >> 32);
        tmp[i] = (int16_t)(voice->formant[slot_a + i] + ot_asr(byte4 + low, 8));
    }
    ot_formants_to_lpc(tmp, lpc);
}

static int ot_render_frames(const OtFrames *fr, int period, uint16_t phase0, uint8_t noise_flip, OtPcm *pcm,
                            const OtVoice *voice)
{
    uint16_t state[80];
    uint16_t prev_a = 0xFFFFu;
    uint16_t prev_b = 0xFFFFu;
    uint32_t pos = 0;
    memset(state, 0, sizeof state);
    state[1] = (uint16_t)(phase0 & 0x0FFFu);
    *((uint8_t *)state + 32) = noise_flip;
    while (pos + 6 <= fr->cursor) {
        uint8_t type = fr->buf[pos];
        uint8_t blend = fr->buf[pos + 1];
        uint16_t formant;
        uint16_t pitch_word;
        uint16_t id_a;
        uint16_t id_b;
        int samples;
        int cls;
        int16_t lpc[11];
        int k;
        uint32_t step;
        memcpy(&formant, fr->buf + pos + 2, 2);
        memcpy(&pitch_word, fr->buf + pos + 4, 2);
        if (type == 0) {
            id_a = prev_a;
            id_b = prev_b;
            step = 6;
        } else if (type == 1) {
            if (pos + 8 > fr->cursor) {
                break;
            }
            id_a = prev_b;
            memcpy(&id_b, fr->buf + pos + 6, 2);
            step = 8;
        } else if (type == 2) {
            if (pos + 8 > fr->cursor) {
                break;
            }
            memcpy(&id_a, fr->buf + pos + 6, 2);
            id_b = id_a;
            step = 8;
        } else if (type == 3) {
            if (pos + 10 > fr->cursor) {
                break;
            }
            memcpy(&id_a, fr->buf + pos + 6, 2);
            memcpy(&id_b, fr->buf + pos + 8, 2);
            step = 10;
        } else {
            break;
        }
        cls = pitch_word & 0xC000;
        if (cls == 0) {
            samples = 40 * period / 256;
        } else if (cls == 0x4000) {
            samples = 200 * period / 1024;
        } else if (cls == 0x8000) {
            samples = 240 * period / 1024;
        } else {
            samples = 280 * period / 1024;
        }
        state[0] = (uint16_t)(formant & 0xFFu);
        state[2] = (uint16_t)((formant >> 8) & 0xFFu);
        state[3] = (uint16_t)(pitch_word & 0x3FFFu);
        if (state[3] == 0) {
            state[15] = 1;
        }
        ot_blend_lpc(voice, id_a, id_b, blend, lpc);
        ot_render_prepare(state, voice);
        for (k = 0; k < samples; k++) {
            int16_t sample = 0;
            int err = ot_render_sample(state, lpc, &sample, voice);
            if (err) {
                return err;
            }
            err = ot_pcm_append(pcm, sample, 1);
            if (err) {
                return err;
            }
        }
        prev_a = id_a;
        prev_b = id_b;
        pos += step;
    }
    return 0;
}

static int ot_speak_phrase(const uint8_t *phonemes, int count, int period, uint16_t phase0,
                           uint8_t noise_flip, OtPcm *pcm, int prosody, const OtVoice *voice)
{
    OtToken tokens[OT_TOKEN_MAX];
    OtFrames frames;
    int ntok = 0;
    int err;
    if (count <= 0) {
        return 0;
    }
    err = ot_tokens_from_phonemes(phonemes, count, tokens, &ntok, prosody, voice);
    if (err) {
        return err;
    }
    memset(&frames, 0, sizeof frames);
    err = ot_expand_tokens(tokens, ntok, &frames, voice);
    if (err) {
        return err;
    }
    return ot_render_frames(&frames, period, phase0, noise_flip, pcm, voice);
}

int ot_render_tokens(const OtToken *tok, int ntok, int period, uint16_t phase0,
                     uint8_t noise_flip, OtPcm *pcm, const OtVoice *voice)
{
    OtFrames frames;
    int err;
    memset(&frames, 0, sizeof frames);
    err = ot_expand_tokens(tok, ntok, &frames, voice);
    if (err) {
        return err;
    }
    return ot_render_frames(&frames, period, phase0, noise_flip, pcm, voice);
}

/*
 * sub_18000141C calls sub_180002DC0 once per phrase. A byte 6..9 ends the
 * phrase (sub_1800021D8 still sees it) and the following bytes <= 9 are
 * silence only: 6 adds 666, 7 adds 2000, 8 or 9 adds 4000. Sample count is
 * the 32-bit product period * units / 256, appended after the phrase when
 * more phonemes remain. The last pause byte becomes the next phrase's
 * prosody nibble (reader byte +1, initially 8). A trailing pause is not
 * appended here; the caller supplies the 256-sample tail.
 */
int ot_speak(const uint8_t *phonemes, int count, int period, uint16_t phase0, uint8_t noise_flip, OtPcm *pcm,
           const OtVoice *voice)
{
    int pos = 0;
    int prosody = 8;
    if (count <= 0) {
        return 0;
    }
    while (pos < count) {
        int i = pos;
        int pause_at = -1;
        while (i < count) {
            uint8_t b = phonemes[i];
            if (b >= 6 && b <= 9) {
                pause_at = i;
                break;
            }
            i++;
        }
        if (pause_at < 0) {
            return ot_speak_phrase(phonemes + pos, count - pos, period, phase0, noise_flip, pcm, prosody,
                                   voice);
        }
        {
            int end = pause_at;
            int units = 0;
            int next_prosody = prosody;
            int err;
            while (end < count && phonemes[end] <= 9) {
                uint8_t p = phonemes[end];
                if (p >= 2) {
                    next_prosody = p;
                    if (p == 6) {
                        units += 666;
                    } else if (p == 7) {
                        units += 2000;
                    } else if (p == 8 || p == 9) {
                        units += 4000;
                    }
                }
                end++;
            }
            err = ot_speak_phrase(phonemes + pos, end - pos, period, phase0, noise_flip, pcm, prosody,
                                  voice);
            if (err) {
                return err;
            }
            prosody = next_prosody;
            pos = end;
            if (pos < count && units > 0) {
                uint32_t samples = ((uint32_t)period * (uint32_t)units) / 256u;
                err = ot_pcm_append(pcm, 0, samples);
                if (err) {
                    return err;
                }
            }
        }
    }
    return 0;
}
