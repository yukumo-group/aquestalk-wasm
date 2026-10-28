/*
 * Speak a UTF-8 file to an 8000 Hz 16-bit mono WAV.
 * Whitespace is dropped. Fullwidth commas, colons, semicolons, and
 * parentheses become 、 and ！ becomes 。 so the phrase splitter sees them.
 * A small vowel the dictionary does not use as part of a digraph is spoken
 * as the full-size vowel. Any other code the table does not contain is skipped.
 */
#include "Open_Talk.h"
#include "ot_data.h"
#include "ot_internal.h"
#include "ot_text_int.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int utf8_next(const uint8_t *s, const uint8_t *end, uint32_t *cp, int *n)
{
    if (s >= end) {
        return 0;
    }
    if (s[0] < 0x80) {
        *cp = s[0];
        *n = 1;
        return 1;
    }
    if ((s[0] & 0xE0) == 0xC0 && s + 2 <= end) {
        *cp = ((uint32_t)(s[0] & 0x1F) << 6) | (s[1] & 0x3F);
        *n = 2;
        return 1;
    }
    if ((s[0] & 0xF0) == 0xE0 && s + 3 <= end) {
        *cp = ((uint32_t)(s[0] & 0x0F) << 12) | ((uint32_t)(s[1] & 0x3F) << 6) | (s[2] & 0x3F);
        *n = 3;
        return 1;
    }
    if ((s[0] & 0xF8) == 0xF0 && s + 4 <= end) {
        *cp = ((uint32_t)(s[0] & 0x07) << 18) | ((uint32_t)(s[1] & 0x3F) << 12) |
              ((uint32_t)(s[2] & 0x3F) << 6) | (s[3] & 0x3F);
        *n = 4;
        return 1;
    }
    return -1;
}

static void utf8_of(uint32_t cp, uint8_t out[3])
{
    out[0] = (uint8_t)(0xE0 | (cp >> 12));
    out[1] = (uint8_t)(0x80 | ((cp >> 6) & 0x3F));
    out[2] = (uint8_t)(0x80 | (cp & 0x3F));
}

static int sjis_of(uint32_t cp, uint8_t *dst)
{
    uint8_t u[3];
    int i;
    if (cp < 0x80) {
        return 0;
    }
    utf8_of(cp, u);
    for (i = 0; i < OT_UTF_COUNT; i++) {
        const uint8_t *rec = ot_utf_map + i * 10;
        if (u[0] == rec[4] && u[1] == rec[5] && u[2] == rec[6]) {
            dst[0] = rec[0];
            dst[1] = rec[1];
            return rec[1] ? 2 : 1;
        }
    }
    return 0;
}

static int is_space(uint32_t cp)
{
    return cp == ' ' || cp == '\t' || cp == '\n' || cp == '\r' || cp == 0x3000;
}

static uint32_t fold_punct(uint32_t cp)
{
    switch (cp) {
    case 0xFF0C:
    case 0xFF1B:
    case 0xFF1A:
    case '(':
    case ')':
    case 0xFF08:
    case 0xFF09:
        return 0x3001;
    case 0xFF01:
        return 0x3002;
    default:
        return cp;
    }
}

static int promote_small(uint8_t *sj, int i)
{
    if (sj[i] == 0x83 && (sj[i + 1] == 0x40 || sj[i + 1] == 0x42 || sj[i + 1] == 0x44 ||
                          sj[i + 1] == 0x46 || sj[i + 1] == 0x48)) {
        sj[i + 1] = (uint8_t)(sj[i + 1] + 1);
        return 1;
    }
    return 0;
}

