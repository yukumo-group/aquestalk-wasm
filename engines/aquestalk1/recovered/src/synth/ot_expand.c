/*
 * Frame expansion. Each diphone class writes 6, 8, or 10 byte frames.
 */

#include "ot_synth.h"

#include "ot_internal.h"
#include "ot_frame_data.h"

#include <string.h>

static const OtSymbol *ot_find_symbol(const OtVoice *voice, uint8_t a, uint8_t b)
{
    int i;
    for (i = 0; i < voice->symbol_count; i++) {
        if (voice->symbols[i].a == a && voice->symbols[i].b == b) {
            return &voice->symbols[i];
        }
    }
    return NULL;
}

/* sub_180001B74. a1 (the record) is used; the dead rcx values at the
   scale calls are not this function. */
static int16_t ot_param(const OtVoice *voice, const OtSymbol *rec, int index)
{
    int n = index;
    int slot;
    if (n == -1) {
        n = (int)rec->count - 1;
    }
    switch (rec->cls) {
    case 1:
        slot = voice->formant_stride * (n + (int)rec->index);
        if ((unsigned)slot >= (unsigned)voice->formant_words) {
            return 0;
        }
        return voice->formant[slot];
    case 3:
        slot = voice->formant_stride * (int)rec->index;
        if ((unsigned)slot >= (unsigned)voice->formant_words) {
            return 0;
        }
        return voice->formant[slot];
    case 2:
    case 4:
    case 5:
    case 6:
    case 11:
        slot = n + (int)rec->index;
        if ((unsigned)slot >= (unsigned)voice->phoneme_word_count) {
            return 0;
        }
        return voice->phoneme_word[slot];
    default:
        return -12222;
    }
}

/* sub_180001C04 */
static uint16_t ot_param_id(const OtSymbol *rec, int index)
{
    int n = index;
    if (n == -1) {
        n = (int)rec->count - 1;
    }
    if (rec->cls == 1) {
        return (uint16_t)(rec->index + n);
    }
    if (rec->cls == 3) {
        return rec->index;
    }
    return 0;
}

/* sub_180002D64. The first argument is unused, which is why Hex-Rays
   reported v43, v67, and v72: those were a stale rcx. */
static void ot_scale_pair(uint8_t out[2], const uint8_t num[2], const uint8_t den[2], const uint8_t mul[2])
{
    out[0] = den[0] ? (uint8_t)((unsigned)mul[0] * num[0] / den[0]) : 0;
    out[1] = den[1] ? (uint8_t)((unsigned)mul[1] * num[1] / den[1]) : 0;
}

static void ot_store16(uint8_t *p, uint16_t v)
{
    memcpy(p, &v, 2);
}

/* sub_180001C78 */
static int ot_emit(OtFrames *fr, uint16_t flags, uint16_t pitch, uint16_t formant,
                   uint8_t blend, uint16_t left_id, uint16_t right_id)
{
    uint8_t *p;
    uint16_t stored;
    if ((int)fr->cursor + 10 > OT_FRAME_MAX) {
        return OT_ERR_FRAMES;
    }
    p = fr->buf + fr->cursor;
    stored = (uint16_t)(flags | (pitch & 0x3FFFu));
    if (fr->prev_left == left_id && fr->prev_right == right_id) {
        p[0] = 0;
        p[1] = blend;
        ot_store16(p + 2, formant);
        ot_store16(p + 4, stored);
        fr->cursor += 6;
    } else if (fr->prev_right == left_id) {
        p[0] = 1;
        p[1] = blend;
        ot_store16(p + 2, formant);
        ot_store16(p + 4, stored);
        ot_store16(p + 6, right_id);
        fr->cursor += 8;
    } else if (left_id == right_id) {
        /* The type word is stored as the immediate 2, so the blend byte is 0. */
        p[0] = 2;
        p[1] = 0;
        ot_store16(p + 2, formant);
        ot_store16(p + 4, stored);
        ot_store16(p + 6, left_id);
        fr->cursor += 8;
    } else {
        p[0] = 3;
        p[1] = blend;
        ot_store16(p + 2, formant);
        ot_store16(p + 4, stored);
        ot_store16(p + 6, left_id);
        ot_store16(p + 8, right_id);
        fr->cursor += 10;
    }
    fr->prev_left = left_id;
    fr->prev_right = right_id;
    return 0;
}

