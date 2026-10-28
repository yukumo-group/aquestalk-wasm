/* shim.h -- runtime support for the decompiled libAqKanji2Koe port. */
#ifndef AQK2K_SHIM_H
#define AQK2K_SHIM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef AQK2K_WASM
/* freestanding declarations (no libc headers on wasm64-unknown-unknown) */
typedef struct _FILE FILE;
extern FILE *stderr;
extern FILE *stdout;
void *malloc(size_t);
void *calloc(size_t, size_t);
void *realloc(void *, size_t);
void free(void *);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);
size_t strlen(const char *);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
char *strcpy(char *, const char *);
int fprintf(FILE *, const char *, ...);
int vfprintf(FILE *, const char *, __builtin_va_list);
int fputc(int, FILE *);
void abort(void);
void exit(int);
void __stack_chk_fail(void);
void __assert_fail(const char *, const char *, unsigned int, const char *);
#else
#include <string.h>
#include <stdlib.h>
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
typedef unsigned long ulong;
typedef void code;

typedef struct { int dummy; } nothrow_t;
typedef struct { void *vptr; } exception;

/* libstdc++ (C++11 ABI) std::string layout, 32 bytes on LP64. */
typedef struct AqStr {
    char *p;
    size_t len;
    union {
        char buf[16];
        size_t cap;
    } u;
} AqStr;

/* Accessors that hide the wasm32 (64-bit pointer cell) vs native layout.
 * AQSTR_INIT matches libstdc++'s small-string initialisation. */
#if defined(__wasm32__)
#define AQSTR_INIT(s) do { (s).p = (uint64_t)(uintptr_t)(s).u.buf; \
                           (s).len = 0; (s).u.buf[0] = 0; } while (0)
#define AQSTR_DATA(s) ((void *)(uintptr_t)(s).p)
#define AQSTR_LOCAL(s) ((s).p == (uint64_t)(uintptr_t)(s).u.buf)
#else
#define AQSTR_INIT(s) do { (s).p = (s).u.buf; \
                           (s).len = 0; (s).u.buf[0] = 0; } while (0)
#define AQSTR_DATA(s) ((void *)(s).p)
#define AQSTR_LOCAL(s) ((s).p == (s).u.buf)
#endif

/* libstdc++ std::u16string layout, 32 bytes. */
typedef struct AqU16 {
    uint16_t *p;
    size_t len;
    union {
        uint16_t buf[8];
        size_t cap;
    } u;
} AqU16;

#if defined(__wasm32__)
#define AQU16_DATA(s) ((uint16_t *)(uintptr_t)(s).p)
#else
#define AQU16_DATA(s) ((uint16_t *)(s).p)
#endif

/* 16 byte SSE register value (only used by one sorting routine). */
typedef struct { unsigned char b[16]; } aq_v16;

typedef struct { unsigned int off; unsigned long long addend; } AqReloc;

extern unsigned char aq_image[];
extern const AqReloc aq_relocs[];
extern const unsigned aq_num_relocs;

/* Relocate the embedded image.  Idempotent. */
void aq_init_image(void);
int aq_lookup_load(const char *path);
int aq_lookup_prefix(const uint16_t *key, int units, int *outLen, uint32_t *outId);
int aq_lookup_prefix_after(int kind, const uint16_t *key, int units, int after,
                           int *outLen, uint32_t *outId);
int aq_lookup_ready(void);
void aq_lookup_register_slot(void *slot, int kind);
int aq_lookup_slot_kind(void *slot);
int aq_lookup_slot_ok(void *slot);

/* Original data-global used as thread pointer base for the stack canary. */
extern long aq_fs_offset;
#define in_FS_OFFSET aq_fs_offset

#define CONCAT44(a, b) ((((unsigned long long)(a)) << 32) | (unsigned int)(b))
#define CONCAT62(a, b) ((((unsigned long long)(a)) << 16) | (unsigned short)(b))
#define CONCAT71(a, b) ((((unsigned long long)(a)) << 8) | (unsigned char)(b))
#define CARRY8(a, b) (((unsigned long long)(a) + (unsigned long long)(b)) < (unsigned long long)(a))

static inline aq_v16 aq_pshuflw(aq_v16 a)
{
    aq_v16 r;
    unsigned short *s = (unsigned short *)a.b;
    unsigned short *d = (unsigned short *)r.b;
    d[0] = s[3];
    d[1] = s[2];
    d[2] = s[1];
    d[3] = s[0];
    d[4] = d[5] = d[6] = d[7] = 0;
    return r;
}

/* ---- C++ runtime / allocator shims ---- */
void *operator_new(size_t n, ...);
void operator_delete(void *p);
void *aq_new_array(size_t n);
void aq_delete_array(void *p);

void aq_exception_dtor(void *p);
void *__cxa_allocate_exception(size_t n);
void __cxa_throw(void *obj, void *tinfo, void *dtor) __attribute__((noreturn));
void *__cxa_begin_catch(void *obj);
void __cxa_end_catch(void);
void _Unwind_Resume(void *p) __attribute__((noreturn));

void aq_throw_length_error(const char *msg) __attribute__((noreturn));
void aq_throw_logic_error(const char *msg) __attribute__((noreturn));
void aq_throw_out_of_range_fmt(const char *fmt, ...) __attribute__((noreturn));

/* ---- libstdc++ std::string ABI (decompiled call site signatures) ---- */
void aqstr_replace_aux(void *self, size_t pos, size_t n1, size_t n2, int c);
void aqstr_replace(void *self, size_t pos, size_t n1, const char *s);
void aqstr_append(void *self, const char *s);
void aqstr_mutate(void *self, size_t pos, size_t n1, const char *s, size_t n2);
void aqstr_erase(void *self, size_t pos);
size_t aqstr_find(void *self, const char *s, size_t pos);
int aqstr_compare(void *self, size_t pos, size_t n1, const char *s);
size_t aqstr_copy(void *self, char *dest, size_t n);

/* ---- internal functions used by the hand written API layer ---- */
long *FUN_001094c0(long *param_1, byte *param_2);
long *FUN_00109e90(long *param_1, undefined8 *param_2);
void FUN_0010c650(undefined1 *param_1);
void FUN_0010c6a0(undefined1 *param_1);
undefined8 FUN_0010c6d0(undefined1 *param_1, char *param_2, undefined8 param_3);
undefined8 FUN_0010cfe0(char *param_1, undefined8 param_2, undefined8 param_3);
undefined8 FUN_0010a600(char *param_1);

/* Cold-section routines that are only reached on malformed dictionaries. */
void FUN_001088f6(void);
void FUN_00108fd0(void);
undefined8 FUN_001089f4(void);

#ifdef __cplusplus
}
#endif

#endif
