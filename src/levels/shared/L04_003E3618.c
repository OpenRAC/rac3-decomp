#include "common.h"

/* localdecomp:start func_L04_003E3618 */
extern void func_L01_00443B88(f32, f32, f32 *);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(u8 *pos, s32 id, s32 color, s32 mode, s32 b, f32 *v, s32 n, f32 sx, f32 sy, f32 z);

void func_L04_003E3618(u8 *p) {
    f32 v[3];
    s32 i;
    s32 b;

    i = 2;
    do {
        func_L01_00443B88(0.0400000028f, 0.0800000057f, v);
        i--;
        b = func_00382498(-120, 120);
        func_L01_0046B458(p + 16, 17, 0xFF4265FE, 0, b, v, 0, 1.0f, 0.1f, 0.0f);
    } while (i >= 0);
}
/* localdecomp:end func_L04_003E3618 */
