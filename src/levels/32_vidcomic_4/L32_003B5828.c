#include "common.h"

INCLUDE_ASM("asm/levels", func_L32_003B5828);

INCLUDE_ASM("asm/levels", func_L32_003B58D0);

INCLUDE_ASM("asm/levels", func_L32_003B5C98);

INCLUDE_ASM("asm/levels", func_L32_003B5F58);

INCLUDE_ASM("asm/levels", func_L32_003B6170);

INCLUDE_ASM("asm/levels", func_L32_003B6408);

INCLUDE_ASM("asm/levels", func_L32_003B6618);

INCLUDE_ASM("asm/levels", func_L32_003B66A0);

INCLUDE_ASM("asm/levels", func_L32_003B6A58);

INCLUDE_ASM("asm/levels", func_L32_003B6C88);

INCLUDE_ASM("asm/levels", func_L32_003B6DD0);

/* localdecomp:start func_L32_003B70F8 */
s32 func_003A52A0(s32, s32, void *);
void func_L01_004450F0(void *, s32, s32);
s32 func_L05_00328FF8(void *);
void func_L32_003B5F58();
extern u8 D_001A30B0[];

void func_L32_003B70F8(void *arg0) {
    s32 temp_a0;
    void *temp_a0_2;
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L32_003B5F58();
    temp_a0 = *(s32 *)((u8 *)temp_s1 + 0x258);
    if ((temp_a0 == -1) || (temp_a0_2 = (temp_a0 << 7) + D_001A30B0, ((*(s32 *)((u8 *)temp_a0_2 + 0xDC)) != arg0)) || ((*(u8 *)((u8 *)temp_a0_2 + 0xD0)) == 0)) {
        *(s32 *)((u8 *)temp_s1 + 0x258) = func_003A52A0(5, 4, arg0);
    }
    if (func_L05_00328FF8(arg0) != 0) {
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L32_003B70F8 */

INCLUDE_ASM("asm/levels", func_L32_003B7190);

INCLUDE_ASM("asm/levels", func_L32_003B7610);

INCLUDE_ASM("asm/levels", func_L32_003B7AB0);

INCLUDE_ASM("asm/levels", func_L32_003B7BE8);

INCLUDE_ASM("asm/levels", func_L32_003B8160);

INCLUDE_ASM("asm/levels", func_L32_003B81F0);

INCLUDE_ASM("asm/levels", func_L32_003B8230);

INCLUDE_ASM("asm/levels", func_L32_003B8390);
