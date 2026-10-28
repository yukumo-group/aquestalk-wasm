/* shim.c -- runtime support for the decompiled libAqKanji2Koe port. */
#include "shim.h"
#include <stdarg.h>
#ifndef AQK2K_WASM
#include <execinfo.h>
#endif

/* ------------------------------------------------------------------ */
/* Embedded original image + dynamic relocations                      */
/* ------------------------------------------------------------------ */
static int aq_image_ready = 0;
static char aq_tls[64];
long aq_fs_offset;

void aq_init_image(void)
{
    if (aq_image_ready)
        return;
    aq_image_ready = 1;
    aq_fs_offset = (long)(uintptr_t)aq_tls - 0x28;
    for (unsigned i = 0; i < aq_num_relocs; i++) {
        unsigned off = aq_relocs[i].off;
        unsigned long long target = aq_relocs[i].addend;
        *(unsigned long long *)(aq_image + off) =
            (unsigned long long)(uintptr_t)aq_image + target;
    }
}

/* ------------------------------------------------------------------ */
/* Allocator / C++ runtime                                             */
/* ------------------------------------------------------------------ */
void *operator_new(size_t n, ...)
{
    void *p = malloc(n ? n : 1);
    if (!p) {
        fprintf(stderr, "aqk2k: out of memory (%zu)\n", n);
        abort();
    }
    return p;
}

void operator_delete(void *p)
{
    free(p);
}

void *aq_new_array(size_t n, ...) { return operator_new(n); }
void aq_delete_array(void *p, ...) { free(p); }

void aq_exception_dtor(void *p) { (void)p; }

void *__cxa_allocate_exception(size_t n)
{
    void *p = malloc(n);
    if (!p)
        abort();
    return p;
}

void __cxa_throw(void *obj, void *tinfo, void *dtor)
{
    (void)obj; (void)tinfo; (void)dtor;
    char *msg = obj ? ((char **)obj)[3] : 0;
    fprintf(stderr, "aqk2k: C++ exception: %s\n", msg ? msg : "(none)");
#ifndef AQK2K_WASM
    void *bt[32];
    int n = backtrace(bt, 32);
    backtrace_symbols_fd(bt, n, 2);
#endif
    abort();
}

void *__cxa_begin_catch(void *obj) { return obj; }
void __cxa_end_catch(void) {}
void _Unwind_Resume(void *p) { (void)p; abort(); }

void *aq_throw_length_error(const char *msg)
{
    fprintf(stderr, "aqk2k: length_error: %s\n", msg ? msg : "");
    abort();
}

void *aq_throw_logic_error(const char *msg)
{
    fprintf(stderr, "aqk2k: logic_error: %s\n", msg ? msg : "");
    abort();
}

void *aq_throw_out_of_range_fmt(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputc('\n', stderr);
    abort();
}

void FUN_001088f6(void) { abort(); }
void FUN_00108fd0(void) { abort(); }
undefined8 FUN_001089f4(void) { abort(); }

/* ------------------------------------------------------------------ */
/* libstdc++ std::string ABI (C++11)                                   */
/* ------------------------------------------------------------------ */
#define AQS(s) ((AqStr *)(s))

static int aqs_is_local(AqStr *s) { return s->p == s->u.buf; }

static size_t aqs_capacity(AqStr *s)
{
    return aqs_is_local(s) ? 15u : s->u.cap;
}

static void aqs_grow(AqStr *s, size_t need)
{
    size_t oldcap = aqs_capacity(s);
    if (need <= oldcap)
        return;
    size_t newcap = oldcap * 2;
    if (newcap < need)
        newcap = need;
    if (newcap < 16)
        newcap = 16;
    char *np = (char *)malloc(newcap + 1);
    if (!np) {
        fprintf(stderr, "aqk2k: out of memory (string grow)\n");
        abort();
    }
    memcpy(np, s->p, s->len + 1);
    if (!aqs_is_local(s))
        free(s->p);
    s->p = np;
    s->u.cap = newcap;
}

static void aqs_check(AqStr *s, size_t pos, size_t n1)
{
    if (pos > s->len || n1 > s->len - pos) {
        fprintf(stderr, "aqk2k: basic_string range error\n");
        abort();
    }
}

void aqstr_replace_aux(void *self, size_t pos, size_t n1, size_t n2, int c)
{
    AqStr *s = AQS(self);
    aqs_check(s, pos, n1);
    size_t newlen = s->len - n1 + n2;
    if (newlen > s->len)
        aqs_grow(s, newlen);
    memmove(s->p + pos + n2, s->p + pos + n1, s->len - pos - n1 + 1);
    if (n2)
        memset(s->p + pos, c, n2);
    s->len = newlen;
    s->p[s->len] = 0;
}

