#include "common.h"

/* localdecomp:start func_L39_004DAE28 */
extern void func_L39_004DAE48(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);

/* from rac4-decomp's func_L00_00516C28, renamed */
void func_L39_004DAE28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t = arg3;
    func_L39_004DAE48(arg0, arg1, arg2, &t);
}
/* localdecomp:end func_L39_004DAE28 */

INCLUDE_ASM("asm/levels", func_L39_004DAE48);
