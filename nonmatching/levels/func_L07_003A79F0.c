/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: MATCH only with BOTH -mvu0-use-vf0-vf2 and @ps2as added (file line L07_003A70B0.c has neither; vu0.h helpers do not compile without the first, jal delay slot nop needs the second) plus NEEDS divs row 'func_L07_003A79F0 2'; C (vec_sub_ab/vec_add_ab from vu0.h) ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003A79F0 */
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L07_003A79F0(void *a0, void *a1, s32 a2, s32 a3, f32 a4) {
    vu0_v4 v;

    vec_sub_ab(&v, a1, a0);
    func_0038CE20(&v, &v, a4 / (func_L01_0040E4C0(&v) + a4) - 0.5f);
    if (a2) {
        vec_sub_ab(a0, a0, &v);
    }
    if (a3) {
        vec_add_ab(a1, a1, &v);
    }
}
/* localdecomp:end func_L07_003A79F0 */
