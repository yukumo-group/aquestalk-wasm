/*
 * Tag lexer for NUM, NUMK, and ALPHA, including decimals.
 */

#include "ot_internal.h"
#include "ot_text_int.h"

#include "ot_data.h"

#include <stdint.h>
#include <string.h>

static int ot_sep(uint8_t ch)
{
    return ch == ' ' || ch == '=' || ch == '>' || ch == '\t' || ch == '\n';
}

static uint8_t *ot_next_tok(uint8_t **pp)
{
    uint8_t *p = *pp;
    uint8_t *start;
    if (!p) {
        return NULL;
    }
    while (*p && ot_sep(*p)) {
        p++;
    }
    if (*p == 0) {
        *pp = p;
        return NULL;
    }
    if (*p == '"') {
        start = ++p;
        while (*p && *p != '"') {
            p++;
        }
        if (*p == '"') {
            *p++ = 0;
        }
        *pp = p;
        return start;
    }
    start = p;
    while (*p && !ot_sep(*p)) {
        p++;
    }
    if (*p) {
        *p++ = 0;
    }
    *pp = p;
    return start;
}

static int ot_key_eq(const uint8_t *key, const char *name)
{
    while (*key && *name) {
        uint8_t a = *key++;
        uint8_t b = (uint8_t)*name++;
        if (a >= 'A' && a <= 'Z') {
            a = (uint8_t)(a + 32);
        }
        if (b >= 'A' && b <= 'Z') {
            b = (uint8_t)(b + 32);
        }
        if (a != b) {
            return 0;
        }
    }
    return *key == 0 && *name == 0;
}

/*
 * sub_180001000. Letter rows are two C strings (offsets 0 and 6).
 * A digit run is handed to sub_180004704. A following character appends pause 7.
 */
static int ot_romaji(uint8_t *text, uint8_t *buf, int *count)
{
    uint8_t *p = text;
    while (*p) {
        uint8_t ch = *p;
        if ((uint8_t)(ch - 'A') <= 25 || (uint8_t)(ch - 'a') <= 25) {
            uint8_t *start = p;
            int group = 0;
            uint8_t saved;
            while ((uint8_t)(*p - 'A') <= 25 || (uint8_t)(*p - 'a') <= 25) {
                p++;
            }
            saved = *p;
            *p = 0;
            while (*start) {
                int base = (*start > 'Z') ? 'a' : 'A';
                int row = 12 * (*start - base);
                int err;
                start++;
                if (*start == 0) {
                    err = ot_append_span(buf, count, ot_letter_rows + row + 6, 6);
                    if (err) {
                        *p = saved;
                        return err;
                    }
                    break;
                }
                if (group == 3) {
                    err = ot_append_span(buf, count, ot_letter_rows + row + 6, 6);
                    if (err) {
                        *p = saved;
                        return err;
                    }
                    err = ot_append_byte(buf, count, 7);
                    if (err) {
                        *p = saved;
                        return err;
                    }
                    group = 0;
                } else {
                    err = ot_append_span(buf, count, ot_letter_rows + row, 6);
                    if (err) {
                        *p = saved;
                        return err;
                    }
                    err = ot_append_byte(buf, count, 4);
                    if (err) {
                        *p = saved;
                        return err;
                    }
                    group++;
                }
            }
            *p = saved;
            if (saved) {
                int err = ot_append_byte(buf, count, 7);
                if (err) {
                    return err;
                }
            }
        } else if ((uint8_t)(ch - '0') <= 9) {
            uint8_t *start = p;
            uint8_t saved;
            int err;
            while ((uint8_t)(*p - '0') <= 9) {
                p++;
            }
            saved = *p;
            *p = 0;
            err = ot_read_number(start, buf, count);
            *p = saved;
            if (err) {
                return err;
            }
            if (saved) {
                err = ot_append_byte(buf, count, 7);
                if (err) {
                    return err;
                }
            }
        } else {
            int row;
            int matched = 0;
            for (row = 0; row < 21; row++) {
                if (ot_punct_rows[row * 8] == ch) {
                    int err = ot_append_span(buf, count, ot_punct_rows + row * 8 + 1, 7);
                    if (err) {
                        return err;
                    }
                    matched = 1;
                    break;
                }
            }
            p++;
            if (matched && *p) {
                int err = ot_append_byte(buf, count, 7);
                if (err) {
                    return err;
                }
            }
        }
    }
    return 0;
}

/*
 * sub_180004288. '<' is scanned with quotes honored. ALPHA VAL=... is romaji
 * (sub_180001000). NUM VAL= calls sub_180004704. NUMK is the counter
 * reader sub_1800047D0 and is not this path. Any other command returns 106.
 */
