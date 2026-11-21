/* functional: high. Hand-written float helper; sign test on the float bits (mfc1 + bltz) is written as a signed int reinterpretation so -0.0 counts as negative like retail. */
/* localdecomp:start func_L02_003E6F38 */
s32 func_L02_003E6F38(f32 a, f32 b, f32 tol) {
    f32 d = a - b;
    union { f32 f; s32 i; } u;
    if (d < 0.0f) d = -d;
    u.f = tol - d;
    return u.i >= 0;
}
/* localdecomp:end func_L02_003E6F38 */
