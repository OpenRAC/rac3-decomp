/* func_L07_0035E490: NEAR 86 diff with the file's flags. Calls, argument registers and gp slots are right. The diff is the float constants: retail loads 0x3C8EFA35, 0x3DA3D70A and 0x3EB851EC with lui/ori/mtc1 (into $f13, $f20, $f21), gcc loads them from the gp pool. Tried: constants in locals, literal constants inline. */
#include "common.h"

extern f32 D_L07_001DD75C;
extern f32 D_L07_001DD760;
extern f32 D_L07_001DD764;
extern s32 D_L07_001DD748;
extern s32 D_L07_001DD758;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L07_0035E490(u8 *a0) {
    u8 *q;
    f32 f;
    f32 k;
    f32 c;

    k = 0.0174532924f;
    c = 0.0799999982f;
    q = *(u8 **)(a0 + 0x68);
    *(f32 *)(q + 0x10) = func_0038DAB8(*(f32 *)(q + 0x10), D_L07_001DD75C * k);
    f = func_00382538();
    func_003D9508(a0 + 0x10, D_L07_001DD748, D_L07_001DD758, 1, D_L07_001DD764, c, f);
    func_003D9508(a0 + 0x10, D_L07_001DD748, D_L07_001DD758, 1, D_L07_001DD764, c, *(f32 *)(q + 0x10) * 1.5f);
    f = func_0038DAB8(*(f32 *)(q + 0x10) * 2.5f, 0.0f);
    func_003D9508(a0 + 0x10, D_L07_001DD748, D_L07_001DD758, 1, D_L07_001DD764, c, f);
    func_003D9508(a0 + 0x10, 0x31, 0x10007FFF, 1, 0.360000014f, c, *(f32 *)(q + 0x10) * 0.5f);
    func_003D9508(a0 + 0x10, 0x31, 0x10007FFF, 1, 0.360000014f, c, *(f32 *)(q + 0x10) * -0.5f);
    f = func_00382538();
    func_003D9508(a0 + 0x10, 0x2F, 0x507F7F7F, 1, D_L07_001DD760, c, f);
}
