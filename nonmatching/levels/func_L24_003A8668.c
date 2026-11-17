/* func_L24_003A8668: 13 diff with the file's flags (+ -mvu0-use-vf0-vf2, needed for vu0.h). Only the vadd.xyz register numbers differ (retail vf2 = vf2 + vf1 with v in vf2, mine vf1 = vf1 + vf2), plus the mul.s/sub.s/andi scheduling that follows from it. Tried vec_add_ab/ba, inline j-form asm in both load orders, separate result pseudo, declaration orders. */
#include "vu0.h"
extern u8 D_L24_001E2200[];
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00446780(void *, f32, void *, s32, f32, f32, s32, s32, s32);

void func_L24_003A8668(u8 *a0) {
    vu0_v4 v;
    f32 w[4] __attribute__((aligned(16)));
    f32 f;
    s32 i;
    s32 c, r, b, a, d, e;
    s32 ten = 10;
    u8 *dd = D_L24_001E2200;
    *(f32 *)(dd + 0x20) = 0.075f;
    *(s32 *)(dd + 0x28) = 33;
    *(s32 *)(dd + 0x2C) = 0;
    for (i = 0; i < 90; i++) {
        qzero(&v);
        func_003C4C18(&v, 1.5f);
        f = fabs_asm(v.x);
        f += fabs_asm(v.y);
        vec_add_ba(&v, a0 + 0x10, &v);
        f *= 0.5f;
        f = 1.5f - f;
        w[0] = func_003824E0(-1.0f, 1.0f) * 0.020000001f;
        w[1] = func_003824E0(-1.0f, 1.0f) * 0.020000001f;
        w[2] = func_003824E0(4.0f, (f *= 6.5f) + 5.0f) * 0.020000001f;
        r = func_00382468(200) & 0xFF;
        c = 200;
        if (func_00382468(2) == 0) {
            c = 0xFF;
        }
        b = func_00382468(128) + 100;
        a = (b << 24) | (ten << 16) | (r << 8) | c;
        d = func_00382468(10) + 30;
        e = func_00382468(50) + 50;
        func_L01_004637C8(&v, w, a, 0, d, e, func_00382468(50) + 250, i & 1);
    }
    func_L01_00446780(a0, 2.0f, a0 + 0x10, 0x10000, 10.0f, 1.0f, 0, 1, 0);
}
