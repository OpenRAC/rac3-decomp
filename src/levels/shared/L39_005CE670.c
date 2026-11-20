#include "common.h"

/* localdecomp:start func_L39_005CE670 */
/* from rac2-decomp's func_L00_0033AA40 */
typedef int u128_t_005CE670 __attribute__((mode(TI)));

extern u8 *func_003CD108(s32);
extern f32 func_L39_005B4410(f32, f32);
extern u8 *D_L39_00296918_005CE670[];

void *func_L39_005CE670(void *position, void *velocity, s32 size, f32 life, f32 a, f32 b, u32 color, u32 value,
                      s32 flag) {
    u8 *particle = func_003CD108(0x40);
    f32 *out;

    if (particle) {
        *(u128_t_005CE670 *)(particle + 0x10) = *(u128_t_005CE670 *)position;
        particle[9] = 0x21;
        out = (f32 *)(particle + 0x20);
        particle[3] = flag ? 0x48 : 0x44;
        particle[1] = 0;
        particle[2] = D_L39_00296918_005CE670[0][1];
        *(u32 *)(particle + 4) = color;
        *(f32 *)(particle + 0xC) = life * 210000.0f;
        {
            f32 random = func_L39_005B4410(0.0f, 255.0f);

            *(s16 *)(particle + 0xA) = size;
            particle[8] = (s32)random;
        }
        *(u128_t_005CE670 *)out = *(u128_t_005CE670 *)velocity;
        *(u32 *)(out + 6) = value;
        out[4] = a;
        do { out[5] = b; } while (0);
    }
    return particle;
}
/* localdecomp:end func_L39_005CE670 */
