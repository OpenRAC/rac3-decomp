/* functional: high. Sibling of func_L04_00379D10 (same effect, fewer particles, different colours/range; 234 diffs, call order/args identical). */
#include "common.h"
#include "vu0.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003A9440(s32, unsigned long);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern u8 D_L04_001E2840[];
extern s32 D_001D545C;

void func_L04_0037A190(u8 *a0) {
    vu0_v4 p[2];
    vu0_v4 t;
    f32 sc, d2, ramp, ang, spd, lo, hi, step;
    u32 colA, colB, colC;
    s32 i;

    sc = func_L04_00379C68(a0);
    d2 = func_L01_0040E548(D_L04_001E2840, a0 + 0x10);
    if (D_001D545C == 0xB) {
        if (10200.0f < d2) return;
        lo = 215.0f;
        step = 0.025f;
        hi = 46225.0f;
    } else {
        if (1600.0f < d2) return;
        lo = 32.0f;
        step = 0.125f;
        hi = 1024.0f;
    }
    if (hi < d2) {
        ramp = (sqrt_asm(d2) - lo) * step;
        colA = func_0038DBD8(0x7FC00000, 0x7F000000, ramp);
        colB = func_0038DBD8(0xD00000, 0, ramp);
    } else {
        ramp = 0.0f;
        colA = 0x7FC00000;
        colB = 0xD00000;
    }
    func_003A9440(0x47, 0x53001);
    for (i = 2; i >= 0; i--) {
        f32 r1, r3;
        ang = func_00382538();
        spd = func_L01_00443A18(0.35f, 0.5f);
        func_0038CE20(&t, a0 + 0xC0, sc);
        vec_add_ab(&p[0], &t, a0 + 0x10);
        func_0038CE20(&t, a0 + 0xD0, func_0038D098(ang) * spd * 0.25f);
        vec_add_ba(&p[0], &p[0], &t);
        func_0038CE20(&t, a0 + 0xE0, func_0038D0B0(ang) * spd * 0.25f);
        vec_add_ba(&p[0], &p[0], &t);
        r1 = func_003824E0(1.0f, 1.5f);
        func_0038CE20(&t, a0 + 0xC0, r1);
        vec_add_ba(&p[1], &p[0], &t);
        func_0038CE20(&t, a0 + 0xD0, func_0038D098(ang) * spd);
        vec_add_ba(&p[1], &p[1], &t);
        func_0038CE20(&t, a0 + 0xE0, func_0038D0B0(ang) * spd);
        vec_add_ab(&p[1], &t, &p[1]);
        r3 = func_003824E0(0.1f, 0.2f);
        func_L01_0040A8C0(&p[0], &p[1], 0x2B, 1, colA, colA, colB, colB, r3, 3.5f, 0.0f);
    }
    func_0038CE20(&p[0], a0 + 0xC0, sc);
    vec_add_ba(&p[0], &p[0], a0 + 0x10);
    colC = func_0038DBD8(0x7FFF2020, 0x50FF2020, func_003824E0(0.0f, 1.0f));
    colC = func_0038DBD8(colC, 0x50000000, ramp);
    {
        f32 sz = func_003824E0(0.5f, 0.8f);
        f32 rot = func_00382538();
        func_003D9508(&p[0], 0x31, colC, 1, sz, 0.3f, rot);
    }
}
