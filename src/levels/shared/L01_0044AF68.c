#include "common.h"

/* localdecomp:start func_L01_0044AF68 */
s32 func_L01_0044AF68(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0xcdb;
}
/* localdecomp:end func_L01_0044AF68 */

INCLUDE_ASM("asm/levels", func_L01_0044AF78);

INCLUDE_ASM("asm/levels", func_L01_0044BB30);

LINKER_REMNANT("asm/levels", func_L01_0044BDF0);
