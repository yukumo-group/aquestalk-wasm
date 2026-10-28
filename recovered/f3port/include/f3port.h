/* f3port.h -- entry points of the mechanically recompiled f3 engine. */
#pragma once

/* UTF-8 / SJIS / UTF-16 text -> complete WAV, or NULL with *size set to an
 * AquesTalk error code.  The result is malloc'd; free it with free(). */
unsigned char *f3_port_synthe_utf8(const char *text, int speed, int *size);
unsigned char *f3_port_synthe_sjis(const char *text, int speed, int *size);
unsigned char *f3_port_synthe_utf16(const unsigned short *text, int speed, int *size);
