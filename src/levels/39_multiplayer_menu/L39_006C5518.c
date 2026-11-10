#include "common.h"

/* localdecomp:start func_L39_006C5518 */
extern u8 D_L39_0047EAA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006C5518(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EAA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006C5518 */

INCLUDE_ASM("asm/levels", func_L39_006C5540);

/* localdecomp:start func_L39_006C5B30 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006C5B30(void *);

extern void func_L39_0067F168();
void func_L39_006C5B30(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006C5B30 */

INCLUDE_ASM("asm/levels", func_L39_006C5B60);

INCLUDE_ASM("asm/levels", func_L39_006C5CC8);
