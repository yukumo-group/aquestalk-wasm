/*
 * COUNTER, MODE, rendaku, and the irregular nin/nichi readings.
 */

#include "ot_internal.h"
#include "ot_text_int.h"

#include "ot_frame_data.h"

#include <stdint.h>
#include <string.h>

/*
 * Readings selected by MODE's first letter, RVA 0x2E370.
 * Index is mode0 * 12 + place-class. A null slot keeps the ordinary name.
 */
static const char *const ot_mode_read[20][12] = {
    {"re--", "iici", "ni", "saxx", "yoxx", "go", "roku", "nana", "haci", "Ku--", "ju--", "Haku"},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "juQQ", 0},
    {0, "iiQQ", 0, 0, 0, 0, 0, 0, 0, 0, "juQQ", 0},
    {0, 0, 0, 0, 0, 0, "roQQ", 0, 0, 0, "juQQ", "HaQQ"},
    {0, "iiQQ", 0, 0, 0, 0, 0, 0, "haQQ", 0, "juQQ", 0},
    {0, "iiQQ", 0, 0, 0, 0, "roQQ", 0, 0, 0, "juQQ", "HaQQ"},
    {0, "iiQQ", 0, 0, 0, 0, "roQQ", 0, "haQQ", 0, "juQQ", "HaQQ"},
    {0, 0, 0, 0, "Si", 0, 0, "Sici", 0, "ku", 0, 0},
    {0, 0, 0, 0, 0, 0, 0, "Sici", 0, "ku", 0, 0},
    {0, 0, 0, 0, 0, 0, 0, "Sici", 0, 0, 0, 0},
    {0, 0, 0, 0, "yo", 0, 0, "Sici", 0, "ku", 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, "ku", 0, 0},
    {0, 0, 0, 0, "yo", 0, 0, 0, 0, 0, 0, 0},
    {0, "hito", "futa", "mi", "yo", "iiTu", "mu", 0, "ya", "kokono", "juQQ", 0},
    {0, "hito", "futa", "mi", "yo", "iiTu", "mu", 0, "ya", 0, "juQQ", 0},
    {0, "hito", "futa", "mi", "yo", "iiTu", 0, 0, 0, 0, "juQQ", 0},
    {0, "hito", "futa", "mi", "yo", "iiTu", 0, 0, 0, 0, 0, 0},
    {0, "hito", "futa", "mi", "yo", 0, 0, 0, 0, 0, "juQQ", 0},
    {0, "hito", "futa", 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, "iiQQ", "ni--", 0, 0, "go--", 0, 0, "haQQ", 0, "juQQ", 0},
};

/* Default prosody for a counter with no MODE. RVA 0x2E070, 28 bytes each. */
static const struct {
    const char *name;
    int m0;
    int m1;
    int m2;
    int at;
} ot_counter_mode[] = {
    {"nexx", 12, 0, 10, 0},
    {"vaTu", 7, 0, 5, 0},
    {"nici", 8, 0, 5, 0},
    {"ji", 10, 0, 7, 0},
    {"fuxx", 6, 1, 7, 0},
    {"Bo--", 0, 0, 7, 0},
    {"eexx", 12, 0, 3, 0},
    {"nixx", 12, 0, 9, 0},
    {"kaii", 5, 0, 0, 1},
    {"kaii", 5, 0, 0, 0},
    {"kaveTu", 6, 0, 0, 1},
    {"Ku--", 5, 0, 1, 0},
    {"Vo--", 0, 0, 7, 0},
    {"Koku", 5, 0, 6, 0},
    {"kiro", 3, 0, 7, 0},
    {"kexx", 5, 0, 7, 0},
    {"ko", 5, 0, 7, 0},
    {"saii", 4, 0, 7, 0},
    {"jikaxx", 10, 0, 0, 1},
    {"daii", 0, 0, 8, 0},
    {"co--me", 4, 0, 4, 0},
    {"Tuki", 13, 0, 12, 0},
    {"baxx", 0, 0, 8, 0},
    {"hoxx", 6, 2, 7, 0},
    {"pa--sexxto", 1, 0, 0, 3},
    {"karori--", 1, 0, 0, 1},
    {"hiki", 6, 2, 15, 0},
};

