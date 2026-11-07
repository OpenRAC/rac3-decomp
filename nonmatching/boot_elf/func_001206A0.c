/* Near miss of func_001206A0: tools/check.py reports 22 diff.
   What differs: the structure is
   right (exponent from the double's bits, mantissa, rounding by shifting), but the registers of
   the argument copy and the exponent are swapped: retail copies `$a0` to `$a1` and keeps the
   exponent in `$a2`, the C has them the other way round. */
#include "common.h"
s32 func_001206A0(u64 arg) {
    s64 e;
    u64 x;
    x = arg;
    e = ((x << 1) >> 53);
    e -= 0x433;
    if (e < -0x35) return 0;
    if (e >= 0xd) return 9999;
    x = ((x << 12) >> 12) | 0x10000000000000ULL;
    if (e < 0) {
        e = -e;
        x >>= (s32)(e - 2);
        if ((x & 3) == 3) x = (x >> 2) + 1; else x >>= 2;
    } else {
        x <<= (s32)e;
    }
    return (s32)x;
}
