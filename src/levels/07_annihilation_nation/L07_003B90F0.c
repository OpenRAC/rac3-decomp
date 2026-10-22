#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003B90F0);

INCLUDE_ASM("asm/levels", func_L07_003B91C8);

INCLUDE_ASM("asm/levels", func_L07_003B94E0);

INCLUDE_ASM("asm/levels", func_L07_003B9590);

INCLUDE_ASM("asm/levels", func_L07_003B96F8);

/* localdecomp:start func_L07_003B98E0 */
void func_L01_003F2AF8(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B98E0(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_s0 + 0x30)) != 0) {
        func_L01_003F2AF8(0, (*(s32 *)((u8 *)temp_s0 + 0x40)));
        *(s32 *)((u8 *)temp_s0 + 0x30) = 0;
    }
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003B98E0 */

INCLUDE_ASM("asm/levels", func_L07_003B9948);
