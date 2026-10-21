#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006AC860);

INCLUDE_ASM("asm/levels", func_L39_006ACC60);

INCLUDE_ASM("asm/levels", func_L39_006ACE10);

LINKER_REMNANT("asm/levels", func_L39_006ACEA0);

INCLUDE_ASM("asm/levels", func_L39_006ACEA8);

LINKER_REMNANT("asm/levels", func_L39_006AD970);

INCLUDE_ASM("asm/levels", func_L39_006AD978);

INCLUDE_ASM("asm/levels", func_L39_006AD9A0);

/* localdecomp:start func_L39_006AE208 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006AE208(void *);

extern void func_L39_0067F168();
void func_L39_006AE208(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006AE208 */

INCLUDE_ASM("asm/levels", func_L39_006AE238);
