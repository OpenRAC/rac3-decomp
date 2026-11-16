/* PAL near miss (Claude wave S/pal): near miss: 32 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division (+ -mvu0-use-vf0-vf2 needed)" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: flags + 32 diff: the file line has no -mvu0-use-vf0-vf2, so the vu0.h helpers do not compile (vf17 spill); raw $vf1/$vf2 asm blocks give 42 diff. With the flag and vec_sub_ab/vec_add_ab the prologue, calls and VU0 sequences are right, NEEDS divs row ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003DC4C8 */
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L07_003DC4C8(u8 *a, u8 *b, s32 fa, s32 fb, f32 k) {
    vu0_v4 d;
    f32 s;

    vec_sub_ab(&d, b, a);
    s = func_L01_0040E4C0(&d);
    func_0038CE20(&d, &d, k / (s + k) - 0.5f);
    if (fa != 0) {
        vec_sub_ab(a, a, &d);
    }
    if (fb != 0) {
        vec_add_ab(b, b, &d);
    }
}
/* localdecomp:end func_L07_003DC4C8 */
