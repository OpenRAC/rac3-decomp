#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004485E0);

/* localdecomp:start func_L01_00448690 */
extern f32 func_L01_004485E0(f32, f32, u8 *);
extern f32 func_0038DAB8(f32, f32);

void func_L01_00448690(f32 *val, u8 *obj, f32 a, f32 lim)
{
    f32 d = func_L01_004485E0(a, *val, obj);

    if (lim < d) {
        d = lim;
    } else if (d < -lim) {
        d = -lim;
    }
    *val = func_0038DAB8(*val, d);
    func_L01_004485E0(a, *val, obj);
}
/* localdecomp:end func_L01_00448690 */

/* localdecomp:start func_L01_00448728 */
extern f32 func_L01_004485E0(f32, f32, u8 *);
extern void func_L01_00448148(f32 *vel, f32 d, f32 a, f32 b, f32 c);
extern f32 func_0038DAB8(f32 a, f32 b);
f32 func_L01_00448728(f32 *pos, f32 *vel, s32 mode, f32 target, f32 a, f32 b, f32 c) {
    f32 d;

    if (mode == 2) {
        if ((target > 0.0f && *pos < 0.0f) || (target < 0.0f && *pos > 0.0f)) {
            if (target < 0.0f) {
                mode = -1;
            } else {
                mode = 1;
            }
        } else {
            mode = 0;
        }
    }
    func_L01_00448148(vel, ((f32 (*)(f32 target, f32 pos, s32 mode))func_L01_004485E0)(target, *pos, mode), a, b, c);
    *pos = func_0038DAB8(*pos, *vel);
    d = ((f32 (*)(f32 target, f32 pos, s32 mode))func_L01_004485E0)(target, *pos, mode);
    if (__builtin_fabsf(d) < c * 0.01f) {
        *pos = target;
        *vel = 0.0f;
        return *vel;
    }
    return d;
}
/* localdecomp:end func_L01_00448728 */

LINKER_REMNANT("asm/levels", func_L01_00448888);

INCLUDE_ASM("asm/levels", func_L01_00448890);
