#include "common.h"

/* localdecomp:start func_L40_0053D8C8 */
typedef struct {
    s32 id;
    s32 x4;
    s32 x8;
    s32 xC;
} Entry_0053B018;

extern Entry_0053B018 D_L40_00340030[];

s32 func_L40_0053D8C8(s32 id, s32 a1, s32 a2, s32 a3)
{
    s32 i;
    s32 slot = -1;

    for (i = 0; i < 10; i++) {
        if (D_L40_00340030[i].id == id) {
            return 2;
        }
        if (slot == -1 && D_L40_00340030[i].id == 0) {
            slot = i;
        }
    }
    if (slot == -1) {
        return -1;
    }
    D_L40_00340030[slot].id = id;
    D_L40_00340030[slot].xC = a3;
    D_L40_00340030[slot].x8 = a2;
    D_L40_00340030[slot].x4 = a1;
    return 1;
}
/* localdecomp:end func_L40_0053D8C8 */
