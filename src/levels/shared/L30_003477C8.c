#include "common.h"

/* declared by functions of L30_003468C8.c, which this file was cut from */
extern void func_L30_0034CB68(u8 *, void *, int, int, int, int, f32, f32);

/* localdecomp:start func_L30_003477C8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003477C8;
extern s32 D_001D545C;
extern V_003477C8 D_001A4C60;
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L30_00348240(u8 *);
extern void func_L30_003478F0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
void func_L30_003477C8(u8 *m) {
    u8 *v;
    V_003477C8 d;
    s32 t;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] != 0x42 && func_L30_0034D8D8(m + 0x10, 1.4f)) {
        t = D_001D545C;
        if (t == 0x22 || t == 0x1E) {
            func_L30_00348240(m);
            t = D_001D545C;
        }
        if (t == 0x23) {
            func_L30_003478F0(m);
        }
    }
    if ((u8)(m[0x20] - 1) < 2) {
        vec_sub_ba(&d, &D_001A4C60, m + 0x10);
        func_L30_0034CB68(m, &d, 1, -1, (int)(m + 0x10), 1, 20.0f, *(f32 *)(v + 0x40));
    }
    if (func_L30_0034D8D8(m + 0x10, 1.5f) == 0 && m[0x20] == 2) {
        if (*(s32 *)(v + 0x68) & 1) {
            func_L01_004450F0(m, 0x42, -1);
        }
    }
}
/* localdecomp:end func_L30_003477C8 */

/* localdecomp:start func_L30_003478F0 */
#include "vu0.h"

extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern void func_L30_0034C958(void *, f32);
extern void func_L30_0034C8A8(void *, void *);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

extern f32 D_L30_001DD150[] __attribute__((section(".sdata"))); __asm__(".extern D_L30_001DD150, 8");
extern s32 D_L30_001DD0A0; __asm__(".extern D_L30_001DD0A0, 4");
extern s32 D_L30_001DD12C; __asm__(".extern D_L30_001DD12C, 4");
extern s32 D_L30_001DD120; __asm__(".extern D_L30_001DD120, 4");
extern f32 D_L30_001DD0A4; __asm__(".extern D_L30_001DD0A4, 4");
extern f32 D_L30_001DD0A8; __asm__(".extern D_L30_001DD0A8, 4");
extern s32 D_L30_001DD094; __asm__(".extern D_L30_001DD094, 4");
extern s32 D_L30_001DD098; __asm__(".extern D_L30_001DD098, 4");
extern s32 D_L30_001DD09C; __asm__(".extern D_L30_001DD09C, 4");
extern f32 D_L30_001DD0AC; __asm__(".extern D_L30_001DD0AC, 4");
extern f32 D_L30_001DD0B0; __asm__(".extern D_L30_001DD0B0, 4");
extern f32 D_L30_001DD088; __asm__(".extern D_L30_001DD088, 4");
extern f32 D_L30_001DD08C; __asm__(".extern D_L30_001DD08C, 4");
extern f32 D_L30_001DD0B8; __asm__(".extern D_L30_001DD0B8, 4");
extern f32 D_L30_001DD0BC; __asm__(".extern D_L30_001DD0BC, 4");
extern s32 D_L30_001DD080; __asm__(".extern D_L30_001DD080, 4");
extern s32 D_L30_001DD084; __asm__(".extern D_L30_001DD084, 4");
extern f32 D_L30_001DD0B4; __asm__(".extern D_L30_001DD0B4, 4");
extern s32 D_L30_001DD07C; __asm__(".extern D_L30_001DD07C, 4");
extern s32 D_L30_001DD184; __asm__(".extern D_L30_001DD184, 4");
/* a texture pick: which table and which byte in it */
typedef struct { s32 idx; s32 off; } P_003478F0;
extern P_003478F0 D_L30_001DD188;
extern P_003478F0 D_L30_001DD190;
extern s32 D_L30_001DF2C0;
__asm__(".extern D_L30_001DF2C0, 16");
extern u8 *D_L30_0021F098[];
extern u8 D_L30_001E11C8_003478F0[] __attribute__((section(".sdata")));

