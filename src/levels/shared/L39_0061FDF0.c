#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0061FDF0);

INCLUDE_ASM("asm/levels", func_L39_0061FEA8);

/* localdecomp:start func_L39_00620168 */
#include "vu0.h"
extern f32 D_L39_0024118C;
extern void func_0038CE20(void *, void *, f32);

void func_L39_00620168(vu0_v4 *out, s32 *outi, s32 base, vu0_v4 *vel, vu0_v4 acc, vu0_v4 *pos, s32 t0, s32 t1, f32 minv) {
    s32 m = (s32)minv;
    s32 d = t1 - t0;
    vu0_v4 vt, at;
    f32 t;

    if (d < m) {
        d = m;
    }
    *outi = base + d;
    *out = *pos;
    t = (f32)(*outi - t1) / (D_L39_0024118C * 1000.0f);
    func_0038CE20(&vt, vel, t);
    func_0038CE20(&at, &acc, t * 0.5f * t);
    vec_add_ab(out, out, &vt);
    vec_add_ab(out, out, &at);
}
/* localdecomp:end func_L39_00620168 */
