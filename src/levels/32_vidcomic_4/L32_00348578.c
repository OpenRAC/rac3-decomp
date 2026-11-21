#include "common.h"

/* localdecomp:start func_L32_00348578 */
#include "vu0.h"

extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);

/* a curve: the point count, then the points from offset 0x10 (row 0 is the header) */
typedef struct {
    s32 n;
} C_00348578;

void func_L32_00348578(C_00348578 *c, vu0_v4 *out, f32 t) {
    vu0_v4 *v = (vu0_v4 *)c;
    vu0_v4 a;
    vu0_v4 b;
    s32 n;
    s32 seg;
    f32 f;
    f32 frac;

    qzero(out);
    if (c == 0) {
        return;
    }
    n = c->n;
    if (n <= 0) {
        return;
    }
    if (n == 1) {
        *out = v[1];
        return;
    }
    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    seg = (s32)(t * (f32)(n - 1));
    if (n - 2 < seg) {
        *out = v[n];
        return;
    }
    if (seg == 0) {
        vec_sub_ba(&a, &v[1], &v[2]);
        vec_add_ba(&a, &a, &v[1]);
    } else {
        a = v[seg];
    }
    if (seg == c->n - 2) {
        vec_sub_ba(&b, &v[c->n], &v[c->n - 1]);
        vec_add_ab(&b, &b, &v[c->n]);
    } else {
        b = v[seg + 3];
    }
    f = t * (f32)(c->n - 1);
    frac = f - cvtsw_asm(cvtws_asm(f));
    func_L01_00445208(out, &v[seg + 1], &v[seg + 2], &a, &b, frac);
}
/* localdecomp:end func_L32_00348578 */
