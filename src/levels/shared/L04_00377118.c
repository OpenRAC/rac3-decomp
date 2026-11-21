#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00377118 */
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
    vec_add_ab(p, p, D_L04_001E1AC0);
    *out = D_L04_001E1AC0[1];
    return 1;
}
/* localdecomp:end func_L04_00377118 */
