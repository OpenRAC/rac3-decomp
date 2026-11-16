/* func_L16_003DD860: 6 diff with --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (the file's own flags fail without -mvu0-use-vf0-vf2). Only the vf1/vf2 register roles of the two vadd.xyz pairs and the order of two sqc2 differ. NEEDS-FLAGS. */
#include "vu0.h"
extern void func_003A52A0(s32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382468(s32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L16_003E2518(void *, void *, s32, s32, s32, s32, s32, f32, f32);
extern u8 D_L16_001D66B0[8];
__asm__(".extern D_L16_001D66B0, 16");
extern s32 D_L16_001DF2B0;
__asm__(".extern D_L16_001DF2B0, 4");

void func_L16_003DD860(void *p, f32 a, f32 b) {
    u8 *self = p;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 c;
    s32 i;
    func_003A52A0(0, 0, self);
    a = a * 8.0f;
    b = b * 4.0f;
    for (i = 0; i < D_L16_001DF2B0; i++) {
        func_0038CE20(&w, self + 0xD0, func_003824E0(-a, a));
        func_0038CE20(&v, self + 0xC0, func_003824E0(-b, b));
        vec_add_ab(&w, &v, &w);
        func_0038CE20(&v, self + 0xE0, func_003824E0(0.0f, 1.0f) * 4.0f);
        vec_add_ab(&w, &v, &w);
        vec_copy(&c, self + 0x10);
        vec_add_ab(&w, &w, &c);
        if (func_00382468(2) == 0) {
            func_L02_00429840(self, &w, 5, 1, D_L16_001D66B0, 0x5060D6FF, 0, 0xB4, 2.0f, 3.0f, 2.75f, 4.25f);
        }
        func_L16_003E2518(self, &w, 0x50, 0x51, 0xA, 0, 2, 1.5f, 4.0f);
    }
}
