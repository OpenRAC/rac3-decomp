/* functional: high. 55 words differ at level_01 (register allocation / scheduling); same loop, clamp maths and calls as retail: if target[i] < 0 the segment origin->target is shortened so axis i ends at 0.1 above zero (t=|(origin[i]-0.1)/delta[i]|). */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);

void func_L01_0044A850(f32 *origin, f32 *target) {
    vu0_v4 start, delta;
    f32 *tp = target;
    f32 *sp = (f32 *)&start;
    f32 *dp = (f32 *)&delta;
    s32 i;

    *(vu0_q *)&start = *(vu0_q *)origin;
    for (i = 2; i >= 0; i--) {
        f32 v = *tp++;
        if (v < 0.0f) {
            vec_sub_ab(&delta, target, &start);
            func_0038CE20(&delta, &delta, fabs_asm((*sp - 0.1f) / *dp));
            vec_add_ba(target, &start, &delta);
        }
        dp++;
        sp++;
    }
}
