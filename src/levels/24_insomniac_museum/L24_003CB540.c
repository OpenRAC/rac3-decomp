#include "common.h"

/* localdecomp:start func_L24_003CB540 */
extern u8 D_001A4C60[];
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);

void func_L24_003CB540(u8 *a0) {
    if (func_0038CF38(a0 + 0x10, D_001A4C60) <= 3.0f) {
        func_L01_00452560(0, 0xD, 0x16AB, 1, 0, 0, 0);
    }
}
/* localdecomp:end func_L24_003CB540 */
