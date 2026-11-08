#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068DDC8);

INCLUDE_ASM("asm/levels", func_L39_0068E0E8);

INCLUDE_ASM("asm/levels", func_L39_0068E110);

LINKER_REMNANT("asm/levels", func_L39_0068E148);

INCLUDE_ASM("asm/levels", func_L39_0068E160);

LINKER_REMNANT("asm/levels", func_L39_0068E9E8);

/* localdecomp:start func_L39_0068E9F0 */
extern u8 D_L39_0047C720[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0068E9F0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C720;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0068E9F0 */

INCLUDE_ASM("asm/levels", func_L39_0068EA18);
