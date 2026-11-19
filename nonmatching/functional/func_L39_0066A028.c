/* functional: high. Compiles; PAL port of the NTSC-U draft (PAL threshold x2F0 >= 0x1A, callee/table names retargeted from the PAL asm); keyed byte-table decode idiom kept as in the matched L39 neighbours; bytes differ in scheduling. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L39_004997E0[];

typedef union Buf_0066A028 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_0066A028;

typedef struct P_0066A028 {
    u8 pad0[0x10];
    u128_t q10;
    u8 pad20[0xBC - 0x20];
    u8 bBC;
    u8 padBD[0xC0 - 0xBD];
    u128_t qC0;
    u128_t qD0;
    u128_t qE0;
    u128_t qF0;
} P_0066A028;

typedef struct S_0066A028 {
    u8 pad0[0x210];
    f32 f210;
    f32 f214;
    f32 f218;
    u8 pad21C[4];
    f32 f220;
    f32 f224;
    f32 f228;
    u8 pad22C[0x2D0 - 0x22C];
    P_0066A028 *x2D0;
    u8 pad2D4[0x2E4 - 0x2D4];
    s32 x2E4;
    u8 pad2E8[0x2F8 - 0x2E8];
    u32 x2F8;
    s16 h2FC;
    u8 pad2FE[0x328 - 0x2FE];
    s32 x328;
} S_0066A028;

typedef struct Q_0066A028 {
    u8 pad0[0x1A4];
    u32 x1A4;
} Q_0066A028;

typedef struct R_0066A028 {
    u8 pad0[0x27B];
    u8 b27B;
} R_0066A028;

typedef struct M_0066A028 {
    u8 pad0[0x20];
    u128_t q20;
    u128_t q30;
    u128_t q40;
    u8 pad50[0xA0 - 0x50];
    u128_t qA0;
    u128_t qB0;
    u8 padC0[0x2F0 - 0xC0];
    s32 x2F0;
    u8 pad2F4[0x19E4 - 0x2F4];
    u8 b19E4;
    u8 pad19E5[0x1A14 - 0x19E5];
    u8 b1A14;
    u8 pad1A15[0x2450 - 0x1A15];
    s32 x2450;
    u8 pad2454[0x2476 - 0x2454];
    u8 b2476;
    u8 pad2477[0x24C9 - 0x2477];
    u8 b24C9;
    u8 pad24CA[0x2528 - 0x24CA];
    S_0066A028 *x2528;
    u8 pad252C[4];
    R_0066A028 *x2530;
    Q_0066A028 *x2534;
    u8 pad2538[0x254C - 0x2538];
    s32 x254C;
} M_0066A028;

typedef struct T_0066A028 {
    u8 pad0[0x14];
    void (*fn14)(void *);
    u8 pad18[4];
} T_0066A028;

extern T_0066A028 D_L39_0033AB08[];
extern s32 D_001A5DF8[];
extern void func_L39_00621370(void *);
extern void func_L01_004606A8(void *);
extern void func_L39_00668660(void *, void *, s32);
extern void func_L39_006673E8(void *, void *, s32);
extern void func_L39_0061CFC8(void *, void *, void *, s32, s32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_006670C0(void *, s32, s32, s32, s32);

void func_L39_0066A028(M_0066A028 *m, s32 a1) {
    S_0066A028 *s;
    s32 t;
    s32 tmp[4];
    Buf_0066A028 buf;
    f32 f;
    u8 c;

    if (m->x254C != 6) {
        return;
    }
    s = m->x2528;
    if (s == 0) {
        return;
    }
    if (D_L39_0033AB08[s->h2FC].fn14 != 0) {
        D_L39_0033AB08[s->h2FC].fn14(s->x2D0);
    }
    if (m->b1A14 == 0) {
        return;
    }
    t = D_001A5DF8[0];
    if ((s->x2F8 & 0x8000000) == 0) {
        m->x2450 = 0x1D;
    }
    m->qA0 = s->x2D0->q10;
    m->qB0 = s->x2D0->qF0;
    m->q20 = s->x2D0->qC0;
    m->q30 = s->x2D0->qD0;
    m->q40 = s->x2D0->qE0;
    func_L39_00621370(m);
    if (a1 == 0 && s->x2D0->bBC != 0xB) {
        if (m->x2F0 >= 0x1A && (m->x2534->x1A4 & 0x10) != 0) {
            goto update;
        }
        if (m->b2476 == 0) {
            f = 0.0f;
        } else {
            u8 *q = &m->b2476;
            u32 a;
            u32 b;
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 mm = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            buf.w[1] = b;
            f = buf.f[1];
        }
        c = f <= 0.0f;
        if (c) {
            goto update;
        }
        if (m->x2530 != 0 && m->x2530->b27B != 0 &&
            ({
                u32 r;
                u8 *q = &m->b19E4;
                if (*q == 0) {
                    r = 0;
                } else {
                    u32 a;
                    u32 b;
                    s32 n = *q;
                    s32 k = ((u32)q - n) & 7;
                    s32 mm = n + 1;
                    s32 i;
                    u8 *d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = b;
                    r = b;
                }
                (r ^ 0x31) == 0;
            })) {
        update:
            func_L01_004606A8(m->x2534);
            s->x328 = m->b24C9 + 1;
            func_L39_00668660(s, tmp, 0);
            func_L39_006673E8(s, m, 1);
            func_L39_0061CFC8(m, tmp, (u8 *)m + 0xB0, 1, 0);
        }
    }
    if (t < s->x2E4 + 0x39) {
        return;
    }
    if (func_0038DBA0(s->f220, s->f210) > 0.03f || func_0038DBA0(s->f224, s->f214) > 0.03f ||
        func_0038DBA0(s->f228, s->f218) > 0.03f) {
        s->x2E4 = t;
        func_L39_006670C0(s, t, 0, 0, 1);
        *(u128_t *)&s->f220 = *(u128_t *)&s->f210;
    }
}
