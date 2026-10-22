#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005051E0);

INCLUDE_ASM("asm/levels", func_L39_005051F0);

INCLUDE_ASM("asm/levels", func_L39_00505270);

INCLUDE_ASM("asm/levels", func_L39_00505360);

INCLUDE_ASM("asm/levels", func_L39_005053AC);

INCLUDE_ASM("asm/levels", func_L39_005053BC);

INCLUDE_ASM("asm/levels", func_L39_00505508);

INCLUDE_ASM("asm/levels", func_L39_00505620);

INCLUDE_ASM("asm/levels", func_L39_00505718);

INCLUDE_ASM("asm/levels", func_L39_00505780);

INCLUDE_ASM("asm/levels", func_L39_005057D0);

INCLUDE_ASM("asm/levels", func_L39_00505838);

INCLUDE_ASM("asm/levels", func_L39_00505974);

/* localdecomp:start func_L39_00505980 */
extern s32 D_L39_00453D58[];
extern s32 D_L39_00453D5C[];
extern s32 D_L39_00453D60[];
extern u32 D_L39_0046EBD0[];

s32 func_L39_00505980(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 < (u32) D_L39_0046EBD0[0]) {
        D_L39_0046EBD0[0] = arg0;
        D_L39_00453D60[0] = arg1;
        D_L39_00453D58[0] = arg2;
        D_L39_00453D5C[0] = arg3;
    }
    return 0;
}
/* localdecomp:end func_L39_00505980 */

INCLUDE_ASM("asm/levels", func_L39_005059C0);

INCLUDE_ASM("asm/levels", func_L39_00505AE8);
