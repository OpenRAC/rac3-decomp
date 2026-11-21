/* functional: high. Squared distance between two xyz points: (a-b)^2 summed x, y then z. */
f32 func_L01_0040E548(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    return (dx * dx + dy * dy) + dz * dz;
}
