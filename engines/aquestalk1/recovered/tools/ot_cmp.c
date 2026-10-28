/*
 * Compare reconstructed PCM with Open_Talk.dll for the same utterance.
 * The DLL is loaded read-only from lib64. This file is a recovery harness.
 */
#include "Open_Talk.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef unsigned char *(__stdcall *SynthFn)(const char *, int, int *);
typedef void(__stdcall *FreeFn)(unsigned char *);

static int compare_one(SynthFn dll_synth, FreeFn dll_free, const char *label, const char *text, int speed)
{
    int ours_size = 0;
    int dll_size = 0;
    unsigned char *ours;
    unsigned char *dll;
    int i;
    int mismatch = -1;
    const int16_t *a;
    const int16_t *b;

    ours = Open_Talk_Synthe_Utf8(text, speed, &ours_size);
    dll = dll_synth(text, speed, &dll_size);
    printf("%s ours %d dll %d\n", label, ours_size, dll_size);
    if (!ours || !dll || ours_size < 44 || dll_size < 44) {
        printf("  missing wav\n");
        Open_Talk_FreeWave(ours);
        if (dll && dll_free) {
            dll_free(dll);
        }
        return 1;
    }
    a = (const int16_t *)(ours + 44);
    b = (const int16_t *)(dll + 44);
    if ((ours_size - 44) / 2 != (dll_size - 44) / 2) {
        printf("  sample count %d vs %d\n", (ours_size - 44) / 2, (dll_size - 44) / 2);
    }
    {
        int n = (ours_size - 44) / 2;
        int m = (dll_size - 44) / 2;
        int lim = n < m ? n : m;
        for (i = 0; i < lim; i++) {
            if (a[i] != b[i]) {
                mismatch = i;
                break;
            }
        }
        if (mismatch < 0 && n != m) {
            mismatch = lim;
        }
        if (mismatch < 0) {
            printf("  identical %d samples\n", n);
        } else if (mismatch < lim) {
            int s;
            printf("  first mismatch %d recovered %d dll %d\n", mismatch, a[mismatch], b[mismatch]);
            for (s = mismatch > 4 ? mismatch - 4 : 0; s < lim && s < mismatch + 6; s++) {
                printf("  [%d] rec %d dll %d\n", s, a[s], b[s]);
            }
        } else {
            printf("  prefixes match, lengths differ at %d\n", mismatch);
        }
    }
    Open_Talk_FreeWave(ours);
    if (dll_free) {
        dll_free(dll);
    }
    return mismatch >= 0;
}

/*
 * Full int16 compare for a free sentence. A null pointer means *pSize is an
 * error code. Same length with a later first difference is PCM drift. A
 * different length or an error is an earlier split (tag, phonemes, or tokens).
 */
static void report_sentence(SynthFn dll_synth, FreeFn dll_free, int index, const char *text)
{
    int ours_size = 0;
    int dll_size = 0;
    unsigned char *ours = Open_Talk_Synthe_Utf8(text, 100, &ours_size);
    unsigned char *dll = dll_synth(text, 100, &dll_size);
    int ours_n = (ours && ours_size >= 44) ? (ours_size - 44) / 2 : -1;
    int dll_n = (dll && dll_size >= 44) ? (dll_size - 44) / 2 : -1;
    printf("S%02d ours_samples %d dll_samples %d", index, ours_n, dll_n);
    if (ours_n < 0 || dll_n < 0) {
        printf(" ours_code %d dll_code %d earlier error\n", ours_size, dll_size);
    } else if (ours_n != dll_n) {
        int lim = ours_n < dll_n ? ours_n : dll_n;
        const int16_t *a = (const int16_t *)(ours + 44);
        const int16_t *b = (const int16_t *)(dll + 44);
        int i;
        int mismatch = lim;
        for (i = 0; i < lim; i++) {
            if (a[i] != b[i]) {
                mismatch = i;
                break;
            }
        }
        if (mismatch < lim) {
            printf(" first %d recovered %d dll %d earlier different-length\n", mismatch, a[mismatch], b[mismatch]);
        } else {
            printf(" first %d prefixes-match earlier different-length\n", mismatch);
        }
    } else {
        const int16_t *a = (const int16_t *)(ours + 44);
        const int16_t *b = (const int16_t *)(dll + 44);
        int i;
        int mismatch = -1;
        for (i = 0; i < ours_n; i++) {
            if (a[i] != b[i]) {
                mismatch = i;
                break;
            }
        }
        if (mismatch < 0) {
            printf(" identical\n");
        } else if (mismatch == 0) {
            printf(" first 0 recovered %d dll %d earlier pcm-from-start\n", a[0], b[0]);
        } else {
            printf(" first %d recovered %d dll %d later pcm-drift\n", mismatch, a[mismatch], b[mismatch]);
        }
    }
    Open_Talk_FreeWave(ours);
    if (dll && dll_free) {
        dll_free(dll);
    }
}

