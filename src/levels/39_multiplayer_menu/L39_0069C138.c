#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0069C138);

LINKER_REMNANT("asm/levels", func_L39_0069C708);

/* localdecomp:start func_L39_0069C710 */
extern u8 D_L39_0047D110[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0069C710(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D110;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0069C710 */
