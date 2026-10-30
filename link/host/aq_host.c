/* C half of the link kit: the libc surface the engines expect.
 *
 * The engines are built freestanding, so when they are linked into a Rust
 * module the Rust side supplies `malloc`/`free` (see host.rs) and
 * `memcpy`/`memset` (compiler-builtins).  Everything else the decompiled code
 * references lives here: string helpers, a time stub, no-op stdio used only
 * for diagnostics, and the trap helpers.
 *
 * This file is compiled once and linked into the final module.  Definitions
 * are strong on purpose: they override the weak string symbols that ship with
 * the Rust standard library, and wasm-ld accepts a strong definition over a
 * weak one.
 */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

typedef struct AqHostFile {
    unsigned char opaque[64];
} AqHostFile;

static AqHostFile aq_host_stderr;
static AqHostFile aq_host_stdout;

/* The engines declare `extern FILE *stderr` / `stdout`.  Only the address
 * matters: every stdio call below is a no-op. */
void *stderr = &aq_host_stderr;
void *stdout = &aq_host_stdout;

int fprintf(void *file, const char *format, ...)
{
    (void)file;
    (void)format;
    return 0;
}

int printf(const char *format, ...)
{
    (void)format;
    return 0;
}

int vfprintf(void *file, const char *format, va_list args)
{
    (void)file;
    (void)format;
    (void)args;
    return 0;
}

int fputc(int ch, void *file)
{
    (void)file;
    return ch;
}

size_t fwrite(const void *data, size_t size, size_t count, void *file)
{
    (void)data;
    (void)size;
    (void)file;
    return count;
}

int puts(const char *text)
{
    (void)text;
    return 0;
}

size_t strlen(const char *text)
{
    const char *end = text;
    while (*end) {
        end++;
    }
    return (size_t)(end - text);
}

int strcmp(const char *left, const char *right)
{
    while (*left && *left == *right) {
        left++;
        right++;
    }
    return (int)(unsigned char)*left - (int)(unsigned char)*right;
}

int strncmp(const char *left, const char *right, size_t count)
{
    while (count--) {
        unsigned char a = (unsigned char)*left++;
        unsigned char b = (unsigned char)*right++;
        if (a != b) {
            return (int)a - (int)b;
        }
        if (!a) {
            return 0;
        }
    }
    return 0;
}

char *strcpy(char *to, const char *from)
{
    char *start = to;
    while ((*to++ = *from++) != 0) {
    }
    return start;
}

char *strncpy(char *to, const char *from, size_t count)
{
    char *start = to;
    while (count && *from) {
        *to++ = *from++;
        count--;
    }
    while (count--) {
        *to++ = 0;
    }
    return start;
}

int memcmp(const void *left, const void *right, size_t count)
{
    const unsigned char *a = (const unsigned char *)left;
    const unsigned char *b = (const unsigned char *)right;
    while (count--) {
        if (*a != *b) {
            return (int)*a - (int)*b;
        }
        a++;
        b++;
    }
    return 0;
}

/* AquesTalk1 records a license timestamp with time().  Zero is fine for the
 * evaluation builds (the marker is not verified by these ports). */
int time(int *out)
{
    if (out) {
        *out = 0;
    }
    return 0;
}

void abort(void)
{
    __builtin_trap();
}

/* Reached only when the decompiled code detects malformed input. */
void __assert_fail(const char *assertion, const char *file, unsigned line, const char *function)
{
    (void)assertion;
    (void)file;
    (void)line;
    (void)function;
    __builtin_trap();
}

void __stack_chk_fail(void)
{
    __builtin_trap();
}
