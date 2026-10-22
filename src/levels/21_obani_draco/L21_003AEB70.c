#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_003AEB70);

INCLUDE_ASM("asm/levels", func_L21_003AF758);

INCLUDE_ASM("asm/levels", func_L21_003AF988);

INCLUDE_ASM("asm/levels", func_L21_003AFBA8);

INCLUDE_ASM("asm/levels", func_L21_003AFCF0);

INCLUDE_ASM("asm/levels", func_L21_003AFED0);

INCLUDE_ASM("asm/levels", func_L21_003AFEF0);

/* localdecomp:start func_L21_003AFF40 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003AFF40(void *arg0) {
    if (((*(u8 *)((u8 *)arg0 + 0x95)) != 1) && ((*(u8 *)((u8 *)arg0 + 0x20)) != 9)) {
        func_L01_004450F0((s32) arg0, 3, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L21_003AFF40 */

INCLUDE_ASM("asm/levels", func_L21_003AFF88);

INCLUDE_ASM("asm/levels", func_L21_003AFFE0);

INCLUDE_ASM("asm/levels", func_L21_003B0068);

/* localdecomp:start func_L21_003B00A0 */
void func_L21_003B00A0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300) = arg1;
}
/* localdecomp:end func_L21_003B00A0 */

/* localdecomp:start func_L21_003B00B0 */
s8 func_L21_003B00B0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300));
}
/* localdecomp:end func_L21_003B00B0 */

/* localdecomp:start func_L21_003B00C0 */
void func_L21_003B00C0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301) = arg1;
}
/* localdecomp:end func_L21_003B00C0 */

/* localdecomp:start func_L21_003B00D0 */
s8 func_L21_003B00D0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301));
}
/* localdecomp:end func_L21_003B00D0 */

/* localdecomp:start func_L21_003B00E0 */
void func_L21_003B00E0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302) = arg1;
}
/* localdecomp:end func_L21_003B00E0 */

/* localdecomp:start func_L21_003B00F0 */
s8 func_L21_003B00F0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302));
}
/* localdecomp:end func_L21_003B00F0 */

/* localdecomp:start func_L21_003B0100 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003B0100(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x95)) == 4) {
        if ((*(u8 *)((u8 *)arg0 + 0x20)) == 9) {
            func_L01_004450F0((s32) arg0, 1, -1);
        }
    }
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 4;
}
/* localdecomp:end func_L21_003B0100 */

/* localdecomp:start func_L21_003B0158 */
s32 func_L21_003B0158(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 3;
}
/* localdecomp:end func_L21_003B0158 */

/* localdecomp:start func_L21_003B0168 */
s32 func_L21_003B0168(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
}
/* localdecomp:end func_L21_003B0168 */

/* localdecomp:start func_L21_003B0178 */
s32 func_L21_003B0178(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 2;
}
/* localdecomp:end func_L21_003B0178 */

/* localdecomp:start func_L21_003B0188 */
s32 func_L21_003B0188(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 0;
}
/* localdecomp:end func_L21_003B0188 */