/* sub_180005514. Indexed as 5 * place-class + mode1. */
static const uint8_t ot_rendaku[80] = {
    0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 1, 1, 1, 0, 2,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/* sub_1800055DC. Indexed as 13 * mode2 + row. -1 means "length of the words". */
static const int8_t ot_accent_row[208] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0,
    2, 0, 0, 0, 1, 1, 0, 2, 0, 1, 0, 2, 1, 2, 2, 1, 1, 1, 1, 2, 2, 2, 1, 0, 2, 1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 2, -1,
    2, -1, 1, 1, 1, 1, -1, 2, 2, 1, -1, 2, 1, 2, 2, 1, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1,
    2, 2, 1, 1, 1, 0, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 3, 2, 2, 2, 2, 2, 1, 2, 2, 1,
    1, 2, 1, 0, 0, 0, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1,
    1, 2, 2, 1, 1, 2, 1, 2, 1, 3, 2, 2, 1, 3, 2, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, -1, 1, 1, 1, 1, -1, 2, -1, 1, -1, 2, 1
};

/* dword_18002DF88[digit]. Only '0'..'9' are read. */
static const int ot_accent_extra[10] = {2, 2, 1, 2, 2, 1, 2, 2, 2, 2};

static int ot_slen(const char *s)
{
    int n = 0;
    if (!s) {
        return 0;
    }
    while (s[n]) {
        n++;
    }
    return n;
}

/* sub_180005170. Kana becomes two-letter symbols. Phoneme 1 records the accent token. */
static int ot_counter_pairs(const uint8_t *src, char *dst, int *accent_at)
{
    int index = 0;
    char *out = dst;
    *accent_at = 0;
    if (!src) {
        *out = 0;
        return 0;
    }
    while (*src) {
        int used = 0;
        int code = ot_dict_lookup(src, &used);
        uint8_t a;
        if (!code || used <= 0) {
            return OT_ERR_EMPTY_TAG;
        }
        if (code == 1) {
            *accent_at = index;
        } else if (code > 0 && code < ot_phoneme_sym_count) {
            a = ot_phoneme_sym[code][0];
            if (a == 'g') {
                a = 'v';
            } else if (a == 'G') {
                a = 'V';
            }
            *out++ = (char)a;
            *out++ = (char)ot_phoneme_sym[code][1];
        } else {
            return OT_ERR_OTHER;
        }
        index++;
        src += used;
    }
    *out = 0;
    return 0;
}

/* sub_18000541C. MODE is three letters, or a known counter supplies them. */
static int ot_resolve_mode(const char *pairs, int accent_at, const char *mode, int *m0, int *m1, int *m2)
{
    int i;
    *m0 = 0;
    *m1 = 0;
    *m2 = 0;
    if (mode) {
        unsigned a = (unsigned)((int)mode[0] - 'A');
        unsigned b = (unsigned)((int)mode[1] - 'a');
        unsigned c = (unsigned)((int)mode[2] - 'A');
        if (a > 0x13u || b > 0x0Fu || c > 0x0Fu) {
            return OT_ERR_EMPTY_TAG;
        }
        *m0 = (int)a;
        *m1 = (int)b;
        *m2 = (int)c;
        return 0;
    }
    for (i = 0; i < 27; i++) {
        if (ot_counter_mode[i].at == accent_at && strcmp(pairs, ot_counter_mode[i].name) == 0) {
            *m0 = ot_counter_mode[i].m0;
            *m1 = ot_counter_mode[i].m1;
            *m2 = ot_counter_mode[i].m2;
            break;
        }
    }
    return 0;
}

