#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005C5FC8 */
extern void *func_003CD108(s32);
extern s32 func_0019D510();
extern u8 *D_L39_00296828[];
void *func_L39_005C5FC8(u128_t *a, u128_t *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 flag) {
    u8 *p = func_003CD108(4);
    u8 *s;
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *a;
        p[9] = 0xA4;
        *(s32 *)(p + 4) = c;
        p[3] = flag ? 0x48 : 0x44;
        p[1] = 0;
        p[2] = D_L39_00296828[0][0];
        p[8] = func_0019D510();
        s = p + 0x20;
        *(s32 *)(p + 0xC) = 0;
        *(u128_t *)(p + 0x10) = *a;
        *(u128_t *)(p + 0x20) = *b;
        *(s16 *)(p + 0xA) = e;
        *(s32 *)(s + 0x1C) = e;
        *(s32 *)(s + 0x10) = c;
        *(s32 *)(s + 0x14) = d;
        *(s16 *)(s + 0x18) = g;
        *(s16 *)(s + 0x1A) = f;
    }
    return p;
}
/* localdecomp:end func_L39_005C5FC8 */
