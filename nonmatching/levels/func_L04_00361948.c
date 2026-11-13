/* func_L04_00361948: near miss (file L04_00360D80.c). 5 differences once config/levels/divs_nops.txt has `func_L04_00361948 2` (74 without): only the two quadword copies `a = m[3]; b = m[0];` before func_L01_003A8CF0 — retail loads m[3] first into $v1, the C loads m[0] first (or, swapped, m[3] first into $v0); pointer locals, vu0_q casts, declaration orders tried */
#include "common.h"
#include "vu0.h"

extern void func_003C2EC0(void *, s32, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003A8CF0(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_003AEA58(void *, void *, void *, s32, f32);
extern s32 D_001D545C;
extern f32 D_L04_001DD6E4;
__asm__(".extern D_L04_001DD6E4, 4");

void func_L04_00361948(u8 *a0, u8 *a1, s32 n, s32 dd) {
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 g;
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;

    func_003C2EC0(*(void **)(a1 + 0x2FC), 0, m);
    func_003A52A0(0, 0, a0);
    a = m[3];
    b = m[0];
    func_L01_003A8CF0(a0, &a, &b, 0.649999976f);
    vec_sub_ba(&d, a1 + 0x220, &m[3]);
    func_0038CF68(&d, &d, D_L04_001DD6E4 * 0.0200000014f);
    if (*(s32 *)(a1 + 0x4E4) == 0) {
        if (func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(a1 + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(a1 + 0x224) - *(f32 *)(a0 + 0x14))) > 1.04719758f) {
            func_0038CF68(&d, &m[0], D_L04_001DD6E4 * 0.0200000014f);
        }
    }
    func_0038CF68(&e, &m[0], D_L04_001DD6E4 * 0.0200000014f);
    func_0038CDF8(&g, &d, &e, (f32)n / (f32)dd);
    if (D_001D545C == 0xD) {
        if (g.z < -0.17453292f) {
            g.z = -0.17453292f;
        }
    }
    func_003C2F58(*(void **)(a1 + 0x2FC), 0, &b);
    func_003C2F58(a0, 0, &a);
    if (func_003D3CB0(&a, &b, 0x10, a0, 0) == 0) {
        if (a1[0x5F] != 0) {
            func_L01_003AEA58(a0, &g, &m[3], 0x10001, a1[0x44]);
        } else {
            func_L01_003AEA58(a0, &g, &m[3], 1, a1[0x44]);
        }
    }
}
