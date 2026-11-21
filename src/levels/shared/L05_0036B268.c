#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L05_0036B268);

/* localdecomp:start func_L05_0036B5E0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0036B5E0;
typedef struct { u8 pad0[8]; s32 w8; } S_0036B5E0;

extern u8 *D_L05_00220758[];
extern void func_003C5180(void *, void *, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, s32, s32, f32, s32, s32, s32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);

void func_L05_0036B5E0(u8 *self) {
    S_0036B5E0 *s3;
    V4_0036B5E0 tmp;
    V4_0036B5E0 vel;
    V4_0036B5E0 pos;
    s32 i;
    s32 col;
    f32 el;
    f32 ang;
    f32 sz;
    u8 *o;

    s3 = *(S_0036B5E0 **)(self + 0x68);
    func_003C5180(self + 0x10, &tmp, 1);
    for (i = 2; i >= 0; i--) {
        col = 0x4F808080;
        el = func_003824E0(-0.9599311f, -1.3962634f);
        ang = func_00382538();
        func_00382760(&vel, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
        sz = func_003824E0(0.65f, 0.85f) * 210000.0f;
        pos.x = *(f32 *)(self + 0x10) + func_L01_00443A18(0.0f, 0.3f);
        pos.y = *(f32 *)(self + 0x14) + func_L01_00443A18(0.0f, 0.3f);
        pos.z = *(f32 *)(self + 0x18) + func_L01_00443A18(0.0f, 0.3f);
        if (s3->w8 != 0) {
            col = 0x4F202080;
        }
        o = func_L01_004708C8(&pos, &vel, col, 0x08101010, sz, func_00382498(17, 29), 1, 0.5f, 1, -1, 1);
        if (o != 0) {
            if (s3->w8 != 0) {
                o[2] = D_L05_00220758[0x16C / 4][0];
            } else {
                o[2] = D_L05_00220758[0x16C / 4][1];
            }
        }
    }
    func_00382580(&vel, 0.0f, 0.025f);
    vec_add_ba(&vel, &vel, self + 0x10);
    vec_sub_ba(&pos, self + 0x10, &vel);
    func_0038CF68(&pos, &pos, -0.015000001f);
    func_L01_004735F0(&vel, &pos, 0x11, 5.0f);
}
/* localdecomp:end func_L05_0036B5E0 */

/* localdecomp:start func_L05_0036B870 */
extern u8 D_L05_0028DE00_0036B870[];
extern s32 D_L05_001E16E0_0036B870;
extern f32 D_L05_001E16E4_0036B870;
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L05_0036BAD0_0036B870(void *a0, u8 *s);

