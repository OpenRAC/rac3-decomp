/* US draft of func_003C48A8 (rac3-uya-decomp func_003BF360, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C48A8 */
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
void func_003C48A8(f32 *p, f32 *out) {
    f32 a, b, c, s, x, y, z, r;
    out[1] = func_0038D160(func_0038CED8(p), -p[2]);
    out[2] = func_0038D160(p[0], p[1]);
    if (__builtin_fabsf(out[2]) > 1e-5f) {
        c = func_0038D098(-out[2]);
        s = func_0038D0B0(-out[2]);
        x = c * p[4] - s * p[5];
        y = s * p[4] + c * p[5];
    } else {
        x = p[4];
        y = p[5];
    }
    if (__builtin_fabsf(out[1]) > 1e-5f) {
        c = func_0038D098(-out[1]);
        s = func_0038D0B0(-out[1]);
        z = -s * x + c * p[6];
        x = c * x + s * p[6];
    } else {
        z = p[6];
    }
    {
        f32 q;
        __asm__("sqrt.s %0, %1" : "=f"(q) : "f"(x * x + y * y));
        r = func_0038D160(q, z);
    }
    out[0] = r;
    if (y < 0.0f) {
        if (r < 0.0f) out[0] = -3.14159274f - r;
        else out[0] = 3.14159274f - r;
    }
}
/* localdecomp:end func_003C48A8 */
