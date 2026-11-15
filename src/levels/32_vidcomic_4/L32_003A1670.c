#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A1670 */
void func_L01_004450F0(s32, s32, s32);

void func_L32_003A1670(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L01_004450F0((s32) arg0, arg1, -1);
    if (*(u8 *)((u8 *)arg0 + 0x20) == 3) {
        *(s8 *)(p + 0x229) = 1;
        *(s8 *)(p + 0x228) = 0;
        *(s32 *)(p + 0x21C) = 4;
    }
}
/* localdecomp:end func_L32_003A1670 */

INCLUDE_ASM("asm/levels", func_L32_003A16C8);
