#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00695328);

INCLUDE_ASM("asm/levels", func_L39_00695368);

LINKER_REMNANT("asm/levels", func_L39_00695520);

INCLUDE_ASM("asm/levels", func_L39_00695530);

/* localdecomp:start func_L39_00695798 */
extern u8 D_L39_0047CC68[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00695798(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047CC68;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_00695798 */

INCLUDE_ASM("asm/levels", func_L39_006957C0);

INCLUDE_ASM("asm/levels", func_L39_00695AE0);

INCLUDE_ASM("asm/levels", func_L39_00695B28);

INCLUDE_ASM("asm/levels", func_L39_00695BA0);
