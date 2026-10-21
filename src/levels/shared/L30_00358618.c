#include "common.h"

/* localdecomp:start func_L30_00358618 */
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001426E0[];
void func_L30_00358618(void *a0) {
    u8 *p = D_001426E0;
    if (p[82] == 1) {
        func_L01_004450F0(a0, 5, -1);
    }
    if (p[82] == 2) {
        func_L01_004450F0(a0, 4, -1);
    }
    if (p[82] == 3) {
        func_L01_004450F0(a0, 2, -1);
    }
    p[82] = 0;
}
/* localdecomp:end func_L30_00358618 */

INCLUDE_ASM("asm/levels", func_L30_003586A8);

INCLUDE_ASM("asm/levels", func_L30_00358A18);

INCLUDE_ASM("asm/levels", func_L30_00358DA8);
