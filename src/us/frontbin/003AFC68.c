#include "common.h"

extern void *func_U_003AED40(s32);

extern s32 D_U_001D89EC;
extern s32 D_U_001D8A14;
extern u8 D_U_0037B8D0[];
extern f32 D_U_001D96D8;
extern void func_U_003B0580();
extern void func_U_00389920(s32);
extern s32 func_U_0037DF98();
extern s32 func_U_00389D18(f32, s32, s32);
extern f32 func_U_003BEB48(f32, f32, f32);
extern void func_U_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_U_003E2C88(s32, f32, f32);
extern void func_U_003B02A0();
extern s32 func_U_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_U_003E23C0(s32, s32, s32);
extern s32 func_U_003E22D0(s32, s32, s32);
extern s32 func_U_003E30C8(s32, s32);
extern s32 func_U_003E2DE0(s32, s32);
extern s32 func_U_003E24B0(s32, s32);
extern s32 func_U_003E31A8(s32, s32);
extern s32 func_U_003E28E0(s32, s32);
extern s32 func_U_003E3250(s32, s32, s32);
extern void func_U_003B07B8();
/* localdecomp:start func_U_003AFC68 */
__asm__(".extern D_U_001D89EC, 4");
__asm__(".extern D_U_001D8A14, 4");
extern void func_U_003B0A60(void);
void func_U_003AFC68(void) {
    s32 flag = 0;
    f32 lim = 0.49f;
    f32 scale = 0.0f;
    f32 base = 0.0f;
    f32 lo = 6.0f;
    f32 hi = 11.0f;
    f32 x, y;
    D_U_001D89EC = -1;
    D_U_001D8A14 = 0;
    func_U_003B0580();
    func_U_00389920(0);
    x = (f32)func_U_00389D18(1.2f, func_U_0037DF98(0x107), -1) / D_U_001D96D8;
    if (lim < x) {
        flag = 1;
        scale = 0.588000059f / x;
        x = lim;
    }
    y = func_U_003BEB48(lo, hi, (x - base) / lim);
    if (hi < y) y = hi;
    else if (y < lo) y = lo;
    func_U_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, y, 0xD0008, func_U_0037DF98(0x107), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    if (flag) func_U_003E2C88(0xD0005, scale, scale);
    func_U_003B02A0(D_U_0037B8D0);
    func_U_003E3A80(0x1C0004, func_U_0037DF98(0x1EBD), 0x8066CCFF, 0.5f, 0.932f, 0.9f, 0.9f);
    func_U_003E23C0(0x1C0004, 3, 3);
    func_U_003E22D0(0x1C0004, 0x2040, 1);
    func_U_003E30C8(0x1C0000, 0x1C0004);
    func_U_003E2DE0(0x11, 0x1C0000);
    func_U_003E24B0(0x1C0003, 0);
    func_U_003E31A8(0x1C0003, func_U_003AED40(0));
    func_U_003E28E0(0x1C0003, 5);
    func_U_003E3250(0x1C0003, 1, 10);
    func_U_003B07B8();
    func_U_003B0A60();
}
/* localdecomp:end func_U_003AFC68 */
