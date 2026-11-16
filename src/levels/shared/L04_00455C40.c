#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00455C40 */
extern void func_0012FEF0(f32 *, void *, void *);

s32 func_L04_00455C40(void *a, void *b, void *c, void *d, f32 *out) {
    f32 u[4];
    f32 v[4];
    f32 w[4];
    f32 cross;
    f32 inv;
    f32 t;
    f32 s;
    func_0012FEF0(u, b, a);
    func_0012FEF0(v, c, d);
    func_0012FEF0(w, a, c);
    cross = u[1] * v[0] - u[0] * v[1];
    if (fabs_asm(cross) < 0.0001f) {
        return 0;
    }
    inv = 1.0f / cross;
    t = v[1] * w[0] - v[0] * w[1];
    s = u[0] * w[1] - u[1] * w[0];
    t *= inv;
    s *= inv;
    *out = t;
    if (t <= 0.0f) {
        return 0;
    }
    if (1.0f <= t) {
        return 0;
    }
    if (s <= 0.0f) {
        return 0;
    }
    if (1.0f <= s) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L04_00455C40 */
