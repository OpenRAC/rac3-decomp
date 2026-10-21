#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_00352C80);

INCLUDE_ASM("asm/levels", func_L02_00352DF0);

INCLUDE_ASM("asm/levels", func_L02_00352F60);

INCLUDE_ASM("asm/levels", func_L02_00353208);

INCLUDE_ASM("asm/levels", func_L02_003532F0);

INCLUDE_ASM("asm/levels", func_L02_00353398);

INCLUDE_ASM("asm/levels", func_L02_003534D8);

/* localdecomp:start func_L02_003536B8 */
extern void func_L02_003536D8(s32);
void func_L02_003536B8(u8 *p) {
    func_L02_003536D8(*(s32 *)(p + 0x68));
}
/* localdecomp:end func_L02_003536B8 */

INCLUDE_ASM("asm/levels", func_L02_003536D8);
