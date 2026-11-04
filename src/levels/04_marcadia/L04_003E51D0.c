#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003E51D0);

INCLUDE_ASM("asm/levels", func_L04_003E5250);

INCLUDE_ASM("asm/levels", func_L04_003E5788);

INCLUDE_ASM("asm/levels", func_L04_003E5898);

INCLUDE_ASM("asm/levels", func_L04_003E5940);

INCLUDE_ASM("asm/levels", func_L04_003E5D88);

INCLUDE_ASM("asm/levels", func_L04_003E5E78);

/* localdecomp:start func_L04_003E5FB8 */
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 D_001DF294;
extern f32 D_001DF298;

void func_L04_003E5FB8(u8 *arg0, f32 fparg0) {
    u8 *s0;
    f32 t;
    f32 x;

    s0 = *(u8 **)(arg0 + 0x68);
    t = func_0038DB00(fparg0, *(f32 *)(arg0 + 0xF0));
    x = *(f32 *)(s0 + 0x78);
    *(f32 *)(s0 + 0x78) = x + (t * D_001DF294 + x * D_001DF298);
    *(f32 *)(arg0 + 0xF0) = func_0038DAB8(*(f32 *)(arg0 + 0xF0), *(f32 *)(s0 + 0x78));
}
/* localdecomp:end func_L04_003E5FB8 */
