/*
 * Phoneme bytes to diphone tokens. Pitch is 0x3E8000 / duration.
 * A closing '?' (nibble 9) adds 6400 to the last transition.
 */

#include "ot_synth.h"

#include "ot_internal.h"
#include "ot_frame_data.h"
#include "ot_f3.h"

#include <stdint.h>
#include <string.h>

static int ot_push(OtToken *tok, int *n, const uint8_t sym[2], uint16_t dur)
{
    uint16_t pitch = 0;
    if (*n >= OT_TOKEN_MAX) {
        return OT_ERR_PHONEME;
    }
    if (dur) {
        pitch = (uint16_t)(0x3E8000u / dur);
    }
    tok[*n].pitch = pitch;
    tok[*n].a = sym[0];
    tok[*n].b = sym[1];
    (*n)++;
    return 0;
}

/* sub_180003784 */
static uint8_t ot_map_consonant(uint8_t ch)
{
    if ((uint8_t)(ch - 66) <= 0x32u && ot_bittest64(0x4422700044625ull, (unsigned)(ch - 66))) {
        return 107;
    }
    if ((uint8_t)(ch - 72) <= 0x2Bu && ot_bittest64(0x80140000801ull, (unsigned)(ch - 72))) {
        return 115;
    }
    if (((ch - 77) & 0xDEu) == 0) {
        return 110;
    }
    if (((ch - 82) & 0xDFu) == 0) {
        return 114;
    }
    if (((ch - 106) & 0xEFu) == 0) {
        return 122;
    }
    if (((ch - 86) & 0xDFu) != 0) {
        return ((ch - 119) & 0xFDu) == 0 ? 121 : 0;
    }
    return 118;
}

static int ot_name_ok(unsigned code)
{
    return code < (unsigned)ot_phoneme_sym_count;
}

/* f3's symbol chunk has a class-0 record whose two bytes are the boundary
 * character twice (".."). Root symbols do not, so this stays off. */
static int ot_boundary_is_class0(const OtVoice *voice)
{
    int i;
    uint8_t ch;
    if (!voice) {
        return 0;
    }
    ch = (uint8_t)voice->boundary;
    for (i = 0; i < voice->symbol_count; i++) {
        if (voice->symbols[i].a == ch && voice->symbols[i].b == ch && voice->symbols[i].cls == 0) {
            return 1;
        }
    }
    return 0;
}

static int ot_push_boundary_pair(OtToken *tok, int *n, const OtVoice *voice)
{
    uint8_t pair[2];
    pair[0] = (uint8_t)voice->boundary;
    pair[1] = pair[0];
    return ot_push(tok, n, pair, (uint16_t)voice->dur_base);
}

/* sub_180003440 */
static int ot_emit_pair(OtToken *tok, int *n, uint8_t prev, uint8_t cur, uint16_t dur, int mark,
                        int boundary)
{
    const uint8_t *ps;
    const uint8_t *cs;
    uint8_t tmp[2];
    if (!ot_name_ok(prev) || !ot_name_ok(cur)) {
        return OT_ERR_SYMBOL;
    }
    ps = ot_phoneme_sym[prev];
    cs = ot_phoneme_sym[cur];
    if (cur == 0xA1) {
        tmp[0] = ps[1];
        tmp[1] = cs[0];
        return ot_push(tok, n, tmp, dur);
    }
    if ((uint8_t)(cur - 10) <= 4u || cur == 0x9F) {
        uint8_t ch = cs[0];
        if ((uint8_t)(prev - 6) > 3u) {
            if (ps[1] == ch) {
                tmp[0] = ch;
                tmp[1] = (uint8_t)mark;
            } else {
                tmp[0] = '+';
                tmp[1] = ch;
            }
        } else {
            tmp[0] = (uint8_t)boundary;
            tmp[1] = ch;
        }
        return ot_push(tok, n, tmp, dur);
    }
    return ot_push(tok, n, cs, dur);
}

/* sub_1800034F0. The 5th argument is the duration word. sub_180003010
   clears r10, so the closing call passes 0 except when the last chunk
   low nibble is 9 and the last slot duration is nonzero. */
