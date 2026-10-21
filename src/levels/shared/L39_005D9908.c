#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005D9908);

INCLUDE_ASM("asm/levels", func_L39_005DA400);

/* localdecomp:start func_L39_005DA638 */
extern s32 func_L01_00517688(void);
extern void func_L39_006121B0(s32);
extern u8 D_L39_001D7F50[8];
void func_L39_005DA638(void) {
    D_L39_001D7F50[func_L01_00517688()] = 0;
    func_L39_006121B0(6);
}
/* localdecomp:end func_L39_005DA638 */
