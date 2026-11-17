#include "common.h"

/* localdecomp:start func_L01_00486A38 */
extern s32 func_00381FF0();
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L05_001DC028;
__asm__(".extern D_L05_001DC028, 16");

void func_L01_00486A38(s32 a0, f32 *a1, f32 *a2) {
    s32 p;
    f32 hi;
    f32 lo;
    f32 k;
    f32 r;
    f32 s;
    f32 t;

    p = func_00381FF0();
    k = 0.49f;
    lo = 6.0f;
    r = (f32)func_0038E548(p, -1, 1.2f) / D_L05_001DC028;
    s = 1.2f;
    hi = 11.0f;
    if (k < r) {
        s = 0.58800006f / r;
        r = k;
    }
    t = func_003C4088(lo, hi, (r - 0.0f) / k);
    do {
        *a2 = t;
        if (hi < t) {
            *a2 = hi;
        } else if (t < lo) {
            *a2 = lo;
        }
    } while (0);
    *a1 = s;
}
/* localdecomp:end func_L01_00486A38 */
