#include "common.h"

/* localdecomp:start func_L39_0050A580 */
extern s32 func_L39_00509EA0(s32, s32, s32, s32);

s32 func_L39_0050A580(s32 a0, s32 a1, s32 a2) {
    return func_L39_00509EA0(a0, a1, a2, 2);
}
/* localdecomp:end func_L39_0050A580 */

/* localdecomp:start func_L39_0050A5A0 */
s32 func_L39_0050A5A0(void **arg0, s32 arg1) {
    void *temp_v1;

    if (arg1 <= 0) {
        return 1;
    }
    if (arg1 >= 2) {
        temp_v1 = *arg0;
        if (((*(u8 *)temp_v1) == 0) && ((*(u8 *)((u8 *)temp_v1 + 1)) == 0)) {
            *arg0 = temp_v1 + 2;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0050A5A0 */
