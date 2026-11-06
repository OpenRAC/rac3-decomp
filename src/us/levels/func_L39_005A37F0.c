#include "common.h"

/* localdecomp:start func_L39_005A37F0 */
extern s32 D_001A4568[];
extern s32 D_001D4CEC_sda;
extern s32 D_001D4CE8_sda;

void func_L39_005A37F0(void) {
    if (D_001A4568[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_001D4CEC_sda & 0x806) {
        *(s32 *)0x00240578 = 12;
    }
}
/* localdecomp:end func_L39_005A37F0 */
