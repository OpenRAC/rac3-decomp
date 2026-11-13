#include "common.h"

/* NTSC-U counterpart of func_L39_005B9F40 (src/levels/shared/L39_005B9F40.c) */
/* localdecomp:start func_L39_005B7F88 */
extern u8 D_L39_00241530[] __attribute__((section(".sdata")));
extern int D_001A5180[];

void func_L39_005B7F88(int index)
{
    int i;
    int j;
    int sum;
    int count;
    if (D_L39_00241530[index] != 0)
        return;
    sum = 0;
    for (j = 0; j < 60; j++)
        if (D_L39_00241530[j] != 0)
            sum += j;
    D_L39_00241530[index] = 1;
    if (index >= 0x1e || index == 24)
        return;
    count = 0;
    for (i = 0; i < 60; i++)
        if (D_001A5180[i] != 0)
            count++;
    D_001A5180[count] = index;
}
/* localdecomp:end func_L39_005B7F88 */
