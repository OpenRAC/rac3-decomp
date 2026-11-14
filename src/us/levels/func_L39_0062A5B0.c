#include "common.h"

/* localdecomp:start func_L39_0062A5B0 */
typedef union { u8 b[8]; u16 h[4]; u32 w[2]; } Buffer_0062A5B0;
extern s32 D_L39_00242B3C;
__asm__(".extern D_L39_00242B3C, 16");
extern s32 D_001D72B0_sda;
extern u8 D_L39_004998A0[];
extern u8 D_L39_00483AC0[];

s32 func_L39_0062A5B0(u8 *s) {
    Buffer_0062A5B0 buf;
    u32 dec;
    s32 result = *(s16 *)(s + 0x2D8);
    if (D_L39_00242B3C) { if (D_001D72B0_sda == 0) result = 2; }
    if (D_001D72B0_sda) goto force_one;
    else {
    {
        u8 *q = s + 0x19E4;
        if (*q == 0) {
            dec = 0;
        } else {
            u32 a, b;
            s32 n, k, m, i;
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
    if ((dec ^ 0x3B) == 0) goto force_one;
    else {
    {
        u8 *q = s + 0x19E4;
        if (*q == 0) {
            dec = 0;
        } else {
            u32 a, b;
            s32 n, k, m, i;
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
    if ((dec ^ 0x70) == 0 && !s[0x378]) goto force_one;
    else {
    {
        u8 *q = s + 0x19E4;
        if (*q == 0) {
            dec = 0;
        } else {
            u32 a, b;
            s32 n, k, m, i;
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
    if ((dec ^ 0x6F) == 0) goto force_one;
    else if (*(s16 *)(s + 0x33E) != 0) goto force_one;
    else if (s[0x377]) {
    u16 short_dec;
    {
        u8 *q = s + 0x1A40;
        if (*q == 0) {
            short_dec = 0;
        } else {
            u32 a, b, x;
            s32 n, k, m, i;
            u8 *d;
            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            d = buf.b;
            for (i = 0; i < 24; i += 3) {
                *d++ = D_L39_00483AC0[m + ((k + i) & 7) * 209];
            }

            a = buf.w[0] ^ (u32)q;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            x = b >> 16;
            buf.w[1] = x / (((b ^ x) << 16) + 1);
            short_dec = buf.h[2];
        }
    }
    if ((short_dec >> 14) & 1) {
    {
        u8 *q = s + 0x19E4;
        if (*q == 0) {
            dec = 0;
        } else {
            u32 a, b;
            s32 n, k, m, i;
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
    if (dec == 0) {
        if (*(s16 *)(s + 0x2DE) < 4) { goto force_one; goto done; }
    }
    }
    }
    }
    }
    }
    goto done;
force_one:
    result = 1;
done:
    if (result == 1 && s[0x378]) result = 0;
    return result;
}
/* localdecomp:end func_L39_0062A5B0 */
