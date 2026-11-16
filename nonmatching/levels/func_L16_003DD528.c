/* func_L16_003DD528: 22 diff with --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (the file's own flags fail: vf registers spilled without -mvu0-use-vf0-vf2). Only the vf1/vf2 roles of the first vadd and the retail order of the copy's sqc2 differ; the D_L16_001D66B0 needs the u8[8] + .extern 16 form. NEEDS-FLAGS. */
#include "vu0.h"
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_003C2880(void *);
extern u8 D_L16_001D66B0[8];
__asm__(".extern D_L16_001D66B0, 16");

void func_L16_003DD528(u8 *self) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    s32 i;
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 0xF, D_L16_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        i = 3;
        do {
            func_0038CE20(&b, self + 0xC0, func_003824E0(-1.0f, 1.0f) * 3.0f);
            func_0038CE20(&a, self + 0xE0, func_003824E0(-1.5f, 0.5f) * 3.0f);
            vec_add_ab(&b, &a, &b);
            vec_copy(&c, self + 0x10);
            vec_add_ab(&b, &b, &c);
            func_L02_00429840(self, &b, 10, 1, D_L16_001D66B0, 0x50D0E238, 0, 0xB4, 2.0f, 3.0f, 2.75f, 4.25f);
        } while (--i >= 0);
        func_003C2880(self);
    }
}
