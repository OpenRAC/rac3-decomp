/* PAL near miss (Codex wave 7): near miss: 91 words differ with the file's flags.
 * Worker's note: 75 diff; w359/func_L01_00448890.05.log; float register allocation and branch scheduling, tested metadata divs 2 2; three equivalent wordings unchanged
 */
#include "common.h"
/* localdecomp:start func_L01_00448890 */
#include "vu0.h"
f32 func_L01_00448890(f32 *pos, f32 *vel, s32 mode, f32 target, f32 accel, f32 decel, f32 limit)
{
    extern f32 func_L01_004485E0(f32, f32, u8 *);
    extern void func_L01_00448690(f32 *, u8 *, f32, f32);
    extern void func_003C4138(f32 *, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    f32 d, stop, ad, speed, v;
    if (mode == 2) {
        if ((target > 0.0f && *pos < 0.0f) || (target < 0.0f && *pos > 0.0f)) {
            if (target < 0.0f) mode = -1;
            else mode = 1;
        } else mode = 0;
    }
    d = func_L01_004485E0(target, *pos, (u8 *)mode);
    if (*vel == 0.0f && d == 0.0f) return 0.0f;
    v = *vel;
    if (v * d >= 0.0f) {
        stop = v * v / decel * 0.5f;
        if (fabs_asm(d) < stop) {
            ad = fabs_asm(d);
            if (stop < ad + fabs_asm(v)) func_003C4138(vel, 0.0f, decel);
            else func_003C4138(vel, 0.0f, decel * 1.1f);
        } else {
            ad = fabs_asm(d);
            speed = sqrt_asm((decel + decel) * d);
            if (limit < speed) speed = limit;
            if (d < 0.0f) func_L01_00448690(vel, 0, -speed, accel);
            else func_L01_00448690(vel, 0, speed, accel);
        }
        v = *vel;
        if (!(fabs_asm(v) < ad)) {
            *pos = target;
            return d;
        }
    } else {
        if (v < 0.0f) v += decel;
        else v -= decel;
        *vel = v;
    }
    *pos = func_0038DAB8(v, *pos);
    return *vel;
}
/* localdecomp:end func_L01_00448890 */
