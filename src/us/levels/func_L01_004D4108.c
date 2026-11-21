#include "common.h"

/* NTSC-U counterpart of func_L01_004D7DC8 (src/levels/shared/L01_004D7DC8.c) */
/* localdecomp:start func_L01_004D4108 */
extern s32 D_L01_001DFBC0_004D4108;
extern float func_00388978(float);
extern s32 func_003894A0(s32, s32, float);

void func_L01_004D4108(u8 *m, s32 blue, s32 green, s32 red, s32 alpha, s32 ba, s32 ga, s32 ra, s32 period) {
    float phase;
    float wave;

    phase = (float)(D_L01_001DFBC0_004D4108 % period) / (float)period;
    wave = func_00388978((phase + phase) * 3.1415927f + (-3.1415927f));
    red += (s32)(wave * (float)ra) + ra / 2;
    green += (s32)(wave * (float)ga) + ga / 2;
    blue += (s32)(wave * (float)ba) + ba / 2;
    *(s32 *)(m + 0x78) = func_003894A0(*(s32 *)(m + 0x78), (alpha << 24) | (red << 16) | (green << 8) | blue, 0.05f);
}
/* localdecomp:end func_L01_004D4108 */
