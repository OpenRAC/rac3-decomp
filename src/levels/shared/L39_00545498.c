#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00545498);

INCLUDE_ASM("asm/levels", func_L39_005455C8);

INCLUDE_ASM("asm/levels", func_L39_00545740);

INCLUDE_ASM("asm/levels", func_L39_00545918);

INCLUDE_ASM("asm/levels", func_L39_00545B20);

/* localdecomp:start func_L39_00546250 */
s32 func_L39_00546250(s32 a0) {
    s32 p = *(s32 *)(*(s32 *)(*(s32 *)(a0 + 104) + 900) + 728);
    s32 r = 0;
    if (p != 0) {
        r = *(u8 *)(p + 6676) != 0;
    }
    return r;
}
/* localdecomp:end func_L39_00546250 */
