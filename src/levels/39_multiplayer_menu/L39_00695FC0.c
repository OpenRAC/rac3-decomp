#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00695FC0);

INCLUDE_ASM("asm/levels", func_L39_00696010);

LINKER_REMNANT("asm/levels", func_L39_006962F8);

INCLUDE_ASM("asm/levels", func_L39_00696308);

LINKER_REMNANT("asm/levels", func_L39_00696AC0);

INCLUDE_ASM("asm/levels", func_L39_00696AC8);

INCLUDE_ASM("asm/levels", func_L39_00696AF0);

/* localdecomp:start func_L39_00697100 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00697100(void *);

extern void func_L39_0067F168();
void func_L39_00697100(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00697100 */

INCLUDE_ASM("asm/levels", func_L39_00697130);
