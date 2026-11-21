/* functional: medium. xy version of the length clamp: len = |src.xy|; returns 0 (writes nothing) when len == 0 or maxlen > len; otherwise dst.xy = src.xy * (maxlen / len), dst.zw = src.zw, returns 1. */
#include "vu0.h"
s32 func_L01_0040E728(f32 *dst, f32 *src, f32 maxlen) {
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];
    f32 w = src[3];
    f32 l2 = x * x + y * y;
    f32 len;
    f32 q;

    if (l2 < 0.0f) {
        l2 = -l2;
    }
    len = sqrt_asm(l2);
    if (len == 0.0f || maxlen - len > 0.0f) {
        return 0;
    }
    q = maxlen / len;
    dst[0] = x * q;
    dst[1] = y * q;
    dst[2] = z;
    dst[3] = w;
    return 1;
}
