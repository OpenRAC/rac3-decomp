/* func_L01_003749E8: a Veldin projectile's update (34 places, shared; switch on the state byte
 * with 5 cases: 0 flies and collides, 1 sets up 24 vector pairs, 2 spawns particles and hunts
 * a target, 3 and 4 wind down). Near miss, not linked. Round 30 W1 (Opus), sixth look
 * (W25: 7 aligned; W22: 19; W17: 50; W10: 154; codex-b41-w10: partial draft).
 * State: complete C for every state. With the file's flags plus -mvu0-use-vf0-vf2 (mode S, @ps2as),
 *   check.py THIS.c func_L01_003749E8 --flags=-mvu0-use-vf0-vf2
 * gives 1506 words (= retail) and 2 diff lines IN the file's context (plus the jump table's
 * %hi/%lo placeholder): state 4's argument moves (W1 section below). In context the three names that the file
 * declares differently use its declarations: D_001A4BE0.w[], func_L01_0040E548(f32 *, f32 *), and
 * func_0038CF68 called through the cast typedef Fn_CF68_3749E8, the file has (f32, void *, void *);
 * with --no-context add: `extern u8 D_001A4BE0[]` (and `*(void **)(D_001A4BE0 + 0x25C0)`),
 * `extern void func_0038CF68(void *, void *, f32);`, `extern f32 func_L01_0040E548(void *, void *);`
 * and drop the (f32 *) casts of the func_L01_0040E548 arguments. Measured at level 01 only: the
 * D_L01_ names (001E29C0, 001E2A40, 001E2DC0, 001EAA00, 001EEA80, 001F1B40, 001D66B0, 002C5600,
 * 00221098) need per-level aliases at the other 33 places.
 * Needs, when it lands: -mvu0-use-vf0-vf2 added to L01_00374630.c's flag line (func_L01_00374630,
 * func_L01_00374790 and func_L01_00374908 still MATCH with it), the jump table (jtbl_002BED90) checked
 * in the full level build, $gp slot D_001D7BE0_sda (-0x4CD0($gp)), D_L01_001D66B0 declared as a
 * scalar `extern u8 D_L01_001D66B0;` passed as `&D_L01_001D66B0`.
 *
 * W1 (round 30; 16 diff lines -> 2):
 * (a) Particle sites 2 and 3: the copy store and the add store are plain C (`*(vu0_q *)&f[11] = c;`,
 *   `*(vu0_q *)&f[8] = x;`, `f[12]`/`f[7]` at site 3), the other VU0 steps stay asm. Why (sched2
 *   dump): a dependence whose consumer is an asm costs 0, so two asm sqc2 issue in one cycle and the
 *   `addiu/move $a0` set only finds a slot after the vsub; the compiler's own TImode move (lqc2/sqc2
 *   with vf registers under -mvu0-use-vf0-vf2) is a real insn with a latency, the add store waits a
 *   cycle and the $a0 set fills it: retail's `sqc2 copy; $a0; sqc2 add; move $a1; lqc2; lqc2; vsub`.
 *   All 256 asm/C combinations of the 8 memory operands of site 2 swept: this is the smallest change
 *   that scores 0 (site 1 already matched and is unchanged).
 * (b) Left: state 4's `func_003A52A0(1, 0, self)`: retail `move $a1,$zero` before `addiu $a0,1`.
 *   Cause (sched1 dump, rank_for_schedule): the a1 set ranks first only when its source is a pseudo
 *   that DIES there (register weight 0 vs 1; same rule puts `move $a2` first at the (2, 0, self)
 *   site, where self's pseudo dies) and that pseudo becomes $zero only AFTER sched1. Measured: a zero
 *   local set before the use is folded by gcse cprop (any set that reaches the call on every path,
 *   also two sets in both arms) and by cse skip-blocks; with -fno-gcse -fno-cse-skip-blocks the
 *   local gives retail's order. The only plain-C form found that hides it from both but lets
 *   local-alloc's update_equiv_regs substitute 0 (single set, single use) is a local set ONLY in the
 *   `if (state->target != 0)` arm (`z = 0; state->timer = z;` ... `func_003A52A0(1, z, self)`):
 *   that gives a full MATCH at level 01 but reads z uninitialized when target == 0 (undefined
 *   behaviour), so it is not used here (copy: b44-drafts/func_L01_003749E8_uninit.c). Also tried:
 *   prototype without parameters, s64 second parameter (`por`), comparison result as the argument
 *   (`slt $a1` kept in $a1), a zero local at the case start / before the test (folded).
 *
 * W25 (this look; 19 -> 7):
 * (a) The three particle loops' add/copy/sub chains are per-instruction VU0 asm statements inside
 *   the function (TImode "m" operands, like the in-function blocks of L03_003AF848 / L03_003B1520),
 *   in the order copy (lqc2 c, sqc2 c), add (lqc2 x, lqc2 y, vadd x = x + y, sqc2 x), sub (lqc2 y = the
 *   add's result, lqc2 x = the copy, vsub c = x - y, sqc2 c). All three sites now give retail's VU0
 *   order and vf registers. Why (sched1 dump): the add loads have a longer path than the copy load,
 *   so they still issue first; the copy store then wins the tie with the add store by luid; the sub
 *   loads issue b first by luid. The W22 file-local vq_ helpers are gone. Swept (local cc1 compile,
 *   0.5 s each): source orders copy-first / add-first / interleaved x every variable-sharing pattern
 *   of the 7 values; only reuse patterns where the sub's b load does not add an anti dependence on
 *   the add store keep the store order (a fresh pseudo for every value spills: qa set twice is a
 *   global, and the copy then takes vf2).
 * (b) func_003D4D00 declared (void *, s32, f32, void *, void *) (11 files have that order): the float
 *   argument's move is emitted before the pointer moves, so `mov.s $f12,$f20` lands before
 *   `move $a2,$s4` at the hit path's second call like retail (-3 rows; positions 0-2 all equal).
 * (c) func_L01_00448340 returns f32 (as in 8 other files): a call_value sets $f0, so the following
 *   func_0038DAB8 call's dependence on $f0 goes to that call instead of the state->scale load; the
 *   scale load then no longer has one dependent more than the f90 load and sched2 keeps f90 first
 *   (luid), as retail (-2 rows).
 * Left (5 real rows): (1) particle sites 2 and 3: retail issues `addiu $a0,$sp,0x90` / `move $a0,$s2`
 *   between the copy store and the add store and `move $a1` after the add store; here both moves come
 *   after the vsub (sched2: the a0 set has priority 3, the VU0 stores lie on the path to the lwc1 of
 *   state->scale and the multiplies, so they win; retail behaves as if the add store were not ready
 *   in the copy store's cycle). Tried: BLKmode (vu0_v4) operands on any subset of the 8 memory
 *   operands (256 combinations) and the interleaved order add-loads, copy, add-store: spills or worse.
 *   (2) state 4: `func_003A52A0(1, 0, self)`: retail `move $a1,$zero` before `addiu $a0,$zero,1`; both
 *   tie in sched1 and sched2 (no deps, same priority, luid decides); casts to void / u8 / s16 / u32
 *   parameter types and using the result give the same order.
 *
 * W22 (50 -> 19):
 * (a) The dummy `0 + (s32)fz - 1` of W17 is gone. Cause (loop dump, -dL): loop.c runs twice; a
 *   life-1 constant that is "not desirable" in pass 1 (loop of 62 insns, threshold about 61) is hoisted
 *   in pass 2 (59 insns), and only registers set ONCE are movable. Retail hoists 5/0x1f8/0x1699 out of
 *   target loop 1 but not its float zero (loop 2 hoists its zero into $f20, two uses combined). A
 *   function-level `f32 zf` set to 0.0f at state 0's first func_L01_00446760 call (`zf = 0.0f;
 *   func_L01_00446760(..., zf)`) and again before the compare in loop 1 has two sets, so loop.c leaves
 *   it: same bytes as the dummy, plain C (reuse of one float temp). Indexing loop 1 (`D[k1]`) instead
 *   keeps the zero in place too but loses the 0x1699 hoist (3 rows) and was not kept.
 * (b) Target loop 2 (index form): retail has `li $v0,0x1f8` in the delay slots of BOTH predecessors of
 *   the id chain (beq slot after `lbu/li 5`, beqz slot after the func_003C4B50 call) and the branch goes
 *   to the `lh`: reorg copied the FIRST insn of the join block (`li`, non-trapping, so no branch-likely).
 *   Here sched2 put `lh` first (ready list: lh priority 2 > li 1) and reorg took the trapping `lh` into
 *   a `beql` slot. Fix: a local `cc` set to 0x1F8 at the END of both arms of the
 *   `cls == 0 || cls[0x46] != 5` diamond (`cc = 0x1F8;` after the reload and in an else branch) and used
 *   only by the first compare (`id == cc`); the other five constants stay literal (a per-site cc for all
 *   six made cc one long-lived pseudo and swapped $v0/$v1: 35 rows). That removed the extra `li`, the
 *   alignment nop of the list loop (length parity) and all ~14 branch-offset rows: 50 -> 21.
 * (c) First particle loop only: TImode-memory twins of the helpers (`"m"(*(vu0_q *)p)` instead of
 *   `*(vu0_v4 *)p`, which is BLKmode: every BLK access conflicts with every other stack access, so a
 *   load never rises above an earlier helper store). vq_add_ab_a ties the vadd result to its first
 *   operand's quantity, vq_sub_ab_b to its second's. Gives retail's vf1/vf2 roles exactly; -2 rows.
 *   72 combinations measured (add/copy source order x add ab/ba x tie none/a/b x sub ab/ba x tie).
 * W22 left: (1) the VU0 chain of the three particle loops (first loop 3 rows, the other two about 6 each):
 *   retail stores the copy `f[10] = pos` BEFORE the add's store (`sqc2 vf1,0xa0` then `sqc2 vf2,0x20`)
 *   and loads the vsub's b first (`lqc2 vf1,0x20; lqc2 vf2,0xa0; vsub.xyz vf1,vf2,vf1`). With TI helpers,
 *   source order [copy, add] gives the right store order but the add's tied quantity spills (3 live "j"
 *   values: sched1 hoists the copy's lqc2 above the vadd) and the register roles of the add flip; order
 *   [add, copy] gives the right roles and the wrong store order. Not both so far; (2) the lwc1 order of
 *   the state->f90 / state->scale loads in the f90-loop's func_L01_00448340 call (retail `lwc1 $f14,0x90`
 *   first; sched1 keeps f90 first, sched2 reverses the tie (later luid first); the `scale * f90` spelling
 *   flips the order but also the $f0/$f14 roles; 2 rows); (3) `move $a1,$zero` before `addiu $a0,$zero,1`
 *   of state 4's func_003A52A0(1, 0, self) (2 rows); (4) `mov.s $f12,$f20` before `move $a2,$s4` at the
 *   second func_003D4D00 call of the hit path (3 rows; the float parameter's position in a per-site
 *   prototype was not tried).
 * What made the difference (aligned diff, all rounds): no function-level `position` local, `self + 0x10`
 * everywhere (613 -> 457); state 0's destroy code inline, hit-call as if/else (-15); state-2 transition
 * tests as ONE `||` condition each (-16); block-local particle/target variables, +1 reference of
 * `self` in states 3/4, the state-1 loop indexed by i, vec_sub_ab/vec_add_ab spellings (W10: 154).
 * W17: (a) `(D_L01_002C5600 + D_001425C0[0x5F])->damage` pointer-plus-index tree keeps +0x6C out of
 * the mtlo address (-3); (b) the second target loop in indexed form `D_L01_001EEA80[k]` without the
 * `count <= 0` return (-14 norm); (c) separate pointer `p2` for the second spawn of the ic==3 block (-10)
 * and its stores in retail's order `p2[2] = ...; p2[3] = 0x44;` (-14); (d) the loop-1 id chain with one
 * per-site local `cc` set before each compare (li in the delay slots like retail; only 5, 0x1F8 and
 * 0x1699 are hoisted); (e) `extern u8 D_L01_001D66B0;` + `&D_L01_001D66B0` (gcse PRE no longer hoists
 * the lui out of the spawn loop, -9); (f) call-result variables used only as the branch test copied
 * into the pointer inside the if and block-local q/target in short-lived uses (-10); (g) separate
 * counters k1/k2 for the two target loops (-30); (h) block-local pointer for the second D_00142DE0
 * update, block-local target in state 3 (-14); (i) counting loops as `for (x = 0; x < 4; x++)` (-2);
 * (j) operand order `vec_add_ab(&f[5], pos, &f[4])` (-2). Details: sonnet-b43-w17-findings.md and
 * sonnet-b43-w22-findings.md in the Data folder. */
