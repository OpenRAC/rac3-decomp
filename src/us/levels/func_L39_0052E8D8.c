#include "common.h"

/* NTSC-U counterpart of func_L39_0052EE60 (src/levels/shared/L39_0052DF20.c) */
#include "vu0.h"
typedef struct {
    u8 pad0[0x660];
    vu0_v4 v660[4];
    vu0_v4 v6A0;
    f32 f6B0[4];
    u8 pad6C0[0x10];
    u8 *f6D0;
    u8 pad6D4[0x3C];
    u16 f710;
    u8 pad712;
    u8 f713;
    u8 pad714;
    u8 f715;
    u8 pad716[4];
    s16 f71A;
    u8 pad71C[0x38];
    s16 f754;
    u8 pad756[0x4E];
    f32 f7A4;
    s32 f7A8;
} A_0052DF20;
typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} S_0052DF20;
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_00664930(void *, u32, s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern vu0_v4 D_L39_002440A0 __attribute__((section(".sdata")));
extern vu0_v4 D_L39_0024AC50_0052E8D8[] __attribute__((section(".sdata")));
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} S_0052E550;
extern S_0052E550 D_L39_0025F840;
extern vu0_v4 D_L39_0024AC90[] __attribute__((section(".sdata")));
extern void func_003888C8(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern u8 *func_L39_0061B038(void *);
extern s32 func_L39_005B6970(void *);

/* localdecomp:start func_L39_0052E8D8 */
#include "vu0.h"

extern u8 *D_L39_002417C0;
typedef struct { u8 pad0[0x24]; u8 *f24; u8 pad28[0x70]; s32 f98; u8 pad9C[0x64]; } E_0052EE60;
extern E_0052EE60 *D_L39_0024C05C;
extern s32 D_L39_0024145C;
extern u8 *D_L39_002638C0[];
typedef struct { u8 pad[0x16C]; s32 w16C; } W_0052EE60;
extern W_0052EE60 D_001A5E50;
__asm__(".extern D_L39_0024AC90, 8");
__asm__(".extern D_L39_002440A0, 16");
__asm__(".extern D_L39_0024AC50_0052E8D8, 4");
__asm__(".extern D_L39_0024ACD0_0052E8D8, 8");
extern vu0_v4 D_L39_0024ACD0_0052E8D8 __attribute__((section(".sdata")));

extern void func_00388E78(void *, void *);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_003883C8(void *);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_L01_00442070(f32);
extern f32 func_003BEB48(f32, f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_0040C1F8(void *, void *, f32);
extern void func_L01_0040C188(void *, void *, f32);
extern s32 func_003CF790(void *, s32, f32, void *, s32);
extern s32 func_L39_005B6970(void *);
extern f32 func_L01_0040C018(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern u8 *func_L39_0061B038(void *);
extern s32 func_L39_0052DFC8(u8 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32 *, s32, vu0_v4 *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_00664930(void *, u32, s32, s32);
extern void func_L39_00664E28(void *, void *, s32);
extern void func_L39_00625860(void *, s32);
extern void func_L39_00664B10(void *, void *, s32);
extern void func_L39_0052D998(A_0052DF20 *);
extern void func_00388758(void *, void *, void *);
extern void func_L39_00667AC0(void *, f32);

typedef struct M_0052EE60 {
    u8 pad0[0x1A0];
    s32 f1A0;
    u8 pad1A4[0x8];
    s32 f1AC;
} M_0052EE60;
typedef struct T_0052EE60 {
    u8 pad0[0x14];
    u8 * vt;
    u8 pad18[0xF8];
    vu0_v4 vel;
    u8 pad120[0x200];
    s16 f320;
    u8 pad322[0xCAE];
    f32 yaw;
    u8 padFD4[0xA36];
    u8 f1A0A;
    u8 pad1A0B[0x9];
    u8 f1A14;
    u8 pad1A15[0xA53];
    f32 f2468;
    u8 pad246C[0xB8];
    u8 * f2524;
    u8 pad2528[0xC];
    M_0052EE60 * m;
    f32 f2538;
    f32 f253C;
    f32 f2540;
    u8 pad2544[0x14];
    M_0052EE60 * f2558;
} T_0052EE60;
typedef struct C_0052EE60 {
    u8 pad0[0x1B0];
    vu0_v4 m1B0;
    u8 pad1C0[0x70];
    vu0_v4 v230;
    vu0_v4 v240;
    vu0_v4 v250;
    vu0_v4 v260;
    vu0_v4 vel;
    u8 pad280[0x8];
    f32 f288;
    u8 pad28C[0x4C];
    T_0052EE60 * t;
    T_0052EE60 * u;
    u8 pad2E0[0x18];
    s32 f2F8;
    u8 pad2FC[0x4];
    u8 f300;
    u8 pad301[0x1];
    s16 f302;
    u8 pad304[0x4];
    s32 f308;
    u8 pad30C[0x4];
    f32 f310;
} C_0052EE60;
typedef struct S_0052EE60 {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f6C;
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    f32 f84;
    f32 f88;
} S_0052EE60;
typedef struct G_0052EE60 {
    u8 pad0[0x620];
    vu0_v4 v620;
    u8 pad630[0x20];
    f32 f650;
    f32 f654;
    f32 f658;
    u8 pad65C[0x4];
    vu0_v4 v660[4];
    f32 f6A0;
    f32 f6A4;
    f32 f6A8;
    u8 pad6AC[0x24];
    C_0052EE60 * c;
    f32 f6D4;
    f32 f6D8;
    f32 f6DC;
    u8 pad6E0[0x18];
    f32 f6F8;
    u8 pad6FC[0x4];
    f32 f700;
    u8 pad704[0x8];
    f32 f70C;
    u16 f710;
    u8 pad712[0x1];
    u8 f713;
    u8 f714;
    u8 pad715[0x5];
    s16 f71A;
    s16 f71C;
    s16 f71E;
    S_0052EE60 * s;
    u8 pad724[0x68];
    u16 f78C;
    u8 pad78E[0x21];
    u8 f7AF;
    u8 pad7B0[0x4];
    s32 f7B4[7];
} G_0052EE60;
typedef struct A_0052EE60 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x48];
    G_0052EE60 * g;
    u8 pad6C[0x50];
    u8 fBC;
    u8 padBD[0x3];
    vu0_v4 mtx[3];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} A_0052EE60;


typedef void (*Fn_0052EE60)(void *, s32, s32, s32, s32);

static __inline__ void vzero_0052EE60(vu0_v4 *v) {
    qzero(v);
}

typedef s32 (*Probe_0052EE60)(u8 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, f32, f32, s32 *, f32, s32, vu0_v4 *);

void func_L39_0052E8D8(u8 *a0) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 oldpos;
    vu0_v4 v30;
    vu0_v4 vel;
    u8 *list[12];
    vu0_v4 v80;
    vu0_v4 outv[4];
    f32 tmp;
    s32 out;
    A_0052EE60 *o;
    G_0052EE60 *g;
    C_0052EE60 *c;
    S_0052EE60 *s;
    T_0052EE60 *t;
    M_0052EE60 *m;
    T_0052EE60 *u = 0;
    u8 *e = 0;
    u8 *r = 0;
    u8 *base = 0;
    f32 *yawp;
    s32 neg;
    s32 cnt = 0;
    s32 x;
    s32 i = 0;
    s32 j = 0;
    s32 n = 0;
    s32 k = 0;
    s16 id = 0;
    f32 yaw0;
    f32 spd = 0.0f;
    f32 ratio = 0.0f;
    f32 accel = 0.0f;
    f32 a = 0.0f;
    f32 b = 0.0f;
    f32 turn = 0.0f;
    f32 lim = 0.0f;

    o = (A_0052EE60 *)a0;
    neg = 0;
    m = 0;
    yawp = 0;
    g = o->g;
    yaw0 = o->fF8;
    c = g->c;
    x = 1;
    t = c->t;
    out = 0;
    if (g->s == 0) {
        return;
    }
    s = g->s;
    if (o->fBC == 0xB && (g->f710 & 8)) {
        return;
    }
    if (t != 0 && t->f1A14 == 0 && t->f2558 != 0 && !(t->f2558->f1AC & 4)) {
        t = 0;
    }
    if (D_L39_002417C0 != 0 && ((s8 *)D_L39_002417C0)[0x18F] == 0) {
        x = 0;
    }
    if (x) {
        base = (u8 *)D_L39_0024C05C;
        for (i = 0; i < 7; i++) {
            if (g->f7B4[i] != -1) {
                e = base + (g->f7B4[i] << 8);
                *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
            }
        }
    }
    if (t != 0) {
        yawp = &t->yaw;
        m = t->m;
        if (t->f320 > 0) {
            vzero_0052EE60(&vel);
            a = 0.0f;
            t = 0;
        } else {
            *(vu0_q *)&vel = *(vu0_q *)&t->vel;
            a = t->f2468;
        }
    } else {
        a = 0.0f;
        vzero_0052EE60(&vel);
    }
    func_00388E78(&c->m1B0, o->mtx);
    if (c->f310 < 0.0f) {
        neg = 1;
    }
    *(vu0_q *)&oldpos = *(vu0_q *)&o->pos;
    for (i = 0; i < 4; i++) {
        vzero_0052EE60(&g->v660[i]);
    }
    accel = s->f0C;
    if (t != 0) {
        yaw0 = *yawp;
        tmp = vel.x * a * s->f18;
        if (c->f300) {
            tmp = tmp * 0.15f;
        }
        if (neg) {
            *yawp = func_003893C8(o->fF8, tmp * 0.017453292f * 0.016666668f);
        } else {
            *yawp = func_00389380(o->fF8, tmp * 0.017453292f * 0.016666668f);
        }
        if ((m->f1A0 & 0x40) && !(g->f710 & 8)) {
            g->f78C += 1;
            a = s->f30;
            b = s->f34;
            if (D_L39_0024145C == 0x15CC || D_L39_0024145C == 0xBC2 || D_L39_0024145C == 0x18) {
                if ((m->f1A0 & 4) || (g->f710 & 2)) {
                    if (func_003883C8(&g->f71E) != 0) {
                        g->f710 &= ~2;
                    }
                    a = a + a;
                    accel = s->f10;
                }
            }
            if (m->f1A0 & 4) {
                accel = accel * 0.8f;
            }
            if (g->f713) {
                a = 0.12f;
                b = 0.1f;
                accel = 23.5f;
            }
            func_L01_00445168(&c->f310, &g->f6D4, accel * 0.016666668f, a, b, s->f2C * 0.00027777778f);
        } else {
            g->f78C -= 2;
        }
        if (!(g->f710 & 1) && (m->f1A0 & 4) && 0.05f < fabs_asm(vel.x)) {
            g->f710 |= 1;
            g->f70C = o->fF8;
            g->f71C = 0;
        }
        if ((((m->f1A0 & 0x80) && !(g->f710 & 8)) || ((g->f710 & 8) && 0.0f < c->f310)) && c->f300 == 0) {
            if (c->f310 <= 0.0f) {
                func_L01_00445168(&c->f310, &g->f6D4, s->f14 * 0.016666668f, s->f3C, s->f40, s->f38 * 0.00027777778f);
            } else if ((m->f1A0 & 0x40) && !(g->f710 & 8)) {
                func_L01_00445168(&c->f310, &g->f6D4, s->f0C * 0.6f * 0.016666668f, s->f30, s->f34, s->f2C * 0.00027777778f);
            } else {
                func_L01_00445168(&c->f310, &g->f6D4, 0.0f, s->f54, s->f58, s->f50 * 0.00027777778f);
            }
        }
        if (!(m->f1A0 & 0xC0)) {
            func_L01_00445168(&c->f310, &g->f6D4, 0.0f, s->f48, s->f4C, s->f44 * 0.00027777778f);
        }
    } else if (c->f300 == 0) {
        func_L01_00445168(&c->f310, &g->f6D4, 0.0f, s->f54, s->f58, s->f50 * 0.00027777778f);
    }
    if (c->f310 < 0.0f) {
        neg = 1;
        spd = -c->f310;
    } else {
        spd = c->f310;
    }
    if ((neg == 0 && c->f310 < 0.0015f) || (t == 0 && fabs_asm(c->f310) < 0.0025f)) {
        spd = 0.0f;
        c->f310 = spd;
    }
    ratio = spd / (accel * 0.016666668f);
    if (1.0f < ratio) {
        ratio = 1.0f;
    }
    if (t == 0) {
        a = s->f70;
    } else if (c->f300) {
        a = s->f74;
    } else {
        tmp = func_L01_00442070(fabs_asm(vel.x));
        if (g->f710 & 1) {
            g->f71C += 1;
            a = func_003BEB48(s->f70, s->f74, tmp);
        } else if (g->f71A < 0x14 && g->f700 < s->f80) {
            a = s->f7C;
        } else if (0.5f < ratio) {
            a = func_003BEB48(s->f70, s->f78, tmp);
        } else {
            a = s->f70;
        }
    }
    tmp = func_00389468(o->fF8, func_00388A28(c->vel.x, c->vel.y));
    if (a < g->f6D8) {
        func_003BEBF8(&g->f6D8, a, g->f700 * 5.0f);
    } else {
        func_003BEBF8(&g->f6D8, a, g->f700);
    }
    a = s->f1C;
    b = s->f20;
    if ((g->f710 & 1) && 20.0f < (f32)g->f71C) {
        if (c->f302 >= 0x1A || ratio < 0.5f || s->f70 * 0.15f <= g->f6D8) {
            tmp = func_00389468(o->fF8, g->f70C);
            g->f710 &= ~1;
            if (g->f71C >= 0xB && 0.43633232f < tmp) {
                g->f710 |= 2;
                g->f71E = 0x1E;
            }
        }
    }
    turn = func_003BEB48(s->f04 * 0.017453292f * 0.016666668f, s->f00 * 0.017453292f * 0.016666668f, ratio);
    lim = (1.0f - ratio) + 1.0f;
    if (1.9f < lim) {
        lim = 1.9f;
    }
    a = a * lim;
    if (neg) {
        a = a * 0.5f;
        turn = turn * 0.5f;
    }
    if (spd < s->f08 * 0.016666668f) {
        tmp = spd / (s->f08 * 0.016666668f);

        if (g->f714) {
            if (tmp < 0.7f) {
                tmp = 0.7f;
            }
        } else {
            if (tmp < 0.25f) {
                tmp = 0.25f;
            }
        }
        tmp = tmp * tmp;
        turn = turn * tmp;
    }
    if (g->f710 & 1) {
        a = a * 1.15f;
        turn = turn * 1.15f;
    }
    if (turn < 0.00029088821f) {
        turn = 0.00029088821f;
    }
    func_003BEBF8(&g->f6F8, turn, 0.0058177644f);
    if (t != 0) {
        if (c->f300) {
            if (yaw0 == *yawp) {
                c->f288 -= c->f288 * 0.016666668f;
                if (fabs_asm(c->f288) < 0.001f) {
                    c->f288 = 0.0f;
                }
                o->fF8 = func_00389380(o->fF8, c->f288);
            } else {
                tmp = c->f288;
                func_L01_004455F0(&o->fF8, *yawp, &tmp, a, b, g->f6F8, 0);
                if (tmp != 0.0f) {
                    c->f288 = tmp;
                }
            }
        } else {
            func_L01_004455F0(&o->fF8, *yawp, &c->f288, a, b, g->f6F8, 0);
        }
    } else {
        c->f288 -= c->f288 * 0.016666668f;
        if (fabs_asm(c->f288) < 0.005f) {
            c->f288 = 0.0f;
        }
        o->fF8 = func_00389380(o->fF8, c->f288);
    }
    vec_sub_ab(&c->vel, &c->vel, &g->f6A0);
    tmp = 0.0f;
    if (c->f300) {
        a = func_00388A28(c->vel.x, c->vel.y);
    } else {
        tmp = -o->fF4;
        if (neg) {
            a = func_00389380(o->fF8, 3.1415927f);
        } else {
            a = o->fF8;
        }
    }
    func_0037E4B8(&v0, spd, a, tmp);
    func_003886E8(&v0, &v0, g->f6D8);
    vec_add_ab(&c->vel, &c->vel, &v0);
    if (c->f300) {
        a = 9.0f;
        if (g->f713 == 0) {
            a = s->f24;
        }
        c->vel.z -= a * 0.00027777778f;
        func_L01_0040C1F8(&c->vel, &c->vel, spd);
    } else {
        c->vel.z -= s->f28 * 0.00027777778f;
        if (c->vel.z < s->f28 * -3.0f * 0.016666668f) {
            c->vel.z = s->f28 * -3.0f * 0.016666668f;
        }
        func_L01_0040C188(&c->vel, &c->vel, spd);
    }
    *(vu0_q *)&g->v620 = *(vu0_q *)&c->vel;
    g->f6A0 -= g->f6A0 * 0.058333337f;
    if (fabs_asm(g->f6A0) < 0.001f) {
        g->f6A0 = 0.0f;
    }
    g->f6A4 -= g->f6A4 * 0.058333337f;
    if (fabs_asm(g->f6A4) < 0.001f) {
        g->f6A4 = 0.0f;
    }
    g->f6A8 -= g->f6A8 * 0.058333337f;
    if (fabs_asm(g->f6A8) < 0.001f) {
        g->f6A8 = 0.0f;
    }
    vec_add_ab(&c->vel, &c->vel, &g->f6A0);
    n = func_003CF790(&o->pos, 0, 4.0f, a0, 0);
    cnt = 0;
    for (i = 0; i < n; i++) {
        if (func_L39_005B6970(D_L39_002638C0[i]) != 0) {
            if (func_L01_0040C018(D_L39_002638C0[i] + 0x10, &o->pos) < 4.0f) {
                v80.x = func_00388960(o->fF8) * 0.2f;
                v80.y = func_00388978(o->fF8) * 0.2f;
                v80.z = 0.0f;
                func_L01_00443938(D_L39_002638C0[i], a0, 0x10000, &o->pos, &v80, 1.0f);
            }
        } else {
            r = func_L39_0061B038(D_L39_002638C0[i]);
            if (r != 0) {
                id = *(s16 *)(D_L39_002638C0[i] + 0xAA);
                k = r[3] & 0xF;
                if (id == 0x107E || k == 0 || (k == 2 && id != 0x109F && id != 0x109D)) {
                    *(s32 *)(D_L39_002638C0[i] + 0x98) = 0;
                    list[cnt++] = D_L39_002638C0[i];
                }
            }
        }
    }
    g->f714 = 0;
    g->f7AF = 0;
    g->f7AF |= ((Probe_0052EE60)func_L39_0052DFC8)(a0, &o->pos, &c->vel, &v10, fabs_asm(c->f310), 0.2f, &out, 1.5f, 0, &outv[0]);
    g->f7AF |= ((Probe_0052EE60)func_L39_0052DFC8)(a0, &o->pos, &c->vel, &v10, fabs_asm(c->f310), 0.2f, &out, 1.5f, 1, &outv[1]) << 1;
    g->f7AF |= ((Probe_0052EE60)func_L39_0052DFC8)(a0, &o->pos, &c->vel, &v10, fabs_asm(c->f310), 0.2f, &out, 1.5f, 2, &outv[2]) << 2;
    g->f7AF |= ((Probe_0052EE60)func_L39_0052DFC8)(a0, &o->pos, &c->vel, &v10, fabs_asm(c->f310), 0.2f, &out, 1.5f, 3, &outv[3]) << 3;
    vec_add_ab(&o->pos, &o->pos, &c->vel);
    for (j = 0; j < 4; j++) {
        func_003888C8(&v0, &D_L39_0024AC90[j], o->mtx);
        vec_add_ab(&v0, &v0, &o->pos);
        if (func_003CE740(&outv[j], &v0, 2, a0, 0) != 0) {
            if (D_L39_0025F840.f18 == 0) {
                c->f308 = 0;
                func_L39_00664930(c, 0xFFFFFFFF, 6, D_001A5E50.w16C);
                if (t != 0) {
                    if (!(c->f2F8 & 0x4000000)) {
                        (*(Fn_0052EE60 *)(t->vt + 0x34))(t, 0x76, 0, 0, 0);
                        t->f1A0A = 1;
                    }
                    func_L39_00664E28(c, t, 0);
                    if (!(c->f2F8 & 0x4000000)) {
                        func_L39_00625860(t, 1);
                        t->f1A0A = 1;
                    }
                }
                if (c->u != 0) {
                    u = c->u;
                    if (!(c->f2F8 & 0x4000000)) {
                        (*(Fn_0052EE60 *)(u->vt + 0x34))(u, 0x76, 0, 0, 0);
                        u->f1A0A = 1;
                    }
                    func_L39_00664B10(c, u, 0);
                    if (!(c->f2F8 & 0x4000000)) {
                        func_L39_00625860(u, 1);
                        u->f1A0A = 1;
                    }
                }
            }
            break;
        }
    }
    func_L39_0052D998((A_0052DF20 *)g);
    for (i = 0; i < cnt; i++) {
        *(s32 *)(list[i] + 0x98) = *(s32 *)(*(u8 **)(list[i] + 0x24) + 0x10);
    }
    if (c->f300) {
        if (!neg) {
            func_003886E8(&v0, &D_L39_002440A0, -0.0015f);
            vec_add_ba(&g->v660[0], &g->v660[0], &v0);
            vec_add_ab(&g->v660[1], &g->v660[1], &v0);
        }
        c->f302 += 1;
        if (c->f302 >= 0x15) {
            g->f71A = 0;
        }
    } else {
        g->f71A += 1;
        if (g->f71A > 1000) {
            g->f71A = 1000;
        }
        if (c->f302 >= 0x1F) {
            g->f700 = s->f84;
        }
        func_003BEBF8(&g->f700, s->f80, s->f88 * 0.016666668f);
        c->f302 = 0;
        g->f6DC = o->pos.z;
    }
    for (i = 0; i < 4; i++) {
        vec_sub_ba(&v0, &D_L39_0024AC50_0052E8D8[i], &D_L39_0024ACD0_0052E8D8);
        func_00388758(&v30, &g->v660[i], &v0);
        g->f650 = func_00389380(g->f650, v30.x);
        g->f654 = func_00389380(g->f654, v30.y);
        g->f658 = func_00389380(g->f658, v30.z);
    }
    g->f650 -= g->f650 * 0.33333334f;
    if (fabs_asm(g->f650) < 0.0005f) {
        g->f650 = 0.0f;
    }
    g->f654 -= g->f654 * 0.33333334f;
    if (fabs_asm(g->f654) < 0.0005f) {
        g->f654 = 0.0f;
    }
    g->f658 -= g->f658 * 0.16666667f;
    if (fabs_asm(g->f658) < 0.0005f) {
        g->f658 = 0.0f;
    }
    o->fF0 = func_00389380(o->fF0, g->f650);
    if (0.9f < fabs_asm(o->fF0)) {
        if (o->fF0 < -0.9f) {
            o->fF0 = -0.9f;
            if (g->f650 < 0.0f) {
                g->f650 = 0.0f;
            }
        } else if (0.9f < o->fF0) {
            o->fF0 = 0.9f;
            if (0.0f < g->f650) {
                g->f650 = 0.0f;
            }
        }
    }
    o->fF4 = func_00389380(o->fF4, g->f654);
    if (0.9f < fabs_asm(o->fF4)) {
        if (o->fF4 < -0.9f) {
            o->fF4 = -0.9f;
            if (g->f654 < 0.0f) {
                g->f654 = 0.0f;
            }
        } else if (0.9f < o->fF4) {
            o->fF4 = 0.9f;
            if (0.0f < g->f654) {
                g->f654 = 0.0f;
            }
        }
    }
    o->fF8 = func_00389380(o->fF8, g->f658);
    if (t != 0) {
        *(vu0_q *)(t->f2524 + 0x10) = *(vu0_q *)&o->pos;
        *(vu0_q *)(t->f2524 + 0xF0) = *(vu0_q *)&o->fF0;
    }
    if (c->u != 0) {
        *(vu0_q *)(c->u->f2524 + 0x10) = *(vu0_q *)&o->pos;
        *(vu0_q *)(c->u->f2524 + 0xF0) = *(vu0_q *)&o->fF0;
    }
    func_L39_00667AC0(c, 50.0f);
    if (c->f2F8 & 4) {
        if (t != 0 && t->f1A14) {
            t->f2538 = o->pos.x;
            t->f253C = o->pos.y;
            t->f2540 = o->pos.z;
        }
        if (c->u != 0 && c->u->f1A14) {
            c->u->f2538 = o->pos.x;
            c->u->f253C = o->pos.y;
            c->u->f2540 = o->pos.z;
        }
        *(vu0_q *)&c->v230 = *(vu0_q *)&o->pos;
        *(vu0_q *)&c->v240 = *(vu0_q *)&o->fF0;
    }
    *(vu0_q *)&c->v250 = *(vu0_q *)&o->pos;
    *(vu0_q *)&c->v260 = *(vu0_q *)&o->fF0;
    if (x) {
        for (i = 0; i < 7; i++) {
            if (g->f7B4[i] != -1) {

                ((E_0052EE60 *)((u8 *)D_L39_0024C05C + (g->f7B4[i] << 8)))->f98 = 0;
            }
        }
    }
}
/* localdecomp:end func_L39_0052E8D8 */
