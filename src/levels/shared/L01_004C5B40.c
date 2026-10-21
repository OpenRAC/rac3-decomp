#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004C5B40);

/* localdecomp:start func_L01_004C5B48 */
extern s32 *D_L01_001E1068;

void func_L01_004C5B48(s32 a) {
    D_L01_001E1068[0] = 0x10000000;
    D_L01_001E1068[1] = 0;
    D_L01_001E1068[2] = 0;
    D_L01_001E1068[3] = a;
    D_L01_001E1068 += 4;
}
/* localdecomp:end func_L01_004C5B48 */
