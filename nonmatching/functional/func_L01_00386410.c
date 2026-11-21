/* functional: high. 237 diff but 19 jals identical; I traced every constant, argument order and branch against the asm by hand; differences are reg alloc, repeated address materialisation (retail rebuilds D_001D66B0 for each call), frame size 0x90 vs 0xa0; VU0 via inline asm */
#include "common.h"
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 *D_L01_00221204[];
extern u8 D_L01_001D66B0[];
void func_L01_00386410(u8 *self, vu0_v4 *position, void *unused, s32 small) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004708C8(void *, void *, u32, u32, s32, s32, s32, s32, s32, f32, f32);
    extern u8 *func_L01_00470C78(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    vu0_v4 velocity, delta, spawn;
    u8 *vars = *(u8 **)(self + 0x68);
    u8 *p;
    u8 *particle;
    f32 angle, random, size, speed;
    s32 life;
    if (*(s32 *)(vars + 0x3C) < 2) {
        angle = func_003824E0(-0.9599310755729675f, -1.3962633609771729f);
        random = func_00382538();
        speed = func_003824E0(0.0f, 0.5f) * 0.020000001415610313f;
        func_00382760(&velocity, speed, random, angle);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(delta) : "m"(*position), "m"(D_L01_001E29C0) : "vf1", "vf2");
        func_0038CF68(&delta, &delta, 0.15f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*position) : "m"(delta), "m"(*position) : "vf1", "vf2");
        size = func_003824E0(50000.0f, 80000.0f);
        spawn.x = position->x + func_L01_00443A18(0.0f, 0.175f);
        spawn.y = position->y + func_L01_00443A18(0.0f, 0.175f);
        spawn.z = position->z + func_L01_00443A18(0.0f, 0.175f);
        if (small) life = func_00382498(8, 17);
        else life = func_00382498(21, 50);
        p = func_L01_004708C8(&spawn, &velocity, 0x4F5050FF, 0x102434EE, life, 1, -1, -1, 1, size, 0.5f);
        if (p) p[2] = *D_L01_00221204[0];
    }
    func_L01_00470C78(position, 33, 0x64FFFFFF, 2, 4, D_L01_001D66B0, 0, 1, 6, 1, 0.1f, 1.05f);
    func_L01_00470C78(position, 25, 0x3C3882F7, 2, 0, D_L01_001D66B0, 0, 0, 6, 1, 0.4f, 2.05f);
    func_L01_00470C78(position, 33, 0x323882F7, 0, 2, D_L01_001D66B0, 0, 4, 6, 1, 0.15f, 1.65f);
    func_L01_00470C78(position, 22, 0x3C0045F7, 2, 0, D_L01_001D66B0, 3, 0, 6, 1, 0.5f, 2.35f);
    func_L01_00470C78(position, 22, 0x1E0045F7, 1, -2, D_L01_001D66B0, 3, 4, 6, 1, 0.3f, 1.75f);
    if (*(s32 *)(vars + 0x3C) < 2) {
        particle = func_L01_00470C78(position, 8, 0x80141414, 2, 2, D_L01_001D66B0, 0, 2, 6, 1, 0.9f, 0.7f);
        if (particle) particle[3] = 0x44;
        particle = func_L01_00470C78(position, 8, 0x80141414, 2, -1, D_L01_001D66B0, 1, 2, 6, 1, 1.7f, 0.7f);
        if (particle) particle[3] = 0x44;
        particle = func_L01_00470C78(position, 8, 0x64141414, 2, 1, D_L01_001D66B0, 1, 2, 6, 1, 2.0f, 1.5f);
        if (particle) particle[3] = 0x44;
    }
}
