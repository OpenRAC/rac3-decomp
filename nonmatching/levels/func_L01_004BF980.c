/* Round 29 W26 (114 -> 89 aligned, 958 vs 961 words), four levers:
 * (1) callees whose result retail ignores declared `extern s32` (func_L01_005147A8, func_003A2750; both already `extern s32`
 * in other files): the call's dead $v0 result keeps $v0 busy, so the mode-5 `lui $v1,0x14; lh $a0,0x26a0($v1)` and
 * `lw $v1,0x80($s1)` temps take $v1 as retail, mode 0 too (-11). A sweep of the other void callees: no gain (func_003C7C38,
 * func_003C6F90, func_003C29B0 as s32 are worse, func_00398BB8 106).
 * (2) mode-2 loop pointer (-9, loop body now retail's): -dL shows loop.c hoists `reg = &D + 84` (the f54 base, a separate
 * movable insn, then strength-reduces f54[k] into a walking pointer) only when the loop has at most 64 real insns in its second
 * pass ("not desirable" at 65, "moved" at 64; confirmed by deleting one store). Retail's hoisted D_00143950 pointer makes the loop
 * smaller than that, so one insn that combine removes later is added: `fl = pl[0xAD] != 0` (s32 fl), with `pl = (u8 *)D_00143950;
 * msk = 0x80000000;` as the first two statements INSIDE the loop body (loop.c hoists both, in retail's order: addiu $s7 pp, lui
 * $s6 msk) and the select through an f32 local `cv = fl ? 1.45f : 2.0f; ffC8 = cv;` (written directly into the store the select
 * is duplicated into both arms: one extra g reference, which flips the global-alloc priority of g/sq/i: refs*log2(refs)/length,
 * g needs 15 refs or less to be allocated after i and sq as retail: sq $s1, i $s2, g $s3).
 * (3) the post-loop `if ((u16 field & 0x1F) != D_0016C580[12])` with the field read first: retail's lhu-before-addiu order (-4).
 * (4) mode-2 `odd`: the third ternary as `if (odd & 0xFF) cv = a; else cv = b; ffAC = func_0038DAB8(cv, pi)` brings back retail's
 * third `andi $v0,$a0,0xff` (cse merged it with the second; +2 words), and `(u8)(sel & 1)` at the first use (-1).
 * Left in the loop: the load-delay `nop` after `lw $v1,0x2c($s3)` (one word), sh 0x32 / sb 0x23 / sh 0x34 order.
 * Not yet explained: mode-2 head ($v0 = li 10 in the bne slot, hi of D_001D54D0 in $a0), the four `lw $v1,($a3)` reload
 * positions, odd (retail `andi $v0,$t0,1; move $a0,$v0; andi $v0,$v0,0xff`), the 0x40/0x2010 $a1/$a3 swap (equal local-alloc
 * priority, pseudo-number tie), tail addu operand order, `b88 = 1` reusing $s2. */
