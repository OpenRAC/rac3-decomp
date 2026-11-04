#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003A6BA8);

/* localdecomp:start func_L24_003A7558 */
extern s32 D_001DE300;
extern u8 D_001CD0C0[];

void func_L24_003A7558(s32 *a0, s32 *a1) {
    {
        u8 *p = D_001CD0C0 + D_001DE300 * 0x5C0;
        if (*(u32 *)(p + 0x1A0) & 0x2000) {
            *a0 = -1;
        }
    }
    {
        u8 *p = D_001CD0C0 + D_001DE300 * 0x5C0;
        if (*(u32 *)(p + 0x1A0) & 0x8000) {
            *a0 = 1;
        }
    }
    {
        u8 *p = D_001CD0C0 + D_001DE300 * 0x5C0;
        if (*(u32 *)(p + 0x1A0) & 0x4000) {
            *a1 = 1;
        }
    }
    {
        u8 *p = D_001CD0C0 + D_001DE300 * 0x5C0;
        if (*(u32 *)(p + 0x1A0) & 0x1000) {
            *a1 = -1;
        }
    }
}
/* localdecomp:end func_L24_003A7558 */

INCLUDE_ASM("asm/levels", func_L24_003A75F0);
