#include "common.h"
/* localdecomp:start func_L03_003B4B38 */
#include "vu0.h"

extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L03_003B4B38(vu0_v4 *position, s32 count, s32 color1, s32 color2) {
    vu0_v4 point;
    vu0_v4 velocity;
    vu0_v4 *pt = &point;
    f32 size;
    s32 spin;
    s32 i;
    u8 *particle;

    point = *position;
    for (i = 0; i < count; i++) {
        size = func_0037E250(1.0f, 2.0f);
        spin = func_0037E1D8(2);
        if (spin == 0) {
            spin--;
        }
        func_L01_00440A88(&velocity, 0.05f, 0.25f);
        particle = func_L01_00467DA8(pt, 0x14, size * 0.1f, size, color1, 0, spin, &velocity, 0.00200000009f, 0);
        if (particle) {
            particle[9] = 0x74;
        }
        particle = func_L01_00467DA8(pt, 0x14, size * 0.07f, size * 0.7f, color2, 1, -spin, &velocity, 0.00200000009f, 0);
        if (particle) {
            particle[9] = 0x74;
        }
    }
}
/* localdecomp:end func_L03_003B4B38 */
