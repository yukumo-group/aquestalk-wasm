#pragma once

#include <stdint.h>

/* ot_dur_scale[0] is word_18002CF90[-24]. Index is (7 * high + low). */
extern const int16_t ot_dur_scale[121];
/* 60 records of 4 int16s. The search key is words 0, 1, 2. */
extern const int16_t ot_dur_key[240];
/* 120 rows of 10 int16s from word_18002D000. */
extern const int16_t ot_dur_val[1200];
