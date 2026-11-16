/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_003B7408.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Best stock checker: 32 differing instructions (third formulation).
 * Restored that loop after two alternatives regressed to 91 differences.
 * Remaining differences: final particle-call argument scheduling, loop tail,
 * and particle-field store allocation. No flags or metadata changed.
 * Uses the stock owning-file context; further tuning remains possible.
 */
#include "common.h"
typedef int Q_003B8D80 __attribute__((mode(TI)));
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
typedef struct { u8 pad[0x1F0]; u8 *p; } G_003B8D80;
extern G_003B8D80 D_L07_0021EC98;
void func_L07_003B8D80(u8 *obj)
{
    f32 position[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    f32 speed, angle, pitch, a, b, c;
    s32 i, life, color;
    G_003B8D80 *g = &D_L07_0021EC98;
    u8 *particle;
    i = 119;
    do {
        *(Q_003B8D80 *)position = *(Q_003B8D80 *)(obj + 0x10);
        func_003C4C18(position, 2.0f);
        speed = func_003824E0(0.100000009f, 0.200000018f);
        angle = func_00382538();
        pitch = func_003824E0(0.0f, 0.785398006f);
        func_00382760(velocity, speed, angle, pitch);
        func_003C4C18(velocity, 0.060000002f);
        life = func_00382498(40, 80);
        color = func_0038DBD8(0x808080, 0xFFFFFF, func_003824E0(0.0f, 1.0f));
        a = func_003824E0(210000.0f, 315000.0f);
        b = func_003824E0(630000.0f, 1050000.0f);
        c = func_003824E0(0.002f, 0.004f);
        particle = func_L01_0046FB40(position, velocity, life, color,
            func_00382468(2) ? 3 : -3, 96, 0, 0, a, b, c);
        if (particle) {
            u8 shade = g->p[1];
            particle[3] = 0x44;
            particle[2] = shade;
        }
    } while (i--);
}
