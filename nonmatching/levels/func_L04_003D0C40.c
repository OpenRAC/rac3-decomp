/* Level 4 (Marcadia), file L04_003D0968.c (its line: -O2 -G8 -fopt-stack -mno-check-zero-division
 * -mvu0-use-vf0-vf2 @ps2as). 20 differences (tools/check.py --no-context, with the file's typedefs) at
 * levels 04 and 18 and on NTSC-U (2026-11-24, task #3048); the history follows.
 * - The prototype is the file's own (`M_003D0968 *, V_003D0968 *`, from func_L04_003D0968's block), cast to
 *   byte pointers inside; the earlier `(u8 *, u8 *)` draft no longer compiled in the file's context.
 * - 264 -> 89: the second search compares against `*(s32 *)(v + 0x90) + 1` read in place instead of an
 *   `n` assigned in the else-if test. With `n`, gcc keeps the first load of +0x90 in a register for the
 *   whole if/else chain (264); retail reloads +0x90 in the else branch.
 * - Still open (the blocker): the three inlined moby-group searches (D_L04_0021C9A0 / D_L04_001DFD9C, as in
 *   func_L04_003627C8) compile, but retail has the found-exits (`b ...; sw $a1, 0x94($s2)`) placed after the
 *   early `return 0` and before the first loop. Loops 1 and 3 share one exit block there, which jumps past all
 *   three searches, and loop 2 has its own, which jumps to the `+0x94 == 0` test. Here they land after the
 *   first loop, which shifts every branch. Retail also keeps the else-branch value of +0x90 in $t2 for loop 2
 *   (`addiu $a0, $t2, 1`); this C reloads it in the loop. Also the loop-setup register choice and the order of
 *   the child-vars stores (+0x60/+0x6C, +0x40).
 * - Tried (task #2809): `goto` exits to a common label (264); `n` assigned inside a nested
 *   else (264); `n` assigned after the else-if test (264); `vv->w90`/`vv->p94` struct fields (264);
 *   `*(s32 *)(v + 0x90) + 1 == 0` for the first test (75, but it
 *   compiles to addiu/bnez where retail compares with $s0 = -1, so it is not retail's form).
 * Stopped per AGENTS.md.
 * Task #2882 (2026-11-22): re-measured 89 differences (tools/check.py) at level 04 with the file's line. One more
 * wording: the three searches as one `static __inline__` helper returning the found moby (or 0), with the
 * `+0x94` store in the caller under `if (e != 0)`: 276 differences.
 * Task #2940 (2026-11-22, upstream 70e001ab): re-measured 89 differences (tools/check.py) at levels 04 and 18. The
 * placement comes from loop.c (find_and_verify_loops): each found-exit block (`p94 = e; break;`) moves to the
 * nearest BARRIER before its jump target at the target's loop depth. Here the BARRIER after arm 1's `else` jump
 * (outside any loop) is the nearest, so the blocks land after loop 1; in retail they sit after the early
 * `return 0`, so retail had no such BARRIER there when loop.c ran. Arm 2 written as a separate test after arm 1,
 * `if (v->w90 != -1) { if (v->w90 >= -1) { ... } }`, reproduces that: all three blocks move after the `return 0`,
 * and arm 2's head is retail's exactly (`lw $v0, 0x90; move $t2, $v0; slti; bnel`, the first `bne` threaded to it).
 * But arm 1 then falls into the `!= -1` test (`lw; addiu; beql`) where retail has `b` to the join, and the third
 * block is not crossjumped: 265 differences (tools/check.py), 40 aligned rows against this draft's 43. No pass
 * after loop.c can make that test unconditional (cse follows only conditional jumps to labels behind a BARRIER;
 * thread_jumps only retargets conditional jumps), and every C form tried keeps it: an `s32 n` for both tests
 * 263, `if (!(v->w90 == -1))` 265, `w90 != -1 && w90 >= -1` in one test 262 (merged into `bltz`), `else if
 * (w90 != -1)` 89 (the else jump is back). The file's own struct types (`M_003D0968`/`V_003D0968` fields)
 * instead of byte offsets: 89, and `for (;;)` with the test as a leading `break`: 89 (same RTL after rotation).
 * Task #3002 (2026-11-23, upstream 1dbb16a7): 89 -> 32 differences (tools/check.py --no-context) at levels 04 and 18
 * (by difflib alignment of the instruction columns: 56 -> 23 rows). What moved it:
 * - The found-exits are written as plain `goto`s to two labelled blocks placed after the early `return 0`
 *   (`found2: p94 = e; goto test3;` then `found13: p94 = e; goto join;`), so loop.c has no block to move and they land
 *   where retail has them; loops 1 and 3 share found13 as in retail (89 -> 51; with found2 first, 47).
 * - The child-vars stores in the order +0x60, +0x68, +0x74, +0x90, +0x70, +0x6C (a search over the 720 orders), and
 *   +0x7C before +0x40 (47 -> 44 -> 37 on the earlier base).
 * - `p = *(D_L04_0021C9A0 + m[0x21])` for the three list heads (the loop setup's $v1/$a0 now match): 44 -> 39.
 * Still open (the blocker): retail reloads +0x90 at arm 2's head and keeps it in $t2 (`lw $v0; move $t2, $v0; slti`),
 * then compares `$t2 + 1` in loop 2; here cse follows the first test's `bne` into arm 2 (its label sits after arm 1's
 * `else` jump and BARRIER) and reuses the first load, so loop 2 reloads +0x90 itself. -fno-cse-follow-jumps (a study
 * flag only, not the file's) gives the reload. The #2940 form (`if (w90 != -1) { if (w90 >= -1) ... } }` after arm 1)
 * with the gotos gives retail's arm-2 head exactly, but arm 1 then ends in `lw; addiu; beql` instead of `b`. Tried
 * without gain: `n` assigned in the else-if test or as an else-block statement (233), `goto join` at the end of arm 1
 * plus a plain `if` (47), a `switch` with `case -1` / `default` (47), `vv->w90` / `mm->vars->w90` for one of the tests
 * (32 / 211), the `+0x94 = 0` store moved into each arm (60). Also open: the two copies of m[0x21] for the loop tests
 * (retail `move $t0, $v1` and `move $a3, $v1`; here `$a3` then `move $t0, $a3`, from gcse), unchanged by
 * `(s32)`, `(u8)0xFF`, `< 0xFF` (38), `D >= m[0x21]` or a `for` form.
 * CLOSEOUT attempt 1 of 2 (task #3039, 2026-11-24, upstream 3e4df279): 32 -> 24 differences at levels 04 and 18.
 * - Mechanism of the +0x90 reload (gcc dumps, -dj -ds -dG): cse follows the first test's `bne` into arm 2 only when
 *   the code just before arm 2's label ends in a BARRIER; a NOTE_INSN_LOOP_END there stops it (cse.c's backward scan).
 *   With loop 1 as a `while`, arm 1 ends in the if's `b join` after the loop's LOOP_END, so cse follows.
 * - Loop 1 is now written as `goto test1; for (;;) { body; test1: if (cond) continue; goto join; }`: its exit
 *   `goto join` is inside the loop, so arm 2's label follows LOOP_END, cse does not follow, and arm 2's head is
 *   retail's `lw $v0, 0x90; move $tN, $v0; slti` with loop 2's `addiu $a0, $tN, 1` (gcse PRE's copy).
 * - Still open: (1) loop 1's tail is `bnel p != head -> join; b top` where retail has `beql p == head -> body; b join`
 *   (jump.c inverts the test around the `goto join` before it threads the jumps; writing the test as
 *   `if (!(cond)) goto join;` gives the same code); (2) $t1/$t2 are swapped between the lui copy of D_L04_0021C9A0
 *   and the +0x90 copy; (3) the m[0x21] copies: gcse PRE inserts them in expression-index order (the zero_extend
 *   load, index 3, before the QImode load, index 18), so the QImode copy is `move $t0, $a3` after it; retail has the
 *   QImode copy first, both from the lbu.
 * - Tried without gain: arm 2 as `s32 n = +0x90` (230, cse equates it), n through `vv->w90`, `*(u32 *)` or a
 *   function-level n (230 each), a pointer `s32 *pw = v + 0x90` (261), `((s32 *)v)[0x24]` (32), a `switch` with n
 *   (230), loop 1 as `for (;;)` with the tests at the top, with n (261: arm 2 reloads, but loop 1 is not rotated),
 *   `&& p94 == 0` on the first test (32), a `u8 k = m[0x21]` for the list heads (34 on this form, 44 on the old one),
 *   `D_L04_0021C9A0[m[0x21]]` for the heads (28).
 * CLOSEOUT attempt 2 of 2 (task #3048, 2026-11-24, upstream 3e4df279): 24 -> 20 differences at levels 04 and 18 and on
 * NTSC-U. Result: still a near miss; DONE (r3-64 budget spent).
 * - Loop 1's tail polarity is fixed: the back edge is an explicit `if (cond) goto top1; goto join;` with `top1:` at the
 *   head of the `for (;;)` body (the goto-into-a-loop form of upstream's func_L39_0068BAD8). The conditional jump now
 *   goes straight back to the body, so jump.c has no jump around a jump to invert: `beql p == head -> body; b join`,
 *   as retail. LOOP_END still precedes arm 2's label, so arm 2 keeps retail's +0x90 reload.
 * - Still open: (2) $t1/$t2 swapped between the lui copy of D_L04_0021C9A0 (gcse reaching reg 302) and the +0x90 copy
 *   (reaching reg 303). The .lreg dump gives 302 10 refs over 376 insns and 303 3 refs over 37 insns, so global.c's
 *   priority (floor_log2(refs) * refs / live length) is 0.0798 against 0.0811: 303 is allocated first and takes $t1.
 *   Retail's assignment needs 302 first. (3) The m[0x21] copies, as before: gcse inserts them in expression-index
 *   order (zero_extend index 3, D's high part 4, the QImode load 18), so the QImode copy reads the zero_extend copy
 *   (`move $t0, $a3`); retail copies both from the lbu, QImode first. The QImode load is the u8 compare with 0xFF in
 *   the loop test (shortened to QImode), which comes after the setup's zero_extend in insn order. In arm 1 the
 *   scheduler also moves the lui copy up, so arm 1's setup differs in more rows than arm 2's.
 * - Tried without gain (counts at level 04): the precedent's own `goto test; do { body; test:; } while (cond);` (50),
 *   `if (!(cond)) goto join;` inside a `while (1)` (24), a block-scoped `u8 k = m[0x21]` for the list heads in arm 1,
 *   arms 1 and 2, or all three (20 each, the same bytes: MIPS promotes the u8 local, so it is a zero_extend load too),
 *   `D_L04_0021C9A0[m[0x21]]` for arm 1's head or all three (24), `*(D + m[0x21])` in the loop tests (20), loops 2
 *   and/or 3 in the same explicit goto form (62 / 193 / 231), and 236 of the 720 declaration orders of the six pointer
 *   locals (all 20; the search was stopped there).
 * Flag for review: the `goto` into the `for (;;)` and the `goto top1` back edge (plain C; precedent: upstream's matched
 * func_L39_0068BAD8, src/levels/39_multiplayer_menu/L39_0068BAD8.c, `goto test; do { ... test:; } while (...)`).
 * Stopped per AGENTS.md. */
