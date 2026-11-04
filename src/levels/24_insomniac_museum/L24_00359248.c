#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_00359248);

INCLUDE_ASM("asm/levels", func_L24_00359528);

INCLUDE_ASM("asm/levels", func_L24_00359650);

INCLUDE_ASM("asm/levels", func_L24_00359E30);

INCLUDE_ASM("asm/levels", func_L24_00359FE0);

/* localdecomp:start func_L24_0035A248 */
__asm__(".extern D_L24_001DF558, 4");
extern u16 *D_L24_0021C360[];
extern u8 *D_L24_001DF51C;
extern s32 D_L24_001DF558;

void func_L24_0035A248(u8 *arg0)
{
    u16 *p;

    if (arg0[0x21] == 0xFF)
        return;
    p = D_L24_0021C360[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L24_001DF558 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L24_0021C360[arg0[0x21]])) {
        u8 *e = D_L24_001DF51C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(arg0 + 0xAA)) {
            *(u8 *)(*(u8 **)(e + 0x68) + 0x199) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L24_0035A248 */

INCLUDE_ASM("asm/levels", func_L24_0035A300);

INCLUDE_ASM("asm/levels", func_L24_0035A438);
