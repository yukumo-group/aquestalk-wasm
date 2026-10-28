/*
 * Reconstruction of lib64/Open_Talk.dll (x64, image base 0x180000000).
 * Behavior below is translated from Hex-Rays via ida_domain. Places the
 * decompiler dropped a register are marked UNCERTAIN. The diphone expander
 * lives in recovered/src/synth/ot_expand.c.
 */

#include "ot_internal.h"

#include "ot_data.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* WAV header, PCM buffer, source-filter sample, and the lattice. */

void ot_pcm_clear(OtPcm *pcm)
{
    free(pcm->data);
    pcm->data = NULL;
    pcm->cap = 0;
    pcm->used = 0;
}

int ot_pcm_append(OtPcm *pcm, int16_t sample, uint32_t count)
{
    uint64_t need;
    if (!pcm->data) {
        pcm->cap = 0x8000;
        pcm->data = (uint8_t *)malloc(pcm->cap);
        if (!pcm->data) {
            return OT_ERR_NOMEM;
        }
        pcm->used = 44;
    }
    need = (uint64_t)pcm->used + 2ull * count;
    if (need >= pcm->cap) {
        uint32_t cap = pcm->cap + ((((uint32_t)(2u * count) / 0x8000u) + 1u) << 15);
        uint8_t *grown = (uint8_t *)malloc(cap);
        if (!grown) {
            return OT_ERR_NOMEM;
        }
        memcpy(grown, pcm->data, pcm->used);
        free(pcm->data);
        pcm->data = grown;
        pcm->cap = cap;
    }
    while (count--) {
        memcpy(pcm->data + pcm->used, &sample, 2);
        pcm->used += 2;
    }
    return 0;
}

void ot_write_wav_header(OtPcm *pcm)
{
    uint32_t total = pcm->used;
    uint32_t pcm_bytes = ((total - 44u) >> 1) << 1;
    uint32_t riff = 0x46464952u;
    uint32_t wave = 0x45564157u;
    uint32_t fmt = 0x20746D66u;
    uint32_t data = 0x61746164u;
    uint32_t fmt_size = 16;
    uint32_t channels_format = 65537u;
    uint32_t align_bits = 1048578u;
    uint32_t rate = 8000;
    uint32_t byte_rate = 16000;
    uint32_t chunk = pcm_bytes + 36u;
    uint8_t *p = pcm->data;
    memcpy(p + 0, &riff, 4);
    memcpy(p + 4, &chunk, 4);
    memcpy(p + 8, &wave, 4);
    memcpy(p + 12, &fmt, 4);
    memcpy(p + 16, &fmt_size, 4);
    memcpy(p + 20, &channels_format, 4);
    memcpy(p + 24, &rate, 4);
    memcpy(p + 28, &byte_rate, 4);
    memcpy(p + 32, &align_bits, 4);
    memcpy(p + 36, &data, 4);
    memcpy(p + 40, &pcm_bytes, 4);
}

/*
 * One sample of the source-filter loop (sub_1800059B4).
 * Table loads are movsx, so the waveforms are signed.
 * state layout follows the decompiler's uint16 view of the synth object:
 *   [0] excitation gate, [1] period phase, [2] pulse amplitude,
 *   [3] pitch period, [4] phase within the period, [5] ring index,
 *   [6..9] and [10..13] the 4-tap excitation delay,
 *   [15] force-reset flag, byte at offset 32 inverts the noise sign,
 *   int32 at offset 68 is the filter ring index.
 * coeff points at 11 int16 LPC coefficients (index 0 is the newest).
 */
