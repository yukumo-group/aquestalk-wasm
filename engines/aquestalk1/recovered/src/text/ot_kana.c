/*
 * Dictionary scan, youon and vowel rewrite, then the phrase parser.
 */

#include "ot_internal.h"
#include "ot_text_int.h"

#include "ot_data.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Grown by ot_append_byte. Detached and returned to the caller at the end of a parse. */
static uint8_t *g_data;
static int g_cap;

uint8_t *ot_ph(void)
{
    return g_data;
}

static int ot_ph_grow(int need)
{
    int ncap;
    uint8_t *n;
    if (need <= g_cap) {
        return 0;
    }
    ncap = g_cap > 0 ? g_cap : 256;
    while (ncap < need) {
        if (ncap > 0x3FFFFFFF) {
            return OT_ERR_NOMEM;
        }
        ncap *= 2;
    }
    n = (uint8_t *)realloc(g_data, (size_t)ncap);
    if (!n) {
        return OT_ERR_NOMEM;
    }
    g_data = n;
    g_cap = ncap;
    return 0;
}

static uint8_t *ot_ph_detach(void)
{
    uint8_t *p = g_data;
    g_data = NULL;
    g_cap = 0;
    return p;
}

int ot_dict_lookup(const uint8_t *text, int *matched)
{
    /* The image walks the table from the last entry backward. */
    for (int i = ot_dict_count - 1; i >= 0; i--) {
        const uint8_t *pat = (const uint8_t *)ot_dict[i].text;
        int len = ot_dict[i].length;
        int n = 0;
        int diff = 0;
        if (len <= 0) {
            break;
        }
        while (n < len) {
            diff = (int)text[n] - (int)pat[n];
            if (diff || text[n] == 0 || pat[n] == 0) {
                break;
            }
            n++;
        }
        if (diff == 0) {
            *matched = len;
            return (int)ot_dict[i].code;
        }
    }
    return 0;
}

int ot_append_byte(uint8_t *buf, int *count, int value)
{
    int err;
    (void)buf;
    err = ot_ph_grow(*count + 1);
    if (err) {
        return err;
    }
    g_data[(*count)++] = (uint8_t)value;
    return 0;
}

static uint8_t ot_map_vowel_a(uint8_t code)
{
    switch (code) {
    case 0xBB: return (uint8_t)-86;
    case 0xB3: return (uint8_t)-94;
    case 0xB4: return (uint8_t)-93;
    case 0xB5: return (uint8_t)-92;
    case 0xB6: return (uint8_t)-91;
    case 0xB7: return (uint8_t)-90;
    case 0xB8: return (uint8_t)-89;
    case 0xB9: return (uint8_t)-88;
    case 0xBA: return (uint8_t)-87;
    case 0xBC: return (uint8_t)-85;
    case 0xBD: return (uint8_t)-84;
    case 0xBE: return (uint8_t)-83;
    case 0xBF: return (uint8_t)-82;
    case 0xC0: return (uint8_t)-81;
    case 0xC1: return (uint8_t)-80;
    case 0xC2: return (uint8_t)-79;
    case 195: return (uint8_t)-78;
    default: return code;
    }
}

static uint8_t ot_map_vowel_b(uint8_t code)
{
    switch (code) {
    case 0xBB: return 75;
    case 0xB3: return 16;
    case 0xB4: return 17;
    case 0xB5: return 21;
    case 0xB6: return 22;
    case 0xB7: return 28;
    case 0xB8: return 29;
    case 0xB9: return 36;
    case 0xBA: return (uint8_t)-111;
    case 0xBC: return 76;
    case 0xBD: return 87;
    case 0xBE: return 89;
    case 0xBF: return 92;
    case 0xC0: return 94;
    case 0xC1: return (uint8_t)-116;
    case 0xC2: return (uint8_t)-114;
    case 195: return (uint8_t)-109;
    default: return code;
    }
}

static void ot_rewrite_yoon(uint8_t *buf, int count)
{
    uint8_t prev = 8;
    for (int i = 0; i < count; i++) {
        uint8_t cur = buf[i];
        /* Bytes 196..204 are the small-tsu / youon family. */
        if ((uint8_t)(cur + 60) <= 8) {
            static const uint8_t k_plain[9] = {49, 50, 51, 52, 53, 113, 114, 115, 116};
            static const uint8_t k_after_prosody[9] = {54, 55, 56, 57, 58, 117, 118, 119, 120};
            const uint8_t *map = ((uint8_t)(prev - 2) > 7) ? k_plain : k_after_prosody;
            cur = map[cur - 196];
            buf[i] = cur;
        }
        prev = cur;
    }
}

