/*
 * NUM readings. Digit tables are the three DLL byte strings; '.' inserts 1a 9f 05.
 */

#include "ot_internal.h"
#include "ot_text_int.h"

#include <stdint.h>
#include <string.h>

int ot_append_span(uint8_t *buf, int *count, const uint8_t *s, int maxn)
{
    int i = 0;
    while (i < maxn && s[i]) {
        int err = ot_append_byte(buf, count, s[i]);
        if (err) {
            return err;
        }
        i++;
    }
    return 0;
}

/* byte_18002EEC8, byte_18002DFF8, byte_18002E020, byte_18002EF54. */
static const char *const ot_num_a[10] = {
    "\x3e\x30", "\x0b\xbf", "\x1f\xa1", "\x14\x9f", "\x52\x9f",
    "\xc8\xa1", "\x30\xb4", "\x1e\x1e", "\x23\xbf", "\x54\xa1"
};
static const char *const ot_num_b[10] = {
    "\x3e\x01\x30", "\x0b\x01\xbf", "\x1f\x01\xa1", "\x14\x01\x9f", "\x52\x01\x9f",
    "\xc8\x01\xa1", "\x30\x01\xb4", "\x1e\x01\x1e", "\x23\x01\xbf", "\x54\x01\xa1"
};
static const char *const ot_num_c[10] = {
    "\x3e\x01\x30", "\x0b\xbf\x01", "\x1f\x01", "\x14\x01\x9f", "\x52\x01\x9f",
    "\xc8\x01", "\x30\xb4\x01", "\x1e\x01\x1e", "\x23\xbf\x01", "\x54\x01\xa1"
};
static const char ot_num_dot[] = "\x1a\x9f\x05";

int ot_append_cstr(uint8_t *buf, int *count, const char *s)
{
    while (*s) {
        int err = ot_append_byte(buf, count, (uint8_t)*s++);
        if (err) {
            return err;
        }
    }
    return 0;
}

/* sub_180004B24. n is 1, 2, or 3 digits; sep is a phoneme byte or 0. */
static int ot_emit_digits(uint8_t *buf, int *count, const uint8_t *s, int n, int sep)
{
    int err = 0;
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        err = ot_append_cstr(buf, count, ot_num_c[s[0] - '0']);
    } else if (n == 2) {
        err = ot_append_cstr(buf, count, ot_num_a[s[0] - '0']);
        if (!err) {
            err = ot_append_cstr(buf, count, ot_num_b[s[1] - '0']);
        }
    } else {
        err = ot_append_cstr(buf, count, ot_num_a[s[0] - '0']);
        if (!err) {
            err = ot_append_cstr(buf, count, ot_num_b[s[1] - '0']);
        }
        if (!err) {
            err = ot_append_cstr(buf, count, ot_num_a[s[2] - '0']);
        }
    }
    if (err) {
        return err;
    }
    if (sep) {
        return ot_append_byte(buf, count, sep);
    }
    return 0;
}

/* sub_1800049F8. Groups from the left. Separator 4, then 7, while length >= 6. */
static int ot_group_digits(uint8_t *buf, int *count, const uint8_t *s)
{
    int n = 0;
    int guard = 0;
    while (s[n]) {
        if ((uint8_t)(s[n] - '0') > 9) {
            return OT_ERR_NONDIGIT;
        }
        n++;
    }
    while (n >= 4) {
        int err;
        if (n == 4) {
            err = ot_emit_digits(buf, count, s, 2, 4);
            if (err) {
                return err;
            }
            return ot_emit_digits(buf, count, s + 2, 2, 0);
        }
        if (n == 5) {
            err = ot_emit_digits(buf, count, s, 2, 4);
            if (err) {
                return err;
            }
            return ot_emit_digits(buf, count, s + 2, 3, 0);
        }
        err = ot_emit_digits(buf, count, s, 2, 4);
        if (err) {
            return err;
        }
        err = ot_emit_digits(buf, count, s + 2, 2, 7);
        if (err) {
            return err;
        }
        s += 4;
        n -= 4;
        if (++guard >= 20) {
            return OT_ERR_OTHER;
        }
    }
    return ot_emit_digits(buf, count, s, n, 0);
}

/*
 * sub_180004704. '.' appends byte_18002EF54 between the parts. '-' appends
 * pause byte 7. Each part is grouped by sub_1800049F8.
 */
int ot_read_number(uint8_t *text, uint8_t *buf, int *count)
{
    uint8_t *start;
    if (!text) {
        return OT_ERR_OTHER;
    }
    if (!*text) {
        return 0;
    }
    start = text;
    while (*text) {
        uint8_t ch = *text;
        if (ch == '.' || ch == '-') {
            int err;
            *text = 0;
            err = ot_group_digits(buf, count, start);
            if (err) {
                return err;
            }
            if (ch == '.') {
                err = ot_append_cstr(buf, count, ot_num_dot);
            } else {
                err = ot_append_byte(buf, count, 7);
            }
            if (err) {
                return err;
            }
            start = text + 1;
            text = start;
            continue;
        }
        text++;
    }
    return ot_group_digits(buf, count, start);
}
