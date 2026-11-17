/* PAL near miss (b8-s3): 4 words differ: retail loads the first source into $vf1 and the second into $vf2 and
 * subtracts `vsub.xyz $vf2, $vf2, $vf1` (second minus first); vec_sub_ba allocates the minuend to $vf1
 * instead (lqc2 $vf2 / lqc2 $vf1 / vsub.xyz $vf1, $vf1, $vf2). Everything else matches, frame included.
 * The unused u[3] gives retail's 0x80 frame.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00448EC0 */
extern void func_0038D5B0(void *, s32);
extern void func_0038D028(void *, void *, void *);

f32 func_L01_00448EC0(f32 *a0, s32 a1, f32 *a2, s32 a3) {
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 v;
    vu0_v4 u[3];
    f32 *p = (f32 *)&r;

    vec_sub_ba(&d, a2, a0);
    func_0038D5B0(&v, a1);
    func_0038D028(&r, &d, &v);
    return p[a3];
}