#include "common.h"

/* localdecomp:start func_L04_003D0C40 */
#include "vu0.h"

extern u16 *D_L04_0021C9A0[];
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFDD8, 4");
extern s32 D_L04_001DFDD8;
__asm__(".extern D_L04_001DEB10, 4");
extern f32 D_L04_001DEB10;
__asm__(".extern D_L04_001DEB20, 4");
extern f32 D_L04_001DEB20;
typedef void (*Fn_L04_003D0C40)(u8 *);
extern void func_L01_00456230(void *, s32);
extern Fn_L04_003D0C40 *func_L01_0043B548(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C7C38(void *);
extern f32 func_0038DAB8(f32, f32);
extern u8 *func_L04_003E2390(void *, vu0_v4 *, vu0_v4 *, s32, s32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L04_003D0C40(M_003D0968 *mm, V_003D0968 *vv) {
    u8 *m = (u8 *)mm;
    u8 *v = (u8 *)vv;
    u16 *p;
    u8 *e;
    u8 *c;
    u8 *cv;
    vu0_v4 pos;
    vu0_v4 rot;

    func_L01_00456230(m, 0);
    v[0x38] = 1;
    *(s32 *)(v + 0xA4) = -1;
    if (*(s32 *)(v + 0x70) > 0) {
        Fn_L04_003D0C40 *t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(v + 0x70) = -1;
        v[0x7E] = 4;
        t[0](m);
        return 0;
    found2:
        *(u8 **)(v + 0x94) = e;
        goto test3;
    found13:
        *(u8 **)(v + 0x94) = e;
        goto join;
    }
    *(u8 **)(v + 0x94) = 0;
    if (*(s32 *)(v + 0x90) == -1) {
        p = *(D_L04_0021C9A0 + m[0x21]);
        goto test1;
        for (;;) {
        top1:
            e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                goto join;
            }
            if (*(s32 *)(*(u8 **)(e + 0x68) + 0x90) == 1) {
                goto found13;
            }
            p++;
        test1:
            if (m[0x21] != 0xFF && m[0x21] <= D_L04_001DFDD8 && p != 0 &&
                ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[m[0x21]])) {
                goto top1;
            }
            goto join;
        }
    } else if (*(s32 *)(v + 0x90) >= -1) {
        p = *(D_L04_0021C9A0 + m[0x21]);
        while (m[0x21] != 0xFF && m[0x21] <= D_L04_001DFDD8 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[m[0x21]])) {
            e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                break;
            }
            if (*(s32 *)(*(u8 **)(e + 0x68) + 0x90) == *(s32 *)(v + 0x90) + 1) {
                goto found2;
            }
            p++;
        }
    test3:
        if (*(u8 **)(v + 0x94) == 0) {
            p = *(D_L04_0021C9A0 + m[0x21]);
            while (m[0x21] != 0xFF && m[0x21] <= D_L04_001DFDD8 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[m[0x21]])) {
                e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                if (*(s32 *)(*(u8 **)(e + 0x68) + 0x90) == -2) {
                    goto found13;
                }
                p++;
            }
        }
    }
