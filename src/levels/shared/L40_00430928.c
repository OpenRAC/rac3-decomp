#include "common.h"

/* localdecomp:start func_L40_00430928 */
typedef int u128_00430928 __attribute__((mode(TI)));
typedef union Buf_00430928 {
    u8 b[8];
    u32 w[2];
} Buf_00430928;
typedef struct V_00430928 {
    f32 x, y, z, w;
} V_00430928 __attribute__((aligned(16)));

typedef struct P_00430928 {
    u8 pad0[0x2D8];
    struct G_00430928 *p2D8;
} P_00430928;

typedef struct G_00430928 {
    u8 pad0[0x19E4];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A14 - 0x19E7];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x251C - 0x24CA];
    void *p251C;
    u8 pad2520[0x2528 - 0x2520];
    P_00430928 *p2528;
    u8 pad252C[0x2530 - 0x252C];
    u8 *p2530;
} G_00430928;

typedef struct Q_00430928 {
    u128_00430928 q0;
    s32 w10;
    s16 h14;
    s16 h16;
    s32 w18;
    u8 pad1C[0x20 - 0x1C];
    u128_00430928 q20;
} Q_00430928;

typedef struct O_00430928 {
    u8 pad0[0x10];
    u128_00430928 q10;
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 pad31[0x34 - 0x31];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Q_00430928 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
    u8 padAC[0xC0 - 0xAC];
    u8 bC0[0x30];
    u128_00430928 qF0;
} O_00430928;

typedef struct R_00430928 {
    u8 pad0[0x28];
    s32 w28;
} R_00430928;

typedef struct W_00430928 {
    u8 pad0[0x180];
    s32 w180;
    u8 pad184[0x196 - 0x184];
    s8 b196;
} W_00430928;

