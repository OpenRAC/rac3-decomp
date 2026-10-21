#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006928D0);

INCLUDE_ASM("asm/levels", func_L39_00692918);

INCLUDE_ASM("asm/levels", func_L39_00692C38);

INCLUDE_ASM("asm/levels", func_L39_00692F20);

LINKER_REMNANT("asm/levels", func_L39_006932C8);

INCLUDE_ASM("asm/levels", func_L39_006932E8);

LINKER_REMNANT("asm/levels", func_L39_006938E0);

INCLUDE_ASM("asm/levels", func_L39_006938E8);

INCLUDE_ASM("asm/levels", func_L39_00693910);

/* localdecomp:start func_L39_00693F40 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00693F40(void *);

extern void func_L39_0067F168();
void func_L39_00693F40(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00693F40 */

INCLUDE_ASM("asm/levels", func_L39_00693F70);
