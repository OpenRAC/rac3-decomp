#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003E51D0);

INCLUDE_ASM("asm/levels", func_L04_003E5250);

INCLUDE_ASM("asm/levels", func_L04_003E5788);

/* localdecomp:start func_L04_003E5898 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;

s32 func_L04_003E5898(u8 *a0, s32 a1) {
    u16 *p;
    u8 *e;
    p = D_L04_0021C9A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L04_001DFDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[a0[0x21]])) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (e[0x43] != a1) return 0;
    }
    return 1;
}
/* localdecomp:end func_L04_003E5898 */

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
