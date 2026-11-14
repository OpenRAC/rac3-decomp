#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C4250 */
extern f32 D_001DEE44_sda;
__asm__(".extern D_001DEE44_sda, 4");
extern f32 D_001DEE48_sda;
__asm__(".extern D_001DEE48_sda, 4");
extern f32 D_001DEE4C_sda;
__asm__(".extern D_001DEE4C_sda, 4");
extern f32 D_001DEE50_sda;
__asm__(".extern D_001DEE50_sda, 4");
extern s32 D_001DEE54_sda;
__asm__(".extern D_001DEE54_sda, 4");
extern s32 D_001DEE58_sda;
__asm__(".extern D_001DEE58_sda, 4");
extern s32 D_001DEE5C_sda;
__asm__(".extern D_001DEE5C_sda, 4");
extern f32 D_001DEE60_sda;
__asm__(".extern D_001DEE60_sda, 4");
extern f32 D_001DEE64_sda;
__asm__(".extern D_001DEE64_sda, 4");
extern s32 D_001DEE68_sda;
__asm__(".extern D_001DEE68_sda, 4");
extern s32 D_001DEE6C_sda;
__asm__(".extern D_001DEE6C_sda, 4");
extern f32 D_001DEE70_sda;
__asm__(".extern D_001DEE70_sda, 4");
extern f32 D_001DEE74_sda;
__asm__(".extern D_001DEE74_sda, 4");
extern s32 D_001DEE78_sda;
__asm__(".extern D_001DEE78_sda, 4");
extern s32 D_001DEE7C_sda;
__asm__(".extern D_001DEE7C_sda, 4");
extern s32 D_001DEE80_sda;
__asm__(".extern D_001DEE80_sda, 4");
extern vu0_v4 D_L03_001E24C0_003C4250;
extern s32 D_L03_001DF540;
__asm__(".extern D_L03_001DF540, 16");
extern s32 D_001DF540_sda;
__asm__(".extern D_001DF540_sda, 4");
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003894A0(s32, s32, f32);

void func_L03_003C4250(u8 *obj) {
    vu0_v4 pos, vel, random, start, delta;
    s32 i, phase, emit;
    s32 color, alpha;
    f32 factor;
    func_003888C8(&pos, &D_001DEE80_sda, obj + 0xC0);
    vec_add_ab(&pos, &pos, obj + 0x10);
    emit = func_0037E1D8(4);
    if (emit == 0) {
        s32 n;
        func_L01_00440A88(&vel, D_001DEE44_sda * 0.0166666675f, D_001DEE48_sda * 0.0166666675f);
        func_L01_00468DC0(&pos, &vel, D_001DEE58_sda, D_001DEE60_sda, D_001DEE54_sda, func_0037E1D8(255) & 255, 0, 0x40, 0);
        for (n = 2; n >= 0; n--) {
            func_L01_00440A88(&random, D_001DEE4C_sda * 0.0166666675f, D_001DEE50_sda * 0.0166666675f);
            vec_add_ab(&vel, &vel, &random);
            func_L01_00468DC0(&pos, &vel, D_001DEE5C_sda, D_001DEE64_sda, D_001DEE54_sda, func_0037E1D8(255) & 255, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&start, &D_L03_001E24C0_003C4250, &pos);
    func_00388830(&start, &start, -0.3f);
    func_00388830(&delta, &start, 0.1f);
    vec_add_ab(&start, &start, &pos);
    for (i = 0; i < 4; i++) {
        factor = fabs_asm(0.5f - (f32)(255 - ((D_L03_001DF540 + i * 20) & 255)) / 255.0f);
        color = func_003894A0(D_001DEE68_sda, D_001DEE6C_sda, factor);
        factor = (D_001DEE70_sda + (f32)i * D_001DEE74_sda) * (*(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24));
        alpha = (u8)D_L03_001DF540;
        if (i & 2) alpha *= 2;
        if (i & 1) alpha = 255 - alpha;
        func_L01_00468C38(&start, color, alpha & 255, D_001DEE7C_sda, D_001DEE78_sda, 2, 0, 0, factor);
        vec_add_ab(&start, &start, &delta);
    }
}
/* localdecomp:end func_L03_003C4250 */
