#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006B6A80);

INCLUDE_ASM("asm/levels", func_L39_006B6AA8);

/* localdecomp:start func_L39_006B6AD0 */
s32 func_L39_006B6AD0(s32 arg0) {
    return arg0 + 0x2A8;
}
/* localdecomp:end func_L39_006B6AD0 */

INCLUDE_ASM("asm/levels", func_L39_006B6AD8);

/* localdecomp:start func_L39_006B6BC0 */
s32 func_L39_006B6BC0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x318));
}
/* localdecomp:end func_L39_006B6BC0 */

LINKER_REMNANT("asm/levels", func_L39_006B6BC8);

/* localdecomp:start func_L39_006B6BD0 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6BD0(void) {
    func_0038CC88(D_001FC6B0, D_L39_0037C848, 0xF80);
}
/* localdecomp:end func_L39_006B6BD0 */

/* localdecomp:start func_L39_006B6C00 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6C00(void) {
    func_0038CC88(D_L39_0037C848, D_001FC6B0, 0xF80);
}
/* localdecomp:end func_L39_006B6C00 */

INCLUDE_ASM("asm/levels", func_L39_006B6C30);

INCLUDE_ASM("asm/levels", func_L39_006B6C48);

INCLUDE_ASM("asm/levels", func_L39_006B6CC8);

LINKER_REMNANT("asm/levels", func_L39_006B7180);

INCLUDE_ASM("asm/levels", func_L39_006B7188);

LINKER_REMNANT("asm/levels", func_L39_006B71B0);

INCLUDE_ASM("asm/levels", func_L39_006B71B8);

INCLUDE_ASM("asm/levels", func_L39_006B72B0);

INCLUDE_ASM("asm/levels", func_L39_006B7340);

INCLUDE_ASM("asm/levels", func_L39_006B7410);

INCLUDE_ASM("asm/levels", func_L39_006B7490);

INCLUDE_ASM("asm/levels", func_L39_006B7520);

LINKER_REMNANT("asm/levels", func_L39_006B7650);

INCLUDE_ASM("asm/levels", func_L39_006B7658);

LINKER_REMNANT("asm/levels", func_L39_006B7830);

INCLUDE_ASM("asm/levels", func_L39_006B7838);

INCLUDE_ASM("asm/levels", func_L39_006B78F8);

INCLUDE_ASM("asm/levels", func_L39_006B7958);
