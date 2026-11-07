/* near miss: int_approach (open-rac-engine, weapons.md: steps an int toward a target by at most
 * a step). All but the absolute value matches: retail has `sw; blezl $v1; neg $v1, $v1` (neg is
 * the trapping `sub`) and keeps the store before it, gcc's abs gives `bltzl; negu` and moves the
 * store into the return's delay slot. The same blezl/neg shape is in 19 Veldin functions: an
 * inline-asm ABS in the original source, it seems, which matched C may not use. */
#include "common.h"

/* localdecomp:start func_L01_00448248 */
/* int_approach: steps *value toward target by at most step; returns how far it still is. */
f32 func_L01_00448248(s32 *value, s32 target, s32 step) {
    s32 delta = target - *value;
    s32 left;

    if (step < delta) delta = step;
    else if (delta < -step) delta = -step;
    *value = *value + delta;
    left = target - *value;
    left = __builtin_abs(left);
    return left;
}
/* localdecomp:end func_L01_00448248 */
