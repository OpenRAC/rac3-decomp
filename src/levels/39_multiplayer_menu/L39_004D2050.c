#include "common.h"

/* localdecomp:start func_L39_004D2050 */
/* from rac4-decomp's func_003F7478, renamed */
void func_L39_004D2050(unsigned int *p) {
    p[0] = 0x67452301;
    p[1] = 0xEFCDAB89;
    p[2] = 0x98BADCFE;
    p[3] = 0x10325476;
    p[4] = 0xC3D2E1F0;
}
/* localdecomp:end func_L39_004D2050 */

INCLUDE_ASM("asm/levels", func_L39_004D2090);

INCLUDE_ASM("asm/levels", func_L39_004D2468);

INCLUDE_ASM("asm/levels", func_L39_004D2710);

INCLUDE_ASM("asm/levels", func_L39_004D2828);

INCLUDE_ASM("asm/levels", func_L39_004D2AF8);

INCLUDE_ASM("asm/levels", func_L39_004D3010);

INCLUDE_ASM("asm/levels", func_L39_004D3160);

INCLUDE_ASM("asm/levels", func_L39_004D3408);

INCLUDE_ASM("asm/levels", func_L39_004D3678);

LINKER_REMNANT("asm/levels", func_L39_004D3A18);

INCLUDE_ASM("asm/levels", func_L39_004D3A20);

INCLUDE_ASM("asm/levels", func_L39_004D3B58);

INCLUDE_ASM("asm/levels", func_L39_004D3E90);

INCLUDE_ASM("asm/levels", func_L39_004D3FA0);

INCLUDE_ASM("asm/levels", func_L39_004D40A8);

LINKER_REMNANT("asm/levels", func_L39_004D4440);

/* localdecomp:start func_L39_004D4448 */
void func_L39_004D4448(s32 *arg0, void *arg1) {
    *arg0 = ((*(u8 *)arg1) << 0x18) | (*(u8 *)((u8 *)arg1 + 3)) | (((*(u8 *)((u8 *)arg1 + 2)) << 8) | ((*(u8 *)((u8 *)arg1 + 1)) << 0x10));
}
/* localdecomp:end func_L39_004D4448 */

INCLUDE_ASM("asm/levels", func_L39_004D4478);
