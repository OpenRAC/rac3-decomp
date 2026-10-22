#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003FE908);

INCLUDE_ASM("asm/levels", func_L01_003FE938);

INCLUDE_ASM("asm/levels", func_L01_003FEA00);

INCLUDE_ASM("asm/levels", func_L01_003FEA68);

INCLUDE_ASM("asm/levels", func_L01_003FF240);

INCLUDE_ASM("asm/levels", func_L01_003FF4E8);

INCLUDE_ASM("asm/levels", func_L01_003FF570);

INCLUDE_ASM("asm/levels", func_L01_003FF9F0);

INCLUDE_ASM("asm/levels", func_L01_003FFC88);

INCLUDE_ASM("asm/levels", func_L01_003FFED0);

INCLUDE_ASM("asm/levels", func_L01_004000C0);

INCLUDE_ASM("asm/levels", func_L01_00400100);

INCLUDE_ASM("asm/levels", func_L01_00400160);

/* localdecomp:start func_L01_004001C8 */
void func_0038CAD0(void *);
extern u8 D_L01_001E64EC[];

void func_L01_004001C8(void) {
    func_0038CAD0(D_L01_001E64EC);
}
/* localdecomp:end func_L01_004001C8 */

INCLUDE_ASM("asm/levels", func_L01_004001E8);

INCLUDE_ASM("asm/levels", func_L01_00400280);

INCLUDE_ASM("asm/levels", func_L01_00400368);

INCLUDE_ASM("asm/levels", func_L01_00400390);

/* localdecomp:start func_L01_00400430 */
extern u8 D_00142692[];
extern s32 D_001D545C;
extern s32 func_L01_00400390(s32 a0, s32 a1);
s32 func_L01_00400430(s32 a0) {
    u8 s = D_00142692[0];
    s32 v;
    if (s != 0) {
        return 3;
    }
    v = 3 - func_L01_00400390(D_001D545C, a0) / 100;
    if (s < v) {
        return v;
    }
    return 1;
}
/* localdecomp:end func_L01_00400430 */

INCLUDE_ASM("asm/levels", func_L01_00400490);

INCLUDE_ASM("asm/levels", func_L01_004004F8);

INCLUDE_ASM("asm/levels", func_L01_004006C8);
