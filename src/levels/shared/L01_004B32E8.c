#include "common.h"

/* localdecomp:start func_L01_004B32E8 */
extern u8 *D_L01_001DAAB0;
extern void func_0038D2D0(void *a0, f32 a1);
void func_L01_004B32E8(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0038D2D0(D_L01_001DAAB0 + i * 64, 1.0f);
    }
}
/* localdecomp:end func_L01_004B32E8 */

INCLUDE_ASM("asm/levels", func_L01_004B3338);

INCLUDE_ASM("asm/levels", func_L01_004B44CC);
