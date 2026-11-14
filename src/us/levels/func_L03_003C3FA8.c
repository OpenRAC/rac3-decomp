#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C3FA8 */
extern vu0_v4 D_L03_001E24C0_003C3FA8;
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_00389158(void *, f32, void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L03_003C3FA8(vu0_v4 *position, s32 count) {
    vu0_v4 velocity;
    vu0_v4 point;
    vu0_v4 direction;
    vu0_v4 axis;
    vu0_v4 offset;
    f32 size;
    s32 spin;
    s32 remaining;
    u8 *particle;
    vec_sub_ab(&direction, &D_L03_001E24C0_003C3FA8, position);
    func_00388830(&offset, &direction, 0.3f);
    direction.z = 0.0f;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.w = axis.z = 1.0f;
    for (remaining = 0; remaining < count; remaining++) {
        size = func_0037E250(0.5f, 2.0f);
        spin = func_0037E1D8(2);
        if (spin == 0) spin--;
        func_00389158(&velocity, func_0037E250(-1.0471975750923157f, 1.0471975750923157f), &direction, &axis);
        func_00388830(&velocity, &velocity, func_0037E250(0.05f, 3.0f) * 0.01666666753590107f);
        velocity.z = func_0037E250(1.0f, 5.0f) * 0.01666666753590107f;
        vec_add_ab(&point, position, &offset);
        position->x += func_L01_00440918(0.0f, 0.15f);
        position->y += func_L01_00440918(0.0f, 0.15f);
        position->z += func_L01_00440918(0.0f, 0.15f);
        particle = func_L01_00467DA8(&point, 60, size * 0.1f, size, 0xDD10FFFF, 0, spin, &velocity, 0.002f, 0);
        if (particle) particle[9] = 0x74;
        particle = func_L01_00467DA8(&point, 60, size * 0.07f, size * 0.7f, 0xDD10FFFF, 1, -spin, &velocity, 0.002f, 0);
        if (particle) particle[9] = 0x74;
    }
}
/* localdecomp:end func_L03_003C3FA8 */
