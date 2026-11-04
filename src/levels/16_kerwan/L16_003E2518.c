#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_003E2518);

/* localdecomp:start func_L16_003E2578 */
extern void func_L01_00439880(u8 *, u16 *, u16 *);
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L16_003E2638(u8 *, s32);

void func_L16_003E2578(u8 *a0) {
    u8 *s;
    u16 x;
    s32 w;
    s32 r;
    s32 t;

    t = a0[0x20];
    s = *(u8 **)(a0 + 0x68);
    if (t != 1) {
        if (t < 2) {
            if (t == 0) {
                func_L01_00439880(a0, &x, (u16 *)&w);
                *(u16 *)(a0 + 0x7C) = x;
                *(u16 *)(s + 4) = *(u16 *)(s + 0x40);
                *(f32 *)s = (f32)*(s32 *)(s + 0x40);
                *(u16 *)(s + 0x36) = *(u16 *)&w;
                func_L01_004450F0(a0, 1, -1);
            }
        }
    } else {
        r = func_L01_00447490(a0, 1, 1);
        if (r != 0) {
            func_L16_003E2638(a0, r);
        }
    }
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L16_003E2578 */

INCLUDE_ASM("asm/levels", func_L16_003E2638);

INCLUDE_ASM("asm/levels", func_L16_003E26E8);

INCLUDE_ASM("asm/levels", func_L16_003E2B18);

INCLUDE_ASM("asm/levels", func_L16_003E2C28);

INCLUDE_ASM("asm/levels", func_L16_003E2C88);

INCLUDE_ASM("asm/levels", func_L16_003E2E30);

INCLUDE_ASM("asm/levels", func_L16_003E3068);
