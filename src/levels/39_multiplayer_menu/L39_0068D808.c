#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068D808);

LINKER_REMNANT("asm/levels", func_L39_0068D9A8);

/* localdecomp:start func_L39_0068D9B0 */
extern u8 D_L39_0047C620[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0068D9B0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C620;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0068D9B0 */
