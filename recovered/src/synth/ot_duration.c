/*
 * Per-slot duration and the '+' phrase join. 13248 is the duration base.
 * Nibble 3 is '+', nibble 4 is '/', nibble 9 is '?'.
 */

#include "ot_synth.h"

#include <stdint.h>

/* Signed divide by 1024, matching the cdq / and 0x3FF / sar 10 in sub_180003A1C. */
static int16_t ot_div1024(int32_t v)
{
    if (v < 0) {
        v += 1023;
    }
    return (int16_t)(v >> 10);
}

/*
 * Per-slot duration delta from sub_180003A1C. The caller adds 13248.
 * count >= 7 and an accent index >= 4 recurses on a split chunk. The stack byte
 * Hex-Rays left uninitialized only contributes a high nibble, and the
 * callee masks that byte to its low nibble, so the split is determined.
 */
static int16_t ot_slot_delta(const OtVoice *voice, int slot, int count, int accent, int nibble, int scale,
                             int next_accent)
{
    int base = 0;
    int key_count;
    int key2;
    int idx = -1;
    int row;
    int value;
    int i;
    if (count < 2) {
        if (accent) {
            return (int16_t)(5 * (int16_t)scale);
        }
        return 0;
    }
    if (count >= 7 && accent >= 4) {
        if (slot < accent) {
            return ot_slot_delta(voice, slot, accent - 1, 0, 3, scale, 1);
        }
        return ot_slot_delta(voice, slot - accent + 1, count - accent + 1, 1, nibble, scale, next_accent);
    }
    if (nibble == 6 || nibble == 7) {
        next_accent = 0;
        base = 60;
    } else if (nibble == 8) {
        next_accent = 1;
        base = 60;
    } else if (nibble == 9) {
        next_accent = 2;
        base = 60;
    }
    key_count = count;
    if (count < 1) {
        key_count = 1;
    } else if (count > 6) {
        key_count = 6;
    }
    if (accent > 5) {
        accent = 5;
    }
    key2 = (key_count != accent) ? accent : 0;
    if (next_accent < 0) {
        next_accent = 0;
    }
    if (next_accent > 2) {
        next_accent = 2;
    }
    for (i = 0; i < 60; i++) {
        if (voice->dur_key[i * 4] == key_count && voice->dur_key[i * 4 + 1] == key2
            && voice->dur_key[i * 4 + 2] == next_accent) {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        return 0;
    }
    row = base + idx;
    if (count <= 6) {
        value = voice->dur_val[10 * row + 2 + slot];
    } else {
        int boundary = voice->dur_val[10 * row + 1];
        if (slot <= boundary) {
            value = voice->dur_val[10 * row + 2 + slot];
        } else if (slot > boundary + count - 6) {
            value = voice->dur_val[10 * row + 8 + (slot - count)];
        } else {
            int left = voice->dur_val[10 * row + 2 + boundary];
            int right = voice->dur_val[10 * row + 3 + boundary];
            int den = (int16_t)(count - 5);
            value = left;
            if (den) {
                value = left + (slot - boundary) * (right - left) / den;
            }
        }
    }
    return ot_div1024((int32_t)(int16_t)scale * (int32_t)(int16_t)value);
}

int ot_clamped_dur(const OtVoice *voice, int slot, int count, int accent, int nibble, int scale,
                   int next_accent)
{
    /* sub_180003A1C / FUN_0010d06c: (delta * M) / 163, then dur_base, all in 32 bits.
     * M is 163 in the root voice, so the root keeps the plain delta. */
    int delta = (int)ot_slot_delta(voice, slot, count, accent, nibble, scale, next_accent);
    int scaled = (int)((int32_t)delta * (int32_t)voice->dur_scale_num / 163);
    int dur = voice->dur_base + scaled;
    if (dur < 0) {
        dur = 0;
    }
    if (dur > 65535) {
        dur = 65535;
    }
    return dur;
}

/*
 * sub_180003C68. A chunk closed by '+' (low nibble 3) is joined with the
 * following chunk. Slots from index 2 of that join are timed again as one
 * phrase, then each stored duration is the average of the separate timing
 * and the joined timing. The following chunk's first slot is averaged the
 * same way when a third chunk exists and the joined low nibble is not 6..9.
 */
void ot_merge_plus(const OtVoice *voice, struct OtChunk *chunks, int nchunk, const int *slot_ph,
                   uint16_t *durs)
{
    int i;
    for (i = 0; i + 1 < nchunk; i++) {
        int na;
        int nb;
        int nc;
        int join_word;
        int join_low;
        int join_scale;
        int third;
        int a4_third;
        int s;
        int from_slot;
        int comb_i;
        int next_i;
        uint16_t comb[2048];
        if (chunks[i].low != 3) {
            continue;
        }
        na = chunks[i].n;
        nb = chunks[i + 1].n;
        nc = na + nb;
        if (nc > 2048) {
            continue;
        }
        join_word = chunks[i].accent;
        if (join_word == 0 && chunks[i + 1].accent != 0) {
            join_word = na + chunks[i + 1].accent;
        }
        join_scale = chunks[i].scale;
        join_low = chunks[i + 1].low;
        third = (i + 2 < nchunk) ? (i + 2) : -1;
        a4_third = (third >= 0) ? chunks[third].accent : 0;
        for (s = 2; s < nc; s++) {
            comb[s] = (uint16_t)ot_clamped_dur(voice, s, nc, join_word, join_low, join_scale, a4_third);
        }
        if (na > 2) {
            for (s = 2; s < na; s++) {
                int at = slot_ph[chunks[i].slot0 + s];
                durs[at] = (uint16_t)(((unsigned)durs[at] + (unsigned)comb[s]) >> 1);
            }
        }
        from_slot = (na > 2) ? na : 2;
        comb_i = from_slot;
        next_i = 0;
        while (from_slot < nc) {
            int at = slot_ph[chunks[i + 1].slot0 + next_i];
            from_slot++;
            durs[at] = (uint16_t)(((unsigned)durs[at] + (unsigned)comb[comb_i]) >> 1);
            comb_i++;
            next_i++;
        }
        if ((unsigned)(join_low - 6) > 3u && third >= 0
            && !(chunks[third].n == 2 && chunks[third].accent == 1)) {
            int cross_dur = ot_clamped_dur(voice, nc, nc, join_word, join_low, join_scale,
                                           chunks[third].accent);
            int at = slot_ph[chunks[third].slot0];
            durs[at] = (uint16_t)(((unsigned)cross_dur + (unsigned)durs[at]) >> 1);
        }
    }
}
