#include "common.h"

/* localdecomp:start func_L01_0044A850 */
#include "vu0.h"

extern void func_L01_0040E3C0_0044A850(void *, void *, f32);

void func_L01_0044A850(vu0_v4 *a, vu0_v4 *b)
{
    vu0_v4 c = *a;
    vu0_v4 d;
    vu0_v4 *pv = &c;
    int i;

    for (i = 0; i < 3; i++) {
        if ((&b->x)[i] < 0.0f) {
            vec_sub_ba(&d, b, pv);
            func_L01_0040E3C0_0044A850(&d, &d, fabs_asm(((&pv->x)[i] - 0.1f) / (&d.x)[i]));
            vec_add_ab(b, pv, &d);
        }
    }
}
/* localdecomp:end func_L01_0044A850 */
