#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003A4E60);

INCLUDE_ASM("asm/levels", func_L24_003A5360);

/* localdecomp:start func_L24_003A53E8 */
void func_L24_003A53E8(u8 *a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6) {
    *(f32 *)(a0 + 0x10) = a1;
    *(f32 *)(a0 + 0x14) = a2;
    *(f32 *)(a0 + 0x18) = a3;
    *(f32 *)(a0 + 0x24) = a4;
    *(f32 *)(a0 + 0x28) = a5;
    *(f32 *)(a0 + 0x2C) = a6;
}
/* localdecomp:end func_L24_003A53E8 */

/* localdecomp:start func_L24_003A5408 */
extern void *D_L24_001A71A0[];
extern s32 func_L24_0042D128(void);

s32 func_L24_003A5408(void *a0, void *a1, u8 a2) {
    if (a1 != 0 && a0 == a1) {
        return 0;
    }
    if (a0 == 0 || a2 == 1) {
        return 1;
    }
    if (a2 == 0) {
        return func_L24_0042D128() != 0;
    }
    if (a2 == 3) {
        return a0 != D_L24_001A71A0[0];
    }
    return 0;
}
/* localdecomp:end func_L24_003A5408 */