static int ot_emit_transition(OtToken *tok, int *n, uint8_t prev, uint8_t cur, uint16_t dur,
                              int boundary)
{
    const uint8_t *ps;
    const uint8_t *cs;
    uint8_t second;
    uint8_t tmp[2];
    uint8_t mapped;
    int rc;
    if (!ot_name_ok(prev) || !ot_name_ok(cur)) {
        return OT_ERR_SYMBOL;
    }
    ps = ot_phoneme_sym[prev];
    cs = ot_phoneme_sym[cur];
    second = ps[1];
    if ((uint8_t)(second - 97) <= 0x17u && ot_bittest(9453841u, (unsigned)(second - 97))) {
        if (cur <= 9u) {
            tmp[0] = second;
            tmp[1] = (uint8_t)boundary;
            return ot_push(tok, n, tmp, dur);
        }
        if ((uint8_t)(cs[0] - 75) <= 0x29u && ot_bittest64(0x22101000263ull, (unsigned)(cs[0] - 75))) {
            tmp[0] = '+';
            tmp[1] = 'k';
            return ot_push(tok, n, tmp, dur);
        }
        if ((uint8_t)(cs[0] - 70) <= 0x2Du && ot_bittest64(0x200100002001ull, (unsigned)(cs[0] - 70))) {
            tmp[0] = '+';
            tmp[1] = 's';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 77) & 0xDEu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'n';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 72) & 0xDFu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'h';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 82) & 0xDFu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'r';
            return ot_push(tok, n, tmp, dur);
        }
        if ((uint8_t)(cs[0] - 68) <= 0x23u && ot_bittest64(0x900080009ull, (unsigned)(cs[0] - 68))) {
            tmp[0] = '+';
            tmp[1] = 'g';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 66) & 0xDFu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'b';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 106) & 0xEFu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'z';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 86) & 0xDFu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'v';
            return ot_push(tok, n, tmp, dur);
        }
        if (((cs[0] - 119) & 0xFDu) == 0) {
            tmp[0] = '+';
            tmp[1] = 'w';
            return ot_push(tok, n, tmp, dur);
        }
    }
    if ((uint8_t)(second - 65) <= 0x14u && ot_bittest(1065217u, (unsigned)(second - 65))) {
        if (cs[0] <= 0x3Fu && ot_bittest64(0x8000500000000000ull, cs[0])) {
            tmp[0] = second;
            tmp[1] = (uint8_t)boundary;
            return ot_push(tok, n, tmp, dur);
        }
        if ((uint8_t)(cs[0] - 75) <= 0x29u && ot_bittest64(0x22101000223ull, (unsigned)(cs[0] - 75))) {
            tmp[0] = ',';
            tmp[1] = 'k';
            return ot_push(tok, n, tmp, dur);
        }
        if ((uint8_t)(cs[0] - 72) <= 0x2Bu && ot_bittest64(0x80140000801ull, (unsigned)(cs[0] - 72))) {
            tmp[0] = ',';
            tmp[1] = 's';
            return ot_push(tok, n, tmp, dur);
        }
        if (cs[0] == '-') {
            return 0;
        }
        tmp[0] = second;
        tmp[1] = (uint8_t)boundary;
        rc = ot_push(tok, n, tmp, dur);
        if (rc) {
            return rc;
        }
        mapped = ot_map_consonant(cs[0]);
        if (mapped) {
            tmp[0] = (uint8_t)boundary;
            tmp[1] = mapped;
            return ot_push(tok, n, tmp, dur);
        }
        return 0;
    }
    if (ps[1] <= 0x3Fu && ot_bittest64(0x8000500000000000ull, ps[1])) {
        mapped = ot_map_consonant(cs[0]);
        if (mapped) {
            tmp[0] = (uint8_t)boundary;
            tmp[1] = mapped;
            return ot_push(tok, n, tmp, dur);
        }
    }
    return 0;
}

/* sub_180003290. A zero pitch is filled from its neighbours.
 * base is the r14d immediate (0x135 in the root DLL, other voices differ). */
