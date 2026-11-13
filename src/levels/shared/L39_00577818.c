#include "common.h"

/* localdecomp:start func_L39_00577818 */
extern s16 D_L39_0024D740;
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern s32 func_L39_005C0EF0(s32 a0);

s32 func_L39_00577818(void) {
    if (D_L39_0024D740 == 0) {
        s32 v = D_L39_002412DC;
        D_L39_0024D740 = (v != 0x1A0A && v != -1 && v != 0x27 && !func_L39_005C0EF0(0x106A)) ? -1 : 1;
    }
    return D_L39_0024D740 == 1;
}
/* localdecomp:end func_L39_00577818 */
