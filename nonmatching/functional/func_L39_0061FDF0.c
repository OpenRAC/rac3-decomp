/* exact: matches at level 39 (byte-identical, default flags) */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
f32 func_L39_0061FDF0(vu0_v4 *a, vu0_v4 *b, vu0_v4 *c) {
    vu0_v4 u, v;
    vec_sub_ab(&u, a, b);
    vec_sub_ab(&v, c, b);
    func_0038CF68(&u, &u, 1.0f);
    func_0038CF68(&v, &v, 1.0f);
    return 1.5707964f - func_0038D0C8(func_0038CE68(&u, &v));
}
