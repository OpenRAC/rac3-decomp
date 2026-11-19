/* functional: high. Point-in-sphere test: b is a sphere (xyz centre, w radius), a a point. Retail forms |a-b|^2 - b.w^2 and tests its float bits as a signed 32-bit int > 0 (so -0.0 counts as inside); returns 1 when inside or on the surface, 0 when outside. */
s32 func_L01_0040E590(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 rr = b[3] * b[3];
    f32 d = ((dx * dx + dy * dy) + dz * dz) - rr;

    if (*(s32 *)&d > 0) {
        return 0;
    }
    return 1;
}
