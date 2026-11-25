#include "common.h"
#include "vu0.h"

/* localdecomp:start func_U_L20_003F27E0 */
extern u8 *D_L20_00220258[];
extern u32 D_L20_001DF02C, D_L20_001DF030;
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00440A88(f32 *, f32, f32);
/* Based on the PAL counterpart, func_L20_003F4918. */
void func_U_L20_003F27E0(void *a0) {
    vu0_v4 v;
    f32 size;
    u32 col;
    u8 *e;
    func_L01_00440A88(&v.x, 0.016666668f, 0.041666668f);
    v.z = fabs_asm(v.z) + func_0037E250(7.0f, 10.5f) * 0.016666668f;
    size = func_0037E250(0.06f, 0.22f);
    /* The default colour is overwritten, but its random draw is retained. */
    col = func_0037E1D8(3) ? D_L20_001DF02C : D_L20_001DF030;
    col = func_0037E1D8(3) ? 0x263438 : 0x273538;
    e = func_L01_0046DCB8(
        a0, &v, func_0037E208(90, 150), col, -2, 0x7F, 0x7F, size * 210000.0f, size * 210000.0f, 0.0043333336f, 0);
    if (e != 0) {
        e[2] = D_L20_00220258[0x184 / 4][func_0037E1D8(3) + 10];
        e[3] = 0x44;
    }
}
/* localdecomp:end func_U_L20_003F27E0 */
