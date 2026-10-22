#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_003B3BB8);

INCLUDE_ASM("asm/levels", func_L23_003B3EA8);

INCLUDE_ASM("asm/levels", func_L23_003B4108);

/* localdecomp:start func_L23_003B44E8 */
void func_L23_003B44E8(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x390) = 0;
}
/* localdecomp:end func_L23_003B44E8 */

INCLUDE_ASM("asm/levels", func_L23_003B44F8);

INCLUDE_ASM("asm/levels", func_L23_003B48D0);

INCLUDE_ASM("asm/levels", func_L23_003B4AD0);

INCLUDE_ASM("asm/levels", func_L23_003B5068);

INCLUDE_ASM("asm/levels", func_L23_003B51C0);

INCLUDE_ASM("asm/levels", func_L23_003B5318);

INCLUDE_ASM("asm/levels", func_L23_003B54A0);

INCLUDE_ASM("asm/levels", func_L23_003B5538);

INCLUDE_ASM("asm/levels", func_L23_003B5628);

INCLUDE_ASM("asm/levels", func_L23_003B5760);

INCLUDE_ASM("asm/levels", func_L23_003B5788);

INCLUDE_ASM("asm/levels", func_L23_003B57B8);

INCLUDE_ASM("asm/levels", func_L23_003B6390);

INCLUDE_ASM("asm/levels", func_L23_003B65F0);

INCLUDE_ASM("asm/levels", func_L23_003B67B0);

INCLUDE_ASM("asm/levels", func_L23_003B6990);

/* localdecomp:start func_L23_003B6A80 */
void func_0038CAD0(s32);

void func_L23_003B6A80(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CAD0(temp_s0 + 0x2C0);
    func_0038CAD0(temp_s0 + 0x2C4);
    func_0038CAD0(temp_s0 + 0x300);
}
/* localdecomp:end func_L23_003B6A80 */

INCLUDE_ASM("asm/levels", func_L23_003B6AD0);

INCLUDE_ASM("asm/levels", func_L23_003B6C90);

INCLUDE_ASM("asm/levels", func_L23_003B6D78);
