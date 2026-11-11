#include "common.h"

/* localdecomp:start func_L39_004CC408 */
s32 func_L39_004EEFF0(s32, s32);
s32 func_L39_004CC408(s32 *arg0) {
    s32 temp_a1;

    if ((arg0 == 0) || (temp_a1 = *arg0, (temp_a1 <= 0))) {
        return 0;
    }
    return func_L39_004EEFF0((s32) arg0, temp_a1 - 1);
}
/* localdecomp:end func_L39_004CC408 */
