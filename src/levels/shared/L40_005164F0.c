#include "common.h"

/* localdecomp:start func_L40_005164F0 */
/* decode loop as in func_L39_0055AD78 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x34];
    s32 (*f34)(u8 *, s32, s32, s32, s32);
} VT_005164F0;
extern u8 D_L40_003BFE20[];

void func_L40_005164F0(u8 *g, u128_t *pos, s32 a2, s32 a3, f32 f) {
    s32 x;

    *(u128_t *)(g + 0x13C0) = *pos;
    *(f32 *)(g + 0x13CC) = f;
    *(s32 *)(g + 0x13D0) = 0;
    *(s32 *)(g + 0x13D4) = 0;
    {
        u8 *p = g + 0x19E4;
        if (*p == 0) {
            x = 0;
        } else {
            u32 buf[2];
            u8 *b;
            s32 i;
            s32 n = *p;
            s32 m = n + 1;
            s32 k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
    }
    if ((x ^ 100) == 0) {
        return;
    }
    {
        u8 *p = g + 0x19E4;
        if (*p == 0) {
            x = 0;
        } else {
            u32 buf[2];
            u8 *b;
            s32 i;
            s32 n = *p;
            s32 m = n + 1;
            s32 k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
    }
    if ((x ^ 0x65) == 0) {
        return;
    }
    {
        u8 *p = g + 0x19E4;
        if (*p == 0) {
            x = 0;
        } else {
            u32 buf[2];
            u8 *b;
            s32 i;
            s32 n = *p;
            s32 m = n + 1;
            s32 k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
    }
    if ((x ^ 0x66) == 0) {
        return;
    }
    (*(VT_005164F0 **)(g + 0x14))->f34(g, 0x66, 2, 0, 1);
    *(s32 *)(g + 0x13D4) = 1;
    *(s32 *)(g + 0x13DC) = a2;
    *(s32 *)(g + 0x13D8) = a3;
}
/* localdecomp:end func_L40_005164F0 */
