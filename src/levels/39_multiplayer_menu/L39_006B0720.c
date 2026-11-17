#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_006B0720);

INCLUDE_ASM("asm/levels", func_L39_006B0728);

/* localdecomp:start func_L39_006B0998 */
extern u8 D_L39_0047E0A0[];
void func_L39_00688400(void *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B0998(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E0A0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B0998 */
