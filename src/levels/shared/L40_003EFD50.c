#include "common.h"

/* localdecomp:start func_L40_003EFD50 */
/* log: first draft MATCH with the file flags (and with -mvu0-use-vf0-vf2 --as ps2as). */
extern s32 D_L40_00246E1C;
extern s32 func_L39_005B4398(s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L40_003EFD50(u8 *a0) {
    if (a0[0x42] < 2 && (a0[0x60] & 2)) {
        if (func_L39_005B4398(D_L40_00246E1C - 1) == 0) {
            func_003C3A10(a0, 1, 0, 0x11);
        } else if (a0[0x42] != 0) {
            func_003C3A10(a0, 0, 0, 0x11);
        }
    }
}
/* localdecomp:end func_L40_003EFD50 */
