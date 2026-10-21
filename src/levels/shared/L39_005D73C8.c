#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005D73C8);

/* localdecomp:start func_L39_005D7670 */
extern s32 func_L01_00517688(void);
extern void func_L39_006121B0(s32);
extern u8 D_L39_001D7EE8[8];
void func_L39_005D7670(void) {
    D_L39_001D7EE8[func_L01_00517688()] = 0;
    func_L39_006121B0(7);
}
/* localdecomp:end func_L39_005D7670 */
