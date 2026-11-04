#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006CC0E8);

INCLUDE_ASM("asm/levels", func_L39_006CC108);

LINKER_REMNANT("asm/levels", func_L39_006CC118);

INCLUDE_ASM("asm/levels", func_L39_006CC120);

/* localdecomp:start func_L39_006CC158 */
extern s32 D_L39_00249AF8[];
extern void func_L01_004D3BD0(void *);

void func_L39_006CC158(void *object, s32 flags) {
    *(u8 **)((u8 *)object + 0x1D0) = D_L39_00249AF8;
    if (flags & 1) {
        func_L01_004D3BD0(object);
    }
}
/* localdecomp:end func_L39_006CC158 */

INCLUDE_ASM("asm/levels", func_L39_006CC188);
