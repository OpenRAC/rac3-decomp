#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003D0878);

/* localdecomp:start func_L03_003D09C0 */
extern s32 func_L01_00447490(s32, s32, s32);
extern void func_L03_003D02A0(f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, u32);

void func_L03_003D09C0(s32 a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L03_003D02A0(0.0f, a0, 31, 0.0f, 0, 7837, 1, 1, 1, 1, 0xC050C020);
    }
}
/* localdecomp:end func_L03_003D09C0 */
