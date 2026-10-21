#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00699838);

INCLUDE_ASM("asm/levels", func_L39_0069A120);

INCLUDE_ASM("asm/levels", func_L39_0069A170);

/* localdecomp:start func_L39_0069A600 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069A600(void *);

extern void func_L39_0067F168();
void func_L39_0069A600(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069A600 */

INCLUDE_ASM("asm/levels", func_L39_0069A630);

INCLUDE_ASM("asm/levels", func_L39_0069AEF0);
