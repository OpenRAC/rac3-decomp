#include "common.h"

/* localdecomp:start func_L39_006B2FC8 */
extern u8 D_L39_0047E310[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B2FC8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E310;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B2FC8 */
