#include "common.h"

/* localdecomp:start func_L01_0045F328 */
extern u8 D_L01_001CCFD0[];

void func_L01_0045F328(s32 a0) {
    u8 *s;

    if (a0 != 0) {
        s = D_L01_001CCFD0;
        *(s16 *)(s + 0x78) = -0x8000;
        *(s16 *)(s + 0x7a) = 0;
    }
    {
        u8 *t;

        t = D_L01_001CCFD0;
        *(s16 *)(t + 0x50) = -0x8000;
        *(s16 *)(t + 0x52) = 0;
        *(s16 *)(t + 0xc8) = -0x8000;
        *(s16 *)(t + 0xca) = 0;
    }
}
/* localdecomp:end func_L01_0045F328 */
