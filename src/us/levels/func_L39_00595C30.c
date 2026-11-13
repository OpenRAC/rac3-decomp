#include "common.h"

/* NTSC-U counterpart of func_L39_00596EE0 (src/levels/shared/L39_00596630.c) */
/* localdecomp:start func_L39_00595C30 */
extern void func_00133100(void), func_001393E8(s32, s32, s32, s32);
extern s32 D_001A5990[];
extern s32 D_L39_00241520;

/* from rac4-decomp's func_00458670 */
void func_L39_00595C30(void)
{
    s32 mode;
    func_00133100();
    mode = D_001A5990[0];
    if (mode)
        D_L39_00241520 = 0;
    if (D_L39_00241520)
        func_001393E8(0, 0, 80, 1);
    else
        func_001393E8(0, 1, mode ? 3 : 2, 0);
}
/* localdecomp:end func_L39_00595C30 */
