#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L04_00377698);

/* localdecomp:start func_L04_003776D8 */
extern s32 D_L04_001E1AA4[];
extern s32 D_L04_001E1B44;

s32 func_L04_003776D8(s32 arg0) {
    if (arg0 != D_L04_001E1AA4[0]) {
        return 0;
    }
    return D_L04_001E1B44;
}
/* localdecomp:end func_L04_003776D8 */

/* localdecomp:start func_L04_003776F8 */
extern s32 D_L04_001E1B80[];
extern s32 D_L04_001E1B40[];
extern s32 D_L04_001E1B84[];
extern s32 D_L04_001E1B50;

void func_L04_003776F8(void) {
    D_L04_001E1B80[0] = 0;
    D_L04_001E1B40[0] = 30;
    D_L04_001E1B84[0] = 0;
    D_L04_001E1B50 = 0;
}
/* localdecomp:end func_L04_003776F8 */

/* localdecomp:start func_L04_00377720 */
typedef int u128_00376398 __attribute__((mode(TI)));

extern s32 D_L04_001E1B80[];
extern u128_00376398 D_L04_001E1B70[];
extern u128_00376398 D_L04_001E1AC0[];

s32 func_L04_00377720(u128_00376398 *out) {
    if (D_L04_001E1B80[0] != 1) {
        *out = D_L04_001E1AC0[0];
        return 0;
    }
    *out = D_L04_001E1B70[0];
    return 1;
}
/* localdecomp:end func_L04_00377720 */

/* localdecomp:start func_L04_00377760 */
extern void func_0038CF68(void *, void *, f32);
extern s32 D_L04_001E1B80[];
extern u128_00376398 D_L04_001E1B70[];
extern u128_00376398 D_L04_001E1B60[];
extern u128_00376398 D_L04_001E1AD0[];

s32 func_L04_00377760(u128_00376398 *out) {
    if (D_L04_001E1B80[0] != 1) {
        *out = D_L04_001E1AD0[0];
        return 0;
    }
    vec_sub_ab(out, D_L04_001E1B70, D_L04_001E1B60);
    func_0038CF68(out, out, 1.0f);
    return 1;
}
/* localdecomp:end func_L04_00377760 */