int ot_render_sample(uint16_t *state, const int16_t *coeff, int16_t *out, const OtVoice *voice)
{
    int noise = 0;
    int period;
    unsigned phase = state[1];
    int i;
    int mixed;
    int acc;
    int ring;
    int16_t *mem;
    const int16_t *tap;

    if (phase >= 0x1000u) {
        phase = 0;
    }
    period = (int)state[0] * (int)voice->period[phase] / 128;
    state[1] = (uint16_t)(phase + 1);
    for (i = 0; i < 4; i++) {
        unsigned idx = state[6 + i];
        if (idx < (unsigned)voice->pulse_count) {
            noise += (int)state[10 + i] * (int)voice->pulse[idx] / 128;
            state[6 + i] = (uint16_t)(idx + 8);
        }
    }
    if (state[15]) {
        state[10 + state[5]] = state[2];
        state[6 + state[5]] = 0;
        state[5] = (uint16_t)(state[5] + 1);
        if (state[5] >= 4) {
            state[5] = 0;
        }
        state[15] = 0;
    } else if (state[3]) {
        uint16_t step;
        state[4] = (uint16_t)(state[4] + 8);
        step = state[4];
        if (state[3] <= step) {
            state[4] = (uint16_t)(step - state[3]);
            state[10 + state[5]] = state[2];
            state[6 + state[5]] = state[4];
            state[5] = (uint16_t)(state[5] + 1);
            if (state[5] >= 4) {
                state[5] = 0;
            }
        }
    }
    mixed = noise;
    /* Byte at offset 32 is the user-key watermark. Set means the noise is inverted. */
    if (*((uint8_t *)state + 32)) {
        mixed = -mixed;
    }
    mixed = period + mixed;
    if (voice->render_mode != 0) {
        uint8_t *raw = (uint8_t *)state;
        int32_t counter = *(int32_t *)(raw + 0x48);
        if (voice->render_mode == 1) {
            /* dvd: negate the mix for 8 samples, then pass it for 8. */
            int exc = (counter < 8) ? -mixed : mixed;
            counter++;
            if (counter >= 16) {
                counter = 0;
            }
            mixed = exc;
        } else {
            /* jgr: a zero counter mutes this sample. The counter wraps at 8. */
            int exc = (counter == 0) ? 0 : mixed;
            counter++;
            if (counter >= 8) {
                counter = 0;
            }
            mixed = exc;
        }
        *(int32_t *)(raw + 0x48) = counter;
    }
    acc = (int)coeff[0] * mixed;
    ring = *(int32_t *)(state + 34);
    mem = (int16_t *)(state + 24);
    tap = coeff + (10 - ring);
    while (tap <= coeff + 10) {
        acc -= (int)(*mem) * (int)(*tap);
        mem++;
        tap++;
    }
    /* After the first sweep, v27 is coeff_base - mem, so the next product is mem[i] * coeff[1], coeff[2], ... */
    tap = coeff + 1;
    while (mem < (int16_t *)(state + 34)) {
        acc -= (int)(*mem) * (int)(*tap);
        mem++;
        tap++;
    }
    if (acc < 0x7FFFFFF) {
        if (acc > -134217727) {
            acc = (acc + 2048) >> 12;
        } else {
            acc = -32768;
        }
    } else {
        acc = 32767;
    }
    ((int16_t *)(state + 24))[ring] = (int16_t)acc;
    *(int32_t *)(state + 34) = ring ? ring - 1 : 9;
    if (voice->render_mode != 0) {
        uint8_t *raw = (uint8_t *)state;
        int32_t env = *(int32_t *)(raw + 0x4C);
        int32_t gain = *(int32_t *)(raw + 0x50);
        int32_t sample = (int16_t)acc;
        int32_t env2 = env - (env >> 5);
        int32_t part = sample >> 5;
        int32_t scaled = sample * gain / 1024;
        *(int32_t *)(raw + 0x4C) = (sample <= 0) ? (env2 - part) : (part + env2);
        if (scaled > 32767) {
            scaled = 32767;
        }
        if (scaled < -32768) {
            scaled = -32768;
        }
        acc = (int)scaled;
    }
    *out = (int16_t)acc;
    return 0;
}