void aqstr_replace(void *self, size_t pos, size_t n1, const char *src)
{
    AqStr *s = AQS(self);
    size_t n2 = src ? strlen(src) : 0;
    aqs_check(s, pos, n1);
    size_t newlen = s->len - n1 + n2;
    if (newlen > s->len)
        aqs_grow(s, newlen);
    char *tmp = NULL;
    if (src && n2 && src >= s->p && src < s->p + s->len) {
        tmp = (char *)malloc(n2);
        if (!tmp)
            abort();
        memcpy(tmp, src, n2);
        src = tmp;
    }
    memmove(s->p + pos + n2, s->p + pos + n1, s->len - pos - n1 + 1);
    if (n2)
        memcpy(s->p + pos, src, n2);
    s->len = newlen;
    s->p[s->len] = 0;
    free(tmp);
}

void *aqstr_append(void *self, const char *src)
{
    AqStr *s = AQS(self);
    if (!src)
        return;
    size_t n = strlen(src);
    aqs_grow(s, s->len + n);
    memcpy(s->p + s->len, src, n);
    s->len += n;
    s->p[s->len] = 0;
    return self;
}

void aqstr_mutate(void *self, size_t pos, size_t n1, const char *src, size_t n2)
{
    AqStr *s = AQS(self);
    aqs_check(s, pos, n1);
    size_t newlen = s->len - n1 + n2;
    if (newlen > s->len)
        aqs_grow(s, newlen);
    memmove(s->p + pos + n2, s->p + pos + n1, s->len - pos - n1 + 1);
    if (n2 && src)
        memmove(s->p + pos, src, n2);
    s->len = newlen;
    s->p[s->len] = 0;
}

void aqstr_erase(void *self, size_t pos)
{
    AqStr *s = AQS(self);
    size_t n = (pos < s->len) ? 1 : 0;
    aqstr_replace_aux(self, pos, n, 0, 0);
}

size_t aqstr_find(void *self, const char *needle, size_t pos)
{
    AqStr *s = AQS(self);
    size_t n = strlen(needle);
    if (n == 0)
        return pos <= s->len ? pos : (size_t)-1;
    if (pos > s->len || n > s->len - pos)
        return (size_t)-1;
    for (size_t i = pos; i + n <= s->len; i++) {
        if (memcmp(s->p + i, needle, n) == 0)
            return i;
    }
    return (size_t)-1;
}

int aqstr_compare(void *self, size_t pos, size_t n1, const char *src)
{
    AqStr *s = AQS(self);
    if (pos > s->len)
        return -1;
    if (n1 > s->len - pos)
        n1 = s->len - pos;
    size_t n2 = strlen(src);
    size_t n = n1 < n2 ? n1 : n2;
    int r = n ? memcmp(s->p + pos, src, n) : 0;
    if (r)
        return r;
    if (n1 < n2)
        return -1;
    if (n1 > n2)
        return 1;
    return 0;
}

size_t aqstr_copy(void *self, char *dest, size_t n)
{
    AqStr *s = AQS(self);
    size_t m = n < s->len ? n : s->len;
    memcpy(dest, s->p, m);
    return m;
}

void *aq_throw_bad_alloc(void)
{
    fprintf(stderr, "aqk2k: bad_alloc\n");
    abort();
}

void *aq_throw_bad_array_new_length(void)
{
    fprintf(stderr, "aqk2k: bad_array_new_length\n");
    abort();
}

void *aqstr_create(void *self, unsigned long *cap)
{
    AqStr *s = AQS(self);
    size_t n = (size_t)*cap;
    char *np = (char *)malloc(n + 1);
    if (!np)
        abort();
    np[0] = 0;
    if (!aqs_is_local(s))
        free(s->p);
    s->p = np;
    s->u.cap = n;
    *cap = n;
    return self;
}

void *aqstr_construct(void *self, unsigned long n, ...)
{
    AqStr *s = AQS(self);
    if (n > aqs_capacity(s))
        aqs_grow(s, n);
    memset(s->p, 0, n);
    s->p[n] = 0;
    s->len = n;
    return self;
}

long aq_istream_read(void *self, ...)
{
    (void)self;
    return 0;
}

long aq_ostream_write(void *self, ...)
{
    (void)self;
    return 0;
}

/* Cold-section exception helpers (only reached on malformed data). */
