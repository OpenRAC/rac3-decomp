#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003E2B80);

INCLUDE_ASM("asm/levels", func_L07_003E2DB0);

/* localdecomp:start func_L07_003E2EC8 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003E2EC8(u8 *arg0) {
    u8 *p;
    s32 r;

    p = *(u8 **)(arg0 + 0x68);
    if (arg0[0x20] != 4) {
        r = func_L01_00447490(arg0, -1, 0);
        if (r != 0) {
            func_0038CF68(p + 0x220, (void *)(r + 0x10), 0.50000006f);
            *(s16 *)(p + 0x25C) = 0x2A;
            arg0[0x30] = 0xFF;
            func_L01_004450F0(arg0, 4, -1);
        }
    }
}
/* localdecomp:end func_L07_003E2EC8 */

INCLUDE_ASM("asm/levels", func_L07_003E2F48);

INCLUDE_ASM("asm/levels", func_L07_003E3050);

INCLUDE_ASM("asm/levels", func_L07_003E31F8);

INCLUDE_ASM("asm/levels", func_L07_003E3220);

INCLUDE_ASM("asm/levels", func_L07_003E3388);

INCLUDE_ASM("asm/levels", func_L07_003E3458);

INCLUDE_ASM("asm/levels", func_L07_003E34D8);
