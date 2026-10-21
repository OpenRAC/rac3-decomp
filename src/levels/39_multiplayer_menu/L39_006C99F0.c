#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006C99F0);

INCLUDE_ASM("asm/levels", func_L39_006C9BF0);

INCLUDE_ASM("asm/levels", func_L39_006C9C48);

INCLUDE_ASM("asm/levels", func_L39_006C9E50);

INCLUDE_ASM("asm/levels", func_L39_006CA060);

INCLUDE_ASM("asm/levels", func_L39_006CA268);

LINKER_REMNANT("asm/levels", func_L39_006CA2A8);

INCLUDE_ASM("asm/levels", func_L39_006CA2C0);

LINKER_REMNANT("asm/levels", func_L39_006CA6C0);

INCLUDE_ASM("asm/levels", func_L39_006CA6C8);

INCLUDE_ASM("asm/levels", func_L39_006CA6F0);

INCLUDE_ASM("asm/levels", func_L39_006CA730);

/* localdecomp:start func_L39_006CA8C8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006CA8C8(void *);

extern void func_L39_0067F168();
void func_L39_006CA8C8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006CA8C8 */

INCLUDE_ASM("asm/levels", func_L39_006CA8F8);
