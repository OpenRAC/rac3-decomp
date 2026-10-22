#include "common.h"

/* localdecomp:start func_L21_003AA338 */
s32 func_L21_003AA338(void *arg0) {
    s32 var_a1;
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x95);
    var_a1 = 0;
    if ((temp_v1 == 0) || ((temp_v1 == 1) && ((*(u8 *)((u8 *)arg0 + 0x20)) == temp_v1))) {
        var_a1 = 1;
    }
    return var_a1;
}
/* localdecomp:end func_L21_003AA338 */
