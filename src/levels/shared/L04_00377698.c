#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_00377698);

INCLUDE_ASM("asm/levels", func_L04_003776D8);

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

INCLUDE_ASM("asm/levels", func_L04_00377760);
