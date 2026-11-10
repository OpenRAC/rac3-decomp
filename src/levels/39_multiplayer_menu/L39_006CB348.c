#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006CB348);

LINKER_REMNANT("asm/levels", func_L39_006CB4C8);

INCLUDE_ASM("asm/levels", func_L39_006CB4D8);

/* localdecomp:start func_L39_006CB8B0 */
extern u8 D_L39_0047EFC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CB8B0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EFC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CB8B0 */
