#include "common.h"

/* localdecomp:start func_L39_005A5C38 */
extern s32 D_001D4CE8_sda;
extern s32 D_001D4CEC_sda;
extern s32 D_001A43E8[];
extern s32 D_L39_002403F8;
extern s32 D_L39_002403FC;

void func_L39_005A5C38(void)
{
    s32 x;
    s32 v;

    v = D_001A43E8[0];
    if (2 != v) {
        D_001D4CE8_sda = 4;
        return;
    }
    x = D_001D4CEC_sda;
    if (x & 0x2020) {
        s32 y = x & ~0x20;
        D_L39_002403F8 = 7;
        D_L39_002403FC = y & ~0x2000;
    }
}
/* localdecomp:end func_L39_005A5C38 */
