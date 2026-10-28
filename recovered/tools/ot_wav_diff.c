/*
 * Write both WAV sides for the ten sentences that used to drift.
 * The DLL is loaded read-only from lib64. Synthesis behavior is unchanged.
 */
#include "Open_Talk.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef unsigned char *(__stdcall *SynthFn)(const char *, int, int *);
typedef void(__stdcall *FreeFn)(unsigned char *);

static int write_buf(const char *path, const unsigned char *buf, int size)
{
    FILE *f;
    size_t n;
    if (!buf || size <= 0) {
        return 1;
    }
    f = fopen(path, "wb");
    if (!f) {
        return 1;
    }
    n = fwrite(buf, 1, (size_t)size, f);
    if (fclose(f) != 0 || n != (size_t)size) {
        return 1;
    }
    return 0;
}

static void one_pair(SynthFn dll_synth, FreeFn dll_free, FILE *readme, int index, const char *text)
{
    char path_dll[64];
    char path_rec[64];
    int ours_size = 0;
    int dll_size = 0;
    unsigned char *ours;
    unsigned char *dll;
    int ours_n;
    int dll_n;
    int mismatch = -1;
    int i;
    const int16_t *a;
    const int16_t *b;
    int lim;

    sprintf(path_dll, "recovered/wav/diff/s%02d_dll.wav", index);
    sprintf(path_rec, "recovered/wav/diff/s%02d_recovered.wav", index);
    ours = Open_Talk_Synthe_Utf8(text, 100, &ours_size);
    dll = dll_synth(text, 100, &dll_size);
    ours_n = (ours && ours_size >= 44) ? (ours_size - 44) / 2 : -1;
    dll_n = (dll && dll_size >= 44) ? (dll_size - 44) / 2 : -1;
    fprintf(readme, "s%02d\n", index);
    fprintf(readme, "sentence: %s\n", text);
    if (!ours) {
        fprintf(readme, "recovered failed, code %d\n", ours_size);
    } else if (write_buf(path_rec, ours, ours_size) != 0) {
        fprintf(readme, "recovered write failed, bytes %d\n", ours_size);
    } else {
        fprintf(readme, "recovered file %s bytes %d samples %d\n", path_rec, ours_size, ours_n);
    }
    if (!dll) {
        fprintf(readme, "dll failed, code %d\n", dll_size);
    } else if (write_buf(path_dll, dll, dll_size) != 0) {
        fprintf(readme, "dll write failed, bytes %d\n", dll_size);
    } else {
        fprintf(readme, "dll file %s bytes %d samples %d\n", path_dll, dll_size, dll_n);
    }
    if (ours_n >= 0 && dll_n >= 0) {
        a = (const int16_t *)(ours + 44);
        b = (const int16_t *)(dll + 44);
        lim = ours_n < dll_n ? ours_n : dll_n;
        for (i = 0; i < lim; i++) {
            if (a[i] != b[i]) {
                mismatch = i;
                break;
            }
        }
        if (mismatch < 0 && ours_n != dll_n) {
            mismatch = lim;
            fprintf(readme, "lengths differ, common prefix %d matches\n", lim);
        } else if (mismatch < 0) {
            fprintf(readme, "identical %d samples\n", ours_n);
        } else {
            fprintf(readme, "first mismatch index %d recovered %d dll %d\n", mismatch, a[mismatch], b[mismatch]);
        }
    }
    fprintf(readme, "\n");
    printf("s%02d recovered %d dll %d mismatch %d\n", index, ours_size, dll_size, mismatch);
    Open_Talk_FreeWave(ours);
    if (dll && dll_free) {
        dll_free(dll);
    }
}

