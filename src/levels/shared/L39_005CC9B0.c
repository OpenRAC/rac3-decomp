#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L39_005CC9B0);

/* localdecomp:start func_L39_005CCB70 */
extern u8 *func_003CD108(s32);
extern s32 func_L39_005B4398(s32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0019D510(void);
extern u8 *D_L39_002968CC[];
u8 *func_L39_005CCB70(void *position, s32 a1, s32 color, f32 length, f32 f13) {
    u8 *particle = func_003CD108(0x2D);
    u8 *data;
    f32 angle, mag;
    s32 c;
    if (particle) {
        *(u128_t *)(particle + 0x10) = *(u128_t *)position;
        if (color == -1) {
            c = ((func_L39_005B4398(6) + 0x14) << 24) | 0x808080;
        } else {
            c = color;
        }
        *(s32 *)(particle + 4) = c;
        particle[9] = 0x21;
        data = particle + 0x20;
        particle[3] = 0x48;
        particle[1] = 1;
        particle[2] = *D_L39_002968CC[0];
        particle[8] = func_0019D510();
        *(s16 *)(particle + 0xA) = 4;
        *(f32 *)(particle + 0xC) = length * 210000.0f;
        angle = func_L39_005B44C8();
        mag = func_L39_005B4410(0.0015f, 0.0025f);
        *(f32 *)(particle + 0x20) = func_0038D098(angle) * mag;
        *(f32 *)(data + 4) = func_0038D0B0(angle) * mag;
        *(s32 *)(data + 0x14) = a1;
        *(f32 *)(data + 0x10) = f13;
        *(s32 *)(data + 8) = 0;
    }
    return particle;
}
/* localdecomp:end func_L39_005CCB70 */
