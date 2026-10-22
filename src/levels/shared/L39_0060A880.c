#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0060A880);

/* localdecomp:start func_L39_0060AA28 */
void func_0011E718(void *, s32);
extern u8 D_L39_00245800[];

s32 func_L39_0060AA28(s32 arg0, void *arg1) {
    func_0011E718(D_L39_00245800, (*(s32 *)((u8 *)arg1 + 4)));
    return 1;
}
/* localdecomp:end func_L39_0060AA28 */
