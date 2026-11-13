#include "common.h"

/* localdecomp:start func_L31_00346798 */
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0xF8 - 0x14];
    f32 fF8;
} S_345C88;

extern f32 D_001A4C60[];
extern f32 func_0038DB00(f32 a, f32 b);

s32 func_L31_00346798(S_345C88 *a0, f32 a, f32 b, f32 c) {
    f32 x = a;
    if (a0->f10 < D_001A4C60[0]) {
        x = b;
    }
    if (c < __builtin_fabsf(func_0038DB00(a0->fF8, x))) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L31_00346798 */

/* localdecomp:start func_L31_00346800 */
#include "vu0.h"

extern s32 func_L31_00346838(void *, void *, vu0_v4 *, s32, f32, f32);

s32 func_L31_00346800(void *a0, void *a1, s32 a2, f32 f) {
    vu0_v4 v;

    qzero(&v);
    v.z = -1.0f;
    return func_L31_00346838(a0, a1, &v, a2, f, f);
}
/* localdecomp:end func_L31_00346800 */
