#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003CB5A8);

INCLUDE_ASM("asm/levels", func_L24_003CB7C0);

INCLUDE_ASM("asm/levels", func_L24_003CB900);

INCLUDE_ASM("asm/levels", func_L24_003CB990);

INCLUDE_ASM("asm/levels", func_L24_003CBA10);

/* localdecomp:start func_L24_003CBDC8 */
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(s32);
extern f32 func_0038CF00(void *, void *);
extern f32 D_1A4C60[];

void func_L24_003CBDC8(u8 *a0) {
    s32 *q = *(s32 **)(a0 + 0x68);
    s32 *g;

    if (a0[0x20] == 0) {
        if (func_L01_00456250(a0) > 0) {
            func_003C2880((s32)a0);
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
    } else {
        if (func_L01_00456250(a0) > 0) {
            func_0038CF00(a0 + 0x10, D_1A4C60);
            g = (s32 *)0x140000;
            g[0x998] = g[0x998] + *q;
            func_003C2880((s32)a0);
        }
    }
}
/* localdecomp:end func_L24_003CBDC8 */

INCLUDE_ASM("asm/levels", func_L24_003CBE68);

INCLUDE_ASM("asm/levels", func_L24_003CC248);
