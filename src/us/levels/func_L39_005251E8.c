#include "common.h"

/* NTSC-U counterpart of func_L39_00525690 (src/levels/shared/L39_00524E00.c): 60 Hz values (15 and 0x17 frames, 1/60 s steps) */
/* localdecomp:start func_L39_005251E8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005251E8;
typedef union { u8 b[16]; u32 w[4]; u16 h[8]; } Buf_005251E8;
typedef struct { V_005251E8 r[4]; } M_005251E8;
typedef struct { u8 pad0[0x2F8]; u32 w2F8; } P2528_005251E8;
typedef struct { u8 pad0[0x27B]; u8 b27B; } P2530_005251E8;
typedef struct G_005251E8 G_005251E8;
typedef struct { u8 pad0[0x34]; void (*f34)(G_005251E8 *, s32, s32, s32, s32); } VT_005251E8;
struct G_005251E8 {
    u8 pad0[0x14];
    VT_005251E8 *vt;
    u8 pad18[0x380 - 0x18];
    u8 m380[0x1078 - 0x380];
    void *p1078;
    u8 pad107C[0x122C - 0x107C];
    u8 *p122C;
    u8 pad1230[0x1250 - 0x1230];
    f32 f1250;
    u8 pad1254[0x1310 - 0x1254];
    s32 w1310;
    u8 pad1314[0x1338 - 0x1314];
    u8 m1338[4];
    u8 m133C[0x19E4 - 0x133C];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 b1A08;
    u8 pad1A09[0x1A14 - 0x1A09];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 m1A40;
    u8 b1A41;
    u8 pad1A42[0x23C0 - 0x1A42];
    u8 m23C0[0x2460 - 0x23C0];
    G_005251E8 *p2460;
    u8 b2464;
    u8 pad2465[0x24C9 - 0x2465];
    u8 b24C9;
    u8 pad24CA[0x2524 - 0x24CA];
    void *p2524;
    P2528_005251E8 *p2528;
    u8 pad252C[0x2530 - 0x252C];
    P2530_005251E8 *p2530;
    u8 pad2534[0x2544 - 0x2534];
    s32 w2544;
    s32 w2548;
    void *p254C;
};
typedef struct {
    V_005251E8 pos;
    u8 *p10;
    f32 f14;
    f32 f18;
    s16 h1C;
    s16 h1E;
    u8 pad20[0x38 - 0x20];
    f32 f38;
    u8 pad3C[0x44 - 0x3C];
    s32 w44;
    f32 f48;
    f32 f4C;
    s32 w50;
    G_005251E8 *g;
    u8 b58;
    s8 b59;
    u8 b5A;
    u8 pad5B;
    s32 w5C;
} V68_005251E8;
typedef struct {
    u8 pad0[0x10];
    V_005251E8 pos;
    u8 b20;
    u8 pad21[0x43 - 0x21];
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    V68_005251E8 *v;
    u8 pad6C[0xC0 - 0x6C];
    V_005251E8 mC0;
    V_005251E8 mD0;
} O_005251E8;
typedef struct { f32 f0; s16 h4; u8 pad6[0xE - 6]; u8 bE; u8 padF[0x17 - 0xF]; u8 b17; } I_005251E8;
typedef struct { u8 pad0[0x21]; s8 b21; u8 pad22[0x30 - 0x22]; f32 f30; u8 pad34[0x80 - 0x34]; } E_005251E8;
typedef struct { u8 pad0[0xD0]; u8 bD0; u8 padD1[0xDC - 0xD1]; void *pDC; u8 padE0[0x80 - 0xE0 + 0x80]; } S_005251E8;

extern s32 D_L39_002412AC;
__asm__(".extern D_L39_0024AB10, 4");
extern s32 D_L39_0024AB10;
__asm__(".extern D_L39_0024AB14, 4");
extern void *D_L39_0024AB14;
extern u8 D_L39_004998A0[];
extern u8 D_L39_00483AC0[];
extern G_005251E8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern void *D_L39_002638C0[];
extern E_005251E8 D_L39_0049C950[];
extern u8 D_L39_001FE1A0[];
extern f32 D_L39_0024AB38;
extern f32 D_L39_0024AB3C;
extern s32 D_L39_0024AB30;
extern s32 D_L39_0024AB34;

extern void func_L39_00619D58(void *, void *);
extern void func_L39_005D8B38(s32, f32, s32);
extern s32 func_L39_00637548(void *);
extern s32 func_L39_00524958(void *, s32);
extern s32 func_L39_005FD580(f32, f32 *, s32 *, s32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_003883C8(void *);
extern s32 func_L39_00670988(void *, s32, s32, s32);
extern s32 func_L39_00670B50(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L39_0061F5C0(void *, s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388E78(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L39_006719D8(void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L39_005FD658(s32);
extern s32 func_003CF790(void *, f32, s32, void *, s32);
extern void func_L39_005FD6D8(void);
extern s32 func_00388398(void *);
extern u8 *func_0037E0B8(void *);
extern s32 func_L39_00646268(u8 *, s32);
extern f32 func_003BEB48(f32, f32, f32);
extern s32 func_L01_0044EAB8(void *, s32, s32, f32);
extern void func_L39_005D8BA0(s32, f32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_00556B80(void *, void *);
extern u8 *func_L39_00528090(u8 *, s32);
extern void func_L39_00525E98(void *);
extern s32 func_L39_005F08A0(void *, s32);
extern void func_L39_005F0988(s32);
extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern void func_L39_0061FAE8(void *);

static __inline__ u32 dec_005251E8(u8 *q) {
    Buf_005251E8 buf;
    s32 n, k, m, i;
    u8 *d;
    u32 a, b;

    if (*q == 0) return 0;
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}


static __inline__ E_005251E8 *ent_005251E8(G_005251E8 *g, s32 id) {
    return func_L39_00646268((u8 *)g, id) ? &D_L39_0049C950[D_L39_0049C950[id].b21] : &D_L39_0049C950[id];
}

static __inline__ G_005251E8 *pl_005251E8(void *m) {
    u8 *x = (u8 *)func_L39_0061B038(m);
    if (x != 0 && (x[3] & 0xF) == 0) return (G_005251E8 *)x;
    return 0;
}

void func_L39_005251E8(O_005251E8 *o) {
    V68_005251E8 *v = o->v;
    G_005251E8 *g = v->g;
    void *target = 0;
    I_005251E8 *info = 0;
    G_005251E8 *h1;
    s32 one;
    G_005251E8 *h2;
    G_005251E8 *h3;

    D_L39_0024AB10 = D_L39_002412AC;
    D_L39_0024AB14 = o;
    if (o->b20 == 0) {
        v->f38 = 1.0f;
        func_L39_00619D58(o, &v->g);
        g = v->g;
        o->b20 = 1;
        v->b59 = -1;
        v->w5C = -1;
        v->b5A = 0;
        if (v->g->b1A14) func_L39_005D8B38(0, 0.0f, v->g->b24C9);
    }
    if (func_L39_00637548(g)) {
        u8 hit;
        s32 r = func_L39_005FD580(150.0f, (f32 *)g->m1338, (s32 *)g->m133C, hit = g->f1250 >= 0.7f && func_L39_00524958(g->p122C, g->w2548));
        if (g->b1A14) {
            func_L01_003F4D78(g->b24C9, o, r, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    func_003883C8(&v->h1C);
    one = 1;
    func_L39_00670988(&g->m1A40, 0, one, 0);
    if ((u8)func_L39_00670B50(&g->m1A40, 0)) {
        if (o->b43 != 2) func_003BE4F0(o, 2, 0, 0);
        if (g->b1A07 == 0) func_L39_0061F5C0(g, -1);
        if (v->h1E == 0) v->h1E = one;
        if (v->h1C == 0) v->h1C = 15;
        func_003BDA38(o, 0, v);
        if ((dec_005251E8(&g->b19E4) ^ 1) == 0) g->vt->f34(g, 0x1D, 1, 0, 1);
        {
        V_005251E8 dir;
        *(vu0_q *)&dir = 0;
        {
            if ((dec_005251E8(&g->b19E4) ^ 0x1D) == 0) {
                M_005251E8 m;
                func_00388E78(&m, g->m23C0);
                dir.z = 1.0f;
                func_003888F0(&dir, &dir, &m);
            } else if (g->b1A08 == 1) {
                func_003886E8(&dir, &o->mD0, -1.0f);
            } else {
                dir.x = 1.0f;
                func_003888C8(&dir, &dir, g->m380);
            }
        }
        v->f48 = func_00388A28(dir.x, dir.y);
        v->f4C = func_00388A28(func_003887A0(&dir), dir.z);
        if (g->b1A14 == 0) {
            func_L39_006719D8(g);
            if (g->p1078 != 0 && func_L39_00524958(g->p1078, g->w2548)) target = g->p1078;
        }
        {
        if (v->g->w1310 != 0 && v->g->b1A14 != 0) {
            if (v->g->p122C != 0) {
                if (g->f1250 > 0.7f && func_003887C8(v, v->g->p122C + 0x10) < 12.0f) {
                    if (func_L39_00524958(g->p122C, g->w2548)) target = v->g->p122C;
                } else if (func_L01_0040C018(v, v->g->p122C + 0x10) < 6.25f) {
                    V_005251E8 a;
                    V_005251E8 b;
                    void *p;
                    G_005251E8 *e;
                    s32 id;
                    s32 n, i;
                    void **pp;

                    func_003886E8(&a, &o->mD0, -1.35f);
                    vec_add_ba(&a, &a, &o->pos);
                    func_003886E8(&b, &o->mC0, -0.275f);
                    vec_add_ab(&a, &a, &b);
                    p = g->p2524;
                    id = g->w2544;
                    e = D_L39_0024CF20[id];
                    id = e != 0 ? e->w2548 : -1;
                    func_L39_005FD658(id);
                    n = func_003CF790(&a, 1.5f, 1, p, 0);
                    func_L39_005FD6D8();
                    pp = D_L39_002638C0;
                    for (i = 0; i < n; i++) {
                        if (*pp != g->p2524 && func_L39_00524958(*pp, g->w2548)) {
                            target = *pp;
                            break;
                        }
                        pp++;
                    }
                }
            }
        } else if (target == 0) {
            V_005251E8 tmp = v->pos;
            target = func_L39_00524B88(o, &tmp, &v->f48, &v->f4C);
        }
        }
        func_00388398(&v->w44);
        if (v->p10 != 0) {
            u8 host;
            h1 = pl_005251E8(v->p10);
            if (v->p10 == 0 || v->p10[0x20] == 0xFE || v->p10[0x20] == 0xFD
                || (h1 != 0 && ((h1->p2528 != 0 && !(h1->p2528->w2F8 & 0x4000000))
                    || (host = h1->p2530 != 0 ? (h1->p2530->b27B != 0 && (dec_005251E8(&h1->b19E4) ^ 0x31) == 0) : 0)))) {
                v->p10 = 0;
                v->w44 = 0;
            }
        }
        if (target != 0 || v->w44 != 0) {
            E_005251E8 *e;
            if (target != 0) {
                info = (I_005251E8 *)func_0037E0B8(target);
                if (target != v->p10 && v->w44 == 0) {
                    v->p10 = target;
                    v->f14 = info->h4;
                    v->f18 = info->f0;
                    v->w44 = 0x17;
                    if (v->f14 <= 1.0f) v->f18 = 0.0f;
                }
                g->p1078 = target;
            }
            {
            f32 rate = 1.2f;
            e = ent_005251E8(g, 9);
            v->f18 -= e->f30 * 0.016666668f * rate;
            }
            if (v->f18 < 0.0f) v->f18 = 0.0f;
            v->f38 = v->f18 / v->f14;
        } else {
            v->f38 = 1.0f;
        }
        {
            s32 r = func_L01_0044EAB8(&v->w50, D_L39_0024AB30, D_L39_0024AB34,
                                      func_003BEB48(D_L39_0024AB38, D_L39_0024AB3C, v->f38) * 0.017453292f * 0.016666668f);
            if (g->b1A14) func_L39_005D8B38(r, v->f38, g->b24C9);
        }
        h2 = pl_005251E8(v->p10);
        if (h2 != 0 && h2->b1A14) func_L39_005D8BA0(h2->b24C9, v->f38);
        if (v->p10 != 0 && v->f18 <= 0.0f) {
            func_L39_005F0CE0(3, 0, o);
            h3 = pl_005251E8(v->p10);
            if (h3 != 0) {
                if (((h3->p2528 == 0 && h3->p254C == 0) || (h3->p2528 != 0 && (h3->p2528->w2F8 & 0x4000000))) && info != 0) {
                    u8 *q;
                    u16 bits;
                    info->b17 = 9;
                    q = &g->b1A41;
                    if (*q == 0) {
                        bits = 0;
                    } else {
                        Buf_005251E8 buf;
                        s32 n, k, m, i;
                        u8 *d;
                        u32 a0, b0;
                        n = *q;
                        k = ((u32)q - n) & 7;
                        m = n + 1;
                        d = buf.b;
                        for (i = 0; i < 24; i += 3) {
                            *d++ = D_L39_00483AC0[((k + i) & 7) * 209 + m];
                        }
                        a0 = buf.w[0] ^ (u32)q;
                        b0 = buf.w[1] ^ a0;
                        buf.w[0] = a0;
                        buf.w[1] = (b0 >> 16) / (((b0 ^ (b0 >> 16)) << 16) + 1);
                        bits = buf.h[2];
                    }
                    h3->p2460 = g;
                    h3->b2464 = (bits >> 9) & 1;
                    if (info->bE == 1) {
                        if (func_L39_005B24C8(1, 2) == 1) info->bE = 4;
                        else info->bE = 2;
                    }
                }
            } else {
                s32 ok = 1;
                if (info != 0 && info->bE == 2) ok = 0;
                if (ok) {
                    if (func_L39_005B24C8(1, 2) == 1) func_L39_00556B80(v->p10, g);
                    else func_L39_00528090(v->p10, (s32)g);
                }
                v->p10 = 0;
            }
        }
        func_L39_00525E98(o);
        if (func_L39_005F08A0(o, v->w5C) == 0) v->w5C = func_L39_005F0CE0(1, 4, o);
        }
    } else {
        v->b58 = one;
        v->p10 = 0;
        v->h1E = 0;
        v->w44 = 0;
        if (v->w5C >= 0) {
            s32 id = v->w5C;
            if (id != -1 && ((S_005251E8 *)(D_L39_001FE1A0 + (id << 7)))->pDC == o && ((S_005251E8 *)(D_L39_001FE1A0 + (id << 7)))->bD0 != 0) {
                func_L39_005F0988(id);
            }
            v->w5C = -1;
        }
        if (o->b60 & 2) func_L01_00441E00((u8 *)o, 1, 0, 1, 0);
        func_L39_0061FAE8(g);
        if (g->b1A14) {
            f32 t = func_003BEB48(D_L39_0024AB38, D_L39_0024AB3C, v->f38) * 0.017453292f * 0.016666668f;
            s32 r = func_L01_0044EAB8(&v->w50, D_L39_0024AB30, D_L39_0024AB34, t);
            func_L39_005D8B38(r, 1.0f, g->b24C9);
        }
    }
}
/* localdecomp:end func_L39_005251E8 */
