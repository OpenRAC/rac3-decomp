/* func_L05_0036BAD0: near miss (file L05_0036B268.c). 2 differences with -mvu0-use-vf0-vf2 and @ps2as once config/levels/divs_nops.txt has `func_L05_0036BAD0 2`: only the order of two independent lqc2 loads (retail loads s+0x20 for the first vec_add_ba before the s+0x30 copy); every order of the five setup statements and every ab/ba helper choice tried, adding the add before the copy swaps the VU registers (80+) */
#include "common.h"
#include "vu0.h"
extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L05_0036C2F0(void *, s32, void *, s32);

void func_L05_0036BAD0(void *a0, u8 *s) {
    vu0_v4 pts[17];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 r;
    vu0_v4 c;
    s32 i;

    for (i = 0; i < 16; i++) {
        *(vu0_q *)&a = *(vu0_q *)s;
        vec_copy(&c, s + 0x30);
        *(vu0_q *)&b = *(vu0_q *)(s + 0x10);
        vec_add_ba(&a, &a, s + 0x20);
        vec_add_ba(&b, &b, &c);
        func_L01_00445208(&pts[i], s + 0x20, s + 0x30, &a, &b, (f32)i / 15.0f);
        *(s32 *)&r.w = 0;
        r.x = func_003824E0(-1.0f, 1.0f);
        r.y = func_003824E0(-1.0f, 1.0f);
        r.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&r, &r, 0.075f);
        vec_add_ab(&pts[i], &pts[i], &r);
    }
    if (*(s32 *)(s + 0x98) >= 8) {
        func_L05_0036C2F0(a0, func_00382498(0x40, 0x80), pts, 0x11);
    } else {
        func_L05_0036C2F0(a0, func_00382498(0, 0x40), pts, 0x11);
    }
}
