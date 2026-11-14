#include "common.h"

/* localdecomp:start func_L39_005A3FC8 */
extern s32 D_001D4CE8_sda;
extern s32 D_001D4CEC_sda;
extern s32 D_001A4568[];

/* When the state at D_001A4568 is not 2 sets D_001D4CE8 to 4; otherwise, if flag bits 0x2020 are
 * set, clears bits 0x20 and 0x2000 and sets mode 7. */
void func_L39_005A3FC8(void) {
    s32 flags;
    s32 state = D_001A4568[0];
    if (2 != state) {
        D_001D4CE8_sda = 4;
        return;
    }
    flags = D_001D4CEC_sda;
    if (flags & 0x2020) {
        s32 updated = flags & ~0x20;
        *(s32 *)0x00240578 = 7;
        *(s32 *)0x0024057C = updated & ~0x2000;
    }
}
/* localdecomp:end func_L39_005A3FC8 */
