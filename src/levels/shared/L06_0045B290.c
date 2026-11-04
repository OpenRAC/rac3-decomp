#include "common.h"

/* localdecomp:start func_L06_0045B290 */
f32 func_L06_0045B290(u8 *p, s32 a, s32 b, f32 x, f32 y) {
    f32 r;
    s32 i;

    if (a == b) {
        return y - x;
    }
    r = 0.0f;
    if (a < b) {
        u8 *e = p + a * 16;
        r = *(f32 *)(e + 0x1C) - x;
        i = a + 1;
        if (i < b) {
            a = b - i;
            do {
                r += *(f32 *)(p + i * 16 + 0x1C);
                i++;
                a--;
            } while (a != 0);
        }
        r = r + y;
    } else {
        a--;
        r = r - x;
        if (b < a) {
            do {
                r = r - *(f32 *)(p + a * 16 + 0x1C);
                a--;
            } while (b < a);
        }
        {
            u8 *e = p + b * 16;
            r = r - (*(f32 *)(e + 0x1C) - y);
        }
    }
    return r;
}
/* localdecomp:end func_L06_0045B290 */

LINKER_REMNANT("asm/levels", func_L06_0045B348);
