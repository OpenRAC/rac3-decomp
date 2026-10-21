#include "common.h"

/* localdecomp:start func_L01_00521630 */
extern s32 D_L01_001DC240_00521630;

extern s32 func_003EDBA8(s32, s32);
s32 func_L01_00521630(s32 p, s32 k) {
    if (k != D_L01_001DC240_00521630) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_L01_00521630 */

/* localdecomp:start func_L01_00521660 */
extern s32 D_L01_001DC240;
s32 func_L01_00521660(void) {
    return D_L01_001DC240;
}
/* localdecomp:end func_L01_00521660 */

INCLUDE_ASM("asm/levels", func_L01_00521668);
