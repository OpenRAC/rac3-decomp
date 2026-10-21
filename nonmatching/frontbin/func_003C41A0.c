/* US draft of func_003C41A0 (rac3-uya-decomp func_003BEC60, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C41A0 */
f32 func_003C41A0(f32 *pos, f32 *vel, f32 target, f32 maxv, f32 acc, f32 lim) {
    f32 d = target - *pos;
    f32 v;
    if (*vel == 0.0f && d == 0.0f) return 0.0f;
    v = *vel;
    if (0.0f <= v * d) {
        f32 stop = v * v / acc * 0.5f;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003C4138(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003C4138(vel, 0.0f, v);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003C4138(vel, -s, v);
            } else {
                func_003C4138(vel, s, v);
            }
        }
        if (__builtin_fabsf(*vel) < __builtin_fabsf(d)) {
            *pos = *pos + *vel;
            return *vel;
        }
        *pos = target;
        return d;
    } else {
        if (v < 0.0f) v = v + acc;
        else v = v - acc;
        *vel = v;
        *pos = *pos + v;
        return *vel;
    }
}
/* localdecomp:end func_003C41A0 */
