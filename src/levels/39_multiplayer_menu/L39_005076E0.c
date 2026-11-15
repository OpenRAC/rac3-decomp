#include "common.h"

/* localdecomp:start func_L39_005076E0 */
extern u8 D_L39_00507B18[];

void func_L39_005076E0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    (*(void **)arg0) = D_L39_00507B18;
}
/* localdecomp:end func_L39_005076E0 */

INCLUDE_ASM("asm/levels", func_L39_005076F8);

INCLUDE_ASM("asm/levels", func_L39_005077B8);
