#include "common.h"

/* localdecomp:start func_L39_004C31D8 */
extern s32 func_L39_004C4EE0();

s32 func_L39_004C31D8(u8 *arg0) {
    s32 ret = 0;

    if (*(s32 *)(*(u8 **)(arg0 + 0x54) + 0x114) != 0) {
        u8 *p = *(u8 **)(arg0 + 0x54);
        if (*(s32 *)(p + 0x8C) == 0 && *(s32 *)(p + 0xA4) == 0 && !(func_L39_004C4EE0() & 0x3000)) {
            *(s32 *)(arg0 + 0x30) = 0x3004;
            ret = 1;
            *(s32 *)(*(u8 **)(arg0 + 0x54) + 0x114) = 0;
            *(s32 *)(*(u8 **)(arg0 + 0x54) + 0x11C) += 1;
            *(s32 *)(*(u8 **)(arg0 + 0x54) + 0x118) += 1;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004C31D8 */
