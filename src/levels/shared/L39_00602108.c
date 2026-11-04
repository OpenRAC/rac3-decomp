#include "common.h"

/* localdecomp:start func_L39_00602108 */
extern u8 D_L39_00245348[];
extern u8 D_L39_00245368[];
extern void func_118E98(u8 *a0, s32 a1, u8 *a2);

void func_L39_00602108(s32 *p, u32 a1, s32 a2, s32 a3)
{
    if (a1 < 4)
        func_118E98(D_L39_00245348, 38, D_L39_00245368);
    p[1] = a3;
    p[2] = a1;
    p[4] = 0;
    p[5] = 0;
    p[3] = 0;
    p[0] = a2;
}
/* localdecomp:end func_L39_00602108 */
