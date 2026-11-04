#include "common.h"

/* localdecomp:start func_L40_003F5F80 */
/* from rac2-decomp's func_L01_00390C60, renamed */
void func_L40_003F5F80(char *a0)
{
    char *v0 = *(char **)(a0 + 0x68);
    char *v1;
    unsigned char a1;
    if (v0 == 0)
        return;
    v1 = *(char **)v0;
    if (v1 == 0)
        return;
    a1 = *(unsigned char *)(v1 + 0x20);
    if (a1 == 0xFE)
        return;
    if (a1 == 0xFD)
        return;
    if (*(unsigned short *)(v1 + 0x34) & 1)
        *(unsigned short *)(a0 + 0x34) |= 0x41;
    else
        *(unsigned short *)(a0 + 0x34) &= 0xFFBE;
}
/* localdecomp:end func_L40_003F5F80 */
