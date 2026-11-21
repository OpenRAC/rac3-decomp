/* Level 4 (Marcadia), file L04_003C89E0.c (@ps2as). Promises fleet near miss (2026-11-20), reworked 2026-11-21 (task 2784):
 * check.py at level 04: 12 diff (7 aligned; the 2026-11-20 draft: 75 diff, 33 aligned).
 * Found: the `m[0x95]` test is `if (m[0x95] == 0) { loop } else { switch (m[0x95]) { case 1: on = 1; break; } }`
 * (the if/else-if form puts the case-1 block in the wrong place), and each loop has its own counter (j, i, k),
 * which gives retail's registers (moby in $s1, counter in $s2).
 * Left: retail tests `m[0x95] == 1` with a branch (`bne $v1, $v0` on the value already loaded, `move $s4, $zero`
 * in the delay slot, `li $v0, 1` hoisted into the earlier bnez's delay slot); gcc reloads m[0x95] and emits
 * xori/sltiu, or movz with a local copy of m[0x95]. Tried: if/else-if, explicit `on = 0` before the test, `on = (x == 1)`,
 * a top-level switch (case orders, with and without default), a u8/s32 local for m[0x95], on as u8/s8/s16/u16/u32.
 * Stopped per AGENTS.md. */
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
    s32 j;
    s32 k;
    s32 *p;
    s32 *q;
    vu0_q_003C8E10 pos;

    m[0x30] = 0xFF;
    pos = *(*(s8 *)(v + 0x7E) != 0 ? &D_L04_001E27C0 : &D_001A4C60_003C8E10);
    if (m[0x95] == 0) {
        for (j = 0; j < 4; j++) {
            if (((s32 *)v)[j] != -1 && func_L01_00456500(&pos, ((s32 *)v)[j]) != 0) {
                on = 1;
                break;
            }
        }
    } else {
        switch (m[0x95]) {
        case 1:
            on = 1;
            break;
        }
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
    for (k = 0; k < 14; k++) {
        if (q[k] != -1) {
            func_L04_003C89E0(q[k], (s32)v, on);
        }
    }
}
/* localdecomp:end func_L04_003C8E10 */