int ot_apply_tag(const uint8_t *text, int *used, uint8_t *buf, int *count)
{
    int i = 1;
    int in_quote = 0;
    uint8_t body[512];
    uint8_t *cursor;
    uint8_t *cmd;
    uint8_t *keys[4];
    uint8_t *vals[4];
    int pairs = 0;
    int n;
    if (text[0] != '<') {
        return OT_ERR_OTHER;
    }
    for (;;) {
        uint8_t ch = text[i];
        if (ch == '"') {
            in_quote = !in_quote;
        } else if (ch == '>' && !in_quote) {
            break;
        } else if (ch == 0) {
            return OT_ERR_BAD_TAG;
        }
        i++;
    }
    if (i <= 1) {
        return OT_ERR_EMPTY_TAG;
    }
    *used = i + 1;
    n = i - 1;
    if (n >= (int)sizeof body) {
        n = (int)sizeof body - 1;
    }
    memcpy(body, text + 1, (size_t)n);
    body[n] = 0;
    cursor = body;
    cmd = ot_next_tok(&cursor);
    if (!cmd || cmd[0] == 0) {
        return OT_ERR_EMPTY_TAG;
    }
    while (pairs < 4) {
        uint8_t *key = ot_next_tok(&cursor);
        uint8_t *val;
        if (!key || key[0] == 0) {
            break;
        }
        val = ot_next_tok(&cursor);
        if (!val) {
            return OT_ERR_EMPTY_TAG;
        }
        keys[pairs] = key;
        vals[pairs] = val;
        pairs++;
    }
    if (strcmp((const char *)cmd, "ALPHA") == 0) {
        int k;
        for (k = 0; k < pairs; k++) {
            if (ot_key_eq(keys[k], "VAL")) {
                return ot_romaji(vals[k], buf, count);
            }
        }
        return OT_ERR_EMPTY_TAG;
    }
    if (strcmp((const char *)cmd, "NUM") == 0) {
        int k;
        for (k = 0; k < pairs; k++) {
            if (ot_key_eq(keys[k], "VAL")) {
                return ot_read_number(vals[k], buf, count);
            }
        }
        return OT_ERR_EMPTY_TAG;
    }
    if (strcmp((const char *)cmd, "NUMK") == 0) {
        int k;
        uint8_t *val = NULL;
        uint8_t *counter = NULL;
        uint8_t *mode = NULL;
        uint8_t *dot = NULL;
        for (k = 0; k < pairs; k++) {
            if (ot_key_eq(keys[k], "VAL")) {
                val = vals[k];
            } else if (ot_key_eq(keys[k], "COUNTER")) {
                counter = vals[k];
            } else if (ot_key_eq(keys[k], "MODE")) {
                mode = vals[k];
            }
        }
        if (!val || val[0] == 0) {
            return OT_ERR_EMPTY_TAG;
        }
        for (k = 0; val[k]; k++) {
            if (val[k] == '.') {
                dot = val + k;
                break;
            }
        }
        /*
         * A '.' splits the value. The integer part is NUMK with the fixed
         * counter at RVA 0x300FC (てん) and MODE "TaO". Byte 5 follows, then
         * the fraction is an ordinary NUM reading. A user COUNTER is appended
         * afterwards as dictionary phonemes. Without a dot, COUNTER and MODE
         * go to sub_1800047D0; MODE is ignored when COUNTER is absent.
         */
        if (dot) {
            int err;
            *dot = 0;
            if (val[0]) {
                err = ot_read_numk_counter(val, buf, count, "\x82\xC4\x82\xF1", "TaO");
            } else {
                err = ot_numk_slot_counter(buf, count, (const uint8_t *)"0000", 0,
                                           "\x82\xC4\x82\xF1", "TaO", 0);
            }
            if (err) {
                return err;
            }
            err = ot_append_byte(buf, count, 5);
            if (err) {
                return err;
            }
            err = ot_read_number(dot + 1, buf, count);
            if (err) {
                return err;
            }
            if (counter) {
                const uint8_t *p = counter;
                while (*p) {
                    int used = 0;
                    int code = ot_dict_lookup(p, &used);
                    if (!code || used <= 0) {
                        return OT_ERR_UNKNOWN;
                    }
                    err = ot_append_byte(buf, count, code);
                    if (err) {
                        return err;
                    }
                    p += used;
                }
            }
            return 0;
        }
        if (!counter) {
            return ot_read_numk(val, buf, count);
        }
        return ot_read_numk_counter(val, buf, count, (const char *)counter, (const char *)mode);
    }
    return OT_ERR_EMPTY_TAG;
}
