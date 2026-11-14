#include "common.h"

/* NTSC-U counterpart of func_L39_0062FE58 (src/levels/shared/L39_0062D7C8.c): 0.0216 -> 0.015; 0.432 -> 0.3; 0.10472 -> 0.0872665 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_0062D610 */
typedef union Buf_0062FE58 {
    u8 b[8];
    u32 w[2];
    u128_t q;
    f32 f[4];
} Buf_0062FE58;

extern u8 D_L39_004998A0[];
extern f32 func_L01_004455F0(s32, f32, s32, f32, f32, f32, s32);
extern void func_L39_00630988(u8 *m, f32 x, f32 y, f32 z);
extern void func_L39_0062DA98(u8 *s);

void func_L39_0062D610(u8 *s) {
    Buf_0062FE58 buf;
    u32 dec;
    s32 eq;
    s32 mode;

    mode = s[0x1A06];
    if (*(s16 *)(s + 0x33E) != 0) {
        mode = 1;
    }
    switch (mode) {
    case 0:
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
        eq = dec == 0x24;
        if (eq) {
            return;
        }
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
        eq = dec == 0x25;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E6;
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
        eq = dec == 0x11;
        if (eq) {
            return;
        }
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
        eq = dec == 0x76;
        if (eq) {
            return;
        }
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
        eq = dec == 0x30;
        if (eq) {
            return;
        }
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
        eq = dec == 0x2C;
        if (eq) {
            return;
        }
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
        eq = dec == 0x2B;
        if (eq) {
            return;
        }
        buf.q = *(u128_t *)(s + 0xB0);
        func_L01_004455F0((s32)&buf.f[0], 0.0f, (s32)(s + 0xC0), 0.0149999997f, 0.300000012f, 0.0872664675f, 0);
        func_L01_004455F0((s32)&buf.f[1], 0.0f, (s32)(s + 0xC4), 0.0149999997f, 0.300000012f, 0.0872664675f, 0);
        func_L39_00630988(s, *(f32 *)(s + 0xC0), *(f32 *)(s + 0xC4), 0.0f);
        break;
    case 1:
    case 2:
        func_L39_0062DA98(s);
        break;
    }
}
/* localdecomp:end func_L39_0062D610 */
