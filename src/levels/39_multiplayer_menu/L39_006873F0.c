#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006873F0);

INCLUDE_ASM("asm/levels", func_L39_00687450);

INCLUDE_ASM("asm/levels", func_L39_00687508);

INCLUDE_ASM("asm/levels", func_L39_00687640);

INCLUDE_ASM("asm/levels", func_L39_006876A0);

/* localdecomp:start func_L39_00687750 */
void func_L39_00687268(void *, s32);
void func_L39_0069F5E8(s32);
void func_L39_0069F618(s32, s32);

void func_L39_00687750(void *arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x104);
    if (temp_s0 != 0) {
        func_L39_0069F5E8(temp_s0);
        func_L39_00687268(arg0, 0x28);
        func_L39_0069F618(temp_s0, arg1);
    }
}
/* localdecomp:end func_L39_00687750 */

INCLUDE_ASM("asm/levels", func_L39_006877B0);

INCLUDE_ASM("asm/levels", func_L39_00687800);

/* localdecomp:start func_L39_006878A0 */
void func_L39_00687268(void *, s32);
void func_L39_0069EAA8(void *);

s32 func_L39_006878A0(void *arg0) {
    s32 var_v0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x108);
    var_v0 = -1;
    if (temp_s0 != 0) {
        func_L39_0069EAA8(temp_s0);
        func_L39_00687268(arg0, 0x29);
        var_v0 = *(s32 *)((u8 *)temp_s0 + 0x2A8);
    }
    return var_v0;
}
/* localdecomp:end func_L39_006878A0 */

INCLUDE_ASM("asm/levels", func_L39_006878F0);

INCLUDE_ASM("asm/levels", func_L39_00687968);

INCLUDE_ASM("asm/levels", func_L39_006879E0);

INCLUDE_ASM("asm/levels", func_L39_00688108);

/* localdecomp:start func_L39_00688340 */
void func_L39_005F1718();
s32 func_L39_005F3548();

s32 func_L39_00688340(void) {
    s32 temp_s0;

    temp_s0 = func_L39_005F3548();
    func_L39_005F1718();
    func_L39_005F1718();
    return temp_s0;
}
/* localdecomp:end func_L39_00688340 */

LINKER_REMNANT("asm/levels", func_L39_00688378);

INCLUDE_ASM("asm/levels", func_L39_00688388);
