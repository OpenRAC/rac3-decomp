#include "common.h"

/* localdecomp:start func_L36_00355290 */
s32 func_L36_00355290(s32 x)
{
    s32 r;

    if ((u32)x < 2) {
        return 4;
    }
    if (x == 2 || x == 9) {
        return 8;
    }
    if (x == 3 || x == 10) {
        return 0xB;
    }
    if (x == 4 || x == 11) {
        return 0xE;
    }
    if (x == 5 || x == 12) {
        return 0x11;
    }
    if (x == 6) {
        return 3;
    }
    if (x == 7) {
        return 4;
    }
    r = 5;
    if (x != 8) {
        r = 4;
    }
    return r;
}
/* localdecomp:end func_L36_00355290 */

/* localdecomp:start func_L36_00355330 */
void *func_L36_00355330(u8 *a0, s32 a1) {
    u8 **p = (u8 **)(*(u8 **)(a0 + 0x68) + 0x8C);
    s32 i;
    u8 *c;

    for (i = 0; i < 13; i++, p++) {
        if (*p != 0) {
            c = *(u8 **)(*p + 0x68);
            if (*(s16 *)(c + 0x46) == 0) {
                if (a1 == 0) {
                    *(s32 *)(c + 0x5C) = 1;
                    return *p;
                }
                a1--;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L36_00355330 */

INCLUDE_ASM("asm/levels", func_L36_00355388);

INCLUDE_ASM("asm/levels", func_L36_003553B8);
