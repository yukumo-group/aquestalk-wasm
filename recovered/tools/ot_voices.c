/*
 * Render the stored voice tables to 8000 Hz 16-bit mono WAV.
 * Each reachable diphone is spoken four times at pitch 203 (speed-100 scale).
 * period.wav and pulse.wav are the excitation waveforms themselves.
 */
#include "ot_speak.h"
#include "ot_internal.h"
#include "ot_synth.h"
#include "ot_data.h"
#include "ot_frame_data.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

enum { OT_VOICE_PITCH = 203, OT_VOICE_PERIOD = 256, OT_VOICE_REPEAT = 4 };

static int write_pcm(const char *path, OtPcm *pcm)
{
    FILE *f;
    size_t n;
    if (!pcm->data || pcm->used < 44) {
        return 1;
    }
    ot_write_wav_header(pcm);
    f = fopen(path, "wb");
    if (!f) {
        return 1;
    }
    n = 0;
    while (n < pcm->used) {
        size_t chunk = pcm->used - n;
        size_t got;
        if (chunk > 32768u) {
            chunk = 32768u;
        }
        got = fwrite(pcm->data + n, 1, chunk, f);
        if (got != chunk) {
            fclose(f);
            return 1;
        }
        n += got;
    }
    if (fclose(f) != 0) {
        return 1;
    }
    return 0;
}

static int append_table(OtPcm *pcm, const int16_t *src, int count, int repeats)
{
    int r;
    int i;
    for (r = 0; r < repeats; r++) {
        for (i = 0; i < count; i++) {
            int err = ot_pcm_append(pcm, src[i], 1);
            if (err) {
                return err;
            }
        }
    }
    return 0;
}

static void sym_piece(char *dst, size_t cap, uint8_t c)
{
    char tmp[8];
    const char *s;
    switch (c) {
    case '+': s = "plus"; break;
    case ';': s = "semi"; break;
    case ',': s = "comma"; break;
    case '-': s = "dash"; break;
    case '/': s = "slash"; break;
    case '?': s = "qmark"; break;
    case '\'': s = "apos"; break;
    case '.': s = "dot"; break;
    case '#': s = "hash"; break;
    case '&': s = "amp"; break;
    case '*': s = "star"; break;
    default:
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            tmp[0] = (char)c;
            tmp[1] = 0;
            s = tmp;
        } else {
            sprintf(tmp, "x%02X", c);
            s = tmp;
        }
        break;
    }
    strncat(dst, s, cap - strlen(dst) - 1);
}

static int seen_pair(const OtSymbol *sym, int index)
{
    int i;
    for (i = 0; i < index; i++) {
        if (ot_symbols[i].a == sym->a && ot_symbols[i].b == sym->b) {
            return 1;
        }
    }
    return 0;
}

static int render_pair(OtPcm *pcm, const OtSymbol *sym)
{
    OtToken tok[OT_VOICE_REPEAT + 4];
    int n = 0;
    int i;
    /*
     * Class 2 and 4 are transitions into the next diphone. Alone, class 4
     * has no following symbol and the expander rejects it. Follow them with
     * "a-" so the attack is heard into a vowel.
     */
    int into_vowel = sym->cls == 2 || sym->cls == 4;
    int repeats = into_vowel ? 1 : OT_VOICE_REPEAT;
    for (i = 0; i < repeats; i++) {
        tok[n].pitch = OT_VOICE_PITCH;
        tok[n].a = sym->a;
        tok[n].b = sym->b;
        n++;
    }
    if (into_vowel) {
        for (i = 0; i < OT_VOICE_REPEAT; i++) {
            tok[n].pitch = OT_VOICE_PITCH;
            tok[n].a = 'a';
            tok[n].b = '-';
            n++;
        }
    }
    return ot_render_tokens(tok, n, OT_VOICE_PERIOD, 0, 0, pcm, ot_voice_builtin());
}