/* Once per frame, before the sample loop. Envelope lives at byte 0x4C. */
void ot_render_prepare(uint16_t *state, const OtVoice *voice)
{
    uint8_t *raw;
    int32_t env;
    int32_t gain;
    if (!voice || voice->render_mode == 0) {
        return;
    }
    raw = (uint8_t *)state;
    env = *(int32_t *)(raw + 0x4C);
    gain = (env < 0x800) ? 0xC00 : (0x400000 / env + 0x400);
    *(int32_t *)(raw + 0x50) = gain;
}

/*
 * One reflection step from sub_180001F00 (Open_Talk+0x1F00).
 * The low term is (src & 0xFFFE) * k, arithmetic-shifted 14, then masked to
 * a multiple of 4. The high term shifts src first and does not shift the
 * product. Hex-Rays reordered the live p/g/h slots, so this follows the
 * disassembly: p is updated from f, g from p, h from g.
 */
static int32_t ot_imul(int32_t a, int32_t b)
{
    return (int32_t)((uint32_t)a * (uint32_t)b);
}

static int32_t ot_reflect(int32_t acc, int32_t src, int32_t k)
{
    acc -= (ot_imul(src & 0xFFFE, k) >> 14) & ~3;
    acc -= ot_imul((src >> 14) & ~3, k);
    return acc;
}

static int32_t ot_shl(int32_t v, int n)
{
    return (int32_t)((uint32_t)v << n);
}

/*
 * Five-stage lattice. a2 is five even or odd formant int16s at stride 2
 * (a2[0], a2[2], ...).
 */
static void ot_lattice(const int16_t *a2, int32_t *dst)
{
    const int32_t one = 0x1000000;
    int32_t k1 = a2[2];
    int32_t k2 = a2[4];
    int32_t k3 = a2[6];
    int32_t k4 = a2[8];
    int32_t f = -ot_shl((int32_t)a2[0], 10);
    int32_t p = ot_shl(one, 1);
    int32_t g;
    int32_t h;
    int32_t tail;

    p = ot_reflect(p, f, k1);
    f -= ot_shl(k1, 10);
    g = ot_reflect(ot_shl(f, 1), p, k2);
    p += one;
    p = ot_reflect(p, f, k2);
    f -= ot_shl(k2, 10);
    h = ot_reflect(ot_shl(p, 1), g, k3);
    g = ot_reflect(g + f, p, k3);
    p += one;
    p = ot_reflect(p, f, k3);
    f -= ot_shl(k3, 10);
    tail = ot_reflect(ot_shl(g, 1), h, k4);
    h = ot_reflect(h + p, g, k4);
    g = ot_reflect(g + f, p, k4);
    p += one;
    p = ot_reflect(p, f, k4);
    f -= ot_shl(k4, 10);
    dst[0] = one;
    dst[1] = f;
    dst[2] = p;
    dst[3] = g;
    dst[4] = h;
    dst[5] = tail;
}

void ot_formants_to_lpc(const int16_t *formants, int16_t *dst)
{
    int32_t even[6];
    int32_t odd[6];
    int i;
    int16_t *hi;
    int16_t *lo;
    ot_lattice(formants, even);
    ot_lattice(formants + 1, odd);
    for (i = 0; i > -20; i -= 4) {
        *(int32_t *)((uint8_t *)even + i + 20) += *(int32_t *)((uint8_t *)even + i + 16);
        *(int32_t *)((uint8_t *)odd + i + 20) -= *(int32_t *)((uint8_t *)odd + i + 16);
    }
    dst[0] = 4096;
    hi = dst + 10;
    lo = dst + 1;
    for (i = 0; i < 5; i++) {
        int e = even[i + 1];
        int o = odd[i + 1];
        int sum = (e + o) >> 13;
        int dif = (e - o) >> 13;
        if (((e + o) & 0x1000) != 0) {
            sum++;
        }
        if (((e - o) & 0x1000) != 0) {
            dif++;
        }
        *lo++ = (int16_t)sum;
        *hi-- = (int16_t)dif;
    }
}

int ot_speed_period(int speed)
{
    if (speed < 50) {
        speed = 50;
    }
    if (speed > 300) {
        speed = 300;
    }
    return 25600 / speed;
}
