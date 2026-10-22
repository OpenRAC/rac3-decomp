#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00332098);

INCLUDE_ASM("asm/levels", func_L07_00332230);

INCLUDE_ASM("asm/levels", func_L07_00332298);

INCLUDE_ASM("asm/levels", func_L07_003323F8);

INCLUDE_ASM("asm/levels", func_L07_003326D8);

INCLUDE_ASM("asm/levels", func_L07_00332848);

INCLUDE_ASM("asm/levels", func_L07_003328D0);

INCLUDE_ASM("asm/levels", func_L07_00332928);

INCLUDE_ASM("asm/levels", func_L07_00332958);

INCLUDE_ASM("asm/levels", func_L07_00332A90);

INCLUDE_ASM("asm/levels", func_L07_00332BE0);

INCLUDE_ASM("asm/levels", func_L07_00332CF0);

INCLUDE_ASM("asm/levels", func_L07_00332F90);

INCLUDE_ASM("asm/levels", func_L07_003330E8);

INCLUDE_ASM("asm/levels", func_L07_00333200);

INCLUDE_ASM("asm/levels", func_L07_003332B8);

INCLUDE_ASM("asm/levels", func_L07_00333310);

/* localdecomp:start func_L07_003333F8 */
void func_L07_003333F8(void *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f3;
    void *temp_a0;

    if (!(fparg0 <= fparg1)) {
        temp_a0 = *(void **)((u8 *)arg0 + 0x68);
        temp_f3 = fparg0 - fparg1;
        *(f32 *)((u8 *)temp_a0 + 0xC0) = (f32) ((*(f32 *)((u8 *)temp_a0 + 0xC0)) + temp_f3);
        *(f32 *)((u8 *)temp_a0 + 0xC4) = (f32) ((*(f32 *)((u8 *)temp_a0 + 0xC4)) + temp_f3);
        if (fparg1 <= 0.0f) {
            *(s32 *)((u8 *)temp_a0 + 0xC8) = (s32) ((*(s32 *)((u8 *)temp_a0 + 0xC8)) + 1);
            *(f32 *)((u8 *)temp_a0 + 0xCC) = (f32) ((*(f32 *)((u8 *)temp_a0 + 0xCC)) + 1.0f);
        }
    }
}
/* localdecomp:end func_L07_003333F8 */

/* localdecomp:start func_L07_00333460 */
extern u8 D_L07_002B0D40[];

s32 func_L07_00333460(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (arg0 * 0x10) + D_L07_002B0D40;
    if ((*(u8 *)((u8 *)temp_a0 + 0xC)) != 0) {
        if (arg1 == -1) {
            return 0;
        }
        return (*(s32 *)((u8 *)temp_a0 + 8)) + (arg1 * 0xC);
    }
    return (*(s32 *)((u8 *)temp_a0 + 8));
}
/* localdecomp:end func_L07_00333460 */

INCLUDE_ASM("asm/levels", func_L07_003334A8);

INCLUDE_ASM("asm/levels", func_L07_003337A8);

/* localdecomp:start func_L07_00333858 */
f32 func_L07_00333858(void *arg0) {
    return (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x98))) + 0x2C)) * (*(f32 *)((u8 *)arg0 + 0x2C)) * 0.0009765625f;
}
/* localdecomp:end func_L07_00333858 */

INCLUDE_ASM("asm/levels", func_L07_00333878);

INCLUDE_ASM("asm/levels", func_L07_003338C0);

INCLUDE_ASM("asm/levels", func_L07_00333918);

INCLUDE_ASM("asm/levels", func_L07_00333A18);

INCLUDE_ASM("asm/levels", func_L07_00333AB8);

INCLUDE_ASM("asm/levels", func_L07_00333B20);

/* localdecomp:start func_L07_00333B68 */
s32 func_L07_00333B68(void *arg0) {
    s16 temp_v1;

    temp_v1 = *(s16 *)((u8 *)arg0 + 0xAA);
    if ((temp_v1 == 0x19E7) || (temp_v1 == 0x1CF6)) {
        return (*(s32 *)((u8 *)arg0 + 0x68));
    }
    return 0;
}
/* localdecomp:end func_L07_00333B68 */

INCLUDE_ASM("asm/levels", func_L07_00333B90);

INCLUDE_ASM("asm/levels", func_L07_00333BF8);

INCLUDE_ASM("asm/levels", func_L07_00333C70);

INCLUDE_ASM("asm/levels", func_L07_00333CE0);

INCLUDE_ASM("asm/levels", func_L07_00333CF8);

INCLUDE_ASM("asm/levels", func_L07_00333D20);

INCLUDE_ASM("asm/levels", func_L07_00333D40);

INCLUDE_ASM("asm/levels", func_L07_00333D70);

INCLUDE_ASM("asm/levels", func_L07_00333DB8);