/* sub_180005514. Rewrites the counter's first letter for rendaku or handakuon. */
static void ot_apply_rendaku(char *pairs, int place_class, int mode1)
{
    int kind;
    if ((unsigned)(mode1 - 1) > 3u || (unsigned)(place_class - 1) > 14u) {
        return;
    }
    kind = ot_rendaku[5 * place_class + mode1];
    if (kind == 1) {
        if (pairs[0] == 'w' && pairs[1] == 'a') {
            pairs[0] = 'b';
            pairs[1] = 'a';
            return;
        }
        switch (pairs[0]) {
        case 'H': pairs[0] = 'B'; break;
        case 'K': pairs[0] = 'V'; break;
        case 'S':
        case 'c': pairs[0] = 'j'; break;
        case 'h': pairs[0] = 'b'; break;
        case 'k': pairs[0] = 'v'; break;
        case 's': pairs[0] = 'z'; break;
        case 't': pairs[0] = 'd'; break;
        default: break;
        }
    } else if (kind == 2) {
        if (pairs[0] == 'w' && pairs[1] == 'a') {
            pairs[0] = 'p';
            pairs[1] = 'a';
        } else if (pairs[0] == 'H') {
            pairs[0] = 'P';
        } else if (pairs[0] == 'h') {
            pairs[0] = 'p';
        } else if (pairs[0] == 'f' && pairs[1] == 'u') {
            pairs[0] = 'p';
            pairs[1] = 'u';
        }
    }
}

/* sub_1800055DC. The returned accent counts pairs from the start of the slot. */
static int ot_counter_accent(const uint8_t window[4], int column, int place_class, const char *name,
                             const char *suffix, const char *counter, int mode2, int accent_at)
{
    int digit;
    int row;
    int b;
    if (mode2 == 0) {
        if (!accent_at) {
            return 0;
        }
        return accent_at + (ot_slen(name) + ot_slen(suffix)) / 2;
    }
    digit = window[3 - column];
    if (place_class < 10) {
        row = place_class;
    } else if (place_class <= 11) {
        row = 10 + (digit != '1');
    } else if (place_class == 12) {
        if (digit != '1') {
            return 0;
        }
        row = 12;
    } else {
        int w2 = window[2];
        int w3 = window[3];
        if ((w2 == '1' && w3 != '0') || ((unsigned)(w2 - '0') > 1u && w3 == '0')
            || (window[0] > '0' && window[1] == '0' && w2 == '0' && w3 == '0')) {
            return (ot_slen(name) + ot_slen(suffix)) / 2 - 1;
        }
        return 0;
    }
    b = ot_accent_row[13 * mode2 + row];
    if (b == -1) {
        return (ot_slen(name) + ot_slen(suffix) + ot_slen(counter)) / 2;
    }
    if (b == 0) {
        return 0;
    }
    if ((unsigned)(place_class - 10) <= 2u && digit != '1') {
        return ot_accent_extra[digit - '0'] + b;
    }
    return b;
}

/*
 * sub_180004CA0 when COUNTER is set. The ordinary name is kept unless MODE's
 * first component selects a string. The counter is spoken on the same accent.
 */
