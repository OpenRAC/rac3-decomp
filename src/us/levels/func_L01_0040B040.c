#include "common.h"

typedef struct {
    u8 pad0[0x140];
    f32 position[4];
} Globals_0040D510;

/* localdecomp:start func_L01_0040B040 */
extern Globals_0040D510 D_L01_001E2900;
extern void func_003BDA38(void *, s32, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_004633E8(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern s32 func_0037E208(s32, s32);

void func_L01_0040B040(char *object, int joint, int unused, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    u8 *particle;
    u8 *data;

    func_003BDA38(object, joint, initial);
    heading = func_00388A28(D_L01_001E2900.position[0] - *(f32 *)(object + 0x10),
                            D_L01_001E2900.position[1] - *(f32 *)(object + 0x14));
    point[0] = initial[0] + func_L01_00440918(0, radius);
    point[1] = initial[1] + func_L01_00440918(0, radius);
    point[2] = initial[2] + func_L01_00440918(0, radius);
    speed = func_0037E250(radius * 0.5f * 0.016666668f, radius * 1.3f * 0.016666668f);
    tilt = func_L01_00440918(0.6981317f, 0.87266463f);
    yaw = func_00389380(heading, func_L01_00440918(0, 1.5707964f));
    func_0037E4B8(velocity, speed, yaw, tilt);
    velocity[2] += func_0037E250(0.9f, 1.7f) * 0.016666668f;
    particle = func_L01_004633E8(0, 1.0f, 1.01f, radius * 1.4f * 210000.0f,
                                 point, -1, velocity, 0x101010, 0);
    if (particle != 0) {
        particle[3] = 0x44;
        *(s16 *)(particle + 0xA) = func_0037E208(40, 70);
        particle[9] = 100;
        data = particle + 0x20;
        *(f32 *)(data + 0x1C) = func_0037E208(1, 10);
        *(s32 *)(data + 4) = 3;
        data[0xA] = 0x7F;
        data[0xB] = particle[0xA];
    }
}
/* localdecomp:end func_L01_0040B040 */