int main(void)
{
    OtPcm pcm;
    OtPcm catalog;
    FILE *index;
    int i;
    int written = 0;
    int skipped = 0;
    int failed = 0;

    memset(&pcm, 0, sizeof pcm);
    if (append_table(&pcm, ot_period, 4096, 2) != 0) {
        fprintf(stderr, "period.wav failed\n");
        return 1;
    }
    if (write_pcm("recovered/wav/voices/period.wav", &pcm) != 0 && errno != EACCES) {
        fprintf(stderr, "period.wav failed errno %d\n", errno);
        return 1;
    }
    ot_pcm_clear(&pcm);

    memset(&pcm, 0, sizeof pcm);
    if (append_table(&pcm, ot_pulse, 0x255, 8) != 0) {
        fprintf(stderr, "pulse.wav failed\n");
        return 1;
    }
    if (write_pcm("recovered/wav/voices/pulse.wav", &pcm) != 0 && errno != EACCES) {
        fprintf(stderr, "pulse.wav failed errno %d\n", errno);
        return 1;
    }
    ot_pcm_clear(&pcm);

    index = fopen("recovered/wav/voices/README.txt", "w");
    if (!index) {
        fprintf(stderr, "README failed\n");
        return 1;
    }
    fprintf(index, "8000 Hz, 16-bit, mono.\n");
    fprintf(index, "period.wav and pulse.wav are the source BEFORE the vocal-tract filter.\n");
    fprintf(index, "period.wav is ot_period twice: the voiced excitation.\n");
    fprintf(index, "pulse.wav is ot_pulse eight times: the noise burst.\n");
    fprintf(index, "Each sample adds a scaled period value and a scaled pulse value, then the\n");
    fprintf(index, "11-tap LPC filter (from ot_formant) shapes that sum. diphones/ and\n");
    fprintf(index, "catalog.wav are that filtered result.\n");
    fprintf(index, "diphones/ are the symbol pairs the synthesizer can look up, at pitch 203.\n");
    fprintf(index, "Steady units (classes 1, 3, 5) are repeated four times. Classes 2 and 4 are\n");
    fprintf(index, "attacks into the following phone, so those files continue into the vowel a-.\n");
    fprintf(index, "catalog.wav is those diphones in table order, with 0.1 s of silence between them.\n");
    fprintf(index, "A later table row with the same two bytes is skipped: lookup always uses the first row.\n\n");

    memset(&catalog, 0, sizeof catalog);
    for (i = 0; i < ot_symbol_count; i++) {
        const OtSymbol *sym = &ot_symbols[i];
        char name[96];
        char path[160];
        int samples;
        if (seen_pair(sym, i)) {
            fprintf(index, "%3d  skipped duplicate %u,%u  class %u\n", i, sym->a, sym->b, sym->cls);
            skipped++;
            continue;
        }
        name[0] = 0;
        sym_piece(name, sizeof name, sym->a);
        strncat(name, "_", sizeof name - strlen(name) - 1);
        sym_piece(name, sizeof name, sym->b);
        sprintf(path, "recovered/wav/voices/diphones/%03d_%s.wav", i, name);

        memset(&pcm, 0, sizeof pcm);
        {
            int err = render_pair(&pcm, sym);
            int werr;
            if (err) {
                fprintf(index, "%3d  FAILED %s  bytes %u %u  class %u  render %d\n",
                        i, name, sym->a, sym->b, sym->cls, err);
                failed++;
                ot_pcm_clear(&pcm);
                continue;
            }
            werr = write_pcm(path, &pcm);
            if (werr && errno != EACCES) {
                fprintf(index, "%3d  FAILED %s  write errno %d %s\n", i, name, errno, strerror(errno));
                failed++;
                ot_pcm_clear(&pcm);
                continue;
            }
        }
        samples = (int)(pcm.used - 44) / 2;
        fprintf(index, "%3d  %s  class %u  count %u  samples %d\n", i, name, sym->cls, sym->count, samples);
        {
            const int16_t *src = (const int16_t *)(pcm.data + 44);
            int n = samples;
            int s;
            for (s = 0; s < n; s++) {
                if (ot_pcm_append(&catalog, src[s], 1) != 0) {
                    fprintf(stderr, "catalog append failed\n");
                    ot_pcm_clear(&pcm);
                    ot_pcm_clear(&catalog);
                    fclose(index);
                    return 1;
                }
            }
            if (ot_pcm_append(&catalog, 0, 800) != 0) {
                fprintf(stderr, "catalog gap failed\n");
                ot_pcm_clear(&pcm);
                ot_pcm_clear(&catalog);
                fclose(index);
                return 1;
            }
        }
        ot_pcm_clear(&pcm);
        written++;
    }
    if (write_pcm("recovered/wav/voices/catalog.wav", &catalog) != 0) {
        fprintf(stderr, "catalog.wav failed errno %d %s used %u\n", errno, strerror(errno), catalog.used);
        ot_pcm_clear(&catalog);
        fclose(index);
        return 1;
    }
    fprintf(index, "\nwrote %d diphones, skipped %d duplicates, failed %d\n", written, skipped, failed);
    fprintf(index, "catalog samples %u\n", (catalog.used - 44) / 2);
    ot_pcm_clear(&catalog);
    fclose(index);
    printf("wrote %d diphones, skipped %d, failed %d\n", written, skipped, failed);
    return failed ? 1 : 0;
}
