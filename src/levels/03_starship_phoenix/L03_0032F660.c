#include "common.h"

/* localdecomp:start func_L03_0032F660 */
s32 func_L03_0032F660(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x20)) - 4) < 8U;
}
/* localdecomp:end func_L03_0032F660 */

INCLUDE_ASM("asm/levels", func_L03_0032F670);

INCLUDE_ASM("asm/levels", func_L03_0032F6A8);

INCLUDE_ASM("asm/levels", func_L03_0032F6F8);

INCLUDE_ASM("asm/levels", func_L03_0032F718);

INCLUDE_ASM("asm/levels", func_L03_0032F790);

INCLUDE_ASM("asm/levels", func_L03_0032F7D0);

INCLUDE_ASM("asm/levels", func_L03_0032F810);

/* localdecomp:start func_L03_0032F930 */
extern u8 D_0014271D[];
u8 func_L03_0032F930(s32 a0) {
    if (a0 == 0) {
        return D_0014271D[0];
    }
    return 1;
}
/* localdecomp:end func_L03_0032F930 */

INCLUDE_ASM("asm/levels", func_L03_0032F948);

INCLUDE_ASM("asm/levels", func_L03_0032FA18);

INCLUDE_ASM("asm/levels", func_L03_0032FA50);

/* localdecomp:start func_L03_0032FA78 */
extern u8 D_L03_002AE4D0[];

void func_L03_0032FA78(s32 arg0, s32 *arg1, s32 *arg2) {
    void *temp_a0;

    temp_a0 = (arg0 * 0x28) + D_L03_002AE4D0;
    *arg1 = (~(*(s32 *)((u8 *)temp_a0 + 0x14)) == 0) ? 0 : 0xEC5A;
    *arg2 = (~(*(s32 *)((u8 *)temp_a0 + 0x18)) == 0) ? 0 : 0xEC58;
}
/* localdecomp:end func_L03_0032FA78 */
