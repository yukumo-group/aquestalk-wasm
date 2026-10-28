/* Native test driver for the recompiled port.
 * usage: aqtest <enc> <speed> <in> <out> [phont]
 * enc: utf8 | sjis | euc | utf16 | roman
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *AquesTalk2_Synthe(const char *, int, int *, void *);
unsigned char *AquesTalk2_Synthe_Euc(const char *, int, int *, void *);
unsigned char *AquesTalk2_Synthe_Utf8(const char *, int, int *, void *);
unsigned char *AquesTalk2_Synthe_Utf16(const unsigned short *, int, int *, void *);
unsigned char *AquesTalk2_Synthe_Roman(const char *, int, int *, void *);
void AquesTalk2_FreeWave(unsigned char *);

static void *readfile(const char *path, long *sz)
{
    FILE *f = fopen(path, "rb");
    if (!f) {
        perror(path);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    *sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    void *p = calloc(1, (size_t)*sz + 2);
    if (fread(p, 1, (size_t)*sz, f) != (size_t)*sz) {
        fprintf(stderr, "short read\n");
        exit(1);
    }
    fclose(f);
    return p;
}

int main(int argc, char **argv)
{
    if (argc < 5) {
        fprintf(stderr, "usage: %s enc speed in out [phont]\n", argv[0]);
        return 2;
    }
    const char *enc = argv[1];
    int speed = atoi(argv[2]);
    long n;
    char *text = (char *)readfile(argv[3], &n);
    while (n && (text[n - 1] == '\n' || text[n - 1] == '\r'))
        text[--n] = 0;
    void *phont = NULL;
    if (argc >= 6) {
        long pz;
        phont = readfile(argv[5], &pz);
    }

    int size = 0;
    unsigned char *wav = NULL;
    if (!strcmp(enc, "utf16")) {
        wav = AquesTalk2_Synthe_Utf16((const unsigned short *)text, speed, &size, phont);
    } else if (!strcmp(enc, "euc")) {
        wav = AquesTalk2_Synthe_Euc(text, speed, &size, phont);
    } else if (!strcmp(enc, "sjis")) {
        wav = AquesTalk2_Synthe(text, speed, &size, phont);
    } else if (!strcmp(enc, "roman")) {
        wav = AquesTalk2_Synthe_Roman(text, speed, &size, phont);
    } else {
        wav = AquesTalk2_Synthe_Utf8(text, speed, &size, phont);
    }

    if (!wav) {
        printf("ERR %d\n", size);
        return 3;
    }
    FILE *of = fopen(argv[4], "wb");
    fwrite(wav, 1, (size_t)size, of);
    fclose(of);
    printf("OK %d\n", size);
    AquesTalk2_FreeWave(wav);
    return 0;
}
