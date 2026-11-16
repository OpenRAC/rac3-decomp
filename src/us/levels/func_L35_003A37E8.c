#include "common.h"

/* NTSC-U counterpart of func_L35_003A5100 (src/levels/35_vidcomic_5/L35_003A4EA8.c) */
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
#include "vu0.h"
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

/* localdecomp:start func_L35_003A37E8 */
#include "vu0.h"
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *D_L35_0021F444[];

void func_L35_003A37E8(s32 arg0) {
    u8 *o = (u8 *)arg0;
    vu0_v4 pos;
    vu0_v4 vel;
    s32 color;
    f32 r;
    u8 *p;

    func_0037E2F0(&pos, 0.0f, 0.25f);
    vec_add_ba(&pos, &pos, o + 0x10);
    func_0037E2F0(&vel, 0.0f, 0.008333333767950535f);
    color = func_0037E1D8(3) ? 0xFFED74 : 0x59F9FF;
    r = func_0037E250(0.8f, 1.2f);
    p = func_L01_00472438(&pos, &vel, 0x46, func_0037E208(-2, 2), color | 0x50000000, color,
                          r * 210000.0f, 105000.0f, -1.0f, 0);
    if (p != 0) {
        p[2] = D_L35_0021F444[0][2];
        p[3] = func_0037E1D8(2) ? 0x44 : 0x48;
    }
}
/* localdecomp:end func_L35_003A37E8 */
