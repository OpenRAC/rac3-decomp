#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003CDE48);

INCLUDE_ASM("asm/levels", func_L07_003CDF40);

INCLUDE_ASM("asm/levels", func_L07_003CE080);

INCLUDE_ASM("asm/levels", func_L07_003CE2B8);

/* localdecomp:start func_L07_003CE2F8 */
void func_0038CF38(void *, s32);

void func_L07_003CE2F8(void *arg0) {
    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)arg0 + 0x68)) + 0x130);
}
/* localdecomp:end func_L07_003CE2F8 */

INCLUDE_ASM("asm/levels", func_L07_003CE320);

INCLUDE_ASM("asm/levels", func_L07_003CE330);

INCLUDE_ASM("asm/levels", func_L07_003CE3A8);

INCLUDE_ASM("asm/levels", func_L07_003CE618);

INCLUDE_ASM("asm/levels", func_L07_003CE858);

INCLUDE_ASM("asm/levels", func_L07_003CE940);

/* localdecomp:start func_L07_003CEA38 */
s32 func_L07_003CEA38(void *arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x418);
    if (temp_v0 == -1) {
        return 0;
    }
    return temp_v0 < 1;
}
/* localdecomp:end func_L07_003CEA38 */

INCLUDE_ASM("asm/levels", func_L07_003CEA60);

INCLUDE_ASM("asm/levels", func_L07_003CEC48);

INCLUDE_ASM("asm/levels", func_L07_003CECD0);
