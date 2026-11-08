#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006A29D0);

INCLUDE_ASM("asm/levels", func_L39_006A2A58);

LINKER_REMNANT("asm/levels", func_L39_006A2F38);

INCLUDE_ASM("asm/levels", func_L39_006A2F50);

LINKER_REMNANT("asm/levels", func_L39_006A3660);

/* localdecomp:start func_L39_006A3668 */
extern u8 D_L39_0047D858[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006A3668(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D858;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006A3668 */

INCLUDE_ASM("asm/levels", func_L39_006A3690);

/* localdecomp:start func_L39_006A3A80 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006A3A80(void *);

extern void func_L39_0067F168();
void func_L39_006A3A80(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006A3A80 */

INCLUDE_ASM("asm/levels", func_L39_006A3AB0);
