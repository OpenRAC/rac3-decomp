/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: near, 3 diff and the file line lacks -mvu0-use-vf0-vf2 (vu0.h helpers fail with vf17 spilled): all matches except retail stores the vadd result a second time, `sqc2 $vf1, 0x10($sp)` after the store to a0 (no existing helper stores one result twice; vec_add_ab ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L06_0042B660 */
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

f32 func_L06_0042B660(u8 *a0, u8 *a1, f32 max) {
    struct {
        vu0_q d;
        vu0_q t;
    } v;
    f32 len;
    f32 c;
    vec_sub_ab(&v.t, a1, a0);
    v.d = v.t;
    c = func_0038CEA8(&v.d);
    len = c;
    if (max < c) {
        c = max;
    } else if (c < -max) {
        c = -max;
    }
    func_0038CF68(&v.d, &v.d, c);
    vec_add_ab(a0, a0, &v.d);
    return len - c;
}
/* localdecomp:end func_L06_0042B660 */
