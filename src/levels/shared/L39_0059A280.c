#include "common.h"

/* localdecomp:start func_L39_0059A280 */
extern void *func_0011D534(void *, s32, s32);

/* from rac4-decomp's func_0045C768, renamed */
void func_L39_0059A280(char *p)
{
    *(s32 *)(p + 0x58) = 0;
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x60) = 0;
    func_0011D534(p + 8, 0xcd, 0x50);
    *(s32 *)(p + 0x68) = 1;
    p[0x6c] = 0;
}
/* localdecomp:end func_L39_0059A280 */
