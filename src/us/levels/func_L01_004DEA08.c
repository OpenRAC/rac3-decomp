#include "common.h"

/* NTSC-U counterpart of func_L01_004E27A8 (src/levels/shared/L01_004E27A8.c) */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
extern G_4DD4B0 D_001A4BE0;
extern s32 D_L01_001DFBC0_004DEA08;
extern f32 func_00388978(f32);

/* localdecomp:start func_L01_004DEA08 */
typedef struct { u8 pad[0x20E]; s16 mode; } Hero_004E27A8;
extern s32 func_003894A0(s32, s32, f32);

/* pulses the moby colour: each channel waves by its amplitude around base + amplitude / 2, over a
   period of frames * 5 / 6 (PAL), then fades the moby's colour (0x78) toward it */
void func_L01_004DEA08(u8 *obj, s32 red, s32 green, s32 blue, s32 alpha, s32 wave_r, s32 wave_g,
                       s32 wave_b, s32 frames) {
    s32 period;
    f32 s;
    f32 speed;
    s32 color;

    period = frames;
    s = func_00388978((f32)(D_L01_001DFBC0_004DEA08 % period) / (f32)period * 2.0f * 3.14159274f + -3.14159274f);
    blue += (s32)(s * wave_b) + wave_b / 2;
    green += (s32)(s * wave_g) + wave_g / 2;
    red += (s32)(s * wave_r) + wave_r / 2;
    if (blue > 255) blue = 255;
    if (green > 255) green = 255;
    if (red > 255) red = 255;
    color = (alpha << 24) | (blue << 16) | (green << 8) | red;
    speed = 0.07f;
    if ((*(Hero_004E27A8 *)&D_001A4BE0).mode) speed = 0.037f;
    *(s32 *)(obj + 0x78) = func_003894A0(*(s32 *)(obj + 0x78), color, speed);
}
/* localdecomp:end func_L01_004DEA08 */
