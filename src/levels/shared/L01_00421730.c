#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00421730);

INCLUDE_ASM("asm/levels", func_L01_00421738);

INCLUDE_ASM("asm/levels", func_L01_004218C8);

/* localdecomp:start func_L01_00421988 */
extern s32 D_L01_001D6A08;
extern s32 D_L01_001D6A0C;
extern f32 D_L01_001D6A10;
extern s32 D_L01_001D6A14;
extern s32 D_L01_001D6A18;
extern void func_L01_00422338(void);
extern void func_L01_00421A30(void);
extern void func_L01_00436070(void *, void *, s32);
extern void func_L01_00448248(s32 *, s32, s32);

void func_L01_00421988(s32 mode, s32 a1, s32 a2, f32 f) {
    if (D_L01_001D6A08 == 0 || (D_L01_001D6A0C != 2 && mode == 2)) {
        D_L01_001D6A0C = mode;
        func_L01_00436070(func_L01_00422338, func_L01_00421A30, 1);
    }
    if (mode == D_L01_001D6A0C) {
        D_L01_001D6A14 = a1;
        D_L01_001D6A18 = a2;
        D_L01_001D6A10 = f;
        func_L01_00448248(&D_L01_001D6A08, 10, 2);
    }
}
/* localdecomp:end func_L01_00421988 */

INCLUDE_ASM("asm/levels", func_L01_00421A30);

INCLUDE_ASM("asm/levels", func_L01_00422338);

/* localdecomp:start func_L01_00422388 */
extern void func_L01_00422388(void);

extern s32 D_L01_001D6A3C;
void func_L01_00422388(void) {
    *(u8 *)&D_L01_001D6A3C = 1;
}
/* localdecomp:end func_L01_00422388 */
