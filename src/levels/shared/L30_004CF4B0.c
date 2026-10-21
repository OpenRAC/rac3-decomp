#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_004CF4B0);

/* localdecomp:start func_L30_004D4690 */
extern void func_L30_004CF4B0(s32, s32);
extern u8 D_001A71C4[];

void func_L30_004D4690(s32 a0) {
    s32 n = 1;
    if (a0 != 0) {
        n = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_L30_004CF4B0(0, n);
        break;
    case 3:
        func_L30_004CF4B0(81, n);
        break;
    case 1:
        func_L30_004CF4B0(63, n);
        break;
    case 5:
        func_L30_004CF4B0(154, n);
        break;
    }
}
/* localdecomp:end func_L30_004D4690 */
