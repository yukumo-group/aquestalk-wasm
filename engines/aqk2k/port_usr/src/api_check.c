/* api_check.c -- small wasm32 wrapper for the AqUsrDic_Check subset. */
#include "shim.h"

extern int AqUsrDic_Check(uint64_t surface, uint64_t yomi, int posCode);
extern long *FUN_0010d930(long *param_1, unsigned char *param_2);

int aus_debug_len(const char *s)
{
    AqU16 t;
    AQU16_INIT(t);
    FUN_0010d930((long *)&t, (unsigned char *)(uintptr_t)s);
    return (int)t.len;
}

void *aq_alloc(unsigned int n) { return malloc((size_t)n); }
void aq_free(void *p) { free(p); }

void aus_init(void)
{
    aq_init_image();
    /* The original library's global error string is constructed by a static
     * initializer; reproduce that for the freestanding image. */
    AqStr *err = (AqStr *)(aq_image + 0x33220);
    AQSTR_INIT(*err);
}

int aus_check(const char *surface, const char *yomi, int posCode)
{
    return AqUsrDic_Check((uint64_t)(uintptr_t)surface,
                          (uint64_t)(uintptr_t)yomi, posCode);
}

