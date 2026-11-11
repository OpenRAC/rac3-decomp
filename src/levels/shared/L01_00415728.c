#include "common.h"

/* localdecomp:start func_L01_00415728 */
extern s32 D_L01_001E1068;
extern u8 D_L01_001D0070[];

void func_L01_00415728(void) {
    *(s32 *)(D_L01_001E1068 + 0) = 0x30000026;
    *(s32 *)(D_L01_001E1068 + 4) = (s32)D_L01_001D0070;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000026;
    D_L01_001E1068 = D_L01_001E1068 + 0x10;
}
/* localdecomp:end func_L01_00415728 */
