#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006B8458);

INCLUDE_ASM("asm/levels", func_L39_006B84E8);

INCLUDE_ASM("asm/levels", func_L39_006B8698);

INCLUDE_ASM("asm/levels", func_L39_006B8AC8);

INCLUDE_ASM("asm/levels", func_L39_006B8D48);

INCLUDE_ASM("asm/levels", func_L39_006B8D88);

LINKER_REMNANT("asm/levels", func_L39_006B9000);

INCLUDE_ASM("asm/levels", func_L39_006B9008);

LINKER_REMNANT("asm/levels", func_L39_006B9F50);

INCLUDE_ASM("asm/levels", func_L39_006B9F58);

INCLUDE_ASM("asm/levels", func_L39_006B9F80);

/* localdecomp:start func_L39_006BA468 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006BA468(void *);

extern void func_L39_0067F168();
void func_L39_006BA468(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006BA468 */

INCLUDE_ASM("asm/levels", func_L39_006BA498);
