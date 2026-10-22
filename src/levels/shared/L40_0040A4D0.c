#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_0040A4D0);

INCLUDE_ASM("asm/levels", func_L40_0040AA08);

INCLUDE_ASM("asm/levels", func_L40_0040ABB8);

LINKER_REMNANT("asm/levels", func_L40_0040B050);

INCLUDE_ASM("asm/levels", func_L40_0040B058);

INCLUDE_ASM("asm/levels", func_L40_0040B1D0);

INCLUDE_ASM("asm/levels", func_L40_0040B9C0);

INCLUDE_ASM("asm/levels", func_L40_0040BAF0);

INCLUDE_ASM("asm/levels", func_L40_0040BC00);

INCLUDE_ASM("asm/levels", func_L40_0040BCF0);

INCLUDE_ASM("asm/levels", func_L40_0040C6F0);

INCLUDE_ASM("asm/levels", func_L40_0040C878);

INCLUDE_ASM("asm/levels", func_L40_0040CA88);

INCLUDE_ASM("asm/levels", func_L40_0040CD80);

/* localdecomp:start func_L40_0040CEF8 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L40_0040CEF8(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[67] != a1) {
        func_003C3A10(a0, a1, a2, a3);
    }
    a0 = *(u8 **)(v + 624);
    if (a0[67] != a1) {
        func_003C3A10(a0, a1, a2, a3);
    }
}
/* localdecomp:end func_L40_0040CEF8 */

/* localdecomp:start func_L40_0040CF68 */
void func_L40_0040CF68(void *arg0) {
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L40_0040CF68 */

INCLUDE_ASM("asm/levels", func_L40_0040CF88);

INCLUDE_ASM("asm/levels", func_L40_0040D310);

INCLUDE_ASM("asm/levels", func_L40_0040D4C0);

INCLUDE_ASM("asm/levels", func_L40_0040D678);

INCLUDE_ASM("asm/levels", func_L40_0040D7D0);
