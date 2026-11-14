#include "common.h"

/* localdecomp:start func_L39_004E15D8 */
extern char D_L39_004F4540[];
extern char D_L39_00477290[];
extern s32 func_L39_004E1610(char *, char *, s32, s32, s32);

/* from rac4-decomp's func_L00_0051D3D8, renamed */
void func_L39_004E15D8(s32 arg0, s32 arg1, s32 arg2) {
    func_L39_004E1610(D_L39_004F4540, D_L39_00477290, arg0, arg1, arg2);
}
/* localdecomp:end func_L39_004E15D8 */

INCLUDE_ASM("asm/levels", func_L39_004E1610);
