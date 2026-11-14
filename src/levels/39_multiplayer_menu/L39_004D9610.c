#include "common.h"

/* localdecomp:start func_L39_004D9610 */
s32 func_L39_004B5748(s32, s32);

s32 func_L39_004D9610(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = func_L39_004B5748(arg0, arg2);
    s32 n = ret;

    if (ret < 0) {
        return ret;
    }
    ret = arg1;
    ret ^= n;
    ret = ret ? -0x6A : n;
    return ret;
}
/* localdecomp:end func_L39_004D9610 */

INCLUDE_ASM("asm/levels", func_L39_004D9650);

INCLUDE_ASM("asm/levels", func_L39_004D98F8);
