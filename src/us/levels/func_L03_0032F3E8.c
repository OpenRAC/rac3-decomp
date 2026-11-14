#include "common.h"

/* localdecomp:start func_L03_0032F3E8 */
/* Converts a frame count to minutes and seconds (dividing by 60 twice, rounding up) and writes them
 * through the two pointers. */
void func_L03_0032F3E8(s32 value, s32 *minutes, s32 *seconds) {
    s32 total;
    s32 quotient;

    total = (value + 0x3B) / 60;
    quotient = total / 60;
    *seconds = total;
    *minutes = quotient;
    *seconds -= quotient * 60;
}
/* localdecomp:end func_L03_0032F3E8 */
