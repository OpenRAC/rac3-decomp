#include "common.h"

/* declared by functions of L39_004CCE58.c, which this file was cut from */
extern unsigned long D_L39_0046A088[];

/* localdecomp:start func_L39_004D0C78 */
extern unsigned long func_1306F8(unsigned long, unsigned long);

/* newlib rand() */
s32 func_L39_004D0C78(void) {
    D_L39_0046A088[0] = func_1306F8(D_L39_0046A088[0], 0x5851F42D4C957F2DUL) + 1;
    return (D_L39_0046A088[0] >> 32) & 0x7FFFFFFF;
}
/* localdecomp:end func_L39_004D0C78 */

INCLUDE_ASM("asm/levels", func_L39_004D0CE0);

/* localdecomp:start func_L39_004D0D68 */
/* from rac4-decomp's func_003F6470 */
u8 *func_L39_004D0D68(u8 *arg0, u8 *arg1) {
    s32 i;

    for (i = 0; i < 8; i++) {
        arg1[i] ^= arg0[i];
    }
    return arg1;
}
/* localdecomp:end func_L39_004D0D68 */

INCLUDE_ASM("asm/levels", func_L39_004D0DA8);

INCLUDE_ASM("asm/levels", func_L39_004D0EF8);

INCLUDE_ASM("asm/levels", func_L39_004D0FE8);

INCLUDE_ASM("asm/levels", func_L39_004D1268);

INCLUDE_ASM("asm/levels", func_L39_004D13F8);

INCLUDE_ASM("asm/levels", func_L39_004D1460);
