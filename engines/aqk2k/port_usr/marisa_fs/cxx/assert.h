#ifndef AQ_CXX_ASSERT_H
#define AQ_CXX_ASSERT_H
#ifdef __cplusplus
extern "C" void abort(void) __attribute__((noreturn));
#else
void abort(void) __attribute__((noreturn));
#endif
#define assert(x) ((x) ? (void)0 : abort())
#endif