static uint16_t ot_interp_pitch(uint16_t prev, uint16_t cur, int step, int count)
{
    int delta = (int)cur - (int)prev;
    int q = (step << 8) / count;
    return (uint16_t)(ot_div_pow2((int)(uint16_t)q * delta, 8) + (int)prev);
}

/* sub_18000242C class 2/3 formant blend. The new Linux build factors this
 * into one helper (FUN_0010b24e) used by both class-2 arms: the special arm
 * blends from prev_form to the symbol's LAST parameter, the normal arm blends
 * to the next symbol's first parameter. */
static uint16_t ot_blend_form(const OtVoice *voice, const OtSymbol *rec, int step,
                              int16_t target, int16_t prev_form)
{
    int count = (int)rec->count;
    int16_t s0 = ot_param(voice, rec, 0);
    int16_t s_last = ot_param(voice, rec, -1);
    int16_t s_step = ot_param(voice, rec, step);
    uint8_t lo0 = (uint8_t)s0;
    uint8_t lol = (uint8_t)s_last;
    uint8_t lot = (uint8_t)target;
    uint8_t los = (uint8_t)s_step;
    uint8_t hi0 = (uint8_t)((uint16_t)s0 >> 8);
    uint8_t hil = (uint8_t)((uint16_t)s_last >> 8);
    uint8_t hit = (uint8_t)((uint16_t)target >> 8);
    uint8_t his = (uint8_t)((uint16_t)s_step >> 8);
    uint8_t prev_lo = (uint8_t)prev_form;
    uint8_t prev_hi = (uint8_t)((uint16_t)prev_form >> 8);
    uint8_t lo;
    uint8_t hi;

    if (lo0 != lol) {
        int numer = ((int)lot - (int)prev_lo) << 10;
        int denom = (int)lol - (int)lo0;
        int quot = numer / denom;
        if ((unsigned)quot <= 0x1000u) {
            int v = ot_div_pow2(((int)los - (int)lo0) * quot, 10) + (int)prev_lo;
            lo = v > 0 ? (uint8_t)v : 0;
        } else {
            lo = (uint8_t)(prev_lo + ((int)lot - (int)prev_lo) * step / count);
        }
    } else {
        lo = (uint8_t)(prev_lo + ((int)lot - (int)prev_lo) * step / count);
    }
    if (hi0 != hil) {
        int numer = ((int)hit - (int)prev_hi) << 10;
        int denom = (int)hil - (int)hi0;
        int quot = numer / denom;
        if ((unsigned)quot <= 0x1000u) {
            int v = ot_div_pow2(((int)his - (int)hi0) * quot, 10) + (int)prev_hi;
            hi = v > 0 ? (uint8_t)v : 0;
        } else {
            hi = (uint8_t)(prev_hi + ((int)hit - (int)prev_hi) * step / count);
        }
    } else {
        hi = (uint8_t)(prev_hi + ((int)hit - (int)prev_hi) * step / count);
    }
    return (uint16_t)(lo | (hi << 8));
}

