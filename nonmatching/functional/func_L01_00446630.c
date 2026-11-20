/* functional: high. 26 words differ at level_01 (clamp scheduling only); same calls and VU0 ops as retail. func_0038CE68 is the dot product. */
#include "vu0.h"

static void v3sub_00446630(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] - pb[0], y = pa[1] - pb[1], z = pa[2] - pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v3add_00446630(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] + pb[0], y = pa[1] + pb[1], z = pa[2] + pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v4copy_00446630(void *d, void *s) {
    f32 *pd = (f32 *)d, *ps = (f32 *)s;
    f32 x = ps[0], y = ps[1], z = ps[2], w = ps[3];
    pd[0] = x; pd[1] = y; pd[2] = z; pd[3] = w;
}
static f32 fabs_00446630(f32 x) { return x < 0.0f ? -x : x; }
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L01_00446630(f32 *out, f32 *p, f32 *q, f32 *r) {
    vu0_v4 d, rp;
    f32 t;

    v3sub_00446630(&d, q, p);
    v3sub_00446630(&rp, r, p);
    t = func_0038CE68(&d, &rp) / func_0038CE68(&d, &d);
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (1.0f < t) {
        t = 1.0f;
    }
    func_0038CE20(&d, &d, t);
    v3add_00446630(out, p, &d);
    return t;
}
