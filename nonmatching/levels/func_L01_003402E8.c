/* func_L01_003402E8 (Claude wave 14 r63, 2026-11-28). Replaces the earlier draft of this function (Round 26 W8 draft). */
/* func_L01_003402E8 (lightning bolts, 716 B, 34 places), wave 14 r63 near miss.
 * Needs another flag line: retail loads li.s 0.17453292 / 0.7853982 / 0.1 as lui/ori/mtc1 (Ps2EeAs, @ps2as) and
 * reaches D_L01_001E29C0 through a hoisted `lui $s5` (split addresses). Its file's line
 * (-mno-split-addresses, no @ps2as) cannot assemble this C (GNU as: "illegal operands sq/lqc2" on symbol
 * operands) and cannot give those words. Under L01_003405B8.c's line
 * "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as" (tools/check.py --mode S --as ps2as,
 * level 01) this is 64 diff; the round-26 draft is 169 there.
 * Changed against the draft: one S_003402E8 {vu0_v4 p[5]} at D_L01_00278E20 with 1-based loops over p[j-1]/p[j]
 * (gives retail's giv bases and countdown counters), d[j] for j = 1..4, a block-scoped counter per branch
 * (retail: s1 in the build loop, s3 in both else loops), and the else branch's D_L01_001E18D8 through a local
 * pointer set at its start (retail's $s6; a global reference is hoisted out of the outer loop).
 * Still differs: the build branch stores p[0] through `mtlo; madd` with its own mult (here cse shares one
 * i*80 product with the loop base), so i / i*2 / 80 / i+1 get s5/s4/fp/s7 instead of s4/s5/s7/fp; the
 * else loop's vsub uses vf1/vf2 swapped; a few scheduling words follow from these. */
#include "common.h"

/* localdecomp:start func_L01_003402E8 */
typedef struct {
    vu0_v4 p[5];
} S_003402E8;

extern s16 D_L01_001E18D8[];
extern S_003402E8 D_L01_00278E20[];
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DD154;
__asm__(".extern D_L01_001DD154, 4");

void func_L01_003402E8(u8 *self) {
    extern f32 func_003824E0(f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    vu0_v4 q;
    vu0_v4 dir;
    vu0_v4 t;
    vu0_v4 d[5];
    f32 sign;
    s32 i;
    vu0_v4 *dp = d;

    q = *(vu0_v4 *)(self + 0x10);
    for (i = 0; i < 4; i++) {
        if (D_L01_001E18D0[i] != 0) {
            D_L01_001E18D0[i] = D_L01_001E18D0[i] - 1;
            if (D_L01_001E18D0[i] < 0) {
                D_L01_001E18D0[i] = 0;
            }
            if (D_L01_001E18D0[i] == 0) {
                s32 j;

                D_L01_001E18D0[i] = 4;
                D_L01_001E18D8[i] = 0x40;
                func_00382580(&dir, D_L01_001DD154, D_L01_001DD154);
                D_L01_00278E20[i].p[0] = q;
                sign = 1.0f;
                for (j = 1; j < 5; j++) {
                    vec_sub_ab(&t, &D_L01_00278E20[i].p[j - 1], &D_L01_001E29C0);
                    func_0038D890(&dir, &dir, &t, func_003824E0(0.17453292f, 0.7853982f) * sign);
                    sign = -sign;
                    vec_add_ab(&D_L01_00278E20[i].p[j], &D_L01_00278E20[i].p[j - 1], &dir);
                }
            } else {
                s16 *alpha = D_L01_001E18D8;
                s32 j;

                for (j = 1; j < 5; j++) {
                    vec_sub_ba(&d[j], &D_L01_00278E20[i].p[j], &D_L01_00278E20[i].p[j - 1]);
                    dp[j].x += func_L01_00443A18(0.0f, 0.1f);
                    dp[j].y += func_L01_00443A18(0.0f, 0.1f);
                    dp[j].z += func_L01_00443A18(0.0f, 0.1f);
                }
                D_L01_00278E20[i].p[0] = q;
                for (j = 1; j < 5; j++) {
                    vec_add_ab(&D_L01_00278E20[i].p[j], &D_L01_00278E20[i].p[j - 1], &d[j]);
                }
                if (D_L01_001E18D0[i] > 0) {
                    alpha[i] = 0x20;
                } else {
                    alpha[i] = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_003402E8 */
