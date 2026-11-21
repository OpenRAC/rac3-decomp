/* functional: high. Verified against PAL asm instruction by instruction (constants 1.2f, 0.49f, 0x3F16872C~0.588f, 6.0f, 11.0f; the delay-slot store of the result before the clamp checks is subsumed by the final value). D_001D9698 is read via lui (declared unsized). */
extern s32 func_0038E928(f32, s32, s32);
extern f32 func_003C4440(f32, f32, f32);
extern f32 D_001D9698[];
void func_003BB348(s32 a, f32 *p, f32 *q) {
    f32 r;
    f32 t;
    f32 k;
    f32 c;
    f32 lo;
    f32 hi;
    if (a != 0) {
        c = 0.49f;
        t = (f32)func_0038E928(1.2f, a, -1) / D_001D9698[0];
        k = 1.2f;
        lo = 6.0f;
        hi = 11.0f;
        if (c < t) {
            k = 0.588000059f / t;
            t = c;
        }
        r = func_003C4440(lo, hi, (t - 0.0f) / c);
        *q = r;
        if (hi < r) {
            *q = hi;
        } else if (r < lo) {
            *q = lo;
        }
        *p = k;
    }
}
