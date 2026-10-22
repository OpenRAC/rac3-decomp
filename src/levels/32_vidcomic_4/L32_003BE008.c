#include "common.h"

INCLUDE_ASM("asm/levels", func_L32_003BE008);

INCLUDE_ASM("asm/levels", func_L32_003BE098);

/* localdecomp:start func_L32_003BE498 */
void func_L32_003BE098(void *);
void func_L32_003BE4E8();

void func_L32_003BE498(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 0xFDU) {
        func_L32_003BE4E8();
        if ((*(u8 *)((u8 *)arg0 + 0x20)) == 2) {
            func_L32_003BE098(arg0);
        }
    }
}
/* localdecomp:end func_L32_003BE498 */

INCLUDE_ASM("asm/levels", func_L32_003BE4E8);

INCLUDE_ASM("asm/levels", func_L32_003BE5E0);

INCLUDE_ASM("asm/levels", func_L32_003BE830);

INCLUDE_ASM("asm/levels", func_L32_003BE8E0);

INCLUDE_ASM("asm/levels", func_L32_003BE960);

INCLUDE_ASM("asm/levels", func_L32_003BED60);
