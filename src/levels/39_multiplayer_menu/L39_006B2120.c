#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006B2120);

INCLUDE_ASM("asm/levels", func_L39_006B22B0);

INCLUDE_ASM("asm/levels", func_L39_006B2450);

INCLUDE_ASM("asm/levels", func_L39_006B2498);

INCLUDE_ASM("asm/levels", func_L39_006B29A8);

INCLUDE_ASM("asm/levels", func_L39_006B2CE0);

INCLUDE_ASM("asm/levels", func_L39_006B2D18);

LINKER_REMNANT("asm/levels", func_L39_006B2D40);

INCLUDE_ASM("asm/levels", func_L39_006B2D50);

LINKER_REMNANT("asm/levels", func_L39_006B2FC0);

INCLUDE_ASM("asm/levels", func_L39_006B2FC8);

INCLUDE_ASM("asm/levels", func_L39_006B2FF0);

/* localdecomp:start func_L39_006B30D8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B30D8(void *);

extern void func_L39_0067F168();
void func_L39_006B30D8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B30D8 */

INCLUDE_ASM("asm/levels", func_L39_006B3108);
