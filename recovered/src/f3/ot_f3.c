/*
 * f3 module.  The current f3 library is a redesigned engine: the kana are the
 * same, but the diphone vocabulary changed (".k" is gone, the table has
 * ".K/0" and ".S/4", "_S/7", "--/9", "__/10", "@S/8", class 6..11 additions)
 * and the class-2/3 blend arithmetic is 9-bit.  Keeping this here means the
 * classic path stays untouched.
 *
 * What is implemented: in a plain CV context the new build does not render a
 * ".k" transition, so the token is dropped (this alone makes the k/g/p/b/t/d
 * rows and the palatalised variants match).  The ".s"/".h"/".m" transitions
 * are still looked up with their old names and either fail (102) or take the
 * wrong frame count; the class 6..11 and 9-bit blend rules are the next step.
 */
#include "ot_f3.h"

#include "ot_synth.h"

void ot_f3_adjust_tokens(OtToken *tok, int *n)
{
    int i;
    int w = 0;
    for (i = 0; i < *n; i++) {
        if (tok[i].a == '.' && tok[i].b == 'k') {
            continue;
        }
        tok[w++] = tok[i];
    }
    *n = w;
}
