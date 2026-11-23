#include "common.h"

/* NTSC-U counterpart of func_L01_002FE0A0 (src/levels/shared/L01_002F7800.c): particle life 3 instead of 2 */
/* localdecomp:start func_L01_002FE070 */
extern f32 D_L01_001D66B0;
extern u8 *D_L01_00221288[];
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00466F98(f32 *, f32 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_002FE070(f32 *pos, f32 size) {
    f32 point[4];
    u8 *p;
    size *= 210000.0f;
    if (func_0037E1D8(2)) {
        s32 rotation = (s32)func_L01_00440918(1.0f, -1.0f);
        p = func_L01_00466F98(pos, &D_L01_001D66B0, 3, 6, 0x20FF40, rotation, size * 6.0f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p) p[2] = D_L01_00221288[0][1];
    }
    point[0] = pos[0] + func_L01_00440918(0.0f, 0.04f);
    point[1] = pos[1] + func_L01_00440918(0.0f, 0.04f);
    point[2] = pos[2] + func_L01_00440918(0.0f, 0.04f);
    if (func_0037E1D8(2)) {
        s32 rotation = (s32)func_L01_00440918(1.0f, -1.0f);
        p = func_L01_00466F98(point, &D_L01_001D66B0, 3, 127, 0x20FF40, rotation, size * 2.4f, 500.0f, 1.0f, 0.0f, 2.0f);
        if (p) {
            p[3] = func_0037E1D8(2) ? 72 : 68;
            p[2] = D_L01_00221288[0][0];
        }
    }
}
/* localdecomp:end func_L01_002FE070 */
