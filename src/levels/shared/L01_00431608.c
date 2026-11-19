#include "common.h"

/* localdecomp:start func_L01_00431608 */
extern f32 *func_0039FDA0(s32, s32);

s32 func_L01_00431608(s32 i, f32 *out, s32 b) {
    f32 *p = func_0039FDA0(i, b);

    if (p != 0) {
        f32 x0 = p[0];
        f32 y0 = p[1];
        f32 x1 = p[2];
        f32 y1 = p[3];
        f32 x2 = p[4];
        f32 y2 = p[5];
        f32 x3 = p[6];
        f32 y3 = p[7];
        f32 sy = (y2 - y3) / (y0 - y1);
        f32 sx = (x2 - x3) / (x0 - x1);

        out[3] = sy;
        out[1] = sx;
        out[2] = y2 - sy * y0;
        out[0] = x2 - sx * x0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00431608 */

INCLUDE_ASM("asm/levels", func_L01_004316B0);

LINKER_REMNANT("asm/levels", func_L01_00431760);
