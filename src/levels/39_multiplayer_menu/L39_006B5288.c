#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006B5288);

INCLUDE_ASM("asm/levels", func_L39_006B52A0);

INCLUDE_ASM("asm/levels", func_L39_006B5498);

INCLUDE_ASM("asm/levels", func_L39_006B5D00);

INCLUDE_ASM("asm/levels", func_L39_006B5F20);

INCLUDE_ASM("asm/levels", func_L39_006B6158);

LINKER_REMNANT("asm/levels", func_L39_006B6388);

INCLUDE_ASM("asm/levels", func_L39_006B63B8);

LINKER_REMNANT("asm/levels", func_L39_006B6648);

INCLUDE_ASM("asm/levels", func_L39_006B6650);

INCLUDE_ASM("asm/levels", func_L39_006B6678);

INCLUDE_ASM("asm/levels", func_L39_006B66B8);

/* localdecomp:start func_L39_006B6860 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B6860(void *);

extern void func_L39_0067F168();
void func_L39_006B6860(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B6860 */

INCLUDE_ASM("asm/levels", func_L39_006B6890);
