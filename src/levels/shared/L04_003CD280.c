#include "common.h"

/* localdecomp:start func_L04_003CD280 */
extern s32 D_L04_001DE9F8;
extern s32 D_L04_001DEA08;

void *func_L04_003CD280(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {                                 /* irregular */
    case 0:
        *arg2 = 0xC;
        return &D_L04_001DE9F8;
    case 1:
        *arg2 = 0x1C;
        return &D_L04_001DEA08;
    default:
        return 0;
    }
}
/* localdecomp:end func_L04_003CD280 */
