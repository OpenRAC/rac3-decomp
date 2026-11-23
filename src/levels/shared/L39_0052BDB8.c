#include "common.h"

/* declared by functions of L39_0052BCA8.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L39_0052BDB8 */
#include "vu0.h"
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_0024AAB0, 8");
__asm__(".extern D_L39_0024AAC0, 8");
__asm__(".extern D_L39_0024AAD0, 4");
extern s32 *D_L39_00241120;
extern u8 D_L39_004997E0[];
__asm__(".extern D_L39_0024AAF0, 16");
__asm__(".extern D_L39_0024AB00, 16");
__asm__(".extern D_L39_00242930, 16");
extern vu0_v4 D_L39_0024AAF0 __attribute__((section(".sdata")));
extern vu0_v4 D_L39_0024AB00 __attribute__((section(".sdata")));
extern vu0_v4 D_L39_00242930 __attribute__((section(".sdata")));
extern u8 D_L39_0024AAB0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L39_0024AAC0[] __attribute__((section(".sdata")));
extern f32 D_L39_0024AAD0;
typedef struct {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0052BDB8;
extern Glob_0052BDB8 D_001A5810;
typedef struct {
    u8 p0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_0052BDB8;
typedef struct {
    u8 p0[0x10];
    vu0_v4 v10;
    u8 p20[0x25B];
    u8 b27B;
} Q_0052BDB8;
typedef struct {
    s32 f0;
    u8 p4[0x10];
    VT_0052BDB8 *f14;
    u8 p18[0x88];
    vu0_v4 vA0;
    vu0_v4 vB0;
    u8 pC0[0x11C2];
    u16 u1282;
    u8 p1284[0x760];
    u8 b19E4;
    u8 p19E5[0x1];
    u8 b19E6;
    u8 p19E7[0x2D];
    u8 b1A14;
    u8 p1A15[0xAB4];
    u8 b24C9;
    u8 p24CA[0x66];
    Q_0052BDB8 *f2530;
    u8 p2534[0x10];
    s32 f2544;
} P_0052BDB8;
typedef struct {
    u8 p0[0xBC];
    u8 bBC;
} D_0052BDB8;
typedef struct {
    u8 p0[0xB0];
    vu0_v4 vB0;
    u8 pC0[0x144];
    f32 f204;
    f32 f208;
    u8 p20C[0x24];
    vu0_v4 v230;
    u8 p240[0x4];
    f32 f244;
    f32 f248;
    u8 p24C[0x4];
    vu0_v4 v250;
    vu0_v4 v260;
    u8 p270[0x18];
    u8 b288[16];
    f32 f298;
    u8 p29C[0x34];
    D_0052BDB8 *f2D0;
    u8 p2D4[0x4];
    P_0052BDB8 *f2D8;
    u8 p2DC[0x1C];
    u32 f2F8;
} G_0052BDB8;
typedef struct {
    u8 *f0;
    u8 p4[0x6C];
    f32 f70;
    s16 s74;
    u8 p76[0x8];
    u8 b7E;
    u8 p7F[0x1];
    f32 f80;
    u8 p84[0x1E];
    u8 bA2;
    u8 pA3[0x1D];
    P_0052BDB8 *fC0;
    u8 pC4[0xC];
    u8 bD0[16];
    u8 pE0[0x58];
    f32 f138;
    u8 p13C[0x14];
    u8 b150[16];
    u8 p160[0x58];
    f32 f1B8;
    u8 p1BC[0x24];
    f32 f1E0;
    u8 p1E4[0x4];
    f32 f1E8;
    u8 p1EC[0x8];
    s32 f1F4;
    G_0052BDB8 *f1F8;
    s32 f1FC;
    u8 b200[16];
    u8 p210[0x20];
    u8 b230[16];
    u8 p240[0x4C];
    s32 f28C;
    u8 p290[0x20];
    f32 f2B0;
    f32 f2B4;
    f32 f2B8;
    u8 p2BC[0x4];
    vu0_v4 v2C0;
    vu0_v4 v2D0;
    s16 s2E0;
    s16 s2E2;
    void (*f2E4)(void);
    u8 p2E8[0x38];
    f32 f320;
    f32 f324;
    u8 p328[0x4];
    s32 f32C;
    u8 p330[0x8];
    s32 f338;
} T_0052BDB8;
typedef struct {
    u8 p0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 p21[0x3];
    u8 *f24;
    u8 p28[0x8];
    u8 b30;
    u8 p31[0x1];
    s16 s32;
    u16 u34;
    u8 p36[0x2C];
    u8 b62;
    u8 p63[0x5];
    T_0052BDB8 *f68;
    u8 p6C[0x24];
    G_0052BDB8 *f90;
    u8 p94[0x2A];
    u8 bBE;
    u8 pBF[0x1];
    u8 bC0[16];
    u8 pD0[0x20];
    vu0_v4 vF0;
} O_0052BDB8;

typedef union { u8 b[8]; u32 w[2]; vu0_v4 v; } Buf_0052BDB8;

static __inline__ u32 Dec_0052BDB8(u8 *q, Buf_0052BDB8 *buf) {
    u32 r;
    s32 n;
    s32 m;
    s32 k;
    s32 i;
    u8 *d;

    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        m = n + 1;
        k = ((s32)q - n) & 7;
        d = buf->b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf->w[0] ^= (u32)q;
        buf->w[1] ^= buf->w[0];
        r = buf->w[1];
    }
    return r;
}

static __inline__ s32 IsState_0052BDB8(P_0052BDB8 *p, u32 st, Buf_0052BDB8 *buf) {
    u8 r;

    if (p->f2530 != 0) {
        r = 0;
        if (p->f2530->b27B != 0 && (Dec_0052BDB8(&p->b19E4, buf) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}
extern void func_003C2880(void *);
extern f32 func_L01_004513A8(void *, void *, void *);
extern void func_L39_0061C1E0(void *, s32);
extern void func_L39_0052BD50(void *);
extern void func_L39_00668C90(s32, void (*)(void *), s32, s32, s32, s32, s32, s32);
extern G_0052BDB8 *func_L39_00666FB8(f32, s32, void *, u32, s32, s32);
extern s32 func_L39_0061BF68(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00412E70(void *, void *, void *, f32, f32);
extern void func_L39_00570200(s32, void *, void *, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_L01_004561B8(void *);
extern void func_L06_0042B660(void *, void *, f32);
extern void func_L01_00448728(void *, void *, void *, f32, f32, f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, f32, f32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L39_005BE878(s32, void *, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L39_00667208(void *, s32, s32, s32);
extern void func_L39_0066A8C8(void *, void *);
extern void func_L39_005F3088(s32);
extern void func_L39_0052CB90(void *);
extern void func_L39_0052CD40(void *);
extern void func_L39_0052D1C0(void *);
extern void func_L39_0052CF70(void *);
extern void func_L39_0052CA90(void *);
extern void func_L39_00648258(void);
extern u8 D_L39_001FE020[];

void func_L39_0052BDB8(O_0052BDB8 *o) {
    T_0052BDB8 *st = o->f68;
    G_0052BDB8 *g = st->f1F8;
    P_0052BDB8 *p;
    vu0_v4 vc;
    Buf_0052BDB8 tm;
    vu0_v4 vb;

    if (st->bA2 == 1) {
        func_003C2880(o);
        return;
    }
    p = 0;
    if (g != 0) {
        p = g->f2D8;
        if (p != 0) {
            st->fC0 = p;
        }
    }
    if (*D_L39_00241120 >= 2) {
        o->b62 = 1;
    }
    switch (o->b20) {
    case 0: {
        T_0052BDB8 *t = o->f68;
        t->f0 = &t->f70;
        o->u34 |= 0x5020;
        t->s74 = 0x32;
        t->b7E = 3;
        t->f70 = 50.0f;
        t->f80 = 2.0f;
        o->f24[0x46] = 5;
        func_L01_004513A8(&o->v10, o, &o->v10);
        o->bBE &= 0xE7;
        func_L39_0061C1E0(o, -1);
        func_L39_00668C90(2, func_L39_0052BD50, 0, 0, 0, 0, 0, 0);
        g = func_L39_00666FB8(2.0f, 2, o, 0xFFFFFFFF, 0xBB8, 0x17100008);
        t->f1F8 = g;
        o->f90 = g;
        o->s32 = 0x1FF;
        o->b30 = 0xFF;
        func_L39_0052BD50(o);
        func_L01_004450F0(o, 1, -1);
        break;
    }
    case 1:
    case 5:
        if (o->b20 == 1) {
            if (func_L39_0061BF68(g->f2D8) >= 0) {
                func_0038D000(&tm.v, &D_L39_0024AAF0, o->bC0);
                vec_add_ab(&tm.v, &tm.v, &o->v10);
                p->f14->f34(p, 0x8F, 1, 0, 1);
                st->f1FC = p->b24C9;
                func_L39_00570200(p->b24C9, p->f2530, &p->f2530->v10, 3, 0x3C, 0);
                func_0038D000(&vb, D_L39_0024AAB0, o->bC0);
                vec_add_ba(&vb, &vb, &o->v10);
                func_L01_00412E70(st->b200, &vb, o, o->vF0.z, 0.0f);
                st->s2E0 = 1;
                if (D_001A5810.bA4[g->f2D8->f2544] == 0) {
                    st->s2E0 = 9;
                }
                st->f2B4 = 1.0471976f;
                st->f2B8 = -0.87266463f;
                st->v2D0.y = D_L39_0024AAD0 * 0.017453292f;
                st->f320 = 120.0f;
                st->f324 = func_0038CEA8(D_L39_0024AAC0);
                st->s2E2 = p->u1282;
                st->f32C = p->b24C9;
                st->f338 = p->f2544;
                st->f2E4 = func_L39_00648258;
                st->v2C0 = D_L39_0024AAC0[0];
                st->v2D0 = D_L39_00242930;
                func_L01_004450F0(o, 2, -1);
                break;
            } else {
                if (g->f2D8 != 0) {
                    *(vu0_q *)&g->v250 = *(vu0_q *)&o->v10;
                    func_0038D000(&vc, &D_L39_0024AB00, o->bC0);
                    vec_add_ab(&g->v250, &g->v250, &vc);
                    *(vu0_q *)&g->v260 = *(vu0_q *)&o->vF0;
                    g->f2D8->f14->f34(g->f2D8, 0x8F, 1, 0, 1);
                    func_L01_004450F0(o, 3, -1);
                }
            }
        }
        if (fabs_asm(o->v10.z - g->f298 + 1.0f) > 0.01f) {
            func_003C41A0(&o->v10.z, &st->f1E8, g->f298 - 1.0f, 0.00080000004f, 0.00080000004f, 0.040000003f);
        }
        break;
    case 2:
        if (func_L01_004561B8(o) != 0) {
            func_L39_005F33E0(3, 0, o);
            st->f1E0 = 0;
        }
        func_003C41A0(&o->v10.z, &st->f1E8, g->f298, 0.0024f, 0.0024f, 0.120000005f);
        if (g->f2D8 == 0 || (u8)IsState_0052BDB8(g->f2D8, 0x31, &tm)) {
            if (g->f2D8 != 0 && (u8)IsState_0052BDB8(g->f2D8, 0x31, &tm) && g->f2D8->b1A14 != 0) {
                func_L39_00667208(g, g->f2D8->f0, 4, -1);
            }
            func_L39_0052CB90(o);
            func_L01_004450F0(o, 1, -1);
            if (st->f1F4 != -1) {
                u8 *e = D_L39_001FE020 + st->f1F4 * 128;
                if (*(void **)(e + 0xDC) == o && e[0xD0] != 0) {
                    func_L39_005F3088(st->f1F4);
                }
            }
            st->f1F4 = -1;
        } else {
            ((void (*)(void *, s32))func_L39_0052CD40)(o, 0);
            func_L39_0052D1C0(o);
            func_L39_0052CF70(o);
            func_L39_0052CA90(o);
            if (fabs_asm(o->v10.z - g->f298) <= st->f1E8) {
                func_L01_004450F0(o, 4, -1);
            }
        }
        break;
    case 3:
        func_L06_0042B660(&o->v10, &g->vB0, 0.040000003f);
        func_L01_00448728(&o->vF0.z, g->b288, 0, g->f208, 0.036000002f, 0.21600002f, 0.06283186f);
        if (g->f2D8 == 0) {
            func_L01_004450F0(o, 1, -1);
        } else {
            func_0038D000(&tm.v, &D_L39_0024AAF0, o->bC0);
            vec_add_ab(&tm.v, &tm.v, &o->v10);
            *(vu0_q *)&g->v250 = *(vu0_q *)&tm.v;
            *(vu0_q *)&g->f2D8->vA0 = *(vu0_q *)&tm.v;
            *(vu0_q *)&g->v260 = *(vu0_q *)&o->vF0;
            *(vu0_q *)&g->f2D8->vB0 = *(vu0_q *)&o->vF0;
        }
        st->f138 = g->f204;
        st->f1B8 = g->f204;
        func_L01_0044E850(o, st->bD0, 2, 0.014400001f, 0.15f);
        func_L01_0044E850(o, st->b150, 3, 0.014400001f, 0.15f);
        break;
    case 4:
        if (g->f2D0->bBC == 10) break;
        if (st->f2B0 >= 0.9f) {
            f32 t;
            f32 f;
            u32 c;
            func_L01_003F6F20(st->f1FC, o, 0x600F0FFF, 0, 0x21, 1.0f, 0.0f, -1, 4, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            func_L39_005BE878(st->f28C, &tm.v, 0);
            t = (st->f2B0 - 0.9f) / (1.0f - 0.9f);
            if (t > 1.0f) {
                t = 1.0f;
            } else if (t < 0.0f) {
                t = 0.0f;
            }
            c = func_0038DBD8(0xFF0FFFFF, 0xFF0F0FFF, t);
            f = func_0038CF00(st->b230, &tm.v);
            func_L01_003F6F20(st->f1FC, o, c, &tm.v, 0x26, fabs_asm(0.9f - f / 150.0f * 0.65f), 0.0f, -1, 4, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        } else {
            func_L01_003F6F20(st->f1FC, o, 0x600FFF0F, 0, 0x21, 1.0f, 0.0f, -1, 4, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
        if (g->f2D8 == 0 || (u8)IsState_0052BDB8(g->f2D8, 0x31, &tm) || (Dec_0052BDB8(&g->f2D8->b19E6, &tm) ^ 0x14) == 0) {
            if (g->f2D8 != 0 && g->f2D8->b1A14 != 0 &&
                ((u8)IsState_0052BDB8(g->f2D8, 0x31, &tm) || (Dec_0052BDB8(&g->f2D8->b19E6, &tm) ^ 0x14) == 0)) {
                func_L39_00667208(g, g->f2D8->f0, 4, -1);
            }
            func_L39_0052CB90(o);
            func_L01_004450F0(o, 1, -1);
            if (st->f1F4 != -1) {
                u8 *e = D_L39_001FE020 + st->f1F4 * 128;
                if (*(void **)(e + 0xDC) == o && e[0xD0] != 0) {
                    func_L39_005F3088(st->f1F4);
                }
            }
            st->f1F4 = -1;
        } else {
            ((void (*)(void *, s32))func_L39_0052CD40)(o, 1);
            func_L39_0052D1C0(o);
            func_L39_0052CF70(o);
            func_L39_0052CA90(o);
            *(vu0_q *)&g->v230 = *(vu0_q *)&o->v10;
            g->f248 = o->vF0.z;
            g->f244 = st->f1E0;
            g->f2F8 |= 0x800;
        }
        break;
    case 6:
    case 7:
        break;
    }
    func_L39_0066A8C8(g, o);
}
/* localdecomp:end func_L39_0052BDB8 */
