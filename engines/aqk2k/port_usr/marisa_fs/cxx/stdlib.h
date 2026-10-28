#ifndef AQ_CXX_STDLIB_H
#define AQ_CXX_STDLIB_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
void *malloc(size_t);
void *calloc(size_t, size_t);
void *realloc(void *, size_t);
void free(void *);
void abort(void) __attribute__((noreturn));
void exit(int) __attribute__((noreturn));
int abs(int);
#ifdef __cplusplus
}
#endif
#endif
