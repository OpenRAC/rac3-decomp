#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003BAC00);

INCLUDE_ASM("asm/levels", func_L07_003BAC58);

INCLUDE_ASM("asm/levels", func_L07_003BADA8);

INCLUDE_ASM("asm/levels", func_L07_003BAEA0);

INCLUDE_ASM("asm/levels", func_L07_003BAF28);

INCLUDE_ASM("asm/levels", func_L07_003BB038);

/* localdecomp:start func_L07_003BB148 */
void func_003A4F28(u32);
int func_L01_004AA710(int, int);

void func_L07_003BB148(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_L01_004AA710(arg0, var_s0) != 0) {
            func_003A4F28(var_s0);
        }
        var_s0 += 1;
    } while (var_s0 < 0x34);
}
/* localdecomp:end func_L07_003BB148 */

INCLUDE_ASM("asm/levels", func_L07_003BB1A8);

INCLUDE_ASM("asm/levels", func_L07_003BB1F0);

INCLUDE_ASM("asm/levels", func_L07_003BB2A8);

INCLUDE_ASM("asm/levels", func_L07_003BB328);

INCLUDE_ASM("asm/levels", func_L07_003BB360);

INCLUDE_ASM("asm/levels", func_L07_003BB410);

/* localdecomp:start func_L07_003BB768 */
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003BB768(s32 arg0) {
    func_L07_003A2380(func_00382498(0x62, 0x69) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_003BB768 */

INCLUDE_ASM("asm/levels", func_L07_003BB7A8);

INCLUDE_ASM("asm/levels", func_L07_003BB840);

INCLUDE_ASM("asm/levels", func_L07_003BBAC8);

INCLUDE_ASM("asm/levels", func_L07_003BBBA8);

INCLUDE_ASM("asm/levels", func_L07_003BC4D8);

INCLUDE_ASM("asm/levels", func_L07_003BC6C0);

INCLUDE_ASM("asm/levels", func_L07_003BCB10);

INCLUDE_ASM("asm/levels", func_L07_003BCBE8);

INCLUDE_ASM("asm/levels", func_L07_003BCC30);

/* localdecomp:start func_L07_003BCC88 */
void func_L07_003BCB10(void *, s32);

void func_L07_003BCC88(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x294)) != -1) {
        func_L07_003BCB10(arg0, 9);
        return;
    }
    func_L07_003BCB10(arg0, 0xA);
}
/* localdecomp:end func_L07_003BCC88 */

INCLUDE_ASM("asm/levels", func_L07_003BCCD0);

/* localdecomp:start func_L07_003BCD80 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003BB038(s32);
void func_L07_003BB1F0();

void func_L07_003BCD80(s32 arg0) {
    func_L07_003BB1F0();
    func_L07_003BB038(arg0);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003BCD80 */
