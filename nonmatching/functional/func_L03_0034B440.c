/* functional: medium. Written from the PAL assembly (no draft). Easing/waveform helper: t = (int)time % (int)period / period (inverted when `invert` == 1), one of six curves (linear, cosine S, quadratic, sine, cubic-ish, one cosine period), then an optional output mapping by `post`: 0 = the curve value, 1 = func_0038DB48 call (an angle function) on value * 2*pi, 2 = same on value * pi/2, 3 = 2*value - 1. For any other `post` retail returns the caller's stale callee-saved $f22 (undefined); here 0.0f. The integer modulo has no zero-divisor check in retail (-mno-check-zero-division); a zero period is guarded here to avoid a host trap. */
/* localdecomp:start func_L03_0034B440 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);
f32 func_L03_0034B440(f32 time, f32 period, s32 invert, s32 post, s32 curve) {
    s32 ti = (s32)time;
    s32 pi = (s32)period;
    f32 t, v, r;
    t = (f32)(pi != 0 ? ti % pi : 0) / period;
    if (invert == 1) t = 1.0f - t;
    switch (curve) {
    case 0:
        v = t;
        break;
    case 1:
        v = 0.5f - func_0038D098(t * 3.1415927f) * 0.5f;
        break;
    case 2:
        if (t < 0.5f) v = (t + t) * t;
        else v = (t + t) * (2.0f - t) - 1.0f;
        break;
    case 3:
        if (t < 0.5f) v = func_0038D0B0(t * 3.1415927f) * 0.5f;
        else v = 1.0f - func_0038D0B0((1.0f - t) * 3.1415927f) * 0.5f;
        break;
    case 4:
        if (t < 0.5f) v = (t + t) * (1.0f - t);
        else v = (t + t) * (t - 1.0f) + 1.0f;
        break;
    case 5:
        v = (func_0038D098(t * 6.2831855f) + 1.0f) * 0.5f;
        break;
    default:
        v = t;
        break;
    }
    if (post == 0) return v;
    if (post == 1) return func_0038DB48(v * 6.2831855f);
    if (post == 2) return func_0038DB48(v * 1.5707964f);
    if (post == 3) return (v + v) - 1.0f;
    return 0.0f;
}
/* localdecomp:end func_L03_0034B440 */
