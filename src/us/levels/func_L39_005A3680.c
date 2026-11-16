#include "common.h"

/* localdecomp:start func_L39_005A3680 */
extern s32 D_001A4568[];
extern u8 D_001D729D_sda;
extern s32 D_001D4CE8_sda;

/* Menu state handler: sets D_001D4CE8_sda to 4 when D_001A4568[0] is not 2, otherwise sets state
 * word 0x00240578 to 8 when a button bit (0x12) is set or D_001D729D_sda is nonzero. */
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
