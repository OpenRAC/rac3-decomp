#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003A97D8);

/* localdecomp:start func_L24_003A9A48 */
extern s32 D_L24_001DF0C0;
extern s32 D_L24_001DE438;
extern f32 D_L24_001DE444;
extern s32 D_L24_001DE430;
extern s32 D_L24_001DE434;
extern f32 D_L24_001DE460;
__asm__(".extern D_L24_001DE438, 4");
__asm__(".extern D_L24_001DE444, 4");
__asm__(".extern D_L24_001DE430, 4");
__asm__(".extern D_L24_001DE434, 4");
__asm__(".extern D_L24_001DE460, 4");
extern void func_003C2880(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);

typedef struct {
    u8 pad0[4];
    u8 *e[4];
    s32 t[4];
    f32 f[4];
    u8 pad34[0xC];
    f32 f40;
    u8 pad44[8];
    s32 w4C;
} S_003A9A48;

void func_L24_003A9A48(u8 *a0)
{
    S_003A9A48 *q = *(S_003A9A48 **)(a0 + 0x68);
    s32 i;
    f32 t;
    u32 c;

    for (i = 0; i < 4; i++) {
        if (q->e[i] != 0) {
            t = (f32)(D_L24_001DF0C0 - q->t[i]) / (f32)D_L24_001DE438;
            if (t > 1.0f) {
                func_003C2880(q->e[i]);
                q->e[i] = 0;
            } else {
                q->e[i][0x23] = D_L24_001DE444 * (1.0f - q->f40) * (1.0f - t);
                c = func_0038DBD8(D_L24_001DE430, D_L24_001DE434, q->f[i]);
                c = func_0038DBD8(q->w4C, c, q->f40 * t);
                func_L01_0043B9E8(q->e[i], c & 0xFF, (c & 0xFF00) >> 8, (c >> 16) & 0xFF);
                func_0038D308(q->e[i] + 0xC0, a0 + 0xF0);
                if (!(i & 1)) {
                    func_0038CE20(q->e[i] + 0xC0, q->e[i] + 0xC0, 1.0f - q->f40 * t);
                    func_0038CE20(q->e[i] + 0xE0, q->e[i] + 0xE0, q->f40 * D_L24_001DE460 * t + 1.0f);
                } else {
                    func_0038CE20(q->e[i] + 0xE0, q->e[i] + 0xE0, 1.0f - q->f40 * t);
                    func_0038CE20(q->e[i] + 0xC0, q->e[i] + 0xC0, q->f40 * D_L24_001DE460 * t + 1.0f);
                }
            }
        }
    }
}
/* localdecomp:end func_L24_003A9A48 */

INCLUDE_ASM("asm/levels", func_L24_003A9C10);

