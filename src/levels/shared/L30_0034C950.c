#include "common.h"

LINKER_REMNANT("asm/levels", func_L30_0034C950);

/* localdecomp:start func_L30_0034C958 */
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L30_0034C958(vu0_v4 *p, f32 radius)
{
    vu0_v4 off;
    f32 r;
    f32 a;

    r = func_003824E0(0.0f, radius);
    a = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    off.x = func_0038D098(a) * r;
    off.z = func_0038D0B0(a) * r;
    off.y = 0.0f;
    vec_add_ab(p, p, &off);
}
/* localdecomp:end func_L30_0034C958 */
