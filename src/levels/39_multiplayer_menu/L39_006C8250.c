#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C8250 */
extern u8 D_L39_0047EBA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006C8250(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EBA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006C8250 */
