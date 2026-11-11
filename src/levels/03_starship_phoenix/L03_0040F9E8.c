#include "common.h"

/* localdecomp:start func_L03_0040F9E8 */
extern s32 D_001D4C60[];
extern s32 D_001D4C80[];
void func_L03_0040F9E8(s32 arg0) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_001D4C60[i] == arg0) D_001D4C60[i] = 0;
        if (D_001D4C80[i] == arg0) D_001D4C80[i] = 0;
    }
}
/* localdecomp:end func_L03_0040F9E8 */
