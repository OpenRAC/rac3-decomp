#include "common.h"

/* NTSC-U counterpart of func_L39_005D2930 (src/levels/shared/L39_005D2930.c) */
/* localdecomp:start func_L39_005D04C0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L39_00296AA4[];
extern u8 *func_003C7B98(s32);
extern float func_L39_005B2510(float, float);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern float func_L39_005B25C8_005D04C0(void);

u8 *func_L39_005D04C0(u128_t *position, u128_t *velocity, s32 lifetime) {
    u8 *particle = func_003C7B98(0x63);
    u8 *motion;
    if (particle) {
        motion = particle + 0x20;
        particle[9] = 0x42;
        particle[3] = 0x44;
        particle[1] = 0;
        particle[2] = *D_L39_00296AA4[0];
        *(float *)(particle + 0xC) = func_L39_005B2510(0.05f, 0.2f) * 210000.0f;
        particle[8] = func_L39_005B2498(255);
        *(s16 *)(particle + 0xA) = lifetime;
        *(u128_t *)(particle + 0x10) = *position;
        *(u128_t *)motion = *velocity;
        *(float *)(motion + 0xC) = func_L39_005B2510(0.6f, 2.6f) * 0.00027777778450399637f;
        *(float *)(motion + 0x18) = *(float *)(particle + 0xC) * 2.0f;
        *(s16 *)(motion + 0x16) = func_L39_005B24C8(0, 3);
        *(s16 *)(motion + 0x14) = lifetime / 2;
        *(float *)(motion + 0x1C) = func_L39_005B25C8_005D04C0();
    }
    return particle;
}
/* localdecomp:end func_L39_005D04C0 */