/* Round 29 W6 (140 -> 114 aligned, 955 vs 961 words): (0) the mode-5/3 D_00251400 block: memset both halves through the
 * symbol, then `for (j...) { a = D_00251400 + j * 0x40; call(.., a); stores at a + 0x20..0x28 }` (a assigned inside the
 * loop): retail's `lui $s0,0x25; addiu $s0,$s0,0x1400` in the slot and the single walking pointer in both copies (-4;
 * with an initial `a = D_00251400` the hi lands in a separate register). (1) the three D_001E14xx float stores as ONE symbol with
 * offsets, `extern f32 D_001E1404;` + (&D_001E1404)[1] = fa; (&D_001E1404)[-1] = fb; D_001E1404 = fb (this order):
 * gcc counts a store at symbol+offset (offset > 0 or < 0) as a 2-word macro, so reorg no longer pulls the last store
 * into the beqz delay slot (lui $s0 goes there as in retail) and ps2as emits retail's three lui/swc1 pairs; with the
 * +8/+4/0 spelling (base D_001E1400) sched1 swaps the last two stores (136); other bases/orders 128-140.
 * (2) the (sel & 1) ternaries: `s32 odd; odd = sel & 1;` and (u8)odd at the three uses = the three andi 0xff of
 * retail (the cast only survives for an s32/u32 local; u8 odd or odd = sel; odd &= 1 fold the mask): -4.
 * (3) tail without the t6 variable: `ta = *(s32 *)(to[0x42] * 4 + *(s32 *)(to + 0x24) + 0x48)` and
 * ((u8 *)*(s32 *)(to + 0x24))[8] at the use (idx evaluated first): retail's $v0/$v1 allocation of the tail temps (-6);
 * the addu operand order (retail: base first) still differs, source order of the sum does not change it.
 * Still differs (see also the older notes): `andi $v0,$t0,1; move $a0,$v0` (retail copies the and result into odd)
 * vs ours `andi $a0,$t0,1`; hi of D_00251400 lands in $v0 (ours `lui $v0,0x25; addiu $s0,$v0`) vs retail `lui $s0`;
 * v0/v1 ties of the mode-5 temps; the mode-2 head (retail `li 10` in the bne slot and `lui $a0,0x1d` just before its
 * lw; ours `lui $v0,0x1d` in the slot); mode-2 loop pointer: a function-level pp or a loop-local pl = D_00143950
 * hoists `lui/addiu` out of the loop like retail ($s7) but in the second loop.c pass the f54[k] store becomes a giv
 * (`add (plus (reg D) 84)`, benefit 7) and is strength-reduced (walking $s4 pointer): with no pl the giv is not
 * recognised (-dL dump: `giv of insn 2015 not worth while`), retail keeps it unreduced AND has the hoisted pointer;
 * `b88 = 1` in the t == 1 arm (cse reuses t = $s2; ternary/if-else-self/(t==1) forms do not help). */
