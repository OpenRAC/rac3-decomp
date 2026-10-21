#include "common.h"

/* localdecomp:start func_L03_0039D9D0 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_00451FE0(u8 *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2880(u8 *);
extern u8 D_L03_001D66B0[];

void func_L03_0039D9D0(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L01_00451FE0(a0, 255, D_L03_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L03_0039D9D0 */
