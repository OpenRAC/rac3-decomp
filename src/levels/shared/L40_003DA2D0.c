#include "common.h"

/* localdecomp:start func_L40_003DA2D0 */
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L40_00249650[8];
extern u8 D_L40_00249690[8];

void func_L40_003DA2D0(void)
{
    u8 *p = D_L40_00249650;
    u8 *q = D_L40_00249690;
    s32 i;

    for (i = 3; i >= 0; i--) {
        func_0038D890(p, p, q, 0.0698131695f);
        q += 0x10;
        func_0038CF68(p, p, 0.25f);
        p += 0x10;
    }
}
/* localdecomp:end func_L40_003DA2D0 */

/* localdecomp:start func_L40_003DA350 */
typedef int u128_t_003DA350 __attribute__((mode(TI)));
typedef union {
    u128_t_003DA350 q;
    f32 f[4];
} V_003DA350;
extern s32 func_L39_005BE900(void *, s32, f32);

s32 func_L40_003DA350(V_003DA350 *a0) {
    V_003DA350 v;
    s32 r;

    v.q = a0->q;
    v.f[3] = 1.0f;
    r = ((s32 (*)(void *, s32))func_L39_005BE900)(&v, 0);
    if (~r < 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_003DA350 */

INCLUDE_ASM("asm/levels", func_L40_003DA390);
