/* functional: medium. check.py at level_06: 71 diffs, code shape only (retail tests the current sequence with separate beq for 0x15/0x14, draft uses a switch); logic per the draft's notes. */
#include "vu0.h"
#include "common.h"
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L06_00351A68(u8 *a0, u8 *a1, s32 seq) {
    f32 len;
    f32 t;
    u8 *s;
    s32 key;

    if (a0[0x43] == seq) {
        return;
    }
    switch (a0[0x43]) {
    case 5:
        len = 40.0f;
        break;
    case 0x15:
    case 0x14:
        len = 50.0f;
        break;
    default:
        func_003C3A10(a0, seq, 0, 10);
        func_003C3A10(*(u8 **)(a1 + 0x260), seq, 0, 10);
        return;
    }
    t = a0[0x41] / len;
    if (seq == 5) {
        t = t * 40.0f;
        s = *(u8 **)(*(u8 **)(a0 + 0x24) + 0x5C);
    } else if (seq == 0x15) {
        t = t * 50.0f;
        s = *(u8 **)(*(u8 **)(a0 + 0x24) + 0x9C);
    } else {
        t = t * 50.0f;
        s = *(u8 **)(*(u8 **)(a0 + 0x24) + 0x98);
    }
    key = ((s32)t + 1) % s[0x10];
    func_003C3A10(a0, seq, key, 10);
    func_003C3A10(*(u8 **)(a1 + 0x260), seq, key, 10);
}
