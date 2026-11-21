#include "common.h"

/* NTSC-U counterpart of func_L40_0041B9F0 (src/levels/shared/L40_0041B820.c) */
extern u8 *D_L40_002494B0[8] __attribute__((section(".sdata")));
extern u8 D_L40_003BFF60[];
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L40_0041AE80(void *moby, s32 type, s32 val, f32 f);

/* localdecomp:start func_L40_0041B1B8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void (*fn14)(void *);
    u8 pad18[0x30 - 0x18];
    void (*fn30)(void *);
    void (*fn34)(void *, s32, s32, s32, s32);
} VT_0041B9F0;

typedef struct {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0x42 - 0x36];
    u8 b42;
    u8 b43;
    u8 pad44[0xF8 - 0x44];
    f32 fF8;
} W_0041B9F0;

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x27B - 0x1C];
    u8 b27B;
} H_0041B9F0;

typedef struct {
    u8 pad0[0x14];
    VT_0041B9F0 *vt;
    u8 pad18[0xA0 - 0x18];
    vu0_v4 pos;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    u8 padBC[0x110 - 0xBC];
    f32 f110;
    f32 f114;
    u8 pad118[0x2F0 - 0x118];
    s32 w2F0;
    u8 pad2F4[0x450 - 0x2F4];
    s32 w450;
    u8 pad454[0x46A - 0x454];
    u8 b46A;
    u8 pad46B[0x478 - 0x46B];
    s32 w478;
    u8 pad47C[0x618 - 0x47C];
    s32 w618;
    s32 w61C;
    u8 pad620[0xFD0 - 0x620];
    f32 fFD0;
    u8 padFD4[0x19E4 - 0xFD4];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A14 - 0x19E7];
    u8 b1A14;
    u8 pad1A15[0x23B8 - 0x1A15];
    f32 f23B8;
    u8 pad23BC[0x251C - 0x23BC];
    s32 w251C;
    u8 pad2520[4];
    W_0041B9F0 *w;
    u8 pad2528[0x2530 - 0x2528];
    H_0041B9F0 *h;
    s32 w2534;
    u8 pad2538[0x2548 - 0x2538];
    s32 team;
    s32 w254C;
} P_0041B9F0;

typedef struct {
    f32 f0;
    f32 f4;
    u8 pad8[4];
    s32 wC;
    u8 pad10[4];
    u32 w14;
    f32 f18;
    f32 f1C;
    u8 pad20[4];
    f32 f24;
    u8 pad28[0x30 - 0x28];
    f32 f30;
    s32 w34;
    u8 pad38[4];
    f32 f3C;
    vu0_v4 v40;
    s32 w50;
    f32 f54;
    f32 f58;
    s32 w5C;
} V_0041B9F0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    V_0041B9F0 *pv;
    u8 pad6C[0x96 - 0x6C];
    u16 h96;
    u8 pad98[0xF8 - 0x98];
    f32 fF8;
} M_0041B9F0;

typedef union {
    vu0_v4 v;
    u8 b[8];
    u32 w[2];
} Buf_0041B9F0;

extern vu0_v4 D_L40_0025BB20;
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);
extern void func_00388BF0(void *, void *);
extern void func_L01_0040BED8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00445168(f32 *, f32, f32, f32, f32, f32 *);
extern void func_L01_00445558(void *, f32, f32, s32);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern void func_L39_00628CD0(void *, s32, s32, s32, f32);
extern s32 func_L39_00669F20(void *, s32, s32);
extern s32 func_L39_0055F748(void *);
extern void func_L40_0041AF38(void *, s32);
extern void func_L40_0041AFE8(u8 *, s32);

static inline u32 Dec_0041B9F0(u8 *q) {
    Buf_0041B9F0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFF60[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

#define Out_0041B9F0(g) ({ \
    s16 r_; \
    if ((g)->h != 0 && (g)->h->b27B != 0) { \
        r_ = 0; \
        if ((Dec_0041B9F0(&(g)->b19E4) ^ 0x31) == 0) { \
            r_++; \
        } \
    } else { \
        r_ = 0; \
    } \
    r_; })

void func_L40_0041B1B8(M_0041B9F0 *m) {
    V_0041B9F0 *pv = m->pv;
    P_0041B9F0 *g;

    if (pv == 0) {
        m->fF8 = func_00389380(m->fF8, 0.104719765f);
        return;
    }
    g = 0;
    if (pv->w50 >= 0) {
        g = (P_0041B9F0 *)D_L40_002494B0[pv->w50];
    }
    if (g != 0) {
        if ((Dec_0041B9F0(&g->b19E4) ^ 0x37) != 0) {
            func_L40_0041AFE8((u8 *)m, 1);
            return;
        }
        if ((u8)Out_0041B9F0(g)) {
            func_L40_0041AFE8((u8 *)m, 1);
            return;
        }
    }
    if (g != 0 && g->b1A14 != 0) {
        s32 a = pv->f58 * 10.0f;
        s32 b = pv->f0 * 10.0f;
        if ((u32)(m->state - 3) < 2 && a != b) {
            ((void (*)(void *, s32, s32, s32, f32))func_L40_0041AE80)(m, 0, 0, 250, pv->f0);
        }
    }
    pv->f58 = pv->f0;
    if (g == 0 && pv->w50 >= 0) {
        pv->w50 = -1;
        if ((u32)(m->state - 3) < 2) {
            func_L01_00441FB8(m, 1, -1);
        }
    }
    switch (m->state) {
    case 0:
        func_L39_00669F20(m, -1, 1);
        {
            vu0_v4 a;
            vu0_v4 b;
            a = m->pos;
            b = m->pos;
            a.z += 0.5f;
            b.z -= 0.5f;
            if (func_003CE740(&a, &b, 0x12, m, 0)) {
                m->pos = D_L40_0025BB20;
                m->pos.z -= 0.3f;
            }
        }
        pv->f3C = m->pos.z;
        m->pos.z = pv->f3C;
        pv->wC = 0;
        pv->f4 = pv->f0;
        func_L01_00441FB8(m, 1, -1);
        qzero(&pv->v40);
        pv->w5C = -1;
        pv->w50 = -1;
        break;
    case 1: {
        s32 i;
        if (m->pos.z < pv->f3C) {
            m->pos.z = m->pos.z + 0.050000004f;
        }
        if (m->pos.z > pv->f3C) {
            m->pos.z = pv->f3C;
        }
        for (i = 0; i < 8; i++) {
            f32 ang;
            f32 dz;
            f32 dist;
            s32 pressed;
            g = (P_0041B9F0 *)D_L40_002494B0[i];
            if (g == 0 || g->b1A14 == 0) {
                continue;
            }
            if ((Dec_0041B9F0(&g->b19E4) ^ 0x31) == 0 || g->w254C != 0) {
                continue;
            }
            if ((Dec_0041B9F0(&g->b19E6) ^ 0x14) == 0 || g->w251C != 0) {
                continue;
            }
            ang = func_00389468(g->fB8, func_00388A28(m->pos.x - g->pos.x, m->pos.y - g->pos.y));
            dz = fabs_asm(g->pos.z - 0.3f - m->pos.z);
            pressed = func_L01_0045D358(0x80, 12, 0, g->w2534);
            dist = func_00388800(&m->pos, &g->pos);
            if (dist < 3.0f && g->b46A == 0) {
                if (ang < 1.9198622f && dz < 0.2f && pv->w14 >= 0x5B && g->w478 == 10 && g->w450 != 0 &&
                    pressed != 0 && m->pos.z == pv->f3C) {
                    s32 ok = 1;
                    s32 j;
                    pv->f54 = 0.0f;
                    for (j = 0; j < 8; j++) {
                        P_0041B9F0 *o = (P_0041B9F0 *)D_L40_002494B0[j];
                        if (o == 0 || o == g || o->team == g->team) {
                            continue;
                        }
                        if ((Dec_0041B9F0(&o->b19E6) ^ 0x14) == 0) {
                            continue;
                        }
                        if (func_003887C8(&m->pos, &o->pos) < 4.5f) {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok) {
                        if (func_L39_0055F748(m) == 0) {
                            func_L40_0041AF38(m, i);
                        }
                        break;
                    }
                } else {
                    if (dist < 3.0f && ang < 1.9198622f && dz < 0.2f) {
                    }
                    if (dist < 3.0f && ang < 1.9198622f) {
                    }
                }
            }
        }
        if (pv->w50 == -1) {
            pv->w14++;
        }
        break;
    }
    case 3: {
        if (g->b1A14 == 0) {
            if ((Dec_0041B9F0(&g->b19E4) ^ 0x37) != 0) {
                g->vt->fn34(g, 0x37, 1, 0, 1);
            }
        }
        {
            vu0_v4 dir;
            vu0_v4 step;
            f32 mat[16] __attribute__((aligned(16)));
            vu0_v4 fwd;
            vu0_v4 rot;
            f32 sp;
            f32 yaw;
            f32 ang;
            f32 z;
            f32 len;
            f32 d;
            f32 t;
            s32 k;

            g->w->h34 |= 0x8000;
            rot = (vu0_v4){0.0f, 0.0f, g->f23B8, 0.0f};
            qzero(&dir);
            if (g->b1A14 != 0) {
                rot.z = g->h->f18;
            }
            yaw = func_00388A28(m->pos.x - g->pos.x, m->pos.y - g->pos.y);
            if ((func_L01_0045D358(0x80, 7, 0, g->w2534) && g->w2F0 >= 0x3D) ||
                func_00388800(&m->pos, &g->pos) >= 4.0f || (u8)Out_0041B9F0(g)) {
                if (g->b1A14 != 0) {
                    func_L40_0041AFE8((u8 *)m, 1);
                    if (pv->w34 != 0 && pv->f0 == 1.0f) {
                        func_L01_00441FB8(m, 5, -1);
                    } else {
                        func_L01_00441FB8(m, 1, -1);
                    }
                    return;
                }
            }
            if (pv->f0 != 1.0f) {
                dir.x = -g->f110;
                dir.y = -g->f114;
            }
            len = func_003887A0(&dir);
            if (1.0f < len) {
                func_L01_0040BED8(&dir, &dir, len);
            }
            func_00388BF0(mat, &rot);
            func_003888F0(&dir, &dir, mat);
            fwd.x = func_00388960(g->w->fF8);
            fwd.y = func_00388978(g->w->fF8);
            fwd.z = 0.0f;
            d = func_00388730(&pv->v40, &dir) - pv->f1C;
            if (0.0015277779f < d) {
                d = 0.0015277779f;
            }
            if (d < -0.0015277779f) {
                d = -0.0015277779f;
            }
            pv->v40 = dir;
            pv->f1C = pv->f1C + d;
            if (0.06166667f < pv->f1C) {
                pv->f1C = 0.06166667f;
            }
            if (pv->f1C < 0.0f) {
                pv->f1C = 0.0f;
            }
            if (fabs_asm(pv->f1C) < 0.00038194447f) {
                pv->f1C = 0.0f;
            }
            func_00388830(&step, &fwd, pv->f1C);
            if (g->w618 & 2) {
                if (g->w->b43 == 0x33) {
                    func_L39_00628CD0(g, 0x2F, 0, 0, 7.0f);
                }
            }
            if (g->w->b43 != 0x33 && g->w61C == 0) {
                if (g->w->b42 == 0x30 && fabs_asm(pv->f1C) == 0.0f) {
                    func_L39_00628CD0(g, 0x2F, 0, 0, 14.0f);
                } else if (g->w->b42 == 0x2F) {
                    if (0.0f < pv->f1C && pv->f0 != 1.0f) {
                        func_L39_00628CD0(g, 0x30, 0, 0, 14.0f);
                    }
                } else if (g->w->b42 == 0x30 && 0.037000004f < pv->f1C) {
                    func_L39_00628CD0(g, 0x31, 0, 0, 14.0f);
                } else if (g->w->b42 == 0x31 && pv->f1C < 0.024666669f) {
                    func_L39_00628CD0(g, 0x30, 0, 0, 16.0f);
                } else if (pv->f0 == 1.0f) {
                    func_L39_00628CD0(g, 0x2F, 0, 0, 14.0f);
                }
            }
            z = g->pos.z;
            vec_add_ba(&g->pos, &g->pos, &step);
            ang = func_00388A28(m->pos.x - g->pos.x, m->pos.y - g->pos.y);
            step.x = func_00388960(ang) * -1.05f;
            step.y = func_00388978(ang) * -1.05f;
            step.z = 0.0f;
            {
                vu0_v4 tgt;
                vu0_v4 off;
                vec_add_ab(&tgt, &m->pos, &step);
                vec_sub_ab(&off, &tgt, &g->pos);
                off.z = 0.0f;
                sp = -func_003887A0(&off);
                func_L01_00445168(&sp, 0.0f, 0.015f, 0.3f, 0.116666675f, &pv->f54);
                func_00388830(&off, &off, pv->f54);
                vec_add_ba(&g->pos, &g->pos, &off);
            }
            g->pos.z = z;
            g->fFD0 = func_00389380(1.5707964f, ang);
            func_L01_00445558(&g->fB8, g->fFD0, 0.104719765f, 0);
            pv->f24 = pv->f24 + 0.0027222224f;
            g->pos.z = g->pos.z - (pv->f24 - 2.0f);
            {
                f32 fl = func_003BE7F0(&g->pos, 0, 0, 0.5f);
                g->pos.z = g->pos.z - 2.0f;
                if (g->pos.z < fl) {
                    g->pos.z = fl;
                    pv->f24 = 0.0f;
                }
            }
            if (g->w->b43 != 0x33) {
                t = func_00389380(-0.2617994f, ang);
                func_L01_00445558(&m->fF8, t, 0.052359883f, 0);
                if (1.0471976f < func_003893C8(m->fF8, t)) {
                    m->fF8 = func_003893C8(m->fF8, 1.0471976f);
                } else if (func_003893C8(m->fF8, t) < -1.0471976f) {
                    m->fF8 = func_00389380(m->fF8, 1.0471976f);
                }
            }
            pv->f18 = pv->f18 + func_00389468(ang, yaw);
            pv->f0 = pv->f18 / (pv->f30 * 6.2831855f);
            if (1.0f < pv->f0) {
                pv->f0 = 1.0f;
            }
            if (pv->f0 < 0.0f) {
                pv->f0 = 0.0f;
            }
            if (g->b1A14 == 0) {
                if (pv->f0 == 1.0f) {
                    pv->f0 = 0.999f;
                } else if (pv->f0 == 0.0f) {
                    pv->f0 = 0.001f;
                }
            }
            g->vt->fn30(g);
            if (pv->f0 == 1.0f) {
                pv->w5C = pv->w50;
                m->h96++;
                k = 0x78;
                if (pv->w34 == 0) {
                    k = 0;
                }
                if ((k + 0x3C) < m->h96 && g->b1A14 != 0) {
                    func_L40_0041AFE8((u8 *)m, 1);
                    if (pv->w34 != 0) {
                        func_L01_00441FB8(m, 5, -1);
                    } else {
                        func_L01_00441FB8(m, 1, -1);
                    }
                }
            }
        }
        break;
    }
    case 4: {
        if (g->b1A14 == 0) {
            if ((Dec_0041B9F0(&g->b19E4) ^ 0x37) != 0) {
                g->vt->fn34(g, 0x37, 1, 0, 1);
            }
        }
        {
            f32 mat[16] __attribute__((aligned(16)));
            vu0_v4 dir;
            vu0_v4 step;
            vu0_v4 fwd;
            vu0_v4 rot;
            f32 sp;
            f32 yaw;
            f32 ang;
            f32 z;
            f32 len;
            f32 d;
            f32 t;
            s32 k;

            rot = (vu0_v4){0.0f, 0.0f, g->f23B8, 0.0f};
            qzero(&dir);
            if (g->b1A14 != 0) {
                rot.z = g->h->f18;
            }
            yaw = func_00389380(func_00388A28(m->pos.x - g->pos.x, m->pos.y - g->pos.y), 3.1415927f);
            if ((func_L01_0045D358(0x80, 7, 0, g->w2534) && g->w2F0 >= 0x3D) ||
                func_00388800(&m->pos, &g->pos) >= 4.0f || (u8)Out_0041B9F0(g)) {
                if (g->b1A14 != 0) {
                    func_L40_0041AFE8((u8 *)m, 1);
                    func_L01_00441FB8(m, 1, -1);
                    return;
                }
            }
            if (0.0f < pv->f0) {
                dir.x = g->f110;
                dir.y = g->f114;
            }
            len = func_003887A0(&dir);
            if (1.0f < len) {
                func_L01_0040BED8(&dir, &dir, len);
            }
            func_00388BF0(mat, &rot);
            func_003888F0(&dir, &dir, mat);
            fwd.x = func_00388960(g->w->fF8);
            fwd.y = func_00388978(g->w->fF8);
            fwd.z = 0.0f;
            d = func_00388730(&pv->v40, &dir) - pv->f1C;
            if (0.0015277779f < d) {
                d = 0.0015277779f;
            }
            if (d < -0.0015277779f) {
                d = -0.0015277779f;
            }
            pv->v40 = dir;
            pv->f1C = pv->f1C + d;
            if (0.06166667f < pv->f1C) {
                pv->f1C = 0.06166667f;
            }
            if (pv->f1C < 0.0f) {
                pv->f1C = 0.0f;
            }
            if (fabs_asm(pv->f1C) < 0.00038194447f) {
                pv->f1C = 0.0f;
            }
            func_00388830(&step, &fwd, pv->f1C);
            if (g->w618 & 2) {
                if (g->w->b43 == 0x33) {
                    func_L39_00628CD0(g, 0x2F, 0, 0, 7.0f);
                }
            }
            if (g->w->b43 != 0x33 && g->w61C == 0) {
                if (g->w->b42 == 0x30 && fabs_asm(pv->f1C) == 0.0f) {
                    func_L39_00628CD0(g, 0x2F, 0, 0, 14.0f);
                } else if (g->w->b42 == 0x2F) {
                    if (0.0f < pv->f1C && 0.0f < pv->f0) {
                        func_L39_00628CD0(g, 0x30, 0, 0, 14.0f);
                    }
                } else if (g->w->b42 == 0x30 && 0.037000004f < pv->f1C) {
                    func_L39_00628CD0(g, 0x31, 0, 0, 14.0f);
                } else if (g->w->b42 == 0x31 && pv->f1C < 0.024666669f) {
                    func_L39_00628CD0(g, 0x30, 0, 0, 16.0f);
                } else if (pv->f0 == 0.0f) {
                    func_L39_00628CD0(g, 0x2F, 0, 0, 14.0f);
                }
            }
            z = g->pos.z;
            vec_add_ba(&g->pos, &g->pos, &step);
            ang = func_00389380(func_00388A28(m->pos.x - g->pos.x, m->pos.y - g->pos.y), 3.1415927f);
            step.x = func_00388960(ang) * 1.05f;
            step.y = func_00388978(ang) * 1.05f;
            step.z = 0.0f;
            {
                vu0_v4 tgt;
                vu0_v4 off;
                vec_add_ab(&tgt, &m->pos, &step);
                vec_sub_ab(&off, &tgt, &g->pos);
                off.z = 0.0f;
                sp = -func_003887A0(&off);
                func_L01_00445168(&sp, 0.0f, 0.015f, 0.3f, 0.116666675f, &pv->f54);
                func_00388830(&off, &off, pv->f54);
                vec_add_ba(&g->pos, &g->pos, &off);
            }
            g->pos.z = z;
            g->fFD0 = func_00389380(1.5707964f, ang);
            func_L01_00445558(&g->fB8, g->fFD0, 0.104719765f, 0);
            pv->f24 = pv->f24 + 0.0027222224f;
            g->pos.z = g->pos.z - (pv->f24 - 2.0f);
            {
                f32 fl = func_003BE7F0(&g->pos, 0, 0, 0.5f);
                g->pos.z = g->pos.z - 2.0f;
                if (g->pos.z < fl) {
                    g->pos.z = fl;
                    pv->f24 = 0.0f;
                }
            }
            if (g->w->b43 != 0x33) {
                t = func_00389380(0.2617994f, ang);
                func_L01_00445558(&m->fF8, t, 0.052359883f, 0);
                if (1.0471976f < func_003893C8(m->fF8, t)) {
                    m->fF8 = func_003893C8(m->fF8, 1.0471976f);
                } else if (func_003893C8(m->fF8, t) < -1.0471976f) {
                    m->fF8 = func_00389380(m->fF8, 1.0471976f);
                }
            }
            pv->f18 = pv->f18 - func_00389468(ang, yaw);
            pv->f0 = pv->f18 / (pv->f30 * 6.2831855f);
            if (1.0f < pv->f0) {
                pv->f0 = 1.0f;
            }
            if (pv->f0 < 0.0f) {
                pv->f0 = 0.0f;
            }
            if (g->b1A14 == 0) {
                if (pv->f0 == 1.0f) {
                    pv->f0 = 0.999f;
                } else if (pv->f0 == 0.0f) {
                    pv->f0 = 0.001f;
                }
            }
            g->vt->fn30(g);
            if (pv->f0 == 0.0f) {
                m->h96++;
                k = 0x78;
                if (pv->w34 == 0) {
                    k = 0;
                }
                pv->w5C = pv->w50;
                if (m->h96 >= (k + 0x3C) && g->b1A14 != 0) {
                    func_L40_0041AFE8((u8 *)m, 1);
                    func_L01_00441FB8(m, 1, -1);
                }
            }
        }
        break;
    }
    case 5: {
        f32 lo = pv->f3C - 0.5f;
        if (lo < m->pos.z) {
            m->pos.z = m->pos.z - 0.050000004f;
        }
        if (m->pos.z < lo) {
            m->pos.z = lo;
        }
        func_L40_0041AFE8((u8 *)m, 0);
        break;
    }
    }
}
/* localdecomp:end func_L40_0041B1B8 */
