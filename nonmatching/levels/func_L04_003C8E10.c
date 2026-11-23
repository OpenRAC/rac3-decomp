/* Level 4 (Marcadia), file L04_003C89E0.c (@ps2as). Promises fleet near miss (2026-11-20), reworked 2026-11-21 (tasks 2784, 2796):
 * check.py at level 04: 11 diff (task 2784's form: 12 diff, 7 aligned; the 2026-11-20 draft: 75 diff, 33 aligned).
 * Found: `m[0x95]` read once into a u8 local, `if (x == 0) { loop } else if (x == 1) { on = x; } else { on = 0; }`
 * (task 2796; the case-1 layout and the saved registers as in task 2784's switch form), and each loop has its own
 * counter (j, i, k), which gives retail's registers (moby in $s1, counter in $s2).
 * Left, two things. (1) Retail tests `x == 1` with a branch (`li $v0, 1; bne $v1, $v0; move $s4, $zero; li $s4, 1`);
 * gcc's jump pass if-converts the arm: xori/sltiu when it assigns 1, movz when it assigns x (this form). Task 2796
 * showed the cause: with the conversion blocked (probe only: a dead `j = 0;` in the arm, which no form here may use)
 * the arm compiles to exactly retail's four instructions. (2) The `pos` copy: retail loads it into $v1 (`lq $v1;
 * sq $v1` before `lbu $v1, 0x95`), so reorg fills the bnez delay slot with the `li $v0, 1` of the else arm; here it
 * is $v0 and reorg moves the `sq` into that slot. Tried (2796): reading m[0x95] before the pos load or before the
 * 0xFF store (53 to 83 diff), a pointer local or if/else for the source address, a TI temporary, a 4-float struct
 * type for pos; a top-level switch with `default: on = 0` keeps the branch but lays the cases out wrong (22 to 92
 * diff over all 6 case orders, with on initialised or not); a 64-bit `on` doesn't compile ("unsupported wide integer
 * operation"). Earlier (2784): if/else-if, explicit `on = 0` before the test, `on = (x == 1)`, a top-level switch
 * without default, a u8/s32 local, on as u8/s8/s16/u16/u32. Stopped per AGENTS.md.
 * LV-R2 retry (2026-11-22): 11 differences (tools/check.py) at level 04. A goto from the loop's success path to `found: on = 1;` in the x == 1 arm gives retail's exact bne/move/li arm (no if-conversion), but the loop is then rotated without retail's `b` into the body: 78. See nonmatching/README.md.
 * RT-A retry (2026-11-22): still 11 differences (tools/check.py) at level 04 with the file's flags; switch, nested-if, no-else and
 *   type variants of the x == 1 arm give 11 to 79 (nonmatching/README.md).
 */
#include "common.h"

/* localdecomp:start func_L04_003C8E10 */
typedef int vu0_q_003C8E10 __attribute__((mode(TI)));
extern vu0_q_003C8E10 D_L04_001E27C0;
extern vu0_q_003C8E10 D_001A4C60_003C8E10 __asm__("D_001A4C60");
extern s32 func_L01_00456500(void *, s32);

void func_L04_003C8E10(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 on = 0;
    u8 x;
    s32 i;
    s32 j;
    s32 k;
    s32 *p;
    s32 *q;
    vu0_q_003C8E10 pos;

    m[0x30] = 0xFF;
    pos = *(*(s8 *)(v + 0x7E) != 0 ? &D_L04_001E27C0 : &D_001A4C60_003C8E10);
    x = m[0x95];
    if (x == 0) {
        for (j = 0; j < 4; j++) {
            if (((s32 *)v)[j] != -1 && func_L01_00456500(&pos, ((s32 *)v)[j]) != 0) {
                on = 1;
                break;
            }
        }
    } else if (x == 1) {
        on = x;
    } else {
        on = 0;
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
