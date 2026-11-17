#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_0055AF88 */
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(f32 *, f32, f32, f32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);
void func_L39_0055AF88(f32 *position, s32 count) {
    f32 dir[4];
    f32 save[4];
    f32 f20;
    f32 f21;
    f32 f22;
    s32 sign;
    s32 i;

    if (count > 0) {
        i = count;
        do {
            f22 = func_L39_005B4410(0.1f, 2.0f);
            sign = func_L39_005B4398(2);
            if (sign == 0)
                sign = sign - 1;
            f21 = func_L39_005B44C8();
            f20 = func_L39_005B4410(0.34906584f, 1.53588974f);
            func_00382760(dir, func_L39_005B4410(0.05f, 0.1f), f21, f20);
            *(u128_t *)save = *(u128_t *)position;
            position[0] = position[0] + func_L39_005B4468(0.0f, 0.15f);
            position[1] = position[1] + func_L39_005B4468(0.0f, 0.15f);
            position[2] = position[2] + func_L39_005B4468(0.0f, 0.15f);
            func_L01_0046B458(position, 0x19, 0x7F207F7F, 0, sign, dir, f22 * 0.1f, f22, 0.003f, 0);
            func_L01_0046B458(position, 0x19, 0x7F7F7F7F, 1, -sign, dir, f22 * 0.07f, f22 * 0.7f, 0.003f, 0);
        } while (--i != 0);
    }
}
/* localdecomp:end func_L39_0055AF88 */
