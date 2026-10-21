#include "common.h"

/* localdecomp:start func_L31_00346B10 */
extern f32 D_L31_001DCFF4;
extern void func_003C4360(s32, f32, f32, f32, f32);

void func_L31_00346B10(u8 *a0, s32 a1, f32 x, f32 y, f32 z, f32 w, f32 u) {
    f32 t = x + (*(f32 *)(a0 + 16) < x ? -D_L31_001DCFF4 : D_L31_001DCFF4) * y;

    func_003C4360(a1, t - *(f32 *)(a0 + 16), w, u, z);
}
/* localdecomp:end func_L31_00346B10 */
