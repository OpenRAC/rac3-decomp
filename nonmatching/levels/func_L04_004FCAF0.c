/* Level 4 (Marcadia), file L04_004FCAF0.c. Promises fleet near miss (2026-11-20), reworked 2026-11-21 (tasks 2784, 2796).
 * Needs -mvu0-use-vf0-vf2 and @ps2as on that one-function file (VU0 adds, inline float constants, the lui form of
 * D_001D6694) and the divs_nops line `func_L04_004FCAF0 1` (retail has one nop before its div.s). Measured with
 * `check.py --as ps2as --flags=-mvu0-use-vf0-vf2` and that line added: 52 diff (12 aligned; the 2026-11-20 draft:
 * 72 diff, 26 aligned with the line, 41 aligned without it).
 * Found: the first early-return group is two ifs (`f25CC == 0x14 || f25CC == 7`, then `f25C4 == 0x74`), which keeps
 * retail's return-0 block right after it, and the index is read twice (`D_001A4BE0.f25C0[0xA8]` in the test and in
 * the subscript), which gives retail's registers.
 * Left: the final VU0 block. Retail loads `vec` into vf1 once and uses it for both the copy to tmp and the add into
 * hero.F0 (lqc2 vec, lqc2 F0, sqc2 tmp, vadd, sqc2 F0, then the F110 add); the vu0.h helpers load it twice. A j-form
 * block in the function (one asm per instruction) gets the sharing but makes gcc keep &D_001A4BE0 in a register in
 * every switch case (196 diff), and the else branch's `addiu $v1` placement.
 * Task 2796: retail's encodings give vec in vf1, F0 in vf2 and the first sum in vf2, with the `lqc2` of vec first and
 * the `sqc2` to tmp before the vadd. A file-local j-form helper that loads vec once, stores it to tmp and adds it
 * (in all 34 statement orders the dependences allow, with the sum in a fresh variable, in a's or in b's, and
 * vec_add_ab or vec_add_ba for the second add) gives 196 or 197 diff: gcc always puts vec in vf2, and the
 * `lui $v0, 0x1a` of &D_001A4BE0 is scheduled first in the block, so reorg copies it into the switch cases' branch
 * delay slots. Stopped per AGENTS.md.
 * Task #2882 (2026-11-22): re-measured 52 differences (tools/check.py) at level 04 with --as ps2as,
 * --flags=-mvu0-use-vf0-vf2 and the divs_nops line. Retail's `tmp` looks like a reload spill slot of one shared
 * vec value rather than a written copy: vec is loaded once into vf1, stored to sp+0x10 right after, and reloaded
 * into vf2 for the F110 add. Two vec_add_ba calls with vec as the second source (no vec_copy, no tmp) do share one
 * load: gcc's CSE merges the two equal `lqc2` asms from the same helper line. But the value then stays in vf2 for
 * both adds, nothing is spilled, and the frame loses 0x10 (193 differences, mostly the frame offsets; ab/ab 193,
 * ab/ba and ba/ab 195). An unused `tmp` local does not size the frame back. *
 * Task #2998 (2026-11-23): 2 differences (tools/check.py, --as ps2as --flags=-mvu0-use-vf0-vf2, the divs_nops
 * line; also with --no-context) at levels 04, 08 and 27. Two changes:
 * 1. The vec value is one TI variable loaded once and used by both adds, with no tmp. With only vf1/vf2 to
 *    allocate, reload spills it: the lqc2 into vf1, the sqc2 to the spill slot at sp+0x10 and the reload into vf2
 *    for the F110 add are retail's `tmp`. F110 is p[2] of p = &D_001A4BE0.fF0, which gives retail's fresh
 *    `lui $v0`, the %lo access of F0 and `addiu $v1, $v0, 0x4cd0` with F110 at 0x20($v1). That block is inline
 *    VU0 j-form (one asm per instruction; PROVISIONAL, r3-34).
 * 2. One `return 1` after the if/else instead of one at the end of each branch. The VU0 block then branches to
 *    the shared `addiu $v0, 1` (retail's `b` with that addiu in its delay slot), so sched1 no longer hoists the
 *    return value and the lui gets $v0, as in retail.
 * Left: the spill store `sqc2 vf1, 0x10($sp)` comes before `lqc2 vf2, F0` where retail has it after. Both issue
 * in the same sched2 cycle (ready list `835 839 1060`, gcc takes the spill store 1060). Unchanged at 2 by: the
 * F0 and vec loads in either source order, p set before or after the vec load or outside the block, reused
 * TI variables for the sums, TImode instead of BLKmode memory operands, a plain C load of F110. An explicit
 * tmp store instead of the spill gives 196 (the lui goes first again); plain C loads of vec or F0 give 53-204.
 * NTSC-U (--version us): 15 differences, real ones (the 0x40/0xF timers and the float constants differ), plus
 * the same pair.
 * CLOSEOUT attempt 1 of 2 (task #3020, 2026-11-24, upstream 9f380a0a): still 2 differences at levels 04, 08 and
 * 27 (check.py --no-context, recipe line and divs row in the working tree). What decides the tie: SN's cc1 takes
 * `-fsched-verbose-5` (dash; the `=` form is ignored), whose "Region Dependences" table shows the spill store
 * and the F0 lqc2 equal on priority (7 and 7) and dependent count (4 and 4), and neither depends on the last
 * scheduled insn (the lui), so the LUID decides. Reload puts the spill store right after the vec lqc2, which
 * sched1 issues with the lui in cycle 1, before the F0 lqc2 (it needs the lui). So the store always has the
 * lower LUID. The priority tie can't be broken here: an asm producer or an asm consumer makes a link cost 1,
 * and only the spill store's link to its reload (both movti) costs 3. Tried this attempt: a plain C TImode
 * store of F0 (through p or the symbol) gives 7, because gcc puts the address in a register (addiu $v0,
 * sqc2 0($v0)) where retail has %lo($v0), so retail's F0 store is the asm; adding a plain C load of F110 to
 * it gives 7; plain C stores of F110 give 45 and 49; p set outside the block (before the switch 164, at the
 * top of the apply branch, after func_L01_004E1560 or after flag = 0: 303). */
