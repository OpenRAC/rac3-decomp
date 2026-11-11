/* near miss (level 7, Annihilation Nation): 15 differences: register choice in the summing loop (retail sum in $t2, base built as addu $a0,$a3,$a0) and the exit block order; tried pointer and index forms of the sum (3 wordings) */
#include "common.h"

/* localdecomp:start func_L07_00333D70 */
s32 func_L07_00333D70(s32 off, s32 lim, s32 n, u8 *buf) {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        sum += buf[off + i];
        if (sum > lim) return (s32)&buf[i];
    }
    return -1;
}
/* localdecomp:end func_L07_00333D70 */
