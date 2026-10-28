/* cli.c -- native differential-test driver for the recompiled engine.
 *
 * usage: aqtk10_test bas spd vol pit acc lmd fsc utf8|utf16|sjis < input
 * Writes the WAV bytes to stdout.  On error writes "ERR <code>\n" to stderr
 * and exits 1.
 */
#include "shim.h"
#include <stdio.h>
#include <stdlib.h>

extern unsigned char *AquesTalk_Synthe(int64_t voice, const char *koe, int *size);
extern unsigned char *AquesTalk_Synthe_Utf8(int64_t voice, const char *koe, int *size);
extern unsigned char *AquesTalk_Synthe_Utf16(int64_t voice, const unsigned short *koe, int *size);
extern void AquesTalk_FreeWave(unsigned char *wav);

typedef struct {
    int bas, spd, vol, pit, acc, lmd, fsc;
} Voice;

int main(int argc, char **argv)
{
    if (argc != 9) {
        fprintf(stderr, "usage: %s bas spd vol pit acc lmd fsc utf8|utf16|sjis\n", argv[0]);
        return 2;
    }
    Voice v;
    v.bas = atoi(argv[1]); v.spd = atoi(argv[2]); v.vol = atoi(argv[3]);
    v.pit = atoi(argv[4]); v.acc = atoi(argv[5]); v.lmd = atoi(argv[6]);
    v.fsc = atoi(argv[7]);
    const char *mode = argv[8];

    size_t cap = 1 << 20, n = 0;
    unsigned char *buf = (unsigned char *)malloc(cap);
    if (!buf) return 2;
    for (;;) {
        if (n == cap) { cap *= 2; buf = (unsigned char *)realloc(buf, cap); }
        size_t got = fread(buf + n, 1, cap - n, stdin);
        n += got;
        if (got == 0) break;
    }

    unsigned char *wav;
    int size = 0;
    if (strcmp(mode, "utf8") == 0) {
        buf = (unsigned char *)realloc(buf, n + 1);
        buf[n] = 0;
        wav = AquesTalk_Synthe_Utf8((int64_t)(intptr_t)&v, (const char *)buf, &size);
    } else if (strcmp(mode, "sjis") == 0) {
        buf = (unsigned char *)realloc(buf, n + 1);
        buf[n] = 0;
        wav = AquesTalk_Synthe((int64_t)(intptr_t)&v, (const char *)buf, &size);
    } else if (strcmp(mode, "utf16") == 0) {
        /* input is raw UTF-16LE; the host is little endian */
        buf = (unsigned char *)realloc(buf, n + 2);
        buf[n] = 0; buf[n + 1] = 0;
        wav = AquesTalk_Synthe_Utf16((int64_t)(intptr_t)&v, (const unsigned short *)buf, &size);
    } else {
        fprintf(stderr, "bad mode\n");
        return 2;
    }
    if (!wav) {
        fprintf(stderr, "ERR %d\n", size);
        return 1;
    }
    fwrite(wav, 1, (size_t)size, stdout);
    AquesTalk_FreeWave(wav);
    free(buf);
    return 0;
}
