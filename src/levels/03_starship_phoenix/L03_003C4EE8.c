#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } V4_003B5710;

/* localdecomp:start func_L03_003C4EE8 */
extern u8 D_L03_001E2440[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);

void func_L03_003C4EE8(f32 *pos, s32 count) {
    f32 velocity[4], origin[4];
    V4_003B5710 direction;
    V4_003B5710 axis;
    f32 offset[4];
    f32 size, zero, angle, k;
    s32 sign;
    s32 i;
    u8 *p;
    vec_sub_ab(&direction, D_L03_001E2440, pos);
    func_0038CF68(offset, &direction, 0.3f);
    direction.z = 0;
    axis.x = 0;
    axis.y = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    i = 0;
    if (count > 0) {
    k = 0.020000001f;
    zero = direction.z;
    for (; i < count; i++) {
        size = func_003824E0(0.5f, 2.0f);
        sign = func_00382468(2);
        if (!sign) sign--;
        angle = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(velocity, &direction, &axis, angle);
        func_0038CF68(velocity, velocity, func_003824E0(0.05f, 3.0f) * k);
        velocity[2] = func_003824E0(1.0f, 5.0f) * k;
        vec_add_ab(origin, pos, offset);
        pos[0] += func_L01_00443A18(zero, 0.15f);
        pos[1] += func_L01_00443A18(zero, 0.15f);
        pos[2] += func_L01_00443A18(zero, 0.15f);
        p = func_L01_0046B458(origin, size * 0.1f, 0x32, size, 0.0028800003f, 0xDD10FFFF, 0, sign, velocity, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(origin, size * 0.07f, 0x32, size * 0.7f, 0.0028800003f, 0xDD10FFFF, 1, -sign, velocity, 0);
        if (p) p[9] = 0x74;
    }
    }
}
/* localdecomp:end func_L03_003C4EE8 */

INCLUDE_ASM("asm/levels", func_L03_003C5190);
