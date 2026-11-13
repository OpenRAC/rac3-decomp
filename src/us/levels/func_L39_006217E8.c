#include "common.h"

/* NTSC-U counterpart of func_L39_00623FB8 (src/levels/shared/L39_00622990.c) */
/* localdecomp:start func_L39_006217E8 */
extern u8 D_L39_004998A0[];
extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_L01_00445168(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);
extern f32 func_00388800(void *, void *);

typedef union Buf_00623FB8 {
    u8 b[8];
    u32 w[2];
} Buf_00623FB8;

void func_L39_006217E8(void *arg0) {
    u8 *g = arg0;
    Buf_00623FB8 buf;
    f32 *p = *(f32 **)(g + 0x2520);

    *(f32 *)(g + 0x1E8) = p[5];
    *(f32 *)(g + 0x1EC) = p[6];
    *(f32 *)(g + 0x1F0) = p[4];
    if ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0) {
        if (*(s16 *)(g + 0x14BC) < *(s32 *)(g + 0x2F0) && g[0x14AE] == 0) {
            *(f32 *)(g + 0x1EC) = *(f32 *)(g + 0x14C8);
        }
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 6) == 0) {
        *(f32 *)(g + 0x1EC) = (*(f32 **)(g + 0x2520))[7];
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0 || g[0x24FD] != 0) {
        *(f32 *)(g + 0x1E8) = 0.8f - (*(f32 **)(g + 0x2520))[4];
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x7E) == 0) {
        *(f32 *)(g + 0x1F0) = 0.8f;
    }
    if (g[0x216] == 0 || (({
        u8 *q = g + 0x19E8;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x12) == 0 || (({
        u8 *q = g + 0x19EB;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x12) == 0 ||
        *(f32 *)(g + 0x1E4) < (*(f32 **)(g + 0x2520))[6] - 0.17f || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x11) == 0 ||
        g[0x374] != 0 || func_00388800(g + 0x1D0, g + 0xA0) > *(f32 *)(g + 0x1F4) * 0.5f) {
        func_003BEBF8((f32 *)(g + 0x1E0), *(f32 *)(g + 0x1E8), 0.02f);
        func_003BEBF8((f32 *)(g + 0x1E4), *(f32 *)(g + 0x1EC), 0.02f);
        func_L01_00445168((f32 *)(g + 0x1F4), *(f32 *)(g + 0x1F0), (f32 *)(g + 0x1F8), 0.02f, 0.3f, 0.06666667f);
    }
}
/* localdecomp:end func_L39_006217E8 */