static void ot_fill_pitch(OtToken *tok, int n, int base)
{
    int i;
    for (i = 0; i < n; i++) {
        uint16_t flags = (uint16_t)(tok[i].pitch & 0xC000u);
        if ((tok[i].pitch & 0x3FFFu) != 0) {
            continue;
        }
        if (i == n - 1) {
            int v = 0;
            if (i > 0) {
                v = tok[i - 1].pitch & 0x3FFF;
            }
            if (i >= 2) {
                v = 2 * v - (tok[i - 2].pitch & 0x3FFF);
            }
            if (v > base) {
                v = base;
            }
            if (v < 0) {
                v = 0;
            }
            tok[i].pitch = (uint16_t)(flags | (uint16_t)v);
        } else {
            int j = i + 1;
            while (j < n && (tok[j].pitch & 0x3FFFu) == 0) {
                j++;
            }
            if (j < n) {
                int next = tok[j].pitch & 0x3FFF;
                int filled;
                if (i > 0) {
                    int prev = tok[i - 1].pitch & 0x3FFF;
                    filled = prev + (next - prev) / (j - i + 1);
                } else {
                    filled = 5 * (next - base) / 6 + base;
                }
                if (filled < 0) {
                    filled = 0;
                }
                tok[i].pitch = (uint16_t)(flags | (uint16_t)filled);
            } else if (i >= 2) {
                int v = 2 * (tok[i - 1].pitch & 0x3FFF) - (tok[i - 2].pitch & 0x3FFF);
                if (v > base) {
                    v = base;
                }
                if (v < 0) {
                    v = 0;
                }
                tok[i].pitch = (uint16_t)(flags | (uint16_t)v);
            } else {
                tok[i].pitch = (uint16_t)(flags | (uint16_t)base);
            }
        }
    }
}

/* Tail flags from sub_180002DC0 after the token list is built. */
static void ot_tag_tail(OtToken *tok, int n, int mark, int boundary)
{
    if (n < 2) {
        return;
    }
    tok[n - 1].pitch = (uint16_t)((tok[n - 1].pitch & 0x3FFFu) | 0x8000u);
    tok[n - 2].pitch = (uint16_t)((tok[n - 2].pitch & 0x3FFFu) | 0x8000u);
    if (tok[n - 2].b == (uint8_t)mark) {
        return;
    }
    if (tok[n - 2].a == '+' && (uint8_t)(tok[n - 2].b - 'a') <= 0x17u
        && ot_bittest(9453841u, (unsigned)(tok[n - 2].b - 'a'))) {
        return;
    }
    if (n >= 3 && tok[n - 3].b != (uint8_t)boundary) {
        uint16_t bits = 0x8000u;
        if (((tok[n - 3].b - 81) & 0xDFu) == 0) {
            bits = 0x4000u;
        }
        tok[n - 3].pitch = (uint16_t)((tok[n - 3].pitch & 0x3FFFu) | bits);
    }
}

/*
 * One phrase of phoneme bytes. Each diphone slot's duration is 13248 plus
 * the per-slot delta, then the pitch word is 0x3E8000 / duration.
 */
