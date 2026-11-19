/* functional: high. Character 'wait/idle' state tick: on entry (func_L01_004561B8) picks a random blend and resets the tracked index; scans 4 trigger distances from a table, may start state 6 helper; leaves to state 0xA/0x11 when flagged. Loop is a plain for; retail rotated it (67 diff). */
#include "common.h"
extern f32 D_L04_001DD6E8[];
__asm__(".extern D_L04_001DD6E8, 16");
extern s32 func_00382468(s32);

s32 func_L04_00365438(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    s32 i;
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
    if ((a0[0x60] & 2) == 0) {
        return 0;
    }
    if (a0[0x21] != 0xFF) {
        func_L01_00445BE0(a0[0x21], 0);
    }
    if (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
        func_L01_004450F0(a0, 0xA, -1);
    }
    if (a0[0x95] == 4) {
        func_L01_004450F0(a0, 0xA, -1);
    }
    if (func_00382468(3) != 0 || *(s32 *)(pv + 0x38C) == -1) {
        func_L01_004450F0(a0, 0x11, -1);
    }
    return 2;
}
