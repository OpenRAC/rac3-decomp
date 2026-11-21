/* functional: high. Loops are plain for loops; retail used hand-rotated loops. 95 diffs. Callee prototypes use the file's s32 forms (pv passed as 32-bit address). */
#include "common.h"
#include "vu0.h"
extern s32 func_L01_00456500(void *, s32);
extern vu0_v4 D_L04_001E27C0;
extern u8 D_001A4C60[];

void func_L04_003C8E10(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_q q;
    s32 flag = 0;
    s32 i, e;

    a0[0x30] = 0xFF;
    if (*(s8 *)(pv + 0x7E) != 0) {
        q = *(vu0_q *)&D_L04_001E27C0;
    } else {
        q = *(vu0_q *)D_001A4C60;
    }
    if (a0[0x95] == 0) {
        for (i = 0; i < 4; i++) {
            e = *(s32 *)(pv + i * 4);
            if (e == -1) continue;
            if (func_L01_00456500(&q, e) != 0) {
                flag = 1;
                break;
            }
        }
    } else if (a0[0x95] == 1) {
        flag = 1;
    }
    if (flag != 0 ? a0[0xBC] != 0 : a0[0xBC] == 0) {
        if (a0[0x20] != 0) return;
    }
    a0[0xBC] = flag != 0;
    a0[0x20] = a0[0xBC] + 1;
    for (i = 0; i < 13; i++) {
        e = *(s32 *)(pv + 0x10 + i * 4);
        if (e != -1) func_L04_003C8DA0((s32)a0, (s32)pv, e, flag);
    }
    for (i = 0; i < 14; i++) {
        e = *(s32 *)(pv + 0x44 + i * 4);
        if (e != -1) func_L04_003C89E0(e, (s32)pv, flag);
    }
}