int ot_tokens_from_phonemes(const uint8_t *ph, int count, OtToken *tok, int *n, int prosody,
                            const OtVoice *voice)
{
    enum { OT_PH_MAX = 2048, OT_CHUNK_MAX = 512 };
    uint8_t prev = 8;
    int i = 0;
    int rc;
    uint16_t durs[OT_PH_MAX];
    int slot_ph[OT_PH_MAX] = {0};
    int nslot = 0;
    int high = prosody;
    int open = 0;
    int low = 8;
    int accent = 0;
    int slot0 = 0;
    struct OtChunk chunks[OT_CHUNK_MAX];
    int nchunk = 0;
    *n = 0;
    if (count > OT_PH_MAX) {
        return OT_ERR_PHONEME;
    }
    for (i = 0; i < count; i++) {
        durs[i] = (uint16_t)voice->dur_base;
    }
    i = 0;
    while (i < count) {
        uint8_t b = ph[i];
        if (b == 2) {
            i++;
            continue;
        }
        if (!open) {
            if (b >= 2 && b <= 9) {
                high = b;
                i++;
                continue;
            }
            open = 1;
            low = 8;
            accent = 0;
            slot0 = nslot;
        }
        if (b <= 9) {
            if (b == 1) {
                accent = nslot - slot0;
            } else if (nslot > slot0 && nchunk < OT_CHUNK_MAX) {
                chunks[nchunk].slot0 = slot0;
                chunks[nchunk].n = nslot - slot0;
                chunks[nchunk].accent = accent;
                chunks[nchunk].low = b;
                chunks[nchunk].high = high;
                nchunk++;
                high = b;
                open = 0;
            } else {
                high = b;
                open = 0;
            }
            i++;
            continue;
        }
        if (nslot < OT_PH_MAX) {
            slot_ph[nslot++] = i;
        }
        i++;
    }
    if (open && nslot > slot0 && nchunk < OT_CHUNK_MAX) {
        chunks[nchunk].slot0 = slot0;
        chunks[nchunk].n = nslot - slot0;
        chunks[nchunk].accent = accent;
        chunks[nchunk].low = low;
        chunks[nchunk].high = high;
        nchunk++;
    }
    /*
     * sub_1800037F0 first walk. Scale is word_18002CF90[7 * high - 24 + low].
     * A '+' chunk (low nibble 3) takes the next non-'+' low nibble for that
     * index (sub_1800022F8). The following chunk keeps the same scale when
     * its high nibble is also 3.
     */
    {
        int scale_state = 1024;
        for (i = 0; i < nchunk; i++) {
            int skip = 0;
            if (i > 0 && chunks[i - 1].low == 3 && chunks[i].high == 3) {
                skip = 1;
            } else if (i > 0 && chunks[i - 1].low == 4 && chunks[i].high == 4
                       && chunks[i - 1].accent == 0 && chunks[i].accent == 1) {
                /* sub_1800037F0 keeps the previous scale across this '/'. */
                skip = 1;
            }
            if (!skip) {
                int low_for_scale = chunks[i].low;
                int idx;
                int sc;
                int prev_scale = scale_state;
                if (low_for_scale == 3) {
                    int j = i + 1;
                    low_for_scale = 8;
                    while (j < nchunk && chunks[j].low == 3) {
                        j++;
                    }
                    if (j < nchunk) {
                        low_for_scale = chunks[j].low;
                    }
                }
                idx = 7 * chunks[i].high + low_for_scale;
                sc = 0;
                if (idx >= 0 && idx < 121) {
                    sc = voice->dur_scale[idx];
                }
                if (i > 0 && chunks[i - 1].accent == 0 && chunks[i].high == 4
                    && sc < 8 * prev_scale / 10) {
                    sc = 8 * prev_scale / 10;
                }
                scale_state = sc;
            }
            chunks[i].scale = scale_state;
        }
    }
    for (i = 0; i < nchunk; i++) {
        int next4 = (i + 1 < nchunk) ? chunks[i + 1].accent : 0;
        int s;
        for (s = 0; s < chunks[i].n; s++) {
            int at = slot_ph[chunks[i].slot0 + s];
            durs[at] = (uint16_t)ot_clamped_dur(voice, s, chunks[i].n, chunks[i].accent, chunks[i].low,
                                                chunks[i].scale, next4);
        }
    }
    /*
     * sub_1800037F0. When another chunk follows, its first slot is replaced
     * by sub_180003A1C(previous count, previous chunk, next accent) + 13248,
     * unless the next chunk is exactly count 2 and accent 1, or the previous
     * low nibble is 5 and the next accent is 1.
     */
    for (i = 0; i + 1 < nchunk; i++) {
        int nn = chunks[i + 1].n;
        int nw = chunks[i + 1].accent;
        int at;
        if (nn < 2) {
            continue;
        }
        if (nn == 2 && nw == 1) {
            continue;
        }
        if (chunks[i].low == 5 && nw == 1) {
            continue;
        }
        at = slot_ph[chunks[i + 1].slot0];
        durs[at] = (uint16_t)ot_clamped_dur(voice, chunks[i].n, chunks[i].n, chunks[i].accent, chunks[i].low,
                                            chunks[i].scale, nw);
    }
    ot_merge_plus(voice, chunks, nchunk, slot_ph, durs);
    /* f3 Open_Talk+0x35dc stores '.' and emits ".." before the diphones.
     * The same pair is appended again and left unrendered (see ot_expand). */
    if (ot_boundary_is_class0(voice)) {
        rc = ot_push_boundary_pair(tok, n, voice);
        if (rc) {
            return rc;
        }
    }
    i = 0;
    while (i < count) {
        uint8_t cur = ph[i];
        /* Bytes 1..9 are chunk controls in sub_1800021D8 (accent nibble or a
           count copy), not diphone slots. */
        if (cur <= 9) {
            i++;
            continue;
        }
        if (cur == 0xA0 && i + 1 < count) {
            uint8_t nxt = ph[i + 1];
            uint8_t sym[2];
            sym[0] = '+';
            sym[1] = 'q';
            if (ot_name_ok(nxt) && (ot_phoneme_sym[nxt][0] == 'S' || ot_phoneme_sym[nxt][0] == 's')) {
                sym[1] = 'Q';
            }
            rc = ot_push(tok, n, sym, durs[i]);
            if (rc) {
                return rc;
            }
            rc = ot_emit_pair(tok, n, 0xA0, nxt, durs[i + 1], voice->vowel_mark, voice->boundary);
            if (rc) {
                return rc;
            }
            prev = nxt;
            i += 2;
            continue;
        }
        if (cur == 0xA0) {
            uint8_t sym[2];
            sym[0] = '+';
            sym[1] = 'q';
            rc = ot_push(tok, n, sym, durs[i]);
            if (rc) {
                return rc;
            }
            prev = cur;
            i++;
            continue;
        }
        rc = ot_emit_transition(tok, n, prev, cur, 0, voice->boundary);
        if (rc) {
            return rc;
        }
        rc = ot_emit_pair(tok, n, prev, cur, durs[i], voice->vowel_mark, voice->boundary);
        if (rc) {
            return rc;
        }
        if (cur != 0xA1) {
            prev = cur;
        }
        i++;
    }
    /*
     * Closing transition in sub_180003010. Duration stays 0 unless the last
     * chunk's low nibble is 9 ('?'), in which case it is the last slot
     * duration plus 6400 when that duration is not zero.
     */
    {
        uint16_t tail_dur = 0;
        uint8_t tail_ph = 8;
        if (nchunk > 0) {
            tail_ph = (uint8_t)chunks[nchunk - 1].low;
            if (tail_ph == 9 && chunks[nchunk - 1].n > 0) {
                int at = slot_ph[chunks[nchunk - 1].slot0 + chunks[nchunk - 1].n - 1];
                tail_dur = durs[at];
                if (tail_dur != 0) {
                    int sum = (int)tail_dur + voice->q_tail;
                    if (sum > 65535) {
                        sum = 65535;
                    }
                    tail_dur = (uint16_t)sum;
                }
            }
        }
        rc = ot_emit_transition(tok, n, prev, tail_ph, tail_dur, voice->boundary);
    }
    if (rc) {
        return rc;
    }
    if (ot_boundary_is_class0(voice)) {
        rc = ot_push_boundary_pair(tok, n, voice);
        if (rc) {
            return rc;
        }
    }
    if (voice->engine == OT_ENGINE_F3) {
        ot_f3_adjust_tokens(tok, n);
    }
    ot_fill_pitch(tok, *n, voice->base_pitch);
    ot_tag_tail(tok, *n, voice->vowel_mark, voice->boundary);
    /* f3 Open_Talk+0x335a: once four tokens exist, the last four pitch words
     * are forced to class 0x8000. あ is exactly those four ("..", ".a", "a.", ".."). */
    if (ot_boundary_is_class0(voice) && *n >= 4) {
        int k;
        for (k = *n - 4; k < *n; k++) {
            tok[k].pitch = (uint16_t)((tok[k].pitch & 0x3FFFu) | 0x8000u);
        }
    }
    return 0;
}
