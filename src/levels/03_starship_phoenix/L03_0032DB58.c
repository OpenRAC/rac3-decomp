#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0032DB58);

/* localdecomp:start func_L03_0032DBC0 */
s32 func_L03_0032DBC0(void) {
    return 0x10001;
}
/* localdecomp:end func_L03_0032DBC0 */

/* localdecomp:start func_L03_0032DBD0 */
void *func_L03_0032F6A8();

s32 func_L03_0032DBD0(s32 arg0, s32 arg1) {
    return (((*(u8 *)((u8 *)(func_L03_0032F6A8()) + 0x1C)) ^ 3) == 0) ? arg1 : 0xA;
}
/* localdecomp:end func_L03_0032DBD0 */

INCLUDE_ASM("asm/levels", func_L03_0032DC08);

INCLUDE_ASM("asm/levels", func_L03_0032DDC8);

INCLUDE_ASM("asm/levels", func_L03_0032DF10);

INCLUDE_ASM("asm/levels", func_L03_0032DF60);

INCLUDE_ASM("asm/levels", func_L03_0032E0D8);

INCLUDE_ASM("asm/levels", func_L03_0032E640);

INCLUDE_ASM("asm/levels", func_L03_0032E6F0);

INCLUDE_ASM("asm/levels", func_L03_0032E7A0);

INCLUDE_ASM("asm/levels", func_L03_0032E7E8);

/* localdecomp:start func_L03_0032E8D8 */
void func_L03_0032E8D8(void *arg0, s32 arg1) {
    u8 temp_a1;
    u8 temp_v0;
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = arg1 & 0xFF;
    temp_v0 = *(u8 *)((u8 *)temp_v1 + 0xF6);
    *(u8 *)((u8 *)temp_v1 + 0xF6) = temp_a1;
    *(s8 *)((u8 *)temp_v1 + 0xF7) = (s8) (temp_a1 & ~temp_v0 & 0x1F);
}
/* localdecomp:end func_L03_0032E8D8 */

INCLUDE_ASM("asm/levels", func_L03_0032E900);

INCLUDE_ASM("asm/levels", func_L03_0032EB30);

INCLUDE_ASM("asm/levels", func_L03_0032EBF0);

INCLUDE_ASM("asm/levels", func_L03_0032EC38);