/* Exploratory PAL draft (W32 round 27, reworked W21 and W38 round 28). Level 01, the owning file's flags plus --as ps2as
 * (retail's bytes use the SN assembler's macro forms); landing needs an 8-aligned file cut at 0x4BF980 with
 * @ps2as. 140 aligned instruction edits (difflib over check.py's lines; was 150 after W21, 345 before; frame 0x1C0
 * like retail, 949 vs 961 instructions; positional counts are meaningless while the lengths differ).
 * Round 28 levers: separate locals per mode/loop for e, sel, n, j, o, t6 (one pseudo shared by several modes
 * gets a call-saved/argument register that retail's separate ranges do not: -150 together); one function-level v
 * for the five slot shifts (global alloc); typed D_00251400 as u8[0x80] (S-mode split lui/addiu, a+0x40 stays
 * reg+const) and .extern D_001DAC60_sda,8 / D_001DABF0_sda u8[8] gp forms; eb = D.v.x24.e base pointer for the
 * entry reads (addiu $t6,$s1,0x148); pp = (u8 *)D_00143950 in the tail; fb = 0.97f set first; u32 f4c (srl);
 * mode 0 as `if (mode == 0) {...}` with the mode != 0 stores after it; |= 0x80000000 arms stored in reverse;
 * mode-3 store order 0x31,0x78,0x34,0x32,0x62 (120-permutation sweep).
 * W38 (150 -> 140): shared-tail stores in the order b88, f98, b89, f8c (sched1 reverses ties: the final order
 * 88,8c,98,89 with the last store in the `b` delay slot is retail's, -5); the mode-2 `else` arm of the A4/A8/AC
 * stores as A4, A8, AC (retail's `sw $zero,0xa8` last, -2); f54[0] = -1 before f54[1] = -1 (retail's 0x58 store
 * then 0x54 in the blez slot, -3).
 * Why the 12 missing words (949 vs 961): (1) the three D_001E14xx float stores: ours fills the beqz delay slot
 * with the LAST store (gcc treats it as a 1-word gp store; ps2as then emits `swc1 $f1,0x4b54($gp)`) while retail's
 * stores are `lui $at; swc1` pairs and the slot holds `lui $s0,0x25` (hi of D_00251400): -3 words per copy (mode 5
 * and mode 3 = 6) and the loop-alignment nop after `move $s1,$zero` (parity) -1 per copy (2); (2) the odd = sel & 1
 * ternaries: retail masks `andi $v0,$v0,0xff` three times (+5 words), gcc knows the nonzero bits;
 * (3) `lui/addiu` of D_00143950 is hoisted into $s7 in retail's mode-2 loop (`lbu 0xad($s7)`), ours folds
 * `lui $v1; lbu 0x39fd($v1)`; hoisting it (pp at the top of the loop body) works but turns the f54[k] store into a
 * walking pointer (182) whatever the k++ spelling (k++ first, f54[k++], k = k + 1).
 * Tried in W38 without gain: D_001E1404 as array/struct/size hint (array: hi shared in $s2, 157; struct BigF for
 * all three: split lui/%lo pairs, 170; .extern size 16: identical), N mode (466-486), a = D_00251400 above the
 * stores (192), idx = 10 moved (first/after eb/after tm/after f4c: 140-154), t - 1 == 0 and a `one` local for the
 * tail `b88 = 1` (identical: cse still reuses $s2 = t where retail has `addiu $v0,$zero,1`), odd = sel; odd &= 1
 * (combine drops the mask: identical), pp inside the loop (151/182).
 * Still differs: see above plus the v0/v1 ties of the loop index and entry address, the mode-2 pre-loop block
 * (retail: `addiu $v0,$zero,0xa` in the bne slot, mult $ac3 forms, reload of *ep one insn later), `u8` odd with
 * andi 0xff, and `sb $s2,0x88` (cse reuses t) vs retail `addiu $v0,$zero,1`. */
/* localdecomp:start func_L01_004BF980 */
extern S_00244740 D_L01_002446C0[];
typedef struct {
    s32 id[5];
} PreviewIds;
extern PreviewIds D_L01_001DADE0[];
extern s32 D_001D4B60;
extern s32 D_001DAC60_sda[2];
__asm__(".extern D_001DAC60_sda, 8");
extern s16 D_001426A0[];
extern s32 D_00143950[];
extern f32 D_001DBD38;
extern u8 D_001E13E0[8];
extern f32 D_001E1404;
extern u8 D_00251400[0x80];
extern s32 D_001D54D0[];
extern s32 D_0016C580[];
extern s16 D_001D6700[];
extern s16 D_001D6706[];
extern s16 D_001D6708[];
extern s16 D_001D670A[];
extern s16 D_001D670C[];
extern s32 D_001DADF4_sda;
__asm__(".extern D_001DADF4_sda, 4");
typedef struct { s32 id; s32 b; s32 c; s32 d; } MEnt;
typedef struct { s32 f0; u8 b4; u8 p5[3]; s32 f8; u8 pc[5]; u8 b11; u8 p12[2]; } E14;
typedef struct { s32 e; s32 w4; u8 p8[0x1C]; } E24;
typedef struct {
    u8 p0[0x1C]; s32 f1c, f20, f24; u8 p28[4]; u8 *objs; u8 p30[4]; s32 idx; u8 p38[0x14]; u32 f4c; s32 mode; s32 f54[2]; u8 p5c[0x14]; s32 f70;
    u8 p74[0xC]; s32 cur; u8 b84[4]; u8 b88; u8 b89; u8 p8a[2]; s32 f8c; f32 ffxx90; f32 ff94; s32 f98; u8 p9c[4]; s32 fa0; f32 ffA4; f32 ffA8; f32 ffAC; u8 pb0[0x10]; f32 ffC0; f32 ffC4; f32 ffC8; u8 pcc[0x74]; union { struct { s32 w140[2]; MEnt ent[8]; } m; E14 e14[8]; struct { u8 p[8]; E24 e[4]; } x24; } v; u8 p1e0[0x570]; s32 f750; u8 p754[0x14]; s32 f768;
} MG;
extern MG D_L01_002446C0_004BF980;
extern void func_L01_004BF950(void);
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001DABF0_sda[8];
__asm__(".extern D_001DABF0_sda, 8");
extern u8 D_001425C0_u8[];
extern u8 D_L01_002C5600[];
extern s32 func_L01_00419E60(u8 *, s32, s32);
extern void func_L01_0042D330(s32, s32);
extern s32 func_003A2750(s32);
extern char *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern s32 func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_003C25D8(u8 *, s32);
extern void func_003C6F90(u8 *, s32, s32, s32, s32);
extern void func_003C7C38(u8 *);
extern void func_003C29B0(u8 *);
extern s32 func_00381CB0(void);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038CB78(u8 *, s32, s32);
extern void func_L01_0043A430(s32, s32, u8 *);
extern void func_L01_0043C8F8(u8 *, s32, s32, s32);
extern void func_00398BB8(s32);
extern void func_00398C80(s32);

