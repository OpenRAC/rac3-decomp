#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00536EB0);

INCLUDE_ASM("asm/levels", func_L39_00537738);

/* localdecomp:start func_L39_00537908 */
extern f32 func_0038DB00(f32, f32);
extern void func_0038DAB8(f32, f32);

void func_L39_00537908(f32 x, f32 y, f32 lim) {
    f32 a;
    f32 b;
    f32 c;

    a = func_0038DB00(y, x);
    b = lim;
    if (!(0.0f < a)) {
        b = -b;
    }
    c = __builtin_fabsf(a);
    if (c < b) {
        b = c;
    } else if (b < -c) {
        b = -c;
    }
    func_0038DAB8(x, b);
}
/* localdecomp:end func_L39_00537908 */
