#include "common.h"

extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_0062F468 */
typedef union Buf_00631AD8 {
    u8 b[8];
    u32 w[2];
} Buf_00631AD8;

extern u8 D_L39_004998A0[];
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);

void func_L39_0062F468(u8 *s) {
    Buf_00631AD8 buf;
    u32 dec;
    s32 eq;

    {
        u8 *q = s + 0x19E4;
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
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            buf.w[1] = b;
            dec = b;
        }
    }
    eq = dec == 0x7E;
    if (!eq) {
        {
            u8 *q = s + 0x19E4;
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
                    *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x90;
        if (!eq) {
            return;
        }
        {
            u8 *q = s + 0x19E7;
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
                    *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x7E;
        if (!eq) {
            return;
        }
    }
    func_L01_0044B920(*(void **)(s + 0x2524), s + 0x1400, s + 0x1404, 0.174532920122f, 0.0261799413711f, 0.0349065884948f);
}
/* localdecomp:end func_L39_0062F468 */
