#include "common.h"

/* localdecomp:start func_L39_0069E1A8 */
void func_L39_0069E1A8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C8) = arg1;
}
/* localdecomp:end func_L39_0069E1A8 */

INCLUDE_ASM("asm/levels", func_L39_0069E1B0);

LINKER_REMNANT("asm/levels", func_L39_0069E5B8);
