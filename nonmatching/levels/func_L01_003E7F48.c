/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact (mode == 1: w = *(obj+0x70)+0x180 first, vec_sub_ab(&d, D_L01_001EAA20, pos), func_0038CE68(&d, w) < 0 -> 1, else 0) only with -mvu0-use-vf0-vf2, which the file line lacks; the file includes vu0.h only at line 1037 (after this function at 712): the ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003E7F48 */
extern f32 func_0038CE68(f32 *, f32 *);
extern short D_L01_001EAA20[];

s32 func_L01_003E7F48(u8 *obj, s32 mode, f32 *pos) {
    vu0_v4 d;

    f32 *w;

    if (mode == 1) {
        w = (f32 *)(*(u8 **)(obj + 0x70) + 0x180);
        vec_sub_ab(&d, D_L01_001EAA20, pos);
        if (func_0038CE68((f32 *)&d, w) < 0.0f) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003E7F48 */
