#include "common.h"


/* localdecomp:start func_L01_00425218 */
/* sweep3 base */
typedef int u128 __attribute__((mode(TI)));
__asm__(".extern D_L01_GP_3650, 4");
extern u128 D_L01_001DFEC0;
extern u128 D_L01_001DFED0;
extern u128 D_L01_001DFEE0;
extern u128 D_L01_001DFEF0;
extern s32 D_L01_GP_3650;

void func_L01_00425218(u128 *p) {
    u128 a;
    u128 b;
    u128 c;
    u128 d;
    a = p[0];
    p = p + 1;
    D_L01_001DFEC0 = a;
    b = p[0];
    p = p + 1;
    D_L01_001DFED0 = b;
    c = p[0];
    p = p + 1;
    D_L01_001DFEE0 = c;
    d = p[0];
    p = p + 1;
    D_L01_001DFEF0 = d;
    D_L01_GP_3650 = (s32)p;
}
/* localdecomp:end func_L01_00425218 */
