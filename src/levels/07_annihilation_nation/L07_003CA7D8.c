#include "common.h"

/* localdecomp:start func_L07_003CA7D8 */
void func_L01_004450F0(void *, s32, s32);
s32 func_L01_004561B8(void *);
s32 func_L07_003CA8A0(void *);
void func_L07_003CA918(void *);
void func_L07_003CAA48(void *);

void func_L07_003CA7D8(void *arg0) {
    u8 temp_v1;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 1:
        if (func_L01_004561B8(arg0) != 0) {
            func_L07_003CAA48(arg0);
        }
        if (func_L07_003CA8A0(arg0) != 0) {
            func_L01_004450F0(arg0, 2, -1);
            return;
        }
        return;
    case 2:
        if (func_L01_004561B8(arg0) != 0) {
            func_L07_003CA918(arg0);
        }
        if (func_L07_003CA8A0(arg0) == 0) {
            func_L01_004450F0(arg0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L07_003CA7D8 */

INCLUDE_ASM("asm/levels", func_L07_003CA8A0);

INCLUDE_ASM("asm/levels", func_L07_003CA918);

INCLUDE_ASM("asm/levels", func_L07_003CAA48);
