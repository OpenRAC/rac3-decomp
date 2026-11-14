#include "common.h"

/* NTSC-U counterpart of func_L03_00435A08 (src/levels/shared/L03_00435A08.c) */
/* localdecomp:start func_L03_00432550 */
f32 func_L03_00432550(f32 *x, f32 *y, f32 a, f32 b, f32 c) {
    b = b * 0.10471976f;
    b = b * b;
    *y = *y * c;
    *y = *y + b * (a - *x);
    *x = *x + *y;
    return *y;
}
/* localdecomp:end func_L03_00432550 */
