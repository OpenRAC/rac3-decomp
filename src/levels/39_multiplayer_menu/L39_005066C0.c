#include "common.h"

/* localdecomp:start func_L39_005066C0 */
void func_L39_0050A5E8(s32, s32);

void func_L39_005066C0(s32 **arg0, s32 **arg1) {
    func_L39_0050A5E8(**arg0, **arg1);
}
/* localdecomp:end func_L39_005066C0 */

/* localdecomp:start func_L39_005066E8 */
s32 func_L39_005066E8(void **arg0, void **arg1) {
    return (*(s32 *)((u8 *)(*arg0) + 0xC)) - (*(s32 *)((u8 *)(*arg1) + 0xC));
}
/* localdecomp:end func_L39_005066E8 */

INCLUDE_ASM("asm/levels", func_L39_00506700);

INCLUDE_ASM("asm/levels", func_L39_005067F0);

/* localdecomp:start func_L39_00506850 */
s32 func_L39_00506850(void *arg0, s32 *arg1) {
    *arg1 = *(s32 *)((u8 *)arg0 + 0x74);
    return 0;
}
/* localdecomp:end func_L39_00506850 */

INCLUDE_ASM("asm/levels", func_L39_00506860);

INCLUDE_ASM("asm/levels", func_L39_00506958);

INCLUDE_ASM("asm/levels", func_L39_00506A80);

INCLUDE_ASM("asm/levels", func_L39_00506C80);

INCLUDE_ASM("asm/levels", func_L39_00506D78);

INCLUDE_ASM("asm/levels", func_L39_00506F90);

INCLUDE_ASM("asm/levels", func_L39_005070D0);

INCLUDE_ASM("asm/levels", func_L39_00507128);

INCLUDE_ASM("asm/levels", func_L39_005071B0);

INCLUDE_ASM("asm/levels", func_L39_005071C8);

INCLUDE_ASM("asm/levels", func_L39_00507208);

INCLUDE_ASM("asm/levels", func_L39_00507238);

INCLUDE_ASM("asm/levels", func_L39_00507268);

INCLUDE_ASM("asm/levels", func_L39_00507378);

INCLUDE_ASM("asm/levels", func_L39_00507408);

INCLUDE_ASM("asm/levels", func_L39_00507420);

INCLUDE_ASM("asm/levels", func_L39_00507460);

INCLUDE_ASM("asm/levels", func_L39_00507490);

INCLUDE_ASM("asm/levels", func_L39_005074C0);

/* localdecomp:start func_L39_00507500 */
void func_L39_00507500(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x28) = 1;
}
/* localdecomp:end func_L39_00507500 */

INCLUDE_ASM("asm/levels", func_L39_00507510);

INCLUDE_ASM("asm/levels", func_L39_005075D0);

/* localdecomp:start func_L39_005076E0 */
extern u8 D_L39_00507B18[];

void func_L39_005076E0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    (*(void **)arg0) = D_L39_00507B18;
}
/* localdecomp:end func_L39_005076E0 */

INCLUDE_ASM("asm/levels", func_L39_005076F8);

INCLUDE_ASM("asm/levels", func_L39_005077B8);

INCLUDE_ASM("asm/levels", func_L39_00507878);

INCLUDE_ASM("asm/levels", func_L39_00507930);

INCLUDE_ASM("asm/levels", func_L39_005079E8);

INCLUDE_ASM("asm/levels", func_L39_00507A80);

INCLUDE_ASM("asm/levels", func_L39_00507B18);

INCLUDE_ASM("asm/levels", func_L39_00507B3C);

INCLUDE_ASM("asm/levels", func_L39_00507B48);

INCLUDE_ASM("asm/levels", func_L39_00507BFC);

INCLUDE_ASM("asm/levels", func_L39_00507C20);

INCLUDE_ASM("asm/levels", func_L39_00507C80);

INCLUDE_ASM("asm/levels", func_L39_00507CF4);

INCLUDE_ASM("asm/levels", func_L39_00507D00);

LINKER_REMNANT("asm/levels", func_L39_00507DC8);

INCLUDE_ASM("asm/levels", func_L39_00507DD0);

LINKER_REMNANT("asm/levels", func_L39_00507E20);

INCLUDE_ASM("asm/levels", func_L39_00507E28);

INCLUDE_ASM("asm/levels", func_L39_00507EFC);

INCLUDE_ASM("asm/levels", func_L39_00507F5C);

INCLUDE_ASM("asm/levels", func_L39_00507F68);

INCLUDE_ASM("asm/levels", func_L39_0050803C);

INCLUDE_ASM("asm/levels", func_L39_00508080);

LINKER_REMNANT("asm/levels", func_L39_005080B0);

INCLUDE_ASM("asm/levels", func_L39_005080B8);

INCLUDE_ASM("asm/levels", func_L39_00508128);

INCLUDE_ASM("asm/levels", func_L39_00508278);

INCLUDE_ASM("asm/levels", func_L39_00508340);

INCLUDE_ASM("asm/levels", func_L39_00508388);

INCLUDE_ASM("asm/levels", func_L39_005083E0);

INCLUDE_ASM("asm/levels", func_L39_005083F8);

INCLUDE_ASM("asm/levels", func_L39_00508410);

/* localdecomp:start func_L39_00508448 */
s32 func_L39_00508448(s32 *arg0, s32 *arg1) {
    *arg1 = *arg0;
    return 0;
}
/* localdecomp:end func_L39_00508448 */

/* localdecomp:start func_L39_00508458 */
void func_L39_005094F8(void);

s32 func_L39_00508458(void *arg0) {
    *(void **)((u8 *)arg0 + 8) = func_L39_005094F8;
    return 0;
}
/* localdecomp:end func_L39_00508458 */

INCLUDE_ASM("asm/levels", func_L39_00508470);

INCLUDE_ASM("asm/levels", func_L39_005084A8);

INCLUDE_ASM("asm/levels", func_L39_00508540);

INCLUDE_ASM("asm/levels", func_L39_005085B0);

INCLUDE_ASM("asm/levels", func_L39_00508620);

INCLUDE_ASM("asm/levels", func_L39_00508684);

INCLUDE_ASM("asm/levels", func_L39_00508758);

INCLUDE_ASM("asm/levels", func_L39_005088D0);
