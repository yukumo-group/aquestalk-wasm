/* shim.h -- types and runtime support for the recompiled AquesTalk2 engine.
 *
 * The port is a *recompilation*, not an emulator: decomp.c contains C code
 * recovered from the machine code with Ghidra, compiled by clang for the
 * target.  This header only provides the fixed width types Ghidra uses and
 * the data image that mirrors the library's .rodata/.data.
 */
#ifndef AQ_SHIM_H
#define AQ_SHIM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef AQ_FREESTANDING
/* No libc: runtime.c provides these for the raw wasm build. */
void *malloc(size_t);
void free(void *);
void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
void abort(void);
#else
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Ghidra's basic types.  All of them are fixed width so the port behaves the
 * same on x86-64 (native verification build) and wasm32. */
typedef uint8_t  undefined;
typedef uint8_t  undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
typedef uint8_t  byte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;
typedef void     code;

/* The original image maps at virtual address 0; aq_image mirrors that address
 * space byte for byte, so `DAT_00xxxxxx` in decomp.c is aq_image + 0xxxxxx. */
#define AQ_IMAGE_SIZE 0x217038u
extern unsigned char aq_image[AQ_IMAGE_SIZE];

extern const unsigned char aq_rodata[];
extern const unsigned aq_rodata_addr, aq_rodata_size;
extern const unsigned char aq_rwdata[];
extern const unsigned aq_rwdata_addr, aq_rwdata_size;

typedef struct {
    uint32_t off;
    uint32_t addend;
} AqReloc;

enum {
    AQ_SYM_NULL = 0,
    AQ_SYM_MALLOC,
    AQ_SYM_FREE,
    AQ_SYM_MEMCPY,
    AQ_SYM_MEMMOVE,
    AQ_SYM_MEMSET
};

typedef struct {
    uint32_t off;
    uint32_t kind;
} AqSymReloc;

extern const AqReloc aq_relocs[];
extern const unsigned aq_num_relocs;
extern const AqSymReloc aq_sym_relocs[];
extern const unsigned aq_num_sym_relocs;

/* Copies the data segments into aq_image and applies dynamic relocations.
 * Idempotent.  Must be called before any engine function. */
void aq_init_image(void);

/* Helpers used by the mechanically generated code. */
#define CONCAT11(a, b) ((undefined2)((((undefined2)(a)) << 8) | (undefined1)(b)))

#ifdef __cplusplus
}
#endif

#endif /* AQ_SHIM_H */
