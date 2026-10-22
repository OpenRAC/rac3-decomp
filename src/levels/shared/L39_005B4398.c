#include "common.h"

/* localdecomp:start func_L39_005B4398 */
s32 func_0019D510();

s32 func_L39_005B4398(s32 arg0) {
    return func_0019D510() % arg0;
}
/* localdecomp:end func_L39_005B4398 */

/* localdecomp:start func_L39_005B43C8 */
s32 func_0019D510();

s32 func_L39_005B43C8(s32 arg0, s32 arg1) {
    return (func_0019D510() % (s32) ((arg1 - arg0) + 1)) + arg0;
}
/* localdecomp:end func_L39_005B43C8 */

/* localdecomp:start func_L39_005B4410 */
s32 func_0019D510();

f32 func_L39_005B4410(f32 fparg0, f32 fparg1) {
    return fparg0 + ((f32) func_0019D510() * (fparg1 - fparg0) * 0.000030517578f);
}
/* localdecomp:end func_L39_005B4410 */

/* localdecomp:start func_L39_005B4468 */
s32 func_0019D510();

f32 func_L39_005B4468(f32 fparg0, f32 fparg1) {
    f32 var_f0;
    s32 temp_v0;

    temp_v0 = func_0019D510();
    var_f0 = fparg0 + ((f32) temp_v0 * (fparg1 - fparg0) * 0.000030517578f);
    if (temp_v0 & 1) {
        var_f0 = -var_f0;
    }
    return var_f0;
}
/* localdecomp:end func_L39_005B4468 */

INCLUDE_ASM("asm/levels", func_L39_005B44C8);

INCLUDE_ASM("asm/levels", func_L39_005B4510);
