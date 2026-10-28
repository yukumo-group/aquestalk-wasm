/* shim.c -- data image loader for the recompiled AquesTalk2 engine. */
#include "shim.h"

static int aq_image_ready;

static void aq_put64(unsigned off, uint64_t v)
{
    /* The original library has 8 byte pointer slots even on the 32 bit wasm
     * build; always write a full 64 bit value so code that reads a slot as
     * undefined8 sees zero extended pointers. */
    memcpy(aq_image + off, &v, sizeof v);
}

void aq_init_image(void)
{
    if (aq_image_ready)
        return;
    aq_image_ready = 1;

    memcpy(aq_image + aq_rodata_addr, aq_rodata, aq_rodata_size);
    memcpy(aq_image + aq_rwdata_addr, aq_rwdata, aq_rwdata_size);

    for (unsigned i = 0; i < aq_num_relocs; i++) {
        unsigned off = aq_relocs[i].off;
        uint64_t addend = aq_relocs[i].addend;

        /* No relocation in this library points into .text; if that ever
         * changes, the addend has to be resolved to the recompiled function
         * instead of an offset in the data image. */
        if (addend >= 0xdc0 && addend < 0xc9c8) {
            /* Would mean the recovered code needs a real function pointer
             * relocation, which this port does not support. */
            abort();
        }
        aq_put64(off, (uint64_t)(uintptr_t)(aq_image + addend));
    }

    for (unsigned i = 0; i < aq_num_sym_relocs; i++) {
        void *p = 0;
        switch (aq_sym_relocs[i].kind) {
        case AQ_SYM_MALLOC:  p = (void *)(uintptr_t)&malloc;  break;
        case AQ_SYM_FREE:    p = (void *)(uintptr_t)&free;    break;
        case AQ_SYM_MEMCPY:  p = (void *)(uintptr_t)&memcpy;  break;
        case AQ_SYM_MEMMOVE: p = (void *)(uintptr_t)&memmove; break;
        case AQ_SYM_MEMSET:  p = (void *)(uintptr_t)&memset;  break;
        default: break;
        }
        aq_put64(aq_sym_relocs[i].off, (uint64_t)(uintptr_t)p);
    }
}
