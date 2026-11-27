#include "common.h"

/* localdecomp:start func_L39_004E5260 */
extern s32 D_L39_0046D354[];

s32 func_L39_004E5260(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    if (D_L39_0046D354[0] != 0) {
        return ((s32 (*)(s32, s32, u8 *, s32))D_L39_0046D354[0])(arg0, arg1, arg2, arg3);
    }
    return 0;
}
/* localdecomp:end func_L39_004E5260 */

LINKER_REMNANT("asm/levels", func_L39_004E5298);

/* localdecomp:start func_L39_004E52A0 */
void func_L39_004E52A0(s32 cb) {
    D_L39_0046D354[0] = cb;
}
/* localdecomp:end func_L39_004E52A0 */
