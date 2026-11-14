#include "common.h"

/* localdecomp:start func_L16_003E8D20 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L16_003E8D20(void *out, void *base, f32 lo, f32 hi)
{
    vu0_v4 v;
    f32 ang;

    qzero(&v);
    ang = func_00382538();
    v.x = func_0038D098(ang);
    v.y = func_0038D0B0(ang);
    func_0038CE20(&v, &v, func_003824E0(lo, hi));
    vec_add_ba(out, &v, base);
}
/* localdecomp:end func_L16_003E8D20 */

INCLUDE_ASM("asm/levels", func_L16_003E8DC0);

INCLUDE_ASM("asm/levels", func_L16_003E9068);
