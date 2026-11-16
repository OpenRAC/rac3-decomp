#include "common.h"

/* NTSC-U counterpart of func_L39_0064DCF0 (src/levels/shared/L39_0064D4A8.c) */
#include "vu0.h"
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_006301D8(void *, void *, void *, f32);
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern f32 func_003BEBF8(f32 *, f32, f32);

/* localdecomp:start func_L39_0064B448 */
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

extern T_0064DCF0 D_L39_0047A968_0064B448[];
extern u8 D_L39_00483AC0[];
extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u32 D_L39_0024BAC8;

extern f32 func_L39_0062FD90(void *, void *);
extern void func_L39_00630DD8(void *, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_0062FA50(void *, void *, void *, f32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_0062D4A8(void *, f32, f32, f32);
extern void func_L01_0050D180(void *, void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern s32 func_003CF790(void *, s32, void *, void *, f32);
extern s32 func_L39_00630400(void *, f32);
extern s32 func_L01_003EFFE0(s32, s32);
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern void func_L39_0062FD10(void *, void *, void *, f32);
extern void func_L39_006301D8(void *, void *, void *, f32);

void func_L39_0064B448(S_0064DCF0 *p)
{
    s32 flag;
    f32 d;
    f32 k;
    s32 w;
    f32 lim;
    s32 lo;
    s32 hi;

    if (p->w61C != 0 || p->f628 < (f32)D_L39_0047A968_0064B448[p->h107C].w18) {
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
            d = func_L39_0062FD90(p, tmp);
            if ((2.0f < d && d < 5.0f) || flag) {
                p->fFB0 = 0.07500000298023224f;
            }
            func_L39_00630DD8(p, 0.0069444444961845875f, 0.0069444444961845875f);
            func_00388830(v, p->v20, p->fFB4);
            func_L39_0062FA50(p, p->v120, p->v120, 0.0f);
            vec_add_ab(p->v120, p->v120, v);
        }
    } else {
        if (flag && p->w2F0 < 0x46) {
            p->fFB0 = 0.07500000298023224f;
        }
        func_L39_00630DD8(p, 0.004166666883975267f, 0.004166666883975267f);
        func_L39_0062FA50(p, p->v120, p->v120, p->fFB4);
    }
    if (p->w1068 != 0 || p->w1064 != 0) {
        p->fFD0 = p->f106C;
        p->qFC0 = p->q1040;
        func_L39_00630AC0(p, 0, 0.05000000074505806f, 0.20000000298023224f, 0.28216156363487244f);
    } else if (p->f628 < 25.0f) {
        func_L39_0062D4A8(p, 8.0f, 1.04719758f, 1.04719758f);
    }
    k = 0.12833333015441895f;
    if (2.25f < p->f2AC) {
        k = 0.06416666507720947f;
    } else if (1.8f < p->f2AC) {
        k = 0.0898333266377449f;
    }
    if (p->w61C == 0 && 23.5f < p->f628 && p->f148 < 0.0f && p->h2DE != 0) {
        {
            u8 pos[16] __attribute__((aligned(16)));
            u8 v[16] __attribute__((aligned(16)));
            Hit_0064DCF0 hit;

            *(vu0_q *)pos = *(vu0_q *)p->vA0;
            func_L01_0050D180(p, pos, pos, -0.5f);
            func_00388830(v, p->v20, 2.0f);
            func_L01_00443628(&hit, p->w2524, 0x10000, 2.0f, v);
            hit.fC = 5627.9248f;
            hit.b19 = 1;
            hit.h1A = 0x47;
            hit.b18 = 0;
            func_003CF790(pos, 0x10, p->w2524, &hit, 0.4f);
        }
    }
    if (func_L39_00630400(p, 25.7f) != 0) {
        u16 bits;

        func_L01_003EFFE0(0x19, p->w2534);
        p->h32E = 0x32;
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
                    *dd++ = D_L39_00483AC0[((kk + i) & 7) * 209 + m];
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
            p->w2530->w48 = 0x1E;
            p->w2530->w2C = 0;
            {
                u8 *q = &p->b319;
                s16 v = 0x23;
                u8 *hk = q;
                Buf_0064DCF0 buf;
                u32 key;
                s32 kk;
                s32 m;
                s32 i;
                s32 t;
                u8 *dd;

                if (*q == 0) {
                    *q = ++D_L39_004998A0[0];
                } else {
                    t = *q;
                    *q = D_L39_004998A1[0];
                    D_L39_004998A1[0] = t;
                }
                key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
                kk = ((u32)q - *q) & 7;
                buf.h[2] = v;
                buf.w[0] = (u32)q ^ key;
                buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
                m = *q + 1;
                dd = buf.b;
                for (i = 0; i < 24; i += 3) {
                    D_L39_004998A0[m + ((kk + i) & 7) * 255] = *dd++;
                }
            }
        }
    }
    w = p->w2F0;
    lo = 9;
    hi = 14;
    if (w < lo) {
        f32 f;

        f = func_L39_0062FE30((u8 *)p, (f32 *)p->v120);
        func_003BEBF8(&f, k, 0.0416666679084301f);
        func_L39_0062FD10(p, p->v120, p->v120, f);
    } else if (w > hi) {
        func_L39_006301D8(p, p->v120, p->v120, 0.03611111268401146f);
        if (func_L39_0062FE30((u8 *)p, (f32 *)p->v120) < 0.0f) {
            p->f1080 = 1.0f;
        }
        lim = -0.6166666746139526f;
        if (func_L39_0062FE30((u8 *)p, (f32 *)p->v120) < lim) {
            func_L39_0062FD10(p, p->v120, p->v120, lim);
        }
    }
}
/* localdecomp:end func_L39_0064B448 */
