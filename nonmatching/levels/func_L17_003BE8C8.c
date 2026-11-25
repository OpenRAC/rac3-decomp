/* Level 17 (Crash Site), PAL near miss, 5 diffs (round 21 W3b; was 10, W3 had 61). The machine gun enemy's hit/explosion effect.
 * Needs its own file (src/levels/17_crash_site/L17_003BE8C8.c cut before func_L17_003BEB98) with the flags
 * "-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as" (NO -fopt-stack) and the sq_ra_funcs.txt row
 * `func_L17_003BE8C8`; with those the frame (0x170, sq slots) is right.
 * Round 21 W3b: the two float-argument moves were callee prototypes. Master's other callers (L04_00366800, L11_003BDA60,
 * L04_003EBDB8) declare func_L02_00429840 as (void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32) and
 * func_L02_003E2E38 as (void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32): floats interleaved among the
 * ints, so the float `mov.s` of an argument comes before the later int moves. 10 -> 5.
 * Remaining 5 words: fx3 and flag swap $s6/$s7 (retail fx3=$s6, flag=$s7; mine reversed). The -dg dump says why: both
 * pseudos are used twice, fx3 is live over 95 insns and flag over 94, so flag is allocated first (higher refs/len priority);
 * retail needs len(fx3) <= len(flag) (a tie goes to the lower pseudo number, fx3). Tried (all 5): `if (fx3)`, `(s32)flag`
 * in the call; pos/vel/pt statement orders (5, 9 and 18); a flag copy local (before the first call / before the last
 * block); `|| flag == 99` (75).

 * Round 25 W7 (b39, ~15 compiles, base 626eebd0d). To reproduce the 5: in config/levels/text_parts.txt drop ` -fopt-stack`
 * from this file's line and add `func_L17_003BE8C8` to config/levels/sq_ra_funcs.txt (neither is committed: the function is
 * still INCLUDE_ASM and the README row's old "61 diff" counted the frame without them); check.py then prints 5 diff
 * (`-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as`).
 * The -dl dump: fx3 = pseudo 121 (95 insns), flag = pseudo 129 (94), both 2 refs; allocno priority is refs / live length, so
 * flag is allocated first and takes $s6. After sched1 the param homing is [fx3 move #6 ... flag lbu #17] = 10 insns inside
 * fx3 only, and [fx3's beqz #96 ... flag's first stack store #106] = 10 insns inside flag only; the lbu of flag is the only
 * non-REG_EQUIV param load (zero_extend), col3/col4/col5 are REG_EQUIV stack loads and never hold a register. Retail needs
 * R1 <= R3 (tie: lower pseudo number fx3 first). The pre-RA order after sched1 puts the first call's three argument moves
 * before the stack-param loads. Not found: a way to move one insn from R1 to R3 without changing the code. Tested without
 * effect (5): the effect-test and width variants of W1 (60 compiles), 128-bit locals, a late scale local, pointer
 * materialization after the copies.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L17_003BE8C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BE8C8;
extern s32 D_L17_001D66B0[2];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L05_003DC520(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L17_003BE8C8(u8 *self, s32 id, s32 snd, s32 fx1, s32 fx2, s32 fx3, s32 col1, s32 col2,
                       f32 speed, f32 scale, s32 col3, s32 col4, s32 col5, u8 flag) {
    V4_3BE8C8 pos, vel;
    V4_3BE8C8 *pt;

    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, id, D_L17_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (snd != 0) func_L05_003DC520(self, snd);
    pt = &pos;
    pos = *(V4_3BE8C8 *)(self + 0x10);
    vel = *(V4_3BE8C8 *)(self + 0xE0);
    func_0038CF68(&vel, &vel, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * speed);
    vec_add_ab(&pos, &pos, &vel);
    if (fx1 != 0) {
        func_L02_00429840(self, pt, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * 4.0f, 0x14, 0,
                          D_L17_001D66B0, 0.20000002f, 1.0f, 1.5f, col1, 0, 0x4B);
    }
    if (fx2 != 0) {
        func_L02_003E2E38(self, pt, 1.0f, D_L17_001D66B0, 0xF, 0, 0.050000004f, 2.5f, 5.0f, 1.0f, 1);
    }
    if (fx3 != 0) {
        func_L01_003303B8((u8 *)pt, 0, 0, 0, 0, 4, 5, 0,
                          *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * scale, 0.0f, 0.0f, 0.0f,
                          flag, 1, 0, 0, 0, 0, 0x1000000, 0, col2, col3, 0, 0, 0, 0, col4, col5, 0, 0);
    }
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
/* localdecomp:end func_L17_003BE8C8 */
