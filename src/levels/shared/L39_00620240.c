#include "common.h"

/* localdecomp:start func_L39_00620240 */
void func_L39_00620240(f32 *out, s32 *outi, s32 base, f32 *a, f32 *b, s32 *p1, s32 *p2, f32 unused, f32 minv) {
    f32 d = *p2 - *p1;
    f32 m = (d < minv) ? minv : d;
    f32 t;
    f32 u;

    t = m / d;
    *outi = base + (s32)m;
    u = 1.0f - t;
    out[0] = u * a[0] + t * b[0];
    out[1] = u * a[1] + t * b[1];
    out[2] = u * a[2] + t * b[2];
}
/* localdecomp:end func_L39_00620240 */

/* localdecomp:start func_L39_006202E0 */
#include "vu0.h"

extern f32 D_L39_0024118C_006202E0;
extern f32 func_L39_00590690_006202E0(f32 *a, f32 *b);
extern void func_L39_00590508_006202E0(f32 *out, f32 *in, f32 s);

void func_L39_006202E0(f32 *vel, f32 *acc, f32 *p0, f32 *p1, f32 *p2, s32 *t0, s32 *t1, s32 *t2) {
    f32 scale = D_L39_0024118C_006202E0 * 1000.0f;
    f32 dt1 = (f32)(*t2 - *t1) / scale;
    f32 dt0 = (f32)(*t1 - *t0) / scale;
    f32 sum = dt0 + dt1;
    f32 a, b, c, d, e, f, g;

    if (dt1 == 0.0f || func_L39_00590690_006202E0(p1, p2) < 0.02f) {
        qzero(vel);
        qzero(acc);
        return;
    }
    if (dt0 == 0.0f || func_L39_00590690_006202E0(p0, p1) < 0.02f) {
        vec_sub_ab(vel, p2, p1);
        func_L39_00590508_006202E0(vel, vel, 1.0f / dt1);
        qzero(acc);
        return;
    }
    a = dt1 / (dt0 * sum);
    b = 1.0f / dt0 - 1.0f / dt1;
    c = dt0 / (sum * dt1);
    vel[0] = a * -p0[0] + b * p1[0] + c * p2[0];
    vel[1] = a * -p0[1] + b * p1[1] + c * p2[1];
    vel[2] = a * -p0[2] + b * p1[2] + c * p2[2];
    d = 2.0f / (dt0 * sum);
    e = 2.0f / (dt0 * dt1);
    f = 2.0f / (sum * dt1);
    acc[0] = d * p0[0] - e * p1[0] + f * p2[0];
    acc[1] = d * p0[1] - e * p1[1] + f * p2[1];
    acc[2] = d * p0[2] - e * p1[2] + f * p2[2];
}
/* localdecomp:end func_L39_006202E0 */
