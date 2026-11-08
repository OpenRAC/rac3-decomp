#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00351240);

/* localdecomp:start func_L07_00351498 */
extern void func_L07_00351498(u8 *);
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458 __attribute__((section(".sdata")));

/* from rac2-decomp's func_L16_0040D188 */
void func_L07_00351498(u8 *arg0)
{
    u16 *p;
    u8 *e;
    if (arg0[0x21] == 0xFF)
        return;
    p = D_L07_0021C020[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L07_001DF458 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L07_0021C020[arg0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == 0x161e)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2a4) = 1;
        else if (*(s16 *)(e + 0xAA) == 0xEA3)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x27c) = 1;
        p++;
    }
}
/* localdecomp:end func_L07_00351498 */
