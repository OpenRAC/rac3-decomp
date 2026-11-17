#include "common.h"

/* localdecomp:start func_L39_0064D4A8 */
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

extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00448728(f32 *, f32 *, f32, f32, f32, f32, s32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L39_00632D78(void *, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L39_00632A20(void *, void *, void *, f32);
extern f32 func_L39_00632678(u8 *, f32 *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_L39_00632818(void *, void *);
extern void func_L39_0062B740(void *, f32, f32, f32, f32);

void func_L39_0064D4A8(S_0064D4A8 *p)
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
            func_L39_0062B4A8(p, 0x2D, 10, 0, 10.0f);
            p->f610 = 0.300000012f;
        }
    }
    vz = p->vel.z;
    if (p->w15E4 == 0 || p->w15E4->w68 == 0) {
        return;
    }
    if (p->w15E4->w68->w34 != 0) {
        f32 h = p->w15E4->fF8;
        if (90.0f < func_0038DBA0(h, p->rot.z)) {
            h = func_0038DAB8(h, 3.14159274f);
        }
        func_L01_00448728(&p->f15FC, &p->f1608, h, 0.0288000014f, 0.432000041f, 0.0f, 0);
    }
    p->fFD0 = p->f15FC;
    func_L39_00633308(p, 0, 0.0288000014f, 0.432000041f, 0.0942477882f);

    vec_sub_ba(&dir, &p->w15E4->pos, &p->pos);
    func_0038CF68(&dir, &dir, 1.0f);
    if (dir.z < 0.230000004f) {
        dir.z = 0.230000004f;
    }
    qzero(&e);
    e.z = p->rot.z;
    func_0038D328(rot, &e);
    func_0038D5B0(inv, rot);
    above = 1;
    func_0038D028(&dir, &dir, inv);
    ang.x = -func_0038D160(sqrt_asm(dir.x * dir.x + dir.z * dir.z), dir.y);
    ang.y = func_0038D160(dir.z, dir.x);
    func_L01_00448728(&p->rot.y, &p->rotv.y, ang.y, 0.0576000027f, 0.288000017f, 0.191986233f, 0);
    func_L01_00448728(&p->rot.x, &p->rotv.x, ang.x, 0.0576000027f, 0.288000017f, 0.191986233f, 0);
    if (!(p->pos.z < p->w15E4->pos.z)) {
        above = 0;
    }
    if (p->h15EC != 0) {
        if (above != 0 && p->w2F0 >= 0x22) {
            if (0.25f < p->f2468) {
                f32 k;
                func_L39_00632D78(p, 0, 1.0f);
                k = p->f2468 * 0.00420000032f;
                if (0.100000009f < k) {
                    k = 0.100000009f;
                }
                v.x = func_0038D098(p->fFD0) * k;
                v.y = func_0038D0B0(p->fFD0) * k;
                v.z = 0.0f;
                vec_add_ab(&p->vel, &p->vel, &v);
            }
        }
        if (p->h15EC != 0) {
            if (func_0038CF38(&p->pos, &p->w15E4->pos) < p->f15F0 * 1.57000005f || 1.5f < p->f2AC) {
                func_L39_00632A20(p, &p->vel, &p->v140, 0.0160000008f);
                if (p->h160E != 0) {
                    if (0.0f < func_L39_00632678((u8 *)p, (f32 *)&p->vel)) {
                        vec_sub_ab(&v, &p->pos, &p->w15E4->pos);
                        func_L39_00632A20(p, &p->vel, &p->vel, 0.0228000004f);
                    }
                }
            }
            {
                f32 g = func_0038CEA8(&p->vel) * 0.000300000014f;
                func_0038CE20(&v, &p->vel, -1.0f);
                func_0038CF68(&v, &v, g);
                vec_add_ab(&p->vel, &p->vel, &v);
            }
        }
    }
    if (p->w15E4 != 0) {
        M_0064D4A8 *m = p->w15E4->w68;
        if (m != 0) {
            spd = func_0038CEA8(&p->vel);
            if (m->fC < spd) {
                func_003C4138(&spd, m->fC, 0.00600000005f);
                func_0038CF68(&p->vel, &p->vel, spd);
            }
        }
    }
    k = 0.150000006f;
    a = func_0038DAB8(p->rot.z, -1.57079637f);
    w.x = func_0038D098(a) * k;
    w.y = func_0038D0B0(a) * k;
    w.z = 0.0f;
    vec_add_ba(&w, &w, &p->pos);
    vec_add_ab(&v, &w, &p->vel);
    vec_sub_ab(&d, &v, &p->w15E4->pos);
    func_0038CF68(&d, &d, p->f15F4);
    vec_add_ba(&v, &p->w15E4->pos, &d);
    vec_sub_ab(&p->vel, &v, &w);
    old = p->f15F4;
    func_L01_004482A0(&p->f15F4, &p->f15F8, p->f15F0, p->f1614, p->f1618, p->f161C);
    len = p->f15F4 - old;
    if (p->f15F4 < func_0038CEA8(&d)) {
        func_0038CF68(&d, &d, len);
        vec_add_ab(&p->pos, &p->pos, &d);
    }
    if (p->h160E != 0 && above != 0) {
        k = 0.280000031f;
        s = func_0038CED8(&p->vel);
        if (s < k) {
            f32 z = 0.0f;
            func_L01_004482A0(&s, &p->f1604, k, 0.0676800013f, 0.432000041f, z);
            v.x = func_0038D098(p->f15FC) * p->f1604;
            v.y = func_0038D0B0(p->f15FC) * p->f1604;
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
        hit = 0.0f < func_L39_00632818(p, &v);
    }
    if (hit) {
        if (p->w2524->b43 != 0x2D) {
            func_L39_0062B4A8(p, 0x2D, 6, 0, 14.0f);
            p->h160C = 1;
        } else if (p->w2524->b42 == p->w2524->b43) {
            func_L39_0062B740(p, 42.0f, t, 0.5f, -1.0f);
            p->h160C = 0;
        }
    } else {
        if (p->w2524->b43 != 0x2D) {
            func_L39_0062B4A8(p, 0x2D, 0x15, 0, 7.0f);
            p->h160C = 2;
        } else if (p->w2524->b42 == p->w2524->b43) {
            func_L39_0062B740(p, 12.0f, t, 0.5f, -1.0f);
            p->h160C = 0;
        }
    }
}
/* localdecomp:end func_L39_0064D4A8 */

/* localdecomp:start func_L39_0064DCF0 */
#include "vu0.h"

typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0064DCF0;

typedef struct {
    u8 p0[0x18];
    s32 w18;
    u8 p1C[0x2C - 0x1C];
} T_0064DCF0;

typedef struct {
    u8 p0[0x2C];
    s32 w2C;
    u8 p30[0x40 - 0x30];
    f32 f40;
    u8 p44[4];
    s32 w48;
} Ob_0064DCF0;

typedef struct {
    u8 p0[0xC];
    f32 fC;
    u8 p10[8];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 p1C[0x30 - 0x1C];
} Hit_0064DCF0;

typedef struct {
    u8 p0[0x20];
    u8 v20[0x80];
    u8 vA0[0x80];
    u8 v120[0x28];
    f32 f148;
    u8 p14C[0x2AC - 0x14C];
    f32 f2AC;
    u8 p2B0[0x2DE - 0x2B0];
    s16 h2DE;
    u8 p2E0[0x10];
    s32 w2F0;
    u8 p2F4[0x319 - 0x2F4];
    u8 b319;
    u8 p31A[0x32E - 0x31A];
    s16 h32E;
    u8 p330[0x370 - 0x330];
    unsigned long d370;
    u8 p378;
    u8 b379;
    u8 p37A[0x469 - 0x37A];
    u8 b469;
    u8 p46A[0x61C - 0x46A];
    s32 w61C;
    u8 p620[8];
    f32 f628;
    u8 p62C[0xFB0 - 0x62C];
    f32 fFB0;
    f32 fFB4;
    u8 pFB8[0xFC0 - 0xFB8];
    vu0_q qFC0;
    f32 fFD0;
    u8 pFD4[0x1040 - 0xFD4];
    vu0_q q1040;
    u8 p1050[0x1064 - 0x1050];
    u8 *w1064;
    s32 w1068;
    f32 f106C;
    u8 p1070[0x107C - 0x1070];
    s16 h107C;
    u8 p107E[0x1080 - 0x107E];
    f32 f1080;
    u8 p1084[0x1A40 - 0x1084];
    u8 b1A40;
    u8 p1A41[0x2524 - 0x1A41];
    void *w2524;
    u8 p2528[8];
    Ob_0064DCF0 *w2530;
    s32 w2534;
} S_0064DCF0;

extern T_0064DCF0 D_L39_0047A8A8_0064DCF0[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

extern f32 func_L39_006325D8(void *, void *);
extern void func_L39_00633620(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_0062FCF0(void *, f32, f32, f32);
extern void func_L01_00511158(void *, void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L39_00632C48(void *, f32);
extern s32 func_L01_003F1F20(s32, s32);
extern f32 func_L39_00632678(u8 *, f32 *);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_00632A20(void *, void *, void *, f32);

void func_L39_0064DCF0(S_0064DCF0 *p)
{
    s32 flag;
    f32 d;
    f32 k;
    s32 w;
    f32 lim;
    s32 lo;
    s32 hi;

    if (p->w61C != 0 || p->f628 < (f32)D_L39_0047A8A8_0064DCF0[p->h107C].w18) {
        p->b469 = 2;
    }
    p->fFB0 = 0.0f;
    flag = 0;
    if ((p->d370 & 0xFFFF0000000000) != 0 || p->b379 != 0 || 4.0f < p->f2AC) {
        flag = 1;
    }
    if (p->w1064 != 0) {
        {
            u8 tmp[16] __attribute__((aligned(16)));
            u8 v[16] __attribute__((aligned(16)));

            vec_sub_ab(tmp, p->w1064 + 0x10, p->vA0);
            d = func_L39_006325D8(p, tmp);
            if ((2.0f < d && d < 5.0f) || flag) {
                p->fFB0 = 0.09f;
            }
            func_L39_00633620(p, 0.0100000007f, 0.0100000007f);
            func_0038CF68(v, p->v20, p->fFB4);
            func_L39_00632298(p, p->v120, p->v120, 0.0f);
            vec_add_ab(p->v120, p->v120, v);
        }
    } else {
        if (flag && p->w2F0 < 0x3A) {
            p->fFB0 = 0.09f;
        }
        func_L39_00633620(p, 0.006f, 0.006f);
        func_L39_00632298(p, p->v120, p->v120, p->fFB4);
    }
    if (p->w1068 != 0 || p->w1064 != 0) {
        p->fFD0 = p->f106C;
        p->qFC0 = p->q1040;
        func_L39_00633308(p, 0, 0.0720000044f, 0.288000017f, 0.3385939f);
    } else if (p->f628 < 25.0f) {
        func_L39_0062FCF0(p, 8.0f, 1.04719758f, 1.04719758f);
    }
    k = 0.15400001406669617f;
    if (2.25f < p->f2AC) {
        k = 0.07700000703334808f;
    } else if (1.8f < p->f2AC) {
        k = 0.10780000686645508f;
    }
    if (p->w61C == 0 && 23.5f < p->f628 && p->f148 < 0.0f && p->h2DE != 0) {
        {
            u8 pos[16] __attribute__((aligned(16)));
            u8 v[16] __attribute__((aligned(16)));
            Hit_0064DCF0 hit;

            *(vu0_q *)pos = *(vu0_q *)p->vA0;
            func_L01_00511158(p, pos, pos, -0.5f);
            func_0038CF68(v, p->v20, 2.0f);
            func_L01_00446760(&hit, p->w2524, 0x10000, 2.0f, v);
            hit.fC = 5627.9248f;
            hit.b19 = 1;
            hit.h1A = 0x47;
            hit.b18 = 0;
            func_003D4D00(pos, 0x10, p->w2524, &hit, 0.4f);
        }
    }
    if (func_L39_00632C48(p, 25.7f) != 0) {
        u16 bits;

        func_L01_003F1F20(0x19, p->w2534);
        p->h32E = 0x2A;
        {
            u8 *q = &p->b1A40;

            if (*q == 0) {
                bits = 0;
            } else {
                Buf_0064DCF0 buf;
                u32 a;
                u32 b;
                s32 n;
                s32 kk;
                s32 m;
                s32 i;
                u8 *dd;

                n = *q;
                kk = ((u32)q - n) & 7;
                m = n + 1;
                dd = buf.b;
                for (i = 0; i < 24; i += 3) {
                    *dd++ = D_L39_00483A00[((kk + i) & 7) * 209 + m];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                bits = buf.h[2];
            }
        }
        if ((s16)bits < 0) {
            p->w2530->f40 = 0.1f;
            p->w2530->w48 = 0x19;
            p->w2530->w2C = 0;
            {
                u8 *q = &p->b319;
                s16 v = 0x1D;
                u8 *hk = q;
                Buf_0064DCF0 buf;
                u32 key;
                s32 kk;
                s32 m;
                s32 i;
                s32 t;
                u8 *dd;

                if (*q == 0) {
                    *q = ++D_L39_004997E0[0];
                } else {
                    t = *q;
                    *q = D_L39_004997E1[0];
                    D_L39_004997E1[0] = t;
                }
                key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
                kk = ((u32)q - *q) & 7;
                buf.h[2] = v;
                buf.w[0] = (u32)q ^ key;
                buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
                m = *q + 1;
                dd = buf.b;
                for (i = 0; i < 24; i += 3) {
                    D_L39_004997E0[m + ((kk + i) & 7) * 255] = *dd++;
                }
            }
        }
    }
    w = p->w2F0;
    lo = 7;
    hi = 12;
    if (w < lo) {
        f32 f;

        f = func_L39_00632678((u8 *)p, (f32 *)p->v120);
        func_003C4138(&f, k, 0.0600000024f);
        func_L39_00632558(p, p->v120, p->v120, f);
    } else if (w > hi) {
        func_L39_00632A20(p, p->v120, p->v120, 0.052f);
        if (func_L39_00632678((u8 *)p, (f32 *)p->v120) < 0.0f) {
            p->f1080 = 1.0f;
        }
        lim = -0.740000069f;
        if (func_L39_00632678((u8 *)p, (f32 *)p->v120) < lim) {
            func_L39_00632558(p, p->v120, p->v120, lim);
        }
    }
}
/* localdecomp:end func_L39_0064DCF0 */
