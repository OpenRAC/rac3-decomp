#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003C81D0);

/* localdecomp:start func_L03_003C8900 */
extern u8 D_001A4BE0[];
void func_L03_003C8900(void) {
    u8 *p = D_001A4BE0;
    s32 v = 2;
    *(s32 *)(p + 568) = v;
    *(s16 *)(p + 546) = v;
}
/* localdecomp:end func_L03_003C8900 */

INCLUDE_ASM("asm/levels", func_L03_003C8918);

INCLUDE_ASM("asm/levels", func_L03_003C8AC0);

INCLUDE_ASM("asm/levels", func_L03_003C8F78);
