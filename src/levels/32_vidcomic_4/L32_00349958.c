#include "common.h"

/* localdecomp:start func_L32_00349958 */
extern f32 func_L32_00348900(u8 *);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L32_001DD000;
__asm__(".extern D_L32_001DD000, 4");

s32 func_L32_00349958(u8 *a0, s32 a1, f32 f) {
    f32 t = f - func_L32_00348900(a0);
    f32 q;

    t = t + t;
    q = t / (f32)a1;
    if (q > 2.0f) {
        q = 2.0f;
    } else if (q < 0.0f) {
        q = 0.0f;
    }
    func_003C4138((f32 *)(a0 + 0x48), q, D_L32_001DD000);
    return 0;
}
/* localdecomp:end func_L32_00349958 */
