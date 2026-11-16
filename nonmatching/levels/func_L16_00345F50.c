/* PAL near miss (Claude wave S/pal): near miss: 30 words differ with the file's flags.
 * Worker's note: 30 diff (near/ file, flags are the file line): body, frame (0x60), the 3 stack vectors as one local struct {a,b,c}, vec_sub_ba/vec_add_ab and both func_L16_00346010 calls match; the difference is that retail converts (s32)t twice: `cvt.w.s f0; mfc1 s1` for ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L16_00345F50 */
extern void func_L16_00346010(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L16_00345F50(s32 *path, u8 *out, f32 t, f32 k) {
    struct {
        vu0_v4 a;
        vu0_v4 b;
        vu0_v4 c;
    } l;
    s32 i = (s32)t;

    func_L16_00346010(path, (i + 1) % path[0], &l.a, k);
    func_L16_00346010(path, i, &l.b, k);
    vec_sub_ba(&l.c, &l.a, &l.b);
    func_0038CE20(&l.c, &l.c, t - (f32)(s32)t);
    vec_add_ab(out, &l.b, &l.c);
}
/* localdecomp:end func_L16_00345F50 */