void func_L01_004BF980(void) {
    s32 mode;
    PreviewIds ids;
    u32 slots[20];
    s32 j5, j3, v, sel, sel5, sel3, sel0, e, e5, e3, e0, n, n5, n3, i, k, cnt;
    s32 odd;
    u8 *o;
    u8 *a;
    u8 *t6;
    s32 j;
    f32 fa, fb;
    u8 loc[0xF0];
    u32 msk;
    s32 *ep;
    u32 *sq;
    u8 *base;
    u8 *pp, *pq;
    u8 *to, *ta, *tt, *tm;
    E24 *eb;
    s32 fl;
    f32 cv;
    u8 *pl;

    if (D_L01_002446C0_004BF980.mode == 0) {
        return;
    }
    if (D_L01_002446C0_004BF980.b89 != 0) {
        func_L01_004BF950();
    }
    mode = D_L01_002446C0_004BF980.mode;
    o = D_L01_002446C0_004BF980.objs;
    D_L01_002446C0_004BF980.idx = 1;

    if (mode == 5) {
        D_L01_002446C0_004BF980.idx = 0;
        ids = D_L01_001DADE0[0];
        sel5 = D_L01_002446C0_004BF980.cur;
        e5 = D_L01_002446C0_004BF980.v.m.ent[sel5].id;
        if (e5 == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60 != e5 && D_L01_002446C0_004BF980.f768 == 0) {
                if (e5 == -1) {
                    func_L01_005147A8(0);
                    func_L01_00425978(D_001426A0[0]);
                } else {
                    func_L01_005147A8(e5);
                    func_L01_00425978(D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id);
                }
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_001DAC60_sda[D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id]));
        }
        if (ids.id[D_L01_002446C0_004BF980.idx] >= 0) {
            do {
                n5 = D_L01_002446C0_004BF980.idx;
                o = D_L01_002446C0_004BF980.objs + (n5 << 8);
                func_003C25D8(o, ids.id[n5]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                o[0x30] = 0;
                o[0x23] = 0;
                o[0x20] = 0;
                *(s32 *)(o + 0x98) = 0;
                *(s32 *)(o + 0xF0) = 0;
                *(s32 *)(o + 0xF4) = 0;
                *(s32 *)(o + 0x78) = 0x80808080;
                *(u16 *)(o + 0x32) = 0x40;
                o[0x31] = 1;
                *(u16 *)(o + 0x34) = 0x2010;
                o[0x62] = 0xFF;
                *(f32 *)(o + 0xF8) = 2.0f;
                func_003C7C38(o);
                o[0x42] = 0;
                o[0x43] = 0;
                func_003C29B0(o);
                if (D_001D4B60 >= 4 || func_00381CB0() > 0) {
                    if (*(s16 *)(o + 0xAA) == 0x50A) *(u16 *)(o + 0x34) |= 1;
                }
                if (!(D_001D4B60 < 3)) {
                    if (*(s16 *)(o + 0xAA) == 0xA73) *(u16 *)(o + 0x34) |= 1;
                }
                D_L01_002446C0_004BF980.idx = D_L01_002446C0_004BF980.idx + 1;
            } while (ids.id[D_L01_002446C0_004BF980.idx] >= 0);
        }
        func_0038CB78(D_001E13E0, 0, 0x40);
        func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x18, D_001E13E0);
        fb = 0.97f;
        fa = D_001DBD38;
        fb = fa * fb;
        (&D_001E1404)[1] = fa;
        (&D_001E1404)[-1] = fb;
        D_001E1404 = fb;
        if (D_001D4B60 < 3) {
            func_0038CB78(D_00251400, 0, 0x40);
            func_0038CB78(D_00251400 + 0x40, 0, 0x40);
            for (j5 = 0; j5 < 2; j5++) {
                a = D_00251400 + j5 * 0x40;
                func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x16 + j5, a);
                *(f32 *)(a + 0x20) = 0.01f;
                *(f32 *)(a + 0x24) = 0.01f;
                *(f32 *)(a + 0x28) = 0.01f;
            }
        }
        goto tail;
    }

    if (mode == 3) {
        D_L01_002446C0_004BF980.idx = 0;
        ids = D_L01_001DADE0[0];
        sel3 = D_L01_002446C0_004BF980.cur;
        e3 = D_L01_002446C0_004BF980.v.m.ent[sel3].id;
        if (e3 == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60 != e3 && D_L01_002446C0_004BF980.f768 == 0) {
                func_L01_00425978(e3);
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_001DAC60_sda[D_L01_002446C0_004BF980.v.m.ent[D_L01_002446C0_004BF980.cur].id]));
        }
        if (ids.id[D_L01_002446C0_004BF980.idx] >= 0) {
            do {
                n3 = D_L01_002446C0_004BF980.idx;
                o = D_L01_002446C0_004BF980.objs + (n3 << 8);
                func_003C25D8(o, ids.id[n3]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                o[0x30] = 0;
                o[0x23] = 0;
                o[0x20] = 0;
                *(s32 *)(o + 0x98) = 0;
                *(s32 *)(o + 0xF0) = 0;
                *(s32 *)(o + 0xF4) = 0;
                o[0x31] = 1;
                *(s32 *)(o + 0x78) = 0x80808080;
                *(u16 *)(o + 0x34) = 0x2010;
                *(u16 *)(o + 0x32) = 0x40;
                o[0x62] = 0xFF;
                *(f32 *)(o + 0xF8) = func_0038DB48(*(f32 *)(o + 0xF8));
                func_003C7C38(o);
                o[0x42] = 0;
                o[0x43] = 0;
                func_003C29B0(o);
                if (D_001D4B60 == 4) {
                    if (*(s16 *)(o + 0xAA) == 0x50A) *(u16 *)(o + 0x34) |= 1;
                }
                if (!(D_001D4B60 < 3)) {
                    if (*(s16 *)(o + 0xAA) == 0xA73) *(u16 *)(o + 0x34) |= 1;
                }
                D_L01_002446C0_004BF980.idx = D_L01_002446C0_004BF980.idx + 1;
            } while (ids.id[D_L01_002446C0_004BF980.idx] >= 0);
        }
        func_0038CB78(D_001E13E0, 0, 0x40);
        func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x18, D_001E13E0);
        fb = 0.97f;
        fa = D_001DBD38;
        fb = fa * fb;
        (&D_001E1404)[1] = fa;
        (&D_001E1404)[-1] = fb;
        D_001E1404 = fb;
        if (D_001D4B60 < 3) {
            func_0038CB78(D_00251400, 0, 0x40);
            func_0038CB78(D_00251400 + 0x40, 0, 0x40);
            for (j3 = 0; j3 < 2; j3++) {
                a = D_00251400 + j3 * 0x40;
                func_L01_0043A430((s32)D_L01_002446C0_004BF980.objs, 0x16 + j3, a);
                *(f32 *)(a + 0x20) = 0.01f;
                *(f32 *)(a + 0x24) = 0.01f;
                *(f32 *)(a + 0x28) = 0.01f;
            }
        }
        tail:
        to = D_L01_002446C0_004BF980.objs;
        ta = (u8 *)*(s32 *)(to[0x42] * 4 + *(s32 *)(to + 0x24) + 0x48);
        if (*(u32 *)(ta + 0x1C) & 0xF0000000) {
            func_L01_0043C8F8(ta + 0x1C + ta[0x10] * 4 + ta[0x13] * 4, *(s32 *)(ta + to[0x40] * 4 + 0x1C), D_L01_002446C0_004BF980.f20, ((u8 *)*(s32 *)(to + 0x24))[8]);
            *(s32 *)(to + 0x58) = D_L01_002446C0_004BF980.f20;
        }
        ta = (u8 *)*(s32 *)(to[0x43] * 4 + *(s32 *)(to + 0x24) + 0x48);
        if (*(u32 *)(ta + 0x1C) & 0xF0000000) {
            func_L01_0043C8F8(ta + 0x1C + ta[0x10] * 4 + ta[0x13] * 4, *(s32 *)(ta + to[0x41] * 4 + 0x1C), D_L01_002446C0_004BF980.f24, ((u8 *)*(s32 *)(to + 0x24))[8]);
            *(s32 *)(to + 0x5C) = D_L01_002446C0_004BF980.f24;
        }
        D_L01_002446C0_004BF980.ffC0 = -9.0f;
        D_L01_002446C0_004BF980.ffC4 = 3.25f;
        pp = (u8 *)D_00143950;
        D_L01_002446C0_004BF980.ffC8 = (pp[0xAD] != 0) ? -0.02f : 0.5f;
        D_L01_002446C0_004BF980.ff94 = 3.5f;
        D_L01_002446C0_004BF980.b88 = 1;
        D_L01_002446C0_004BF980.f98 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        D_L01_002446C0_004BF980.f8c = 0;
        return;
    }

    if (mode == 2) {
        sel = D_L01_002446C0_004BF980.cur;
        eb = D_L01_002446C0_004BF980.v.x24.e;
        ep = &eb[sel].e;
        D_L01_002446C0_004BF980.idx = 10;
        D_L01_002446C0_004BF980.f4c = (D_001D54D0[0] & ~*ep) | D_L01_002446C0_004BF980.v.x24.e[sel].w4;
        tm = (u8 *)D_0016C580[0];
        slots[0] = (u32)((s32)*(s16 *)(tm + 0xAA) << 16);
        if (*ep == 3) slots[0] |= 0x80000000;
        {
            v = *(s16 *)((u8 *)D_001D6700 + ((D_L01_002446C0_004BF980.f4c & 0xC) >> 1));
            slots[1] = (u32)(v << 16);
            slots[2] = slots[1] | 0x8000;
            if (*ep == 0xC) { slots[1] |= 0x80000000; slots[2] |= 0x80000000; }
        }
        {
            v = D_001D670C[0];
            slots[3] = (u32)(v << 16);
            slots[4] = slots[3] | 0x8000;
            if (*ep == 0xC00) { slots[3] |= 0x80000000; slots[4] |= 0x80000000; }
        }
        {
            v = D_001D6706[0];
            slots[5] = (u32)(v << 16);
            if (*ep == 0x30) slots[5] |= 0x80000000;
        }
        {
            v = D_001D6708[0];
            slots[6] = (u32)(v << 16);
            slots[7] = slots[6] | 0x8000;
            if (*ep == 0x40) { slots[6] |= 0x80000000; slots[7] |= 0x80000000; }
        }
        {
            v = D_001D670A[0];
            slots[8] = (u32)(v << 16);
            slots[9] = slots[8] | 0x8000;
            if (*ep == 0x200) { slots[8] |= 0x80000000; slots[9] |= 0x80000000; }
        }
        D_L01_002446C0_004BF980.fa0 = 0;
        sq = slots;
        sq[D_L01_002446C0_004BF980.idx] = 0x10E30000;
        D_L01_002446C0_004BF980.idx = D_L01_002446C0_004BF980.idx + 1;
        if (*ep == 0xC00 || *ep == 0x200 || *ep == 0xC || *ep == 3 || *ep == 0x40) {
            D_L01_002446C0_004BF980.ffA4 = 0.346f;
            D_L01_002446C0_004BF980.ffA8 = 0.3227f;
            D_L01_002446C0_004BF980.ffAC = func_0038DAB8(0.8566f, 3.1415927f);
        } else if (*ep == 0x30 || *ep == 0x2000) {
            D_L01_002446C0_004BF980.ffA4 = 0.0225f;
            D_L01_002446C0_004BF980.ffA8 = 0.0239f;
            D_L01_002446C0_004BF980.ffAC = func_0038DB00(-3.0301f, 1.5707964f);
        } else {
            e = eb[sel].e;
            if (e == 0x1000 || e == 0x180) {
                D_L01_002446C0_004BF980.ffA4 = -0.587f;
                D_L01_002446C0_004BF980.ffA8 = 0.165f;
                D_L01_002446C0_004BF980.ffAC = func_0038DAB8(2.055f, 1.5707964f);
            } else if (e == 0x1F0000) {
                odd = sel & 1;
                D_L01_002446C0_004BF980.ffA4 = (u8)(sel & 1) ? 0.533f : 0.566f;
                D_L01_002446C0_004BF980.ffA8 = (u8)odd ? 0.3203f : 0.165f;
                if (odd & 0xFF) cv = 0.6699f; else cv = 1.4345f;
                D_L01_002446C0_004BF980.ffAC = func_0038DAB8(cv, 3.1415927f);
            } else if (e == 0xC000) {
                D_L01_002446C0_004BF980.ffA4 = -0.5f;
                D_L01_002446C0_004BF980.ffA8 = -0.4f;
                D_L01_002446C0_004BF980.ffAC = func_0038DB00(-2.1f, 1.5707964f);
            } else {
                D_L01_002446C0_004BF980.ffA4 = 0;
                D_L01_002446C0_004BF980.ffA8 = 0;
                D_L01_002446C0_004BF980.ffAC = -1.5707964f;
            }
        }
        D_L01_002446C0_004BF980.f54[0] = -1;
        D_L01_002446C0_004BF980.f54[1] = -1;
        k = 0;
        for (i = 0; i < D_L01_002446C0_004BF980.idx; i = i + 1) {
            pl = (u8 *)D_00143950;
            msk = 0x80000000;
            o = D_L01_002446C0_004BF980.objs + (i << 8);
            func_003C25D8(o, *(u16 *)((u8 *)&sq[i] + 2) & 0x7FFF);
            func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
            if (sq[i] & msk) {
                D_L01_002446C0_004BF980.f54[k] = i;
                k++;
            }
            if (o[0x63] != 0) o[0x63] = 0xF;
            *(u16 *)(o + 0x32) = 0x100;
            o[0x31] = 1;
            *(s32 *)(o + 0x78) = 0x80808080;
            o[0x30] = 0;
            o[0x23] = 0xFF;
            *(u16 *)(o + 0x34) = *(u16 *)&sq[i] | 0x2010;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            *(f32 *)(o + 0x2C) = 1.0f;
            D_L01_002446C0_004BF980.ffC0 = -12.0f;
            D_L01_002446C0_004BF980.ff94 = 1.0f;
            D_L01_002446C0_004BF980.ffC4 = 0;
            fl = pl[0xAD] != 0;
            cv = fl ? 1.45f : 2.0f;
            D_L01_002446C0_004BF980.ffC8 = cv;
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(f32 *)(o + 0xF8) = -1.5707964f;
            func_003C7C38(o);
        }
        D_L01_002446C0_004BF980.b88 = 1;
        D_L01_002446C0_004BF980.f98 = 0;
        D_L01_002446C0_004BF980.b89 = 0;
        D_L01_002446C0_004BF980.f8c = 0;
        if (D_001DADF4_sda != (D_L01_002446C0_004BF980.f4c & 3)) {
            func_00398BB8(D_L01_002446C0_004BF980.f4c & 3);
            D_001DADF4_sda = D_L01_002446C0_004BF980.f4c & 3;
        }
        if (((*(u16 *)((u8 *)&D_L01_002446C0_004BF980 + 0x4E)) & 0x1F) != D_0016C580[12]) func_00398C80((*(u16 *)((u8 *)&D_L01_002446C0_004BF980 + 0x4E)) & 0x1F);
        return;
    }

    if (mode == 0) {
    D_L01_002446C0_004BF980.f750 = 0;
    sel0 = D_L01_002446C0_004BF980.cur;
    {
        s32 t = D_L01_002446C0_004BF980.v.e14[sel0].b4;
        if (t == 1) {
            func_003C25D8(o, 0xCDB);
            func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
            *(u16 *)(o + 0x32) = 0x40;
            *(s32 *)(o + 0x78) = 0x80808080;
            *(u16 *)(o + 0x34) = 0x2010;
            *(u16 *)(o + 0x7C) = t;
            o[0x31] = t;
            o[0x30] = 0;
            o[0x23] = 0;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            D_L01_002446C0_004BF980.ff94 = 3.5f;
            *(u128_t *)&D_L01_002446C0_004BF980.ffC0 = *(u128_t *)D_001DABF0_sda;
            if (((u8 *)D_00143950)[0xAD] != 0) {
                D_L01_002446C0_004BF980.ffC8 = D_L01_002446C0_004BF980.ffC8 - 0.55f;
            }
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(s32 *)(o + 0xF8) = 0;
            D_L01_002446C0_004BF980.f98 = 0;
            func_003C7C38(o);
            D_L01_002446C0_004BF980.f8c = 0;
            D_L01_002446C0_004BF980.b88 = 1;
            return;
        }
        if (D_L01_002446C0_004BF980.v.e14[sel0].b11 != 0) {
            func_L01_00419E60((u8 *)loc, D_L01_002446C0_004BF980.v.e14[sel0].f0, 2);
            func_L01_004BC0B8((s32)func_00381FF0(*(s16 *)(loc + 0x42)));
        } else {
            e0 = D_L01_002446C0_004BF980.v.e14[sel0].f0;
            pq = (u8 *)D_L01_002C5600;
            func_L01_004BC0B8((s32)func_00381FF0(*(s16 *)(pq + D_001425C0_u8[e0] * 0xF0 + 0x42)));
        }
        func_003A2750(1);
        func_L01_0042D330(D_L01_002446C0_004BF980.v.e14[D_L01_002446C0_004BF980.cur].f8, D_L01_002446C0_004BF980.f1c);
        D_L01_002446C0_004BF980.b89 = 1;
        D_L01_002446C0_004BF980.f70 = D_L01_002446C0_004BF980.cur;
        D_L01_002446C0_004BF980.b88 = 0;
        return;
    }
    }
    D_L01_002446C0_004BF980.b89 = 0;
    D_L01_002446C0_004BF980.b88 = 0;
}
/* localdecomp:end func_L01_004BF980 */
