#include "common.h"

/* localdecomp:start func_L24_003A76B8 */
void func_L24_003A76B8(void *a0, u8 *p, s32 a2, s32 a3)
{
    if (a3 == -1 || a2 == 1) {
        f32 v = *(f32 *)(p + 0x98C) + 0.01f;
        *(f32 *)(p + 0x98C) = v;
        if (v > 0.9f) {
            *(f32 *)(p + 0x98C) = 0.9f;
        }
    }
    if (a2 == -1 || a3 == 1) {
        f32 v = *(f32 *)(p + 0x98C) - 0.01f;
        *(f32 *)(p + 0x98C) = v;
        if (v < 0.5f) {
            *(f32 *)(p + 0x98C) = 0.5f;
        }
    }
}
/* localdecomp:end func_L24_003A76B8 */

INCLUDE_ASM("asm/levels", func_L24_003A7750);

INCLUDE_ASM("asm/levels", func_L24_003A7870);

INCLUDE_ASM("asm/levels", func_L24_003A79F0);
