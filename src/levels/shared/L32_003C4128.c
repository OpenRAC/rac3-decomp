#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003C4128 */
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(f32 *, void *, f32);

void func_L32_003C4128(void *vector, void *axis, void *projected, void *remainder) {
    f32 dot;

    if (func_0038CEA8(axis) <= 0.0f) {
        *(vu0_q *)projected = *(vu0_q *)vector;
        qzero(remainder);
    } else {
        dot = func_0038CE68(axis, vector);
        func_0038CE20((f32 *)projected, axis, dot / func_0038CE68(axis, axis));
        __asm__ __volatile__(
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(*(vu0_v4 *)remainder)
            : "m"(*(vu0_v4 *)vector), "m"(*(vu0_v4 *)projected)
            : "vf1", "vf2");
    }
}
/* localdecomp:end func_L32_003C4128 */
