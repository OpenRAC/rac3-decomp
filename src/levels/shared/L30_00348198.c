#include "common.h"

/* localdecomp:start func_L30_00348198 */
#include "vu0.h"

extern vu0_v4 D_L30_001E9020;

extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);

void func_L30_00348198(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0x68);
    vu0_v4 t;

    if (func_L01_003FB640(moby + 0x10, 0x12, moby, *(f32 *)(vars + 0x40)) != 0) {
        vec_sub_ab(&t, moby + 0x10, &D_L30_001E9020);
        func_0038CF68(&t, &t, *(f32 *)(vars + 0x40));
        vec_add_ba(moby + 0x10, &t, &D_L30_001E9020);
        func_0038CE20(&t, &t, -1.0f);
        *(f32 *)(vars + 0x48) = func_0038D160(t.x, t.z);
    }
}
/* localdecomp:end func_L30_00348198 */
