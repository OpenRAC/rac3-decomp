#include "common.h"

/* NTSC-U counterpart of func_L39_005A5B10 (src/levels/shared/L39_005A5B10.c) */
/* localdecomp:start func_L39_005A3EA0 */
typedef struct { u8 pad0[0x15C]; s32 f15C; s32 f160; s32 f164; s32 f168; s32 f16C; } S_005A5B10;
extern S_005A5B10 D_001A4560;
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
void func_L39_005A3EA0(void) {
    D_L39_0024057C &= ~4;
    if (D_001A4560.f15C == 2 && D_001A4560.f164 < 0) {
        if (D_001A4560.f16C != 0) {
            D_L39_0024057C |= 0x40;
            D_L39_00240578 = 0x16;
        } else {
            D_L39_00240578 = 2;
        }
    }
}
/* localdecomp:end func_L39_005A3EA0 */
