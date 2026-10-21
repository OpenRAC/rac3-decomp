#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00359058);

/* localdecomp:start func_L30_003593A0 */
extern s32 D_00142BC0[];
extern u8 D_L30_001E8DC0[];
extern void func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
void func_L30_003593A0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    unsigned long t;
    *(s32 *)(s1 + 164) = 0;
    t = D_00142BC0[0];
    if (!((t >> 1) & 1)) {
        func_00392B20(D_L30_001E8DC0, 33);
        func_00392C78(D_L30_001E8DC0);
        *(s32 *)(s1 + 212) = 1;
    }
}
/* localdecomp:end func_L30_003593A0 */
