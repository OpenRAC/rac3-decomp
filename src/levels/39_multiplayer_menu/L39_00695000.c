#include "common.h"

/* localdecomp:start func_L39_00695000 */
extern u8 D_L39_0047CB68[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00695000(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047CB68;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_00695000 */

INCLUDE_ASM("asm/levels", func_L39_00695028);

/* localdecomp:start func_L39_00695198 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00695198(void *);

extern void func_L39_0067F168();
void func_L39_00695198(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00695198 */

INCLUDE_ASM("asm/levels", func_L39_006951C8);
