#include "common.h"

/* localdecomp:start func_L39_005A5B10 */
typedef struct { u8 pad0[0x15C]; s32 f15C; s32 f160; s32 f164; s32 f168; s32 f16C; } S_005A5B10;
extern S_005A5B10 D_001A43E0;
extern s32 D_L39_002403FC;
extern s32 D_L39_002403F8;
void func_L39_005A5B10(void) {
    D_L39_002403FC &= ~4;
    if (D_001A43E0.f15C == 2 && D_001A43E0.f164 < 0) {
        if (D_001A43E0.f16C != 0) {
            D_L39_002403FC |= 0x40;
            D_L39_002403F8 = 0x16;
        } else {
            D_L39_002403F8 = 2;
        }
    }
}
/* localdecomp:end func_L39_005A5B10 */
