/* functional: high. 26 words differ at level_01 (clamp scheduling only); same calls and VU0 ops as retail. func_0038CE68 is the dot product. */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L01_00446630(f32 *out, f32 *p, f32 *q, f32 *r) {
    vu0_v4 d, rp;
    f32 t;

    vec_sub_ba(&d, q, p);
    vec_sub_ab(&rp, r, p);
    t = func_0038CE68(&d, &rp) / func_0038CE68(&d, &d);
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (1.0f < t) {
        t = 1.0f;
    }
    func_0038CE20(&d, &d, t);
    vec_add_ab(out, p, &d);
    return t;
}
