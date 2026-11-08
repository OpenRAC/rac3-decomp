#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00596630);

INCLUDE_ASM("asm/levels", func_L39_00596A08);

INCLUDE_ASM("asm/levels", func_L39_00596E58);

/* localdecomp:start func_L39_00596EE0 */
extern void func_00133100(void), func_001393E8(s32, s32, s32, s32);
extern s32 D_001A5810[];
extern s32 D_002413A0;

/* from rac4-decomp's func_00458670 */
void func_L39_00596EE0(void)
{
    s32 mode;
    func_00133100();
    mode = D_001A5810[0];
    if (mode)
        D_002413A0 = 0;
    if (D_002413A0)
        func_001393E8(0, 0, 80, 1);
    else
        func_001393E8(0, 1, mode ? 3 : 2, 0);
}
/* localdecomp:end func_L39_00596EE0 */
