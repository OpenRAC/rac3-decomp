#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D48D0);

INCLUDE_ASM("asm/levels", func_L07_003D4DB8);

INCLUDE_ASM("asm/levels", func_L07_003D5008);

/* localdecomp:start func_L07_003D5170 */
extern void func_L07_003D51D8(u8 *);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_L07_001DF41C[];

void func_L07_003D5170(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 x;
    u8 *base;
    *(s32 *)(p + 0x28) = 0;
    func_L07_003D51D8(a0);
    x = *(s32 *)(p + 0x24);
    base = D_L07_001DF41C[0];
    func_L01_00456230(base + (x << 8), 0);
    *(u8 *)(p + 8) = 1;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D5170 */

INCLUDE_ASM("asm/levels", func_L07_003D51D8);
