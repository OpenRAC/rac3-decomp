#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern void func_L01_004AA7E8(void *, s32);

/* declared by functions of L30_003501B0.c, which this file was cut from */
extern s32 D_L30_001DD740;

/* localdecomp:start func_L30_003502D0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003502D0;
typedef struct { u8 pad0[4]; s32 x4; } MV_003502D0;
typedef struct {
    u8 pad0[0x10]; V4_003502D0 x10;
    u8 pad20[0x68 - 0x20]; MV_003502D0 *x68;
} MM_003502D0;
typedef struct {
    u8 pad0[4]; s32 x4; u8 b8; u8 pad9; s16 hA; f32 xC; V4_003502D0 x10;
} A_003502D0;
typedef struct {
    MM_003502D0 *x0;
    s32 x4;
    s16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    f32 x10;
    f32 x14;
    f32 x18;
} B_003502D0;

__asm__(".extern D_L30_001DD740, 4");
extern s32 D_L30_001DD740;
__asm__(".extern D_L30_001DD82C, 4");
extern f32 D_L30_001DD82C;
__asm__(".extern D_L30_001DD830, 4");
extern f32 D_L30_001DD830;
__asm__(".extern D_L30_001DD834, 4");
extern f32 D_L30_001DD834;
__asm__(".extern D_L30_001DD838, 4");
extern f32 D_L30_001DD838;
__asm__(".extern D_L30_001DD83C, 4");
extern f32 D_L30_001DD83C;
__asm__(".extern D_L30_001DD840, 4");
extern f32 D_L30_001DD840;
__asm__(".extern D_L30_001DD844, 4");
extern f32 D_L30_001DD844;
__asm__(".extern D_L30_001DD850, 4");
extern s32 D_L30_001DD850;
__asm__(".extern D_L30_001DD81C, 4");
extern s32 D_L30_001DD81C;
__asm__(".extern D_L30_001DD828, 4");
extern f32 D_L30_001DD828;
__asm__(".extern D_L30_001DD810, 4");
extern s32 D_L30_001DD810[] __attribute__((section(".sdata")));

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);

void func_L30_003502D0(A_003502D0 *a, B_003502D0 *b) {
    MM_003502D0 *m;
    MV_003502D0 *v;
    f32 ang;
    f32 r;
    f32 t;
    f32 len;
    f32 d;
    f32 h;
    s32 n;
    f32 s;
    f32 sa;
    f32 sb;
    f32 lo;
    f32 hi;
    V4_003502D0 tmp;
    u16 e;
    f32 fb;
    f32 fa;
    s32 mode;
    s32 k;

    if (b == 0) {
        return;
    }
    m = b->x0;
    k = b->x4;
    v = m->x68;
    if (m == 0 || k == 0) {
        return;
    }
    if (b->hA & 1) {
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        r = func_003824E0(0.0f, D_L30_001DD82C);
        a->x10.x = func_0038D098(ang) * r;
        a->x10.z = func_0038D0B0(ang) * r;
        a->x10.y = 0.0f;
        vec_add_ba(&a->x10, &a->x10, &m->x10);
        t = func_L03_0034B440(1, 0, 0, v->x4 - D_L30_001DD740 + D_L30_001DD850, D_L30_001DD850 + 1, 1.0f);
        vec_sub_ba(&tmp, &a->x10, &m->x10);
        len = func_0038CEA8(&tmp);
        d = func_003C4088(D_L30_001DD830, D_L30_001DD834, t) - len;
        n = D_L30_001DD850;
        h = b->h8;
        b->x14 = ang;
        b->x10 = (d + d) / h;
        b->x18 = (d * -2.0f) / (h * h);
        if (D_L30_001DD740 - n / 3 < v->x4) {
            b->hE = b->hE & ~3;
        } else if (D_L30_001DD740 - n * 2 / 3 < v->x4) {
            b->hE = (b->hE & ~3) | 1;
        } else {
            b->hE = (b->hE & ~3) | 2;
        }
    }
    s = func_L03_0034B440(1, 0, 0, a->hA, b->h8, 1.0f);
    e = b->hE;
    fb = (e >> 9) * 0.0078125f;
    fa = ((e & 0x1FC) >> 2) * 0.0078125f;
    mode = e & 3;
    sa = func_003C4088(D_L30_001DD83C, D_L30_001DD838, fa);
    sb = sa * func_003C4088(D_L30_001DD844, D_L30_001DD840, fb);
    tmp.x = func_0038D098(b->x14) * b->x10;
    tmp.z = func_0038D0B0(b->x14) * b->x10;
    tmp.y = 0.0f;
    b->x10 += b->x18;
    vec_add_ba(&a->x10, &a->x10, &tmp);
    a->x4 = func_0038DBD8(D_L30_001DD810[mode], D_L30_001DD81C, s);
    lo = b->hC & 0xFF;
    hi = lo + (lo + D_L30_001DD828 * b->h8 * (b->hC >> 8) * 0.00390625f);
    a->b8 = func_003C4088(lo, hi, func_L03_0034B148(a->hA, b->h8, 0.0f));
    a->xC = func_003C4088(sa, sb, s);
}
/* localdecomp:end func_L30_003502D0 */

INCLUDE_ASM("asm/levels", func_L30_00350690);
