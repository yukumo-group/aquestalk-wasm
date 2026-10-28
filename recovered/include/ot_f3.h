/* f3-specific synthesis hooks.  The new f3 build is a different engine from
 * f1..dvd: its symbol table uses a new diphone vocabulary (_S, .K, .S, --,
 * __, @S) and classes 6..11.  Everything f3-specific lives in src/f3/. */
#pragma once

struct OtToken;

/* Post-process the classic token list for f3 (name remapping of the new
 * transition symbols).  Called from ot_tokens_from_phonemes when
 * voice->engine == OT_ENGINE_F3. */
void ot_f3_adjust_tokens(struct OtToken *tok, int *n);
