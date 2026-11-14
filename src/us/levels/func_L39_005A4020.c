#include "common.h"

/* localdecomp:start func_L39_005A4020 */
extern s32 D_001D4CE8_sda;
extern s32 D_001D4CEC_sda;
extern s32 D_001A4568[];

/* If the state is not 2, sets a global to 4. Otherwise, when flag 0x20 or 0x2000 is set, sets the
 * global at 0x240578 to 14 and clears those two flags. */
void func_L39_005A4020(void) {
    s32 flags;
    s32 state = D_001A4568[0];
    if (2 != state) {
        D_001D4CE8_sda = 4;
        return;
    }
    flags = D_001D4CEC_sda;
    if (flags & 0x2020) {
        s32 updated = flags & ~0x20;
        *(s32 *)0x00240578 = 14;
        *(s32 *)0x0024057C = updated & ~0x2000;
    }
}
/* localdecomp:end func_L39_005A4020 */
