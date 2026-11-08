#include "common.h"

/* localdecomp:start func_L01_00448248 */
/* Steps *p toward target by at most step and returns the distance left, through the game's integer
   abs (abs_asm, include/vu0.h). */
#include "vu0.h"

f32 func_L01_00448248(s32 *p, s32 target, s32 step) {
    s32 d = target - *p;

    if (step < d) {
        d = step;
    } else if (d < -step) {
        d = -step;
    }
    *p += d;
    return abs_asm(target - *p);
}
/* localdecomp:end func_L01_00448248 */

LINKER_REMNANT("asm/levels", func_L01_00448298);

/* localdecomp:start func_L01_004482A0 */
extern void func_L01_00448148(f32 *, f32);

f32 func_L01_004482A0(f32 *a0, f32 *a1, f32 f1, f32 f2, f32 f3, f32 f4)
{
    f32 s = f1;
    f32 u = f4;
    f32 t;
    f32 r;

    f32 sum;

    func_L01_00448148(a1, s - a0[0]);
    sum = a0[0] + a1[0];
    a0[0] = sum;
    t = s - sum;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(t));
    if (r < u * 0.01f) {
        a0[0] = s;
        a1[0] = 0.0f;
        return a1[0];
    }
    return t;
}
/* localdecomp:end func_L01_004482A0 */

INCLUDE_ASM("asm/levels", func_L01_00448340);
