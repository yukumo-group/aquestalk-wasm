/* shim.h -- types and runtime glue for the recompiled AquesTalk10 engine.
 *
 * decomp.c is a mechanical C translation of the original x86-64 machine
 * code (produced by Ghidra).  It is compiled to real native/wasm code; the
 * only thing kept from the binary is its data (kana tables and voice data),
 * reproduced by image.c.  Nothing here emulates x86 instructions.
 */
#ifndef AQTK10_SHIM_H
#define AQTK10_SHIM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef AQTK_FREESTANDING
/* raw wasm build: no libc headers, declarations only */
void *malloc(size_t);
void free(void *);
void *calloc(size_t, size_t);
void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memmove(void *, const void *, size_t);
int memcmp(const void *, const void *, size_t);
size_t strlen(const char *);
void abort(void);
#else
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef signed char sbyte;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned int uint3;      /* Ghidra 24-bit integer, padded to 32 */
typedef void code;

#define CONCAT11(a, b) ((unsigned short)((((unsigned int)(unsigned char)(a)) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) ((unsigned int)((((unsigned int)(unsigned char)(a)) << 16) | (unsigned short)(b)))
#define CONCAT22(a, b) ((unsigned int)((((unsigned int)(unsigned short)(a)) << 16) | (unsigned short)(b)))
#define CONCAT44(a, b) ((unsigned long long)((((unsigned long long)(unsigned int)(a)) << 32) | (unsigned int)(b)))
#define CONCAT53(a, b) ((unsigned long long)((((unsigned long long)(unsigned int)(a)) << 24) | ((unsigned int)(b) & 0xffffffu)))
#define CONCAT62(a, b) ((unsigned long long)((((unsigned long long)(unsigned short)(a)) << 16) | (unsigned short)(b)))
#define CONCAT71(a, b) ((unsigned long long)((((unsigned long long)(unsigned char)(a)) << 8) | (unsigned char)(b)))

/* Original data layout: image offset == original VMA - 0x100000. */
extern unsigned char aq_image[];

typedef struct {
    unsigned int off;               /* image offset of the pointer slot */
    unsigned long long addend;      /* image offset of the target */
} AqReloc;

extern const AqReloc aq_relocs[];
extern const unsigned aq_num_relocs;

void aq_load_image(void);

#ifdef __cplusplus
}
#endif

#endif
