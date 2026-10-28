/* Dump one utterance from either engine to a WAV file.
 * usage: dump <so|-> <preset|-> <text> <out.wav>
 * "-" for so means the recovered engine; "-" for preset means builtin tables.
 */
#include "Open_Talk.h"

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *(*SynthFn)(const char *, int, int *);
typedef void (*FreeFn)(unsigned char *);

int main(int argc, char **argv)
{
    const char *so_path;
    const char *preset;
    const char *text;
    const char *out;
    int size = 0;
    unsigned char *wav;
    FILE *f;
    if (argc != 5) {
        fprintf(stderr, "usage: %s <so|-> <preset|-> <text> <out.wav>\n", argv[0]);
        return 2;
    }
    so_path = argv[1];
    preset = argv[2];
    text = argv[3];
    out = argv[4];
    if (strcmp(so_path, "-") == 0) {
        Open_Talk_SelectVoice(strcmp(preset, "-") ? preset : "");
        wav = Open_Talk_Synthe_Utf8(text, 100, &size);
    } else {
        void *h = dlopen(so_path, RTLD_NOW | RTLD_LOCAL);
        SynthFn synth;
        FreeFn freer;
        if (!h) {
            fprintf(stderr, "dlopen: %s\n", dlerror());
            return 1;
        }
        synth = (SynthFn)dlsym(h, "AquesTalk_Synthe_Utf8");
        freer = (FreeFn)dlsym(h, "AquesTalk_FreeWave");
        if (!synth) {
            fprintf(stderr, "no AquesTalk_Synthe_Utf8\n");
            return 1;
        }
        wav = synth(text, 100, &size);
        if (!wav) {
            fprintf(stderr, "synth failed code %d\n", size);
            return 1;
        }
        f = fopen(out, "wb");
        if (!f) {
            return 1;
        }
        fwrite(wav, 1, (size_t)size, f);
        fclose(f);
        if (freer) {
            freer(wav);
        }
        return 0;
    }
    if (!wav) {
        fprintf(stderr, "ours failed code %d\n", size);
        return 1;
    }
    f = fopen(out, "wb");
    if (!f) {
        return 1;
    }
    fwrite(wav, 1, (size_t)size, f);
    fclose(f);
    Open_Talk_FreeWave(wav);
    return 0;
}
