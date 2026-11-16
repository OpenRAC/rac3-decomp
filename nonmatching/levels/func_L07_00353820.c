/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "@ps2as and -mvu0-use-vf0-vf2 added to the file line" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact with --as ps2as + -mvu0-use-vf0-vf2 (vec_add_ba from vu0.h; 2.2f inline constant); L07_00351C58.c line has neither. Needs `self + (idx * 16 + 0xC0)` grouping, returns the callee s32. C in near/
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_00353820 */
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L07_00333200(u8 *, u8 *, u8 *);

s32 func_L07_00353820(u8 *self, s32 idx, s32 n, f32 scale) {
    u8 *s = *(u8 **)(self + 0x68);
    vu0_v4 tmp;

    func_0038CF68(&tmp, self + (idx * 16 + 0xC0), scale * (f32)n * 2.2f);
    vec_add_ba(&tmp, self + 0x10, &tmp);
    return func_L07_00333200(*(u8 **)(s + 0x240), self, (u8 *)&tmp);
}
/* localdecomp:end func_L07_00353820 */
