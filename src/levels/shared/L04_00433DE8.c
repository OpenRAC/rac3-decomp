#include "common.h"

LINKER_REMNANT("asm/levels", func_L04_00433DE8);

/* localdecomp:start func_L04_00433E40 */
extern f32 D_L04_001D6AF4;
extern s32 D_L04_001D6AB0;
extern u8 D_L04_001D6AA5;
extern s32 D_L04_002E7220[];

void func_L04_00433E40(void) {
    D_L04_001D6AF4 = 1.0f;
    D_L04_002E7220[8] = (s32)&D_L04_001D6AB0;
    D_L04_002E7220[12] = 1;
    D_L04_001D6AA5 = 0;
}
/* localdecomp:end func_L04_00433E40 */
