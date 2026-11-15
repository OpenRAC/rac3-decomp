#include "common.h"

/* localdecomp:start func_L39_00528BF0 */
typedef int u128_t_00528BF0 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V_00528BF0;

extern s32 func_L39_005BE900(void *, void *, f32);
/* argument order as func_L01_0044AF78 in L24_0034F040.c: the floats come before the integers */
extern void func_L39_005B8978(u8 *, s32, s32 *, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L39_00528BF0(u8 *a0, s32 a1, s32 *a2, f32 x, f32 y) {
    V_00528BF0 v;
    V_00528BF0 out;
    s32 *p;
    s32 a3;
    s32 t0;
    s32 t1;

    p = (s32 *)(a0 + 0x10);
    if (a2 != 0) {
        p = a2;
    }
    *(u128_t_00528BF0 *)&v = *(u128_t_00528BF0 *)p;
    v.w = x;
    if (func_L39_005BE900(&v, &out, 128.0f) >= 0) {
        a3 = 10;
        t0 = 3;
        t1 = 9;
        if (out.x > 64.0f) {
            a3 = 0;
            t0 = 1;
            t1 = 1;
        } else if (out.x > 32.0f) {
            a3 = 5;
            t1 = 1;
        }
        func_L39_005B8978(a0, a1, p, x, y, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, a3, t0, t1, 0, 1, 1, -1, 0, 0x1010001);
    }
}
/* localdecomp:end func_L39_00528BF0 */
