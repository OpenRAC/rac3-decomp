/* US draft of func_003C3FA0 (rac3-uya-decomp func_003C3E68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C3FA0 */
extern f32 func_0038D478(f32);
f32 func_003C3FA0(f32 a, f32 b, f32 t) {
    if (t == 0.0f) return a;
    if (t == 1.0f) return b;
    return a + (b - a) * ((1.0f - func_0038D478(t * 3.14159274f)) * 0.5f);
}
/* localdecomp:end func_003C3FA0 */