static int prepare(const uint8_t *src, size_t n, uint8_t **out, int *skipped)
{
    const uint8_t *p = src;
    const uint8_t *end = src + n;
    uint8_t *sj;
    size_t cap;
    size_t used = 0;
    int i;
    *skipped = 0;
    cap = n + 8;
    sj = (uint8_t *)malloc(cap);
    if (!sj) {
        return 1;
    }
    while (p < end) {
        uint32_t cp = 0;
        int len = 0;
        int got = utf8_next(p, end, &cp, &len);
        uint8_t piece[2];
        int nb;
        if (got <= 0) {
            free(sj);
            return 1;
        }
        p += len;
        if (is_space(cp)) {
            continue;
        }
        cp = fold_punct(cp);
        nb = sjis_of(cp, piece);
        if (nb <= 0) {
            (*skipped)++;
            continue;
        }
        if (used + (size_t)nb + 1 > cap) {
            free(sj);
            return 1;
        }
        memcpy(sj + used, piece, (size_t)nb);
        used += (size_t)nb;
    }
    sj[used] = 0;
    i = 0;
    while (sj[i] >= 0x20) {
        int matched = 0;
        int code = ot_dict_lookup(sj + i, &matched);
        if (!code || matched <= 0) {
            if (promote_small(sj, i)) {
                code = ot_dict_lookup(sj + i, &matched);
            }
            if (!code || matched <= 0) {
                free(sj);
                return 2;
            }
        }
        i += matched;
    }
    *out = sj;
    return 0;
}

static int write_all(const char *path, const unsigned char *data, int n)
{
    FILE *f = fopen(path, "wb");
    size_t off = 0;
    if (!f) {
        return 1;
    }
    while (off < (size_t)n) {
        size_t chunk = (size_t)n - off;
        size_t got;
        if (chunk > 32768u) {
            chunk = 32768u;
        }
        got = fwrite(data + off, 1, chunk, f);
        if (got != chunk) {
            fclose(f);
            return 1;
        }
        off += got;
    }
    return fclose(f) != 0;
}

int main(int argc, char **argv)
{
    const char *in_path;
    const char *out_path;
    const char *voice = NULL;
    FILE *f;
    uint8_t *src;
    uint8_t *sjis = NULL;
    unsigned char *wav;
    long sz;
    int skipped = 0;
    int prep;
    int size = 0;
    size_t nread;
    if (argc != 3 && argc != 4) {
        fprintf(stderr, "usage: ot_say input.txt output.wav [voice]\n");
        return 1;
    }
    in_path = argv[1];
    out_path = argv[2];
    if (argc == 4) {
        voice = argv[3];
    }
    f = fopen(in_path, "rb");
    if (!f) {
        fprintf(stderr, "cannot read %s\n", in_path);
        return 1;
    }
    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f);
        return 1;
    }
    sz = ftell(f);
    if (sz < 0) {
        fclose(f);
        return 1;
    }
    if (fseek(f, 0, SEEK_SET) != 0) {
        fclose(f);
        return 1;
    }
    src = (uint8_t *)malloc((size_t)sz + 1);
    if (!src) {
        fclose(f);
        return 1;
    }
    nread = fread(src, 1, (size_t)sz, f);
    fclose(f);
    if (nread != (size_t)sz) {
        free(src);
        return 1;
    }
    src[sz] = 0;
    prep = prepare(src, (size_t)sz, &sjis, &skipped);
    free(src);
    if (prep) {
        fprintf(stderr, "prepare failed %d\n", prep);
        return 1;
    }
    if (voice && Open_Talk_SelectVoice(voice) != 0) {
        fprintf(stderr, "unknown voice %s\n", voice);
        free(sjis);
        return 1;
    }
    wav = Open_Talk_Synthe((const char *)sjis, 100, &size);
    free(sjis);
    if (!wav || size < 44) {
        fprintf(stderr, "synth failed code %d\n", size);
        Open_Talk_FreeWave(wav);
        return 1;
    }
    if (write_all(out_path, wav, size)) {
        fprintf(stderr, "write failed\n");
        Open_Talk_FreeWave(wav);
        return 1;
    }
    printf("wrote %s  %d bytes  %d samples  %.1f s  skipped %d\n", out_path, size,
           (size - 44) / 2, (double)((size - 44) / 2) / 8000.0, skipped);
    Open_Talk_FreeWave(wav);
    return 0;
}