#include "common.h"
#include "vu0.h"
#include "structs/weapon.h"

typedef struct {
    vu0_v4 velocity;
    vu0_v4 directionA;
    vu0_v4 directionB;
    u8 pad30[4];
    s32 timer;
    s32 f38;
    u8 pad3C[8];
    f32 crossScale;
    u8 pad48[4];
    f32 rotation;
    u8 pad50[4];
    u8 *target;
    u8 pad58[0xC];
    s32 sound;
    f32 scale;
    s32 entry;
    u8 pad70[0x10];
    f32 intensity;
    u8 pad84[8];
    void *effect;
    f32 f90;
    s32 f94;
    u8 pad98[8];
    vu0_v4 base[24];
    vu0_v4 vectors[24];
    f32 phase[24];
} UpdateState;

typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 f19;
    u16 f1A;
} HitInfo;

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1c[4];
    u8 f20[0x40];
} Hit_EAA00;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 fC;
    vu0_v4 f10;
} SoundRow;

extern u8 D_001A30B0[];
extern u8 D_001425C0[];
extern u8 D_00142DE0[];
extern vu0_v4 D_001A4C60[];
extern vu0_v4 D_L01_001E29C0[];
extern vu0_v4 D_L01_001E2A40[];
extern vu0_v4 D_L01_001E2DC0[];
extern Hit_EAA00 D_L01_001EAA00;
extern SoundRow D_L01_001F1B40[];
extern u8 D_L01_001D66B0;
extern u8 *D_L01_00221098[];
extern u8 *D_L01_001EEA80[];
extern struct WeaponRow D_L01_002C5600[];
typedef void (*Fn_CF68_3749E8)(void *, void *, f32);
extern u32 D_001D7BE0_sda;
__asm__(".extern D_001D7BE0_sda, 4");

extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L01_004C8688(void *, void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00424D88(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_003770A8(void *);
extern void func_L01_00376490(void *);
extern void func_L01_00376D08(void *);
extern void func_L01_003773C0(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_L01_00377908(void);
extern void func_L01_00377940(void);
extern void func_L01_003778D0(void *);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_004C7D98(void *, void *);
extern u8 *func_00382348(void *);
extern s32 func_003C4B50(void *);
extern void func_L01_0034E558(void *, s32, void *, void *, s32);
extern u8 **func_L01_00448FB8(void *);
extern void func_L01_00374908(void *, void *);
extern f32 func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_003C7C38(void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_00444350(void);
extern void func_L01_0033D0E8(void *);
extern void func_L01_003779C8(void *);
extern void func_L01_004C8668(void *);
extern void func_003C2880(void *);

void func_L01_003749E8(u8 *self) {
    UpdateState *state = *(UpdateState **)(self + 0x68);
    u8 *target;
    u8 *entry;
    vu0_v4 f[13];
    f32 scale;
    s32 ia, ib, ic, id2, ie, if_, ig;
    s32 n, k, k1, k2, id, life, rint;
    u8 *p, *m, *q, *cls, *pd;
    f32 zf;

    if (func_L01_004CB2D8()) {
        func_L01_004CAB30((self + 0x10), (self + 0x10));
    }

    switch (self[0x20]) {
    case 0:
        *(vu0_q *)&f[0] = *(vu0_q *)(self + 0x10);
        scale = func_0038CEA8(&state->velocity);
        func_L01_004C8688(state->effect, state, 0);
        vec_add_ba((self + 0x10), &state->velocity, (self + 0x10));
        state->rotation = func_0038DAB8(state->rotation, 0.6981317400932312f);
        ((Fn_CF68_3749E8)func_0038CF68)(&state->directionA, &state->directionA,
                      func_0038D0B0(state->rotation) * 0.05f);
        ((Fn_CF68_3749E8)func_0038CF68)(&state->directionB, &state->directionB,
                      func_0038D0B0(state->rotation) * 0.05f);
        vec_add_ba(&state->velocity, &state->directionA, &state->velocity);
        vec_add_ba(&state->velocity, &state->directionB, &state->velocity);
        ((Fn_CF68_3749E8)func_0038CF68)(&state->velocity, &state->velocity, scale);
        ((Fn_CF68_3749E8)func_0038CF68)(&state->velocity, &state->velocity, scale * 0.9040000438690186f);
        if (*(f32 *)(self + 0x10) < 2.0f || 1021.0f < *(f32 *)(self + 0x10) ||
            *(f32 *)(self + 0x14) < 2.0f || 1021.0f < *(f32 *)(self + 0x14) ||
            *(f32 *)(self + 0x18) < 2.0f || 1021.0f < *(f32 *)(self + 0x18)) {
            if (state->sound != -1) {
                func_L01_00424D88(state->sound);
            }
            state->sound = -1;
            func_L01_004C8668(state->effect);
            func_003C2880(self);
            return;
        }
        state->timer++;
        if (func_003D3CB0(&f[0], (self + 0x10), 0, self, 0)) {
            *(vu0_q *)(self + 0x10) = *(vu0_q *)D_L01_001EAA00.f20;
            *(vu0_q *)&f[1] = *(vu0_q *)(D_L01_001EAA00.f20 + 0x20);
            ((Fn_CF68_3749E8)func_0038CF68)(&f[1], &f[1], 0.5f);
            vec_add_ba((self + 0x10), (self + 0x10), &f[1]);
            state->timer = 0;
            func_L01_004450F0(self, 1, -1);
            *(vu0_q *)&f[2] = *(vu0_q *)&state->velocity;
            func_0038CE20(&f[2], &f[2], 3.0f);
            f[2].w = 5627.9248046875f;
            zf = 0.0f;
            func_L01_00446760(&f[3], self, 0x10000, &f[2], zf);
            ((HitInfo *)&f[3])->f18 = 0;
            ((HitInfo *)&f[3])->f19 = 1;
            ((HitInfo *)&f[3])->f1A = *(u16 *)(self + 0xAA);
            if (D_L01_001EAA00.f18 != 0) {
                if (D_L01_001EAA00.f18 != (u8 *)state->f38) {
                    func_003D4D00(D_L01_001EAA00.f20, 0, 1.0f, self, &f[3]);
                }
            } else {
                func_003D4D00(D_L01_001EAA00.f20, 0, 1.0f, self, &f[3]);
            }
        }
        if (state->sound == -1) {
            state->sound = func_L01_00424CB0((self + 0x10), 5.0f, 0.0f, 0.45f, 0.2f, 1.0f);
        } else {
            SoundRow *row = &D_L01_001F1B40[state->sound];
            row->f10 = *(vu0_v4 *)(self + 0x10);
            row->f10.w = 5.0f;
            row->f0 = 0.45f;
            row->f4 = 0.2f;
            row->f8 = 1.0f;
            row->fC = 0;
        }
        *(vu0_q *)&f[1] = *(vu0_q *)(self + 0x10);
        f[1].w = 0.5f;
        if (func_0038DC20(&f[1], 96.0f) > 0) {
            func_L01_00404A10(func_L01_003770A8, self);
            *(vu0_q *)&f[2] = *(vu0_q *)(self + 0x10);
            func_L01_003773C0(self, &f[2], &f[0]);
        }
        if (state->timer >= 30) {
            state->timer = 0;
            func_L01_004450F0(self, 1, -1);
        }
        return;
    case 1: {
        for (ia = 0; ia < 24; ia++) {
            state->phase[ia] = func_003824E0(0.01745329424738884f, 0.05235987901687622f);
            state->crossScale = state->scale * 0.1f;
            func_00382580(&state->base[ia], 1.0f, 1.0f);
            vec_sub_ab(&f[1], D_L01_001E29C0, (self + 0x10));
            ((Fn_CF68_3749E8)func_0038CF68)(&f[1], &f[1], 1.0f);
            func_0038CE90(&state->vectors[ia], &state->base[ia], &f[1]);
            ((Fn_CF68_3749E8)func_0038CF68)(&state->vectors[ia], &state->vectors[ia], state->crossScale);
        }
        if (state->sound != -1) {
            func_L01_00424D88(state->sound);
        }
        state->sound = -1;
        if (func_L01_00377908() && state->target == 0) {
            func_L01_00377940();
        }
        func_L01_003778D0(self);
        func_L01_004450F0(self, 2, -1);
        return;
    }
    case 2:
        state->timer++;
        if ((state->target == 0 && state->timer >= 501) ||
            (state->target != 0 && 2500.0f < func_L01_0040E548((f32 *)(state->target + 0x10), (f32 *)(self + 0x10)))) {
            state->timer = 0;
            func_L01_004450F0(self, 3, -1);
        }
        if ((state->target == 0 && 900.0f < func_L01_0040E548((f32 *)(self + 0x10), (f32 *)(D_001A4C60))) ||
            (state->target != 0 && 2500.0f < func_L01_0040E548((f32 *)(state->target + 0x10), (f32 *)(D_001A4C60)))) {
            state->timer = 0;
            func_L01_004450F0(self, 3, -1);
        }
        state->intensity += 0.005f;
        if (state->intensity > 0.75f) {
            state->intensity = 0.75f;
        }
        if (!func_L01_004AA710(self, state->entry)) {
            state->entry = func_003A52A0(0, 4, self);
        }
        *(vu0_q *)&f[1] = *(vu0_q *)(self + 0x10);
        f[1].w = 0.5f;
        if (func_0038DC20(&f[1], 96.0f) > 0) {
            f32 s20, s23, s22;
            func_L01_00404A10(func_L01_00376490, self);
            for (ib = 0; ib < 4; ib++) {
                s32 rint;
                s32 life;
                u8 *p;
                rint = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_00382580(&f[2], state->scale, state->scale * 2.200000047683716f);
                {
                    vu0_q x, y, c;
                    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)(self + 0x10)));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[10]) : "j"(c));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[2]));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)(self + 0x10)));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[2]) : "j"(x));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[2]));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[10]));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[3]) : "j"(c));
                }
                ((Fn_CF68_3749E8)func_0038CF68)(&f[3], &f[3],
                              func_003824E0(state->scale + state->scale, state->scale * 2.700000047683716f) *
                                  0.020000001415610313f);
                life = func_00382498(20, 25) * 5;
                life = life + 2;
                life = life / 6;
                p = func_L01_004713C8(&f[2], &f[3], life, 0x804040, rint, 0, 0x7F,
                                      state->scale * 0.800000011920929f * 210000.0f,
                                      func_003824E0(state->scale * 0.30000001192092896f, state->scale * 0.5f) * 210000.0f,
                                      0.0f, 6);
                if (p != 0) {
                    p[2] = *D_L01_00221098[23];
                }
            }
            s20 = state->scale * 0.800000011920929f;
            s23 = state->scale * 0.4000000059604645f;
            s22 = state->scale * 0.6000000238418579f;
            func_L01_004C7D98((self + 0x10), &f[4]);
            ((Fn_CF68_3749E8)func_0038CF68)(&f[4], &f[4], -5.0f);
            vec_add_ab(&f[5], (self + 0x10), &f[4]);
            if (func_003D3CB0((self + 0x10), &f[5], 0, self, 0)) {
                *(vu0_q *)&f[2] = *(vu0_q *)(D_L01_001EAA00.f20 + 0x20);
                *(vu0_q *)&f[3] = *(vu0_q *)D_L01_001EAA00.f20;
                ((Fn_CF68_3749E8)func_0038CF68)(&f[2], &f[2], 0.05f);
                vec_add_ba(&f[3], &f[3], &f[2]);
                ((Fn_CF68_3749E8)func_0038CF68)(&f[2], &f[2], 1.0f);
                vec_sub_ab(&f[6], D_L01_001E2A40, (self + 0x10));
                func_0038CE90(&f[7], &f[6], &f[2]);
                ((Fn_CF68_3749E8)func_0038CF68)(&f[7], &f[7],
                              func_003824E0(state->scale + state->scale, state->scale * 3.0f));
                for (ic = 0; ic < 5; ic++) {
                s32 rint;
                s32 life;
                u8 *p;
                    rint = (s32)func_L01_00443A18(2.0f, 5.0f);
                    func_0038D890(&f[8], &f[7], &f[2], func_00382538());
                    {
                        vu0_q x, y, c;
                        __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)(self + 0x10)));
                        *(vu0_q *)&f[11] = c;
                        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[8]));
                        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[3]));
                        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                        *(vu0_q *)&f[8] = x;
                        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[8]));
                        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[11]));
                        __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(x), "j"(y));
                        __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[9]) : "j"(c));
                    }
                    ((Fn_CF68_3749E8)func_0038CF68)(&f[9], &f[9], state->scale * 4.0f * 0.020000001415610313f);
                    life = func_00382498(20, 25) * 5;
                life = life + 2;
                life = life / 6;
                    p = func_L01_004713C8(&f[8], &f[9], life, 0x404040, rint, 0, 0x7F,
                                          s20 * 210000.0f,
                                          func_003824E0(s23, s22) * 210000.0f, 0.0f, 6);
                    if (p != 0) {
                        p[2] = *D_L01_00221098[23];
                        if (ic == 3) {
                            p[3] = 0x44;
                        }
                    }
                    if (ic == 3) {
                        if (func_00382468(2)) {
                            f32 s;
                            s32 col;
                            u8 *p2;
                            s = func_003824E0(0.05999999865889549f, 0.12999999523162842f);
                            col = func_00382468(3) ? 0x263438 : 0x273538;
                            ((Fn_CF68_3749E8)func_0038CF68)(&f[9], &f[9], 0.1300000101327896f);
                            n = func_00382498(15, 20);
                            p2 = func_L01_004713C8(&f[8], &f[9], (n * 5 + 2) / 6, col, -2, 0x7F, 0x7F,
                                                  s * 210000.0f, s * 210000.0f,
                                                  0.006240000482648611f, 0);
                            if (p2 != 0) {
                                p2[2] = (D_L01_00221098[0x61])[func_00382468(3) + 0xA];
                                p2[3] = 0x44;
                            }
                        }
                    }
                }
            }
            ((Fn_CF68_3749E8)func_0038CF68)(&f[2], D_L01_001E2DC0, -0.05000000074505806f);
            vec_add_ba(&f[3], D_L01_001E2DC0, (self + 0x10));
            vec_add_ab(&f[3], &f[3], &f[2]);
            ((Fn_CF68_3749E8)func_0038CF68)(&f[6], &D_L01_001E2DC0[2],
                          func_003824E0(state->scale + state->scale, state->scale * 3.0f));
            for (id2 = 0; id2 < 5; id2++) {
                s32 rint;
                s32 life;
                u8 *p;
                rint = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&f[7], &f[6], &f[2], func_00382538());
                {
                    vu0_q x, y, c;
                    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)(self + 0x10)));
                    *(vu0_q *)&f[12] = c;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[7]));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[3]));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    *(vu0_q *)&f[7] = x;
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[7]));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[12]));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[8]) : "j"(c));
                }
                ((Fn_CF68_3749E8)func_0038CF68)(&f[8], &f[8], state->scale * 4.0f * 0.020000001415610313f);
                life = func_00382498(20, 25) * 5;
                life = life + 2;
                life = life / 6;
                p = func_L01_004713C8(&f[7], &f[8], life, 0x404040, rint, 0, 0x7F,
                                      s20 * 210000.0f,
                                      func_003824E0(s23, s22) * 210000.0f, 0.0f, 6);
                if (p != 0) {
                    p[2] = *D_L01_00221098[23];
                    if (id2 == 3) {
                        p[3] = 0x44;
                    }
                }
            }
        }
        if ((D_L01_002C5600 + D_001425C0[0x5F])->level >= 4) {
            n = func_003D4D00((self + 0x10), 1, state->scale + 4.5f, (void *)D_001A4BE0.w[0x25C0 / 4], 0);
            if (n > 0) {
                u8 **tbl = D_L01_001EEA80;
                for (k1 = n; k1 != 0; k1--, tbl++) {
                    u8 *m;
                    u8 *cls;
                    s32 id, cc;
                    u8 *q;
                    m = *tbl;
                    if (m == 0) {
                        continue;
                    }
                    cls = *(u8 **)(m + 0x24);
                    if (cls == 0 || cls[0x46] != 5) {
                        if (!func_003C4B50(m)) {
                            continue;
                        }
                        m = *tbl;
                    }
                    id = *(s16 *)(m + 0xAA);
                    if (id == 0x1F8) {
                        continue;
                    }
                    if (id == 0x1699) {
                        continue;
                    }
                    cc = 0x165C;
                    if (id == cc) {
                        continue;
                    }
                    cc = 0x1612;
                    if (id == cc) {
                        continue;
                    }
                    cc = 0x16FA;
                    if (id == cc) {
                        continue;
                    }
                    cc = 0x16CB;
                    if (id == cc) {
                        continue;
                    }
                    if (*(u16 *)(m + 0x34) & 2) {
                        continue;
                    }
                    q = func_00382348(m);
                    if (q == 0 || q[0x34] == 0) {
                        continue;
                    }
                    zf = 0.0f;
                    if (!(zf < *(f32 *)q)) {
                        continue;
                    }
                    if (func_00382468(0x12) == 0) {
                        *(vu0_q *)&f[2] = *(vu0_q *)(*tbl + 0x10);
                        func_L01_0034E558(*tbl, 0x800530, &f[2], self, 0);
                    }
                }
            }
        }
        target = state->target;
        if (target == 0) {
            s32 count;
                        count = func_003D4D00((self + 0x10), 1, state->scale + 9.0f, (void *)D_001A4BE0.w[0x25C0 / 4], 0);
            for (k2 = 0; k2 < count; k2++) {
                u8 *m;
                u8 *cls;
                s32 id, cc;
                u8 *q;
                m = D_L01_001EEA80[k2];
                if (m == 0) {
                    continue;
                }
                cls = *(u8 **)(m + 0x24);
                if (cls == 0 || cls[0x46] != 5) {
                    if (!func_003C4B50(m)) {
                        continue;
                    }
                    m = D_L01_001EEA80[k2];
                    cc = 0x1F8;
                } else {
                    cc = 0x1F8;
                }
                id = *(s16 *)(m + 0xAA);
                if (id == cc) {
                    continue;
                }
                if (id == 0x1699 || id == 0x165C || id == 0x1612 || id == 0x16FA ||
                    id == 0x16CB) {
                    continue;
                }
                if (*(u16 *)(m + 0x34) & 2) {
                    continue;
                }
                q = func_00382348(m);
                if (*(s16 *)(D_L01_001EEA80[k2] + 0xAA) == 0x1BF5 && q != 0) {
                    f32 d = *(f32 *)q;
                    if (0.0f < d &&
                        d <= ((D_L01_002C5600 + D_001425C0[0x5F])->damage * state->scale) * 2.0f) {
                        q[0x2E] = 1;
                        return;
                    }
                }
                if (func_003C4B50(D_L01_001EEA80[k2])) {
                    state->target = D_L01_001EEA80[k2];
                    *(vu0_q *)&f[2] = *(vu0_q *)&state->velocity;
                    func_0038CE20(&f[2], &f[2], 3.0f);
                    f[2].w = 5627.9248046875f;
                    func_L01_00446760(&f[3], self, 0x10000, &f[2], 1.0f);
                    ((HitInfo *)&f[3])->f19 = 1;
                    ((HitInfo *)&f[3])->f1A = *(u16 *)(self + 0xAA);
                    ((HitInfo *)&f[3])->f18 = 0;
                    func_003D4D00(D_L01_001EEA80[k2] + 0x10, 0, 1.0f, self, &f[3]);
                    return;
                }
                if (q == 0 || q[0x34] == 0) {
                    continue;
                }
                if (!(0.0f < *(f32 *)q) || q[0x2E] != 0) {
                    continue;
                }
                if (!(*(f32 *)q <= ((D_L01_002C5600 + D_001425C0[0x5F])->damage * state->scale) * 2.0f)) {
                    continue;
                }
                {
                    u8 **list0 = func_L01_00448FB8(D_L01_001EEA80[k2]);
                    if (list0 != 0) {
                        u8 **list = list0;
                        for (ie = 0; ie < 4; ie++, list++) {
                            if (*list != 0) {
                                u8 *r = func_00382348(*list);
                                if (r != 0) {
                                    r[0x2E] = 1;
                                }
                            }
                        }
                    }
                }
                func_L01_00374908(self, D_L01_001EEA80[k2]);
                if (state->target != D_L01_001EEA80[k2]) {
                    return;
                }
                *(vu0_q *)&f[2] = *(vu0_q *)&state->velocity;
                func_0038CE20(&f[2], &f[2], 3.0f);
                f[2].w = 5627.9248046875f;
                func_L01_00446760(&f[3], self, 0x10000, &f[2], 0.0f);
                ((HitInfo *)&f[3])->f19 = 1;
                ((HitInfo *)&f[3])->f1A = *(u16 *)(self + 0xAA);
                ((HitInfo *)&f[3])->f18 = 0;
                func_003D4D00(D_L01_001EEA80[k2] + 0x10, 0, 1.0f, self, &f[3]);
                return;
            }
            return;
        }
        {
        u8 *qt = func_00382348(target);
        if (qt == 0) {
            state->target = 0;
            return;
        }
        if (qt[0x2E] != 0) {
            state->target = 0;
            return;
        }
        }
        *(u16 *)(state->target + 0x34) |= 2;
        func_L01_00448340(state->target + 0x10, (self + 0x10), state->pad58,
                          state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                          state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                          state->f90 * state->scale * 1.5f * 0.020000001415610313f);
        {
        u8 **tbl0 = func_L01_00448FB8(state->target);
        if (tbl0 != 0) {
            u8 **tbl = tbl0;
            for (if_ = 0; if_ < 4; if_++, tbl++) {
                if (*tbl != 0) {
                    func_L01_00448340(*tbl + 0x10, (self + 0x10), state->pad98,
                                      state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                                      state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                                      state->f90 * state->scale * 1.5f * 0.020000001415610313f);
                    *(f32 *)(*tbl + 0xF8) = func_0038DAB8(*(f32 *)(*tbl + 0xF8), 0.30000001192092896f);
                    *(f32 *)(*tbl + 0xF0) = func_0038DAB8(*(f32 *)(*tbl + 0xF0), 0.10000000149011612f);
                    *(f32 *)(*tbl + 0xF4) = func_0038DAB8(*(f32 *)(*tbl + 0xF4), -0.20000000298023224f);
                    *(f32 *)(*tbl + 0x2C) = *(f32 *)(*tbl + 0x2C) * 0.9519999623298645f;
                    func_0038D308(*tbl + 0xC0, *tbl + 0xF0);
                }
            }
        }
        }
        if (state->f94 < 30) {
            *(f32 *)(state->target + 0x2C) = *(f32 *)(state->target + 0x2C) * 0.9900000095367432f;
            state->f94++;
        }
        *(f32 *)(state->target + 0xF8) = func_0038DAB8(*(f32 *)(state->target + 0xF8), 0.30000001192092896f);
        *(f32 *)(state->target + 0xF0) = func_0038DAB8(*(f32 *)(state->target + 0xF0), 0.10000000149011612f);
        *(f32 *)(state->target + 0xF4) = func_0038DAB8(*(f32 *)(state->target + 0xF4), -0.20000000298023224f);
        func_0038D308(state->target + 0xC0, state->target + 0xF0);
        func_003C7C38(state->target);
        if (!(func_0038CF00(state->target + 0x10, (self + 0x10)) < 0.10000000149011612f)) {
            return;
        }
        *(u16 *)(state->target + 0x34) &= 0xFFFD;
        q = func_00382348(state->target);
        if (q != 0) {
            if (D_001D7BE0_sda < 0x29) {
                if (D_001D7BE0_sda != 9) {
                    n = func_L01_00444350();
                    pd = D_00142DE0;
                    *(s32 *)(pd + 0x17C) += n;
                }
            } else {
                if (D_001D7BE0_sda != 9) {
                    u8 *pd2;
                    pd2 = D_00142DE0;
                    *(s32 *)(pd2 + 0x17C) += *(u16 *)(state->target + 0xB6);
                }
            }
            func_003A52A0(2, 0, self);
            q[0x2E] = 1;
        }
        if (func_003C4B50(state->target)) {
            p = state->target;
            qzero(p + 0xF0);
            p[0xA8] = 0xFF;
            *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24);
            *(s32 *)(*(u8 **)(p + 0x68) + 0x12C) = 0;
            func_L01_0033D0E8(p);
        }
        state->target = 0;
        for (ig = 0; ig < 3; ig++) {
            u8 *p;
            p = func_L01_004713C8((self + 0x10), &D_L01_001D66B0, 0x11, 0x204080, 5, 0, 0x7F,
                                  state->scale * 3.5f * 210000.0f,
                                  state->scale * 0.20000000298023224f * 210000.0f, 0.0f, 6);
            if (p != 0) {
                p[2] = *D_L01_00221098[0x59];
            }
        }
        return;
    case 3: {
        u8 *tg3 = state->target;
        if (tg3 != 0) {
            if (2500.0f < func_L01_0040E548((f32 *)(tg3 + 0x10), (f32 *)((self + 0x10)))) {
                *(u16 *)(state->target + 0x34) &= 0xFFFD;
                {
                u8 *t3 = func_00382348(state->target);
                if (t3 != 0) {
                    t3[0x2E] = 1;
                }
                }
            } else {
                self[0x20] = 2;
                state->timer = 0;
            }
        }
        if (++state->timer < 18) {
            func_L01_00404A10(func_L01_00376D08, self);
            return;
        }
        }
        break;
    case 4:
        if (state->target != 0) {
            self[0x20] = 2;
            state->timer = 0;
        }
        if (++state->timer < 18) {
            goto callback;
        }
        func_003A52A0(1, 0, self);
        break;
    default:
        return;
    }

    if (state->entry != -1) {
        entry = D_001A30B0 + state->entry * 0x80;
        if (*(u8 **)(entry + 0xDC) == self && entry[0xD0] != 0) {
            func_003A4F28(state->entry);
        }
    }
    state->entry = -1;
    func_L01_003779C8(self);
destroy:
    func_L01_004C8668(state->effect);
    func_003C2880(self);
    return;

callback:
    func_L01_00404A10(func_L01_00376D08, self);
}
