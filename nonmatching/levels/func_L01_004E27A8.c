/* PAL near miss (Codex wave 10): near miss: 37 words differ with the file's flags.
 * Worker's note: 37 diff c02.log (35 with sq-ra c03.log): fixed fopt-stack produces sd/ld saves and 0x50 frame versus retail sq/lq 0x90; arithmetic scheduling also differs; three C forms same bytes
 */
#include "common.h"
/* localdecomp:start func_L01_004E27A8 */
extern s32 D_L01_001DFB40;
extern s16 D_001A4DEE;
void func_L01_004E27A8(u8 *obj, s32 red, s32 green, s32 blue, s32 alpha,
                       s32 red_amp, s32 green_amp, s32 blue_amp, s32 period) {
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    s32 ticks = (period * 5 + 2) / 6;
    f32 phase = (f32)(D_L01_001DFB40 % ticks) / (f32)ticks;
    f32 wave = func_0038D0B0(phase * 2.0f * 3.14159274f + -3.14159274f);
    f32 rate;
    u32 color;
    blue += (s32)(wave * (f32)blue_amp) + blue_amp / 2;
    green += (s32)(wave * (f32)green_amp) + green_amp / 2;
    red += (s32)(wave * (f32)red_amp) + red_amp / 2;
    if (blue > 255) blue = 255;
    if (green > 255) green = 255;
    if (red > 255) red = 255;
    color = (alpha << 24) | (blue << 16) | (green << 8) | red;
    rate = 0.07f;
    if (D_001A4DEE) rate = 0.037f;
    *(u32 *)(obj + 0x78) = func_0038DBD8(*(u32 *)(obj + 0x78), color, rate * 1.2f);
}
/* localdecomp:end func_L01_004E27A8 */
