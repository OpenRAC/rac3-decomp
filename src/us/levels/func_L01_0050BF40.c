#include "common.h"

/* localdecomp:start func_L01_0050BF40 */
extern s32 D_001A5808[] __attribute__((section(".data")));

/* Stores value in a global (D_001A5808), replacing -1 with 5, and returns the stored value. */
s32 func_L01_0050BF40(s32 value) {
    if (value == -1) {
        value = 5;
    }
    D_001A5808[0] = value;
    return value;
}
/* localdecomp:end func_L01_0050BF40 */
