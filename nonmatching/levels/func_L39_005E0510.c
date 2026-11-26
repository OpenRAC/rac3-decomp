/*
 * func_L39_005E0510 -- k4 Sonnet first pass, 2500 B (625 instructions), shared at 15 places (39:005E0510, 40:004B2BB8 ... 53:004B8D40).
 * Result: NEAR. With `--flags=@ps2as` (the file's own flags lack @ps2as, see below): 12 differing rows of 628 after aligning
 * (tools/check.py reports 572 because of a 1-word shift at the start; the plain-flags profile is 127+ aligned diffs, all of them
 * the float constants, which need Ps2EeAs).
 * Equal: the whole prologue/epilogue, every call and argument in order (about 140 calls), all float constants (lui/ori/mtc1),
 * the $f20-$f26 allocation, both loops (do/while with beql, `0x30004..0x3000B`), the 0x241120 >= 3 branch, the $gp loads.
 * Still differs, three spots:
 *  1. Start: retail is `addiu a1,1 ; addu v0,v0,v1 ; addiu a0,1 ; jal func_006108F8 ; sb a1,(v0)` (store in the delay slot, the stored 1
 *     sharing the a1 register of the second argument). Mine: a0=1, addu, a1=1, sb, jal, a0=1. Tried: assignment as call argument
 *     (D[..] = 1 as arg 2 or arg 1), an `s32 one` local (goes to s0), swapped order, (s32,u8) prototype. Not solved; looks like a
 *     CSE/arg-order wording for `D_L39_00243970[func_L01_00517688()] = 1; func_L01_004D2110(1, 1);`.
 *  2. A `nop` after the `lwc1 $f13, -0x4670($gp)` that precedes the first loop (before its `.p2align 3` label). Retail has none.
 *  3. Last loop (`func_003E8630(0x30000, i)`, 6 instructions with its delay slots): retail is 6 long and unpadded; the check pads it
 *     with a nop before the beqz (asm_filter.insn_count does not recognise the `li $4,196608` / jal delay shape under ps2as, so the
 *     filter does not write it raw). Probably a tool limitation, not a C difference.
 * FLAG NEED: the function needs `@ps2as` (float immediates built with lui/ori/mtc1). src/levels/shared/L39_005E04A0.c has the flags
 * `-O2 -G8 -fopt-stack -mno-check-zero-division` (no @ps2as, because its other function func_L39_005E04A0 matches without), so the file
 * has to be cut at this function with a `@ps2as` line (like L39_005E0ED8.c); not done here as instructed.
 * Prototypes inferred from register use (confidence: high for arg order/types, the callees are the shared UI calls of func_L39_005E0FC8
 * in src/levels/shared/L40_004B3670.c): func_L01_00516470/00517538/00516728(id, f32, f32), func_L01_00516AA0/00516C78(id, s32, s32),
 * func_L01_005170B8/00517190(id, s32), func_L01_00516FD8(id, void*), func_003E7F20(id, s32) (=func_L39_006119E8), func_003E8630(a, b),
 * func_003B5060/003E5090/003E51F8/003E5360(id), func_003E8348(s32, s32), func_003E6FF0(s32, s32), func_L01_004D2110 (called as (1,1) and (0)).
 * D_L39_00243970 (u8[8], $gp-0x4650), D_L39_00243950 (f32, $gp-0x4670) need `__asm__(".extern X, N")` so they are $gp-relative.
 * Next steps: (1) put the file under @ps2as (or cut), re-run check; (2) chase the three spots above, in order; spot 3 may need an
 * asm_filter fix by the maintainer.
 * Profile: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * k6 (2026-11-26): the index in a local before the stored 1 (`idx = f(); v = 1; D[idx] = v; func(1, v)`) removes
 * spot 2 and the 1-word shift: now 8 aligned differences, spot 1 is only a0/a1 swapped (retail sets a1=1 first and
 * stores a1; here a0=1 first and the store uses a0). 12 wordings tried (v/w locals, u8/s8 v, (v,1), (v,v), assignment
 * as the argument, pointer to the slot): all store through a0. A (s32,s32) prototype is impossible: the second call
 * passes only a0 (`func_L01_004D2110(0)`). Spot 3 (loop padding nop) unchanged.
 * k6 permuter: the store and call inside `do { } while (0)` (a macro's shape) stores through a1 as retail: 4 aligned
 * differences left, `addiu $v1, $gp, -0x4650` and `addiu $a1, $zero, 1` swapped, and spot 3.
 * Spot 3 was tools/asm_filter.py (an `li` of 0x30000 now counts as one lui, so the loop is padded to 6 as
 * retail): with that fix 2 differences are left, the two-word swap only (still needs its file cut to @ps2as).
 */
