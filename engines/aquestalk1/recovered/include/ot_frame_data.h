#pragma once

#include <stdint.h>

/* 6-byte symbol records from RVA 0x2AAA0. */
typedef struct OtSymbol {
    uint8_t a;
    uint8_t b;
    uint8_t cls;
    uint8_t count;
    uint16_t index;
} OtSymbol;

/* 11 int16s per record. Word 0 is the parameter sub_180001B74 returns.
   Words 1..10 are the formants sub_180001D74 interpolates. */
/* Middle pointer of each triple at RVA 0x1B8C0: the 2-byte symbol name. */
extern const uint8_t ot_phoneme_sym[][3];
extern const int ot_phoneme_sym_count;
