#include "common.h"

/* localdecomp:start func_L03_003D0120 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003D0120(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 15, 0, 0, 1, 0, 0, 0, 0xC050C020, -20.0f, 0.0f);
    }
}
/* localdecomp:end func_L03_003D0120 */

INCLUDE_ASM("asm/levels", func_L03_003D0190);

INCLUDE_ASM("asm/levels", func_L03_003D02A0);

/* localdecomp:start func_L03_003D0598 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003D0598(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 31, 1, 7888, 1, 1, 1, 0, 0xC050C020, -1.0f, 2.5f);
    }
}
/* localdecomp:end func_L03_003D0598 */

INCLUDE_ASM("asm/levels", func_L03_003D0608);

/* localdecomp:start func_L03_003D07E0 */
extern void func_L03_003D0608(u8 *, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_00382498(s32, s32);

void func_L03_003D07E0(u8 *obj)
{
    if (*(u16 *)(obj + 150) == 0) {
        func_L03_003D0608(obj, 1, 3, -0.3f, 2.5f, 0.15f, 0.03f, 1.0f, -8.0f, 7.0f);
        *(u16 *)(obj + 150) = func_00382498(50, 400);
    }
    *(u16 *)(obj + 150) -= 1;
}
/* localdecomp:end func_L03_003D07E0 */
