/* functional: high. Near exact: instruction stream matches retail except 2 nops before div.s (needs a config/levels/divs_nops.txt line 'func_L01_0040BE10 2') and the file lacking -mvu0-use-vf0-vf2 for vec helpers; checked with that flag added. */
#include "vu0.h"
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_0040BE10(f32 *a, f32 *v) {
    f32 t;
    s32 i;
    f32 r;
    if (v[0] > 0.0f && v[1] > 0.0f && v[2] > 0.0f) {
        return;
    }
    t = 1.0f;
    for (i = 0; i < 3; i++) {
        if (v[i] <= 0.0f) {
            r = 1.0f - v[i] / (v[i] - a[i]);
            if (r < t) {
                t = r;
            }
        }
    }
    vec_sub_ab(v, v, a);
    func_0038CE20(v, v, t - 0.01f);
    vec_add_ba(v, v, a);
}
