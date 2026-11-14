#include "common.h"

/* localdecomp:start func_L39_005FF060 */
#include "vu0.h"

extern void func_L39_005FF198(void *, void *, f32 *);
extern void func_0038CE20(f32 *, void *, f32);

void func_L39_005FF060(void *a, void *b, f32 *v, f32 t) {
    f32 d[4];

    func_L39_005FF198(a, b, d);
    func_0038CE20(d, d, t);
    vec_sub_ab(v, v, d);
}
/* localdecomp:end func_L39_005FF060 */

/* localdecomp:start func_L39_005FF0B8 */
#include "vu0.h"

extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_003D5630(void);

s32 func_L39_005FF0B8(f32 f, vu0_v4 *a, vu0_v4 *p, vu0_v4 *out, s32 flag) {
    vu0_v4 t;

    if (flag != 0) {
        func_0038CF68(&t, a, -6.0f);
        vec_add_ab(&t, &t, p);
        if (func_003D3CB0(p, &t, 2, 0, 0) == 0 || func_003D5630() != 2) {
            vu0_q q;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
            __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(q));
            func_0038CE20((f32 *)a, a, f);
            flag = 0;
        }
    }
    vec_sub_ba(out, out, a);
    return flag;
}
/* localdecomp:end func_L39_005FF0B8 */
