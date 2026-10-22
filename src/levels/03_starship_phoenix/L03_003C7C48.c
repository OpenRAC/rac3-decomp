#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003C7C48);

INCLUDE_ASM("asm/levels", func_L03_003C7EF0);

INCLUDE_ASM("asm/levels", func_L03_003C7F78);

INCLUDE_ASM("asm/levels", func_L03_003C8000);

/* localdecomp:start func_L03_003C8088 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279C[];

void func_L03_003C8088(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (D_0014279C[0] == 0) {
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8((s32) arg0, 1);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L03_003C8088 */

/* localdecomp:start func_L03_003C80E8 */
void func_L01_004AA7E8(s32, s32);
extern u8 D_0014279D[];

void func_L03_003C80E8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        if (D_0014279D[0] == 0) {
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
            *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8((s32) arg0, 1);
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L03_003C80E8 */

INCLUDE_ASM("asm/levels", func_L03_003C8148);
