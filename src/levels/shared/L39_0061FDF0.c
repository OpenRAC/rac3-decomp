#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0061FDF0);

/* localdecomp:start func_L39_0061FEA8 */
#include "vu0.h"
extern f32 D_L39_0024118C_0061FEA8;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_0040E548_0061FEA8(void *, void *);

void func_L39_0061FEA8(vu0_v4 *vel, vu0_v4 *acc, vu0_v4 *p0, vu0_v4 *p1, vu0_v4 *p2, s32 *t0, s32 *t1, s32 *t2) {
    f32 a = (f32)(*t2 - *t1) / (D_L39_0024118C_0061FEA8 * 1000.0f);
    f32 b = (f32)(*t1 - *t0) / (D_L39_0024118C_0061FEA8 * 1000.0f);
    f32 s;
    f32 c0, c1, c2, d0, d1, d2;

    if (a == 0.0f || func_L01_0040E548_0061FEA8(p1, p2) < 0.02f) {
        qzero(vel);
        qzero(acc);
        return;
    }
    if (b == 0.0f || func_L01_0040E548_0061FEA8(p0, p1) < 0.02f) {
        vec_sub_ab(vel, p2, p1);
        func_0038CE20(vel, vel, 1.0f / a);
        qzero(acc);
        return;
    }
    s = b + a;
    c0 = a / (b * s);
    c1 = 1.0f / b + 1.0f / a;
    c2 = 1.0f / a + 1.0f / s;
    d0 = 2.0f / (b * s);
    d1 = 2.0f / (b * a);
    d2 = 2.0f / (a * s);
    vel->x = c0 * p0->x - c1 * p1->x + c2 * p2->x;
    vel->y = c0 * p0->y - c1 * p1->y + c2 * p2->y;
    vel->z = c0 * p0->z - c1 * p1->z + c2 * p2->z;
    acc->x = d0 * p0->x - d1 * p1->x + d2 * p2->x;
    acc->y = d0 * p0->y - d1 * p1->y + d2 * p2->y;
    acc->z = d0 * p0->z - d1 * p1->z + d2 * p2->z;
}
/* localdecomp:end func_L39_0061FEA8 */

/* localdecomp:start func_L39_00620168 */
#include "vu0.h"
extern f32 D_L39_0024118C;
extern void func_0038CE20(void *, void *, f32);

void func_L39_00620168(vu0_v4 *out, s32 *outi, s32 base, vu0_v4 *vel, vu0_v4 acc, vu0_v4 *pos, s32 t0, s32 t1, f32 minv) {
    s32 m = (s32)minv;
    s32 d = t1 - t0;
    vu0_v4 vt, at;
    f32 t;

    if (d < m) {
        d = m;
    }
    *outi = base + d;
    *out = *pos;
    t = (f32)(*outi - t1) / (D_L39_0024118C * 1000.0f);
    func_0038CE20(&vt, vel, t);
    func_0038CE20(&at, &acc, t * 0.5f * t);
    vec_add_ab(out, out, &vt);
    vec_add_ab(out, out, &at);
}
/* localdecomp:end func_L39_00620168 */
