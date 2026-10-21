#include "common.h"

/* localdecomp:start func_L04_004700B8 */
extern u32 D_001D545C[];
extern s32 D_L04_002F1D30[];
extern s32 D_L04_001EE9A0[];
s32 func_L04_004700B8(s32 a0) {
    u32 n;
    s32 i;
    n = D_001D545C[0];
    if (n >= 19) {
        return 0;
    }
    for (i = D_L04_002F1D30[n]; i < D_L04_002F1D30[n + 1]; i++) {
        if (D_L04_001EE9A0[i] == a0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L04_004700B8 */
