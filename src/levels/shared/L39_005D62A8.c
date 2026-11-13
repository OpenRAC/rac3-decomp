#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005D62A8);

INCLUDE_ASM("asm/levels", func_L39_005D62B8);

LINKER_REMNANT("asm/levels", func_L39_005D63C0);

/* localdecomp:start func_L39_005D6408 */
extern u8 D_L39_002429AE;
extern s32 D_001D5C98_sda;
extern s32 D_001A5810[];

void func_L39_005D6408(void) {
    if (D_L39_002429AE == 0) {
        s32 v = D_001D5C98_sda;
        D_001D5C98_sda = v + 1;
        if ((v + 1) % 50 == 0 && D_001A5810[0] != 0) {
            D_001D5C98_sda = v + 11;
        }
    }
}
/* localdecomp:end func_L39_005D6408 */
