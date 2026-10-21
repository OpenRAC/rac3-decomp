#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003DCBF0);

INCLUDE_ASM("asm/levels", func_L05_003DCD10);

INCLUDE_ASM("asm/levels", func_L05_003DCF78);

/* localdecomp:start func_L05_003DD1E0 */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_0038CAD0(u8 *);
extern void func_L05_003DCF78(u8 *);
void func_L05_003DD1E0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (func_L01_004561B8(a0)) {
        *(s32 *)(p + 4) = 10;
    }
    if (func_0038CAD0(p) && a0[49] && *(s32 *)(p + 4) > 0) {
        func_L05_003DCF78(a0);
    }
}
/* localdecomp:end func_L05_003DD1E0 */
