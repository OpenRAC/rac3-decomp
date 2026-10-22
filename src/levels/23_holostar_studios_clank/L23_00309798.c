#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_00309798);

INCLUDE_ASM("asm/levels", func_L23_00309888);

INCLUDE_ASM("asm/levels", func_L23_003098F8);

/* localdecomp:start func_L23_003099A8 */
extern s32 D_001A71A0[];
extern s32 D_L23_001DC5F4;
extern s32 D_L23_001DC5F8;

s32 func_L23_003099A8(s32 arg0) {
    return *(((arg0 ^ D_001A71A0[0]) == 0) ? &D_L23_001DC5F4 : &D_L23_001DC5F8) != 0;
}
/* localdecomp:end func_L23_003099A8 */

INCLUDE_ASM("asm/levels", func_L23_003099D0);
