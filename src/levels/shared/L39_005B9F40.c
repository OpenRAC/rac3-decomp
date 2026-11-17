#include "common.h"

/* localdecomp:start func_L39_005B9F40 */
extern u8 D_002413B0[] __attribute__((section(".sdata")));
extern int D_001A5000[];

void func_L39_005B9F40(int index)
{
    int i;
    int j;
    int sum;
    int count;
    if (D_002413B0[index] != 0)
        return;
    sum = 0;
    for (j = 0; j < 60; j++)
        if (D_002413B0[j] != 0)
            sum += j;
    D_002413B0[index] = 1;
    if (index >= 0x1e || index == 24)
        return;
    count = 0;
    for (i = 0; i < 60; i++)
        if (D_001A5000[i] != 0)
            count++;
    D_001A5000[count] = index;
}
/* localdecomp:end func_L39_005B9F40 */

INCLUDE_ASM("asm/levels", func_L39_005B9FD8);
