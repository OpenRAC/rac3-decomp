#include "common.h"

INCLUDE_ASM("asm/levels", func_L22_003E9FF0);

INCLUDE_ASM("asm/levels", func_L22_003EA088);

/* localdecomp:start func_L22_003EA388 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L22_003EA088(void *, s32, s32, s32, s32, f32, f32, f32);

void func_L22_003EA388(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L22_003EA088(a0, 0x7FF, 0, 0x1EC0, 0x80000020, 1.0f, 0.0f, 1.8f);
    }
}
/* localdecomp:end func_L22_003EA388 */

INCLUDE_ASM("asm/levels", func_L22_003EA3F0);
