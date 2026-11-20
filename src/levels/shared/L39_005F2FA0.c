#include "common.h"

/* declared by functions of L39_005F1470.c, which this file was cut from */
extern u8 D_001FE020[];

/* localdecomp:start func_L39_005F2FA0 */
extern u8 D_001FE020[];

s32 func_L39_005F2FA0(s32 arg0, s32 arg1) {
    u8 temp_a0;
    void *temp_v0;

    if (arg1 >= 0) {
        temp_v0 = (arg1 << 7) + D_001FE020;
        if (((*(s32 *)((u8 *)temp_v0 + 0xDC)) == arg0) && ((temp_a0 = (*(u8 *)((u8 *)temp_v0 + 0xD0)), (((u32) (temp_a0 - 1) < 2U) != 0)) || (temp_a0 == 7))) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005F2FA0 */
