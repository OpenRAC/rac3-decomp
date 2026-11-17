/* PAL near miss (Codex wave 4): near miss: 2 words differ with the file's flags.
 * Replaces the earlier draft (PAL near miss (PR #10); 22 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 2).
 * Worker's note: 2 diff reproduced: final dsra32 before jr rather than delay slot; ee29 emits a two-instruction sign extension outside noreorder, assigned assembler leaves final nop; no flags_alt authorized; sister build/codex/pool/X4/pal_func_001206A0_rac2.c; best log ...
 */
#include "common.h"

/* localdecomp:start func_001206A0 */
int func_001206A0(long raw) {
    unsigned long bits = raw;
    long exponent = (long)((bits << 1) >> 53);
    exponent -= 1075;
    if (exponent < -53) return 0;
    if (exponent >= 13) return 9999;
    bits = (bits << 12) >> 12;
    bits |= 1UL << 52;
    if (exponent < 0) {
        exponent = -exponent;
        bits >>= (int)(exponent - 2);
        if ((bits & 3) == 3) bits = (bits >> 2) + 1;
        else bits >>= 2;
    } else {
        bits <<= (int)exponent;
    }
    { int result = bits; return result; }
}
/* localdecomp:end func_001206A0 */
