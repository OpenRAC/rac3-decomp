#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_003A8FE0);

INCLUDE_ASM("asm/levels", func_L11_003A9260);

INCLUDE_ASM("asm/levels", func_L11_003A9860);

INCLUDE_ASM("asm/levels", func_L11_003A9B30);

INCLUDE_ASM("asm/levels", func_L11_003A9CB0);

/* localdecomp:start func_L11_003A9D50 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L11_003A9D50(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x2D0);
    func_0038CB00(temp_s0 + 0x2D4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L11_003A9D50 */
