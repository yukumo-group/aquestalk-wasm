/* Thin entry points over the recompiled f3 engine (decomp.c). */
#include "f3port.h"
#include "shim.h"

extern undefined8 AquesTalk_Synthe_Utf8(undefined8 koe, undefined4 speed, int *size);
extern undefined8 AquesTalk_Synthe(undefined8 koe, undefined4 speed, int *size);
extern undefined8 AquesTalk_Synthe_Utf16(undefined8 koe, undefined4 speed, int *size);

unsigned char *f3_port_synthe_utf8(const char *text, int speed, int *size)
{
    aq_init_image();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe_Utf8(
        (undefined8)(uintptr_t)text, (undefined4)speed, size);
}

unsigned char *f3_port_synthe_sjis(const char *text, int speed, int *size)
{
    aq_init_image();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe(
        (undefined8)(uintptr_t)text, (undefined4)speed, size);
}

unsigned char *f3_port_synthe_utf16(const unsigned short *text, int speed, int *size)
{
    aq_init_image();
    return (unsigned char *)(uintptr_t)AquesTalk_Synthe_Utf16(
        (undefined8)(uintptr_t)text, (undefined4)speed, size);
}
