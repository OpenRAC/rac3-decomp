/* functional: high. Squared length of the xyz vector (x*x + y*y + z*z, VU0 mul then add chain y into x then z). */
f32 func_L01_0040E4C0(f32 *v) {
    f32 xx = v[0] * v[0];
    f32 yy = v[1] * v[1];
    f32 zz = v[2] * v[2];
    return (xx + yy) + zz;
}
