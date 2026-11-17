/* Level 5. File L05_00328BF8.c (@ps2as). check.py: 106 diff. The logic and the D_001BBC40/D_001D545C reads are retail's; the loop is not: retail hoists s+0xE0 and &D_001BBC40 ($s5, $fp) but recomputes s+0x110 and s+0x100 in each iteration into saved registers, and uses nine saved registers in all; this C hoists differently and uses seven. First draft, not tuned. */
#include "common.h"

extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0043B510(s32);
extern u8 D_001A4C60[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;

void func_L05_003298C0(s32 a0, u8 *s) {
    s32 i;
    s32 j;
    s32 t;
    for (i = 0; i < 4; i++) {
        if (((s32 *)(s + 0xE0))[i] == -1) {
            continue;
        }
        t = ((s32 *)(s + 0x110))[i];
        if (t == -1 || (D_001BBC40[t + D_001D545C * 16] & 0x80) == 0) {
            if (((s32 *)(s + 0x100))[i] == -1) {
                continue;
            }
            if (func_00382380(D_001A4C60, ((s32 *)(s + 0x100))[i], 0) == 0) {
                continue;
            }
        }
        for (j = 0; j < 4; j++) {
            if (((s32 *)(s + 0xE0))[i] == ((s32 *)(s + 0x90))[j]) {
                break;
            }
        }
        ((s32 *)(s + 0xA0))[j] = ((s32 *)(s + 0xF0))[i];
        ((s32 *)(s + 0xD0))[j] = ((s32 *)(s + 0x120))[i];
        ((s32 *)(s + 0xE0))[i] = -1;
        if (((s32 *)(s + 0x100))[i] != -1 && (D_001BBC40[((s32 *)(s + 0x110))[i] + D_001D545C * 16] & 0x80) == 0) {
            func_L01_0043B510(((s32 *)(s + 0x110))[i]);
        }
    }
}
