#include "common.h"

/* NTSC-U counterpart of func_L39_0066A028 (src/levels/shared/L39_00668D60.c): frame counter D_001A5F78, w2F0 threshold 0x1F (PAL 0x1A) */
/* localdecomp:start func_L39_00667750 */
typedef int u128_t __attribute__((mode(TI)));
typedef union Vec_00667750 {
    u128_t q;
    f32 f[4];
} Vec_00667750;
typedef union Buf_00667750 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_00667750;
typedef struct S_00667750 { s32 a, b, c, d, e, f, g; } S_00667750;
typedef struct Ent_00667750 {
    s32 a, b, c, d, e;
    void (*f)(void *);
    s32 g;
} Ent_00667750;
typedef struct Tgt_00667750 {
    u8 pad0[0x10];
    u128_t q10;
    u8 pad20[0xBC - 0x20];
    u8 bBC;
    u8 padBD[3];
    u128_t qC0;
    u128_t qD0;
    u128_t qE0;
    u128_t qF0;
} Tgt_00667750;
typedef struct Obj_00667750 {
    u8 pad0[0x210];
    Vec_00667750 q210;
    Vec_00667750 q220;
    u8 pad230[0x2D0 - 0x230];
    Tgt_00667750 *p2D0;
    u8 pad2D4[0x2E4 - 0x2D4];
    s32 w2E4;
    u8 pad2E8[0x2F8 - 0x2E8];
    s32 w2F8;
    s16 h2FC;
    u8 pad2FE[0x328 - 0x2FE];
    s32 w328;
} Obj_00667750;
typedef struct Sub2530_00667750 {
    u8 pad0[0x27B];
    u8 b27B;
} Sub2530_00667750;
typedef struct Sub2534_00667750 {
    u8 pad0[0x1A4];
    s32 w1A4;
} Sub2534_00667750;
typedef struct Ply_00667750 {
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
    Obj_00667750 *p2528;
    u8 pad252C[4];
    Sub2530_00667750 *p2530;
    Sub2534_00667750 *p2534;
    u8 pad2538[0x254C - 0x2538];
    s32 w254C;
} Ply_00667750;

extern u8 D_L39_004998A0[];
extern s32 D_001A5F78[];
extern S_00667750 D_L39_0033AC08[];
extern void func_L39_0061EBD0(void *);
extern void func_L01_0045D318(void *);
extern void func_L39_00665D88(void *, void *, s32);
extern void func_L39_00664B10(void *, void *, s32);
extern void func_L39_0061A850(void *, void *, void *, s32, s32);
extern f32 func_00389468(f32, f32);
extern void func_L39_006647E8(void *, s32, s32, s32, s32);

static __inline__ u32 DecU_00667750(u8 *q) {
    Buf_00667750 buf;
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
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        x = buf.w[0] ^ (u32)q;
        buf.w[0] = x;
        buf.w[1] ^= x;
        r = buf.w[1];
    }
    return r;
}

static __inline__ f32 DecF_00667750(u8 *q) {
    Buf_00667750 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    x = buf.w[0] ^ (u32)q;
    buf.w[0] = x;
    buf.w[1] ^= x;
    return buf.f[1];
}

static __inline__ s32 LeF_00667750(u8 *q, f32 v) {
    return DecF_00667750(q) <= v;
}

void func_L39_00667750(Ply_00667750 *a, s32 a1) {
    Obj_00667750 *o;
    Vec_00667750 v;
    s32 cur;
    u8 host;

    if (a->w254C != 6) {
        return;
    }
    o = a->p2528;
    if (o == 0) {
        return;
    }
    if (D_L39_0033AC08[o->h2FC].f != 0) {
        ((Ent_00667750 *)D_L39_0033AC08)[o->h2FC].f(o->p2D0);
    }
    if (a->b1A14 == 0) {
        return;
    }
    cur = D_001A5F78[0];
    if (!(o->w2F8 & 0x8000000)) {
        a->w2450 = 0x1D;
    }
    a->qA0 = o->p2D0->q10;
    a->qB0 = o->p2D0->qF0;
    a->q20 = o->p2D0->qC0;
    a->q30 = o->p2D0->qD0;
    a->q40 = o->p2D0->qE0;
    func_L39_0061EBD0(a);
    if (a1 == 0 && o->p2D0->bBC != 0xB) {
        if ((a->w2F0 >= 0x1F && (a->p2534->w1A4 & 0x10)) || (u8)LeF_00667750(&a->b2476, 0.0f) || (host = (a->p2530 != 0 ? (a->p2530->b27B != 0 && (DecU_00667750(&a->b19E4) ^ 0x31) == 0) : 0))) {
            func_L01_0045D318(a->p2534);
            o->w328 = a->b24C9 + 1;
            func_L39_00665D88(o, &v, 0);
            func_L39_00664B10(o, a, 1);
            func_L39_0061A850(a, &v, &a->qB0, 1, 0);
        }
    }
    if (cur >= o->w2E4 + 0x39) {
        if (func_00389468(o->q220.f[0], o->q210.f[0]) > 0.03f ||
            func_00389468(o->q220.f[1], o->q210.f[1]) > 0.03f ||
            func_00389468(o->q220.f[2], o->q210.f[2]) > 0.03f) {
            o->w2E4 = cur;
            func_L39_006647E8(o, cur, 0, 0, 1);
            o->q220 = o->q210;
        }
    }
}
/* localdecomp:end func_L39_00667750 */