int ot_expand_tokens(const OtToken *tok, int ntok, OtFrames *fr, const OtVoice *voice)
{
    int index;
    int spoken;
    uint16_t prev_pitch;
    uint16_t prev_id = 0;
    int16_t prev_form = 0;
    int16_t prev_scaled = 0;

    if (ntok <= 0) {
        return 0;
    }
    fr->prev_left = 0xFFFFu;
    fr->prev_right = 0xFFFFu;
    fr->cursor = 0;
    prev_pitch = (uint16_t)(tok[0].pitch & 0x3FFFu);
    /*
     * f3's expander (Open_Talk+0x31da) stops at count-1. The extra token is
     * the class-0 terminator "..", which is there for the next-symbol read
     * and is not itself rendered. Root tables have no class-0 symbol, so
     * every token is still spoken.
     */
    spoken = ntok;
    {
        const OtSymbol *tail = ot_find_symbol(voice, tok[ntok - 1].a, tok[ntok - 1].b);
        if (tail && tail->cls == 0 && ntok > 1) {
            spoken = ntok - 1;
        }
    }
    for (index = 0; index < spoken; index++) {
        uint16_t flags = (uint16_t)(tok[index].pitch & 0xC000u);
        uint16_t cur_pitch = (uint16_t)(tok[index].pitch & 0x3FFFu);
        const OtSymbol *rec = ot_find_symbol(voice, tok[index].a, tok[index].b);
        uint8_t cls;
        uint8_t count;
        int err = 0;
        if (!rec) {
            return OT_ERR_SYMBOL;
        }
        cls = rec->cls;
        count = rec->count;
        if (cls == 0) {
            /* Open_Talk+0x24f5. count frames of formant 0 at this token's pitch. */
            int step;
            for (step = 0; step < (int)count; step++) {
                err = ot_emit(fr, flags, cur_pitch, 0, 0, 0, 0);
                if (err) {
                    return err;
                }
            }
            prev_id = 0;
            prev_form = 0;
        } else if (cls == 1) {
            int16_t sample1 = 0;
            int step;
            int16_t form = prev_form;
            uint16_t phon = prev_id;
            if (count > 1) {
                sample1 = ot_param(voice, rec, 1);
            }
            for (step = 0; step < (int)count; step++) {
                int16_t sample = ot_param(voice, rec, step);
                uint16_t id = ot_param_id(rec, step);
                uint16_t pitch;
                /* Class 1 writes one frame per sample. The blend byte is 0. */
                if (step != 0 || count <= 1
                    || (uint8_t)((uint16_t)sample >> 8) == 0
                    || (uint8_t)((uint16_t)sample1 >> 8) != 0) {
                    pitch = ot_interp_pitch(prev_pitch, cur_pitch, step, count);
                } else {
                    pitch = 0;
                }
                err = ot_emit(fr, flags, pitch, (uint16_t)sample, 0, id, id);
                if (err) {
                    return err;
                }
                form = sample;
                phon = id;
            }
            prev_form = form;
            prev_id = phon;
        } else if (cls == 3) {
            /* Class 3 walks the symbol's sample count. */
            uint16_t id = rec->index;
            int16_t target = ot_param(voice, rec, -1);
            int step;
            uint8_t prev_lo = (uint8_t)prev_form;
            uint8_t prev_hi = (uint8_t)((uint16_t)prev_form >> 8);
            int dlo = (int)(uint8_t)target - (int)prev_lo;
            int dhi = (int)(uint8_t)((uint16_t)target >> 8) - (int)prev_hi;
            int dp = (int)cur_pitch - (int)prev_pitch;
            for (step = 0; step < (int)count; step++) {
                int q = (step << 8) / (int)count;
                uint16_t q16 = (uint16_t)q;
                uint8_t lo = (uint8_t)(ot_div_pow2(dlo * (int)q16, 8) + (int)prev_lo);
                uint8_t hi = (uint8_t)(ot_div_pow2(dhi * (int)q16, 8) + (int)prev_hi);
                uint16_t pitch = (uint16_t)(ot_div_pow2((int)q16 * dp, 8) + (int)prev_pitch);
                err = ot_emit(fr, flags, pitch, (uint16_t)(lo | (hi << 8)), (uint8_t)q16, prev_id, id);
                if (err) {
                    return err;
                }
            }
            prev_id = id;
            prev_form = target;
        } else if (cls == 2) {
            uint8_t na = 0;
            uint8_t nb = 0;
            const OtSymbol *next;
            uint16_t next_id = 0;
            int special;
            if (index + 1 < ntok) {
                na = tok[index + 1].a;
                nb = tok[index + 1].b;
            } else {
                /* unk_18002FD88, the two bytes past a finished token list. */
                na = ';';
                nb = ';';
            }
            next = ot_find_symbol(voice, na, nb);
            if (!next) {
                return OT_ERR_SYMBOL;
            }
            special = (tok[index].a == '+'
                          && (uint8_t)(tok[index].b - 'b') <= 15
                          && ot_bittest(0x8221u, (unsigned)(tok[index].b - 'b')))
                || (tok[index].a == ',' && tok[index].b == 'k');
            /*
             * Open_Talk+0x242C case 2. The +4 is only on the special arm
             * (next class 1). The other arm uses the symbol index as stored.
             */
            if (next->cls == 1) {
                next_id = next->index;
                if (special) {
                    next_id = (uint16_t)(next->index + 4);
                }
            } else if (next->cls == 3) {
                next_id = next->index;
            }
            if (special) {
                /* New build: blend from prev_form to the symbol's last
                 * parameter (the old DLL scaled by the first parameter). */
                int16_t target = ot_param(voice, rec, -1);
                int step;
                uint16_t form = 0;
                for (step = 0; step < (int)count; step++) {
                    int q = (step << 8) / (int)count;
                    uint16_t pitch = ot_interp_pitch(prev_pitch, cur_pitch, step, count);
                    form = ot_blend_form(voice, rec, step, target, prev_form);
                    err = ot_emit(fr, flags, pitch, form, (uint8_t)q, prev_id, next_id);
                    if (err) {
                        return err;
                    }
                }
                if ((int)count > 0) {
                    prev_form = (int16_t)form;
                }
                prev_id = next_id;
            } else {
                int16_t target = ot_param(voice, next, 0);
                int step;
                for (step = 0; step < (int)count; step++) {
                    int q = (step << 8) / (int)count;
                    uint16_t pitch = ot_interp_pitch(prev_pitch, cur_pitch, step, count);
                    uint16_t form = ot_blend_form(voice, rec, step, target, prev_form);
                    err = ot_emit(fr, flags, pitch, form, (uint8_t)q, prev_id, next_id);
                    if (err) {
                        return err;
                    }
                }
                prev_form = target;
                prev_id = next_id;
            }
        } else if (cls == 4) {
            uint8_t na = 0;
            uint8_t nb = 0;
            const OtSymbol *next;
            uint16_t next_id = 0;
            int step;
            if (index + 1 < ntok) {
                na = tok[index + 1].a;
                nb = tok[index + 1].b;
            }
            next = ot_find_symbol(voice, na, nb);
            if (!next) {
                return OT_ERR_SYMBOL;
            }
            if (next->cls == 1 || next->cls == 3) {
                next_id = next->index;
            }
            if (tok[index].a == ';' && (tok[index].b == 'k' || tok[index].b == 'v')) {
                for (step = 0; step < (int)count; step++) {
                    uint16_t pitch = ot_interp_pitch(prev_pitch, cur_pitch, step, count);
                    err = ot_emit(fr, flags, pitch, 0, 0, next_id, next_id);
                    if (err) {
                        return err;
                    }
                }
                prev_form = 0;
                prev_id = next_id;
            } else {
                int16_t from_next = ot_param(voice, next, 0);
                int16_t last = ot_param(voice, rec, -1);
                uint8_t den[2];
                uint8_t num[2];
                memcpy(num, &from_next, 2);
                memcpy(den, &last, 2);
                for (step = 0; step < (int)count; step++) {
                    int16_t sample = ot_param(voice, rec, step);
                    uint8_t mul[2];
                    uint8_t out[2];
                    uint16_t form;
                    uint16_t pitch = ot_interp_pitch(prev_pitch, cur_pitch, step, count);
                    memcpy(mul, &sample, 2);
                    ot_scale_pair(out, num, den, mul);
                    memcpy(&form, out, 2);
                    err = ot_emit(fr, flags, pitch, form, 0, next_id, next_id);
                    if (err) {
                        return err;
                    }
                }
                prev_form = last;
                prev_id = next_id;
            }
        } else if (cls == 5) {
            /* Class 5 uses the sample count as the divisor. */
            int16_t base = ot_param(voice, rec, 0);
            int16_t numer = prev_form;
            int step;
            uint8_t den[2];
            uint8_t num[2];
            int16_t scaled = prev_scaled;
            memcpy(den, &base, 2);
            memcpy(num, &numer, 2);
            if (count == 0) {
                prev_form = prev_scaled;
            } else {
                for (step = 0; step < (int)count; step++) {
                    int16_t sample = ot_param(voice, rec, step);
                    uint8_t mul[2];
                    uint8_t out[2];
                    uint16_t form;
                    uint16_t pitch = ot_interp_pitch(prev_pitch, cur_pitch, step, count);
                    memcpy(mul, &sample, 2);
                    ot_scale_pair(out, num, den, mul);
                    memcpy(&form, out, 2);
                    err = ot_emit(fr, flags, pitch, form, 0, prev_id, prev_id);
                    if (err) {
                        return err;
                    }
                    scaled = (int16_t)form;
                }
                prev_scaled = scaled;
                prev_form = scaled;
            }
        }
        prev_pitch = cur_pitch;
    }
    return 0;
}
