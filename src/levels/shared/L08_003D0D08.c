#include "common.h"

/* localdecomp:start func_L08_003D0D08 */
extern u8 *D_L08_001E1D90[];
extern u8 *D_L08_001DEA84;
extern f32 D_L08_001DEBD0;

s32 func_L08_003D0D08(s32 index) {
    u8 *y;

    if (*(s16 *)(D_L08_001E1D90[0] + 0x86) != 0x13) {
        return 1;
    }
    y = (u8 *)(*(s32 *)(*(s32 *)(*(u8 **)(D_L08_001DEA84 + index * 32 + 0x1C) + 4) + 0x70) + 0x40);
    if (*(s16 *)(y + 0x14) == 1 && 1.0f == D_L08_001DEBD0) {
        return 1;
    }
    return *(s16 *)(y + 0x14) == 3;
}
/* localdecomp:end func_L08_003D0D08 */
