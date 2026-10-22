#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006BA5C0);

LINKER_REMNANT("asm/levels", func_L39_006BAAF8);

INCLUDE_ASM("asm/levels", func_L39_006BAB00);

/* localdecomp:start func_L39_006BB148 */
void func_L39_00688400(void *, s32);
void func_L39_006CC158(void *, s32);
extern u8 D_L39_0047E880[];

void func_L39_006BB148(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047E880;
    func_L39_006CC158(arg0 + 0x8590, 2);
    func_L39_00688400(arg0, arg1);
}
/* localdecomp:end func_L39_006BB148 */

INCLUDE_ASM("asm/levels", func_L39_006BB1A0);

INCLUDE_ASM("asm/levels", func_L39_006BBB38);

INCLUDE_ASM("asm/levels", func_L39_006BBBE0);

INCLUDE_ASM("asm/levels", func_L39_006BBC08);

INCLUDE_ASM("asm/levels", func_L39_006BBD80);

INCLUDE_ASM("asm/levels", func_L39_006BD290);

INCLUDE_ASM("asm/levels", func_L39_006BD408);

INCLUDE_ASM("asm/levels", func_L39_006BD788);

INCLUDE_ASM("asm/levels", func_L39_006BD988);

INCLUDE_ASM("asm/levels", func_L39_006BDAB8);

INCLUDE_ASM("asm/levels", func_L39_006BDCC8);

INCLUDE_ASM("asm/levels", func_L39_006BDCF0);

INCLUDE_ASM("asm/levels", func_L39_006BDE00);

INCLUDE_ASM("asm/levels", func_L39_006BE260);

/* localdecomp:start func_L39_006BE580 */
void func_L39_006BE580(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}
/* localdecomp:end func_L39_006BE580 */

/* localdecomp:start func_L39_006BE598 */
void func_L39_006BE598(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}
/* localdecomp:end func_L39_006BE598 */

INCLUDE_ASM("asm/levels", func_L39_006BE5B0);

LINKER_REMNANT("asm/levels", func_L39_006BE7C8);

INCLUDE_ASM("asm/levels", func_L39_006BE7E0);

LINKER_REMNANT("asm/levels", func_L39_006C0F08);

INCLUDE_ASM("asm/levels", func_L39_006C0F10);

INCLUDE_ASM("asm/levels", func_L39_006C0F38);

INCLUDE_ASM("asm/levels", func_L39_006C16F0);

INCLUDE_ASM("asm/levels", func_L39_006C1730);
