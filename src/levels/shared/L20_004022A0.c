#include "common.h"

/* localdecomp:start func_L20_004022A0 */
extern s32 func_L01_00447490(s32, s32, s32);
extern void func_L20_004015B0(f32, f32, f32, s32, s32, s32, s32, u32);

void func_L20_004022A0(s32 a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L20_004015B0(2.5f, -5.6f, 1.0f, a0, 31, 0, 7903, 0xC0508080);
    }
}
/* localdecomp:end func_L20_004022A0 */
