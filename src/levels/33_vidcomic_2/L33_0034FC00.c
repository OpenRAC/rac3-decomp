#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L33_0034FC00);

INCLUDE_ASM("asm/levels", func_L33_0034FEE8);

INCLUDE_ASM("asm/levels", func_L33_00350188);

INCLUDE_ASM("asm/levels", func_L33_00350378);

INCLUDE_ASM("asm/levels", func_L33_00350470);

INCLUDE_ASM("asm/levels", func_L33_003505D8);

INCLUDE_ASM("asm/levels", func_L33_00350818);

INCLUDE_ASM("asm/levels", func_L33_003523C0);

INCLUDE_ASM("asm/levels", func_L33_00352760);

INCLUDE_ASM("asm/levels", func_L33_003527C0);

INCLUDE_ASM("asm/levels", func_L33_00352908);

INCLUDE_ASM("asm/levels", func_L33_00352A08);

INCLUDE_ASM("asm/levels", func_L33_00352E08);

INCLUDE_ASM("asm/levels", func_L33_00352ED0);

INCLUDE_ASM("asm/levels", func_L33_003532D8);

/* localdecomp:start func_L33_003534E0 */
extern f32 func_0038DB00(f32 a, f32 b);
extern f32 D_L33_001DD97C;
__asm__(".extern D_L33_001DD97C, 4");
extern f32 D_L33_001DD980;
__asm__(".extern D_L33_001DD980, 4");

s32 func_L33_003534E0(u8 *p) {
    f32 a = fabs_asm(func_0038DB00(*(f32 *)(p + 0xF8), D_L33_001DD97C));
    f32 b = fabs_asm(func_0038DB00(D_L33_001DD980, *(f32 *)(p + 0xF8)));
    return a < b;
}
/* localdecomp:end func_L33_003534E0 */

INCLUDE_ASM("asm/levels", func_L33_00353540);

INCLUDE_ASM("asm/levels", func_L33_00353800);

INCLUDE_ASM("asm/levels", func_L33_00353970);

INCLUDE_ASM("asm/levels", func_L33_00353EF0);
