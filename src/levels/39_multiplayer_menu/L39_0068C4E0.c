#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068C4E0);

LINKER_REMNANT("asm/levels", func_L39_0068C708);

INCLUDE_ASM("asm/levels", func_L39_0068C718);

INCLUDE_ASM("asm/levels", func_L39_0068C918);

INCLUDE_ASM("asm/levels", func_L39_0068CBE8);

/* localdecomp:start func_L39_0068CD28 */
void func_00120D28(s32, s32, s32);

void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    if (arg1 != 0) {
        func_00120D28(arg0 + 4, arg1, 0x33);
        *(s8 *)(arg0 + 0x37) = 0;
    } else {
        *(s8 *)(arg0 + 4) = 0;
    }
    *(f32 *)(arg0 + 0x38) = arg2;
    *(f32 *)(arg0 + 0x3C) = arg3;
    *(f32 *)(arg0 + 0x40) = arg4;
    *(f32 *)(arg0 + 0x44) = arg5;
}
/* localdecomp:end func_L39_0068CD28 */

INCLUDE_ASM("asm/levels", func_L39_0068CDA8);

LINKER_REMNANT("asm/levels", func_L39_0068D1C0);

/* localdecomp:start func_L39_0068D1C8 */
extern u8 D_L39_0047C520[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0068D1C8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C520;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0068D1C8 */

INCLUDE_ASM("asm/levels", func_L39_0068D1F0);

INCLUDE_ASM("asm/levels", func_L39_0068D230);
