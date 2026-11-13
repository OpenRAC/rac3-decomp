#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

/* declared by functions of L39_0062D7C8.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_006319D8 */
s32 func_L39_006319D8(char *a0, s32 a1) {
    char *p = a0 + a1 * 80;
    s32 x = (*(s32 *)(p + 1140) == 2) ? *(s32 *)(p + 1144) : -1;
    return x == 14 || x == 15;
}
/* localdecomp:end func_L39_006319D8 */

/* localdecomp:start func_L39_00631A08 */
s32 func_L39_00631A08(s32 a0, u8 *p, s32 v) {
    if (v == 255) {
        v = p[169];
    }
    return v;
}
/* localdecomp:end func_L39_00631A08 */

/* localdecomp:start func_L39_00631A20 */
s32 func_L39_00631A20(u8 *a0, s32 a1, f32 *a2) {
    *a2 = 0.0f;
    switch (a1) {
    case 28:
    case 29:
    case 31:
        if (*(f32 *)(a0 + 1576) > 25.0f) {
            *a2 = -1.4835298f;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00631A20 */

/* localdecomp:start func_L39_00631A88 */

f32 func_L39_00631A88(S_0062F240 *a0, int a1)
{
    int n;
    if (a1 >= 32) {
        a1 = 31;
    }
    n = a0->count;
    if (n < a1) {
        a1 = n;
    }
    return a0->hist[(a0->head - a1 + 31) % 32];
}
/* localdecomp:end func_L39_00631A88 */

/* localdecomp:start func_L39_00631AD8 */
typedef union Buf_00631AD8 {
    u8 b[8];
    u32 w[2];
} Buf_00631AD8;

extern u8 D_L39_004997E0[];
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L39_00631AD8(u8 *s) {
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
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
    func_L01_0044EAE0(*(void **)(s + 0x2524), s + 0x13F8, s + 0x13FC, 0.3f, 0.139626354f, -1.0f);
}
/* localdecomp:end func_L39_00631AD8 */

INCLUDE_ASM("asm/levels", func_L39_00631CB0);
