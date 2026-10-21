#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0044ABD0);

INCLUDE_ASM("asm/levels", func_L01_0044AE78);

/* localdecomp:start func_L01_0044AEB8 */
extern s32 func_003C4B50(u8 *a0);
s32 func_L01_0044AEB8(u8 *a0) {
    if (a0 == 0) return 0;
    if (func_003C4B50(a0) != 0) return *(s16 *)(a0 + 0xAA) == 0x1F6;
    return 1;
}
/* localdecomp:end func_L01_0044AEB8 */
