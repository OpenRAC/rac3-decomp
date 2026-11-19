/* functional: medium. Written from the PAL asm only. Draw callback of the Marcadia spawner object (the one registered by func_L04_0035A050): when the object is within the configured range of the world-table entry, builds a bolt-effect parameter block (colours blended with black by the fade, random size from a table, sizes scaled for slots 2/3 in variant 1) for each of its four slots whose midpoint is visible and in range and submits it through func_L01_0040B858, then draws the per-slot overlays (func_L04_0035C398) for slots in state 1, and finally one or two glow sprites at the object. Retail has the same logic; the sqrt is sqrt_asm. Unsure: the parameter block's field meanings (kept as raw offsets 0x30..0x7C of the local block as retail writes them); the constants 0xFF000000 / table words D_001DD4F8[n] / sizes D_L04_001DD508[n] are as retail reads them. */
#include "common.h"
#include "vu0.h"

extern s32 D_L04_001DF940;
extern f32 D_001DD4F0;
extern s32 D_001DD4F8[4];
extern f32 D_L04_001DD508[];
extern u8 D_L04_001E2840[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L01_00446630(void *, void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_L01_0040B858(void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_L04_0035C398(void *, s32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L04_0035C9C8(void *op) {
    u8 *o = op;
    u8 *m = *(u8 **)(o + 0x68);
    u8 *p, *q, *tab, *c;
    vu0_v4 vA, vB;          /* vA at sp+0x20 (w = radius), vB at sp+0x10 */
    vu0_v4 vC;              /* sp+0x80 */
    vu0_v4 v0;              /* sp+0x00 */
    struct {
        s32 w30, w34;
        f32 f38;
        s32 w3C, w40;
        f32 f44;
        f32 f48, f4C;
        f32 f50, f54, f58, f5C, f60;
        s32 w64;
        f32 f68, f6C;
        s32 w70, w74, w78, w7C;
    } B;
    f32 dist, d2, fade, k, rnd;
    s32 n, a, r;

    if (*(s32 *)(m + 0x18) == 0) {
        s32 t = *(s32 *)(m + 0x50 + 0x20);
        if (t != 1) {
            if (t != 2) return;
            if (D_L04_001DF940 - *(s32 *)(m + 0x50 + 0x24) >= 8) return;
        }
    }
    tab = D_L04_001E2840;
    dist = func_0038CF00(tab, o + 0x10);
    if ((f32)*(s16 *)(o + 0x32) < dist) return;

    B.w30 = 10;
    B.w34 = 8;
    B.f38 = 1.25f;
    B.f50 = 0.06f;
    B.f54 = 0.05f;
    B.f58 = 0.2f;
    B.f5C = 0.6f;
    B.f60 = 1.2f;
    B.w64 = 15;
    B.f68 = 15.0f;
    B.f6C = 20.0f;
    B.w70 = 0;
    B.w74 = 0;
    B.w78 = 0;
    B.w7C = 0x45;

    for (n = 0; n < 4; n++) {
        p = m + 0x50 + n * 0x30;
        func_L01_00446630(&v0, p, p + 0x10, tab);
        d2 = func_L01_0040E548(&v0, tab);
        if (D_001DD4F0 * D_001DD4F0 < d2) continue;
        func_0038CDF8(&vA, p, p + 0x10, 0.5f);
        vA.w = func_0038CF00(p, p + 0x10) * 0.5f;
        if (func_0038DC20(&vA, D_001DD4F0) == -1) continue;
        a = D_001DD4F8[n];
        B.w3C = a;
        B.w40 = func_0038DBD8(0.5f, 0xFF000000, a);
        if ((D_001DD4F0 - 4.0f) * (D_001DD4F0 - 4.0f) < d2) {
            fade = (sqrt_asm(d2) - (D_001DD4F0 - 4.0f)) * 0.25f;
            B.w3C = func_0038DBD8(fade, B.w3C, 0xFF000000);
            B.w40 = func_0038DBD8(fade, B.w40, 0xFF000000);
        }
        rnd = func_003824E0(1.0f, 1.0375f);
        B.f44 = D_L04_001DD508[n] * 0.225f * rnd;
        if (*(s32 *)(m + 0xA0) == 1 && (n == 2 || n == 3)) {
            B.f44 = B.f44 * 0.6f;
        }
        if (n == 0) {
            B.f48 = 0.5f;
            B.f4C = 0.55f;
        } else {
            B.f4C = 0.0f;
            B.f48 = 1.0f;
        }
        func_L01_0040B858(m + 0x50 + n * 0x30, &B);
    }
    func_003A9440(0x47, 0x513F1);
    for (n = 0; n < 4; n++) {
        if (*(s32 *)(m + 0x50 + n * 0x30 + 0x20) == 1) {
            func_L04_0035C398(m, n);
        }
    }
    if (dist < D_001DD4F0) {
        vA = *(vu0_v4 *)(o + 0x10);
        vA.w = 2.0f;
        if (func_0038DC20(&vA, D_001DD4F0) == -1) return;
        a = *(s32 *)(m + 0x20);
        if (a == -1) {
            k = 0.25f;
        } else if (a != 0) {
            k = 0.35f;
        } else {
            k = 0.45f;
        }
        func_0038CE20(&vB, o + 0xC0, k);
        vec_add_ab(&vB, &vB, o + 0x10);
        rnd = func_003824E0(1.0f, 1.0375f) * 0.45f;
        func_003D9508(&vB, 0x39, 0x302020FF, 1, rnd, 0.3f, func_00382538());
        if (*(s32 *)(m + 0x20) < 0) return;
        func_0038CE20(&vC, o + 0xC0, 0.35f);
        vec_add_ab(&vB, &vC, &vB);
        rnd = func_003824E0(1.0f, 1.0375f) * 0.337499976f;
        func_003D9508(&vB, 0x39, 0x302020FF, 1, rnd, 0.3f, func_00382538());
    }
}
