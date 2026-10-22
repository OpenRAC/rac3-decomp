#include "common.h"

/* localdecomp:start func_L39_006C69B8 */
void func_L39_006C69B8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2A8) = arg1;
}
/* localdecomp:end func_L39_006C69B8 */

INCLUDE_ASM("asm/levels", func_L39_006C69C0);

INCLUDE_ASM("asm/levels", func_L39_006C6B30);

INCLUDE_ASM("asm/levels", func_L39_006C7128);

INCLUDE_ASM("asm/levels", func_L39_006C7800);

INCLUDE_ASM("asm/levels", func_L39_006C7B40);

INCLUDE_ASM("asm/levels", func_L39_006C7C40);

INCLUDE_ASM("asm/levels", func_L39_006C7CE8);

INCLUDE_ASM("asm/levels", func_L39_006C7D28);

INCLUDE_ASM("asm/levels", func_L39_006C7E10);

INCLUDE_ASM("asm/levels", func_L39_006C7E98);

INCLUDE_ASM("asm/levels", func_L39_006C7F08);

/* localdecomp:start func_L39_006C7F78 */
void func_L39_0068B2F8(s32, s32, s32);
void func_L39_006C7F78(void *arg0) {
    func_L39_0068B2F8((s32) arg0, (*(s32 *)((u8 *)arg0 + 0xB68)) + 0xF, 0);
}
/* localdecomp:end func_L39_006C7F78 */

INCLUDE_ASM("asm/levels", func_L39_006C7FA0);

/* localdecomp:start func_L39_006C8020 */
s32 func_L39_006C8020(void *arg0) {
    return (u32) ((*(s32 *)((u8 *)arg0 + 0x290)) - 0xF) < 0xAU;
}
/* localdecomp:end func_L39_006C8020 */

LINKER_REMNANT("asm/levels", func_L39_006C8030);

INCLUDE_ASM("asm/levels", func_L39_006C8050);

LINKER_REMNANT("asm/levels", func_L39_006C8248);

INCLUDE_ASM("asm/levels", func_L39_006C8250);

INCLUDE_ASM("asm/levels", func_L39_006C8278);

INCLUDE_ASM("asm/levels", func_L39_006C82C8);

INCLUDE_ASM("asm/levels", func_L39_006C8490);

INCLUDE_ASM("asm/levels", func_L39_006C84E8);
