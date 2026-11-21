#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004485E0 */
extern f32 func_0038DB00(f32, f32);

f32 func_L01_004485E0(f32 target, f32 pos, u8 *mode) {
    f32 d = func_0038DB00(target, pos);

    if (mode == 0 || d * (f32)(s32)mode > 0.0f) {
        return d;
    }
    if (fabs_asm(d) <= 0.0017453292f) {
        return 0.0f;
    }
    if (d > 0.0f) {
        return d - 6.2831855f;
    }
    return d + 6.2831855f;
}
/* localdecomp:end func_L01_004485E0 */

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
    if (fabs_asm(d) < c * 0.01f) {
        *pos = target;
        *vel = 0.0f;
        return *vel;
    }
    return d;
}
/* localdecomp:end func_L01_00448728 */

LINKER_REMNANT("asm/levels", func_L01_00448888);

/* localdecomp:start func_L01_00448890 */
#include "vu0.h"
extern f32 func_L01_004485E0(f32, f32, u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4138(f32 *, f32, f32);
extern void func_L01_00448690(f32 *, u8 *, f32, f32);

/* angle_approach: turns *angle towards goal, speeding *rate up and easing it to a stop. */
f32 func_L01_00448890(f32 *angle, f32 *rate, f32 goal, f32 slew, f32 accel, f32 top, s32 mode) {
    f32 d;
    f32 stop_dist;
    f32 limit;
    f32 vel;

    if (mode == 2) {
        if ((goal > 0.0f && *angle < 0.0f) || (goal < 0.0f && *angle > 0.0f)) {
            if (goal < 0.0f) {
                mode = -1;
            } else {
                mode = 1;
            }
        } else {
            mode = 0;
        }
    }
    d = ((f32 (*)(f32, f32, s32))func_L01_004485E0)(goal, *angle, mode);
    if (*rate == 0.0f && d == 0.0f) {
        return 0.0f;
    }
    vel = *rate;
    if (vel * d >= 0.0f) {
        stop_dist = vel * vel / accel * 0.5f;
        if (__builtin_fabsf(d) < stop_dist) {
            if (stop_dist < __builtin_fabsf(d) + __builtin_fabsf(vel)) {
                func_003C4138(rate, 0.0f, accel);
            } else {
                func_003C4138(rate, 0.0f, accel * 1.1f);
            }
        } else {
            limit = sqrt_asm((accel + accel) * d);
            if (top < limit) {
                limit = top;
            }
            if (d < 0.0f) {
                func_L01_00448690(rate, 0, -limit, slew);
            } else {
                func_L01_00448690(rate, 0, limit, slew);
            }
        }
        vel = *rate;
        if (!(__builtin_fabsf(vel) < __builtin_fabsf(d))) {
            *angle = goal;
            return d;
        }
    } else {
        if (vel < 0.0f) {
            vel += accel;
        } else {
            vel -= accel;
        }
        *rate = vel;
    }
    *angle = func_0038DAB8(vel, *angle);
    return *rate;
}
/* localdecomp:end func_L01_00448890 */
