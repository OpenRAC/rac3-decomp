#include "common.h"

/* localdecomp:start func_L31_00424440 */
#include "vu0.h"
extern void func_003C5060(void *, void *, void *, void *);
extern f32 func_0038D160(f32, f32);

/* from rac2-decomp's func_002B04E0 */
f32 func_L31_00424440(u8 *o, vu0_v4 *a, void *c) {
    vu0_v4 v;

    vec_sub_ba(&v, a, o + 0x10);
    func_003C5060(o, &v, &v, c);
    return func_0038D160(v.x, v.y);
}
/* localdecomp:end func_L31_00424440 */
