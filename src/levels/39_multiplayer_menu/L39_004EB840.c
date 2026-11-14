#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EB840 */
s32 func_L39_004EB840(long index)
{
    switch (index) {
    case 2: case 3: case 18: case 19: case 20: case 21: case 22:
        return 0x30;
    case 4: case 5: case 6: case 9: case 11: case 13: case 14: case 15: case 16:
        return 0x2A;
    case 7: case 8:
        return 0x33;
    case 10: case 12:
        return 0x2D;
    case 23:
        return 0x2C;
    case 17:
        return 0x50;
    case 50:
        return 0x28;
    }
    return 0x2E;
}
/* localdecomp:end func_L39_004EB840 */

INCLUDE_ASM("asm/levels", func_L39_004EB8B0);

INCLUDE_ASM("asm/levels", func_L39_004EBB10);
