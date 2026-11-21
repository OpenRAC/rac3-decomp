/* functional: medium. Reflect-style bounce: n = surface normal (src2), v = direction (src3). vhat = normalise(v) (VU rsqrt; zero length gives FLT_MAX like the VU's divide guard); d = -(n . vhat). If d's sign bit is set (vhat points along n) dst = n unchanged; otherwise dst.xyz = n + 2*d*vhat, dst.w = n.w. */
#include "vu0.h"
void func_L01_0040E790(f32 *dst, f32 *n, f32 *v) {
    f32 nx = n[0], ny = n[1], nz = n[2], nw = n[3];
    f32 vx = v[0], vy = v[1], vz = v[2];
    f32 l2 = (vx * vx + vy * vy) + vz * vz;
    f32 q;
    f32 hx, hy, hz, d;

    if (l2 < 0.0f) {
        l2 = -l2;
    }
    if (l2 == 0.0f) {
        q = 3.40282347e+38f;
    } else {
        q = 1.0f / sqrt_asm(l2);
    }
    hx = vx * q;
    hy = vy * q;
    hz = vz * q;
    d = ((-nx * hx) + (-ny * hy)) + (-nz * hz);
    if (*(s32 *)&d < 0) {
        dst[0] = nx;
        dst[1] = ny;
        dst[2] = nz;
        dst[3] = nw;
        return;
    }
    dst[0] = -nx + 2.0f * (hx * d - -nx);
    dst[1] = -ny + 2.0f * (hy * d - -ny);
    dst[2] = -nz + 2.0f * (hz * d - -nz);
    dst[3] = nw;
}
