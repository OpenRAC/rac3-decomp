#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003B5B48);

INCLUDE_ASM("asm/levels", func_L10_003B64C8);

INCLUDE_ASM("asm/levels", func_L10_003B85A0);

INCLUDE_ASM("asm/levels", func_L10_003B8A80);

LINKER_REMNANT("asm/levels", func_L10_003B8EC0);

/* localdecomp:start func_L10_003B8ED0 */
void func_003C2880(s32);
void func_L01_004443E8(void *, s32, s32);

void func_L10_003B8ED0(void *arg0, s32 arg1) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x2DC);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x2DC) = 0;
    }
    if (((*(f32 *)((u8 *)temp_s0 + 0x30)) <= 0.0f) && (arg1 == 0)) {
        func_L01_004443E8(arg0, 0, 3);
    }
}
/* localdecomp:end func_L10_003B8ED0 */

INCLUDE_ASM("asm/levels", func_L10_003B8F50);
