#include "common.h"

/* localdecomp:start func_L39_005A3680 */
extern s32 D_001A4568[];
extern u8 D_001D729D_sda;
extern s32 D_001D4CE8_sda;

void func_L39_005A3680(void) {
    if (D_001A4568[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_001D729D_sda == 0) {
        if ((*(s32 *)0x0024057C & 0x12) == 0) {
            return;
        }
    }
    *(s32 *)0x00240578 = 8;
}
/* localdecomp:end func_L39_005A3680 */
