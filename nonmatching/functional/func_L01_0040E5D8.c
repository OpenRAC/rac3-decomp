/* functional: high. Sphere overlap test, each argument is xyz centre + w radius. Returns 1 when |a-b|^2 - (a.w+b.w)^2 is negative (sign bit set, so -0.0 also counts), else 0. */
s32 func_L01_0040E5D8(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 rs = a[3] + b[3];
    f32 d = ((dy * dy + dx * dx) + dz * dz) - rs * rs;

    if (*(s32 *)&d >= 0) {
        return 0;
    }
    return 1;
}
