/* Level 4. File L04_00362CE0.c (@ps2as). check.py: 25 diff. Retail fills the delay slot of the first branch (func_L01_004561B8() == 0) from its target with a beql (lw $s0, 0x368($s3)); gcc puts the loop's constant 6 there from the fall-through instead, which shifts the code up to the loop by one word. while/for/goto/else forms of the loop and of the test change nothing. The row address (row = D + idx * 0x30, a pointer local) and the $gp float table (section(".sdata") plus a .extern hint) are retail's. */
#include "common.h"

extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L04_00361948(u8 *, u8 *, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern s32 func_00382468(s32);
__asm__(".extern D_L04_001DD6E8, 4");
extern f32 D_L04_001DD6E8[] __attribute__((section(".sdata")));
extern u8 *D_L04_001DFA4C;

s32 func_L04_00365438(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 i;
    u8 *row;
    if (func_L01_004561B8(a0) != 0) {
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, 0, (func_00382498(4, 10) * 5 + 2) / 6);
        }
        *(s32 *)(pv + 0x368) = -1;
    }
    for (i = *(s32 *)(pv + 0x368); i < 4; i++) {
        if (func_L01_0044E1B8(a0, D_L04_001DD6E8[i]) != 0 && a0[0x42] == 6) {
            *(s32 *)(pv + 0x368) = i;
            func_L04_00361948(a0, pv, i, 4);
        }
    }
    if (a0[0x60] & 2) {
        if (a0[0x21] != 0xFF) {
            func_L01_00445BE0(a0[0x21], 0);
        }
        if (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_004450F0(a0, 10, -1);
        }
        if (a0[0x95] == 4) {
            func_L01_004450F0(a0, 10, -1);
        }
        if (func_00382468(3) != 0 || *(s32 *)(pv + 0x38C) == -1) {
            func_L01_004450F0(a0, 0x11, -1);
        }
        return 2;
    }
    return 0;
}
