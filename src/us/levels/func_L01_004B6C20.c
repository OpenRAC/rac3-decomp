#include "common.h"

/* NTSC-U counterpart of func_L01_004BA7B8 (src/levels/shared/L01_004BA278.c): 5 -> 6 */
/* localdecomp:start func_L01_004B6C20 */
extern f32 D_L01_001DF9D0;
__asm__(".extern D_L01_001DF9D0, 16");
extern f32 D_L01_001D6720_004B6C20;
extern void func_00385B60(s32);

void func_L01_004B6C20(void) {
    D_L01_001D6720_004B6C20 = 1.2f;
    if (D_L01_001DF9D0 < 1.0f) {
        func_00385B60(6);
    }
}
/* localdecomp:end func_L01_004B6C20 */
