#include "common.h"

/* localdecomp:start func_L32_0034A2D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 D_L32_001DD018;
extern s32 D_L32_001DD01C;
extern f32 D_L32_001DD020;
extern s32 D_L32_001DD024;
extern f32 D_L32_001DD028;
extern f32 D_L32_001DD02C;
extern f32 D_L32_001DD030;
extern f32 D_L32_001DD034;
extern f32 D_L32_001DD088;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(Vec4 *, Vec4 *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern void func_L01_004713C8(Vec4 *, Vec4 *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_L32_0034A2D0(u8 *m) {
    Vec4 v;
    Vec4 w;
    u8 *pv;
    s32 c;
    s32 r;

    pv = *(u8 **)(m + 104);
    *(f32 *)(pv + 28) += D_L32_001DD028;
    while (*(f32 *)(pv + 28) > 1.0f) {
        *(f32 *)(pv + 28) -= 1.0f;
        v.q = *(u128_t *)(m + 16);
        v.f[0] += func_003824E0(-D_L32_001DD088, 0.0f);
        v.f[2] += func_003824E0(-D_L32_001DD02C, D_L32_001DD02C);
        w.q = *(u128_t *)pv;
        func_0038CE20(&w, &w, D_L32_001DD034);
        c = func_L30_0034DBA0(D_L32_001DD018, D_L32_001DD01C);
        r = func_00382498(-4, 4);
        func_L01_004713C8(&v, &w, D_L32_001DD024, D_L32_001DD030, c, r, 128, 0, 0.0f, func_003824E0(-D_L32_001DD020, D_L32_001DD020), 0);
    }
}
/* localdecomp:end func_L32_0034A2D0 */

/* localdecomp:start func_L32_0034A428 */
void func_L32_0034A428(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    s32 i;
    for (i = 2; i >= 0; i--) {
        p[4 + i] = 0;
    }
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
}
/* localdecomp:end func_L32_0034A428 */

INCLUDE_ASM("asm/levels", func_L32_0034A460);
