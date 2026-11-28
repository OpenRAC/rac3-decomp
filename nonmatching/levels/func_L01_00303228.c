/* c51 (wave 14c): re-measured unchanged under the cut line "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
 * -mvu0-use-vf0-vf2" (L01_00302118.c's line, the file before; split addresses): wc51/chk.py --line ... --target level_01
 * 8 diff (wc51/func_L01_00303228/try-01.log), the W20 rows below: reload's register for the spilled D_L01_001E29C0
 * vector (vf1 here, vf2 in retail) and the order of the two spill slots (0x100/0x110). The cut is a boundary move:
 * L01_00302118.c ends at 0x00303658 instead of 0x00303228 (0x00303658 8-aligned at all 34 places; func_L01_00303658
 * needs -mno-split-addresses: 2 diff under the S line, wc51/func_L01_00303228/sib-00303658-S.log). */
/* Round 27 W20: 8 raw differences (W13: 9; round 19: 12), measured at level 01 with tools/check.py --mode S --as ps2as
 * and the owning file's other flags. A match still needs the split-address file cut (see the J5D note below).
 * What W20 changed: the vector block is written as explicit VU0 asm statements (lqc2/vadd.xyz/sqc2 per operand) with the
 * memory operand of the F load typed vu0_q (TImode, 16 bytes) and the others typed vu0_v4 (struct = BLKmode). A BLK operand
 * conflicts with every earlier store in sched1, a TI operand only with the overlapping one. A sweep of 2^8 typings
 * of the eight memory operands (qld, qst, add c/f/store, sub c/D29C0/store, 200+ compiles): best 8, all-BLK 12,
 * W13's 9 = only the q store typed TI; every mix that types the c load TI too grows the frame by a spill slot (197-201).
 * Source order of the asm statements, the c.w store position, helper ab/ba order: no effect (sched1 reorders them).
 * What still differs (8 raw):
 * (1) retail's D29C0 load takes vf2 (spilled with sqc2 vf2,0x110, then the c load takes vf1, then the F load vf2); this C
 *     gets vf1 for it. The pre-reload (sched1) order is the same as retail's: q ld, swc1, q st, D29C0 ld, c ld, F ld,
 *     because the D29C0 load (insn 184) fills the free issue slot at t=15 beside the q store; the c/F loads depend on that
 *     store. The register is chosen by reload (order_regs_for_reload / the spill reg of the output reload of the spilled
 *     D29C0 pseudo): vf1 here, vf2 in retail.
 * (2) the spill slots: retail has the loop's &uv pointer at 0x100 and the vf spill at 0x110, this C the other way round.
 *     Slots are handed out in pseudo order (reload's alter_reg): the vf pseudo (174) is an expand-time pseudo, the pointer
 *     (287, `sp+0x50`) one that loop.c creates, so the vf slot comes first. A user-variable pointer (declared at the top,
 *     set before the loops) gets the slot 0x100 but becomes an allocated callee-saved register (no spill): 105 diffs.
 * Tried and not better: a separate local copy g of D29C0 (vec_copy(&g,..); sub from g; g outside or inside the struct): 15;
 * the loop's vec_sub_ba instead of ab: 9; extra vf pseudos in the loop to move the hard_reg_n_uses balance: reload still takes vf1;
 * one vu0_q variable reused for the add and the sub result (a 4-ref pseudo that spills: 11 / 200).
 * Retain INCLUDE_ASM. */
