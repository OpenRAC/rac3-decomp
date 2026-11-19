/* functional: high. 66 words differ at level_01 but only as scheduling shifts (div.s/sd ordering); same stack layout, calls and VU0 ops. func_003D3CB0 is the front-end segment collision test (frontbin). */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L01_00446BF0(f32 *a, f32 *b, f32 *p, f32 *q, void *arg4, s32 arg5, s32 steps) {
    vu0_v4 da, db, pa, pb, qv;
    f32 step = 1.0f / (f32)steps;
    f32 t = step;
    s32 i;

    vec_sub_ba(&da, a, p);
    vec_sub_ab(&db, b, q);
    for (i = 0; i < steps; i++) {
        func_0038CE20(&pa, &da, t);
        func_0038CE20(&pb, &db, t);
        vec_add_ba(&pa, &pa, p);
        vec_copy(&qv, q);
        vec_add_ab(&pb, &pb, &qv);
        if (func_003D3CB0(&pa, &pb, 0, arg4, arg5) != 0) {
            return 1;
        }
        t += step;
    }
    return 0;
}
