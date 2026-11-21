/* functional: medium. dst.xyz = src.xyz * (1/f), dst.w = src.w (VU0 vdiv + vmulq.xyz, whole quad stored). The VU divide by zero is not IEEE: Q becomes +-FLT_MAX, written out as retail's guard (sign of f). Denormal flushing not modelled. */
void func_L01_0040E408(f32 *dst, f32 *src, f32 f) {
    f32 q;
    f32 w = src[3];
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];

    if (f == 0.0f) {
        q = (*(u32 *)&f >> 31) ? -3.40282347e+38f : 3.40282347e+38f;
    } else {
        q = 1.0f / f;
    }
    dst[0] = x * q;
    dst[1] = y * q;
    dst[2] = z * q;
    dst[3] = w;
}
