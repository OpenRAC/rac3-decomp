#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006A29D0);

INCLUDE_ASM("asm/levels", func_L39_006A2A58);

LINKER_REMNANT("asm/levels", func_L39_006A2F38);

INCLUDE_ASM("asm/levels", func_L39_006A2F50);

LINKER_REMNANT("asm/levels", func_L39_006A3660);

INCLUDE_ASM("asm/levels", func_L39_006A3668);

INCLUDE_ASM("asm/levels", func_L39_006A3690);

/* localdecomp:start func_L39_006A3A80 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006A3A80(void *);

extern void func_L39_0067F168();
void func_L39_006A3A80(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006A3A80 */

INCLUDE_ASM("asm/levels", func_L39_006A3AB0);
