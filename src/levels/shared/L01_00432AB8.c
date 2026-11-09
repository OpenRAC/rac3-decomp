#include "common.h"

/* localdecomp:start func_L01_00432AB8 */
extern u32 D_001D4CEC_sda;
extern s32 D_001D4CE8_sda;
__asm__(".extern D_001D4CEC_sda, 16");
__asm__(".extern D_001D4CE8_sda, 16");

/* from rac2-decomp's func_002988F0, renamed (constants adapted) */
void func_L01_00432AB8(void)
{
    if ((D_001D4CEC_sda & 0x40) == 0)
        D_001D4CE8_sda = 4;
}
/* localdecomp:end func_L01_00432AB8 */
