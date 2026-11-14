#include "common.h"

/* localdecomp:start func_L39_005A37F0 */
extern s32 D_001A4568[];
extern s32 D_001D4CEC_sda;
extern s32 D_001D4CE8_sda;

/* Probably the unformatted-memory-card case: sets D_001D4CE8_sda to 4 unless D_001A4568[0] is 2, in
 * which case it sets the screen state word to 12 if flag bits 0x806 are set. */
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
