#include "common.h"

/* NTSC-U counterpart of func_L01_00491630 (src/levels/shared/L01_00491630.c): 8 -> 10 */
extern void func_L01_0048DE38(void);

/* localdecomp:start func_L01_0048DE38 */
extern s32 D_L01_001D8E50_0048DE38;
__asm__(".extern D_L01_001D8E50_0048DE38, 4");
extern s32 D_L01_001D8E28_0048DE38[4] __attribute__((section(".sdata")));
extern s32 D_L01_001D8E18_0048DE38[2];
__asm__(".extern D_L01_001D8E18_0048DE38, 8");
extern f32 D_L01_001DC128;
extern u8 D_L01_002EB398[];
extern void func_L01_0048E5D8(void);
extern void func_00389920(s32);
extern s32 func_0037DF98(s32);
extern s32 func_00389D18(s32, s32, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern void func_L01_0048E2F8(void *);
extern s32 func_003E2DE0(s32, s32);
extern void *func_003AED40(s32);
extern s32 func_003E31A8(s32, s32);
extern void func_L01_0048E948(void);
extern void func_L01_0048EC60(void);
extern void func_L01_00512D70(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern s32 func_L01_00513698(void);
extern s32 func_003B46F0(s32);
extern void func_L01_00494E68(void *, s32);

void func_L01_0048DE38(void) {
    s32 i;
    s32 s;
    f32 x;
    f32 r;
    f32 lo, hi;
    f32 a, b;

    D_L01_001D8E50_0048DE38 = 0;
    lo = 0.0f;
    hi = 0.49f;
    a = 6.0f;
    b = 11.0f;
    for (i = 0; i < 4; i++) {
        D_L01_001D8E28_0048DE38[i] = -1;
    }
    func_L01_0048E5D8();
    func_00389920(0);
    x = (f32)func_00389D18(func_0037DF98(0x107), -1, 1.2f) / D_L01_001DC128;
    if (hi < x) x = hi;
    x = (x - lo) / (hi - lo);
    r = func_003BEB48(a, b, x);
    if (b < r) r = b;
    else if (r < a) r = a;
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_0037DF98(0x107), 0xD0006, 0x124, 0xD0007, 0xCD5, r);
    func_003E3A80(0xD0009, func_0037DF98(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD0009, 1);
    func_003E3A80(0xD000A, func_0037DF98(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD000A, 1);
    func_003E34A0(0xD000B, 0xD0009, 0xD000A);
    func_L01_0048E2F8(D_L01_002EB398);
    func_003E2DE0(0x11, 0x1C0000);
    func_003E31A8(0x1C0003, (s32)func_003AED40(0));
    func_L01_0048E948();
    func_L01_0048EC60();
    func_L01_00512D70(0x1C0003, 0);
    func_003E3250(0x1C0003, 1, 10);
    s = func_003B46F0(func_L01_00513698());
    func_L01_00494E68((void *)s, D_L01_001D8E18_0048DE38[func_L01_00513698()]);
}
/* localdecomp:end func_L01_0048DE38 */
