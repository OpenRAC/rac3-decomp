#include "common.h"

/* NTSC-U counterpart of func_L39_0065F1A8 (src/levels/shared/L39_0065D0A0.c): 5 -> 6 */
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_0065C8D0 */
typedef union Buf_0065F1A8 {
    u8 b[8];
    u32 w[2];
} Buf_0065F1A8;

typedef struct VT_0065F1A8 {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} VT_0065F1A8;

typedef struct S_0065F1A8 {
    u8 pad0[0x14];
    VT_0065F1A8 *vt;
    u8 pad18[0x30C - 0x18];
    s32 s30C;
    u8 pad310[0x754 - 0x310];
    s32 s754;
    u8 pad758[0x19E4 - 0x758];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 pad1A08[0x1A17 - 0x1A08];
    u8 b1A17;
    u8 pad1A18[0x2468 - 0x1A18];
    f32 f2468;
} S_0065F1A8;

extern u8 D_L39_004998A0[];
extern void func_L39_0061FAE8(void *);

s32 func_L39_0065C8D0(S_0065F1A8 *s) {
    Buf_0065F1A8 buf;

    if (({
            u32 r;
            u8 *q = &s->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                u32 a, b;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            r == 2;
        }) ||
        ({
            u32 r;
            u8 *q = &s->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                u32 a, b;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            r == 3;
        }) ||
        ({
            u32 r;
            u8 *q = &s->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                u32 a, b;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            r == 0;
        })) {
        if (s->b1A07 != 0 && s->s30C < 6 && s->f2468 < 0.7f) {
            if (({
                    u8 r;
                    u8 *q = &s->b1A17;
                    if (*q == 0) {
                        r = 0;
                    } else {
                                u32 a, b;
                        s32 n = *q;
                        s32 k = ((u32)q - n) & 7;
                        s32 m = n + 1;
                        s32 i;
                        u8 *d = buf.b;
                        for (i = 0; i < 24; i += 3) {
                            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        r = buf.b[4];
                    }
                    r;
                }) == 0) {
                func_L39_0061FAE8(s);
                s->s754 = 2;
                s->vt->fn34(s, 0x22, 1, 0, 1);
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0065C8D0 */
