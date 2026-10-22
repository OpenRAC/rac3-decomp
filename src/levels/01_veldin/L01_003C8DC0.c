#include "common.h"

/* localdecomp:start func_L01_003C8DC0 */
s32 func_L01_003C8DC0(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    if ((u32) (temp_v1 - 8) >= 2U) {
        return ((temp_v1 ^ 0xB) != 0) ? 0 : -1;
    }
    return 1;
}
/* localdecomp:end func_L01_003C8DC0 */
