#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0032FAB8);

/* localdecomp:start func_L03_0032FAF0 */
extern f32 func_0038D098(f32 a);
extern f32 func_0038D0B0(f32 a);

void func_L03_0032FAF0(f32 *out, f32 *in, f32 angle, f32 radius) {
    out[0] = in[0] + radius * func_0038D098(angle);
    out[1] = in[1] + radius * func_0038D0B0(angle);
    out[2] = in[2];
    out[3] = 0.0f;
}
/* localdecomp:end func_L03_0032FAF0 */

/* localdecomp:start func_L03_0032FB70 */
float func_L03_0032FB70(float x) {
    if (x < 0.0f) return x + 6.2831855f;
    return x;
}
/* localdecomp:end func_L03_0032FB70 */
