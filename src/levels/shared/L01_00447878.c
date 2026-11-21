#include "common.h"

/* localdecomp:start func_L01_00447878 */
#include "vu0.h"
extern f32 func_0038CED8(void *);

f32 func_L01_00447878(f32 *a, f32 *b, f32 *out, f32 d, f32 e) {
    vu0_v4 v;
    f32 t;

    vec_sub_ab(&v, b, a);
    t = func_0038CED8(&v) / d;
    if (out != 0) {
        *out = t;
    }
    if (t != 0.0f) {
        return -((a[2] - b[2]) + e * (t * t) * 0.5f) / t;
    }
    return 0.0f;
}
/* localdecomp:end func_L01_00447878 */

INCLUDE_ASM("asm/levels", func_L01_00447938);

LINKER_REMNANT("asm/levels", func_L01_00448060);

/* localdecomp:start func_L01_00448070 */
int func_L01_00448070(int a, int b, float t)
{
    return a + (int)((b - a) * t);
}
/* localdecomp:end func_L01_00448070 */
