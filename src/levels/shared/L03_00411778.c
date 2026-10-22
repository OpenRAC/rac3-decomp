#include "common.h"

/* localdecomp:start func_L03_00411778 */
extern s16 D_001A4DEE[];
extern s32 D_L03_001E6834[];

void func_L03_00411778(s32 arg0, s32 arg1) {
    if (D_L03_001E6834[0] == ((s32) ((arg0 * 5) + 2) / 6)) {
        D_001A4DEE[0] = (s16) ((s32) (((arg1 - arg0) * 5) + 2) / 6);
    }
}
/* localdecomp:end func_L03_00411778 */
