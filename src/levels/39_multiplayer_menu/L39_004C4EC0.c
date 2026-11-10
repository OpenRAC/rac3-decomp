#include "common.h"

/* localdecomp:start func_L39_004C4EC0 */
void func_L39_004C4EC0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC0) = arg1;
}
/* localdecomp:end func_L39_004C4EC0 */

INCLUDE_ASM("asm/levels", func_L39_004C4EC8);

INCLUDE_ASM("asm/levels", func_L39_004C4EE0);
