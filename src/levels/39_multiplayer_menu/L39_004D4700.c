#include "common.h"

/* localdecomp:start func_L39_004D4700 */
extern s32 func_L39_004D1DC8(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004D4700(s32 arg0, s32 arg1, s32 arg2)
{
    return func_L39_004D1DC8(arg1, arg2, arg2 + 8, arg2 + 16, arg0, arg2 + 24, 1);
}
/* localdecomp:end func_L39_004D4700 */

INCLUDE_ASM("asm/levels", func_L39_004D4730);

LINKER_REMNANT("asm/levels", func_L39_004D4D10);

INCLUDE_ASM("asm/levels", func_L39_004D4D18);

INCLUDE_ASM("asm/levels", func_L39_004D4E68);

INCLUDE_ASM("asm/levels", func_L39_004D5030);

LINKER_REMNANT("asm/levels", func_L39_004D51E8);

INCLUDE_ASM("asm/levels", func_L39_004D51F0);

INCLUDE_ASM("asm/levels", func_L39_004D5288);

/* localdecomp:start func_L39_004D5370 */
extern u8 D_L39_00453FB0[];
extern s32 func_001262A0(s32);
extern void func_L39_004D5488(s32, s32, s32);

void func_L39_004D5370(s32 arg0, s32 arg1)
{
    u8 *p = D_L39_00453FB0;
    u8 *q = p + 0x10544;
    u32 i;

    (*(void (**)(void))(p + 0x10720))();
    for (i = 0; i < 0x20; i++) {
        q[i] = 0;
    }
    p = D_L39_00453FB0;
    func_001262A0(*(s32 *)(p + 0x106D4));
    func_L39_004D5488(0, arg1 ? -1 : *(s32 *)(p + 0x106B4), arg0);
}
/* localdecomp:end func_L39_004D5370 */

/* localdecomp:start func_L39_004D5420 */
extern u8 D_L39_00453FB0[];
extern void func_L39_004D5370(s32, s32);
extern void func_001262B0(s32);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);

void func_L39_004D5420(void)
{
    u8 *p = D_L39_00453FB0;

    func_L39_004D5370(0, 1);
    func_001262B0(*(s32 *)(p + 0x106C4));
    func_001262A0(*(s32 *)(p + 0x106C8));
    *(s32 *)(p + 0x106F4) = 0;
    func_00126280(*(s32 *)(p + 0x106C8));
}
/* localdecomp:end func_L39_004D5420 */

INCLUDE_ASM("asm/levels", func_L39_004D5488);
