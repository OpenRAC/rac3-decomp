#include "common.h"

/* NTSC-U counterpart of func_L04_00377698 (src/levels/shared/L04_00377698.c): threshold 9 instead of 7, data at NTSC-U addresses */
/* localdecomp:start func_L04_00376310 */
extern s32 D_L04_001E1B24[];
extern s32 D_L04_001E1C00[];
extern s32 D_L04_001E1BD0;

s32 func_L04_00376310(s32 arg0) {
    if (arg0 != D_L04_001E1B24[0]) {
        return 0;
    }
    if (D_L04_001E1C00[0] != 1) {
        return 0;
    }
    if (D_L04_001E1BD0 < 9) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L04_00376310 */
