/* functional: high. Same operations and order as retail (perpendicular formed as r-(r+perp) to keep its rounding); only scheduling and stack layout differ (84 words at level_01 with -mvu0-use-vf0-vf2 added for the vector helpers). Returns the unclamped t, the point is written with t clamped to 0..1. */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);

f32 func_L01_004464C8(f32 *out, f32 *p, f32 *q, f32 *r) {
    vu0_v4 d, pr;
    f32 denom, t, tc, sx, sy, nx, ny;

    vec_sub_ab(&d, q, p);
    vec_sub_ab(&pr, p, r);
    /* retail forms the perpendicular as r - (r + (d.y, -d.x)), which rounds */
    sx = r[0] + d.y;
    sy = r[1] + -d.x;
    nx = r[0] - sx;
    ny = r[1] - sy;
    denom = d.y * nx - d.x * ny;
    if (fabs_asm(denom) < 0.0001f) {
        vec_copy(out, p);
        return 0.0f;
    }
    t = (ny * pr.x - nx * pr.y) * (1.0f / denom);
    tc = t;
    if (tc < 0.0f) {
        tc = 0.0f;
    }
    if (1.0f < tc) {
        tc = 1.0f;
    }
    func_0038CE20(out, &d, tc);
    vec_add_ba(out, out, p);
    return t;
}
