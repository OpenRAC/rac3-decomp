#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00637D38);

INCLUDE_ASM("asm/levels", func_L39_00637E10);

INCLUDE_ASM("asm/levels", func_L39_00637EC8);

INCLUDE_ASM("asm/levels", func_L39_00638458);

/* localdecomp:start func_L39_006384B0 */
typedef struct {
    char _p0[0xFB0];
    s32 fFB0;
    s32 fFB4;
} S1_006384B0;

/* from rac4-decomp's func_00162968 */
void func_L39_006384B0(S1_006384B0 *arg0) {
    arg0->fFB0 = 0;
    arg0->fFB4 = 0;
}
/* localdecomp:end func_L39_006384B0 */

INCLUDE_ASM("asm/levels", func_L39_006384C0);

/* localdecomp:start func_L39_006387D0 */
extern void func_0038CE20(void *, void *, f32);

void func_L39_006387D0(u8 *a0, f32 s) {
    func_0038CE20(a0 + 320, a0 + 320, s);
    func_0038CE20(a0 + 336, a0 + 336, s);
    func_0038CE20(a0 + 288, a0 + 288, s);
    func_0038CE20(a0 + 400, a0 + 400, s);
    *(f32 *)(a0 + 4020) *= s;
}
/* localdecomp:end func_L39_006387D0 */

INCLUDE_ASM("asm/levels", func_L39_00638848);

INCLUDE_ASM("asm/levels", func_L39_00638C28);

INCLUDE_ASM("asm/levels", func_L39_00638DF0);

INCLUDE_ASM("asm/levels", func_L39_00638F50);

INCLUDE_ASM("asm/levels", func_L39_006390D0);
