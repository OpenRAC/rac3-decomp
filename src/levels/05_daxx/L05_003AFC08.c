#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003AFC08);

INCLUDE_ASM("asm/levels", func_L05_003AFF38);

INCLUDE_ASM("asm/levels", func_L05_003B00A8);

INCLUDE_ASM("asm/levels", func_L05_003B1100);

INCLUDE_ASM("asm/levels", func_L05_003B12E8);

INCLUDE_ASM("asm/levels", func_L05_003B1450);

INCLUDE_ASM("asm/levels", func_L05_003B15D0);

INCLUDE_ASM("asm/levels", func_L05_003B1778);

/* localdecomp:start func_L05_003B19E8 */
extern f32 func_0038DAB8(f32, f32);

void func_L05_003B19E8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 x = *(f32 *)(p + 0x27C);

    *(f32 *)(p + 0x280) = *(f32 *)(p + 0x284);
    *(f32 *)(p + 0x28C) = *(f32 *)(p + 0x290);
    *(f32 *)(p + 0x278) = x;
    *(f32 *)(a0 + 0xF8) = func_0038DAB8(x, 3.14159274f);
}
/* localdecomp:end func_L05_003B19E8 */

INCLUDE_ASM("asm/levels", func_L05_003B1A40);
