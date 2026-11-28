#include "common.h"
/* localdecomp:start func_L01_00389198 */
#include "vu0.h"
extern vu0_v4 D_L01_001E2A40_00389198;
extern u8 *D_L01_00221118[];

void func_L01_00389198(void *p) {
    extern f32 func_00388A28(f32, f32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_L01_00440918(f32, f32);
    extern f32 func_00389380(f32, f32);
    extern void func_0037E4B8(void *, f32, f32, f32);
    extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 *origin = p;
    vu0_v4 delta, velocity, position;
    f32 angle, speed, tilt, yaw;
    f32 life;
    s32 type, i;
    u8 *particle;

    vec_sub_ab(&delta, &D_L01_001E2A40_00389198, origin);
    angle = func_00388A28(delta.x, delta.y);
    for (i = 14; i >= 0; i--) {
        speed = func_0037E250(0.5f, 1.0f);
        type = func_L01_00440918(1.0f, 2.0f);
        func_0037E250(0.05f, 0.2f);
        life = 210000.0f;
        tilt = func_0037E250(0.0f, 1.3962634f);
        yaw = func_00389380(angle, func_L01_00440918(0.0f, 1.3962634f));
        func_0037E4B8(&velocity, speed * 0.0166666675f, yaw, tilt);
        position.x = origin->x + func_L01_00440918(0.0f, 0.1f);
        position.y = origin->y + func_L01_00440918(0.0f, 0.1f);
        position.z = origin->z + func_L01_00440918(0.0f, 0.1f);
        particle = func_L01_00466F98(&position, &velocity, 30, 127, 0x7F7F7F, type,
            func_0037E250(0.05f, 0.2f) * life, 500.0f, 1.0f, 0.0f, 2.0f);
        if (particle) {
            particle[2] = D_L01_00221118[0x5B][1];
        }
    }
}
/* localdecomp:end func_L01_00389198 */
