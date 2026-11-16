#include "common.h"

/* NTSC-U counterpart of func_L39_0064D4A8 (src/levels/shared/L39_0064D4A8.c) */
/* localdecomp:start func_L39_0064AC00 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0064D4A8;

typedef struct {
    u8 p0[0xC];
    f32 fC;
    u8 p10[0x34 - 0x10];
    s32 w34;
} M_0064D4A8;

typedef struct {
    u8 p0[0x10];
    V_0064D4A8 pos;
    u8 p20[0x68 - 0x20];
    M_0064D4A8 *w68;
    u8 p6C[0xF8 - 0x6C];
    f32 fF8;
} T_0064D4A8;

typedef struct {
    u8 p0[0x42];
    u8 b42;
    u8 b43;
} A_0064D4A8;

typedef struct {
    u8 p0[0xA0];
    V_0064D4A8 pos;
    V_0064D4A8 rot;
    V_0064D4A8 rotv;
    u8 pD0[0x120 - 0xD0];
    V_0064D4A8 vel;
    V_0064D4A8 v130;
    V_0064D4A8 v140;
    u8 p150[0x2AC - 0x150];
    f32 f2AC;
    u8 p2B0[0x2DE - 0x2B0];
    s16 h2DE;
    u8 p2E0[0x2F0 - 0x2E0];
    s32 w2F0;
    u8 p2F4[0x610 - 0x2F4];
    f32 f610;
    u8 p614[4];
    s32 w618;
    u8 p61C[0xFD0 - 0x61C];
    f32 fFD0;
    u8 pFD4[0x15E4 - 0xFD4];
    T_0064D4A8 *w15E4;
    u8 p15E8[4];
    s16 h15EC;
    u8 p15EE[2];
    f32 f15F0;
    f32 f15F4;
    f32 f15F8;
    f32 f15FC;
    f32 f1600;
    f32 f1604;
    f32 f1608;
    s16 h160C;
    s16 h160E;
    u8 p1610[4];
    f32 f1614;
    f32 f1618;
    f32 f161C;
    u8 p1620[0x2468 - 0x1620];
    f32 f2468;
    u8 p246C[0x2524 - 0x246C];
    A_0064D4A8 *w2524;
} S_0064D4A8;

extern void func_L39_00628CD0(void *, s32, s32, s32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_L01_004455F0(f32 *, f32 *, f32, f32, f32, f32, s32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388BF0(void *, void *);
extern void func_00388E78(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L39_00630530(void *, s32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388800(void *, void *);
extern void func_L39_006301D8(void *, void *, void *, f32);
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern f32 func_00388770(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_L39_0062FFD0(void *, void *);
extern void func_L39_00628F68(void *, f32, f32, f32, f32);

void func_L39_0064AC00(S_0064D4A8 *p)
{
    V_0064D4A8 dir;
    V_0064D4A8 ang;
    f32 rot[16] __attribute__((aligned(16)));
    f32 inv[16] __attribute__((aligned(16)));
    V_0064D4A8 e;
    V_0064D4A8 v;
    V_0064D4A8 d;
    V_0064D4A8 w;
    f32 len;
    f32 old;
    f32 spd;
    f32 vz;
    f32 a;
    f32 k;

    f32 s;
    f32 t;
    s32 above;
    s32 hit;

    if (p->w618 & 2) {
        if (p->w2524->b43 == 0x2C) {
            func_L39_00628CD0(p, 0x2D, 10, 0, 12.0f);
            p->f610 = 0.300000012f;
        }
    }
    vz = p->vel.z;
    if (p->w15E4 == 0 || p->w15E4->w68 == 0) {
        return;
    }
    if (p->w15E4->w68->w34 != 0) {
        f32 h = p->w15E4->fF8;
        if (90.0f < func_00389468(h, p->rot.z)) {
            h = func_00389380(h, 3.14159274f);
        }
        func_L01_004455F0(&p->f15FC, &p->f1608, h, 0.019999999553f, 0.300000011921f, 0.0f, 0);
    }
    p->fFD0 = p->f15FC;
    func_L39_00630AC0(p, 0, 0.019999999553f, 0.300000011921f, 0.0785398185253f);

    vec_sub_ba(&dir, &p->w15E4->pos, &p->pos);
    func_00388830(&dir, &dir, 1.0f);
    if (dir.z < 0.230000004f) {
        dir.z = 0.230000004f;
    }
    qzero(&e);
    e.z = p->rot.z;
    func_00388BF0(rot, &e);
    func_00388E78(inv, rot);
    above = 1;
    func_003888F0(&dir, &dir, inv);
    ang.x = -func_00388A28(sqrt_asm(dir.x * dir.x + dir.z * dir.z), dir.y);
    ang.y = func_00388A28(dir.z, dir.x);
    func_L01_004455F0(&p->rot.y, &p->rotv.y, ang.y, 0.0399999991059f, 0.20000000298f, 0.15998852253f, 0);
    func_L01_004455F0(&p->rot.x, &p->rotv.x, ang.x, 0.0399999991059f, 0.20000000298f, 0.15998852253f, 0);
    if (!(p->pos.z < p->w15E4->pos.z)) {
        above = 0;
    }
    if (p->h15EC != 0) {
        if (above != 0 && p->w2F0 >= 0x29) {
            if (0.25f < p->f2468) {
                f32 k;
                func_L39_00630530(p, 0, 1.0f);
                k = p->f2468 * 0.00350000010803f;
                if (0.0833333358169f < k) {
                    k = 0.0833333358169f;
                }
                v.x = func_00388960(p->fFD0) * k;
                v.y = func_00388978(p->fFD0) * k;
                v.z = 0.0f;
                vec_add_ab(&p->vel, &p->vel, &v);
            }
        }
        if (p->h15EC != 0) {
            if (func_00388800(&p->pos, &p->w15E4->pos) < p->f15F0 * 1.57000005f || 1.5f < p->f2AC) {
                func_L39_006301D8(p, &p->vel, &p->v140, 0.0111111113802f);
                if (p->h160E != 0) {
                    if (0.0f < func_L39_0062FE30((u8 *)p, (f32 *)&p->vel)) {
                        vec_sub_ab(&v, &p->pos, &p->w15E4->pos);
                        func_L39_006301D8(p, &p->vel, &p->vel, 0.0158333331347f);
                    }
                }
            }
            {
                f32 g = func_00388770(&p->vel) * 0.000250000011874f;
                func_003886E8(&v, &p->vel, -1.0f);
                func_00388830(&v, &v, g);
                vec_add_ab(&p->vel, &p->vel, &v);
            }
        }
    }
    if (p->w15E4 != 0) {
        M_0064D4A8 *m = p->w15E4->w68;
        if (m != 0) {
            spd = func_00388770(&p->vel);
            if (m->fC < spd) {
                func_003BEBF8(&spd, m->fC, 0.00416666688398f);
                func_00388830(&p->vel, &p->vel, spd);
            }
        }
    }
    k = 0.150000006f;
    a = func_00389380(p->rot.z, -1.57079637f);
    w.x = func_00388960(a) * k;
    w.y = func_00388978(a) * k;
    w.z = 0.0f;
    vec_add_ba(&w, &w, &p->pos);
    vec_add_ab(&v, &w, &p->vel);
    vec_sub_ab(&d, &v, &p->w15E4->pos);
    func_00388830(&d, &d, p->f15F4);
    vec_add_ba(&v, &p->w15E4->pos, &d);
    vec_sub_ab(&p->vel, &v, &w);
    old = p->f15F4;
    func_L01_00445168(&p->f15F4, &p->f15F8, p->f15F0, p->f1614, p->f1618, p->f161C);
    len = p->f15F4 - old;
    if (p->f15F4 < func_00388770(&d)) {
        func_00388830(&d, &d, len);
        vec_add_ab(&p->pos, &p->pos, &d);
    }
    if (p->h160E != 0 && above != 0) {
        k = 0.233333349228f;
        s = func_003887A0(&p->vel);
        if (s < k) {
            f32 z = 0.0f;
            func_L01_00445168(&s, &p->f1604, k, 0.0469999983907f, 0.300000011921f, z);
            v.x = func_00388960(p->f15FC) * p->f1604;
            v.y = func_00388978(p->f15FC) * p->f1604;
            v.z = z;
            vec_add_ba(&p->vel, &p->vel, &v);
        }
    }
    if (p->h15EC == 0 || p->h2DE == 0) {
        return;
    }
    if (!(vz < 0.0f && 0.0f < p->vel.z) && p->h160C == 0) {
        return;
    }
    t = sqrt_asm(p->f15F0 / p->f1600) * 3.14159274f;
    p->h160E = 0;
    if (p->h160C != 0) {
        hit = p->h160C == 1;
    } else {
        v = p->v140;
        hit = 0.0f < func_L39_0062FFD0(p, &v);
    }
    if (hit) {
        if (p->w2524->b43 != 0x2D) {
            func_L39_00628CD0(p, 0x2D, 6, 0, 17.0f);
            p->h160C = 1;
        } else if (p->w2524->b42 == p->w2524->b43) {
            func_L39_00628F68(p, 42.0f, t, 0.5f, -1.0f);
            p->h160C = 0;
        }
    } else {
        if (p->w2524->b43 != 0x2D) {
            func_L39_00628CD0(p, 0x2D, 0x15, 0, 9.0f);
            p->h160C = 2;
        } else if (p->w2524->b42 == p->w2524->b43) {
            func_L39_00628F68(p, 12.0f, t, 0.5f, -1.0f);
            p->h160C = 0;
        }
    }
}
/* localdecomp:end func_L39_0064AC00 */