void func_L05_0036B870(u8 *a0) {
    s32 i;
    u8 *e;

    for (i = 0; i < 16; i++) {
        e = D_L05_0028DE00_0036B870 + i * 0xB0;
        if (*(u8 **)(e + 0x9C) != a0) {
            continue;
        }
        func_L05_0036BAD0_0036B870(a0, e);
        if (*(s32 *)(e + 0xA0) != 0) {
            continue;
        }
        func_003D9508(e + 0x30, 0x39, 0x3F7F0000, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, func_00382538());
        func_003D9508(e + 0x30, 0x39, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, func_00382538());
        func_003D9508(e + 0x30, 0xB, 0x103F0000, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
    }
    func_003D9508(a0 + 0x10, 0x1A, ((D_L05_001E16E0_0036B870 + 0x14) << 24) | 0xFF0032, 1, D_L05_001E16E4_0036B870, 0.5f, 0.0f);
    func_003D9508(a0 + 0x10, 0x3D, (D_L05_001E16E0_0036B870 << 24) | 0xFF0032, 1, D_L05_001E16E4_0036B870, 0.5f, 0.0f);
    func_003D9508(a0 + 0x10, 0x3D, (D_L05_001E16E0_0036B870 << 24) | 0xFF0032, 1, D_L05_001E16E4_0036B870 + D_L05_001E16E4_0036B870, 0.5f, 0.0f);
    D_L05_001E16E4_0036B870 = D_L05_001E16E4_0036B870 + 0.3f;
    D_L05_001E16E0_0036B870 -= 6;
    if (D_L05_001E16E0_0036B870 < 0) {
        D_L05_001E16E0_0036B870 = 0;
    }
}
/* localdecomp:end func_L05_0036B870 */

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

/* localdecomp:start func_L05_0036BC98 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q0;
    u128_t q10;
    f32 x20, y24, z28, p2C;
    u128_t q30;
    u128_t q40;
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    s32 w98;
    s32 w9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s32 pAC;
} P_0036BC98;

extern P_0036BC98 D_L05_0028DE00[];
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L05_0036BC98(u8 *owner, u8 *pos, s32 arg) {
    s32 i;
    P_0036BC98 *p;
    P_0036BC98 *base = D_L05_0028DE00;

    for (i = 0; i < 16; i++) {
        p = &base[i];
        if (p->w9C == 0) {
            p->w9C = (s32)owner;
            *(u128_t *)&p->x20 = *(u128_t *)(owner + 0x10);
            p->q40 = *(u128_t *)pos;
            p->x20 += func_003824E0(-0.1f, 0.1f);
            p->y24 += func_003824E0(-0.1f, 0.1f);
            p->z28 += func_003824E0(-0.1f, 0.1f);
            p->f50 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f54 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f58 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f74 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f78 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f7C = func_003824E0(-3.1415927f, 3.1415927f);
            p->f5C = func_L01_00443A18(0.001f, 0.005f);
            p->f60 = func_L01_00443A18(0.001f, 0.005f);
            p->f64 = func_L01_00443A18(0.001f, 0.005f);
            p->f80 = func_L01_00443A18(0.001f, 0.005f);
            p->f84 = func_L01_00443A18(0.001f, 0.005f);
            p->f88 = func_L01_00443A18(0.001f, 0.005f);
            p->f68 = func_003824E0(3.25f, 4.75f);
            p->f6C = func_003824E0(3.25f, 4.75f);
            p->f70 = func_003824E0(3.25f, 4.75f);
            p->f8C = func_003824E0(3.25f, 4.75f);
            p->f90 = func_003824E0(3.25f, 4.75f);
            p->f94 = func_003824E0(3.25f, 4.75f);
            p->w98 = 17;
            qzero(&p->q0);
            p->wA4 = p->wA0 = arg;
            qzero(&p->q10);
            p->wA8 = 0;
            return;
        }
    }
}
/* localdecomp:end func_L05_0036BC98 */

/* localdecomp:start func_L05_0036BF28 */
#include "vu0.h"

typedef struct {
    f32 rot[3];
    f32 pad0C;
    f32 rot2[3];
    f32 pad1C;
    vu0_q pos;
    vu0_q out;
    vu0_q target;
    f32 ang[3];
    f32 spd[3];
    f32 amp[3];
    f32 ang2[3];
    f32 spd2[3];
    f32 amp2[3];
    s32 life;
    void *owner;
    s32 time;
    s32 total;
    s32 flag;
    u8 padAC[4];
} E_36BF28_0036BF28;
typedef struct {
    u8 pad0[0x10];
    vu0_q pos;
} O_36BF28_0036BF28;
extern E_36BF28_0036BF28 D_L05_0028DE00_0036BF28[16];
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L05_0036BF28(O_36BF28_0036BF28 *o) {
    vu0_q d;
    E_36BF28_0036BF28 *e;
    E_36BF28_0036BF28 *tab;
    s32 i;

    tab = D_L05_0028DE00_0036BF28;
    for (i = 0; i < 16; i++) {
        e = &tab[i];
        if (e->owner != o) {
            continue;
        }
        ((f32 *)&e->pos)[0] += func_003824E0(-0.1f, 0.1f);
        ((f32 *)&e->pos)[1] += func_003824E0(-0.1f, 0.1f);
        ((f32 *)&e->pos)[2] += func_003824E0(-0.1f, 0.1f);
        vec_sub_ba(&d, &e->target, &e->pos);
        e->pos = o->pos;
        vec_add_ba(&e->target, &e->pos, &d);
        if (e->time != 0) {
            e->ang[0] = func_0038DAB8(e->ang[0], e->spd[0] * 100.0f);
            e->ang[1] = func_0038DAB8(e->ang[1], e->spd[1] * 100.0f);
            e->ang[2] = func_0038DAB8(e->ang[2], e->spd[2] * 100.0f);
            e->ang2[0] = func_0038DAB8(e->ang2[0], e->spd2[0] * 100.0f);
            e->ang2[1] = func_0038DAB8(e->ang2[1], e->spd2[1] * 100.0f);
            e->ang2[2] = func_0038DAB8(e->ang2[2], e->spd2[2] * 100.0f);
        } else {
            e->ang[0] = func_0038DAB8(e->ang[0], e->spd[0] * 50.0f);
            e->ang[1] = func_0038DAB8(e->ang[1], e->spd[1] * 50.0f);
            e->ang[2] = func_0038DAB8(e->ang[2], e->spd[2] * 50.0f);
            e->ang2[0] = func_0038DAB8(e->ang2[0], e->spd2[0] * 50.0f);
            e->ang2[1] = func_0038DAB8(e->ang2[1], e->spd2[1] * 50.0f);
            e->ang2[2] = func_0038DAB8(e->ang2[2], e->spd2[2] * 50.0f);
        }
        e->rot[0] = func_0038D098(e->ang[0]) * e->amp[0];
        e->rot[1] = func_0038D0B0(e->ang[1]) * e->amp[1];
        e->rot[2] = -func_0038D0B0(e->ang[2]) * e->amp[2];
        e->rot2[0] = func_0038D098(e->ang2[0]) * e->amp2[0];
        e->rot2[1] = func_0038D0B0(e->ang2[1]) * e->amp2[1];
        e->rot2[2] = -func_0038D0B0(e->ang2[2]) * e->amp2[2];
        func_0038CDF8(&e->out, &e->pos, &e->target, 1.0f - (f32)e->time / (f32)e->total);
        if (func_0038CAD0(&e->time) != 0) {
            if (e->flag == 0) {
                e->flag = 1;
            }
            if (func_0038CAD0(&e->life) != 0) {
                e->owner = 0;
            }
        }
    }
}
/* localdecomp:end func_L05_0036BF28 */
