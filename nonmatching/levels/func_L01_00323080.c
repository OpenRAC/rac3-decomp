/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: MATCH only with -mvu0-use-vf0-vf2 (vec_add_ba + vec_sub_ab; line lacks it): func_00382580(&v, 0.025f, 0.15f); vec_add_ba(&v, &v, a0); vec_sub_ab(&w, a0, &v); func_0038CF68 through a cast (the file declares it (f32 *, s32, f32) and this function (f32 *)); ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00323080 */
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);

void func_L01_00323080(f32 *a0) {
    vu0_q v;
    vu0_q w;
    func_00382580(&v, 0.025f, 0.15f);
    vec_add_ba(&v, &v, a0);
    vec_sub_ab(&w, a0, &v);
    ((void (*)(void *, void *, f32))func_0038CF68)(&w, &w, 0.015000001f);
    func_L01_004735F0(&v, &w, 0xC, 1.0f);
}
/* localdecomp:end func_L01_00323080 */
