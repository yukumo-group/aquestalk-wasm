/*
 * NUMK place-name readings. The accent dword inserts phoneme 1.
 */

#include "ot_internal.h"
#include "ot_text_int.h"

#include "ot_frame_data.h"

#include <stdint.h>
#include <string.h>

/* aRe at RVA 0x2EBC0, 16 bytes per digit and place. Accent is the dword at +12. */
const char *const ot_numk_name[4][10] = {
    {"re--", "iici", "ni", "saxx", "yoxx", "go", "roku", "nana", "haci", "Ku--"},
    {"", "ju--", "niju--", "saxxju--", "yoxxju--", "goju--", "rokuju--", "nanaju--", "haciju--", "Ku--ju--"},
    {"", "Haku", "niHaku", "saxxBaku", "yoxxHaku", "goHaku", "roQQPaku", "nanaHaku", "haQQPaku", "Ku--Haku"},
    {"iiQQsexx", "sexx", "nisexx", "saxxzexx", "yoxxsexx", "gosexx", "rokusexx", "nanasexx", "haQQsexx", "Ku--sexx"}
};
const int ot_numk_accent[4][10] = {
    {1, 2, 1, 0, 1, 1, 2, 1, 2, 1},
    {0, 1, 1, 1, 1, 2, 2, 2, 2, 1},
    {0, 2, 3, 1, 1, 3, 4, 2, 4, 1},
    {3, 1, 2, 3, 3, 2, 3, 3, 3, 3}
};

static int ot_find_pair(uint8_t a, uint8_t b)
{
    int code;
    for (code = ot_phoneme_sym_count - 1; code > 0; code--) {
        if (ot_phoneme_sym[code][0] == a && ot_phoneme_sym[code][1] == b) {
            return code;
        }
    }
    return -1;
}

/* sub_1800052DC. Each two letters are a symbol. The accent index inserts byte 1. */
static int ot_speak_pairs(uint8_t *buf, int *count, const char *s, int accent)
{
    int n = 0;
    while (s[0] && s[1]) {
        int code = ot_find_pair(s[0], s[1]);
        int err;
        if (code < 0) {
            return OT_ERR_OTHER;
        }
        n++;
        if (n == accent && (uint8_t)(code + 97) <= 2) {
            err = ot_append_byte(buf, count, 1);
            if (!err) {
                err = ot_append_byte(buf, count, code);
            }
        } else if (n == accent) {
            err = ot_append_byte(buf, count, code);
            if (!err) {
                err = ot_append_byte(buf, count, 1);
            }
        } else {
            err = ot_append_byte(buf, count, code);
        }
        if (err) {
            return err;
        }
        s += 2;
    }
    return 0;
}

/* sub_180004CA0 for a null MODE, then sub_180004F48 over one 4-digit window. */
int ot_numk_place(uint8_t *buf, int *count, int place, int digit)
{
    int col = place & 3;
    if (digit < 0 || digit > 9 || col < 0 || col > 3) {
        return OT_ERR_NONDIGIT;
    }
    return ot_speak_pairs(buf, count, ot_numk_name[col][digit], ot_numk_accent[col][digit]);
}

static void ot_delete_phoneme(uint8_t *buf, int *count, int index)
{
    uint8_t *ph;
    int i;
    (void)buf;
    if (index < 0 || index >= *count) {
        return;
    }
    ph = ot_ph();
    for (i = index; i + 1 < *count; i++) {
        ph[i] = ph[i + 1];
    }
    (*count)--;
}

/*
 * sub_180001A40. After a 4-digit group whose tens digit is 1, 5, 6, or 8
 * and whose ones digit is not 0, drop the separator and the accent that
 * belongs to the tens reading. Open_Talk+0x1A40.
 */
void ot_numk_fixup(uint8_t *buf, int *count, int ones_ichi)
{
    uint8_t *ph = ot_ph();
    int n = *count;
    int i;
    int after;
    int earlier;
    if (n <= 0) {
        return;
    }
    i = n - 1;
    while (i >= 0 && (uint8_t)(ph[i] - 3) > 6) {
        i--;
    }
    if (i < 0) {
        return;
    }
    after = i + 1;
    earlier = after - 2;
    if (earlier < 0 || earlier >= n) {
        return;
    }
    while (earlier >= 0 && (uint8_t)(ph[earlier] - 3) > 6) {
        earlier--;
    }
    if (earlier < 0) {
        earlier = 0;
    } else {
        earlier++;
    }
    if (ones_ichi) {
        int at = after;
        while (at < n && ph[at] != 1) {
            at++;
        }
        if (at >= n) {
            ot_delete_phoneme(buf, count, after - 1);
            return;
        }
    }
    ot_delete_phoneme(buf, count, after - 1);
    {
        int j = earlier;
        while (j < after && ph[j] != 1) {
            j++;
        }
        if (j >= after) {
            j = -1;
        }
        ot_delete_phoneme(buf, count, j);
    }
}

int ot_numk_window(uint8_t *buf, int *count, const uint8_t window[4], int place0)
{
    int last = 3;
    int i;
    int seen = 0;
    int err;
    while (last >= 0 && window[last] == '0') {
        last--;
    }
    if (last < 0) {
        return ot_numk_place(buf, count, place0, 0);
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
    err = ot_numk_place(buf, count, place0 + (3 - seen), window[last] - '0');
    if (err) {
        return err;
    }
    /* Tens digit selects sub_180001A40. Bit 49/53/54/56 of 0x162000000000000. */
    if (window[2] <= '8' && window[3] != '0') {
        unsigned bit = (unsigned)window[2];
        if (bit < 64 && ((0x162000000000000ULL >> bit) & 1ULL)) {
            ot_numk_fixup(buf, count, window[2] == '1');
        }
    }
    return 0;
}

/* sub_18000521C continues one accent count across the name, the place suffix, and the counter. */
int ot_speak_pairs_from(uint8_t *buf, int *count, const char *s, int accent, int *npairs)
{
    if (!s || !s[0]) {
        return 0;
    }
    while (s[0] && s[1]) {
        int code = ot_find_pair((uint8_t)s[0], (uint8_t)s[1]);
        int n;
        int err;
        if (code < 0) {
            return OT_ERR_OTHER;
        }
        n = ++(*npairs);
        if (n == accent && (uint8_t)(code + 97) <= 2) {
            err = ot_append_byte(buf, count, 1);
            if (!err) {
                err = ot_append_byte(buf, count, code);
            }
        } else if (n == accent) {
            err = ot_append_byte(buf, count, code);
            if (!err) {
                err = ot_append_byte(buf, count, 1);
            }
        } else {
            err = ot_append_byte(buf, count, code);
        }
        if (err) {
            return err;
        }
        s += 2;
    }
    return 0;
}
