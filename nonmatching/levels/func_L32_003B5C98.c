/* func_L32_003B5C98: near miss, 130 diff (65 register-masked structural words) from 156 (round 12, s4, about 40 compiles + 3 hill
 * climbs). Measured with check.py --no-context --flags=-mno-split-addresses, a divs_nops row `func_L32_003B5C98 2 2 0 0` (not
 * committed) and `typedef int u128_t __attribute__((mode(TI)));` from the file's first block prepended.
 * FLAGS: the function needs `-mno-split-addresses` (retail's `lui $a1,0x1e; lw $a1,-0x640($a1)` and `lui $s3,0x1e; addiu
 * $s3,$s3,0x24a0` are the assembler's own expansions of `lw reg, sym` / `la reg, sym`), a flag the L32 build already uses
 * (L32_0034B5A8.c: `-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses`). func_L32_003B58D0 (split addresses,
 * @ps2as) sits in the same file, so this one has to be cut at 0x3B5C98 (8-aligned) into its own file with that line.
 * With that flag, the table as a scalar `extern s32 D_L32_001DF9C0;` + `.extern D_L32_001DF9C0, 16` (not `[0]` of an
 * array: the array form keeps one `la` in $s0 for both reads) and `v = m[0x68]` loaded BEFORE the `m != 0` test (reorg then puts
 * the load into the beqz delay slot, as retail does), the head of the function matches retail's instruction for instruction
 * and the saved-register roles are retail's (a0=s0, a1=s1, v=s2, d=s3): 156 -> 134 (130 with the divs row).
 * What is left is scheduling of the middle block: retail interleaves `D_L32_001DF9C0 % n` (lui/lw/div) and (f32)n into the float
 * statements before the first call; hill climbs over the order of the 8 statements (120 + 90 + 90 evals, also with r0/nf locals)
 * only move it between 108 and 135 with more structural words, and all 120 orders of the flag block's five stores give 133-136.
 */
#include "common.h"

extern f32 D_L32_001DEF00;
extern f32 D_L32_001DEF04;
extern f32 D_L32_001DEF14;
extern f32 D_L32_001DEEFC;
extern s32 D_L32_001DEEF4;
extern s32 D_L32_001DEEF0;
extern s32 D_L32_001DEEEC;
extern s32 D_L32_001DEEE8;
extern f32 D_L32_001DEEE4;
extern f32 D_L32_001DEEE0;
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern u8 D_L32_001E24A0[];
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);

void func_L32_003B5C98(u8 *a0, u8 *a1) {
    u8 *m;
    u8 *v;
    f32 f20;
    f32 f1;
    f32 f2;
    s32 n;

    u8 *d;
    if (a1 != 0 && (m = *(u8 **)a1, d = D_L32_001E24A0, v = *(u8 **)(m + 0x68), m != 0) && v != 0 && d != 0) {
        if (a1[9] & 1) {
            func_003C2F58(m, 0, a0 + 0x10);
            *(f32 *)(a0 + 0x18) += D_L32_001DEF00 * 0.5f;
            *(u128_t *)(a0 + 0x20) = *(u128_t *)(a0 + 0x10);
            *(f32 *)(a0 + 0x2C) = 1.0f;
            *(f32 *)(a0 + 0x28) -= D_L32_001DEF00;
            *(f32 *)(a0 + 0x1C) = D_L32_001DEF14;
            *(f32 *)(a1 + 0xC) = D_L32_001DEF04 * *(f32 *)(v + 0x140);
            a0[3] = d[0x10];
        }
        *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + *(f32 *)(a1 + 0xC);
        *(f32 *)(a0 + 0x20) = *(f32 *)(a0 + 0x20) + *(f32 *)(a1 + 0xC);
        f1 = D_L32_001DEEFC - D_L32_001DEF00;
        n = D_L32_001DEEF4;
        f20 = 1.0f - (f32)*(s16 *)(a0 + 0xA) * 0.25f / (f32)a1[8];
        *(f32 *)(a0 + 0x18) += f1 / ((f32)a1[8] * 4.0f);
        *(f32 *)(a0 + 0x28) -= f1 / ((f32)a1[8] * 4.0f);
        *(f32 *)(a0 + 0x1C) += D_L32_001DEF14 * f1 / (D_L32_001DEF00 * 4.0f * (f32)a1[8]);
        *(s32 *)(a0 + 4) = func_0038DBD8(func_L03_0034B440(0, 0, 5, (f32)(D_L32_001DF9C0 % n), (f32)n, 1.0f), D_L32_001DEEEC, D_L32_001DEEF0);
        {
            s32 k = D_L32_001DEEE8;
            u32 c;
            f32 q = func_003C4088(D_L32_001DEEE0, D_L32_001DEEE4, func_L03_0034B440(0, 0, 5, (f32)(D_L32_001DF9C0 % k), (f32)k, 1.0f)) * (1.0f - f20);
            c = (*(u32 *)(a0 + 4) & 0xFFFFFF) + ((s32)q << 24);
            *(u32 *)(a0 + 0xC) = c;
            *(u32 *)(a0 + 4) = c;
        }
    }
}

INCLUDE_ASM("asm/levels", func_L32_003B5C98);