int main(void)
{
    HMODULE dll = LoadLibraryA("lib64\\Open_Talk.dll");
    SynthFn synth;
    FreeFn free_wave;
    void *sym;
    void *fr;
    int bad = 0;
    if (!dll) {
        printf("load failed %lu\n", GetLastError());
        return 1;
    }
    sym = (void *)GetProcAddress(dll, "Open_Talk_Synthe_Utf8");
    fr = (void *)GetProcAddress(dll, "Open_Talk_FreeWave");
    memcpy(&synth, &sym, sizeof synth);
    memcpy(&free_wave, &fr, sizeof free_wave);
    bad += compare_one(synth, free_wave, "a", "\xE3\x81\x82", 100);
    bad += compare_one(synth, free_wave, "alpha", "<ALPHA VAL=a>", 100);
    bad += compare_one(synth, free_wave, "num2", "<NUM VAL=2>", 100);
    bad += compare_one(synth, free_wave, "alpha5", "<ALPHA VAL=5>", 100);
    bad += compare_one(synth, free_wave, "numk1", "<NUMK VAL=1>", 100);
    bad += compare_one(synth, free_wave, "numk10", "<NUMK VAL=10>", 100);
    bad += compare_one(synth, free_wave, "pause", "\xE3\x81\x82\xE3\x80\x81\xE3\x81\x82", 100);
    bad += compare_one(synth, free_wave, "ka", "\xE3\x81\x8B", 100);
    bad += compare_one(synth, free_wave, "numk12", "<NUMK VAL=12>", 100);
    bad += compare_one(synth, free_wave, "numk23", "<NUMK VAL=23>", 100);
    bad += compare_one(synth, free_wave, "num23", "<NUM VAL=23>", 100);
    bad += compare_one(synth, free_wave, "numk15", "<NUMK VAL=1.5>", 100);
    bad += compare_one(synth, free_wave, "numk1234", "<NUMK VAL=12.34>", 100);
    bad += compare_one(synth, free_wave, "numknin", "<NUMK VAL=1 COUNTER=\xe3\x81\xab\xe3\x82\x93>", 100);
    bad += compare_one(synth, free_wave, "numkko", "<NUMK VAL=3 COUNTER=\xe3\x81\x93>", 100);
    bad += compare_one(synth, free_wave, "numkmode", "<NUMK VAL=3 COUNTER=\xe3\x81\x93 MODE=TaO>", 100);
    if (bad) {
        return 1;
    }
    {
        static const char *const sentences[] = {
            "\xe3\x81\xa7\xe3\x82\x93\xe3\x82\x8f\xe3\x81\xb0'\xe3\x82\x93\xe3\x81\x94\xe3\x83\xbc\xe3\x82\x8f\xe3\x80\x81<NUM VAL=01-2345-6789>\xe3\x81\xa7\xe3\x81\x99\xe3\x80\x82",
            "\xe3\x81\x95\xe3\x83\xbc\xe3\x81\xb0\xe3\x83\xbc;<NUM VAL=3512>\xe3\x81\xae/\xe3\x81\xaf\xe3\x83\xbc\xe3\x81\xa9\xe3\x81\xa7\xe3\x81\x83'_\xe3\x82\xb9_\xe3\x82\xaf\xe3\x81\xab\xe3\x80\x81\xe3\x81\x88'\xe3\x82\x89\xe3\x83\xbc+\xe3\x81\xaf\xe3\x81\xa3\xe3\x81\x9b\xe3\x83\xbc\xe3\x80\x82",
            "\xe3\x81\x92\xe3\x81\xa4\xe3\x82\x88'\xe3\x83\xbc\xe3\x81\xae/<NUMK VAL=21 COUNTER=\xe3\x81\x98>\xe3\x81\x8b\xe3\x82\x89\xe3\x80\x81<NUMK VAL=8 COUNTER=\xe3\x81\xa1\xe3\x82\x83'\xe3\x82\x93\xe3\x81\xad\xe3\x82\x8b>\xe3\x81\xa7/\xe3\x82\x88\xe3\x82\x84\xe3\x81\x8f+\xe3\x81\x97\xe3\x81\xbe'\xe3\x81\x97\xe3\x81\x9f\xe3\x80\x82",
            "\xe3\x82\x8a\xe3\x82\x87'\xe3\x83\xbc\xe3\x81\x8d\xe3\x82\x93\xe3\x82\x8f;<NUMK VAL=550 COUNTER=\xe3\x81\x88\xe3\x82\x93>\xe3\x81\xa7\xe3\x81\x99\xe3\x80\x82",
            "\xe3\x81\x99\xe3\x81\xbf\xe3\x81\xbe\xe3\x81\x9b'\xe3\x82\x93\xe3\x80\x81<NUMK VAL=10 COUNTER=\xe3\x81\xb5\xe3\x82\x93>+\xe3\x81\x8a\xe3\x81\x8f\xe3\x82\x8c\xe3\x81\xbe'\xe3\x81\x99\xe3\x80\x82",
            "<NUMK VAL=20 COUNTER=\xe3\x81\xb5\xe3\x82\x93>\xe3\x81\xab\xe3\x80\x81\xe3\x81\x88'\xe3\x81\x8d\xe3\x81\xa7/\xe3\x81\xbe'\xe3\x81\xa3\xe3\x81\xa6\xe3\x81\xbe\xe3\x81\x99\xe3\x80\x82",
            "\xe3\x81\x82\xe3\x81\x99\xe3\x81\xae\xe3\x81\xa6'\xe3\x82\x93\xe3\x81\x8d\xe3\x80\x81\xe3\x81\xa8\xe3\x83\xbc\xe3\x81\x8d\xe3\x82\x87\xe3\x83\xbc\xe3\x80\x81\xe3\x81\xaf\xe3\x82\x8c'\xe3\x81\xae\xe3\x81\xa1+\xe3\x81\x8f\xe3\x82\x82\xe3\x82\x8a\xe3\x80\x81\xe3\x81\x95\xe3\x81\x84\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x8d'\xe3\x81\x8a\xe3\x82\x93\xe3\x80\x81<NUMK VAL=25 COUNTER=\xe3\x81\xa9>\xe3\x80\x82",
            "<NUMK VAL=100 COUNTER=\xe3\x82\x81'\xe3\x83\xbc\xe3\x81\xa8\xe3\x82\x8b>\xe3\x81\x95\xe3\x81\x8d\xe3\x80\x81\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x88\xe3\x82\x93\xe3\x81\x84\xe3\x82\x8a\xe3\x81\x90\xe3\x81\xa1\xe3\x81\xae/\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x95\xe3\x81\xa6\xe3\x82\x93\xe3\x82\x92+\xe3\x81\xb2\xe3\x81\xa0\xe3\x82\x8a\xe3\x81\xa7'\xe3\x81\x99\xe3\x80\x82",
            "\xe3\x81\x93\xe3\x81\xae\xe3\x81\x95\xe3\x81\x8d;<NUMK VAL=3 COUNTER=\xe3\x81\x8d\xe3\x82\x8d>/\xe3\x81\x98\xe3\x82\x85\xe3\x83\xbc\xe3\x81\x9f\xe3\x81\x84\xe3\x81\xa1\xe3\x82\x85\xe3\x83\xbc\xe3\x80\x82\xe3\x81\xa4\xe3\x83\xbc\xe3\x81\x8b\xe3\x81\x98'\xe3\x81\x8b\xe3\x82\x93;<NUMK VAL=10 COUNTER=\xe3\x81\xb5\xe3\x82\x93>\xe3\x80\x81",
            "\xe3\x82\x88\xe3\x82\x8d\xe3\x81\x97'\xe3\x81\x84\xe3\x81\xa7\xe3\x81\x99\xe3\x81\x8b\xef\xbc\x9f",
            "\xe3\x81\x93\xe3\x82\x8c\xe3\x81\xa7\xe3\x81\x84'\xe3\x81\x84\xef\xbc\x9f",
            "\xe3\x81\xb0\xe3\x81\xa3\xe3\x81\xa6\xe3\x82\x8a\xe3\x83\xbc\xe3\x81\xae/\xe3\x81\x98\xe3\x82\x85\xe3\x83\xbc\xe3\x81\xa7\xe3\x82\x93+\xe3\x81\x8b\xe3\x82\x93\xe3\x82\x8a\xe3\x82\x87\xe3\x83\xbc\xe3\x80\x82",
            "<NUMK VAL=2006 COUNTER=\xe3\x81\xad\xe3\x82\x93>\xe3\x80\x81<NUMK VAL=1 COUNTER=\xe3\x81\x8c\xe3\x81\xa4>;<NUMK VAL=15 COUNTER=\xe3\x81\xab\xe3\x81\xa1>\xe3\x80\x82",
            "<NUMK VAL=16 COUNTER=\xe3\x81\x98>;<NUMK VAL=5 COUNTER=\xe3\x81\xb5\xe3\x82\x93>/<NUMK VAL=35 COUNTER=\xe3\x81\xb3\xe3\x82\x87\xe3\x83\xbc>\xe3\x81\xa7\xe3\x81\x99\xe3\x80\x82",
            "\xe3\x81\x9d\xe3\x82\x8c\xe3\x81\x8b\xe3\x82\x89'\xe3\x82\x8f\xe3\x80\x81\xe3\x82\x84\xe3\x81\xbe\xe3\x81\x90\xe3\x81\xa1'\xe3\x81\x91\xe3\x82\x93\xe3\x81\xa7;\xe3\x82\x84\xe3\x81\xa8\xe3\x82\x8f\xe3\x82\x8c\xe3\x81\xb0'\xe3\x82\x93\xe3\x81\xa8\xe3\x83\xbc\xe3\x81\x8a/\xe3\x81\x99\xe3\x82\x8b\xe3\x82\x88'\xe3\x83\xbc\xe3\x81\xab+\xe3\x81\xaa'\xe3\x82\x8a\xe3\x80\x81\xe3\x81\x8b'\xe3\x81\x9e\xe3\x81\x8f\xe3\x81\xae/\xe3\x82\x82\xe3\x81\xa8'\xe3\x81\xab\xe3\x82\x8f\xe3\x80\x81\xe3\x81\xbb\xe3\x81\xa8'\xe3\x82\x93\xe3\x81\xa9;\xe3\x82\x82\xe3\x81\xa9\xe3\x82\x8c'\xe3\x81\xaa\xe3\x81\x8f+\xe3\x81\xaa\xe3\x82\x8a\xe3\x81\xbe'\xe3\x81\x97\xe3\x81\x9f\xe3\x80\x82",
            "\xe3\x81\xb0\xe3\x81\x8f\xe3\x81\x8a\xe3\x82\x93\xe3\x81\x8c\xe3\x80\x81\xe3\x81\x8e\xe3\x82\x93\xe3\x81\x9b'\xe3\x81\x8b\xe3\x81\x84\xe3\x81\xae/\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x92\xe3\x82\x93\xe3\x81\xab/\xe3\x81\xb2\xe3\x82\x8d\xe3\x81\x8c\xe3\x82\x8b\xe3\x80\x82",
        };
        int s;
        printf("sentences\n");
        for (s = 0; s < 16; s++) {
            report_sentence(synth, free_wave, s + 1, sentences[s]);
        }
    }
    return 0;
}