int ot_numk_slot_counter(uint8_t *buf, int *count, const uint8_t window[4], int place,
                                const char *counter, const char *mode, int flag)
{
    int column = place & 3;
    int digit = window[3 - column] - '0';
    int place_class;
    int m0 = 0;
    int m1 = 0;
    int m2 = 0;
    int accent_at = 0;
    int accent;
    int npairs = 0;
    int err;
    int replace;
    const char *name;
    const char *suffix = 0;
    char pairs[64];
    if (digit < 0 || digit > 9) {
        return OT_ERR_NONDIGIT;
    }
    if (place == 0) {
        place_class = digit;
    } else if (place < 4) {
        place_class = place + 9;
    } else {
        place_class = place / 4 + 12;
    }
    name = ot_numk_name[column][digit];
    accent = ot_numk_accent[column][digit];
    if (flag && place_class >= 13 && column == 3 && window[3 - column] == '1') {
        name = ot_numk_name[column][0];
        if (place_class == 15) {
            accent = 0;
            suffix = "co--";
        } else {
            accent = ot_numk_accent[column][0];
        }
    } else if (place_class == 15) {
        suffix = "co--";
    } else if (place_class == 13) {
        suffix = "maxx";
        accent = ot_slen(name) / 2 + 1;
    } else if (place_class == 14) {
        suffix = "ooku";
        accent = ot_slen(name) / 2;
    }
    err = ot_counter_pairs((const uint8_t *)counter, pairs, &accent_at);
    if (err) {
        return err;
    }
    err = ot_resolve_mode(pairs, accent_at, mode, &m0, &m1, &m2);
    if (err) {
        return err;
    }
    replace = 0;
    if (m0 && place_class <= 11) {
        const char *alt = ot_mode_read[m0][place_class];
        if (place_class < 10) {
            if (alt) {
                name = alt;
            }
        } else if (alt) {
            replace = 1;
        }
    }
    ot_apply_rendaku(pairs, place_class, m1);
    accent = ot_counter_accent(window, column, place_class, name, suffix, pairs, m2, accent_at);
    err = ot_speak_pairs_from(buf, count, name, accent, &npairs);
    if (err) {
        return err;
    }
    if (replace && *count > 0) {
        uint8_t *ph = ot_ph();
        if (ph[*count - 1] == 1 && *count >= 2) {
            ph[*count - 2] = 1;
        }
        ph[*count - 1] = 0xA0;
    }
    err = ot_speak_pairs_from(buf, count, suffix, accent, &npairs);
    if (err) {
        return err;
    }
    return ot_speak_pairs_from(buf, count, pairs, accent, &npairs);
}

static int ot_numk_window_counter(uint8_t *buf, int *count, const uint8_t window[4], int place0,
                                  const char *counter, const char *mode, int flag)
{
    int last = 3;
    int i;
    int seen = 0;
    int err;
    while (last >= 0 && window[last] == '0') {
        last--;
    }
    if (last < 0) {
        return ot_numk_slot_counter(buf, count, window, place0, counter, mode, 0);
    }
    for (i = 0; i < last; i++) {
        int place = place0 + (3 - i);
        if (window[i] != '0') {
            err = ot_numk_place(buf, count, place, window[i] - '0');
            if (err) {
                return err;
            }
            err = ot_append_byte(buf, count, 4);
            if (err) {
                return err;
            }
        }
        seen++;
    }
    err = ot_numk_slot_counter(buf, count, window, place0 + (3 - seen), counter, mode, flag);
    if (err) {
        return err;
    }
    if (window[2] <= '8' && window[3] != '0') {
        unsigned bit = (unsigned)window[2];
        if (bit < 64 && ((0x162000000000000ULL >> bit) & 1ULL)) {
            ot_numk_fixup(buf, count, window[2] == '1');
        }
    }
    return 0;
}

/* Irregular counters in sub_180005774. The bytes are the whole reading. */
static int ot_append_raw(uint8_t *buf, int *count, const uint8_t *s)
{
    return ot_append_cstr(buf, count, (const char *)s);
}

