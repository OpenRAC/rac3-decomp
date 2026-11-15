#include "common.h"

/* localdecomp:start func_L39_004E51C0 */
extern s32 D_L39_0046D34C[];

s32 func_L39_004E51C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_L39_0046D34C[0] != 0) {
        return ((s32 (*)(s32, s32, s32, s32))D_L39_0046D34C[0])(arg0, arg1, arg2, arg3);
    }
    return 0;
}
/* localdecomp:end func_L39_004E51C0 */

LINKER_REMNANT("asm/levels", func_L39_004E51F8);
