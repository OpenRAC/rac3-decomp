#include "common.h"

/* localdecomp:start func_L39_0062D0C8 */
/* log:
 * v1: vec_add_ab + qzero from vu0.h
 */
#include "vu0.h"

extern f32 func_L39_006325D8(void *, void *);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);

void func_L39_0062D0C8(u8 *self, f32 a) {
    u8 *v = self + 0x190;
    f32 len = func_L39_006325D8(self, v);
    f32 d;

    if (0.001f < len) {
        func_L39_00632558(self, v, v, 0.0f);
        d = len - a;
        if (d < 0.0f) {
            d = 0.0f;
        }
        func_L39_00632298(self, v, v, d);
        vec_add_ab(self + 0x120, self + 0x120, v);
    } else {
        qzero(v);
    }
}
/* localdecomp:end func_L39_0062D0C8 */

/* localdecomp:start func_L39_0062D190 */
#include "vu0.h"

typedef int q_0062D190 __attribute__((mode(TI)));

typedef union {
    q_0062D190 q;
    u8 b[8];
    u32 w[2];
} Buf_0062D190;

typedef struct {
    u8 pad0[0x120];
    vu0_v4 pos;
    u8 pad130[0x1A4 - 0x130];
    f32 f1A4;
    f32 f1A8;
    u8 pad1AC[0x216 - 0x1AC];
    u8 b216;
    u8 pad217[0x2DA - 0x217];
    s16 h2DA;
    u8 pad2DC[0x3E4 - 0x2DC];
    s16 h3E4;
    u8 pad3E6[0xFB0 - 0x3E6];
    f32 fFB0;
    f32 fFB4;
    u8 padFB8[0xFC0 - 0xFB8];
    q_0062D190 qFC0;
    f32 fFD0;
    u8 padFD4[0x1310 - 0xFD4];
    s32 w1310;
    u8 pad1314[0x1534 - 0x1314];
    s16 h1534;
    u8 pad1536[0x15A0 - 0x1536];
    q_0062D190 q15A0;
    u8 pad15B0[0x19E4 - 0x15B0];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A06 - 0x19E7];
    u8 b1A06;
    u8 pad1A07[0x2534 - 0x1A07];
    s32 w2534;
} G_0062D190;

extern u8 D_L39_004997E0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L39_00632818(void *, void *);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L39_006325D8(void *, void *);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);

void func_L39_0062D190(G_0062D190 *g, f32 a) {
    vu0_v4 v;
    Buf_0062D190 buf;
    vu0_v4 v2;
    f32 ang;
    f32 s;
    f32 r1;
    f32 r2;

    switch (g->b1A06) {
    case 0:
        ang = g->fFD0;
        s = g->fFB0;
        {
            u8 *q = &g->b19E6;
            u32 dec;
            if (*q == 0) {
                dec = 0;
            } else {
                u32 a;
                u32 b;
                s32 n;
                s32 k;
                s32 m;
                s32 i;
                u8 *d;

                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
            if ((dec ^ 4) == 0 && g->h1534 != 0 && g->b216 != 0) {
                s = 0.10000001f;
            }
        }
        if (g->h2DA != 0) {
            {
                u8 *q = &g->b19E4;
                u32 dec;
                if (*q == 0) {
                    dec = 0;
                } else {
                    u32 a;
                    u32 b;
                    s32 n;
                    s32 k;
                    s32 m;
                    s32 i;
                    u8 *d;

                    n = *q;
                    k = ((u32)q - n) & 7;
                    m = n + 1;
                    d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = b;
                    dec = b;
                }
                if ((dec ^ 0xE) == 0 && 0.020000001f < s) {
                    s = 0.020000001f;
                }
            }
        }
        v.x = func_0038D098(ang) * s;
        v.y = func_0038D0B0(ang) * s;
        v.z = g->pos.z;
        s = -(g->pos.x * v.x + g->pos.y * v.y);
        r1 = func_0038CED8(&v);
        r2 = func_0038CED8(&g->pos);
        if (r1 == 0.0f || r2 == 0.0f) {
            s = 0.0f;
        } else {
            s /= r1;
            s /= r2;
        }
        s += 1.0f;
        s *= 1.5f;
        if (3.0f < s) {
            s = 3.0f;
        }
        if (s < 1.0f) {
            s = 1.0f;
        }
        vec_sub_ab(&v, &v, &g->pos);
        a *= s;
        if (a < func_0038CED8(&v)) {
            func_0038CFB8(&v, &v, a);
        }
        vec_add_ab(&g->pos, &g->pos, &v);
        buf.q = g->q15A0;
        g->fFB4 = g->f1A8 - func_L39_00632818(g, &buf);
        if (g->h3E4 != 0 ||
            (g->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, g->w2534) != 0 && func_L39_006212E8(g) != 10)) {
            {
                u8 *q = &g->b19E4;
                u32 dec;
                if (*q == 0) {
                    dec = 0;
                } else {
                    u32 a;
                    u32 b;
                    s32 n;
                    s32 k;
                    s32 m;
                    s32 i;
                    u8 *d;

                    n = *q;
                    k = ((u32)q - n) & 7;
                    m = n + 1;
                    d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = b;
                    dec = b;
                }
                if ((dec ^ 0x10) != 0) {
                    g->fFB4 = g->f1A4;
                }
            }
        }
        break;
    case 1:
    case 2:
        buf.q = g->qFC0;
        s = g->fFB0;
        func_L39_00632558(g, &v, &buf, 0.0f);
        func_0038CF68(&v, &v, s);
        func_L39_00632558(g, &v2, &g->pos, 0.0f);
        s = -func_0038CE68(&v2, &v);
        r1 = func_L39_006325D8(g, &v);
        r2 = func_L39_006325D8(g, &g->pos);
        if (r1 == 0.0f || r2 == 0.0f) {
            s = 0.0f;
        } else {
            s /= r1;
            s /= r2;
        }
        s += 1.0f;
        s *= 1.5f;
        if (3.0f < s) {
            s = 3.0f;
        }
        if (s < 1.0f) {
            s = 1.0f;
        }
        vec_sub_ab(&v, &v, &g->pos);
        func_L39_00632558(g, &v, &v, 0.0f);
        a *= s;
        if (a < func_L39_006325D8(g, &v)) {
            func_L39_00632298(g, &v, &v, a);
        }
        vec_add_ab(&g->pos, &g->pos, &v);
        g->fFB4 = g->f1A8;
        if (g->h3E4 != 0 ||
            (g->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, g->w2534) != 0 && func_L39_006212E8(g) != 10)) {
            {
                u8 *q = &g->b19E4;
                Buf_0062D190 buf;
                u32 dec;
                if (*q == 0) {
                    dec = 0;
                } else {
                    u32 a;
                    u32 b;
                    s32 n;
                    s32 k;
                    s32 m;
                    s32 i;
                    u8 *d;

                    n = *q;
                    k = ((u32)q - n) & 7;
                    m = n + 1;
                    d = buf.b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    a = buf.w[0] ^ (u32)q;
                    b = buf.w[1] ^ a;
                    buf.w[0] = a;
                    buf.w[1] = b;
                    dec = b;
                }
                if ((dec ^ 0x10) != 0) {
                    g->fFB4 = g->f1A4;
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L39_0062D190 */
