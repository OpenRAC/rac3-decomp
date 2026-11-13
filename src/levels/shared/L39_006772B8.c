#include "common.h"

/* localdecomp:start func_L39_006772B8 */
typedef struct { u8 pad[0x180]; s32 w180; } S_006772B8;
extern S_006772B8 *D_L39_00241640 __attribute__((section(".data")));
extern s32 D_L39_002412DC __attribute__((section(".data")));
s32 func_L39_006772B8(s32 a, s32 b) {
    s32 r = 0;
    if ((D_L39_00241640 != 0 && D_L39_00241640->w180 == 2) || (u32)(D_L39_002412DC - 0x2E) < 4) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_006772B8 */
