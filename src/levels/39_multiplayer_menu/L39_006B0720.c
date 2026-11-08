#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_006B0720);

INCLUDE_ASM("asm/levels", func_L39_006B0728);

/* localdecomp:start func_L39_006B0998 */
extern u8 D_L39_0047E0A0[];
void func_L39_00688400(void *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B0998(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E0A0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B0998 */

INCLUDE_ASM("asm/levels", func_L39_006B09C0);

INCLUDE_ASM("asm/levels", func_L39_006B0C50);

INCLUDE_ASM("asm/levels", func_L39_006B0C90);

INCLUDE_ASM("asm/levels", func_L39_006B0FA8);

LINKER_REMNANT("asm/levels", func_L39_006B1078);

INCLUDE_ASM("asm/levels", func_L39_006B1080);

LINKER_REMNANT("asm/levels", func_L39_006B15A0);

/* localdecomp:start func_L39_006B15A8 */
void func_L39_00688400(void *, s32);
void func_L39_006CC158(void *, s32);
extern u8 D_L39_0047E210[];

void func_L39_006B15A8(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047E210;
    func_L39_006CC158(arg0 + 0x2B8, 2);
    func_L39_00688400(arg0, arg1);
}
/* localdecomp:end func_L39_006B15A8 */

INCLUDE_ASM("asm/levels", func_L39_006B15F8);

/* localdecomp:start func_L39_006B19B0 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B19B0(void *);

extern void func_L39_0067F168();
void func_L39_006B19B0(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B19B0 */

INCLUDE_ASM("asm/levels", func_L39_006B19E0);
