#include "common.h"

/* declared by functions of L31_003A06D0.c, which this file was cut from */
extern s32 func_0038DBD8(f32, s32, s32);

/* localdecomp:start func_L31_003A0D30 */
#include "vu0.h"
__asm__(".extern D_L31_001DE6EC, 4");
extern s32 D_L31_001DE6EC;
__asm__(".extern D_L31_001DE72C, 4");
extern f32 D_L31_001DE72C;
__asm__(".extern D_L31_001DE710, 4");
extern f32 D_L31_001DE710;
__asm__(".extern D_L31_001DE714, 4");
extern f32 D_L31_001DE714;
__asm__(".extern D_L31_001DE71C, 4");
extern s32 D_L31_001DE71C;
__asm__(".extern D_L31_001DE720, 4");
extern s32 D_L31_001DE720;
__asm__(".extern D_L31_001DE764, 4");
extern s32 D_L31_001DE764;
__asm__(".extern D_L31_001DE724, 4");
extern f32 D_L31_001DE724;
__asm__(".extern D_L31_001DE728, 4");
extern f32 D_L31_001DE728;
__asm__(".extern D_L31_001DE718, 4");
extern f32 D_L31_001DE718;
__asm__(".extern D_L31_001DE730, 4");
extern s32 D_L31_001DE730;
__asm__(".extern D_L31_001DE75C, 1");
extern u8 D_L31_001DE75C;
__asm__(".extern D_L31_001DE704, 4");
extern f32 D_L31_001DE704;
__asm__(".extern D_L31_001DE6F0, 4");
extern f32 D_L31_001DE6F0;
__asm__(".extern D_L31_001DE6E8, 4");
extern f32 D_L31_001DE6E8;
__asm__(".extern D_L31_001DE70C, 4");
extern f32 D_L31_001DE70C;
__asm__(".extern D_L31_001DE768, 4");
extern s32 D_L31_001DE768;
__asm__(".extern D_L31_001DE700, 4");
extern f32 D_L31_001DE700;
__asm__(".extern D_L31_001DE6FC, 4");
extern f32 D_L31_001DE6FC;
__asm__(".extern D_L31_001DE6F8, 4");
extern s32 D_L31_001DE6F8;
__asm__(".extern D_L31_001DE6F4, 4");
extern f32 D_L31_001DE6F4;
__asm__(".extern D_L31_001DE708, 4");
extern s32 D_L31_001DE708;
__asm__(".extern D_L31_001DE760, 1");
extern u8 D_L31_001DE760;
typedef int u128_003A0D30 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    vu0_v4 vel;
    u8 pad20[0x3C - 0x20];
    s32 x3C;
    u8 pad40[0x44 - 0x40];
    s32 col0a;
    s32 col0b;
    s32 col1a;
    s32 col1b;
    u8 pad54[0x58 - 0x54];
    f32 acc0;
    f32 acc1;
    f32 scale;
} V_003A0D30;
extern s32 func_L01_00456250(void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_L30_0034DBA0(s32, s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, f32, f32, f32, s32, s32, s32);

void func_L31_003A0D30(u8 *a0) {
    V_003A0D30 *v = *(V_003A0D30 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 p;
    vu0_v4 q;
    f32 scale;
    f32 alpha;
    f32 t;
    f32 r;
    f32 rnd;
    s32 life;
    s32 col;
    u8 *e;

    if (v->x3C == 0) {
        scale = v->scale;
    } else {
        scale = 1.0f;
    }
    if (v->x3C == 0) {
        alpha = (f32)*(u16 *)(a0 + 0x96) / (f32)D_L31_001DE6EC;
        if (1.0f < alpha) {
            alpha = 1.0f;
        }
        alpha = 1.0f - alpha;
        alpha *= 128.0f;
    } else {
        alpha = 128.0f;
    }
    if (a0[0x20] == 3) {
        alpha = 0.0f;
    }
    if (func_L01_00456250(a0) == 0) {
        scale *= 0.5f;
    }
    if (func_L30_0034D8D8(a0 + 0x10, 1.1f) == 0) {
        return;
    }
    v->acc0 += D_L31_001DE72C * scale;
    while (1.0f < v->acc0) {
        v->acc0 -= 1.0f;
        *(u128_003A0D30 *)&p = *(u128_003A0D30 *)(a0 + 0x10);
        func_0038CF68(&d, &v->vel, 1.0f);
        func_0038CE20(&d, &d, func_003824E0(-D_L31_001DE710 * scale, D_L31_001DE710 * scale));
        vec_add_ab(&p, &d, &p);
        func_0038CF68(&d, &v->vel, 1.0f);
        t = d.x;
        d.x = -d.z;
        d.z = t;
        d.y = 0.0f;
        rnd = func_003824E0(-1.0f, 1.0f);
        func_0038CE20(&d, &d, D_L31_001DE714 * rnd * scale);
        vec_add_ab(&p, &d, &p);
        qzero(&q);
        life = D_L31_001DE71C + (s32)((f32)(D_L31_001DE720 - D_L31_001DE71C) * fabs_asm(rnd));
        if (D_L31_001DE764 != 0) {
            col = func_0038DBD8(func_003824E0(0.0f, 1.0f), v->col0a, v->col0b);
        } else {
            col = func_L30_0034DBA0(v->col0a, v->col0b);
        }
        r = func_003824E0(D_L31_001DE724 * scale, D_L31_001DE728 * scale);
        e = func_L01_004713C8(&p, &q, life, col, func_00382498(-4, 4), r, 0.0f, D_L31_001DE718, alpha < 64.0f ? 64 : (s32)alpha, 0, D_L31_001DE730);
        if (e != 0) {
            e[3] = D_L31_001DE75C;
        }
    }
    v->acc1 += D_L31_001DE704;
    while (1.0f < v->acc1) {
        v->acc1 -= 1.0f;
        qzero(&p);
        p.x = func_003824E0(-D_L31_001DE6F0 * scale, D_L31_001DE6F0 * scale);
        p.y = D_L31_001DE6E8;
        p.z = func_003824E0(-D_L31_001DE6F0 * scale, D_L31_001DE6F0 * scale);
        vec_add_ba(&p, &p, a0 + 0x10);
        *(u128_003A0D30 *)&q = *(u128_003A0D30 *)&v->vel;
        func_0038CE20(&q, &q, D_L31_001DE70C);
        if (a0[0x20] == 3) {
            qzero(&q);
        }
        if (D_L31_001DE768 != 0) {
            col = func_0038DBD8(func_003824E0(0.0f, 1.0f), v->col1a, v->col1b);
        } else {
            col = func_L30_0034DBA0(v->col1a, v->col1b);
        }
        r = func_003824E0(D_L31_001DE700 * scale, D_L31_001DE6FC * scale);
        e = func_L01_004713C8(&p, &q, D_L31_001DE6F8, col, func_00382498(-4, 4), r, 0.0f, D_L31_001DE6F4, (s32)alpha, 0, D_L31_001DE708);
        if (e != 0) {
            e[3] = D_L31_001DE760;
        }
    }
}
/* localdecomp:end func_L31_003A0D30 */
