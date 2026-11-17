/* NTSC-U draft (2026-11-14, Claude worker): C of func_L35_003A37E8, the NTSC-U twin of func_L35_003A5100, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2" (src/levels/35_vidcomic_5/L35_003A29A8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L35_003A37E8 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) and @ps2as (float immediates) beyond the PAL file's flags. */
extern u8 *D_L35_0021F444[];

extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L35_003A37E8(void *self) {
    u8 *o = self;
    vu0_v4 a;
    vu0_v4 b;
    s32 color;
    f32 f;
    u8 *p;

    func_0037E2F0(&a, 0.0f, 0.25f);
    vec_add_ba(&a, &a, o + 0x10);
    func_0037E2F0(&b, 0.0f, 0.0083333338f);
    color = 0x59F9FF;
    if (func_0037E1D8(3)) color = 0xFFED74;
    f = func_0037E250(0.8f, 1.2f);
    p = func_L01_00472438(&a, &b, 0x46, func_0037E208(-2, 2), color | 0x50000000, color, 0, f * 210000.0f, 105000.0f, -1.0f);
    if (p != 0) {
        p[2] = D_L35_0021F444[0][2];
        p[3] = func_0037E1D8(2) ? 0x44 : 0x48;
    }
}
/* localdecomp:end func_L35_003A37E8 */
