#include "common.h"

/* NTSC-U counterpart of func_L03_003C4EE8 (src/levels/03_starship_phoenix/L03_003C4EE8.c): 0.02 -> 0.0166667; 0.00288 -> 0.002; 50 -> 60 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V4_003B5710;

/* localdecomp:start func_L03_003C3098 */
extern u8 D_L03_001E24C0_003C3098[];
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);

void func_L03_003C3098(f32 *pos, s32 count) {
    f32 velocity[4], origin[4];
    V4_003B5710 direction;
    V4_003B5710 axis;
    f32 offset[4];
    f32 size, zero, angle, k;
    s32 sign;
    s32 i;
    u8 *p;
    vec_sub_ab(&direction, D_L03_001E24C0_003C3098, pos);
    func_00388830(offset, &direction, 0.3f);
    direction.z = 0;
    axis.x = 0;
    axis.y = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    i = 0;
    if (count > 0) {
    k = 0.0166666675f;
    zero = direction.z;
    for (; i < count; i++) {
        size = func_0037E250(0.5f, 2.0f);
        sign = func_0037E1D8(2);
        if (!sign) sign--;
        angle = func_0037E250(-1.0471976f, 1.0471976f);
        func_00389158(velocity, &direction, &axis, angle);
        func_00388830(velocity, velocity, func_0037E250(0.05f, 3.0f) * k);
        velocity[2] = func_0037E250(1.0f, 5.0f) * k;
        vec_add_ab(origin, pos, offset);
        pos[0] += func_L01_00440918(zero, 0.15f);
        pos[1] += func_L01_00440918(zero, 0.15f);
        pos[2] += func_L01_00440918(zero, 0.15f);
        p = func_L01_00467DA8(origin, size * 0.1f, 0x3C, size, 0.00200000009f, 0xDD10FFFF, 0, sign, velocity, 0);
        if (p) p[9] = 0x74;
        p = func_L01_00467DA8(origin, size * 0.07f, 0x3C, size * 0.7f, 0.00200000009f, 0xDD10FFFF, 1, -sign, velocity, 0);
        if (p) p[9] = 0x74;
    }
    }
}
/* localdecomp:end func_L03_003C3098 */
