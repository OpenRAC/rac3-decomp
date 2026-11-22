/* Level 4 (Marcadia), file L04_003C89E0.c (@ps2as). check.py: 38 aligned differences. gcc turns `else if (m[0x95] == 1) on = 1;` into xori/sltiu where retail keeps a branch with `on = 0` in its delay slot (if/else, switch and a nested if tried), and the moby pointer and the loop counter take each other's saved registers (retail: moby in $s1, counter in $s2). Stopped per AGENTS.md. */
#include "common.h"

/* localdecomp:start func_L04_003C8E10 */
typedef int vu0_q_003C8E10 __attribute__((mode(TI)));
extern vu0_q_003C8E10 D_L04_001E27C0;
extern vu0_q_003C8E10 D_001A4C60_003C8E10 __asm__("D_001A4C60");
extern s32 func_L01_00456500(void *, s32);

void func_L04_003C8E10(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 on = 0;
    s32 i;
    s32 *p;
    s32 *q;
    vu0_q_003C8E10 pos;

    m[0x30] = 0xFF;
    pos = *(*(s8 *)(v + 0x7E) != 0 ? &D_L04_001E27C0 : &D_001A4C60_003C8E10);
    if (m[0x95] == 0) {
        for (i = 0; i < 4; i++) {
            if (((s32 *)v)[i] != -1 && func_L01_00456500(&pos, ((s32 *)v)[i]) != 0) {
                on = 1;
                break;
            }
        }
    } else if (m[0x95] == 1) {
        on = 1;
    }
    if (on) {
        if (m[0xBC] != 0 && m[0x20] != 0) {
            return;
        }
    } else {
        if (m[0xBC] == 0 && m[0x20] != 0) {
            return;
        }
    }
    if (on) {
        m[0xBC] = 1;
    } else {
        m[0xBC] = 0;
    }
    q = (s32 *)(v + 0x44);
    p = (s32 *)(v + 0x10);
    m[0x20] = m[0xBC] + 1;
    for (i = 0; i < 13; i++) {
        if (p[i] != -1) {
            func_L04_003C8DA0((s32)m, (s32)v, p[i], on);
        }
    }
    for (i = 0; i < 14; i++) {
        if (q[i] != -1) {
            func_L04_003C89E0(q[i], (s32)v, on);
        }
    }
}
/* localdecomp:end func_L04_003C8E10 */
