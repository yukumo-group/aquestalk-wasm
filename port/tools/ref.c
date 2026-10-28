#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *(*synth_s)(const char *, int, int *, void *);
typedef unsigned char *(*synth_w)(const unsigned short *, int, int *, void *);
typedef void (*free_fn)(unsigned char *);

static void *readfile(const char *path, long *sz) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); exit(1); }
    fseek(f, 0, SEEK_END); *sz = ftell(f); fseek(f, 0, SEEK_SET);
    void *p = calloc(1, *sz + 2);
    if (fread(p, 1, *sz, f) != (size_t)*sz) { fprintf(stderr, "short read\n"); exit(1); }
    fclose(f);
    return p;
}

int main(int argc, char **argv) {
    if (argc < 6) { fprintf(stderr, "usage: %s lib enc speed in out [phont]\n", argv[0]); return 2; }
    void *h = dlopen(argv[1], RTLD_NOW);
    if (!h) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 1; }
    const char *enc = argv[2];
    int speed = atoi(argv[3]);
    long n; char *text = readfile(argv[4], &n);
    while (n && (text[n-1] == '\n' || text[n-1] == '\r')) text[--n] = 0;
    void *phont = NULL;
    if (argc >= 7) { long pz; phont = readfile(argv[6], &pz); }

    int size = 0;
    unsigned char *wav = NULL;
    if (!strcmp(enc, "utf16")) {
        synth_w f = (synth_w)dlsym(h, "AquesTalk2_Synthe_Utf16");
        unsigned short *w = malloc(n + 2);
        memcpy(w, text, n); w[n/2] = 0;
        wav = f(w, speed, &size, phont);
    } else {
        const char *name = "AquesTalk2_Synthe";
        if (!strcmp(enc, "euc"))  name = "AquesTalk2_Synthe_Euc";
        if (!strcmp(enc, "utf8")) name = "AquesTalk2_Synthe_Utf8";
        if (!strcmp(enc, "roman"))name = "AquesTalk2_Synthe_Roman";
        synth_s f = (synth_s)dlsym(h, name);
        if (!f) { fprintf(stderr, "dlsym %s\n", name); return 1; }
        wav = f(text, speed, &size, phont);
    }
    if (!wav) { printf("ERR %d\n", size); return 3; }
    FILE *of = fopen(argv[5], "wb");
    fwrite(wav, 1, size, of);
    fclose(of);
    printf("OK %d\n", size);
    ((free_fn)dlsym(h, "AquesTalk2_FreeWave"))(wav);
    return 0;
}
