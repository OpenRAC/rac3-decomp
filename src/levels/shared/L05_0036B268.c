#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L05_0036B268);

INCLUDE_ASM("asm/levels", func_L05_0036B5E0);

INCLUDE_ASM("asm/levels", func_L05_0036B870);

/* localdecomp:start func_L05_0036BAD0 */
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
    vu0_q qc;
    s32 i;

    for (i = 0; i < 16; i++) {
        *(vu0_q *)&a = *(vu0_q *)s;
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(*(vu0_v4 *)(s + 0x30)));
        *(vu0_q *)&b = *(vu0_q *)(s + 0x10);
        vec_add_ba(&a, &a, s + 0x20);
        {
            vu0_q qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qc));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qr));
        }
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
/* localdecomp:end func_L05_0036BAD0 */

INCLUDE_ASM("asm/levels", func_L05_0036BC98);

INCLUDE_ASM("asm/levels", func_L05_0036BF28);