static void ot_apply_eval_limit(uint8_t *buf, int count)
{
    /* Development mark 22614 (0x5856) is what removes the evaluation blanking. */
    if (g_dev_mark == 22614) {
        return;
    }
    for (int i = 0; i < count; i++) {
        uint8_t cur = buf[i];
        if ((uint8_t)(cur - 30) <= 4 || (cur >= 0x27 && cur <= 0x2B)) {
            buf[i] = 0x20;
        }
    }
}

/*
 * dword_18001B8D0, one dword per phoneme at stride 24. Nonzero selects
 * ot_map_vowel_a (sub_1800018C0); zero selects ot_map_vowel_b (sub_18000195C).
 * Dumped from the loaded image. The compare at Open_Talk+0x41C4 is against ebp,
 * and the same ebp is the zero phoneme (mov cl, bpl) and the zeroed counters.
 */
static const uint8_t ot_vowel_use_a[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

/*
 * sub_180003F3C vowel pass, Open_Talk+0x40F6. Bytes 179..195 are rewritten.
 * Map B when (prev+94) <= 16, when the next byte is 6 or 7, when the next
 * byte is 8 or 9 and either counter is zero, or when the dword above is zero.
 * The scan skips bytes <= 9. prev becomes the mapped byte. Byte 1 copies the
 * run length into the second counter and does not change prev.
 */
static void ot_rewrite_vowels(uint8_t *buf, int count)
{
    uint8_t prev = 8;
    int run = 0;
    int saved = 0;
    int i;
    for (i = 0; i < count; i++) {
        uint8_t cur = buf[i];
        if (cur == 1) {
            saved = run;
            continue;
        }
        if ((uint8_t)(cur - 2) <= 7) {
            run = 0;
            saved = 0;
            prev = cur;
            continue;
        }
        if ((uint8_t)(cur + 77) > 0x10) {
            run++;
            prev = cur;
            continue;
        }
        {
            uint8_t next = (i + 1 < count) ? buf[i + 1] : 0;
            int use_b;
            if ((uint8_t)(prev + 94) <= 0x10 || (uint8_t)(next - 6) <= 1) {
                use_b = 1;
            } else if ((uint8_t)(next - 8) <= 1) {
                use_b = (run == 0 || saved == 0);
            } else {
                int k = i + 1;
                uint8_t key = next;
                while (key != 0 && key <= 9) {
                    k++;
                    key = (k < count) ? buf[k] : 0;
                }
                use_b = !ot_vowel_use_a[key];
            }
            buf[i] = use_b ? ot_map_vowel_b(cur) : ot_map_vowel_a(cur);
            run++;
            prev = buf[i];
        }
    }
}

static int ot_parse_fail(uint8_t **out, int err)
{
    *out = ot_ph_detach();
    return err;
}

int ot_parse_kana(const uint8_t *text, uint8_t **out, int *count)
{
    *count = 0;
    *out = NULL;
    free(g_data);
    g_data = NULL;
    g_cap = 0;
    if (ot_ph_grow(1)) {
        return OT_ERR_NOMEM;
    }
    g_data[0] = 0;
    while (*text >= 0x20) {
        int used = 0;
        int err;
        if (*text == '<') {
            err = ot_apply_tag(text, &used, g_data, count);
            if (err) {
                return ot_parse_fail(out, err);
            }
            text += used;
            continue;
        }
        {
            int code = ot_dict_lookup(text, &used);
            if (!code || used <= 0) {
                return ot_parse_fail(out, OT_ERR_UNKNOWN);
            }
            err = ot_append_byte(g_data, count, code);
            if (err) {
                return ot_parse_fail(out, err);
            }
            text += used;
        }
    }
    ot_rewrite_yoon(ot_ph(), *count);
    ot_rewrite_vowels(ot_ph(), *count);
    ot_apply_eval_limit(ot_ph(), *count);
    *out = ot_ph_detach();
    return 0;
}
