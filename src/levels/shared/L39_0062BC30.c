#include "common.h"

/* localdecomp:start func_L39_0062BC30 */
typedef union {
    u8 b[8];
    u32 w[2];
} Buf_0062BC30;

typedef struct {
    u8 pad0[0x23];
    u8 b23;
} Obj_0062BC30;

typedef struct {
    u8 pad0[0x748];
    Obj_0062BC30 *objs[2];
    u8 pad750[4];
    s32 w754;
    u8 pad758[0x1A0B - 0x758];
    u8 b1A0B;
    u8 pad1A0C[0x1A17 - 0x1A0C];
    u8 b1A17;
} G_0062BC30;

extern u8 D_L39_004997E0[];
extern s32 func_L39_00631A20(void *, s32, f32 *);

s32 func_L39_0062BC30(G_0062BC30 *g, s32 idx, s32 k) {
    s32 r;
    f32 f;
    Obj_0062BC30 *o;
    u8 res1;
    u8 res2;
    Buf_0062BC30 buf;
    u8 *q1;
    u32 a1;
    u32 b1;
    s32 n1;
    s32 k1;
    s32 m1;
    s32 i1;
    u8 *d1;
    u8 *q2;
    u32 a2;
    u32 b2;
    s32 n2;
    s32 k2;
    s32 m2;
    s32 i2;
    u8 *d2;

    r = 0;
    q1 = &g->b1A17;
    if (*q1 == 0) {
        res1 = 0;
    } else {
        n1 = *q1;
        k1 = ((u32)q1 - n1) & 7;
        m1 = n1 + 1;
        d1 = buf.b;
        for (i1 = 0; i1 < 24; i1 += 3) {
            *d1++ = D_L39_004997E0[m1 + ((k1 + i1) & 7) * 255];
        }
        a1 = buf.w[0] ^ (u32)q1;
        b1 = buf.w[1] ^ a1;
        buf.w[0] = a1;
        buf.w[1] = (b1 >> 16) / (((b1 ^ (b1 >> 16)) << 16) + 1);
        res1 = buf.b[4];
    }
    if (res1 != 0 && g->b1A0B == 0) {
        if (idx == 0) {
            goto done;
        }
        q2 = &g->b1A17;
        if (*q2 == 0) {
            res2 = 0;
        } else {
            n2 = *q2;
            k2 = ((u32)q2 - n2) & 7;
            m2 = n2 + 1;
            d2 = buf.b;
            for (i2 = 0; i2 < 24; i2 += 3) {
                *d2++ = D_L39_004997E0[m2 + ((k2 + i2) & 7) * 255];
            }
            a2 = buf.w[0] ^ (u32)q2;
            b2 = buf.w[1] ^ a2;
            buf.w[0] = a2;
            buf.w[1] = (b2 >> 16) / (((b2 ^ (b2 >> 16)) << 16) + 1);
            res2 = buf.b[4];
        }
        if ((res2 ^ 2) == 0) {
            goto done;
        }
    }
    if (k != 0x28) {
        o = g->objs[idx];
        if (o == 0 || o->b23 != 0x32 || g->w754 != 0) {
            r = 0x40;
        }
    }
done:
    if (r != 0 && k >= 0x17) {
        r = 1;
    }
    f = 0.0f;
    if (func_L39_00631A20(g, k, &f) != 0 && r == 0) {
        r = 0x20;
    }
    return r;
}
/* localdecomp:end func_L39_0062BC30 */