/* near miss (round 19 worker J5D): 7 aligned rows of 267 words (12 raw diffs, same length as retail) with `--mode S` (split addresses) and the file's other flags.
 * check.py --all-modes: S + ps2as 55 raw (before the fixes below), N 156: retail is built in S mode, but the file's line (L01_00302118.c) has -mno-split-addresses, so a
 * match needs a CUT: a new file at 0x303228 with `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2` (8-aligned at all 34 places) and the rest
 * (func_L01_00303658 on) in a file with the old line. An effect drawing a ring of 4 x 4 textured quads around the moby (GS packet on the stack, 0xFF90 / 0x260 tags):
 * the basis from the owner's matrix rows (func_0038CE90 / CF68), a random angle accumulated in D_L01_001E16E4, one func_003D9508 spawn, then the quad loop with
 * u / v = x * 0.5 + 0.5 wrapped by func_L01_0040F518(., 8.0).
 * What fixed most (32 -> 7): the owner pointer split into two variables (`owner` / `o2`: one variable set in two blocks is a global pseudo and took $a3), the colour stores
 * as an if / else with a store chain per arm, `extern u8 D_L01_001E16D0[8]` (the 8-byte `la` form gives retail's `lui $at; lqc2 vf1,lo($at)`), `r = &s.b0` early,
 * the gp table as `s16 D[4]` + `.extern D, 8` (`addiu $v1,$gp,-0x350`), no local copy of D_L01_001E29C0 (the vf pseudo is spilled by reload, as in retail).
 * Left (7 rows): (1) the vector block after the first func_003C5278 call: retail schedules `lqc2 vf1,D16D0; swc1 f20,0xcc; sqc2 vf1,0xf0; lqc2 vf2,D29C0($s0); lqc2 vf1,0xc0 ...`
 * with the D29C0 value in vf2 and its spill slot at 0x110, this C has the c.w store first and the D29C0 load in vf1; (2) the pointer spill slot: retail 0x100 (pointer) / 0x110
 * (vf spill), this C the other way round (reload numbers the slots by pseudo number: the vf pseudo comes before loop.c's hoisted `&uv` pointer here). Sweeps over the
 * position of `s.c.w = 1.0f`, of the vec_copy, of `r = &s.b0` and the helper forms (ab / ba) all stay at 7. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00303228 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00303228;
typedef struct {
    V_00303228 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
    V_00303228 b0, b1, b2;
    V_00303228 c, d, e, f;
} S_00303228;

extern s32 D_L01_001DC580;
extern s32 D_L01_001DC584;
extern s32 D_L01_001DC588;
extern s32 D_L01_001DC58C;
extern s32 D_L01_001DC590;
extern s32 D_L01_001DC594;
extern s32 D_L01_001DC598;
extern s32 D_L01_001DC59C;
extern s32 D_L01_001DC5AC;
extern f32 D_L01_001DC5B0;
extern s16 D_L01_001DC560[4];
__asm__(".extern D_L01_001DC580, 4");
__asm__(".extern D_L01_001DC584, 4");
__asm__(".extern D_L01_001DC588, 4");
__asm__(".extern D_L01_001DC58C, 4");
__asm__(".extern D_L01_001DC590, 4");
__asm__(".extern D_L01_001DC594, 4");
__asm__(".extern D_L01_001DC598, 4");
__asm__(".extern D_L01_001DC59C, 4");
__asm__(".extern D_L01_001DC5AC, 4");
__asm__(".extern D_L01_001DC5B0, 4");
__asm__(".extern D_L01_001DC560, 8");
extern u8 D_L01_001E16D0[8];
extern f32 D_L01_001E16E4;
extern V_00303228 D_L01_001E29C0;
extern V_00303228 D_L01_002A7CA0[];
extern V_00303228 D_L01_002A7DA0[];
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00301788(u8 *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern f32 func_L01_0040F518(f32, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_00303228(u8 *m)
{
    S_00303228 s;
    u8 *info;
    u8 *owner;
    u8 *o2;
    V_00303228 *tbl;
    V_00303228 *r;
    s32 i;
    s32 j;
    f32 ang;
    f32 u;
    f32 v;

    info = *(u8 **)(m + 0x68);
    if (info != 0) {
        s.x78 = func_00389598(D_L01_001DC594);
        s.x88 = (long)D_L01_001DC580 | ((long)D_L01_001DC584 << 2) | ((long)D_L01_001DC588 << 4) | ((long)D_L01_001DC58C << 6)
                | ((long)D_L01_001DC590 << 32);
        s.x80 = 0xFF9000000260L;
        s.x70 = 0;
        func_003A9440(0x47, 0x53001);
        if (m[0x20] == 1) {
            owner = *(u8 **)(m + 0xB8);
            *(vu0_q *)(m + 0x10) = *(vu0_q *)(owner + 0x10);
            *(vu0_q *)(info + 0x10) = *(vu0_q *)(owner + 0x10);
            func_003C5278(m + 0x10, info + 0x10, info + 0x10, -0.5f);
        }
        r = &s.b0;
        s.c.x = *(f32 *)(m + 0x10);
        s.c.y = *(f32 *)(m + 0x14);
        s.c.z = *(f32 *)(m + 0x18);
        func_003C5278(m + 0x10, &s.c, &s.c, -0.5f - *(f32 *)info);
        {
            vu0_q q, qa, qb, qr, qc, qd, qs;
            __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_v4 *)D_L01_001E16D0));
            s.c.w = 1.0f;
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&s.f) : "j"(q));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)&s.c));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_q *)&s.f));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&s.c) : "j"(qr));
            __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(*(vu0_v4 *)&s.c));
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(*(vu0_v4 *)&D_L01_001E29C0));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qs) : "j"(qd), "j"(qc));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&s.e) : "j"(qs));
        }
        func_0038CF68(r, &s.e, 1.0f);
        func_0038CE90(&s.b1, r, *(u8 **)(m + 0xB8) + 0xE0);
        func_0038CF68(&s.b1, &s.b1, 1.0f);
        func_0038CE90(&s.b2, &s.b1, r);
        if (info[0x57] != 0) {
            s.c40 = s.c44 = s.c48 = s.c4C = D_L01_001DC59C;
        } else {
            s.c40 = s.c44 = s.c48 = s.c4C = D_L01_001DC598;
        }
        ang = func_0038DAB8(D_L01_001E16E4, func_003824E0(-0.15f, -0.3f) * 0.017453292f);
        D_L01_001E16E4 = ang;
        func_003D9508(info + 0x10, 0x59, info[0x57] != 0 ? 0x4F7F207F : 0x4FFF2020, 1, 0.4f, 0.0f, ang);
        if (func_L01_00301788(m) != 0) {
            s.x78 = func_00389598(D_L01_001DC5AC);
            s.c40 = s.c44 = s.c48 = s.c4C = 0x107F7F7F;
            s.x88 = 0x8000000044L;
            o2 = *(u8 **)(m + 0xB8);
            *(vu0_q *)&s.b0 = *(vu0_q *)(o2 + 0xC0);
            *(vu0_q *)&s.b1 = *(vu0_q *)(o2 + 0xD0);
            *(vu0_q *)&s.b2 = *(vu0_q *)(o2 + 0xE0);
            s.c.z = *(f32 *)(m + 0x18);
            if (*(s16 *)(o2 + 0xAA) == 0x1F5) {
                tbl = D_L01_002A7DA0;
            } else {
                tbl = D_L01_002A7CA0;
            }
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    func_0038D028(&s.m[j], &tbl[D_L01_001DC560[i * 4 + j]], &s.b0);
                    vec_sub_ab(&s.d, &s.m[j], &D_L01_001E29C0);
                    s.d.y = s.d.z;
                    func_0038CFB8(&s.d, &s.d, D_L01_001DC5B0);
                    u = s.d.x * 0.5f + 0.5f;
                    s.uv[j][0] = u;
                    s.uv[j][0] = func_L01_0040F518(u, 8.0f);
                    v = s.d.y * 0.5f + 0.5f;
                    s.uv[j][1] = v;
                    s.uv[j][1] = func_L01_0040F518(v, 8.0f);
                }
                func_003D2DA0(&s, 0, 0);
            }
        }
        func_003A9440(0x47, 0x5360B);
    }
}
/* localdecomp:end func_L01_00303228 */