#include "common.h"

/* localdecomp:start func_L04_004FCAF0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x80];
    vu0_v4 f80;
    u8 pad90[0x60];
    vu0_v4 fF0;
    u8 pad100[0x10];
    vu0_v4 f110;
    u8 pad120[0xBC];
    s16 f1DC;
    u8 pad1DE[0x3E];
    s16 f21C;
    u8 pad21E[0x16];
    s32 f234;
    u8 pad238[0x1241];
    u8 f1479;
    u8 pad147A[0x236];
    s32 f16B0;
    u8 pad16B4[0xF0C];
    u8 * f25C0;
    s32 f25C4;
    u8 pad25C8[0x4];
    s32 f25CC;
    u8 pad25D0[0x14];
    u8 f25E4;
    u8 pad25E5[0x223];
    u8 * f2808;
    u8 pad280C[0x44];
    s32 f2850;
} Hero_L04_004FCAF0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 *src;
    u32 flags;
    u8 kind;
    u8 pad29[3];
    f32 dmg;
    u32 f30;
    u8 pad34[4];
    u8 *target;
    u8 pad3C[4];
} Hit_L04_004FCAF0;

__asm__(".extern D_001A4BE0, 16");
extern Hero_L04_004FCAF0 D_001A4BE0;
extern s32 D_001D6694;
extern u8 D_00142660[];
extern s16 D_001426A0[];
extern Hit_L04_004FCAF0 D_L04_001ED800[];
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L04_0050CB28(s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern s32 func_L01_003F1F20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);

s32 func_L04_004FCAF0(s32 apply) {
    Hit_L04_004FCAF0 *e;
    u8 *src;
    u8 *hit;
    s32 n;
    s32 flag;
    s16 cls;
    vu0_v4 vec;

    if (D_001A4BE0.f25CC == 0x14 || D_001A4BE0.f25CC == 7) {
        return 0;
    }
    if (D_001A4BE0.f25C4 == 0x74) {
        return 0;
    }
    if (D_001A4BE0.f25C4 == 0x31 || D_001A4BE0.f1DC != 0 || D_001D6694 != 0) {
        return 0;
    }
    D_001A4BE0.f2808 = 0;
    if (D_001A4BE0.f25C0[0xA8] == 0xFF) {
        return 0;
    }
    e = &D_L04_001ED800[D_001A4BE0.f25C0[0xA8]];
    if (e->target != D_001A4BE0.f25C0) {
        return 0;
    }
    if (!(e->flags & 9)) {
        return 0;
    }
    if (D_001A4BE0.f234 != 0) {
        return 0;
    }
    if (e->dmg != 0.0f && func_L01_0041A4F0() && D_001A4BE0.f25E4 != 5) {
        D_00142660[0x5A] = 0;
        D_00142660[0x5B] = 0;
    }
    if (func_L01_004C93D8() != 0.0f && D_001A4BE0.f25E4 == 0 && !(e->flags & 0x20000000)) {
        e->dmg = func_L01_004C9360(e->dmg);
        if (e->dmg == 0.0f) {
            return 0;
        }
    }
    if ((e->flags & 0x20000000) && D_001A4BE0.f25E4 == 0) {
        n = D_001426A0[0];
        if (n > 4) {
            n = 4;
        }
        if (n < 0) {
            n = 0;
        }
        e->dmg /= func_L01_004DFE88(n);
    }
    D_001A4BE0.f2808 = e->src;
    if (apply != 0) {
        func_L01_004E1560();
        flag = 0;
        if (e->f30 & 1) {
            vec = e->pos;
            if (e->pos.w == 5627.9248f) {
                flag = 1;
            }
        } else {
            src = e->src;
            if (src != 0) {
                vec_sub_ba(&vec, &D_001A4BE0.f80, src + 0x10);
            } else {
                func_L01_005110E8(&vec, 0, -1.0f, 0.0f, 0.0f);
            }
        }
        switch (D_001A4BE0.f25E4) {
        case 0:
            if (D_001A4BE0.f2808 != 0) {
                cls = *(s16 *)(D_001A4BE0.f2808 + 0xAA);
                if (cls == 0x4EB || cls == 0x558 || cls == 0x1C5F) {
                    func_L04_0050CB28(0x82, 1);
                    return 1;
                }
            }
            if ((D_001A4BE0.f25C4 == 1 || D_001A4BE0.f25C4 == 0x1D || D_001A4BE0.f16B0 == 2) && !(e->flags & 8)) {
                hit = func_L01_00447490(D_001A4BE0.f25C0, 1, 0);
                if (hit != 0) {
                    func_L01_004DFEA0(*(f32 *)(hit + 0x2C));
                }
                if (D_001A4BE0.f2850 == 0) {
                    func_L04_0050CB28(0x16, 1);
                } else {
                    func_L01_003F1F20(0x12, 0);
                }
                D_001A4BE0.f1DC = 0x40;
                if (D_001A4BE0.f21C == 0) {
                    D_001A4BE0.f21C = 0xF;
                }
                func_L01_004F4E70(0x14, 0);
                return 0;
            }
            if (D_001A4BE0.f25CC == 0x12) {
                func_L04_0050CB28(0x77, 1);
            } else if (D_001A4BE0.f25CC == 0x11) {
                func_L04_0050CB28(0x78, 1);
            } else if (e->flags & 8) {
                func_L04_0050CB28(0x91, 1);
            } else {
                func_L04_0050CB28(0x16, 1);
            }
            if (D_001A4BE0.f25C4 == 0x91) {
                qzero(&vec);
            } else {
                func_L01_004ED838(&vec, flag, D_001A4BE0.f1479 ? 0.0f : 0.0660000071f, 0.0340000018f);
                if (flag && e->kind == 4) {
                    func_L01_00511618(&vec, &vec, 2.0f);
                }
            }
            break;
        case 1:
            func_L04_0050CB28(0x42, 1);
            func_L01_004ED838(&vec, flag, 0.0600000024f, 0.0600000024f);
            break;
        case 3:
            func_L04_0050CB28(0x55, 1);
            func_L01_004ED838(&vec, flag, 0.100000009f, 0.0480000041f);
            break;
        }
        {
            /* PROVISIONAL, VU0 j-constraint form */
            vu0_q v, a, b, r, s;
            vu0_v4 *p = &D_001A4BE0.fF0;
            __asm__("lqc2 %0, %1" : "=j"(v) : "m"(vec));
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*p));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(v));
            __asm__("sqc2 %1, %0" : "=m"(*p) : "j"(r));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p[2]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(s) : "j"(b), "j"(v));
            __asm__("sqc2 %1, %0" : "=m"(p[2]) : "j"(s));
        }
    } else {
        if (D_001A4BE0.f1DC != 0) {
            return 1;
        }
        hit = func_L01_00447490(D_001A4BE0.f25C0, 1, 0);
        if (hit != 0) {
            func_L01_004DFEA0(*(f32 *)(hit + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        D_001A4BE0.f1DC = 0x40;
    }
    return 1;
}
/* localdecomp:end func_L04_004FCAF0 */
