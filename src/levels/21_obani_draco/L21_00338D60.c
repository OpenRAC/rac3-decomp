#include "common.h"

/* localdecomp:start func_L21_00338D60 */
s32 func_L21_00338D60(void *arg0, u8 *arg1) {
    switch (*(u8 *)((u8 *)arg0 + 0xBC)) {
    case 1:
        return arg1[1];
    case 2:
        return arg1[2];
    case 0:
        return arg1[3];
    case 3:
        return arg1[4];
    default:
        return 0;
    }
}
/* localdecomp:end func_L21_00338D60 */
