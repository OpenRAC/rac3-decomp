#include "common.h"

/* localdecomp:start func_L39_005A36D0 */
extern s32 D_001A4568[];
extern s32 D_001D4CE8_sda;
extern u8 D_L39_00242B2C;
extern void func_00397238(void);

/* Chooses the next game screen state in D_001D4CE8_sda: 4 when D_001A4568[0] is not 2, 0x1A or 7
 * when flag 0x20 is set (calling func_00397238), and otherwise turns flag 8 into a request code 9
 * in a global. */
void func_L39_005A36D0(void) {
    s32 flags;
    if (D_001A4568[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    flags = *(s32 *)0x0024057C;
    if (flags & 0x20) {
        func_00397238();
        if (D_L39_00242B2C != 0) {
            D_001D4CE8_sda = 0x1A;
        } else {
            D_001D4CE8_sda = 7;
        }
        return;
    }
    if (flags & 8) {
        *(s32 *)0x0024057C = flags ^ 8;
        *(s32 *)0x00240578 = 9;
    }
}
/* localdecomp:end func_L39_005A36D0 */
