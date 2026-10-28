/* shim.c -- data image loader for the recompiled f3 engine. */
#include "shim.h"

#include <time.h>

static int aq_image_ready;

static void aq_put64(unsigned off, uint64_t v)
{
    memcpy(aq_image + off, &v, sizeof v);
}

void aq_init_image(void)
{
    unsigned i;

    if (aq_image_ready) {
        return;
    }
    aq_image_ready = 1;

    for (i = 0; i < aq_num_segments; i++) {
        memcpy(aq_image + aq_segments[i].addr, aq_segments[i].data, aq_segments[i].size);
    }

    for (i = 0; i < aq_num_relocs; i++) {
        unsigned off = aq_relocs[i].off;
        uint32_t addend = aq_relocs[i].addend;
        uint64_t value;

        /* The only two relocations that point into .text are the .init_array
         * and .fini_array entries (0x6150 / 0x6190); those functions are not
         * part of the port, so leave them null. */
        if (addend >= 0x6000u && addend < 0x10b85u) {
            value = 0;
        } else {
            value = (uint64_t)(uintptr_t)(aq_image + addend);
        }
        aq_put64(off, value);
    }

    for (i = 0; i < aq_num_sym_relocs; i++) {
        void *p = 0;
        switch (aq_sym_relocs[i].kind) {
        case AQ_SYM_MALLOC:
            p = (void *)(uintptr_t)&malloc;
            break;
        case AQ_SYM_FREE:
            p = (void *)(uintptr_t)&free;
            break;
        case AQ_SYM_MEMCPY:
            p = (void *)(uintptr_t)&memcpy;
            break;
        case AQ_SYM_MEMMOVE:
            p = (void *)(uintptr_t)&memmove;
            break;
        case AQ_SYM_MEMSET:
            p = (void *)(uintptr_t)&memset;
            break;
        case AQ_SYM_TIME:
            p = (void *)(uintptr_t)&time;
            break;
        case AQ_SYM_STACK_CHK_FAIL:
            p = (void *)(uintptr_t)&abort;
            break;
        default:
            break;
        }
        aq_put64(aq_sym_relocs[i].off, (uint64_t)(uintptr_t)p);
    }
}
