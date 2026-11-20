/* functional: high. 55 words differ at level_01 (register allocation / scheduling); same loop, clamp maths and calls as retail: if target[i] < 0 the segment origin->target is shortened so axis i ends at 0.1 above zero (t=|(origin[i]-0.1)/delta[i]|). */
#include "vu0.h"

static void v3sub_0044A850(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] - pb[0], y = pa[1] - pb[1], z = pa[2] - pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v3add_0044A850(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] + pb[0], y = pa[1] + pb[1], z = pa[2] + pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v4copy_0044A850(void *d, void *s) {
    f32 *pd = (f32 *)d, *ps = (f32 *)s;
    f32 x = ps[0], y = ps[1], z = ps[2], w = ps[3];
    pd[0] = x; pd[1] = y; pd[2] = z; pd[3] = w;
}
static f32 fabs_0044A850(f32 x) { return x < 0.0f ? -x : x; }
extern void func_0038CE20(void *, void *, f32);

void func_L01_0044A850(f32 *origin, f32 *target) {
    vu0_v4 start, delta;
    f32 *tp = target;
    f32 *sp = (f32 *)&start;
    f32 *dp = (f32 *)&delta;
    s32 i;

    *(vu0_q *)&start = *(vu0_q *)origin;
    for (i = 2; i >= 0; i--) {
        f32 v = *tp++;
        if (v < 0.0f) {
            v3sub_0044A850(&delta, target, &start);
            func_0038CE20(&delta, &delta, fabs_0044A850((*sp - 0.1f) / *dp));
            v3add_0044A850(target, &start, &delta);
        }
        dp++;
        sp++;
    }
}
