#pragma once

#include <stdint.h>

/* Tables copied out of Open_Talk.dll. Pointers in the original image were
   turned into length-prefixed byte strings so the data is position independent. */

typedef struct OtDictEnt {
    const char *text;
    int length;
    unsigned code;
} OtDictEnt;

extern const uint8_t ot_key_perm[7];
extern const uint8_t ot_utf_map[178 * 10];
extern const OtDictEnt ot_dict[];
extern const int ot_dict_count;
extern const uint8_t ot_letter_rows[26 * 12];
extern const uint8_t ot_punct_rows[21 * 8];
