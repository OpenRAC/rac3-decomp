#include "common.h"

/* localdecomp:start func_L10_003E5E68 */
extern float D_L10_001E67A4[];
extern int D_L10_001E0194[] __attribute__((section(".sdata")));
extern int D_L10_001DF2D0[] __attribute__((section(".sdata")));
extern float D_L10_001E0140 __attribute__((section(".sdata")));
extern void func_003873C0(void);

/* from rac2-decomp's func_L00_002E54E0, renamed */
void func_L10_003E5E68(float value)
{
    int quantized;
    if (value < 1024.0f)
        value = 1024.0f;
    if (value > 4096.0f)
        value = 4096.0f;
    quantized = (int)value - 0x40;
    D_L10_001E67A4[0] = value * 1024.0f;
    D_L10_001E0194[0] = quantized;
    D_L10_001DF2D0[0] = quantized;
    D_L10_001E0140 = (value - 64.0f) * 1024.0f;
    func_003873C0();
}
/* localdecomp:end func_L10_003E5E68 */
