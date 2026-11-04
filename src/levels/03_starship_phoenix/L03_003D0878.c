#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003D0878);

INCLUDE_ASM("asm/levels", func_L03_003D09C0);

INCLUDE_ASM("asm/levels", func_L03_003D0A28);

/* localdecomp:start func_L03_003D0E88 */
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);

void func_L03_003D0E88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 v = *(s32 *)(p + 0x68);

    v = v | 0x90;
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x30) = 0.3f;
    *(f32 *)(p + 0x64) = 0.2f;
    *(f32 *)(p + 0x3C) = *(f32 *)(p + 0x38) = 0.8f;
    *(f32 *)(p + 0x40) = 1.48352981f;
    *(f32 *)(p + 0x60) = 0.0872664626f;
    *(f32 *)(p + 0x5C) = 0.00392f;
    *(s32 *)(p + 0x68) = v;
    func_L01_0045BD78(a0, 0.064f, 0.20000002f, 0.01507964546f, 0.335103243f);
}
/* localdecomp:end func_L03_003D0E88 */