int main(void)
{
    static const struct {
        int index;
        const char *text;
    } rows[] = {
        {2, "\xe3\x81\x95\xe3\x83\xbc\xe3\x81\xb0\xe3\x83\xbc;<NUM VAL=3512>\xe3\x81\xae/\xe3\x81\xaf\xe3\x83\xbc\xe3\x81\xa9\xe3\x81\xa7\xe3\x81\x83'_\xe3\x82\xb9_\xe3\x82\xaf\xe3\x81\xab\xe3\x80\x81\xe3\x81\x88'\xe3\x82\x89\xe3\x83\xbc+\xe3\x81\xaf\xe3\x81\xa3\xe3\x81\x9b\xe3\x83\xbc\xe3\x80\x82"},
        {3, "\xe3\x81\x92\xe3\x81\xa4\xe3\x82\x88'\xe3\x83\xbc\xe3\x81\xae/<NUMK VAL=21 COUNTER=\xe3\x81\x98>\xe3\x81\x8b\xe3\x82\x89\xe3\x80\x81<NUMK VAL=8 COUNTER=\xe3\x81\xa1\xe3\x82\x83'\xe3\x82\x93\xe3\x81\xad\xe3\x82\x8b>\xe3\x81\xa7/\xe3\x82\x88\xe3\x82\x84\xe3\x81\x8f+\xe3\x81\x97\xe3\x81\xbe'\xe3\x81\x97\xe3\x81\x9f\xe3\x80\x82"},
        {5, "\xe3\x81\x99\xe3\x81\xbf\xe3\x81\xbe\xe3\x81\x9b'\xe3\x82\x93\xe3\x80\x81<NUMK VAL=10 COUNTER=\xe3\x81\xb5\xe3\x82\x93>+\xe3\x81\x8a\xe3\x81\x8f\xe3\x82\x8c\xe3\x81\xbe'\xe3\x81\x99\xe3\x80\x82"},
        {7, "\xe3\x81\x82\xe3\x81\x99\xe3\x81\xae\xe3\x81\xa6'\xe3\x82\x93\xe3\x81\x8d\xe3\x80\x81\xe3\x81\xa8\xe3\x83\xbc\xe3\x81\x8d\xe3\x82\x87\xe3\x83\xbc\xe3\x80\x81\xe3\x81\xaf\xe3\x82\x8c'\xe3\x81\xae\xe3\x81\xa1+\xe3\x81\x8f\xe3\x82\x82\xe3\x82\x8a\xe3\x80\x81\xe3\x81\x95\xe3\x81\x84\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x8d'\xe3\x81\x8a\xe3\x82\x93\xe3\x80\x81<NUMK VAL=25 COUNTER=\xe3\x81\xa9>\xe3\x80\x82"},
        {8, "<NUMK VAL=100 COUNTER=\xe3\x82\x81'\xe3\x83\xbc\xe3\x81\xa8\xe3\x82\x8b>\xe3\x81\x95\xe3\x81\x8d\xe3\x80\x81\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x88\xe3\x82\x93\xe3\x81\x84\xe3\x82\x8a\xe3\x81\x90\xe3\x81\xa1\xe3\x81\xae/\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x95\xe3\x81\xa6\xe3\x82\x93\xe3\x82\x92+\xe3\x81\xb2\xe3\x81\xa0\xe3\x82\x8a\xe3\x81\xa7'\xe3\x81\x99\xe3\x80\x82"},
        {10, "\xe3\x82\x88\xe3\x82\x8d\xe3\x81\x97'\xe3\x81\x84\xe3\x81\xa7\xe3\x81\x99\xe3\x81\x8b\xef\xbc\x9f"},
        {11, "\xe3\x81\x93\xe3\x82\x8c\xe3\x81\xa7\xe3\x81\x84'\xe3\x81\x84\xef\xbc\x9f"},
        {12, "\xe3\x81\xb0\xe3\x81\xa3\xe3\x81\xa6\xe3\x82\x8a\xe3\x83\xbc\xe3\x81\xae/\xe3\x81\x98\xe3\x82\x85\xe3\x83\xbc\xe3\x81\xa7\xe3\x82\x93+\xe3\x81\x8b\xe3\x82\x93\xe3\x82\x8a\xe3\x82\x87\xe3\x83\xbc\xe3\x80\x82"},
        {15, "\xe3\x81\x9d\xe3\x82\x8c\xe3\x81\x8b\xe3\x82\x89'\xe3\x82\x8f\xe3\x80\x81\xe3\x82\x84\xe3\x81\xbe\xe3\x81\x90\xe3\x81\xa1'\xe3\x81\x91\xe3\x82\x93\xe3\x81\xa7;\xe3\x82\x84\xe3\x81\xa8\xe3\x82\x8f\xe3\x82\x8c\xe3\x81\xb0'\xe3\x82\x93\xe3\x81\xa8\xe3\x83\xbc\xe3\x81\x8a/\xe3\x81\x99\xe3\x82\x8b\xe3\x82\x88'\xe3\x83\xbc\xe3\x81\xab+\xe3\x81\xaa'\xe3\x82\x8a\xe3\x80\x81\xe3\x81\x8b'\xe3\x81\x9e\xe3\x81\x8f\xe3\x81\xae/\xe3\x82\x82\xe3\x81\xa8'\xe3\x81\xab\xe3\x82\x8f\xe3\x80\x81\xe3\x81\xbb\xe3\x81\xa8'\xe3\x82\x93\xe3\x81\xa9;\xe3\x82\x82\xe3\x81\xa9\xe3\x82\x8c'\xe3\x81\xaa\xe3\x81\x8f+\xe3\x81\xaa\xe3\x82\x8a\xe3\x81\xbe'\xe3\x81\x97\xe3\x81\x9f\xe3\x80\x82"},
        {16, "\xe3\x81\xb0\xe3\x81\x8f\xe3\x81\x8a\xe3\x82\x93\xe3\x81\x8c\xe3\x80\x81\xe3\x81\x8e\xe3\x82\x93\xe3\x81\x9b'\xe3\x81\x8b\xe3\x81\x84\xe3\x81\xae/\xe3\x81\x93\xe3\x83\xbc\xe3\x81\x92\xe3\x82\x93\xe3\x81\xab/\xe3\x81\xb2\xe3\x82\x8d\xe3\x81\x8c\xe3\x82\x8b\xe3\x80\x82"},
    };
    HMODULE dll;
    SynthFn synth;
    FreeFn free_wave;
    void *sym;
    void *fr;
    FILE *readme;
    int i;

    dll = LoadLibraryA("lib64\\Open_Talk.dll");
    if (!dll) {
        printf("load failed %lu\n", GetLastError());
        return 1;
    }
    sym = (void *)GetProcAddress(dll, "Open_Talk_Synthe_Utf8");
    fr = (void *)GetProcAddress(dll, "Open_Talk_FreeWave");
    memcpy(&synth, &sym, sizeof synth);
    memcpy(&free_wave, &fr, sizeof free_wave);
    readme = fopen("recovered/wav/diff/README.txt", "wb");
    if (!readme) {
        printf("readme open failed\n");
        return 1;
    }
    fprintf(readme, "WAV pairs for the ten sentences that drifted before the pitch-contour fix, speed 100.\n");
    fprintf(readme, "Each file is the buffer returned by Open_Talk_Synthe_Utf8, saved as-is.\n");
    fprintf(readme, "Header size is 44 bytes. File size is 44 + samples * 2.\n");
    fprintf(readme, "Recovered output is the sources under recovered/src. DLL output is lib64/Open_Talk.dll.\n\n");
    for (i = 0; i < 10; i++) {
        one_pair(synth, free_wave, readme, rows[i].index, rows[i].text);
    }
    if (fclose(readme) != 0) {
        printf("readme close failed\n");
        return 1;
    }
    return 0;
}
