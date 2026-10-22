#include "common.h"

/* localdecomp:start func_L39_0069E1A8 */
void func_L39_0069E1A8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C8) = arg1;
}
/* localdecomp:end func_L39_0069E1A8 */

INCLUDE_ASM("asm/levels", func_L39_0069E1B0);

LINKER_REMNANT("asm/levels", func_L39_0069E5B8);

INCLUDE_ASM("asm/levels", func_L39_0069E5C0);

INCLUDE_ASM("asm/levels", func_L39_0069E740);

INCLUDE_ASM("asm/levels", func_L39_0069E768);

INCLUDE_ASM("asm/levels", func_L39_0069E7A8);

/* localdecomp:start func_L39_0069E920 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069E920(void *);

extern void func_L39_0067F168();
void func_L39_0069E920(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069E920 */

INCLUDE_ASM("asm/levels", func_L39_0069E950);
