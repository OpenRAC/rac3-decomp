#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_003A8050);

INCLUDE_ASM("asm/levels", func_L21_003A97E8);

INCLUDE_ASM("asm/levels", func_L21_003A9B20);

INCLUDE_ASM("asm/levels", func_L21_003A9E88);

/* localdecomp:start func_L21_003AA068 */
s32 func_L21_003AA068(void *arg0) {
    s32 var_v1;

    var_v1 = 1;
    if (!((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x30)) <= 0.0f)) {
        var_v1 = 0;
    }
    return var_v1;
}
/* localdecomp:end func_L21_003AA068 */

/* localdecomp:start func_L21_003AA090 */
s32 func_L21_003AA090(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 0x18;
}
/* localdecomp:end func_L21_003AA090 */

INCLUDE_ASM("asm/levels", func_L21_003AA0A0);

INCLUDE_ASM("asm/levels", func_L21_003AA0C0);

INCLUDE_ASM("asm/levels", func_L21_003AA108);

/* localdecomp:start func_L21_003AA160 */
void func_L01_004450F0(void *, s32, s32);

s32 func_L21_003AA160(void *arg0, s8 arg1) {
    u8 temp_v1;

    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301) = arg1;
    if (((*(u8 *)((u8 *)arg0 + 0x95)) == 7) || (temp_v1 = (*(u8 *)((u8 *)arg0 + 0x20)), (temp_v1 == 0x18)) || (temp_v1 == 0x19)) {
        return 0;
    }
    func_L01_004450F0(arg0, 1, 7);
    return 1;
}
/* localdecomp:end func_L21_003AA160 */

INCLUDE_ASM("asm/levels", func_L21_003AA1C0);

INCLUDE_ASM("asm/levels", func_L21_003AA258);

/* localdecomp:start func_L21_003AA290 */
void func_L21_003AA290(void *arg0, s16 arg1) {
    *(s16 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x304) = arg1;
}
/* localdecomp:end func_L21_003AA290 */

/* localdecomp:start func_L21_003AA2A0 */
void func_L21_003AA2A0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300) = arg1;
}
/* localdecomp:end func_L21_003AA2A0 */

/* localdecomp:start func_L21_003AA2B0 */
s8 func_L21_003AA2B0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300));
}
/* localdecomp:end func_L21_003AA2B0 */

/* localdecomp:start func_L21_003AA2C0 */
void func_L21_003AA2C0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301) = arg1;
}
/* localdecomp:end func_L21_003AA2C0 */

/* localdecomp:start func_L21_003AA2D0 */
s8 func_L21_003AA2D0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301));
}
/* localdecomp:end func_L21_003AA2D0 */

/* localdecomp:start func_L21_003AA2E0 */
void func_L21_003AA2E0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302) = arg1;
}
/* localdecomp:end func_L21_003AA2E0 */

/* localdecomp:start func_L21_003AA2F0 */
s8 func_L21_003AA2F0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302));
}
/* localdecomp:end func_L21_003AA2F0 */

/* localdecomp:start func_L21_003AA300 */
s32 func_L21_003AA300(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 9;
}
/* localdecomp:end func_L21_003AA300 */

/* localdecomp:start func_L21_003AA310 */
s32 func_L21_003AA310(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x95)) - 7) < 2U;
}
/* localdecomp:end func_L21_003AA310 */
