#include "common.h"

/* localdecomp:start func_L14_003CF628 */
s32 func_00382380(void *, s32, s32);
extern s8 D_00142760[];
extern u8 D_001A4C60[];

void func_L14_003CF628(void *arg0) {
    if (func_00382380(D_001A4C60, *(*(s32 **)((u8 *)arg0 + 0x68)), 0) != 0) {
        D_00142760[0] = 1;
    }
}
/* localdecomp:end func_L14_003CF628 */
