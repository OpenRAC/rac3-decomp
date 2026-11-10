#include "common.h"

/* localdecomp:start func_L30_0034DA70 */
/* m2c3 */
f32 func_L30_0034DA70(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 var_f12;

    var_f12 = fparg0;
    if (fparg2 < var_f12) {
        var_f12 = fparg2;
    } else if (var_f12 < fparg1) {
        var_f12 = fparg1;
    }
    if (arg0 == 0) {
        var_f12 = (fparg2 + fparg1) - var_f12;
    }
    return (var_f12 - fparg1) / (fparg2 - fparg1);
}
/* localdecomp:end func_L30_0034DA70 */
