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

/* localdecomp:start func_L39_0068D1F0 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots at -0x444..-0x434. */
extern f32 D_001DC46C_sda;
extern f32 D_001DC470_sda;
extern f32 D_001DC474_sda;
extern f32 D_001DC478_sda;
extern f32 D_001DC47C_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_0068D1F0(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DC46C_sda, D_001DC470_sda, D_001DC474_sda, D_001DC478_sda, D_001DC47C_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_0068D1F0 */

INCLUDE_ASM("asm/levels", func_L39_0068D230);