/* localdecomp:start func_L24_003A9E20 */
extern s32 D_L24_001DE43C;
extern f32 D_L24_001DE448;
__asm__(".extern D_L24_001DE43C, 4");
__asm__(".extern D_L24_001DE448, 4");
extern u8 D_L24_001E1750[] __attribute__((section(".sdata")));
extern u8 D_L24_001E1770[] __attribute__((section(".sdata")));
extern s32 D_L24_001E1790;
extern f32 func_003824E0(f32, f32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L24_00358FE8(u8 *);
extern void func_L24_003A9C10();

typedef struct {
    u8 pad0[4];
    s32 z[4];
    u8 pad14[0x50 - 0x14];
    f32 a[12];
} V_003A9E20;

void func_L24_003A9E20(u8 *a0) {
    V_003A9E20 *v = *(V_003A9E20 **)(a0 + 0x68);
    s32 i;

    if (D_L24_001DE43C == 0) {
        D_L24_001DE43C = 1;
        func_L03_0034B218(D_L24_001E1750, 100, 50, 2.2f, 4, func_L24_003A9C10);
    }
    v->a[0] = func_003824E0(0.0f, 1.0f);
    for (i = 1; i < 12; i++) {
        v->a[i] = (1.0f - (D_L24_001DE448 < v->a[i - 1] ? D_L24_001DE448 : v->a[i - 1])) - (D_L24_001DE448 < 1.0f - v->a[i - 1] ? D_L24_001DE448 : 1.0f - v->a[i - 1]);
        v->a[i] = func_003824E0(0.0f, v->a[i]);
        if (v->a[i - 1] - (D_L24_001DE448 < v->a[i - 1] ? D_L24_001DE448 : v->a[i - 1]) < v->a[i]) {
            v->a[i] += (D_L24_001DE448 < v->a[i - 1] ? D_L24_001DE448 : v->a[i - 1]) + (D_L24_001DE448 < 1.0f - v->a[i - 1] ? D_L24_001DE448 : 1.0f - v->a[i - 1]);
        }
    }
    func_L24_00358FE8(D_L24_001E1770);
    D_L24_001E1790 = 0x65;
    for (i = 3; i >= 0; i--) {
        v->z[i] = 0;
    }
}
/* localdecomp:end func_L24_003A9E20 */

/* localdecomp:start func_L24_003AA000 */
typedef struct { f32 x, y, z, w; } V_003AA000;
typedef struct {
    /* 0x00 */ V_003AA000 v[4];
    /* 0x40 */ u32 col[4];
    /* 0x50 */ u8 pad50[0x40];
} Q_003AA000;

extern Q_003AA000 D_L24_002832E0;
extern u8 D_L24_001E1770[] __attribute__((section(".sdata")));
__asm__(".extern D_L24_001DE44C, 4");
__asm__(".extern D_L24_001DE450, 4");
__asm__(".extern D_L24_001DE454, 4");
__asm__(".extern D_L24_001DE458, 4");
__asm__(".extern D_L24_001DE45C, 4");
__asm__(".extern D_L24_001DE464, 4");
extern f32 D_L24_001DE44C;
extern f32 D_L24_001DE450;
extern f32 D_L24_001DE454;
extern f32 D_L24_001DE458;
extern f32 D_L24_001DE45C;
extern f32 D_L24_001DE464;
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L24_00358F70(f32 *m, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void func_L24_00359020(void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L24_003AA000(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    s32 k;
    f32 a, b, t, h, x, y, w, frac;
    f32 *p;
    V_003AA000 *vp;
    u32 grey = 0x808080;

    for (i = 0; i < 12; i++) {
        a = (1.0f - D_L24_001DE458) * (f32)i * 0.125f;
        b = a + D_L24_001DE458;
        frac = *(f32 *)(v + 0x40);
        if (b < frac || frac < a) {
            continue;
        }
        p = (f32 *)(v + 0x50);
        p += i;
        t = (frac - a) / (b - a);
        h = D_L24_001DE450 + func_0038D0B0(func_0038DB48(*p * 3.1415927f)) * (D_L24_001DE44C - D_L24_001DE450);
        w = D_L24_001DE464 * *(f32 *)(obj + 0xC);
        x = func_003C4088(*(f32 *)(obj + 0x10) + w * -0.0009765f, *(f32 *)(obj + 0x10) + w * 0.0009765f, *p);
        y = func_003C4088(*(f32 *)(obj + 0x18) - D_L24_001DE454 * 0.5f * h,
                          *(f32 *)(obj + 0x18) + h + D_L24_001DE454 * 0.5f * h, t);
        for (k = 0; k < 4; k++) {
            vp = &D_L24_002832E0.v[k];
            vp->y = *(f32 *)(obj + 0x14);
            vp->w = 1.0f;
        }

        D_L24_002832E0.v[0].x = x - D_L24_001DE45C * 0.5f;
        D_L24_002832E0.v[1].x = x + D_L24_001DE45C * 0.5f;
        D_L24_002832E0.v[2].x = x - D_L24_001DE45C * 0.5f;
        D_L24_002832E0.v[3].x = x + D_L24_001DE45C * 0.5f;
        D_L24_002832E0.v[0].z = y + D_L24_001DE454 * 0.5f * h;
        if (*(f32 *)(obj + 0x18) + h < D_L24_002832E0.v[0].z) {
            D_L24_002832E0.v[0].z = *(f32 *)(obj + 0x18) + h;
        } else if (D_L24_002832E0.v[0].z < *(f32 *)(obj + 0x18)) {
            D_L24_002832E0.v[0].z = *(f32 *)(obj + 0x18);
        }
        D_L24_002832E0.v[1].z = y + D_L24_001DE454 * 0.5f * h;
        if (*(f32 *)(obj + 0x18) + h < D_L24_002832E0.v[1].z) {
            D_L24_002832E0.v[1].z = *(f32 *)(obj + 0x18) + h;
        } else if (D_L24_002832E0.v[1].z < *(f32 *)(obj + 0x18)) {
            D_L24_002832E0.v[1].z = *(f32 *)(obj + 0x18);
        }
        D_L24_002832E0.v[2].z = y - D_L24_001DE454 * 0.5f * h;
        if (*(f32 *)(obj + 0x18) + h < D_L24_002832E0.v[2].z) {
            D_L24_002832E0.v[2].z = *(f32 *)(obj + 0x18) + h;
        } else if (D_L24_002832E0.v[2].z < *(f32 *)(obj + 0x18)) {
            D_L24_002832E0.v[2].z = *(f32 *)(obj + 0x18);
        }
        D_L24_002832E0.v[3].z = y - D_L24_001DE454 * 0.5f * h;
        if (*(f32 *)(obj + 0x18) + h < D_L24_002832E0.v[3].z) {
            D_L24_002832E0.v[3].z = *(f32 *)(obj + 0x18) + h;
        } else if (D_L24_002832E0.v[3].z < *(f32 *)(obj + 0x18)) {
            D_L24_002832E0.v[3].z = *(f32 *)(obj + 0x18);
        }
        for (k = 3; k >= 0; k--) {
            D_L24_002832E0.col[k] = 0x80808080;
        }
        D_L24_002832E0.col[0] = grey;
        D_L24_002832E0.col[1] = grey;
        ((void (*)(f32 *, f32, f32, f32, f32, f32, s32))func_L24_00358F70)((f32 *)&D_L24_002832E0, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1);
        func_L24_00359020(D_L24_001E1770, &D_L24_002832E0);
        func_003D2DA0(&D_L24_002832E0, 0, 0);
    }
}
/* localdecomp:end func_L24_003AA000 */
