#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00343398);

INCLUDE_ASM("asm/levels", func_L30_003434E8);

/* localdecomp:start func_L30_003435C0 */
extern u8 D_001A4C60[];

extern f32 func_0038CF00(void *, void *);
extern void func_L30_003434E8(u8 *);

void func_L30_003435C0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    int saved;
    f32 d;
    if (vars[439]) {
        saved = *(int *)(vars + 404);
    }
    d = func_0038CF00(D_001A4C60, vars + 320);
    *(int *)(vars + 404) = func_0038CF00(D_001A4C60, vars + 336) < d;
    func_L30_003434E8(moby);
    if (vars[439]) {
        *(int *)(vars + 404) = saved;
    }
}
/* localdecomp:end func_L30_003435C0 */

INCLUDE_ASM("asm/levels", func_L30_00343660);

INCLUDE_ASM("asm/levels", func_L30_00343798);

INCLUDE_ASM("asm/levels", func_L30_00343830);

INCLUDE_ASM("asm/levels", func_L30_00343AC8);

INCLUDE_ASM("asm/levels", func_L30_00343CD0);
