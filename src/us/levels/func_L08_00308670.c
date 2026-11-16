#include "common.h"

/* NTSC-U counterpart of func_L08_00308978 (src/levels/shared/L08_00308978.c) */
/* localdecomp:start func_L08_00308670 */
#include "vu0.h"

__asm__(".extern D_L08_001DC50C, 4");
__asm__(".extern D_L08_001DC510, 4");
__asm__(".extern D_L08_001DC514, 4");
__asm__(".extern D_L08_001DC518, 4");
__asm__(".extern D_L08_001DC51C, 4");
__asm__(".extern D_L08_001DC520, 4");
__asm__(".extern D_L08_001DC524, 4");
__asm__(".extern D_L08_001DC528, 4");
__asm__(".extern D_L08_001DC52C, 4");
__asm__(".extern D_L08_001DC530, 4");
__asm__(".extern D_L08_001DC534, 4");
__asm__(".extern D_L08_001DC538, 4");
__asm__(".extern D_L08_001DC53C, 4");
extern f32 D_L08_001DC50C;
extern f32 D_L08_001DC510;
extern f32 D_L08_001DC514;
extern f32 D_L08_001DC518;
extern s32 D_L08_001DC51C;
extern s32 D_L08_001DC520;
extern s32 D_L08_001DC524;
extern f32 D_L08_001DC528;
extern f32 D_L08_001DC52C;
extern s32 D_L08_001DC530;
extern s32 D_L08_001DC534;
extern s32 D_L08_001DC538;
extern s32 D_L08_001DC53C;
extern s32 D_L08_001DEDC0_00308670;
extern vu0_v4 D_L08_001E1CC0_00308670;

extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);

void func_L08_00308670(u8 *o) {
    vu0_v4 pos, v10, v20, v30, v40;
    s32 i, j;
    s32 c;
    f32 q;

    *(vu0_q *)&pos = *(vu0_q *)(o + 0x10);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&v10, D_L08_001DC50C * 0.0166666675f, D_L08_001DC510 * 0.0166666675f);
        i = 2;
        func_L01_00468DC0(&pos, &v10, D_L08_001DC520, D_L08_001DC528, D_L08_001DC51C, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        do {
            func_L01_00440A88(&v20, D_L08_001DC514 * 0.0166666675f, D_L08_001DC518 * 0.0166666675f);
            vec_add_ab(&v10, &v10, &v20);
            func_L01_00468DC0(&pos, &v10, D_L08_001DC524, D_L08_001DC52C, D_L08_001DC51C, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        } while (--i >= 0);
    }
    vec_sub_ba(&v30, &D_L08_001E1CC0_00308670, &pos);
    func_00388830(&v30, &v30, -0.3f);
    func_00388830(&v40, &v30, 0.1f);
    vec_add_ab(&v30, &v30, &pos);
    for (j = 0; j < 4; j++) {
        s32 x = (D_L08_001DEDC0_00308670 + j * 20) & 0xFF;
        s32 r = func_003894A0(D_L08_001DC530, D_L08_001DC534, fabs_asm(0.5f - (f32)(255 - x) / 255.0f));
        c = *(u8 *)&D_L08_001DEDC0_00308670;
        if (j & 2) c = c << 1;
        if (j & 1) c = 255 - c;
        func_L01_00468C38(&v30, r, c & 0xFF, D_L08_001DC53C, D_L08_001DC538, 2, 0,
                          0, ((f32)j + 3.0f) * (*(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24)));
        vec_add_ab(&v30, &v30, &v40);
    }
}
/* localdecomp:end func_L08_00308670 */
