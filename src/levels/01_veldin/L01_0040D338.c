#include "common.h"

typedef struct {
    u8 pad0[0x140];
    f32 position[4];
} Globals_0040D510;

/* localdecomp:start func_L01_0040D338 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern s32 D_001DFB40;
extern void func_L01_003303B8(V4 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00443948(s32 a);
extern f32 func_004439C0(f32 a, f32 b);
extern void func_0043A778(void *a, s32 b, V4 *c);
extern void func_L01_0040D510(char *object, int joint, float radius);
extern void func_L01_0040D790(u8 *object, s32 joint, f32 radius);

void func_L01_0040D338(void *o, s32 n, s32 *arr, f32 sc) {
    V4 v;
    s32 i;
    if (n > 0) {
    for (i = 0; i < n; i++) {
        if (func_00443948(2) != 0) {
            func_L01_0040D510(o, arr[i], func_004439C0(0.5f, 0.89999998f) * sc);
            func_L01_0040D790(o, arr[i], func_004439C0(0.5f, 0.69999999f) * sc);
        }
    }
    if (D_001DFB40 % 80 == 0) {
        func_0043A778(o, arr[func_00443948(n)], &v);
        func_L01_003303B8(&v, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    }
}
/* localdecomp:end func_L01_0040D338 */

/* localdecomp:start func_L01_0040D510 */
extern Globals_0040D510 D_L01_001E2880;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern s32 func_00382498(s32, s32);

void func_L01_0040D510(char *object, int joint, float radius) {
    float initial[4], point[4], velocity[4];
    float heading, speed, tilt, yaw;
    u8 *particle;
    u8 *data;

    func_003C2F58(object, joint, initial);
    heading = func_0038D160(D_L01_001E2880.position[0] - *(f32 *)(object + 0x10),
                            D_L01_001E2880.position[1] - *(f32 *)(object + 0x14));
    point[0] = initial[0] + func_L01_00443A18(0, radius);
    point[1] = initial[1] + func_L01_00443A18(0, radius);
    point[2] = initial[2] + func_L01_00443A18(0, radius);
    speed = func_003824E0(radius * 0.5f * 0.020000001f, radius * 1.3f * 0.020000001f);
    tilt = func_L01_00443A18(0.6981317f, 0.87266463f);
    yaw = func_0038DAB8(heading, func_L01_00443A18(0, 1.5707964f));
    func_00382760(velocity, speed, yaw, tilt);
    velocity[2] += func_003824E0(0.9f, 1.7f) * 0.020000001f;
    particle = func_L01_004669B0(0, 1.0f, 1.01f, radius * 1.4f * 210000.0f,
                                 point, -1, velocity, 0x101010, 0);
    if (particle != 0) {
        particle[3] = 0x44;
        *(s16 *)(particle + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
        particle[9] = 100;
        data = particle + 0x20;
        *(f32 *)(data + 0x1C) = (func_00382498(1, 10) * 5 + 2) / 6;
        *(s32 *)(data + 4) = 3;
        data[0xA] = 0x7F;
        data[0xB] = particle[0xA];
    }
}
/* localdecomp:end func_L01_0040D510 */

/* localdecomp:start func_L01_0040D790 */
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern s32 func_00382498(s32, s32);

void func_L01_0040D790(u8 *object, s32 joint, f32 radius) {
    f32 initial[4], point[4], velocity[4];
    f32 heading, speed, tilt, yaw;
    u8 *particle;
    u8 *data;

    func_003C2F58(object, joint, initial);
    heading = func_0038D160(D_L01_001E2880.position[0] - *(f32 *)(object + 0x10),
                            D_L01_001E2880.position[1] - *(f32 *)(object + 0x14));
    point[0] = initial[0] + func_L01_00443A18(0, radius);
    point[1] = initial[1] + func_L01_00443A18(0, radius);
    point[2] = initial[2] + func_L01_00443A18(0, radius);
    speed = func_003824E0(radius * 0.5f * 0.02000000141561031f, radius * 0.02000000141561031f);
    tilt = func_L01_00443A18(0, 1.3962633609771729f);
    yaw = func_0038DAB8(heading, func_L01_00443A18(0, 1.5707963705062866f));
    func_00382760(velocity, speed, yaw, tilt);
    velocity[2] += func_003824E0(0.7f, 1.2f) * 0.02000000141561031f;
    particle = func_L01_004669B0(0, 1.0f, 1.01f, radius * 210000.0f,
                                 point, -1, velocity, 0x3582B5BD, 0);
    if (particle != 0) {
        particle[3] = 0x48;
        *(s16 *)(particle + 0xA) = (func_00382498(0x46, 0x82) * 5 + 2) / 6;
        particle[9] = 100;
        data = particle + 0x20;
        *(f32 *)(data + 0x1C) = (func_00382498(1, 10) * 5 + 2) / 6;
        *(s32 *)(data + 4) = 3;
        data[0xA] = 0x7F;
        data[0xB] = particle[0xA];
    }
}
/* localdecomp:end func_L01_0040D790 */
