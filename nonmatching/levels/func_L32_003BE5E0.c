/* func_L32_003BE5E0 (Claude wave 14 r51, 2026-11-28). Replaces the earlier draft of this function (shared-2 worker draft (2026-11-16), updated round 23 (b37 W8)). */
/* func_L32_003BE5E0: 10 diff with the file's flags (wave 14 r51; the previous draft had 34). Changes against it:
 * D_L32_001DF1A0 is not const (its lwc1 becomes the first insn of the || body, so both delay slots take it
 * as retail does: plain bc1t/bc1f); the velocity step is an if/else with D_L32_001DF19C (not const) read in
 * each arm and the sum t + d computed in each arm (cross-jumping merges the two add.s after reload); the
 * if/else ends cse's block, so the 0.0f of the `t < 0` test is no longer shared with the call's 0.0f ($f0,
 * then a separate mtc1 $zero,$f12 as retail) and t/t2 get retail's $f1/$f3; alpha = D_L32_001DF1B0 (not const)
 * * (1 - f4) is computed before the a1+0x14 store (retail loads D_1B0 before that swc1). Remaining (10): the
 * lwc1 $f21 of D_L32_001DF198 is scheduled right after swc1 0x14($s1) where retail has it after the lw/mul/
 * lwc1/and, and the lh $a0 / mtc1 $zero,$f12 slots around it (sched2 order only, registers all match).
 * Contract: the block of func_L32_003BE830 declares `extern void func_L32_003BE5E0(void *)`; this two-argument
 * definition needs that extern to read `(u8 *, u8 *)` (as the old draft noted). */
#include "common.h"

/* localdecomp:start func_L32_003BE5E0 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L32_001DF1A8; __asm__(".extern D_L32_001DF1A8, 4");
extern f32 D_L32_001DF1A4; __asm__(".extern D_L32_001DF1A4, 4");
extern const f32 D_L32_001DF1AC; __asm__(".extern D_L32_001DF1AC, 4");
extern const f32 D_L32_001DF1C4; __asm__(".extern D_L32_001DF1C4, 4");
extern const f32 D_L32_001DF18C; __asm__(".extern D_L32_001DF18C, 4");
extern const f32 D_L32_001DF188; __asm__(".extern D_L32_001DF188, 4");
extern s32 D_L32_001DF178; __asm__(".extern D_L32_001DF178, 4");
extern s32 D_L32_001DF17C; __asm__(".extern D_L32_001DF17C, 4");
extern f32 D_L32_001DF1A0; __asm__(".extern D_L32_001DF1A0, 4");
extern f32 D_L32_001DF19C; __asm__(".extern D_L32_001DF19C, 4");
extern f32 D_L32_001DF1B0; __asm__(".extern D_L32_001DF1B0, 4");
extern const f32 D_L32_001DF198; __asm__(".extern D_L32_001DF198, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L32_003BE5E0(u8 *a0, u8 *a1) {
    u8 *p;
    u8 *q;
    f32 f21, f20, d, t, t2, f4, amplitude, alpha;
    u16 v;
    if (a1 == 0) return;
    p = *(u8 **)a1;
    q = *(u8 **)(a1 + 4);
    if (p == 0 || q == 0) return;
    if (*(u16 *)(a1 + 0xA) & 1) {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
        *(f32 *)(a1 + 0x10) = func_003824E0(D_L32_001DF1A8, D_L32_001DF1A4);
        amplitude = D_L32_001DF1AC;
        *(f32 *)(a1 + 0x14) = func_003824E0(-amplitude, amplitude);
        amplitude = D_L32_001DF1C4;
        *(f32 *)(a0 + 0x10) += func_003824E0(-amplitude, amplitude);
        *(f32 *)(a0 + 0xC) = func_003824E0(D_L32_001DF18C, D_L32_001DF188);
        *(s32 *)(a0 + 4) = func_0038DBD8(D_L32_001DF178, D_L32_001DF17C, func_003824E0(0.0f, 1.0f));
    }
    f4 = func_L03_0034B440((f32)*(s16 *)(a0 + 0xA), (f32)*(s16 *)(a1 + 8), 1.0f, 1, 0, 0);
    if (*(f32 *)(p + 0x18) < *(f32 *)(a0 + 0x18) || *(f32 *)(a1 + 0x10) > 0.0f) {
        *(f32 *)(a1 + 0x10) -= D_L32_001DF1A0;
        *(f32 *)(a0 + 0x18) += *(f32 *)(a1 + 0x10);
    }
    t = *(f32 *)(a1 + 0x14);
    if (t < 0.0f) {
        d = D_L32_001DF19C;
        t2 = t + d;
    } else {
        d = -D_L32_001DF19C;
        t2 = t + d;
    }
    alpha = D_L32_001DF1B0 * (1.0f - f4);
    *(f32 *)(a1 + 0x14) = t2;
    *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) | ((s32)alpha << 24);
    *(f32 *)(a0 + 0x10) += t2;
    v = *(u16 *)(a1 + 0xE);
    f21 = D_L32_001DF198 * (f32)*(s16 *)(a1 + 8) * (f32)(v >> 8) * 0.00390625f;
    f20 = (f32)(v & 0xFF);
    *(u8 *)(a0 + 8) = (s32)func_003C4088(f20, f20 + (f20 + f21), func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), 0.0f));
}
/* localdecomp:end func_L32_003BE5E0 */
