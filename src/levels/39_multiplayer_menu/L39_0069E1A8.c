#include "common.h"

/* localdecomp:start func_L39_0069E1A8 */
void func_L39_0069E1A8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2C8) = arg1;
}
/* localdecomp:end func_L39_0069E1A8 */

INCLUDE_ASM("asm/levels", func_L39_0069E1B0);

LINKER_REMNANT("asm/levels", func_L39_0069E5B8);

INCLUDE_ASM("asm/levels", func_L39_0069E5C0);

/* localdecomp:start func_L39_0069E740 */
extern u8 D_L39_0047D310[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0069E740(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D310;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0069E740 */

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
