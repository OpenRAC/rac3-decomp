#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D2AB8);

INCLUDE_ASM("asm/levels", func_L07_003D2B30);

INCLUDE_ASM("asm/levels", func_L07_003D2B98);

/* localdecomp:start func_L07_003D2BE0 */
void func_L01_004AA7E8(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003D2BE0(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x98) = 0;
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x43) & 0xEFFF);
    func_L01_004AA7E8((s32) arg0, 1);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003D2BE0 */
