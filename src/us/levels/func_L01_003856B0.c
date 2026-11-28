#include "common.h"
/* localdecomp:start func_L01_003856B0 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003868A0;
extern Vec_003868A0 D_L01_001E2A40_003856B0;
void func_L01_003856B0(u8 *obj, Vec_003868A0 *pos) {
    extern f32 func_00388A28(f32, f32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_L01_00440918(f32, f32);
    extern f32 func_00389380(f32, f32);
    extern void func_0037E4B8(Vec_003868A0 *, f32, f32, f32);
    extern void func_L01_00466F98(Vec_003868A0 *, Vec_003868A0 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    Vec_003868A0 delta, velocity, origin;
    u8 *state;
    f32 angle;
    s32 count;
    s32 i;
    state = *(u8 **)(obj + 0x68);
    vec_sub_ab(&delta, &D_L01_001E2A40_003856B0, pos);
    angle = func_00388A28(delta.x, delta.y);
    count = 2;
    if (*(s32 *)(state + 0x3C) <= 1) {
        count = 5;
    }
    for (i = 0; i < count; i++) {
        f32 speed = func_0037E250(0.5f, 1.0f);
        s32 type = (s32)func_L01_00440918(1.0f, 2.0f);
        f32 spread;
        f32 yaw;
        f32 duration;
        duration = func_0037E250(0.05f, 0.2f) * 210000.0f;
        spread = func_0037E250(0.0f, 1.39626336f);
        yaw = func_L01_00440918(0.0f, 1.39626336f);
        yaw = func_00389380(angle, yaw);
        func_0037E4B8(&velocity, speed * 0.0166666675f, yaw, spread);
        origin.x = pos->x + func_L01_00440918(0.0f, 0.1f);
        origin.y = pos->y + func_L01_00440918(0.0f, 0.1f);
        origin.z = pos->z + func_L01_00440918(0.0f, 0.1f);
        duration = func_0037E250(0.05f, 0.2f) * 210000.0f;
        func_L01_00466F98(&origin, &velocity, 30, 127, 0x7F7F7F, type, duration, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_L01_003856B0 */
