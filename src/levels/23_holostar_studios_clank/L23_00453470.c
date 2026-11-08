#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L23_00453470 */
extern u8 *func_L01_004618E0(s32);
extern float func_003824E0(float, float);
extern u8 *D_L23_0021EEE8[];
u8 *func_L23_00453470(void *position, void *velocity, s32 word, s32 color, s32 index, float lifetime, float scale, float size) {
    u8 *particle = func_L01_004618E0(0x32);
    u8 *data;
    if (particle) {
        data = particle + 0x20;
        *(u128_t *)(particle + 0x10) = *(u128_t *)position;
        particle[9] = 0x41;
        particle[3] = 0x44;
        particle[1] = 0;
        particle[2] = D_L23_0021EEE8[0][index];
        *(s32 *)(particle + 4) = color;
        *(float *)(particle + 0xC) = lifetime * 210000.0f;
        particle[8] = (s32)func_003824E0(0.0f, 255.0f);
        *(s16 *)(particle + 0xA) = 12;
        *(u128_t *)data = *(u128_t *)velocity;
        *(s32 *)(data + 0x1C) = word;
        *(float *)(data + 0x10) = scale;
        *(s32 *)(data + 0x14) = (s32)func_003824E0(-3.0f, 3.0f);
        *(float *)(data + 0x18) = size;
    }
    return particle;
}
/* localdecomp:end func_L23_00453470 */
