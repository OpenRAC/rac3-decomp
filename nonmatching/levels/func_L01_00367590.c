/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact (lim = D_001D545C == 11 ? 80 : 40; if lim <= func_0038CF00(&E0, &F0): vec_sub_ab(v, &F0, &E0); func_0038CF68(v, v, lim re-read); vec_add_ab(&F0, &E0, v)) only with -mvu0-use-vf0-vf2, which the file line lacks; D_L01_001E1CE0/1CF0 declared as extern ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00367590 */
extern s32 D_001D545C;
extern s32 D_L01_001E1CE0;
extern s32 D_L01_001E1CF0;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_00367590(void) {
    f32 lim = 40.0f;
    f32 v[4];

    if (D_001D545C == 11) {
        lim = 80.0f;
    }
    if (lim <= func_0038CF00(&D_L01_001E1CE0, &D_L01_001E1CF0)) {
        vec_sub_ab(v, &D_L01_001E1CF0, &D_L01_001E1CE0);
        func_0038CF68(v, v, D_001D545C == 11 ? 80.0f : 40.0f);
        vec_add_ab(&D_L01_001E1CF0, &D_L01_001E1CE0, v);
    }
}
/* localdecomp:end func_L01_00367590 */