void func_L30_003478F0(u8 *p) {
    u8 *s;
    f32 *a;
    f32 *b;
    s32 i;
    s32 n;
    s32 c;
    s32 d;
    s32 k;
    f32 t;
    f32 rad;
    f32 f;
    f32 g;
    f32 h;
    u8 *r;
    vu0_v4 v __attribute__((aligned(16)));
    vu0_v4 w __attribute__((aligned(16)));

    s = *(u8 **)(p + 0x68);
    a = (f32 *)(s + 0x58);
    b = D_L30_001DD150;
    for (i = 2; i >= 0; i--) {
        t = *a + *b++;
        *a++ = t - cvtsw_asm(cvtws_asm(t));
    }
    for (n = 0; n < D_L30_001DD0A0; n++) {
        qzero(&v);
        rad = func_003C4088(D_L30_001DD0A8, D_L30_001DD0A4,
                          func_L03_0034B440(1, 0, 5, D_L30_001DF2C0 + D_L30_001DD12C + *(s32 *)(s + 0x54) - D_L30_001DD120,
                                            D_L30_001DD12C, 1.0f));
        func_L30_0034C958(&v, rad);
        f = rad * rad - v.x * v.x - v.z * v.z;
        f = sqrt_asm(f);
        v.y -= f;
        vec_add_ba(&v, &v, p + 0x10);
        c = func_00382498(D_L30_001DD098, D_L30_001DD094);
        d = func_00382498(-D_L30_001DD09C, D_L30_001DD09C);
        g = func_003824E0(D_L30_001DD0B0, D_L30_001DD0AC);
        h = func_003824E0(D_L30_001DD08C, D_L30_001DD088);
        f = func_003824E0(D_L30_001DD0BC, D_L30_001DD0B8) * *(f32 *)(s + 0x50);
        w.x = func_0038D098(func_0038DB48(*(f32 *)(s + 0x48) + (*(s32 *)(s + 0x4C) ? 1.5707963705062866f : -1.5707963705062866f))) * f;
        w.z = func_0038D0B0(func_0038DB48(*(f32 *)(s + 0x48) + (*(s32 *)(s + 0x4C) ? 1.5707963705062866f : -1.5707963705062866f))) * f;
        w.y = 0;
        k = func_0038DBD8(func_003824E0(w.y, 1.0f), D_L30_001DD080, D_L30_001DD084);
        r = func_L01_00475C60(&v, &w, c, d, k, D_L30_001DD07C, g, g / D_L30_001DD0B4, h, 0);
        if (r != 0) {
            if (func_00382498(0, 2) == 0) {
                r[2] = D_L30_0021F098[D_L30_001DD188.idx][D_L30_001DD188.off];
            } else {
                r[2] = D_L30_0021F098[D_L30_001DD190.idx][D_L30_001DD190.off];
            }
            if (func_00382498(0, D_L30_001DD184) == 0) {
                r[3] = 0x44;
            } else {
                r[3] = 0x48;
            }
        }
    }
    func_L30_0034C8A8(D_L30_001E11C8_003478F0, p);
}
/* localdecomp:end func_L30_003478F0 */

INCLUDE_ASM("asm/levels", func_L30_00347C20);

/* localdecomp:start func_L30_00347EF0 */
__asm__(".extern D_L30_001DD004, 4");
__asm__(".extern D_L30_001DD008, 4");
__asm__(".extern D_L30_001DD00C, 4");
__asm__(".extern D_L30_001DD04C, 4");
__asm__(".extern D_L30_001DD050, 4");
__asm__(".extern D_L30_001DD06C, 4");
__asm__(".extern D_L30_001DD070, 4");
__asm__(".extern D_L30_001DD12C, 4");
extern f32 D_L30_001DD004;
extern f32 D_L30_001DD008;
extern s32 D_L30_001DD00C;
extern s32 D_L30_001DD04C;
extern s32 D_L30_001DD050;
extern f32 D_L30_001DD06C;
extern s32 D_L30_001DD070;
extern s32 D_L30_001DD12C;
/* the record func_L03_0034B218 fills (its S_34B218) */
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    void *w14;
} S_00347EF0;
extern S_00347EF0 D_L30_001E11C8 __attribute__((section(".sdata")));
extern s32 func_00382498(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L30_00347C20(u8 *, u8 *);

void func_L30_00347EF0(u8 *moby) {
    u8 *v = *(u8 **)(moby + 0x68);
    s32 t = D_L30_001DD12C;
    f32 r = *(f32 *)(moby + 0x2C) / *(f32 *)(*(u8 **)(moby + 0x24) + 0x24);
    f32 x = D_L30_001DD004 * r;
    f32 y = D_L30_001DD008 * r;
    f32 z = *(f32 *)(v + 0x50) * r;
    *(f32 *)(v + 0x40) = x;
    *(f32 *)(v + 0x50) = z;
    *(f32 *)(v + 0x44) = y;
    *(s32 *)(v + 0x54) = func_00382498(0, t);
    *(s32 *)(v + 0x64) = -1;
    *(s32 *)(moby + 0x98) = 0;
    *(u16 *)(moby + 0x34) = (*(u16 *)(moby + 0x34) | 0x41) & ~0x1000;
    func_L01_004AA7E8(moby, 1);
    if (D_L30_001DD00C == 0) {
        D_L30_001DD00C = 1;
        func_L03_0034B218((u8 *)&D_L30_001E11C8, D_L30_001DD04C, D_L30_001DD050, D_L30_001DD06C, D_L30_001DD070, (void *)func_L30_00347C20);
    }
}
/* localdecomp:end func_L30_00347EF0 */

/* localdecomp:start func_L30_00347FC8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x40];
    f32 f40;
    u8 pad44[4];
    f32 f48;
    s32 f4C;
    f32 f50;
} V_00347FC8;

extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern vu0_v4 D_L30_001E9020;

void func_L30_00347FC8(u8 *moby) {
    V_00347FC8 *v = *(V_00347FC8 **)(moby + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;

    a.x = func_0038D098(func_0038DB48(v->f48 + (v->f4C ? 1.5707964f : -1.5707964f))) * v->f40;
    a.z = func_0038D0B0(func_0038DB48(v->f48 + (v->f4C ? 1.5707964f : -1.5707964f))) * v->f40;
    a.y = 0.0f;
    c = a;
    func_0038CF68(&a, &a, v->f40);
    func_0038CF68(&b, &a, v->f50);
    func_0038CF68(&d, &a, v->f40 + v->f40);
    vec_add_ba(&c, &a, &b);
    vec_add_ab(&a, moby + 0x10, &a);
    vec_add_ab(&c, moby + 0x10, &c);
    vec_add_ab(&d, moby + 0x10, &d);
    if (func_003D3CB0(&a, &c, 0x12, moby, 0)) {
        func_0038CF68(&b, &b, func_0038CF00(&a, &D_L30_001E9020));
        v->f48 = v->f48 + (v->f4C ? 1.5707964f : -1.5707964f);
    }
    vec_add_ab(moby + 0x10, moby + 0x10, &b);
}
/* localdecomp:end func_L30_00347FC8 */
