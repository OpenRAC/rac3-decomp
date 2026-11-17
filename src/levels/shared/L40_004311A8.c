#include "common.h"

/* localdecomp:start func_L40_004311A8 */
#include "vu0.h"
extern void func_00382580(void *, f32, f32);
extern s32 func_0038DC20(f32 *, f32);
extern void func_L40_00430DD0(f32, u8 *, s32, s32, s32);
extern s32 D_L40_00247A0C;
__asm__(".extern D_L40_00247A0C, 4");

void func_L40_004311A8(u8 *a0, f32 f12, f32 f13, f32 f14, f32 f15, s32 a1, s32 a2, s32 a3) {
    vu0_v4 v;
    vu0_v4 base;
    vu0_v4 pos;
    f32 r;
    s32 i;
    s32 n;

    n = a2;
    if (n == 0x1FF) {
        n = 0xFF;
    }
    *(vu0_q *)&v = *(vu0_q *)(a0 + 0x10);
    v.w = f15 + f15;
    r = 128.0f;
    if (n > 0x80) {
        r = (f32)n;
    }
    if (func_0038DC20(&v.x, r) >= 0) {
        func_00382580(&base, f13 * 0.8f, f13 * 1.2f);
        base.z += f12;
        vec_add_ba(&base, &base, a0 + 0x10);
        for (i = 0; i < D_L40_00247A0C; i++) {
            func_00382580(&pos, f14 * 0.7f, f14 * 1.3f);
            vec_add_ab(&pos, &base, &pos);
            func_L40_00430DD0(f15 * 0.75f, (u8 *)&pos, a1, n, a3);
        }
    }
}
/* localdecomp:end func_L40_004311A8 */
