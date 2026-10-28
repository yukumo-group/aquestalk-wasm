/*
 * Embedded voice registry.  The tables live in voice_<name>.c, raw-dumped
 * from the Linux libAquesTalk.so builds.
 */
#include "ot_voice.h"

#include <string.h>

const OtVoice *ot_voice_f1(void);
const OtVoice *ot_voice_f2(void);
const OtVoice *ot_voice_m1(void);
const OtVoice *ot_voice_m2(void);
const OtVoice *ot_voice_r1(void);
const OtVoice *ot_voice_imd1(void);
const OtVoice *ot_voice_jgr(void);
const OtVoice *ot_voice_dvd(void);
const OtVoice *ot_voice_f3(void);

static const OtVoice *(*const g_voice[])(void) = {
    ot_voice_f1, ot_voice_f2, ot_voice_m1, ot_voice_m2, ot_voice_r1,
    ot_voice_imd1, ot_voice_jgr, ot_voice_dvd, ot_voice_f3
};
static const char *const g_name[] = {
    "f1", "f2", "m1", "m2", "r1", "imd1", "jgr", "dvd", "f3"
};

static int g_current;

static int ot_name_eq(const char *a, const char *b)
{
    while (*a && *b) {
        char ca = *a;
        char cb = *b;
        if (ca >= 'A' && ca <= 'Z') {
            ca = (char)(ca + 32);
        }
        if (cb >= 'A' && cb <= 'Z') {
            cb = (char)(cb + 32);
        }
        if (ca != cb) {
            return 0;
        }
        a++;
        b++;
    }
    return *a == 0 && *b == 0;
}

int ot_voice_count(void)
{
    return (int)(sizeof g_voice / sizeof g_voice[0]);
}

const char *ot_voice_name(int index)
{
    if (index < 0 || index >= ot_voice_count()) {
        return NULL;
    }
    return g_name[index];
}

const OtVoice *ot_voice_by_name(const char *name)
{
    int i;
    if (!name || !name[0]) {
        return NULL;
    }
    for (i = 0; i < ot_voice_count(); i++) {
        if (ot_name_eq(name, g_name[i])) {
            return g_voice[i]();
        }
    }
    return NULL;
}

const OtVoice *ot_voice_builtin(void)
{
    return g_voice[0]();
}

const OtVoice *ot_voice_current(void)
{
    return g_voice[g_current]();
}

int ot_voice_select(const char *name)
{
    int i;
    if (!name || !name[0]) {
        g_current = 0;
        return 0;
    }
    for (i = 0; i < ot_voice_count(); i++) {
        if (ot_name_eq(name, g_name[i])) {
            g_current = i;
            return 0;
        }
    }
    return -1;
}
