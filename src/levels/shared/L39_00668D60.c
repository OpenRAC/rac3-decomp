#include "common.h"

/* localdecomp:start func_L39_00668D60 */
typedef struct Vt_00668D60 { u8 pad0[0x34]; void (*f34)(void *, s32, s32, s32, s32); } Vt_00668D60;
typedef struct Sub_00668D60 { u8 pad0[0x98]; s32 w98; } Sub_00668D60;
typedef struct Ply_00668D60 {
    u8 pad0[0x14];
    Vt_00668D60 *vt;
    u8 pad18[0x1A0A - 0x18];
    u8 b1A0A;
    u8 pad1A0B[0x1A14 - 0x1A0B];
    u8 b1A14;
    u8 pad1A15[0x2524 - 0x1A15];
    Sub_00668D60 *p2524;
    u8 pad2528[0x2534 - 0x2528];
    s32 w2534;
} Ply_00668D60;
typedef struct Obj_00668D60 {
    u8 pad0[0x10];
    u8 pos10[0x24];
    u16 h34;
    u8 pad36[0x96 - 0x36];
    s16 h96;
    s32 w98;
    u8 pad9C[0xA8 - 0x9C];
    u8 bA8;
    u8 padA9;
    s16 hAA;
    u8 padAC[0xBC - 0xAC];
    u8 bBC;
} Obj_00668D60;
typedef struct Tgt_00668D60 {
    u8 pad0[0x20];
    Obj_00668D60 *o20;
    u8 pad24[5];
    u8 b29;
} Tgt_00668D60;
typedef struct Slf_00668D60 {
    u8 pad0[0x270];
    u8 pos270[0x60];
    Obj_00668D60 *o2D0;
    u8 pad2D4[4];
    Ply_00668D60 *p2D8;
    Ply_00668D60 *p2DC;
    u8 pad2E0[8];
    s32 w2E8;
    u8 pad2EC[0x2F8 - 0x2EC];
    s32 w2F8;
    u8 pad2FC[0x308 - 0x2FC];
    f32 f308;
    u8 pad30C[0x328 - 0x30C];
    s32 w328;
} Slf_00668D60;

extern Tgt_00668D60 *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L39_00626998(void *, void *, s32);
extern s32 func_00132100(f32);
extern void func_L39_00667208(void *, u32, s32, s32);
extern s32 func_L39_0061BF68(void *);
extern void func_L01_003F1F20(s32, s32);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern u8 D_001A5E38[];
extern s32 D_001A5E3C[];
extern s32 D_001A5DF8[];
extern f32 D_001DAAEC_sda;
extern f32 D_001DAAF0_sda;
__asm__(".extern D_001DAAEC_sda, 4");
__asm__(".extern D_001DAAF0_sda, 4");

