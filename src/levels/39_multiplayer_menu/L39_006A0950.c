#include "common.h"

/* localdecomp:start func_L39_006A0950 */
extern int D_L39_0047D628[];
extern void func_L39_00688400(char *, int);
void func_L39_006A0950(char *a0, int a1)
{
    *(int *)(a0 + 0x60) = (int)D_L39_0047D628;
    *(int *)(a0 + 0x2B0) = -1;
    *(int *)(a0 + 0x2B4) = -1;
    *(int *)(a0 + 0x2B8) = -1;
    *(int *)(a0 + 0x2BC) = -1;
    *(int *)(a0 + 0x2C4) = -1;
    *(int *)(a0 + 0x2C8) = -1;
    *(int *)(a0 + 0x2C0) = -1;
    func_L39_00688400(a0, a1);
}
/* localdecomp:end func_L39_006A0950 */
