#include "common.h"

/* NTSC-U counterpart of func_L08_003A17C0 (src/levels/shared/L08_003A17C0.c) */
#include "vu0.h"

/* localdecomp:start func_L08_0039FB40 */
extern f32 D_L08_001DE29C_0039FB40;
__asm__(".extern D_L08_001DE29C_0039FB40, 4");
extern u8 *D_L08_0021EB18_0039FB40[];
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);

void func_L08_0039FB40(void *unused, void *owner, void *c) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    s32 i;
    s32 n;
    u8 *p;
    f32 speed;

    i = 0;
    do {
        func_003886E8(&v50, (u8 *)c + 0x20, func_0037E250(0.0f, 0.75f));
        vec_add_ab(&v0, &v50, c);
        func_003886E8(&v50, (u8 *)c + 0x10, func_L01_00440918(0.0f, 0.5f));
        vec_add_ab(&v0, &v50, &v0);
        func_003886E8(&v10, &v0, func_0037E250(D_L08_001DE29C_0039FB40 * 0.25f, D_L08_001DE29C_0039FB40) * 0.016666668f);
        p = func_L01_0046DCB8(owner, &v10, func_0037E208(50, 70), 0x5A182, func_0037E208(1, 4), 0x30, 0, 0,
                              63000.004f, 42000.0f, 0.0013888889f);
        n = 3;
        if (p != 0) {
            p[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
            p[2] = D_L08_0021EB18_0039FB40[0x69][0];
        }
        speed = D_L08_001DE29C_0039FB40;
        if (i < n * 4) {
            func_003886E8(&v20, &v0, func_0037E250(speed * 0.12f, speed * 0.5f) * 0.016666668f);
            p = func_L01_0046DCB8(owner, &v20, func_0037E208(50, 70), 0x5A182, func_0037E208(-1, -3), 0x20, 0, 0,
                                  84000.0f, 168000.0f, 0.0013888889f);
            if (p != 0) {
                p[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
                p[2] = D_L08_0021EB18_0039FB40[0x17][0];
            }
            func_003886E8(&v30, &v0, func_0037E250(D_L08_001DE29C_0039FB40 * 0.3f, D_L08_001DE29C_0039FB40 * 0.55f) * 0.016666668f);
            p = func_L01_0046DCB8(owner, &v30, func_0037E208(50, 70), 0xFFC8, -1, 0x60, 0, 0,
                                  126000.01f, 42000.0f, 0.0011111111f);
            if (p != 0) {
                p[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
                p[2] = D_L08_0021EB18_0039FB40[0x22][0];
            }
        }
        if (i < 9) {
            func_003886E8(&v40, &v0, func_0037E250(D_L08_001DE29C_0039FB40 * 0.12f, D_L08_001DE29C_0039FB40 * 0.5f) * 0.016666668f);
            func_L01_00463938(owner, &v40, 0x4000FFC8, -1.0f, -0.0055555557f);
        }
    } while (++i < n * 4 + 3);
}
/* localdecomp:end func_L08_0039FB40 */
