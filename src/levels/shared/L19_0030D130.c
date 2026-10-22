#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_0030D130);

INCLUDE_ASM("asm/levels", func_L19_0030D388);

/* localdecomp:start func_L19_0030D818 */
void func_L01_004450F0(void *, s32, s32);
s32 func_L01_00456250(void *);
void func_L01_004AA7E8(void *, s32);

void func_L19_0030D818(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_L01_004450F0(arg0, 1, -1);
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8(arg0, 1);
        return;
    case 1:
        if (func_L01_00456250(arg0) != 0) {
            func_L01_004450F0(arg0, 2, -1);
            *(s32 *)((u8 *)arg0 + 0x98) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x10));
            return;
        }
        return;
    case 2:
        if (func_L01_00456250(arg0) == 0) {
            func_L01_004450F0(arg0, 1, -1);
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
        }
        break;
    }
}
/* localdecomp:end func_L19_0030D818 */

/* localdecomp:start func_L19_0030D8F8 */
extern s32 func_00382380(s32, s32, s32);

s32 func_L19_0030D8F8(u8 *a0, s32 a1) {
    return func_00382380(a1, *(s32 *)(*(u8 **)(a0 + 104) + 112), 0) != 0;
}
/* localdecomp:end func_L19_0030D8F8 */

INCLUDE_ASM("asm/levels", func_L19_0030D928);

INCLUDE_ASM("asm/levels", func_L19_0030D9A8);