join:
    if (*(s32 *)(v + 0x90) == -2 || *(s32 *)(v + 0x90) == -1) {
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        *(s32 *)(m + 0x98) = 0;
        func_L01_004AA7E8(m, 1);
        *(u8 **)(v + 0x9C) = 0;
        *(u8 **)(v + 0xA0) = 0;
    } else {
        c = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) &= ~0x41;
        *(u16 *)(m + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(c + 0x10);
        *(u8 **)(v + 0x9C) = func_003C24B0(0xB57, 0xA0);
        (*(u8 **)(v + 0x9C))[0x30] = m[0x30];
        *(u16 *)(*(u8 **)(v + 0x9C) + 0x32) = *(u16 *)(m + 0x32);
        cv = *(u8 **)(*(u8 **)(v + 0x9C) + 0x68);
        *(s32 *)(cv + 0x60) = *(s32 *)(v + 0x98);
        *(f32 *)(cv + 0x68) = 1.0f;
        *(s32 *)(cv + 0x74) = -1;
        *(s32 *)(cv + 0x90) = -1;
        *(f32 *)(cv + 0x70) = 3.5f;
        *(s32 *)(cv + 0x6C) = 0;
        func_0038D000(*(u8 **)(v + 0x9C) + 0x10, &D_L04_001DEB10, m + 0xC0);
        vec_add_ba(*(u8 **)(v + 0x9C) + 0x10, *(u8 **)(v + 0x9C) + 0x10, m + 0x10);
        *(vu0_q *)(*(u8 **)(v + 0x9C) + 0xF0) = *(vu0_q *)(m + 0xF0);
        func_0038D308(*(u8 **)(v + 0x9C) + 0xC0, *(u8 **)(v + 0x9C) + 0xF0);
        *(f32 *)(cv + 0x7C) = *(f32 *)(*(u8 **)(v + 0x9C) + 0x18);
        *(s32 *)(cv + 0x40) = 0;
        func_L01_00456230(*(u8 **)(v + 0x9C), 0);
        (*(u8 **)(v + 0x9C))[0x20] = 6;
        func_003C7C38(*(u8 **)(v + 0x9C));
        func_0038D000(&pos, &D_L04_001DEB20, m + 0xC0);
        vec_add_ab(&pos, &pos, m + 0x10);
        *(vu0_q *)&rot = *(vu0_q *)(m + 0xF0);
        rot.z = func_0038DAB8(rot.z, 3.14159274f);
        *(u8 **)(v + 0xA0) = func_L04_003E2390(m, &pos, &rot, *(s32 *)(v + 0x80), *(s32 *)(v + 0x88),
                                               *(f32 *)(v + 0x84), *(f32 *)(v + 0x8C), v[0x44]);
        (*(u8 **)(v + 0xA0))[0x30] = m[0x30];
        *(u16 *)(*(u8 **)(v + 0xA0) + 0x32) = *(u16 *)(m + 0x32);
        func_003C7C38(*(u8 **)(v + 0xA0));
    }
    if (*(s32 *)(v + 0x90) == -3) {
        func_L01_004450F0(m, 2, -1);
    } else {
        func_L01_004450F0(m, 1, -1);
    }
    return 1;
}
/* localdecomp:end func_L04_003D0C40 */
