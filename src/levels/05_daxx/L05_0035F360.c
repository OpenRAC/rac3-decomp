#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_0035F360);

INCLUDE_ASM("asm/levels", func_L05_0035F6E0);

INCLUDE_ASM("asm/levels", func_L05_00360070);

/* localdecomp:start func_L05_003601F0 */
extern void func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern f32 func_0038D160(f32, f32);

void func_L05_003601F0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x68);
    f32 d;
    *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * 0.5f;
    d = func_0038D160(*(f32 *)(q + 0x30) - *(f32 *)(p + 0x10), *(f32 *)(q + 0x34) - *(f32 *)(p + 0x14));
    {
        f32 k = 2.0943953132e-4f;
        func_L01_00448890(p + 0xF8, q + 0xAC, d, k, k, 0.02792526968f, 0);
    }
}
/* localdecomp:end func_L05_003601F0 */

INCLUDE_ASM("asm/levels", func_L05_00360280);

INCLUDE_ASM("asm/levels", func_L05_003602D0);

INCLUDE_ASM("asm/levels", func_L05_00360448);

INCLUDE_ASM("asm/levels", func_L05_00360730);

INCLUDE_ASM("asm/levels", func_L05_00360868);
