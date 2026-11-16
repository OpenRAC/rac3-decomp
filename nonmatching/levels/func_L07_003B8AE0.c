/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as + -mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: MATCH only with -mvu0-use-vf0-vf2 added to the line of src/levels/07_annihilation_nation/L07_003B7408.c (without it vu0.h's vec_sub_ba/vec_add_ab do not compile: vf17 spill); C in near/func_L07_003B8AE0.xhigh.c (check with --flags=-mvu0-use-vf0-vf2); no divs ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003B8AE0 */
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003B8AE0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 loc;
    f32 d;
    f32 d2;

    d = func_0038CF38(a0 + 0x10, s + 0x270);
    vec_sub_ba(&loc, a0 + 0x10, s + 0x70);
    loc.z = 0.0f;
    func_0038CF68(&loc, &loc, 7.0f);
    vec_add_ab(s + 0x270, s + 0x70, &loc);
    *(f32 *)(s + 0x278) = *(f32 *)(*(u8 **)(s + 0x190) + 0x18);
    d2 = func_0038CF38(a0 + 0x10, s + 0x270);
    *(f32 *)(s + 0x28C) += d2 - d;
}
/* localdecomp:end func_L07_003B8AE0 */
