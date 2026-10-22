#include "common.h"

/* localdecomp:start func_L03_003AF410 */
s32 func_L03_003AF410(void *arg0) {
    s32 temp_a0;

    temp_a0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x13C);
    switch (temp_a0) {                              /* irregular */
    case 4:
        return 4;
    case 6:
        return 3;
    default:
        return -1;
    }
}
/* localdecomp:end func_L03_003AF410 */

INCLUDE_ASM("asm/levels", func_L03_003AF450);

INCLUDE_ASM("asm/levels", func_L03_003AF7F0);

INCLUDE_ASM("asm/levels", func_L03_003AF848);

/* localdecomp:start func_L03_003AFC08 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC08(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 6, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 6;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFC08 */

/* localdecomp:start func_L03_003AFC50 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC50(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 4, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 4;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFC50 */

/* localdecomp:start func_L03_003AFC98 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC98(s32 arg0) {
    func_L01_00445130(arg0, 8, -1);
}
/* localdecomp:end func_L03_003AFC98 */

/* localdecomp:start func_L03_003AFCB8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFCB8(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003AFCB8 */

/* localdecomp:start func_L03_003AFCD8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFCD8(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 7, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 7;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFCD8 */

INCLUDE_ASM("asm/levels", func_L03_003AFD20);

INCLUDE_ASM("asm/levels", func_L03_003AFD48);

INCLUDE_ASM("asm/levels", func_L03_003AFE60);

INCLUDE_ASM("asm/levels", func_L03_003AFF18);

INCLUDE_ASM("asm/levels", func_L03_003AFF68);

INCLUDE_ASM("asm/levels", func_L03_003AFFB8);

INCLUDE_ASM("asm/levels", func_L03_003B0088);

INCLUDE_ASM("asm/levels", func_L03_003B0140);

INCLUDE_ASM("asm/levels", func_L03_003B0238);

INCLUDE_ASM("asm/levels", func_L03_003B0290);

INCLUDE_ASM("asm/levels", func_L03_003B05B0);

/* localdecomp:start func_L03_003B05F0 */
s32 func_00382468(s32);

void func_L03_003B05F0(s32 arg0, s32 arg1) {
    s32 *temp_s0_2;
    s32 *temp_v0;
    s32 temp_a0;
    s32 temp_s0;
    s32 var_s1;

    if (arg1 > 0) {
        var_s1 = arg1;
        do {
            var_s1 -= 1;
            temp_s0 = func_00382468(arg1);
            temp_v0 = (func_00382468(arg1) * 4) + arg0;
            temp_s0_2 = (temp_s0 * 4) + arg0;
            temp_a0 = *temp_s0_2;
            *temp_s0_2 = *temp_v0;
            *temp_v0 = temp_a0;
        } while (var_s1 != 0);
    }
}
/* localdecomp:end func_L03_003B05F0 */

INCLUDE_ASM("asm/levels", func_L03_003B0670);

INCLUDE_ASM("asm/levels", func_L03_003B06F0);

INCLUDE_ASM("asm/levels", func_L03_003B0760);

INCLUDE_ASM("asm/levels", func_L03_003B0810);

/* localdecomp:start func_L03_003B0ED8 */
extern s32 D_L03_001DE858;

void func_L03_003B0ED8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_L03_001DE858 |= 1 << arg0;
        return;
    }
    D_L03_001DE858 &= ~(1 << arg0);
}
/* localdecomp:end func_L03_003B0ED8 */
