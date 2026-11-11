#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00432978);

/* localdecomp:start func_L01_004329A0 */
extern void (*D_L01_001D759C)(void);
extern s32 D_L01_001D4CEC[];
extern s32 D_L01_001D4CE8[];

void func_L01_004329A0(void) {
    if (D_L01_001D759C != 0) {
        D_L01_001D759C();
        D_L01_001D759C = 0;
    }
    if ((D_L01_001D4CEC[0] & 0x40) == 0) {
        D_L01_001D4CE8[0] = 4;
    }
}
/* localdecomp:end func_L01_004329A0 */
