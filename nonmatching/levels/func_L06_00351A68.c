/* PAL animation-pair near miss: 67 instruction words differ with the owning
 * file flags. The inline pair helper improves the 71-word draft; range folding,
 * the redundant sequence check and register allocation still differ.
 * Not linked and not counted as a match.
 */
#include "vu0.h"
#include "common.h"
extern void func_003C3A10(u8 *, s32, s32, s32);
static __inline__ void change_pair(u8 *a, u8 *b, s32 sequence, s32 key) {
    if (a[0x43] != sequence) {
        func_003C3A10(a, sequence, key, 10);
        func_003C3A10(*(u8 **)(b + 0x260), sequence, key, 10);
    }
}
void func_L06_00351A68(u8 *a0, u8 *a1, s32 seq) {
    f32 len;
    f32 t;
    u8 *s;
    s32 key;

    if (a0[0x43] == seq) {
        return;
    }
    if (a0[0x43] == 5) {
        t = a0[0x41] / 40.0f;
    } else if (a0[0x43] == 0x15 || a0[0x43] == 0x14) {
        t = a0[0x41] / 50.0f;
    } else {
        change_pair(a0, a1, seq, 0);
        return;
    }
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
    change_pair(a0, a1, seq, key);
}
