#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_004495A8);

INCLUDE_ASM("asm/levels", func_L03_004495E8);

/* localdecomp:start func_L03_004497E8 */
extern s32 D_L03_0021D8C0[];
extern void func_L03_00449838(s32 a0, s32 a1, s16 a2, s16 a3);
void func_L03_004497E8(s32 a0, s32 a1, s16 a2, s16 a3) {
    if (a1 != -1) {
        s32 x = D_L03_0021D8C0[a1];
        if (x) {
            func_L03_00449838(a0, x, a2, a3);
        }
    }
}
/* localdecomp:end func_L03_004497E8 */

INCLUDE_ASM("asm/levels", func_L03_00449838);
