#include "common.h"

/* localdecomp:start func_L01_00366058 */
extern s32 D_001A71A4[];
extern s32 D_L01_001E1CE0;
extern f32 D_L01_001E1CE4;

void func_L01_00366058(void) {
    s32 incremented;
    s32 decremented;
    if (D_001A71A4[0] == 1) {
        incremented = D_L01_001E1CE0 + 1;
        D_L01_001E1CE0 = incremented;
        if (incremented >= 41) {
            D_L01_001E1CE0 = 40;
        }
    } else {
        decremented = D_L01_001E1CE0 - 1;
        D_L01_001E1CE0 = decremented;
        if (decremented < 0) {
            D_L01_001E1CE0 = 0;
        }
    }
    D_L01_001E1CE4 = (f32)D_L01_001E1CE0 / 40.0f;
}
/* localdecomp:end func_L01_00366058 */