void func_L39_00668D60(Slf_00668D60 *s) {
    Tgt_00668D60 *t;
    f32 f;
    f32 g;
    f32 vec[4];
    Ply_00668D60 *x;
    s32 r;

    t = func_L01_00447490(s->o2D0, -1, 0);
    if (t != 0 && t->o20 != 0) {
        if ((s->p2D8 != 0 && func_L39_00626998(s->p2D8, t->o20, 0) == 0) ||
            (s->p2DC != 0 && func_L39_00626998(s->p2DC, t->o20, 0) == 0)) {
            s->o2D0->bA8 = 0xFF;
            return;
        }
    }
    f = func_L01_004474E8(s->o2D0, t);
    if (f != 0.0f) {
        if ((s->p2D8 == 0 && s->p2DC == 0 && D_001A5E38[0] != 0) || (s->p2D8 != 0 && s->p2D8->b1A14 != 0) ||
            (s->p2DC != 0 && s->p2DC->b1A14 != 0)) {
            if (t->b29 >= 3 && (t->o20 == 0 || t->o20->hAA != 0x15A5)) {
                f *= 2.2f;
            }
            g = s->f308 - f;
            if (s->p2D8 != 0) {
                func_L39_00626998(s->p2D8, t->o20, 0);
            }
            if (s->p2DC != 0) {
                func_L39_00626998(s->p2DC, t->o20, 0);
            }
            func_L39_00667208(s, func_00132100(g), 0xF, -1);
        }
    }
    if (s->f308 < 0.0f) {
        s->f308 = 0.0f;
    }
    if (s->f308 <= 0.0f) {
        func_L39_00667208(s, 0xFFFFFFFF, 6, D_001A5E3C[0]);
    }
    s->o2D0->bA8 = 0xFF;
    if ((s->o2D0->bBC == 9 && D_001A5DF8[0] >= s->w2E8) || (s->o2D0->bBC == 0xB && s->w2E8 <= 0)) {
        s->o2D0->w98 = 0;
        s->o2D0->h34 |= 0x41;
        if (s->p2D8 != 0) {
            r = func_L39_0061BF68(s->p2D8);
            if (r >= 0) {
                s->w328 = r + 1;
            }
            if (s->w2F8 & 0x4000000) {
                s->p2D8->vt->f34(s->p2D8, 0x39, 1, 0, 1);
            } else {
                s->p2D8->p2524->w98 = 0;
                s->p2D8->b1A0A = 1;
            }
            if (s->p2D8->b1A14 != 0) {
                func_L01_003F1F20(0x1C, s->p2D8->w2534);
            }
        }
        if (s->p2DC != 0) {
            r = func_L39_0061BF68(s->p2DC);
            if (r >= 0) {
                s->w328 = r + 1;
            }
            if (s->w2F8 & 0x4000000) {
                s->p2DC->vt->f34(s->p2DC, 0x39, 1, 0, 1);
            } else {
                s->p2DC->p2524->w98 = 0;
                s->p2DC->b1A0A = 1;
            }
            if (s->p2DC->b1A14 != 0) {
                func_L01_003F1F20(0x1C, s->p2DC->w2534);
            }
        }
        if (s->o2D0->hAA == 0x10C2) {
            func_L39_005F3488(0, 0, s->o2D0, 0x10C2);
        }
        func_0038CF68(vec, s->pos270, 0.10000001f);
        if (s->o2D0->bBC != 0xB) {
            func_L01_003303B8(s->o2D0->pos10, 1, 25, 20, 20, 20, 45, 2, 1.5f, 10.0f, D_001DAAEC_sda, D_001DAAF0_sda,
                              0, 0, 0, 0, 1, 0, 0x1010001, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00452310(s->o2D0, 0x3FF, vec, 1, 35, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
        } else {
            func_L01_00451FE0(s->o2D0, 0x3FF, vec, 0xFF, 1.0f, 1.5f, 0.5f, 0.75f, 1.0f, 0xB4, 0, 0, 0x23, -1.0f, 1.0f, 1.0f, 0, 3);
        }
        s->o2D0->bBC = 0xA;
        s->o2D0->h96 = 0;
    }
}
/* localdecomp:end func_L39_00668D60 */

INCLUDE_ASM("asm/levels", func_L39_006692A0);

/* localdecomp:start func_L39_0066A028 */
typedef int u128_t __attribute__((mode(TI)));
typedef union Vec_0066A028 {
    u128_t q;
    f32 f[4];
} Vec_0066A028;
typedef union Buf_0066A028 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_0066A028;
typedef struct S_0066A028 { s32 a, b, c, d, e, f, g; } S_0066A028;
typedef struct Ent_0066A028 {
    s32 a, b, c, d, e;
    void (*f)(void *);
    s32 g;
} Ent_0066A028;
typedef struct Tgt_0066A028 {
    u8 pad0[0x10];
    u128_t q10;
    u8 pad20[0xBC - 0x20];
    u8 bBC;
    u8 padBD[3];
    u128_t qC0;
    u128_t qD0;
    u128_t qE0;
    u128_t qF0;
} Tgt_0066A028;
typedef struct Obj_0066A028 {
    u8 pad0[0x210];
    Vec_0066A028 q210;
    Vec_0066A028 q220;
    u8 pad230[0x2D0 - 0x230];
    Tgt_0066A028 *p2D0;
    u8 pad2D4[0x2E4 - 0x2D4];
    s32 w2E4;
    u8 pad2E8[0x2F8 - 0x2E8];
    s32 w2F8;
    s16 h2FC;
    u8 pad2FE[0x328 - 0x2FE];
    s32 w328;
} Obj_0066A028;
typedef struct Sub2530_0066A028 {
    u8 pad0[0x27B];
    u8 b27B;
} Sub2530_0066A028;
typedef struct Sub2534_0066A028 {
    u8 pad0[0x1A4];
    s32 w1A4;
} Sub2534_0066A028;
typedef struct Ply_0066A028 {
    u8 pad0[0x20];
    u128_t q20;
    u128_t q30;
    u128_t q40;
    u8 pad50[0xA0 - 0x50];
    u128_t qA0;
    u128_t qB0;
    u8 padC0[0x2F0 - 0xC0];
    s32 w2F0;
    u8 pad2F4[0x19E4 - 0x2F4];
    u8 b19E4;
    u8 pad19E5[0x1A14 - 0x19E5];
    u8 b1A14;
    u8 pad1A15[0x2450 - 0x1A15];
    s32 w2450;
    u8 pad2454[0x2476 - 0x2454];
    u8 b2476;
    u8 pad2477[0x24C9 - 0x2477];
    u8 b24C9;
    u8 pad24CA[0x2528 - 0x24CA];
    Obj_0066A028 *p2528;
    u8 pad252C[4];
    Sub2530_0066A028 *p2530;
    Sub2534_0066A028 *p2534;
    u8 pad2538[0x254C - 0x2538];
    s32 w254C;
} Ply_0066A028;

extern u8 D_L39_004997E0[];
extern S_0066A028 D_L39_0033AB08[];
extern void func_L39_00621370(void *);
extern void func_L01_004606A8(void *);
extern void func_L39_00668660(void *, void *, s32);
extern void func_L39_006673E8(void *, void *, s32);
extern void func_L39_0061CFC8(void *, void *, void *, s32, s32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_006670C0(void *, s32, s32, s32, s32);

static __inline__ u32 DecU_0066A028(u8 *q) {
    Buf_0066A028 buf;
    u32 r;

    if (*q == 0) {
        r = 0;
    } else {
        u32 x;
        s32 n = *q;
        s32 k = ((u32)q - n) & 7;
        s32 m = n + 1;
        s32 i;
        u8 *d = buf.b;

        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        x = buf.w[0] ^ (u32)q;
        buf.w[0] = x;
        buf.w[1] ^= x;
        r = buf.w[1];
    }
    return r;
}

static __inline__ f32 DecF_0066A028(u8 *q) {
    Buf_0066A028 buf;
    u32 x;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    x = buf.w[0] ^ (u32)q;
    buf.w[0] = x;
    buf.w[1] ^= x;
    return buf.f[1];
}

static __inline__ s32 LeF_0066A028(u8 *q, f32 v) {
    return DecF_0066A028(q) <= v;
}

void func_L39_0066A028(Ply_0066A028 *a, s32 a1) {
    Obj_0066A028 *o;
    Vec_0066A028 v;
    s32 cur;
    u8 host;

    if (a->w254C != 6) {
        return;
    }
    o = a->p2528;
    if (o == 0) {
        return;
    }
    if (D_L39_0033AB08[o->h2FC].f != 0) {
        ((Ent_0066A028 *)D_L39_0033AB08)[o->h2FC].f(o->p2D0);
    }
    if (a->b1A14 == 0) {
        return;
    }
    cur = D_001A5DF8[0];
    if (!(o->w2F8 & 0x8000000)) {
        a->w2450 = 0x1D;
    }
    a->qA0 = o->p2D0->q10;
    a->qB0 = o->p2D0->qF0;
    a->q20 = o->p2D0->qC0;
    a->q30 = o->p2D0->qD0;
    a->q40 = o->p2D0->qE0;
    func_L39_00621370(a);
    if (a1 == 0 && o->p2D0->bBC != 0xB) {
        if ((a->w2F0 >= 0x1A && (a->p2534->w1A4 & 0x10)) || (u8)LeF_0066A028(&a->b2476, 0.0f) || (host = (a->p2530 != 0 ? (a->p2530->b27B != 0 && (DecU_0066A028(&a->b19E4) ^ 0x31) == 0) : 0))) {
            func_L01_004606A8(a->p2534);
            o->w328 = a->b24C9 + 1;
            func_L39_00668660(o, &v, 0);
            func_L39_006673E8(o, a, 1);
            func_L39_0061CFC8(a, &v, &a->qB0, 1, 0);
        }
    }
    if (cur >= o->w2E4 + 0x39) {
        if (func_0038DBA0(o->q220.f[0], o->q210.f[0]) > 0.03f ||
            func_0038DBA0(o->q220.f[1], o->q210.f[1]) > 0.03f ||
            func_0038DBA0(o->q220.f[2], o->q210.f[2]) > 0.03f) {
            o->w2E4 = cur;
            func_L39_006670C0(o, cur, 0, 0, 1);
            o->q220 = o->q210;
        }
    }
}
/* localdecomp:end func_L39_0066A028 */
