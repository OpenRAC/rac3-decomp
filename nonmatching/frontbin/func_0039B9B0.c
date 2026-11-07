/* Near miss of func_0039B9B0: tools/check.py reports 3 diff.
   What differs: gcc schedules the
   `lui` of the struct base (0x142430) before the `lui`/`lw` that reads the flag at 0x1D4CEC;
   retail reads the flag first. Declaring the struct as a scalar with a large size hint puts the
   load first but allocates the registers differently (7 diff). */
#include "common.h"
typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_0039B9B0;
extern s32 D_001D4CEC_0039B9B0_r;
extern s32 D_001D4CEC_0039B9B0_w;
extern s32 D_001D4CEC_0039B9B0_g;
extern s32 D_001D4CE8_0039B9B0;
__asm__(".extern D_001D4CEC_0039B9B0_r, 16");
__asm__(".extern D_001D4CEC_0039B9B0_w, 16");
void func_0039B9B0(void) {
    S_396BC0 *s;
    s32 f;
    f = D_001D4CEC_0039B9B0_r;
    f &= ~4;
    D_001D4CEC_0039B9B0_g = f;
    s = &D_142430_0039B9B0;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CEC_0039B9B0_w = f | 0x40;
            D_001D4CE8_0039B9B0 = 0x16;
        } else {
            D_001D4CE8_0039B9B0 = s->f15C;
        }
    }
}
