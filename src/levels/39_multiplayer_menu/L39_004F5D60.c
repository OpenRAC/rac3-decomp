#include "common.h"

/* localdecomp:start func_L39_004F5D60 */
s32 func_L39_004F5D38(void);

/* from rac4-decomp's func_003FE5B0, renamed */
s32 func_L39_004F5D60(void *arg0) {
    s32 var_v0;
    var_v0 = func_L39_004F5D38();
    if (var_v0 != 0) {
        return var_v0;
    }
    var_v0 = (*(s32 *)((u8 *)arg0 + 0x2C) & 1) ? 0 : 0x202;
    return var_v0;
}
/* localdecomp:end func_L39_004F5D60 */
