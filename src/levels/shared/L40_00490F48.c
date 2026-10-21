#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00490F48);

/* localdecomp:start func_L40_004910D0 */
extern s32 D_L40_001D7C70;
extern s32 D_L40_001D7C74;
extern s32 D_L40_001D7C78;
extern void func_L01_00423020(void *, s32);
extern void func_L40_00491130(void);
extern void func_L40_00491270(void);
extern void func_L40_004913B8(void);

void func_L40_004910D0(void) {
    if (D_L40_001D7C70 != 0) {
        func_L01_00423020(func_L40_00491130, 0);
    }
    if (D_L40_001D7C74 != 0) {
        func_L01_00423020(func_L40_00491270, 0);
    }
    if (D_L40_001D7C78 != 0) {
        func_L01_00423020(func_L40_004913B8, 0);
    }
}
/* localdecomp:end func_L40_004910D0 */

INCLUDE_ASM("asm/levels", func_L40_00491130);

INCLUDE_ASM("asm/levels", func_L40_00491270);

INCLUDE_ASM("asm/levels", func_L40_004913B8);
