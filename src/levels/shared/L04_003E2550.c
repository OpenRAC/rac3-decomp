#include "common.h"

/* localdecomp:start func_L04_003E2550 */
extern void func_L01_00456C98(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L04_003E2550(s32 a0, u8 *a1, s32 a2) {
    if (a2) {
        func_L01_00456C98(a0, *(s32 *)(a1 + 88), 0, 0, 1, 1, 3, 0, 0, 0,
                      *(f32 *)(a1 + 92), *(f32 *)(a1 + 92) + *(f32 *)(a1 + 92), 1.0f);
    } else {
        func_L01_00456C98(a0, *(s32 *)(a1 + 80), 0, 0, 1, 1, 3, 0, 0, 0,
                      *(f32 *)(a1 + 84), *(f32 *)(a1 + 84) + *(f32 *)(a1 + 84), 1.0f);
    }
    return *(s16 *)(a1 + 76) != 0;
}
/* localdecomp:end func_L04_003E2550 */

INCLUDE_ASM("asm/levels", func_L04_003E25F8);

INCLUDE_ASM("asm/levels", func_L04_003E26C8);

INCLUDE_ASM("asm/levels", func_L04_003E2818);
