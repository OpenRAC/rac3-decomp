/* PAL near miss (sonnet b33 nm2b, round 20): 6 raw differences in level 1 (9 before; h6 wrote it from the retail listing).
 * The call's arguments are right (the prototype of func_L01_003FB640 has the float before the pointer: `(void *, s32, f32, u8 *)`).
 * Levers that worked (9 -> 6): (1) the last add of retail is `lqc2 $vf1,r; lqc2 $vf2,o; vadd.xyz $vf1,$vf2,$vf1; sqc2 $vf1,pos` (r first, o second, the sum o + r): ONE
 * non-volatile asm block with those explicit registers, "=m"/"m" operands and the clobbers "vf1", "vf2" (cc1 accepts them) reproduces it; no helper in vu0.h has that operand order;
 * (2) the two copies as `__asm__("lqc2 %0, %1" : "=j"(q))` + a PLAIN C store `*(vu0_q *)&x = q;` (cc1 prints the sqc2 itself, a memory-unit insn for the scheduler).
 * Left (2 adjacent swaps): ours is lqc2 p, lqc2 o, sqc2 q, lui, sqc2 o, lqc2 D, lqc2 q, li; retail is lqc2 p, lui, sqc2 q, lqc2 o, lqc2 D, sqc2 o, li, lqc2 q.
 * Retail's pairs per cycle: [L p, lui] [S q, L o] [L D, S o] [li, L q]. sched1's priorities (check.py --flags="-dS -dR -fsched-verbose-5", the "prio" column): L o 6 > lui 5, so
 * ours puts L o in the first cycle; the retail order needs prio(L o) <= prio(lui) in the first cycle and L o >= L D in the second. Everything that lowers L o's chain (TI-typed
 * `*(vu0_q *)&q` operand for the reload of q) also drops L o below L D (it then goes after L D: 7-22 diffs).
 * A `"memory"` clobber on the load of o (and/or the reload of q) gets 4 diffs (the load then depends on the sqc2 of q), but a clobber on a pure load is an artificial barrier
 * (AGENTS.md "no artificial barriers"), so it is not a legal form; it is recorded here only as the explanation of the order.
 * Tried (about 130 compiles): 4 statement orders of the copies and the sub, vu0_q-typed (TI) and vu0_v4-typed (BLK) memory operands for every load, copies stored by asm sqc2 instead of C,
 * the sub as helper / as asm statements with TI operands, the last add as helper forms (vec_add_ab/ba with both argument orders: 9) and as the block (6).
 * With `-fno-schedule-insns` (no sched1) the whole function is 2 diffs and the VU block matches retail exactly (the retail order is sched2's order of the SOURCE order), i.e. retail's
 * sched1 did not move the loads above the stores: something orders `lqc2 o` after the `sqc2 q` without a barrier that we cannot reproduce.
 * h9 (round 20, 32-form grid of asm / C loads and stores + 4 r-store forms): base stays 6. Every form with a C load of o (`*(vu0_q *)(a0 + 0x10)`) is 20-23: sched1 hoists the C load into the branch's
 * delay slot (`bnel ...; lqc2 vf1,0x10($s1)`; asm statements are never moved across blocks), and a C load whose value is only stored becomes lq/sq through a GPR. A C store of r or a TI asm store
 * leaves the priorities unchanged (6). Retail's cycle pairs [L p | lui] [S q | L o] [L D | S o] [li | L q] need L o unavailable in cycle 1 (one memory insn per cycle behind L p); the C-load form
 * cannot give that without the hoist. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003F8A90 */
extern s32 func_L01_003FB640(void *, s32, f32, u8 *);
extern vu0_v4 D_L01_001EAA30;

s32 func_L01_003F8A90(u8 *a0) {
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 o;
    vu0_v4 q;
    vu0_q qa, qb;
    u8 *d = *(u8 **)(a0 + 0x68);

    func_0038D000(&p, d + 0x20, a0 + 0xC0);
    vec_add_ab(&p, &p, a0 + 0x10);
    if (func_L01_003FB640(&p, 2, *(f32 *)(d + 0x2C), *(u8 **)(d + 0x54))) {
        /* q = p and o = pos: lqc2 into a VU0 register, stored by the compiler (a plain sqc2) */
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p));
        *(vu0_q *)&q = qa;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        *(vu0_q *)&o = qb;
        vec_sub_ab(&r, &D_L01_001EAA30, &q);
        /* pos = o + r: one VU0 sequence */
        __asm__(
            "lqc2 $vf1, %1\n\t"
            "lqc2 $vf2, %2\n\t"
            "vadd.xyz $vf1, $vf2, $vf1\n\t"
            "sqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "m"(r), "m"(o) : "vf1", "vf2");
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003F8A90 */

INCLUDE_ASM("asm/levels", func_L01_003F8A90);
