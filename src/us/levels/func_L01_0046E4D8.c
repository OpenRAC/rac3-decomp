#include "common.h"

/* NTSC-U counterpart of func_L01_00471BF0 (src/levels/shared/L01_0046A938.c) */
/* localdecomp:start func_L01_0046E4D8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L01_002212B0[];
extern u8 *func_L01_0045E438(s32);
extern float func_0037E250(float, float);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern float func_0037E2A8(void);
extern float func_003BE7F0(void *, float, s32, s32);

u8 *func_L01_0046E4D8(u128_t *position, u128_t *velocity, s32 lifetime) {
    u8 *particle = func_L01_0045E438(0x66);
    u8 *motion;
    u8 *pos;
    if (particle) {
        motion = particle + 0x20;
        pos = particle + 0x10;
        particle[9] = 0x42;
        particle[3] = 0x44;
        particle[1] = 0;
        particle[2] = *D_L01_002212B0[0];
        *(float *)(particle + 0xC) = func_0037E250(0.03f, 0.175f) * 210000.0f;
        particle[8] = func_0037E1D8(255);
        *(s16 *)(particle + 0xA) = lifetime;
        *(u128_t *)pos = *position;
        *(u128_t *)motion = *velocity;
        *(float *)(motion + 0xC) = func_0037E250(4.6f, 8.6f) * 0.00027777778450399637f;
        *(float *)(motion + 0x18) = *(float *)(particle + 0xC) * 2.0f;
        *(s16 *)(motion + 0x16) = func_0037E208(0, 3);
        *(s16 *)(motion + 0x14) = lifetime / 2;
        *(float *)(motion + 0x1C) = func_0037E2A8();
        *(float *)(motion + 0x10) = func_003BE7F0(pos, 0.5f, 0, 0);
    }
    return particle;
}
/* localdecomp:end func_L01_0046E4D8 */
