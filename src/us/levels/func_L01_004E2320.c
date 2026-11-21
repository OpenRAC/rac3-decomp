#include "common.h"

/* NTSC-U counterpart of func_L01_004E60E8 (src/levels/shared/L01_004E2988.c) */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int s128 __attribute__((mode(TI)));
extern G_4DD4B0 D_001A4BE0;
extern s32 func_003883C8(void *);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern G_4DD4B0 D_001A4BE0;

/* localdecomp:start func_L01_004E2320 */
typedef struct {
    u8 p0[0x80]; s128 position; f32 rotation[4];
    u8 pA0[0x1B8-0xA0]; s32 timer;
    u8 p1BC[0x4EC-0x1BC]; s16 emit; s16 trail;
} Hero_004E60E8;
extern s16 D_001A50CE[];
void func_L01_004E2320(void) {
    extern s32 func_003883C8(void *);
    extern f32 func_L01_00440918(f32, f32);
    extern void func_L01_00463938(f32 *, f32 *, s32, f32, f32);
    extern void func_0037E4B8(f32 *, f32, f32, f32);
    extern void func_L01_00460318(f32 *, f32 *, s32, s32, s32, s32, s32, s32);
    f32 position[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    s16 *trail = D_001A50CE;
    f32 angle, radius, factor, alpha, r1, r2;
    s32 color, a, b, i;
    s32 intensity;
    if (func_003883C8(trail)) {
        Hero_004E60E8 *hero = (Hero_004E60E8 *)((u8 *)trail - 0x4EE);
        *(s128 *)position = *(s128 *)((u8 *)trail - 0x46E);
        angle = func_00389380(hero->rotation[2], 1.5707964f);
        radius = func_L01_00440918(0.0033333336f, 0.011666667f);
        velocity[0] = func_00388960(angle) * radius;
        velocity[1] = func_00388978(angle) * radius;
        velocity[2] = 0.0f;
        velocity[3] = -0.0022222223f;
        func_L01_00463938(position, velocity, 0, -1.0f, velocity[2]);
        hero->trail = func_0037E208(2, 3);
    }
    if (func_003883C8(trail - 1)) {
        s128 *origin;
        f32 *out;
        factor = (f32)(40 - *(s32 *)((u8 *)trail - 0x336)) / 40.0f;
        if (factor > 1.0f) factor = 1.0f;
        if (factor < 0.0f) factor = 0.0f;
        intensity = (s32)(factor * 240.0f);
        if (intensity > 160) intensity = 160;
        if (intensity < 32) intensity = 32;
        color = (intensity << 24) | 0xC0F0;
        origin = (s128 *)((u8 *)trail - 0x46E);
        out = velocity;
        for (i = 56; i >= 0; i--) {
            a = (s32)(func_0037E250(4200.0f, 7350.0f) / 1000.0f);
            b = (s32)(func_0037E250(21000.0f, 31500.001953125f) / 1000.0f);
            alpha = func_0037E250(0.0025000002f, 0.0095000006f);
            *(s128 *)position = *origin;
            r1 = func_0037E2A8();
            r2 = func_0037E2A8();
            func_0037E4B8(out, alpha, r1, r2);
            func_L01_00460318(position, out, color, 0x70F0, 40, a, b, 1);
        }
        ((Hero_004E60E8 *)&D_001A4BE0)->emit = func_0037E208(3, 7);
    }
}
/* localdecomp:end func_L01_004E2320 */
