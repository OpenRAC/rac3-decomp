#include "common.h"

/* localdecomp:start func_L03_00435A08 */
f32 func_L03_00435A08(f32 *x, f32 *y, f32 a, f32 b, f32 c) {
    c = (c - 1.0f) * 1.2f + 1.0f;
    b = b * 0.10471976f;
    b = b * b;
    *y = *y * c;
    *y = *y + b * (a - *x);
    *x = *x + *y;
    return *y;
}
/* localdecomp:end func_L03_00435A08 */
