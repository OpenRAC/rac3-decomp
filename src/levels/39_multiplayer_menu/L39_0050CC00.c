#include "common.h"

/* localdecomp:start func_L39_0050CC00 */
extern s32 func_L39_00515DA8(s32, void *, s32, s32 *);
extern s32 func_L39_0050CC90(void *, void *, void *, s32, void *);

s32 func_L39_0050CC00(void *a0, void *a1, void *a2, s32 a3, void *a4) {
    s32 out;
    if (a4 == 0) {
        out = a3;
    } else if (func_L39_00515DA8(*(s32 *)a0, a4, a3, &out) != 0) {
        return 0x803;
    }
    return func_L39_0050CC90(a0, a1, a2, out, a4);
}
/* localdecomp:end func_L39_0050CC00 */

INCLUDE_ASM("asm/levels", func_L39_0050CC90);
