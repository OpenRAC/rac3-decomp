#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_0035DBA8);

/* localdecomp:start func_L14_0035DE68 */
void func_L14_0035DBA8(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L14_0035DE68(void *arg0, void *arg1) {
    f32 *temp_v0;
    f32 temp_f0;

    temp_v0 = *(f32 **)((u8 *)arg0 + 0x68);
    temp_f0 = *temp_v0 - (*(f32 *)((u8 *)arg1 + 0x2C));
    *temp_v0 = temp_f0;
    if ((temp_f0 > 0.0f) && ((*(u16 *)((u8 *)arg0 + 0x7C)) != 0)) {
        func_L14_0035DBA8((s32) arg0);
        return;
    }
    *(u16 *)((u8 *)arg0 + 0x7C) = 0U;
    func_L01_004450F0(arg0, 3, -1);
}
/* localdecomp:end func_L14_0035DE68 */

INCLUDE_ASM("asm/levels", func_L14_0035DED8);

INCLUDE_ASM("asm/levels", func_L14_0035DFE0);
