/* US draft of func_003BAF90 (rac3-uya-decomp func_003B5AB0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BAF90 */
extern s32 func_0038E548(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_001D9698;
void func_003BAF90(s32 a, s32 pp, s32 qq) {
    f32 *p = (f32 *)pp;
    f32 *q = (f32 *)qq;
    f32 r;
    f32 t;
    f32 k;
    f32 c;
    f32 lo;
    f32 hi;
    if (a != 0) {
        c = 0.49f;
        t = (f32)func_0038E548(1.2f, a, -1) / D_001D9698;
        k = 1.2f;
        lo = 6.0f;
        hi = 11.0f;
        if (c < t) {
            k = 0.588000059f / t;
            t = c;
        }
        r = func_003C4088(lo, hi, (t - 0.0f) / c);
        *q = r;
        if (hi < r) {
            *q = hi;
        } else if (r < lo) {
            *q = lo;
        }
        *p = k;
    }
}
/* localdecomp:end func_003BAF90 */
