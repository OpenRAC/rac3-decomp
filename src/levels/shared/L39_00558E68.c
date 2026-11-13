#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00558E68 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
typedef struct { u8 p0[0x14B8]; f32 f14B8; u8 p1[0x19E4 - 0x14BC]; u8 b19E4; u8 p2[0x2524 - 0x19E5]; u8 *w2524; } G_00558E68;
typedef struct { u8 p0[8]; G_00558E68 *g; s32 wC; u8 p1[0x40]; u8 q50[8]; f32 f58; f32 f5C; u8 q60[8]; f32 f68; } S_00558E68;
typedef struct { u8 p0[0x68]; S_00558E68 *s; } M_00558E68;
typedef union { u8 b[8]; u32 w[2]; } Buf_00558E68;
s32 func_L39_00558E68(M_00558E68 *m) {
    S_00558E68 *s = m->s;
    Buf_00558E68 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 mm;
    s32 i;
    u8 *d;
    u8 *q;
    u32 r;
    u32 a2;
    u32 b2;
    s32 n2;
    s32 k2;
    s32 mm2;
    s32 i2;
    u8 *d2;
    u8 *q2;
    u32 r2;

    q = &s->g->b19E4;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        mm = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        r = b;
    }
    if ((r ^ 7) == 0 && s->g->f14B8 > 6.0f) {
        if (s->wC == 0) {
            *(u128_t *)s->q50 = *(u128_t *)(s->g->w2524 + 0x10);
            s->wC = 1;
        }
    }
    if (s->wC != 0) {
        q2 = &s->g->b19E4;
        if (*q2 == 0) {
            r2 = 0;
        } else {
            n2 = *q2;
            k2 = ((u32)q2 - n2) & 7;
            mm2 = n2 + 1;
            d2 = buf.b;
            for (i2 = 0; i2 < 40; i2 += 5) {
                *d2++ = D_L39_004997E0[mm2 + ((k2 + i2) & 7) * 255];
            }
            a2 = buf.w[0] ^ (u32)q2;
            b2 = buf.w[1] ^ a2;
            buf.w[0] = a2;
            buf.w[1] = b2;
            r2 = b2;
        }
        if ((r2 ^ 7) != 0) {
            s->wC = 0;
            *(u128_t *)s->q60 = *(u128_t *)(s->g->w2524 + 0x10);
            if (s->f68 - s->f58 > 6.0f) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00558E68 */

/* localdecomp:start func_L39_00559018 */
extern u8 D_L39_004997E0[];
typedef struct { u8 p0[8]; u8 *g; u8 p1[0x70]; f32 f7C; } S_00559018;
typedef struct { u8 p0[0x68]; S_00559018 *s; } M_00559018;
typedef union { u8 b[8]; u32 w[2]; } Buf_00559018;
void func_L39_00559018(M_00559018 *m) {
    S_00559018 *s = m->s;
    Buf_00559018 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 mm;
    s32 i;
    u8 *d;
    u8 *q;
    u8 *q2;
    s32 n2;
    s32 k2;
    s32 mm2;
    s32 i2;
    u8 *d2;
    u32 a2;
    u32 b2;
    u32 r2;
    u32 r;
    f32 x;
    f32 c;
    u8 c1;

    q = s->g + 0x19E6;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        mm = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        r = b;
    }
    c1 = (r ^ 4) != 0;
    if (!c1) {
        q2 = s->g + 0x19E4;
        if (*q2 == 0) {
            r2 = 0;
        } else {
            n2 = *q2;
            k2 = ((u32)q2 - n2) & 7;
            mm2 = n2 + 1;
            d2 = buf.b;
            for (i2 = 0; i2 < 40; i2 += 5) {
                *d2++ = D_L39_004997E0[mm2 + ((k2 + i2) & 7) * 255];
            }
            a2 = buf.w[0] ^ (u32)q2;
            b2 = buf.w[1] ^ a2;
            buf.w[0] = a2;
            buf.w[1] = b2;
            r2 = b2;
        }
        c1 = (r2 ^ 0x83) == 0;
    }
    if (c1) {
        s->f7C = *(f32 *)(*(u8 **)(s->g + 0x2524) + 0x18);
    } else {
        if (*(f32 *)(s->g + 0x14B8) > 6.5f) {
            s->f7C = *(f32 *)(*(u8 **)(s->g + 0x2524) + 0x18);
        } else {
            x = *(f32 *)(s->g + 0x2A8);
            c = s->f7C;
            if (__builtin_fabsf(x - c) < 0.5f) {
            } else if (c - x > 10.0f) {
                s->f7C = *(f32 *)(*(u8 **)(s->g + 0x2524) + 0x18);
            } else {
                s->f7C = x;
            }
        }
    }
}
/* localdecomp:end func_L39_00559018 */
