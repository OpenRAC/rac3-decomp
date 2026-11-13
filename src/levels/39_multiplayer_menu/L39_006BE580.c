#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_00688400(void *, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);

/* localdecomp:start func_L39_006BE580 */
void func_L39_006BE580(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}
/* localdecomp:end func_L39_006BE580 */

/* localdecomp:start func_L39_006BE598 */
void func_L39_006BE598(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}
/* localdecomp:end func_L39_006BE598 */

/* localdecomp:start func_L39_006BE5B0 */
typedef struct S_006BE5B0 {
    s32 w[0x23];
} S_006BE5B0;

void func_L39_006BE5B0(S_006BE5B0 *arg0, S_006BE5B0 *arg1) {
    S_006BE5B0 temp;

    temp = *arg0;
    *arg0 = *arg1;
    *arg1 = temp;
}
/* localdecomp:end func_L39_006BE5B0 */

LINKER_REMNANT("asm/levels", func_L39_006BE7C8);

INCLUDE_ASM("asm/levels", func_L39_006BE7E0);

LINKER_REMNANT("asm/levels", func_L39_006C0F08);

/* localdecomp:start func_L39_006C0F10 */
extern u8 D_L39_0047E998[];

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006C0F10(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E998;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006C0F10 */
