#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006AF7A8);

INCLUDE_ASM("asm/levels", func_L39_006AF7D0);

LINKER_REMNANT("asm/levels", func_L39_006AF808);

INCLUDE_ASM("asm/levels", func_L39_006AF810);

LINKER_REMNANT("asm/levels", func_L39_006AFF40);

/* localdecomp:start func_L39_006AFF48 */
extern u8 D_L39_0047DFA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006AFF48(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DFA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006AFF48 */

INCLUDE_ASM("asm/levels", func_L39_006AFF70);

/* localdecomp:start func_L39_006B03B8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B03B8(void *);

extern void func_L39_0067F168();
void func_L39_006B03B8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B03B8 */

INCLUDE_ASM("asm/levels", func_L39_006B03E8);
