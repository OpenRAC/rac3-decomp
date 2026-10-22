#include "common.h"

/* localdecomp:start func_L39_006C87E0 */
void func_L39_006C87E0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x3A8) = arg1;
}
/* localdecomp:end func_L39_006C87E0 */

INCLUDE_ASM("asm/levels", func_L39_006C87E8);

INCLUDE_ASM("asm/levels", func_L39_006C89D8);

LINKER_REMNANT("asm/levels", func_L39_006C8BD0);

INCLUDE_ASM("asm/levels", func_L39_006C8BE0);

LINKER_REMNANT("asm/levels", func_L39_006C8F28);

INCLUDE_ASM("asm/levels", func_L39_006C8F30);

INCLUDE_ASM("asm/levels", func_L39_006C8F58);

/* localdecomp:start func_L39_006C9398 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006C9398(void *);

extern void func_L39_0067F168();
void func_L39_006C9398(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006C9398 */

INCLUDE_ASM("asm/levels", func_L39_006C93C8);
