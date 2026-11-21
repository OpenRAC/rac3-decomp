/* PAL near miss (haiku-w1): 106 words differ with the file's flags; the prologue loads 210000.0f before the 1.0/2.0/0.05/0.2 constants (retail: those four first, then 210000.0f after atan2), and the first and later jal argument moves are not in their delay slots; the i-- sits before the if (retail: in the beqz slot). */
#include "common.h"
#include "vu0.h"

extern vu0_v4 D_L01_001E29C0;
typedef struct { u8 pad[0x16C]; u8 *owner; } State_0038A4B8;
extern State_0038A4B8 D_L01_00221098;

void func_L01_0038A4B8(void *p) {
    vu0_v4 *origin = p;
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 delta, velocity, position;
    f32 angle, speed, tilt, yaw, lifetime;
    s32 type, i;
    u8 *particle;
    f32 big;

    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    big = 210000.0f;
    i = 14;
    do {
        speed = func_003824E0(0.5f, 1.0f);
        type = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        tilt = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, speed * 0.020000001415610313f, yaw, tilt);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        lifetime = func_003824E0(0.05f, 0.2f) * big;
        particle = func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, type,
            lifetime, 500.0f, 1.0f, 0.0f, 2.0f);
        i--;
        if (particle != 0) particle[2] = D_L01_00221098.owner[1];
    } while (i >= 0);
}
