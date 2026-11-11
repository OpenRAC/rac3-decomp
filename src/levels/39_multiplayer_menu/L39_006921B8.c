#include "common.h"

/* localdecomp:start func_L39_006921B8 */
extern u8 D_L39_0047C968[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006921B8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C968;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006921B8 */

INCLUDE_ASM("asm/levels", func_L39_006921E0);

/* localdecomp:start func_L39_006923F0 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006923F0(void *);

extern void func_L39_0067F168();
void func_L39_006923F0(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006923F0 */

INCLUDE_ASM("asm/levels", func_L39_00692420);
