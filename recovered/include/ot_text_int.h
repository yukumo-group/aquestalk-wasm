/*
 * Calls between the kana scan, the tag lexer, and the number readers.
 */

#pragma once

#include <stdint.h>

int ot_dict_lookup(const uint8_t *text, int *matched);
/* Live phoneme bytes. ot_append_byte may move this block. */
uint8_t *ot_ph(void);
int ot_append_byte(uint8_t *buf, int *count, int value);
int ot_append_span(uint8_t *buf, int *count, const uint8_t *s, int maxn);
int ot_append_cstr(uint8_t *buf, int *count, const char *s);
int ot_read_number(uint8_t *text, uint8_t *buf, int *count);
int ot_speak_pairs_from(uint8_t *buf, int *count, const char *s, int accent, int *npairs);
int ot_numk_place(uint8_t *buf, int *count, int place, int digit);
void ot_numk_fixup(uint8_t *buf, int *count, int ones_ichi);
int ot_numk_window(uint8_t *buf, int *count, const uint8_t window[4], int place0);
int ot_numk_slot_counter(uint8_t *buf, int *count, const uint8_t window[4], int place,
                         const char *counter, const char *mode, int flag);

extern const char *const ot_numk_name[4][10];
extern const int ot_numk_accent[4][10];
int ot_read_numk_counter(uint8_t *text, uint8_t *buf, int *count, const char *counter, const char *mode);
int ot_read_numk(uint8_t *text, uint8_t *buf, int *count);
int ot_apply_tag(const uint8_t *text, int *used, uint8_t *buf, int *count);
