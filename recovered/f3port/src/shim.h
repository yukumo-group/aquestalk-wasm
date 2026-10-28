/* shim.h -- types and data image for the recompiled f3 engine.
 *
 * The port is a recompilation: decomp.c is C recovered from the machine code
 * with Ghidra, compiled by clang.  aq_image mirrors the original virtual
 * address space so `DAT_0011xxxx` is simply aq_image + 0x11xxxx.
 */
#ifndef F3_SHIM_H
#define F3_SHIM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#ifdef AQ_FREESTANDING
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

#define AQ_IMAGE_SIZE 0x29060u
extern unsigned char aq_image[AQ_IMAGE_SIZE];

typedef struct {
    uint32_t addr;
    const unsigned char *data;
    uint32_t size;
} AqSegment;

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
    AQ_SYM_MEMSET,
    AQ_SYM_TIME,
    AQ_SYM_STACK_CHK_FAIL
};

typedef struct {
    uint32_t off;
    uint32_t kind;
} AqSymReloc;

extern const AqSegment aq_segments[];
extern const unsigned aq_num_segments;
extern const AqReloc aq_relocs[];
extern const unsigned aq_num_relocs;
extern const AqSymReloc aq_sym_relocs[];
extern const unsigned aq_num_sym_relocs;

void __stack_chk_fail(void);

/* Copies the data segments into aq_image and applies the dynamic relocations.
 * Idempotent; must run before any engine function. */
void aq_init_image(void);

typedef int8_t int7;
#define CONCAT11(a, b) ((undefined2)((((undefined2)(a)) << 8) | (undefined1)(b)))
#define CONCAT71(a, b) ((uint64_t)((((uint64_t)(a)) << 8) | (uint8_t)(b)))
#define CONCAT22(a, b) ((uint32_t)((((uint32_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT44(a, b) ((uint64_t)((((uint64_t)(a)) << 32) | (uint32_t)(b)))

#ifdef __cplusplus
}
#endif

#endif /* F3_SHIM_H */