#include "common.h"

extern u8 D_L39_00243970[8];
__asm__(".extern D_L39_00243970, 8");
extern f32 D_L39_00243950;
__asm__(".extern D_L39_00243950, 4");
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern u8 D_L39_0024C5A0[] __attribute__((section(".sdata")));
extern u8 D_L39_0024C5A8[] __attribute__((section(".sdata")));
extern s32 func_L01_00517688(void);
extern void func_L01_004D2110();
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E51F8(s32);
extern void func_003E5360(s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_005170B8(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516C78(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_L01_00516FD8(s32, void *);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);

void func_L39_005E0510(s32 arg0) {
    s32 i;
    { s32 idx = func_L01_00517688(); s32 v = 1; do { D_L39_00243970[idx] = v; func_L01_004D2110(1, v); } while (0); }
    func_003B5060(0x30000);
    func_003B5060(0x3000c);
    func_003E5090(0x30001);
    func_003E5090(0x30002);
    func_003E5090(0x30003);
    func_003E5090(0x3000d);
    func_003E5090(0x3000e);
    func_003E51F8(0x30004);
    func_003E51F8(0x30005);
    func_003E51F8(0x30006);
    func_003E51F8(0x30007);
    func_003E51F8(0x30008);
    func_003E51F8(0x30009);
    func_003E51F8(0x3000a);
    func_003E51F8(0x3000b);
    func_003E51F8(0x3000f);
    func_003E51F8(0x30010);
    func_003E51F8(0x30011);
    func_003E51F8(0x30012);
    func_003E51F8(0x30013);
    func_003E5360(0x30014);
    func_003E5360(0x30015);
    func_003E5360(0x30016);
    func_003E5360(0x30017);
    func_L39_00611AC8(0x30001, func_00392A18(), 0x2f);
    func_L39_00611AC8(0x30002, func_00392A18(), 0x30);
    func_L39_00611AC8(0x30003, func_00392A18(), 0x31);
    func_L39_00611AC8(0x3000d, func_00392A18(), 0x24);
    func_L39_00611AC8(0x3000e, func_00392A18(), 0x23);
    if (*D_00241120 >= 3) {
        func_L01_00516470(0x30001, 0.865f, 0.93f);
        func_L01_00516470(0x30002, 0.865f, 0.93f);
        func_L01_00516470(0x30003, 0.865f, 0.93f);
    } else {
        func_L01_00516470(0x30001, 0.865f, 0.83f);
        func_L01_00516470(0x30002, 0.865f, 0.83f);
        func_L01_00516470(0x30003, 0.865f, 0.83f);
    }
    func_L01_005170B8(0x30001, 0x332299de);
    func_L01_005170B8(0x30002, 0x331465b7);
    func_L01_005170B8(0x30003, 0x331465b7);
    func_L01_00517538(0x30001, 1.75f, 1.75f);
    func_L01_00517538(0x30002, 1.75f, 1.75f);
    func_L01_00517538(0x30003, 1.75f, 1.75f);
    for (i = 0x30004; i <= 0x3000B; i++) {
        func_L01_00517538(i, 0.03f, D_L39_00243950 * 0.03f);
        func_L01_00516AA0(i, 1, 0);
        func_L01_00516C78(i, 3, 3);
        func_L01_00517190(i, 0xED35);
    }
    func_L01_00516470(0x3000f, 0.925f, 0.095f);
    func_L01_00516470(0x3000d, 0.5f, 0.5f);
    func_L01_00516470(0x3000e, 0.5f, 0.5f);
    func_L01_00516470(0x30011, 0.375f, -0.405f);
    func_L01_00516470(0x30010, 0.375f, -0.43f);
    func_L01_00516470(0x30012, 0.83f, 0.08f);
    func_L01_00516470(0x30013, 0.74f, 0.08f);
    func_L01_00516470(0x30014, 0.825f, 0.062f);
    func_L01_00516470(0x30015, 0.74f, 0.062f);
    func_L01_00516470(0x30016, 0.77f, 0.12f);
    func_L01_00516470(0x30017, 0.78f, 0.06f);
    func_L01_00516AA0(0x3000d, 1, 1);
    func_L01_00516AA0(0x3000e, 1, 1);
    func_L01_00516AA0(0x3000f, 1, 1);
    func_L01_00516AA0(0x30011, 1, 1);
    func_L01_00516AA0(0x30010, 1, 1);
    func_L01_00516AA0(0x30014, 1, 1);
    func_L01_00516AA0(0x30015, 1, 1);
    func_L01_00517538(0x3000d, 1.0f, 1.0f);
    func_L01_00517538(0x3000e, 1.0f, 1.0f);
    func_L01_00517538(0x3000f, 0.06f, 0.06f);
    func_L01_00517538(0x30012, 0.073f, 0.055f);
    func_L01_00517538(0x30013, 0.073f, 0.055f);
    func_L01_00517538(0x30014, 0.7f, 0.75f);
    func_L01_00517538(0x30015, 0.7f, 0.75f);
    func_L01_00517538(0x30016, 0.55f, 0.7f);
    func_L01_00517538(0x30017, 0.6f, 0.7f);
    func_L01_005170B8(0x3000d, 0x331465b7);
    func_L01_005170B8(0x3000e, 0x332299de);
    func_L01_005170B8(0x3000f, 0x706ec8ff);
    func_L01_005170B8(0x30011, 0x600000ff);
    func_L01_005170B8(0x30010, 0x60ff0000);
    func_L01_005170B8(0x30012, 0x600000ff);
    func_L01_005170B8(0x30013, 0x60ff0000);
    func_L01_005170B8(0x30014, 0x8066ccff);
    func_L01_005170B8(0x30015, 0x8066ccff);
    func_L01_005170B8(0x30016, 0x8066ccff);
    func_L01_005170B8(0x30017, 0x8066ccff);
    func_L01_00516728(0x30014, 0.003f, 0.003f);
    func_003E7F20(0x30014, 2);
    func_L01_00516FD8(0x30014, D_L39_0024C5A0);
    func_L01_00516C78(0x30014, 3, 3);
    func_L01_00516728(0x30014, 0.003f, 0.003f);
    func_003E7F20(0x30014, 2);
    func_L01_00516FD8(0x30015, D_L39_0024C5A8);
    func_L01_00516C78(0x30014, 3, 3);
    func_L01_00516C78(0x30011, 2, 3);
    func_L01_00516C78(0x30010, 2, 3);
    func_003E8630(0x30000, 0x30002);
    func_003E8630(0x30000, 0x30001);
    func_003E8630(0x30000, 0x30003);
    func_003E8630(0x30000, 0x30016);
    func_003E8630(0x30000, 0x30017);
    func_003E8630(0x30000, 0x3000c);
    func_003E8630(0x3000C, 0x3000d);
    func_003E8630(0x3000C, 0x3000e);
    func_003E8630(0x3000C, 0x3000f);
    func_003E8630(0x3000C, 0x30011);
    func_003E8630(0x3000C, 0x30010);
    func_003E8630(0x3000C, 0x30012);
    func_003E8630(0x3000C, 0x30013);
    func_003E8630(0x3000C, 0x30014);
    func_003E8630(0x3000C, 0x30015);
    for (i = 0x30004; i <= 0x3000B; i++) {
        func_003E8630(0x30000, i);
    }
    func_003E8348(0x15, 0x30000);
    func_003E6FF0(arg0, 1);
    func_L01_004D2110(0);
}
