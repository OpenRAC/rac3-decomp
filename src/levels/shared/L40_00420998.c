#include "common.h"

/* localdecomp:start func_L40_00420998 */
extern f32 func_L39_005B4410(void);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L40_00420998(f32 *out) {
    f32 r = func_L39_005B4410();
    f32 a = func_L39_005B44C8();
    f32 b = func_L39_005B44C8();
    out[0] = func_0038D098(a) * func_0038D0B0(b) * r;
    out[1] = func_0038D0B0(a) * func_0038D0B0(b) * r;
    out[2] = 0.0f;
}
/* localdecomp:end func_L40_00420998 */
