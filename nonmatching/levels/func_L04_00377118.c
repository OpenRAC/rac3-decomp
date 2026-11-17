/* func_L04_00377118: near miss, 30 diff with -mvu0-use-vf0-vf2 -mno-split-addresses @ps2as (file L04_00377118.c needs them). gcc keeps D_L04_001E1AD0's address in a saved register across the func_0038CE20 call (one extra saved register); retail rematerializes it with lui/addiu at each use. Result-variable and early-return forms give the same. */
#include "common.h"
#include "vu0.h"
typedef int u128_00377118 __attribute__((mode(TI)));
extern s32 func_L01_00366FC8(void);
extern void func_0038CE20(void *, void *, f32);
extern u128_00377118 D_L04_001E1AD0[];
extern u128_00377118 D_L04_001E1AC0[];

s32 func_L04_00377118(u128_00377118 *p, u128_00377118 *out) {
    if (func_L01_00366FC8() == 0) {
        return 0;
    }
    func_0038CE20(p, D_L04_001E1AD0, 0.200000003f);
    vec_add_ba(p, p, D_L04_001E1AC0);
    *out = D_L04_001E1AD0[0];
    return 1;
}
