#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_003A0EE8);

INCLUDE_ASM("asm/levels", func_L02_003A2320);

INCLUDE_ASM("asm/levels", func_L02_003A23C8);

INCLUDE_ASM("asm/levels", func_L02_003A2620);

/* localdecomp:start func_L02_003A2708 */
void func_L02_003A2708(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s16 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 4) = -1;
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L02_003A2708 */
