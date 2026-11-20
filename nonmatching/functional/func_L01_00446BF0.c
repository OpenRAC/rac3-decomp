/* functional: high. 66 words differ at level_01 but only as scheduling shifts (div.s/sd ordering); same stack layout, calls and VU0 ops. func_003D3CB0 is the front-end segment collision test (frontbin). */
#include "vu0.h"

static void v3sub_00446BF0(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] - pb[0], y = pa[1] - pb[1], z = pa[2] - pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v3add_00446BF0(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] + pb[0], y = pa[1] + pb[1], z = pa[2] + pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v4copy_00446BF0(void *d, void *s) {
    f32 *pd = (f32 *)d, *ps = (f32 *)s;
    f32 x = ps[0], y = ps[1], z = ps[2], w = ps[3];
    pd[0] = x; pd[1] = y; pd[2] = z; pd[3] = w;
}
static f32 fabs_00446BF0(f32 x) { return x < 0.0f ? -x : x; }
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L01_00446BF0(f32 *a, f32 *b, f32 *p, f32 *q, void *arg4, s32 arg5, s32 steps) {
    vu0_v4 da, db, pa, pb, qv;
    f32 step = 1.0f / (f32)steps;
    f32 t = step;
    s32 i;

    v3sub_00446BF0(&da, a, p);
    v3sub_00446BF0(&db, b, q);
    for (i = 0; i < steps; i++) {
        func_0038CE20(&pa, &da, t);
        func_0038CE20(&pb, &db, t);
        v3add_00446BF0(&pa, &pa, p);
        v4copy_00446BF0(&qv, q);
        v3add_00446BF0(&pb, &pb, &qv);
        if (func_003D3CB0(&pa, &pb, 0, arg4, arg5) != 0) {
            return 1;
        }
        t += step;
    }
    return 0;
}
