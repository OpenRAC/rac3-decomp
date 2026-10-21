#include "common.h"

/* localdecomp:start func_L03_003CFFB8 */
extern s32 func_L01_00447490(s32, s32, s32);
extern void func_L03_003D02A0(f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, u32);

void func_L03_003CFFB8(s32 a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L03_003D02A0(0.0f, a0, 31, 0.0f, 0, 7837, 1, 1, 1, 1, 0xC050C020);
    }
}
/* localdecomp:end func_L03_003CFFB8 */

/* localdecomp:start func_L03_003D0020 */
extern void func_L03_003D0608(u8 *, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u16 func_00382498(s32, s32);

void func_L03_003D0020(u8 *m) {
    if (*(u16 *)(m + 150) == 0) {
        func_L03_003D0608(m, 0, 10, 0.0f, 0.0f, 0.25f, -0.04f, 1.0f, -8.0f, 7.0f);
        *(u16 *)(m + 150) = func_00382498(60, 400);
    }
    (*(u16 *)(m + 150))--;
}
/* localdecomp:end func_L03_003D0020 */

/* localdecomp:start func_L03_003D00A8 */
extern void func_L03_003D02A0(f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, u32);
extern s32 func_L01_00447490(s32, s32, s32);
void func_L03_003D00A8(u8 *a0) {
    if (((s32 (*)(u8 *, s32, s32))func_L01_00447490)(a0, -1, 0)) {
        ((void (*)(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32))func_L03_003D02A0)(a0, 31, 0, 7839, 1, 1, 1, 0, 0xC050C020, 1.5f, 8.0f);
    }
}
/* localdecomp:end func_L03_003D00A8 */
