/*
 * Katakana breadth benchmark: official AquesTalk1 Linux libAquesTalk.so vs
 * the recovered engine in recovered/src.
 *
 * For each case (UTF-8 string) both synthesizers run at the same speed, and
 * the WAV buffers are compared sample by sample after the 44-byte header.
 *
 * Usage:
 *   kana_bench <libAquesTalk.so> <preset.bin|-> <cases.tsv> [speed]
 *
 * Output: one TSV line per case plus a summary line with a leading '#'.
 */
#include "Open_Talk.h"

#include <dlfcn.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *(*SynthFn)(const char *, int, int *);
typedef void (*FreeFn)(unsigned char *);

typedef struct Case {
    char *label;
    char *text;
} Case;

static char *trim(char *s)
{
    char *e;
    while (*s == ' ' || *s == '\t') {
        s++;
    }
    e = s + strlen(s);
    while (e > s && (e[-1] == '\n' || e[-1] == '\r' || e[-1] == ' ' || e[-1] == '\t')) {
        *--e = 0;
    }
    return s;
}

static int load_cases(const char *path, Case **out)
{
    FILE *f = fopen(path, "rb");
    char line[4096];
    Case *cases = NULL;
    int n = 0;
    int cap = 0;
    if (!f) {
        fprintf(stderr, "cannot open cases %s\n", path);
        return -1;
    }
    while (fgets(line, sizeof line, f)) {
        char *tab;
        char *label;
        char *text;
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r') {
            continue;
        }
        tab = strchr(line, '\t');
        if (!tab) {
            continue;
        }
        *tab = 0;
        label = trim(line);
        text = trim(tab + 1);
        if (!*text) {
            continue;
        }
        if (n == cap) {
            cap = cap ? cap * 2 : 64;
            cases = (Case *)realloc(cases, (size_t)cap * sizeof *cases);
            if (!cases) {
                fclose(f);
                return -1;
            }
        }
        cases[n].label = strdup(label);
        cases[n].text = strdup(text);
        n++;
    }
    fclose(f);
    *out = cases;
    return n;
}

typedef struct Stats {
    int ok;
    int identical;
    int same_len;
    int first_diff;
    int bad_samples;
    int max_abs;
    double rms;
    int ours_n;
    int ref_n;
} Stats;

static void compare(Stats *st, const unsigned char *ours, int osz, const unsigned char *ref, int rsz)
{
    const int16_t *a;
    const int16_t *b;
    int n;
    int m;
    int lim;
    int i;
    double acc = 0.0;

    memset(st, 0, sizeof *st);
    st->first_diff = -1;
    if (!ours || !ref || osz < 44 || rsz < 44) {
        return;
    }
    st->ok = 1;
    n = (osz - 44) / 2;
    m = (rsz - 44) / 2;
    st->ours_n = n;
    st->ref_n = m;
    st->same_len = (n == m);
    a = (const int16_t *)(const void *)(ours + 44);
    b = (const int16_t *)(const void *)(ref + 44);
    lim = n < m ? n : m;
    for (i = 0; i < lim; i++) {
        int d = (int)a[i] - (int)b[i];
        if (d != 0) {
            st->bad_samples++;
            acc += (double)d * (double)d;
            if (d < 0) {
                d = -d;
            }
            if (d > st->max_abs) {
                st->max_abs = d;
            }
            if (st->first_diff < 0) {
                st->first_diff = i;
            }
        }
    }
    if (lim > 0) {
        st->rms = sqrt(acc / (double)lim);
    }
    st->identical = (st->same_len && st->bad_samples == 0);
}

int main(int argc, char **argv)
{
    const char *so_path;
    const char *voice_name;
    const char *cases_path;
    int speed = 100;
    void *handle;
    SynthFn ref_synth;
    FreeFn ref_free;
    Case *cases = NULL;
    int ncases;
    int i;
    int identical = 0;
    int len_diff = 0;
    int pcm_diff = 0;
    int err_match = 0;
    int err_diff = 0;
    int err_side = 0;
    long long total_samples = 0;

    if (argc < 4) {
        fprintf(stderr, "usage: %s libAquesTalk.so preset.bin|- cases.tsv [speed]\n", argv[0]);
        return 2;
    }
    so_path = argv[1];
    voice_name = argv[2];
    cases_path = argv[3];
    if (argc > 4) {
        speed = atoi(argv[4]);
    }
    handle = dlopen(so_path, RTLD_NOW | RTLD_LOCAL);
    if (!handle) {
        fprintf(stderr, "dlopen %s: %s\n", so_path, dlerror());
        return 2;
    }
    ref_synth = (SynthFn)dlsym(handle, "AquesTalk_Synthe_Utf8");
    ref_free = (FreeFn)dlsym(handle, "AquesTalk_FreeWave");
    if (!ref_synth || !ref_free) {
        fprintf(stderr, "missing exports in %s\n", so_path);
        return 2;
    }
    ncases = load_cases(cases_path, &cases);
    if (ncases < 0) {
        return 2;
    }

    printf("case\tlabel\ttext\tours_bytes\tref_bytes\tours_samples\tref_samples\tverdict\t"
           "first_diff\tbad_samples\tmax_abs\trms\n");
    for (i = 0; i < ncases; i++) {
        int osz = 0;
        int rsz = 0;
        unsigned char *ours;
        unsigned char *ref;
        Stats st;
        const char *verdict;
        int oc;
        int rc;

        Open_Talk_SelectVoice((voice_name && strcmp(voice_name, "-") != 0) ? voice_name : "");
        ours = Open_Talk_Synthe_Utf8(cases[i].text, speed, &osz);
        ref = ref_synth(cases[i].text, speed, &rsz);
        oc = ours ? 0 : osz;
        rc = ref ? 0 : rsz;
        compare(&st, ours, osz, ref, rsz);
        if (!ours && !ref) {
            verdict = (oc == rc) ? "ERR_MATCH" : "ERR_DIFF";
        } else if (!ours || !ref) {
            verdict = "ERR_ONE_SIDE";
        } else if (st.identical) {
            verdict = "IDENTICAL";
        } else if (!st.same_len) {
            verdict = "LEN_DIFF";
        } else {
            verdict = "PCM_DIFF";
        }
        if (strcmp(verdict, "IDENTICAL") == 0) {
            identical++;
        } else if (strcmp(verdict, "LEN_DIFF") == 0) {
            len_diff++;
        } else if (strcmp(verdict, "PCM_DIFF") == 0) {
            pcm_diff++;
        } else if (strcmp(verdict, "ERR_MATCH") == 0) {
            err_match++;
        } else if (strcmp(verdict, "ERR_DIFF") == 0) {
            err_diff++;
        } else {
            err_side++;
        }
        total_samples += st.ref_n > 0 ? st.ref_n : 0;
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%s\t%d\t%d\t%d\t%.2f\n", i, cases[i].label,
               cases[i].text, osz, rsz, st.ours_n, st.ref_n, verdict, st.first_diff,
               st.bad_samples, st.max_abs, st.rms);
        if (!ours) {
            printf("# note case %d ours error code %d\n", i, oc);
        }
        if (!ref) {
            printf("# note case %d ref error code %d\n", i, rc);
        }
        Open_Talk_FreeWave(ours);
        if (ref) {
            ref_free(ref);
        }
    }
    printf("# summary cases=%d identical=%d len_diff=%d pcm_diff=%d err_match=%d err_diff=%d "
           "err_one_side=%d ref_samples=%lld\n",
           ncases, identical, len_diff, pcm_diff, err_match, err_diff, err_side, total_samples);
    dlclose(handle);
    return 0;
}
