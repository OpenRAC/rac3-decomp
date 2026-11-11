#include "common.h"

/* localdecomp:start func_L01_00432A10 */
extern void (*D_L01_001D7598)(void);
extern s32 D_L01_001D4CEC[];
extern s32 D_L01_001D4CE8[];

void func_L01_00432A10(void) {
    if (D_L01_001D7598 != 0) {
        D_L01_001D7598();
        D_L01_001D7598 = 0;
    }
    if ((D_L01_001D4CEC[0] & 0x40) == 0) {
        D_L01_001D4CE8[0] = 4;
    }
}
/* localdecomp:end func_L01_00432A10 */