__asm__(".extern D_L40_00241640, 16");
extern W_00430928 *D_L40_00241640;
extern G_00430928 *D_L40_00249330[] __attribute__((section(".sdata")));
extern u8 D_L40_003BFE20[];
__asm__(".extern D_L40_00248500, 16");
extern u8 *D_L40_00248500;
__asm__(".extern D_L40_0024845C, 16");
extern u8 *D_L40_0024845C;
extern s32 *D_L40_00357470 __attribute__((section(".data")));
__asm__(".extern D_L40_002479D0, 4");
extern f32 D_L40_002479D0;
extern void func_003C2880(void *);
extern s32 func_L39_0066C828(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L40_00430170(s32);
extern void func_L40_00430198(u8 *);
extern s32 func_L40_004300D8(s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_004305B0(void *);
extern void func_L40_00430100(s32, s32, u8);
extern s32 func_00381FF0(s32);
extern void func_L01_00436660(s32, s32, s32);

/* the 5-step byte decode of an obfuscated u32, as in matched func_L39_00524E00 */
static __inline__ u32 dec_00430928(u8 *p) {
    Buf_00430928 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L40_00430928(O_00430928 *o) {
    s32 one = D_L40_00241640->w180;
    Q_00430928 *q = o->p68;
    G_00430928 *g;
    u8 host;
    f32 r2;

    if (one != 1) {
        func_003C2880(o);
        return;
    }
    switch (o->b20) {
    case 0: {
        R_00430928 *r = (R_00430928 *)func_L39_0066C828(o, -1, 1);
        s32 e = 0;
        V_00430928 v;
        if (o->hAA == 0x1C2F) {
            e = 1;
        }
        q->h16 = 0;
        q->h14 = e;
        r->w28 = e;
        o->b30 = 0xFF;
        q->q0 = o->q10;
        q->q20 = o->qF0;
        q->w10 = -1;
        o->h34 |= 0x100;
        {
            *(u128_00430928 *)&v = q->q20;
            v.y = v.y + -1.5707964f;
            func_0038D308(o->bC0, &v);
            func_L01_004450F0(o, 1, -1);
        }
        break;
    }
    case 1: {
        s32 j;
        for (j = 0; j < 8; j++) {
            if (D_L40_00249330[j] != 0 && D_L40_00249330[j]->p251C == o) {
                D_L40_00249330[j]->p251C = 0;
            }
        }
        break;
    }
    case 2:
        g = D_L40_00249330[q->w10];
        if (g == 0) {
            if (func_L40_00430170((s32)o) == 0) {
                func_L40_00430198((u8 *)o);
            }
            break;
        }
        if (g->b1A14 == 0) {
            break;
        }
        if (func_L40_00430170((s32)o) == 0) {
            if ((dec_00430928(&g->b19E6) ^ 0x14) == 0 || (dec_00430928(&g->b19E4) ^ 0x7A) == 0
                || (host = g->p2530 != 0 ? (g->p2530[0x27B] != 0 && (dec_00430928(&g->b19E4) ^ 0x31) == 0) : 0)
                || g->p251C == 0 || (g->p2528 != 0 && g->p2528->p2D8 == g)) {
                func_L40_00430198((u8 *)o);
            }
        }
        if (func_L40_004300D8((s32)o) != 0) {
            break;
        }
        r2 = D_L40_002479D0;
        r2 = r2 * r2;
        if (func_L01_0040E548(&o->q10, D_L40_00248500 + (q->w18 << 7) + 0x30) < r2) {
            u8 *t = D_L40_0024845C + ((q->h14 == 0 ? D_L40_00357470[1] : D_L40_00357470[0]) << 8);
            if (D_L40_00241640->b196 == 1 || func_L40_004305B0(t) != 0) {
                func_L40_00430100((s32)o, 1, q->w10);
            } else {
                g = D_L40_00249330[q->w10];
                if (g != 0 && g->b1A14 != 0) {
                    func_L01_00436660(func_00381FF0(0x1709), -1, g->b24C9);
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L40_00430928 */

/* localdecomp:start func_L40_00430DD0 */
#include "vu0.h"
/* from func_L05_003AFC08 (src/levels/05_daxx/L05_003AFC08.c), with its constants read from tuning globals */
extern void func_00382580(void *, f32, f32);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, f32, s32, f32, s32, f32, s32, s32, s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L40_0029AF58[];
__asm__(".extern D_L40_0029AF58, 16");
extern f32 D_L40_002479D4;
extern s32 D_L40_002479D8;
extern s32 D_L40_002479DC;
extern f32 D_L40_002479E0;
extern f32 D_L40_002479E4;
extern f32 D_L40_002479E8;
extern f32 D_L40_002479EC;
extern s32 D_L40_002479F0;
extern s32 D_L40_002479F4;
extern f32 D_L40_002479F8;
extern f32 D_L40_002479FC;
extern s32 D_L40_00247A00;
__asm__(".extern D_L40_002479D4, 4");
__asm__(".extern D_L40_002479D8, 4");
__asm__(".extern D_L40_002479DC, 4");
__asm__(".extern D_L40_002479E0, 4");
__asm__(".extern D_L40_002479E4, 4");
__asm__(".extern D_L40_002479E8, 4");
__asm__(".extern D_L40_002479EC, 4");
__asm__(".extern D_L40_002479F0, 4");
__asm__(".extern D_L40_002479F4, 4");
__asm__(".extern D_L40_002479F8, 4");
__asm__(".extern D_L40_002479FC, 4");
__asm__(".extern D_L40_00247A00, 4");

void func_L40_00430DD0(f32 x, u8 *p, s32 n, s32 a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;

    func_00382580(loc, D_L40_002479D4 * 0.5f * 0.020000001f, D_L40_002479D4 * 0.020000001f);
    func_L01_003D8E60(p, loc, -1e+05f, D_L40_002479DC, x * D_L40_002479E0, 7, -5.0f, 5, D_L40_002479D8, a, 0);
    if (cnt > 0) {
        if (func_L39_005B4398(cnt) == 0) {
            func_L01_003303B8(p, x * 0.6f, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L40_0029AF58;
        do {
            func_00382580(loc, D_L40_002479E4 * 0.5f * 0.020000001f, D_L40_002479E4 * 0.020000001f);
            {
                s32 k = (D_L40_002479F0 * 5 + 2) / 6;
                s32 m = func_L39_005B43C8(-2, 2);
                f32 f20 = D_L40_002479EC * x * 2.1e+05f;
                f32 t = func_L39_005B4410(D_L40_002479F8 * 0.6f, D_L40_002479F8);
                r = func_L01_00475C60(p, loc, k, m, 0x7F407FFF, 0x407FFF, f20, f20, t, 0);
                if (r != 0) {
                    r[9] = 0xF2;
                    r[3] = func_L39_005B4398(D_L40_00247A00) ? 0x44 : 0x48;
                    r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
                }
            }
            if (func_L39_005B4398(4)) {
                s32 k;
                s32 m;
                f32 s, f20, f21, t;
                func_0038CE20(loc, loc, D_L40_002479E8);
                *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
                k = (D_L40_002479F4 * 5 + 2) / 6;
                m = func_L39_005B43C8(-2, 2);
                s = D_L40_002479EC * x;
                f20 = s * 0.3f * 2.1e+05f;
                f21 = s * 0.04f * 2.1e+05f;
                t = func_L39_005B4410(D_L40_002479FC * 0.6f, D_L40_002479FC);
                r = func_L01_00475C60(p, loc, k, m, 0x7F0048FF, 0x48FF, f20, f21, t, 0);
                if (r != 0) {
                    r[9] = 0xF2;
                    r[3] = func_L39_005B4398(D_L40_00247A00) ? 0x44 : 0x48;
                    r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
                }
            }
            n--;
        } while (n != 0);
    }
}
/* localdecomp:end func_L40_00430DD0 */
