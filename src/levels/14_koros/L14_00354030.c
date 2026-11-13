#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_00354030 */
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00452310(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
void func_L14_00354030(u8 *a0) {
    vu0_v4 v;
    u8 *s = *(u8 **)(a0 + 0x68);
    func_L01_003303B8(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.5f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_0038CE20(&v, s + 0x1D0, 0.7f);
    func_L01_00452310(a0, 0x3FF, &v, 1, 0x28, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_L01_004AAC98(4, 0, a0, 0x165C);
}
/* localdecomp:end func_L14_00354030 */
