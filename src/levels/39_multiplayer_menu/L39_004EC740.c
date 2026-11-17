#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EC740 */
s32 func_L39_004EC740(s32 *a0, s32 a1) {
    a0[6] = 3;
    if (a1 >= 0) {
        a0[16] += a1;
        return 0;
    }
    return a1;
}
/* localdecomp:end func_L39_004EC740 */
