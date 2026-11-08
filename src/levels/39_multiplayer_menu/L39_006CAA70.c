#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006CAA70);

INCLUDE_ASM("asm/levels", func_L39_006CAA98);

INCLUDE_ASM("asm/levels", func_L39_006CAAE8);

INCLUDE_ASM("asm/levels", func_L39_006CAC48);

INCLUDE_ASM("asm/levels", func_L39_006CAD88);

LINKER_REMNANT("asm/levels", func_L39_006CAEC0);

INCLUDE_ASM("asm/levels", func_L39_006CAEC8);

LINKER_REMNANT("asm/levels", func_L39_006CB078);

/* localdecomp:start func_L39_006CB080 */
extern u8 D_L39_0047EEC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CB080(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EEC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CB080 */

INCLUDE_ASM("asm/levels", func_L39_006CB0A8);

/* localdecomp:start func_L39_006CB230 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006CB230(void *);

extern void func_L39_0067F168();
void func_L39_006CB230(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006CB230 */

INCLUDE_ASM("asm/levels", func_L39_006CB260);
