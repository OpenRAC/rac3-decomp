/* functional: high. Squared distance in the xy plane between two points (z ignored). */
f32 func_L01_0040E570(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    return dx * dx + dy * dy;
}
