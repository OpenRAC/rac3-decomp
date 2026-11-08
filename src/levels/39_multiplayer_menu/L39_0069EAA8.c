#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0069EAA8);

LINKER_REMNANT("asm/levels", func_L39_0069EB08);

INCLUDE_ASM("asm/levels", func_L39_0069EB18);

LINKER_REMNANT("asm/levels", func_L39_0069F0F8);

/* localdecomp:start func_L39_0069F100 */
extern u8 D_L39_0047D410[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0069F100(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D410;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0069F100 */

INCLUDE_ASM("asm/levels", func_L39_0069F128);

INCLUDE_ASM("asm/levels", func_L39_0069F168);

/* localdecomp:start func_L39_0069F310 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069F310(void *);

extern void func_L39_0067F168();
void func_L39_0069F310(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069F310 */

INCLUDE_ASM("asm/levels", func_L39_0069F340);
