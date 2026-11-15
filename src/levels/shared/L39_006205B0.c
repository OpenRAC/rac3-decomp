#include "common.h"

/* localdecomp:start func_L39_006205B0 */
#include "vu0.h"
extern f32 D_L39_0024118C;
extern void func_0038CE20(void *, void *, f32);

void func_L39_006205B0(void *out, void *b, void *a, s32 *start, s32 *now) {
    f32 t;

    t = 1.0f / ((f32)(*now - *start) / (D_L39_0024118C * 1000.0f));
    vec_sub_ab(out, a, b);
    func_0038CE20(out, out, t);
}
/* localdecomp:end func_L39_006205B0 */
