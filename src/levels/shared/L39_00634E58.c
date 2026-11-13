#include "common.h"

/* localdecomp:start func_L39_00634E58 */
extern void func_L39_006321F0(void *, void *, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern u8 D_L39_0025F760[];

s32 func_L39_00634E58(u8 *a0, f32 x, f32 y, f32 *out) {
    f32 zero = 0.0f;
    f32 v0[4];
    f32 v1[4];
    func_L39_006321F0(a0, v0, 1, *(f32 *)(a0 + 0x1F4) - 0.02f, zero, x);
    func_L39_006321F0(a0, v1, 1, y, zero, x);
    if (func_003D3CB0(v0, v1, 2, 0, 0)) {
        if (out != 0) {
            *out = func_0038CF00(v0, D_L39_0025F760);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00634E58 */
