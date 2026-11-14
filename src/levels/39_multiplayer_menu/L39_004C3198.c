#include "common.h"

/* localdecomp:start func_L39_004C3198 */
s32 func_L39_004C3198(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x20) == 0) {
        return 1;
    }
    arg0 = *(u8 **)(arg0 + 0x54);
    if ((s32)(*(long *)arg0 & 1) == 0) {
        *(s32 *)(arg0 + 0x114) = 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004C3198 */
