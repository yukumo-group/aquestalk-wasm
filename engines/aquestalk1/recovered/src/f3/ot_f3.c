/*
 * f3 module.  The current f3 library is a redesigned engine: the kana are the
 * same, but the diphone vocabulary changed and the expander grew classes
 * 6..11.  The token stream was captured from the .so with gdb (the expander
 * function FUN_0010a524 receives the token list); for a plain CV mora it is:
 *
 *   vowel-initial : "..", ".a", "a.", ".."
 *   consonant     : ".K"/".S"/".n"/".r"/".z"/".y"/".v"/".q", <pair>, <vowel>, ".."
 *   sokuon        : "..", ".q", "..", ".."
 *   long vowel    : "..", "..", "..", ".."
 *
 * The classic builder produces the same tokens but with the leading ".."
 * prelude kept and the old transition names (".k", ".s", ".-", "+q"), so this
 * module rewrites the list in place.
 */
#include "ot_f3.h"

#include "ot_synth.h"

#include <string.h>

static int f3_is_transition(const OtToken *t)
{
    return t->a == '.' && t->b != '.' && t->b != 'a' && t->b != 'i' &&
           t->b != 'u' && t->b != 'e' && t->b != 'o' && t->b != 'x';
}

void ot_f3_adjust_tokens(OtToken *tok, int *n)
{
    int i;

    /* フュ has no dot transition of its own; the .so uses ".S". */
    if (*n >= 2 && tok[0].a == '.' && tok[0].b == '.' && tok[1].a == 'F') {
        tok[0].a = '.';
        tok[0].b = 'S';
    }

    /* The .so starts a consonant mora with the transition, not with "..". */
    if (*n >= 2 && tok[0].a == '.' && tok[0].b == '.' && f3_is_transition(&tok[1])) {
        for (i = 1; i < *n; i++) {
            tok[i - 1] = tok[i];
        }
        (*n)--;
    }

    /* The .so always ends with the boundary pair; single-phoneme inputs get
     * an extra ".." that the classic builder does not add. */
    while (*n < 4 && *n > 0) {
        tok[*n].pitch = 0;
        tok[*n].a = '.';
        tok[*n].b = '.';
        (*n)++;
    }

    for (i = 0; i < *n; i++) {
        if (tok[i].a == '.' && tok[i].b == 'k') {
            tok[i].b = 'K';
        } else if (tok[i].a == '.' && tok[i].b == 's') {
            tok[i].b = 'S';
        } else if (tok[i].a == '+' && tok[i].b == 'q') {
            tok[i].a = '.';
            tok[i].b = 'q';
        } else if (tok[i].a == '.' && tok[i].b == '-') {
            tok[i].b = '.';
        }
    }
}
