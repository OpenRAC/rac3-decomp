/* functional: medium. Clamp a vector's length to maxlen: len = |src.xyz| (VU sqrt of |len^2|). Returns 0 and writes nothing when len == 0 or maxlen > len; otherwise dst.xyz = src.xyz * (maxlen / len), dst.w = src.w, returns 1. Retail's divide is a VU vdiv; len > 0 here so no div-by-zero case. */
#include "vu0.h"
s32 func_L01_0040E6B8(f32 *dst, f32 *src, f32 maxlen) {
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];
    f32 w = src[3];
    f32 l2 = (x * x + y * y) + z * z;
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
    dst[2] = z * q;
    dst[3] = w;
    return 1;
}
