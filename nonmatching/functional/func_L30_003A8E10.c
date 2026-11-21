/* functional: high. Compiles in L30 context (needs #include vu0.h before the file's D_L30_002A2560 extern); bytes differ only in scheduling/gp-vs-lui addressing of D_L30_001E1BC*; PAL differs from the NTSC draft: scaled call passes f14 (D_L30_001DEAC4) unscaled. */
/* localdecomp:start func_L30_003A8E10 */
#include "vu0.h"
__asm__(".extern D_L30_001DEAB0, 4");
__asm__(".extern D_L30_001DEAB4, 4");
__asm__(".extern D_L30_001DEAB8, 4");
__asm__(".extern D_L30_001DEABC, 4");
__asm__(".extern D_L30_001DEAC0, 4");
__asm__(".extern D_L30_001DEAC4, 4");
__asm__(".extern D_L30_001DEAC8, 4");
__asm__(".extern D_L30_001DEACC, 4");
__asm__(".extern D_L30_001DEAD8, 4");
__asm__(".extern D_L30_001DF2C0, 4");
__asm__(".extern D_L30_001E1BC0, 4");
__asm__(".extern D_L30_001E1BC4, 4");
__asm__(".extern D_L30_001E1BC8, 4");
__asm__(".extern D_L30_001E1BCC, 4");
extern u8 D_001A4BE0[], D_001A4C60[];
extern vu0_q D_L30_002A2560[];
extern s32 D_L30_001DEAB0, D_L30_001DEAB4, D_L30_001DF2C0;
extern f32 D_L30_001DEAB8, D_L30_001DEABC, D_L30_001DEAC0, D_L30_001DEAC4, D_L30_001DEAC8, D_L30_001DEACC, D_L30_001DEAD8;
extern f32 D_L30_001E1BC0, D_L30_001E1BC4, D_L30_001E1BC8, D_L30_001E1BCC;
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L30_003A9508(void *, void *, void *);
extern f32 func_L30_003A9928(s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern f32 func_L30_0034DA70(s32, f32, f32, f32);
void func_L30_003A8E10(u8 *m, vu0_v4 *out, vu0_v4 *input, u8 *other) {
    vu0_v4 orig, tmp, delta;
    f32 a, b, c, d, e, f, g, h;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *row, *row2;
    f32 *w;
    vu0_q *vec;
    s32 i, j, k;
    s32 state;

    *out = *input;
    *(f32 *)(v + 0x2C) = 0.0f;
    orig = *input;
    state = *(s32 *)(D_001A4BE0 + 0x25C4);
    if (state == 159 || state == 161 || state == 160) {
        return;
    }
    row = v + 0x30;
    row2 = row;
    w = (f32 *)(v + 0x4C);
    vec = D_L30_002A2560;
    for (i = 0; i < 32; i++, row += 0x20, row2 += 0x20, w += 8, vec++) {
        if (*(s32 *)row != -1 && func_L01_00456500(D_001A4C60, *(s32 *)row) && *w > 0.0f) {
            f32 weight, blend;
            func_L30_003A9508(row2, &tmp, vec);
            weight = *w * func_L30_003A9928(*(s32 *)row, D_001A4C60);
            blend = weight / (weight + *(f32 *)(v + 0x2C));
            func_0038CE20(&tmp, &tmp, blend);
            func_0038CE20(v + 0x10, v + 0x10, 1.0f - blend);
            vec_add_ab(v + 0x10, v + 0x10, &tmp);
            *(f32 *)(v + 0x2C) += weight;
        }
    }
    row = v + 0x30;
    vec = D_L30_002A2560;
    for (j = 0; j < 32; j++, row += 0x20, vec++) {
        if (*(s32 *)row != -1 && !func_L01_00456500(D_001A4C60, *(s32 *)row)) {
            *vec = *(vu0_q *)(v + 0x10);
        }
    }
    if (!func_L30_0034D8D8(D_001A4C60, D_L30_001DEAD8) || D_L30_001DF2C0 < 20) {
        *out = *(vu0_v4 *)(v + 0x10);
        *(s32 *)(v + 0x20) = 0;
        *(s32 *)(v + 0x24) = 0;
        *(s32 *)(v + 0x28) = 0;
    } else {
        func_L01_004482A0(&out->x, (f32 *)(v + 0x20), *(f32 *)(v + 0x10), D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC);
        func_L01_004482A0(&out->y, (f32 *)(v + 0x24), *(f32 *)(v + 0x14), D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC);
        func_L01_004482A0(&out->z, (f32 *)(v + 0x28), *(f32 *)(v + 0x18), D_L30_001DEAC8, D_L30_001DEAC4, D_L30_001DEACC);
    }
    if (D_L30_001DEAB0 && D_L30_001DF2C0 > 20) {
        u8 *hero = D_001A4BE0;
        f32 x, z, s;
        func_L30_0034CDC0(&a, &b, &c, &d, D_L30_001DEAB8);
        func_L30_0034CDC0(&e, &f, &g, &h, D_L30_001DEABC);
        x = out->x - (e + f) * 0.5f;
        z = out->z - (g + h) * 0.5f;
        tmp = *out;
        a += x; e += x; f += x; b += x;
        h += z; c += z; d += z; g += z;
        if (*(f32 *)(hero + 0x80) < a) {
            s = (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(0, *(f32 *)(hero + 0x80), e, a) + 1.0f;
            func_L01_004482A0(&out->x, (f32 *)(v + 0x20), out->x - (a - *(f32 *)(hero + 0x80)), s * D_L30_001DEAC8, D_L30_001DEAC4, s * D_L30_001DEACC);
        }
        if (*(f32 *)(hero + 0x88) < c && *(f32 *)(hero + 0x2F8) > 2.0f && *(s32 *)(hero + 0x25C4) != 161) {
            s = (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(0, *(f32 *)(hero + 0x88), g, c) + 1.0f;
            func_L01_004482A0(&out->z, (f32 *)(v + 0x28), out->z - (c - *(f32 *)(hero + 0x88)), s * D_L30_001DEAC8, D_L30_001DEAC4, s * D_L30_001DEACC);
        }
        if (b < *(f32 *)(hero + 0x80)) {
            s = (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(1, *(f32 *)(hero + 0x80), b, f) + 1.0f;
            func_L01_004482A0(&out->x, (f32 *)(v + 0x20), out->x + (*(f32 *)(hero + 0x80) - b), s * D_L30_001DEAC8, D_L30_001DEAC4, s * D_L30_001DEACC);
        }
        if (d < *(f32 *)(hero + 0x88)) {
            s = (D_L30_001DEAC0 - 1.0f) * func_L30_0034DA70(1, *(f32 *)(hero + 0x88), d, h) + 1.0f;
            func_L01_004482A0(&out->z, (f32 *)(v + 0x28), out->z + (*(f32 *)(hero + 0x88) - d), s * D_L30_001DEAC8, D_L30_001DEAC4, s * D_L30_001DEACC);
        }
        vec_sub_ab(&delta, out, &tmp);
        row = v + 0x30;
        vec = D_L30_002A2560;
        for (k = 0; k < 32; k++, row += 0x20, vec++) {
            if (*(s32 *)row != -1 && func_L01_00456500(D_001A4C60, *(s32 *)row)) {
                vec_add_ab(vec, vec, &delta);
            }
        }
    }
    if (D_L30_001DEAB4 && other && *(u8 **)(other + 0x68)) {
        *out = *(vu0_v4 *)(*(u8 **)(other + 0x68) + 0xC0);
        *(s32 *)(v + 0x20) = 0;
        *(s32 *)(v + 0x24) = 0;
        *(s32 *)(v + 0x28) = 0;
    }
    if (D_L30_001E1BC4 > 0.0f) { if (out->x < D_L30_001E1BC4) out->x = D_L30_001E1BC4; D_L30_001E1BC4 = 0.0f; }
    if (D_L30_001E1BC0 > 0.0f) { if (out->x > D_L30_001E1BC0) out->x = D_L30_001E1BC0; D_L30_001E1BC0 = 0.0f; }
    if (D_L30_001E1BCC > 0.0f) { if (out->z < D_L30_001E1BCC) out->z = D_L30_001E1BCC; D_L30_001E1BCC = 0.0f; }
    if (D_L30_001E1BC8 > 0.0f) { if (out->z > D_L30_001E1BC8) out->z = D_L30_001E1BC8; D_L30_001E1BC8 = 0.0f; }
    *input = *out;
    *(vu0_v4 *)v = *(vu0_v4 *)D_001A4C60;
}
/* localdecomp:end func_L30_003A8E10 */
