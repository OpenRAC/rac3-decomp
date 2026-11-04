#include "common.h"

/* localdecomp:start func_L21_003A3A20 */
void func_L01_004450F0(s32, s32, s32);
void func_L21_003A3AA8(void *arg0);
extern s32 D_L21_001E0FC0[];

void func_L21_003A3A20(void *arg0) {
    s32 *tbl;
    u32 idx;
    s32 v;
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        func_L21_003A3AA8(arg0);
        switch (*(u8 *)((u8 *)arg0 + 0x20)) {
        case 0:
            func_L01_004450F0((s32) arg0, 1, -1);
            break;
        case 1:
            tbl = D_L21_001E0FC0;
            idx = *(s16 *)((u8 *)arg0 + 0xAA) - 0x1B44;
            do {
                v = tbl[idx];
            } while (0);
            *(s32 *)((u8 *)arg0 + 0x78) = v;
            break;
        }
    }
}
/* localdecomp:end func_L21_003A3A20 */

INCLUDE_ASM("asm/levels", func_L21_003A3AA8);
