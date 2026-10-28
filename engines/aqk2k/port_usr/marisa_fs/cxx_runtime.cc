#include <new>
#include <stdlib.h>
#include <string.h>

const std::nothrow_t std::nothrow = std::nothrow_t();

void *operator new(size_t n) { void *p = malloc(n ? n : 1); if (!p) abort(); return p; }
void *operator new[](size_t n) { void *p = malloc(n ? n : 1); if (!p) abort(); return p; }
void *operator new(size_t n, const std::nothrow_t &) noexcept { return malloc(n ? n : 1); }
void *operator new[](size_t n, const std::nothrow_t &) noexcept { return malloc(n ? n : 1); }
void operator delete(void *p) noexcept { free(p); }
void operator delete[](void *p) noexcept { free(p); }
void operator delete(void *p, size_t) noexcept { free(p); }
void operator delete[](void *p, size_t) noexcept { free(p); }
void operator delete(void *p, const std::nothrow_t &) noexcept { free(p); }
void operator delete[](void *p, const std::nothrow_t &) noexcept { free(p); }

extern "C" int __cxa_atexit(void (*)(void *), void *, void *) { return 0; }
extern "C" void *__dso_handle = 0;
