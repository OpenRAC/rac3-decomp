#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003FA478);

INCLUDE_ASM("asm/levels", func_L20_003FACD8);

INCLUDE_ASM("asm/levels", func_L20_003FAF10);

/* localdecomp:start func_L20_003FB120 */
void func_003C2880(s32);
void func_L01_004443E8(void *, s32, s32);
s32 func_L01_004AAC98(s32, s32, s32, s32);

void func_L20_003FB120(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004AAC98(0, 0, arg0, 0x1E00);
    func_003C2880((*(s32 *)((u8 *)temp_s1 + 0x2EC)));
    *(s32 *)((u8 *)temp_s1 + 0x240) = 0;
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L20_003FB120 */

INCLUDE_ASM("asm/levels", func_L20_003FB180);
