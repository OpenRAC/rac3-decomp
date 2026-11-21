#include "common.h"

/* NTSC-U counterpart of func_L01_00301B10 (src/levels/shared/L01_00301B10.c): 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L01_00301968 */
extern vu0_v4 D_L01_001E2A40_00301968;
extern vu0_v4 D_001A4EC0;
extern f32 D_L01_001DC538;
__asm__(".extern D_L01_001DC538, 4");
extern f32 D_L01_001DC53C;
__asm__(".extern D_L01_001DC53C, 4");
extern s32 D_L01_001DC540;
__asm__(".extern D_L01_001DC540, 4");
extern s32 D_L01_001DC544;
__asm__(".extern D_L01_001DC544, 4");
extern s32 D_L01_001DC548;
__asm__(".extern D_L01_001DC548, 4");
extern s32 D_L01_001DC54C;
__asm__(".extern D_L01_001DC54C, 4");
extern f32 D_L01_001DC550;
__asm__(".extern D_L01_001DC550, 4");
extern f32 D_L01_001DC554;
__asm__(".extern D_L01_001DC554, 4");
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L01_00301968(u8 *o) {
    vu0_v4 d;
    vu0_v4 v10;
    vu0_v4 v20;
    u8 *st;
    s32 color;

    vec_sub_ab(&d, &D_L01_001E2A40_00301968, o + 0x10);
    st = *(u8 **)(o + 0x68);
    func_003886E8(&v10, &D_001A4EC0, func_0037E250(D_L01_001DC538 * 0.0166666675f, D_L01_001DC53C * 0.0166666675f));
    func_00389158(&v20, &v10, &d, func_0037E2A8());
    if (st[0x57] != 0) {
        color = D_L01_001DC54C;
    } else {
        color = D_L01_001DC544;
    }
    func_L01_00468DC0(o + 0x10, &v20, color, D_L01_001DC550, D_L01_001DC540, func_0037E1D8(0xFF) & 0xFF, 1, 0x40, 0);
    func_L01_00468DC0(o + 0x10, &v20, D_L01_001DC548, D_L01_001DC554, D_L01_001DC540, func_0037E1D8(0xFF) & 0xFF, 1, 0x40, 0);
}
/* localdecomp:end func_L01_00301968 */
