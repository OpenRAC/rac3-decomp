#include "common.h"

/* localdecomp:start func_L01_003D46A8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V4_3D46A8;

extern void func_L01_0044DB68(s32, V4_3D46A8 *, f32, f32, f32);
extern void func_L01_003D41E8(s32, V4_3D46A8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_003D46A8(s32 a0, s32 a1, s32 a2, s32 a3, f32 x, f32 y) {
    V4_3D46A8 v;

    func_L01_0044DB68(a0, &v, 0.35f, 0.0f, y);
    func_L01_003D41E8(a0, &v, a3, 1, a1, a2, 1, 0.2f, 1.0f, 0.0033333336f, x, 0.0f);
}
/* localdecomp:end func_L01_003D46A8 */
