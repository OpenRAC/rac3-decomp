/* Level 06 shared (src/levels/shared/L06_*.c) draft, 2026-11-14. 16 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): retail keeps the constant 1 of the second branch in $s1 (compare and store) and does not fill the branch-likely slots with the second call's lw; the `one` local gets $s1 but the slots still fill and $s2/$s3 swap. */
#include "common.h"
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L06_00352410(u8 *, u8 *, s32);
s32 func_L06_00352500(u8 *a0, u8 *a1) {
    s32 r = 0;
    s32 one;
    if (func_L01_0044E1B8(*(void **)(a1 + 0x260), 9.0f) && *(s32 *)(a1 + 0x380) != 0) {
        if (*(s32 *)(a1 + 0x35C) > 0) {
            func_L06_00352410(a0, a1, 0);
            r = 1;
            *(s32 *)(a1 + 0x380) = 0;
        }
        *(s32 *)(a1 + 0x35C) -= 1;
    } else {
        one = 1;
        if (func_L01_0044E1B8(*(void **)(a1 + 0x260), 1.0f) && *(s32 *)(a1 + 0x380) != one) {
            if (*(s32 *)(a1 + 0x35C) > 0) {
                func_L06_00352410(a0, a1, 1);
                r = 1;
                *(s32 *)(a1 + 0x380) = one;
            }
            *(s32 *)(a1 + 0x35C) -= 1;
        }
    }
    return r;
}
