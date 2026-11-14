#include "common.h"

/* NTSC-U counterpart of func_L39_00631100 (src/levels/shared/L39_0062D7C8.c): 0.072 -> 0.05; 0.3024 -> 0.21; 0.1 -> 0.0833333; 0.2448 -> 0.17 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A0[];
#include "vu0.h"

/* localdecomp:start func_L39_0062E8B8 */
#include "vu0.h"

typedef union Buf_00631100 {
    u8 b[8];
    u32 w[2];
} Buf_00631100;

extern u8 D_L39_004998A0[];
extern f32 func_L39_0062FE30(u8 *, f32 *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00445208_0062E8B8(void *, void *, s32 *, f32, f32, f32);
extern void func_L01_00445168(f32 *, s32 *, f32, f32, f32, f32);

void func_L39_0062E8B8(u8 *self) {
    Buf_00631100 buf;

    if (self[0x1A06] != 0) {
        if (*(s16 *)(self + 0x2DE) == 0 && *(f32 *)(self + 0x2AC) < 0.0f) {
            f32 x = fabs_asm(*(f32 *)(self + 0x2AC));
            f32 y = fabs_asm(func_L39_0062FE30(self, (f32 *)(self + 0x120))) + 0.01f;
            if (x < y) {
                u8 *v = self + 0xA0;
                if (self[0x216] == 0 || func_00388800(self + 0x1D0, v) > *(f32 *)(self + 0x1F4) * 0.5f) {
                    *(u128_t *)v = *(u128_t *)(self + 0x260);
                    return;
                }
                func_L01_00445208_0062E8B8(v, self + 0x260, (s32 *)(self + 0x2D4), 0.0500000007f, 0.209999993f, 0.0833333358f);
            } else {
                func_L01_00445208_0062E8B8(self + 0xA0, self + 0x260, (s32 *)(self + 0x2D4), 0.0500000007f, 0.209999993f, 0.0833333358f);
            }
        } else {
            *(s32 *)(self + 0x2D4) = 0;
        }
        return;
    }
    if (*(s16 *)(self + 0x2DE) == 0 && *(f32 *)(self + 0xA8) < *(f32 *)(self + 0x2A8)) {
        f32 f4 = *(f32 *)(self + 0xA8);
        f32 f3 = *(f32 *)(self + 0x2A8);
        if (fabs_asm(f4 - f3) < fabs_asm(*(f32 *)(self + 0x128)) + 0.01f) {
            if (self[0x216] == 0 || func_00388800(self + 0x1D0, self + 0xA0) > *(f32 *)(self + 0x1F4) * 0.5f) {
                *(f32 *)(self + 0xA8) = *(f32 *)(self + 0x2A8);
            } else {
                func_L01_00445168((f32 *)(self + 0xA8), (s32 *)(self + 0x2D4), *(f32 *)(self + 0x2A8), 0.0500000007f, 0.170000002f, 0.0833333358f);
            }
        } else {
            if (*(f32 *)(self + 0x158) < 0.0f) {
                *(f32 *)(self + 0xA8) = f4 - *(f32 *)(self + 0x158);
                if (f3 < *(f32 *)(self + 0xA8)) {
                    *(f32 *)(self + 0xA8) = f3;
                }
            }
            func_L01_00445168((f32 *)(self + 0xA8), (s32 *)(self + 0x2D4), *(f32 *)(self + 0x2A8), 0.0500000007f, 0.170000002f, 0.0833333358f);
        }
    } else {
        *(s32 *)(self + 0x2D4) = 0;
    }
    {
    u8 *q = self + 0x19E6;
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
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    if (dec != 0) {
        u8 *q2 = self + 0x19E4;
        u32 dec2;
        s32 eq;
        if (*q2 == 0) {
            dec2 = 0;
        } else {
            u32 a;
            u32 b;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *d;

            n = *q2;
            k = ((u32)q2 - n) & 7;
            m = n + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q2;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            buf.w[1] = b;
            dec2 = b;
        }
        eq = dec2 == 2;
        if (!eq) {
            goto zero;
        }
    }
    if (*(f32 *)(self + 0x1A4) == 0.0f) {
        f32 hi = *(f32 *)(self + 0x2E4);
        f32 cur = *(f32 *)(self + 0xA8);
        if (hi < cur) {
            *(f32 *)(self + 0x2E4) = cur;
        } else {
            f32 lo = *(f32 *)(self + 0x2E8);
            if (cur < lo) {
                *(f32 *)(self + 0x2E8) = cur;
            } else if (lo == 0.0f) {
                *(f32 *)(self + 0x2E8) = cur;
            } else if (hi - lo < 0.03f) {
                *(f32 *)(self + 0xA8) = hi;
                *(s32 *)(self + 0x2E0) = 1;
            } else {
                *(s32 *)(self + 0x2E0) = 0;
                *(f32 *)(self + 0x2E4) = 0.0f;
                *(f32 *)(self + 0x2E8) = 0.0f;
            }
        }
    } else {
    zero:
        *(s32 *)(self + 0x2E0) = 0;
        *(f32 *)(self + 0x2E4) = 0.0f;
        *(f32 *)(self + 0x2E8) = 0.0f;
    }
    }
}
/* localdecomp:end func_L39_0062E8B8 */
