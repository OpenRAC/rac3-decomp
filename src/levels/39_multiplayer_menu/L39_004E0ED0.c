#include "common.h"

/* localdecomp:start func_L39_004E0ED0 */
s32 func_L39_004DD858(s32);
s32 func_L39_004EA5A8(s32);

s32 func_L39_004E0ED0(void *arg0) {
    s32 temp_v1;

    if (arg0 != 0) {
        temp_v1 = (*(s32 *)arg0);
        if (temp_v1 == 6) {
            return func_L39_004EA5A8((*(s32 *)((u8 *)arg0 + 0xC)));
        }
        if (temp_v1 == 0x74) {
            return func_L39_004DD858((*(s32 *)((u8 *)arg0 + 0xC)));
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004E0ED0 */
