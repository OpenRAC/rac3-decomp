#include "common.h"

/* localdecomp:start func_L04_00313D88 */
extern s32 D_L04_001DC558;
extern s32 D_L04_001DC578;

void *func_L04_00313D88(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {                                 /* irregular */
    case 1:
        *arg2 = 0x1C;
        return &D_L04_001DC558;
    case 6:
        *arg2 = 4;
        return &D_L04_001DC578;
    default:
        return 0;
    }
}
/* localdecomp:end func_L04_00313D88 */
