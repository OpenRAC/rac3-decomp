/* functional: high. Same operations and order as retail; the VU0 vector helpers (vsub.xyz, vadd.xyz, quadword copy) are plain float math with the w lane kept as retail does (d.w = q.w, out.w untouched by the add, quadword copy moves all four). The perpendicular is formed as r - (r + (d.y, -d.x)) to keep retail's rounding. Returns the unclamped t; the point is written with t clamped to 0..1. */
extern void func_0038CE20(void *, void *, f32);

f32 func_L01_004464C8(f32 *out, f32 *p, f32 *q, f32 *r) {
    f32 d[4], pr[2];
    f32 denom, t, tc, sx, sy, nx, ny, ax;

    d[0] = q[0] - p[0];
    d[1] = q[1] - p[1];
    d[2] = q[2] - p[2];
    d[3] = q[3];
    pr[0] = p[0] - r[0];
    pr[1] = p[1] - r[1];
    sx = r[0] + d[1];
    sy = r[1] + -d[0];
    nx = r[0] - sx;
    ny = r[1] - sy;
    denom = d[1] * nx - d[0] * ny;
    ax = denom < 0.0f ? -denom : denom;
    if (ax < 0.0001f) {
        out[0] = p[0];
        out[1] = p[1];
        out[2] = p[2];
        out[3] = p[3];
        return 0.0f;
    }
    t = (ny * pr[0] - nx * pr[1]) * (1.0f / denom);
    tc = t;
    if (tc < 0.0f) {
        tc = 0.0f;
    }
    if (1.0f < tc) {
        tc = 1.0f;
    }
    func_0038CE20(out, d, tc);
    out[0] = out[0] + p[0];
    out[1] = out[1] + p[1];
    out[2] = out[2] + p[2];
    return t;
}