static int ot_numk_irregular(const uint8_t *text, const uint8_t *counter, uint8_t *buf, int *count, int *done)
{
    const uint8_t *p = text;
    *done = 0;
    if (!counter || !counter[0]) {
        return 0;
    }
    if (strcmp((const char *)counter, "\x82\xC9\x82\xF1") == 0) {
        if (strcmp((const char *)text, "1") == 0) {
            *done = 1;
            return ot_append_raw(buf, count, (const uint8_t *)"\xB9\x1B\x01\x2D");
        }
        if (strcmp((const char *)text, "2") == 0) {
            *done = 1;
            return ot_append_raw(buf, count, (const uint8_t *)"\xBA\x19\x2D\x01");
        }
        return 0;
    }
    if (strcmp((const char *)counter, "\x82\xC9\x82\xBF") != 0) {
        return 0;
    }
    while (*p == '0') {
        p++;
    }
    if (strcmp((const char *)p, "1") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\xC1\x0B\x19\xBF\x01");
    }
    if (strcmp((const char *)p, "2") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\xBA\xC1\x0F");
    }
    if (strcmp((const char *)p, "3") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x28\xA0\x0F");
    }
    if (strcmp((const char *)p, "4") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x52\xA0\x0F");
    }
    if (strcmp((const char *)p, "5") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x0B\xC1\x0F");
    }
    if (strcmp((const char *)p, "6") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x29\x0B\x0F");
    }
    if (strcmp((const char *)p, "7") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x1E\x22\x0F");
    }
    if (strcmp((const char *)p, "8") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x52\xA1\x0F");
    }
    if (strcmp((const char *)p, "9") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x13\x13\x22\x0F");
    }
    if (strcmp((const char *)p, "10") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x1B\xA1\x0F");
    }
    if (strcmp((const char *)p, "14") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x7B\x01\xA1\x52\xA0\x0F");
    }
    if (strcmp((const char *)p, "20") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x23\xC1\x0F");
    }
    if (strcmp((const char *)p, "24") == 0) {
        *done = 1;
        return ot_append_raw(buf, count, (const uint8_t *)"\x1F\x01\x7B\xA1\x04\x52\xA0\x0F");
    }
    return 0;
}

/*
 * sub_1800047D0 for one 4-digit window. COUNTER and MODE reach only the last
 * slot (sub_180004F48). A null counter leaves MODE unused, matching 004CA0.
 */
int ot_read_numk_counter(uint8_t *text, uint8_t *buf, int *count, const char *counter, const char *mode)
{
    int n = 0;
    int i;
    int done = 0;
    int err;
    uint8_t window[4];
    if (!text || !text[0]) {
        return text ? 0 : OT_ERR_OTHER;
    }
    if (!mode) {
        err = ot_numk_irregular(text, (const uint8_t *)counter, buf, count, &done);
        if (err || done) {
            return err;
        }
    }
    while (text[n]) {
        if ((uint8_t)(text[n] - '0') > 9) {
            return OT_ERR_NONDIGIT;
        }
        n++;
    }
    if (n == 1 && text[0] == '0') {
        return ot_numk_slot_counter(buf, count, (const uint8_t *)"0000", 0, counter, mode, 0);
    }
    if (n > 4) {
        return OT_ERR_OTHER;
    }
    for (i = 0; i < 4; i++) {
        int src = i - (4 - n);
        window[i] = (src >= 0) ? text[src] : (uint8_t)'0';
    }
    return ot_numk_window_counter(buf, count, window, 0, counter, mode, 1);
}

/*
 * sub_1800047D0 with a null MODE and no counter. One 4-digit window from the
 * right for values shorter than 5 digits, which is what Open_Talk+0x4CA0
 * receives ("0001", "0010", "0012", "0023").
 */
int ot_read_numk(uint8_t *text, uint8_t *buf, int *count)
{
    int n = 0;
    int i;
    uint8_t window[4];
    if (!text) {
        return OT_ERR_OTHER;
    }
    if (!*text) {
        return 0;
    }
    while (text[n]) {
        if ((uint8_t)(text[n] - '0') > 9) {
            return OT_ERR_NONDIGIT;
        }
        n++;
    }
    if (n == 1 && text[0] == '0') {
        return ot_numk_window(buf, count, (const uint8_t *)"0000", 0);
    }
    if (n > 4) {
        return OT_ERR_OTHER;
    }
    for (i = 0; i < 4; i++) {
        int src = i - (4 - n);
        window[i] = (src >= 0) ? text[src] : '0';
    }
    return ot_numk_window(buf, count, window, 0);
}
