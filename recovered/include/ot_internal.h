/*
 * Shared declarations for the split of the former open_talk.c.
 * The error numbers are the DLL's *pSize codes.
 */

#pragma once

#include <stdint.h>

#include "ot_speak.h"

enum {
    OT_ERR_OTHER = 100,
    OT_ERR_NOMEM = 101,
    OT_ERR_SYMBOL = 102,
    OT_ERR_UNKNOWN = 105,
    OT_ERR_EMPTY_TAG = 106,
    OT_ERR_BAD_TAG = 107,
    OT_ERR_NONDIGIT = 108,
    OT_ERR_PRESET = 109,
    OT_ERR_TOO_LONG = 200,
    OT_ERR_PHONEME = 201,
    OT_ERR_MERGE = 202,
    OT_ERR_WORK = 203,
    OT_ERR_FRAMES = 204
};

enum { OT_PHONEME_MAX = 2047, OT_UTF_COUNT = 0xB2 };

/* word_180034C18, word_180034C1C, qword_180034C10 */
extern uint16_t g_dev_mark;
extern uint16_t g_usr_mark;
extern uint64_t g_usr_material;

/* *out is a heap buffer the caller frees. There is no phoneme-count ceiling. */
int ot_parse_kana(const uint8_t *text, uint8_t **out, int *count);
void ot_pcm_clear(OtPcm *pcm);
void ot_write_wav_header(OtPcm *pcm);
int ot_speed_period(int speed);
