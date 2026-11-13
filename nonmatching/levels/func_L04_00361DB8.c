/* func_L04_00361DB8: near miss, 11 diff (file L04_00360D80.c). Every path returns 0; gcc folds the whole body to `return 0` after the first test, while retail keeps the three state tests (5, 8, 7) and two separate zero results. if/||/switch/result-variable forms all fold. */
#include "common.h"
s32 func_L04_00361DB8(u8 *a0) {
    s32 r = 0;
    if ((u32)(a0[0x20] - 0x12) >= 7) {
        u8 t = a0[0x95];
        if (t == 5 || t == 8 || t == 7) {
            r = 0;
        }
    }
    return r;
}
