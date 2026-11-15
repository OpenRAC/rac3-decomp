#include "common.h"

/* localdecomp:start func_L30_0041FE40 */
f32 func_L30_0041FE40(s32 places, f32 x) {
    s32 scale = 1;
    s32 i;
    f32 s;
    f32 half;

    for (i = 0; i < places; i++) {
        scale *= 10;
    }
    s = (f32)scale;
    half = 1.0f / (s + s);
    if (x < 0.0f) {
        half = -half;
    }
    x += half;
    x *= s;
    x = (f32)(s32)x;
    return x / s;
}
/* localdecomp:end func_L30_0041FE40 */
