/* PAL near miss (b9-t2): 8 words differ: the float registers of the D*D compare and of the sqrt result (retail loads D into f1 before the move of the call result, ours into f0); sqrt_asm for the sqrt.s */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L04_0035C2B0 */
extern s32 func_0038DC20(void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern u8 D_L04_001E2840[];
__asm__(".extern D_001DD4F0, 4");
extern f32 D_001DD4F0;

void func_L04_0035C2B0(f32 w, vu0_v4 *p, s32 *out0, f32 *out1) {
    vu0_v4 q;
    f32 d;
    f32 t;

    q = *p;
    q.w = w;
    if (func_0038DC20(&q, D_001DD4F0) == -1) {
        *out0 = 0;
        *out1 = 1.0f;
        return;
    }
    d = func_L01_0040E548(D_L04_001E2840, p);
    if (D_001DD4F0 * D_001DD4F0 < d) {
        *out0 = 0;
        *out1 = 1.0f;
        return;
    }
    *out0 = 1;
    t = D_001DD4F0 - 4.0f;
    if (t * t < d) {
        *out1 = (sqrt_asm(d) - t) * 0.25f;
    } else {
        *out1 = 0.0f;
    }
}
/* localdecomp:end func_L04_0035C2B0 */
