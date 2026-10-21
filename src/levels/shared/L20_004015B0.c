#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_004015B0);

/* localdecomp:start func_L20_004018A8 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L20_004015B0(u8 *, s32, s32, s32, s32, f32, f32, f32);
void func_L20_004018A8(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L20_004015B0(a0, 7, 0, 7854, 0xC050C020, 0.7f, -0.2f, 0.25f);
    }
}
/* localdecomp:end func_L20_004018A8 */
