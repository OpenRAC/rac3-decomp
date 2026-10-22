#include "common.h"

/* localdecomp:start func_L02_003BBA80 */
void func_L01_004AA7E8(s32, s32);
void func_L02_003BBA80(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L02_003BBA80 */

INCLUDE_ASM("asm/levels", func_L02_003BBAC0);

INCLUDE_ASM("asm/levels", func_L02_003BBC98);
