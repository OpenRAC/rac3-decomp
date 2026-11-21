#include "common.h"

/* NTSC-U counterpart of func_L01_0033D2B8 (src/levels/shared/L01_0033D2B8.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L01_0033CBC8 */
extern f32 D_L01_001DD018;
extern f32 func_0037E2A8(void);
extern f32 func_00389380(f32, f32);
extern void func_00389018(u8 *, s32, f32);
extern void func_L01_00437350(u8 *, s32, u8 *);

void func_L01_0033CBC8(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    f32 f;

    switch (a[0x20]) {
    case 0:
        a[0x20] = 1;
        a[0x63] = 0x20;
        *(f32 *)(s + 0x40) = func_0037E2A8();
        func_L01_00437350(a, 1, s);
        break;
    case 1:
        f = D_L01_001DD018 * 0.01745329238474369f * 0.0166666675f;
        *(f32 *)(a + 0xF8) = func_00389380(*(f32 *)(a + 0xF8), f);
        *(f32 *)(s + 0x40) = func_00389380(*(f32 *)(s + 0x40), f * -2.0f);
        func_00389018(s + 0x10, 2, *(f32 *)(s + 0x40));
        break;
    }
}
/* localdecomp:end func_L01_0033CBC8 */
