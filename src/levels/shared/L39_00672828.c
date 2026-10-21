#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00672828);

INCLUDE_ASM("asm/levels", func_L39_00672898);

INCLUDE_ASM("asm/levels", func_L39_00672930);

INCLUDE_ASM("asm/levels", func_L39_006729B0);

/* localdecomp:start func_L39_00672C00 */
void func_L39_00672C00(u8 *a0, s32 a1) {
    s32 i;
    s32 c = 255;
    *(s32 *)(a0 + 872) = a1;
    for (i = 9; i >= 0; i--) a0[66 + i * 80] = c;
    *(s16 *)(a0 + 876) = 0;
}
/* localdecomp:end func_L39_00672C00 */

INCLUDE_ASM("asm/levels", func_L39_00672C30);

INCLUDE_ASM("asm/levels", func_L39_00672DD8);

INCLUDE_ASM("asm/levels", func_L39_00673160);

INCLUDE_ASM("asm/levels", func_L39_006732D0);

INCLUDE_ASM("asm/levels", func_L39_00673498);

INCLUDE_ASM("asm/levels", func_L39_00673540);

INCLUDE_ASM("asm/levels", func_L39_00673A80);

INCLUDE_ASM("asm/levels", func_L39_00673B68);

INCLUDE_ASM("asm/levels", func_L39_00673EF0);

INCLUDE_ASM("asm/levels", func_L39_00674190);

/* localdecomp:start func_L39_00674320 */
extern u32 D_L39_002404C0;
extern u8 *func_L39_0061BFB0(u32);
void func_L39_00674320(u8 *a0) {
    if (a0[6676] == 0) {
        u32 v = *(u32 *)(*(u8 **)(*(u8 **)(a0 + 9560) + 4) + 80) ^ D_L39_002404C0;
        if (v != 0xFFFFFFFF) {
            u8 *r = func_L39_0061BFB0(v);
            if (r != 0) {
                *(s32 *)(a0 + 4216) = *(s32 *)(r + 9508);
            }
        }
    }
}
/* localdecomp:end func_L39_00674320 */
