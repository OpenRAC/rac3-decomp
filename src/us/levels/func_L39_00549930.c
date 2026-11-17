#include "common.h"

/* NTSC-U counterpart of func_L39_0054A250 (src/levels/shared/L39_0054A250.c) */
/* localdecomp:start func_L39_00549930 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    s32 a[5];
} V20_0054A250;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    void *p68;
} O_0054A250;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
} P_0054A250;
typedef struct {
    u8 pad0[0x10];
    void *(*fn10)(void *);
} Vt_0054A250;
typedef struct {
    u8 pad0[0x14];
    Vt_0054A250 *vt;
} R_0054A250;
typedef struct {
    u8 pad0[0x1A4];
    s32 w1A4;
} Q_0054A250;
typedef struct {
    u8 pad0[0x2D8];
    s16 h2D8;
    u8 pad2DA[0x30C - 0x2DA];
    s32 w30C;
    u8 pad310[0x3B0 - 0x310];
    f32 v3B0[4];
    u8 pad3C0[0x3E0 - 0x3C0];
    P_0054A250 *p3E0;
    u8 pad3E4[0x460 - 0x3E4];
    s32 w460;
    u8 pad464[0x1310 - 0x464];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 pad1A08[0x1A14 - 0x1A08];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 b1A40[1];
    u8 pad1A41[0x24FE - 0x1A41];
    u8 b24FE;
    u8 pad24FF;
    u8 b2500;
    u8 pad2501[0x2524 - 0x2501];
    s32 w2524;
    u8 pad2528[0x2534 - 0x2528];
    Q_0054A250 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 w2544;
} E_0054A250;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s32 w34;
    u8 pad38[0x3C - 0x38];
    s32 w3C;
    E_0054A250 *p40;
    void *p44;
} M_0054A250;
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
typedef struct {
    u8 pad0[0x26];
    u8 b86;
    u8 pad27[0x2C - 0x27];
    u32 w8C;
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x50 - 0x48];
} W_0054A250;
typedef struct {
    u8 pad0[0x10];
    u128_t q10;
} Z_0054A250;
typedef struct {
    u8 pad0[0x10];
    u128_t q10;
    u8 pad20[0x100 - 0x20];
    u8 big[16];
} S_0054A250;
typedef struct {
    f32 pos[3];
    s32 w;
    s32 x;
} L_0054A250;

extern void func_003BDA38(void *, s32, void *);
extern void func_L01_00441E00(void *, s32, s32, s32, s32);
extern f32 *func_0037E0B8(void *);
extern s32 func_L39_00644C00(void *);
extern void *func_L39_005B8FF0(void *, void *, void *, s32, s32, f32, f32, f32, f32, f32, s32, s32, void *, s32, s32, s32);
extern void func_L39_005FBF00(f32, f32, f32, f32, void *, void *, void *, void *, s32);
extern s32 func_L39_005FC5C0(void *, void *, void *, void *, void *, void *, s32, s32, s32, s32, f32);
extern void func_L39_00619D58(void *, void *);
extern void func_L39_0061FAE8(void *);
extern s32 func_L39_00670988(void *, s32, s32, void *);
extern R_0054A250 *func_L39_0061AA60(s32);
extern void func_L39_0061F5C0(void *, s32);
extern s32 func_L01_003F0118(void *, void *);
extern void func_L39_0054C618(void *, void *, void *, s32, s32, void *);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern s32 func_L39_00646268(void *, s32);
extern void func_L01_003F0338(s32, void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L39_00549FC0(u8 *);

extern f32 D_L39_0024B120;
__asm__(".extern D_L39_0024B120, 4");
extern f32 D_L39_0024B124;
__asm__(".extern D_L39_0024B124, 4");
extern f32 D_L39_0024B128;
__asm__(".extern D_L39_0024B128, 4");
extern f32 D_L39_0024B12C;
__asm__(".extern D_L39_0024B12C, 4");
typedef union {
    u8 b[16];
    u32 w[4];
    f32 f[4];
} Buf_0054A250;

extern u8 D_L39_004998A0[];

static inline u32 Dec_0054A250(u8 *q, Buf_0054A250 *bp) {
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
    d = bp->b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = bp->w[0] ^ (u32)q;
    b = bp->w[1] ^ a;
    bp->w[0] = a;
    bp->w[1] = b;
    return b;
}

static inline s32 DecEq_0054A250(u8 *q, s32 v, Buf_0054A250 *bp) {
    return Dec_0054A250(q, bp) == v;
}

static inline s32 Busy_0054A250(E_0054A250 *s, Buf_0054A250 *bp) {
    return DecEq_0054A250(&s->b19E4, 1, bp) || DecEq_0054A250(&s->b19E4, 0x1D, bp) ||
           s->b24FE != 0 || s->b2500 != 0;
}
extern V20_0054A250 D_L39_0024B130;
extern s32 D_L39_0024D628[8] __attribute__((section(".sdata")));
extern u8 D_L39_00470680[];
extern T_0054A250 D_L39_0049C950[];

void func_L39_00549930(O_0054A250 *obj) {
    M_0054A250 *m = obj->p68;
    E_0054A250 *e = m->p40;
    f32 vec[4];
    Buf_0054A250 v30;
    L_0054A250 loc;
    W_0054A250 w;
    S_0054A250 sx;
    u8 flag;
    s32 r;

    if (e != 0) {
        if (e->b1A14 != 0) {
            func_003BDA38(obj, 0, vec);
        }
    }
    if (obj->b42 == obj->b43 && (obj->b60 & 2)) {
        func_L01_00441E00(obj, 1, 0, 2, 0);
    }
    m->p44 = 0;
    if (e != 0) {
        P_0054A250 *p = e->p3E0;
        if (p != 0 && p->b20 != 254 && p->b20 != 253) {
            f32 *q = func_0037E0B8(p);
            if (q != 0 && 0.0f < *q) {
                m->p44 = e->p3E0;
            }
        }
        if (e->b1A14 != 0) {
            flag = Busy_0054A250(e, &v30);
            if (flag == 0 && e->w1310 == 0 && m->p44 == 0) {
                *(V20_0054A250 *)&loc = D_L39_0024B130;

                r = func_L39_00644C00(e);
                m->p44 = func_L39_005B8FF0(vec, &e->v3B0, sx.big, 0, 0, 0.3926991f, 0.7853982f, 11.1f, 0.0f, 0.0f, r, 0, &loc, 1, e->h2D8, 0);
            }
        }
    }
    if (e != 0) {
        if (e->b1A14 != 0) {
            func_L39_005FBF00(D_L39_0024B124, D_L39_0024B120, D_L39_0024B12C * 0.01666666753590107f, D_L39_0024B128 * 0.00027777778450399637f, e, (u8 *)m + 0x20, vec, m->p44, 0);
            m->w34 = func_L39_005FC5C0(e, vec, (u8 *)m + 0x20, m, (u8 *)m + 0x10, obj, 1, 0, 0, 0,
                                       D_L39_0024B128 * 0.00027777778450399637f);
        }
    }
    switch (obj->b20) {
    case 0:
        func_L39_00619D58(obj, &m->p40);
        e = m->p40;
        obj->b20 = 1;
        m->w3C = -1;
    case 1:
        if (e == 0) {
            return;
        }
        if (e->w30C >= 21) {
            func_L39_0061FAE8(e);
        }
        r = func_L39_00670988(e->b1A40, 0, 1, &w);
        if (r == 8) {
            if (e->b1A14 == 0) {
                func_003BDA38(obj, 0, vec);
            }
            if (w.b86 & 0x80) {
                v30.f[0] = w.f9C;
                v30.f[1] = w.fA0;
                v30.f[2] = w.fA4;
                v30.f[3] = 0;
            } else {
                loc.pos[0] = w.f90;
                loc.pos[1] = w.f94;
                loc.pos[2] = w.f98;
                loc.w = 0;
                if (w.w8C != 0xFFFFFFFF) {
                    R_0054A250 *rr = func_L39_0061AA60(w.w8C);
                    Z_0054A250 *zz = rr ? rr->vt->fn10(rr) : 0;
                    if (zz != 0) {
                        *(u128_t *)&loc = zz->q10;
                    }
                }
                sx.q10 = *(u128_t *)&loc;
                func_L39_005FBF00(D_L39_0024B124, D_L39_0024B120, D_L39_0024B12C * 0.01666666753590107f, D_L39_0024B128 * 0.00027777778450399637f, e, &v30, vec, &sx, 0);
            }
            D_L39_0024D628[e->w2544] = 1;
            func_L39_0061F5C0(e, -1);
            m->w3C = func_L01_003F0118(D_L39_00470680, e->p2534);
            func_L01_00441E00(obj, 2, 0, 2, 0);
            func_L39_0054C618(obj, vec, &v30, 0, e->w2524, e);
            func_L39_005F0CE0(0, 0, obj);
            {
                T_0054A250 *t;
                if (func_L39_00646268(e, 5)) {
                    u8 *d = (u8 *)D_L39_0049C950;
                    t = (T_0054A250 *)(d + (((s8 *)d)[0x2A1] << 7));
                } else {
                    u8 *d = (u8 *)D_L39_0049C950;
                    t = (T_0054A250 *)(d + 0x280);
                }
                m->f30 = 1.0f / t->f28;
            }
        } else if (r == 4) {
            if ((e->p2534->w1A4 & e->w460) != 0 || D_L39_0024D628[e->w2544] == 1) {
                func_L39_005F0CE0(1, 0, obj);
                D_L39_0024D628[e->w2544] = 0;
            }
        }
        if (r != 8 || e->b1A07 == 0) {
            if (m->w3C >= 0) {
                func_L01_003F0338(m->w3C, e->p2534);
                m->w3C = -1;
            }
        }
        obj->b20 = 1;
        break;
    }
    if (e->b1A14 != 0) {
        func_L01_004026A0(func_L39_00549FC0, obj);
    }
}
/* localdecomp:end func_L39_00549930 */
