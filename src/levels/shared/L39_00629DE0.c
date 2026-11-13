#include "common.h"

/* localdecomp:start func_L39_00629DE0 */
/* from this file's func_L39_0055AD78 loop (L39_005598D8.c) */
typedef struct {
    u8 pad0[0xB8];
    f32 fB8;
    u8 padBC[0x3E4 - 0xBC];
    s16 h3E4;
    u8 pad3E6;
    u8 b3E7;
    u8 pad3E8[0x1310 - 0x3E8];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5[0x1A06 - 0x19E5];
    u8 b1A06;
} Obj_00629DE0;
extern u8 D_L39_004997E0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern void func_L39_00632D78(void *, s32, f32);
extern f32 func_L39_00633C78(void *, void *, s32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);

s32 func_L39_00629DE0(Obj_00629DE0 *o) {
    s32 ret = 2;
    f32 ang;
    if (o->h3E4 != 0 || (o->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, *(s32 *)((u8 *)o + 0x2534)) != 0 && func_L39_006212E8(o) != 10)) {
        u8 *p = &o->b19E4;
        s32 x = 0;
        long t = *p;
        if (t != 0) {
            u32 buf[2];
            u8 *b;
            s32 i;
            s32 m;
            s32 k;
            s32 n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
        if ((x ^ 0x10) != 0) {
            u8 c = o->b3E7;
            if (c == 0) {
                ret = 0;
            } else if (c == 3) {
                ret = 3;
            } else {
                ret = (c == 2) ? 2 : 1;
            }
            return ret;
        }
    }
    func_L39_00632D78(o, 0, 1.0f);
    if (o->b1A06 != 0) {
        ang = func_L39_00633C78(o, (u8 *)o + 0xFC0, 0);
    } else {
        ang = func_0038DB00(*(f32 *)((u8 *)o + 0xFD0), o->fB8);
    }
    if (func_0038DBA0(ang, 3.1415927f) < 0.7853982f) {
        ret = 3;
    } else if (func_0038DBA0(ang, -1.5707964f) < 0.7853982f) {
        ret = 1;
    } else if (func_0038DBA0(ang, 1.5707964f) < 0.7853982f) {
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_00629DE0 */

/* localdecomp:start func_L39_00629FE0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00629FE0;
typedef struct {
    u8 pad0[0x1C];
    s32 w1C;
    f32 f20;
} P_00629FE0;
typedef struct {
    u8 pad0[0x10];
    V_00629FE0 pos;
    u8 pad20[0x31 - 0x20];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    P_00629FE0 *p68;
} E_00629FE0;
extern E_00629FE0 *D_L39_00264B68[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L39_00639350(u8 *, void *, s32 *, f32, f32, f32, f32);

void func_L39_00629FE0(u8 *o, s32 force) {
    E_00629FE0 *e;
    E_00629FE0 *best;
    f32 bestd;
    s32 i;

    o[0x15EE] = 0;
    bestd = 1e8f;
    best = 0;
    for (i = 0; i < 32 && (e = D_L39_00264B68[i]) != 0; i++) {
        P_00629FE0 *p;
        f32 d;
        f32 c, dd;
        f32 r;
        f32 range;
        f32 t;
        f32 y;
        s32 out;
        u32 x;
        if (e->h34 & 1) {
            continue;
        }
        if (*(f32 *)(o + 0xA8) - e->pos.z > 3.0f) {
            continue;
        }
        p = e->p68;
        d = func_0038CF00(o + 0xA0, &e->pos);
        if (p->f20 != 0.0f && d > p->f20) {
            continue;
        }
        if (d > 16.0f) {
            continue;
        }
        c = 0.7853982f;
        {
            u8 *q = o + 0x19E4;
            u8 buf[16];
            s32 n, k, m, j;
            u8 *bp;
            if (*q == 0) {
                x = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                bp = buf;
                for (j = 0; j < 40; j += 5) {
                    *bp++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                ((u32 *)buf)[0] ^= (u32)q;
                ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
                x = ((u32 *)buf)[1];
            }
        }
        if ((x ^ 0x2C) == 0 || force != 0) {
            c = 1.4835298f;
        }
        dd = 0.7853982f;
        {
            u8 *q = o + 0x19E4;
            u8 buf[16];
            s32 n, k, m, j;
            u8 *bp;
            if (*q == 0) {
                x = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                bp = buf;
                for (j = 0; j < 40; j += 5) {
                    *bp++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                ((u32 *)buf)[0] ^= (u32)q;
                ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
                x = ((u32 *)buf)[1];
            }
        }
        if ((x ^ 0x2C) == 0 || force != 0) {
            dd = 1.4835298f;
        }
        {
            u8 *q = o + 0x19E4;
            u8 buf[16];
            s32 n, k, m, j;
            u8 *bp;
            if (*q == 0) {
                x = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                bp = buf;
                for (j = 0; j < 40; j += 5) {
                    *bp++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                ((u32 *)buf)[0] ^= (u32)q;
                ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
                x = ((u32 *)buf)[1];
            }
        }
        if ((x ^ 1) == 0) {
            dd = 0.08726646f;
            c = dd;
        } else {
        {
            u8 *q = o + 0x19E4;
            u8 buf[16];
            s32 n, k, m, j;
            u8 *bp;
            if (*q == 0) {
                x = 0;
            } else {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                bp = buf;
                for (j = 0; j < 40; j += 5) {
                    *bp++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                ((u32 *)buf)[0] ^= (u32)q;
                ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
                x = ((u32 *)buf)[1];
            }
        }
        if ((x ^ 0x1D) == 0 || o[0x24FE] != 0) {
            dd = 0.08726646f;
            c = dd;
        }
        }
        t = p->f20;
        y = *(f32 *)(o + 0xB8);
        range = 16.0f;
        if (t != 0.0f) {
            range = t;
        }
        r = func_L39_00639350(o, e, &out, y, range, c, dd);
        if (out != 0) {
            continue;
        }
        if (e->b31 == 0) {
            r += 10.0f;
        }
        if (p->w1C >= 0 && func_00382380(o + 0xA0, p->w1C, 0) != 0) {
            continue;
        }
        if (r < bestd) {
            bestd = r;
            best = e;
        }
    }
    *(E_00629FE0 **)(o + 0x15E0) = best;
    if (best != 0) {
        V_00629FE0 a;
        V_00629FE0 b;
        a = *(V_00629FE0 *)(o + 0xA0);
        a.z += 0.5f;
        b = best->pos;
        if (func_003D3CB0(&a, &b, 2, best, 0) == 0) {
            if (*(s32 *)(o + 0x2CC) != 0) {
                b.z = a.z;
                if (func_003D3CB0(&a, &b, 4, *(void **)(o + 0x2524), 0) != 0) {
                    return;
                }
            }
            *(f32 *)(o + 0x15E8) = bestd;
            o[0x15EE] = 1;
        }
    }
}
/* localdecomp:end func_L39_00629FE0 */

INCLUDE_ASM("asm/levels", func_L39_0062A4C0);
