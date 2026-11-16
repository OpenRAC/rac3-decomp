#include "common.h"

/* NTSC-U counterpart of func_L39_00647730 (src/levels/shared/L39_00647730.c) */
/* localdecomp:start func_L39_00644F00 */
#include "vu0.h"
extern f32 D_001DA960_sda_00644F00;
__asm__(".extern D_001DA960_sda_00644F00, 4");
extern f32 D_001DA964_sda_00644F00;
__asm__(".extern D_001DA964_sda_00644F00, 4");
extern f32 D_001DA968_sda_00644F00;
__asm__(".extern D_001DA968_sda_00644F00, 4");
extern f32 D_001DA96C_sda_00644F00;
__asm__(".extern D_001DA96C_sda_00644F00, 4");
extern s32 D_001DA970_sda_00644F00;
__asm__(".extern D_001DA970_sda_00644F00, 4");
extern f32 D_001DA974_sda_00644F00;
__asm__(".extern D_001DA974_sda_00644F00, 4");
extern f32 D_001DA978_sda_00644F00;
__asm__(".extern D_001DA978_sda_00644F00, 4");
extern u32 D_001DA958_sda_00644F00;
__asm__(".extern D_001DA958_sda_00644F00, 4");
extern s32 D_001DA95C_sda_00644F00;
__asm__(".extern D_001DA95C_sda_00644F00, 4");
extern s32 func_L39_00637548(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
extern f32 func_L39_005B25C8_00644F00(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void *func_L39_005CBA68(vu0_v4 *pos, vu0_v4 *vel, u32 colour, f32 f, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);

void func_L39_00644F00(void *obj, void *a1) {
    u8 *o = obj;
    f32 b0[4];
    f32 b1[4];
    f32 b2[4];
    f32 b3[4];
    s32 i;
    s32 j;
    s32 cnt;
    f32 r, ang;

    if (o[0x1A14] != 0) {
        if (func_L39_00637548(o) == 2) {
            func_003886E8(b3, *(u8 **)(o + 0x2530) + 0x380, 1.5f);
            vec_add_ab(b1, b3, *(void **)(o + 0x2530));
            qzero(b2);
            for (j = 0; j < 50; j++) {
                func_0037E2F0(b0, 0.0f, 0.75f);
                vec_add_ab(b0, b1, b0);
                b0[2] = b0[2] - 0.4f;
                b2[2] = func_L39_005B2510(D_001DA964_sda_00644F00, D_001DA968_sda_00644F00) * 0.01666666753590107f;
                func_L39_005CBA68((vu0_v4 *)b0, (vu0_v4 *)b2, D_001DA958_sda_00644F00, D_001DA960_sda_00644F00, D_001DA95C_sda_00644F00, func_L39_005B2498(0xFF) & 0xFF, 0, 0x40, 0);
            }
        }
    }
    for (i = 0; i < D_001DA970_sda_00644F00; i++) {
        cnt = func_L39_005B2498(2);
        r = func_L39_005B2510(0.0f, 0.4f);
        ang = func_L39_005B25C8_00644F00();
        b0[0] = func_00388960(ang) * r;
        b0[1] = func_00388978(ang) * r;
        b0[2] = 0.0f;
        b0[2] = b0[2] + func_L39_005B2510(D_001DA974_sda_00644F00, D_001DA978_sda_00644F00);
        vec_add_ba(b0, b0, a1);
        *(vu0_q *)b2 = 0;
        b2[2] = func_L39_005B2510(D_001DA964_sda_00644F00, D_001DA968_sda_00644F00) * 0.01666666753590107f;
        *(vu0_q *)b1 = *(vu0_q *)b2;
        b1[2] = b1[2] + D_001DA96C_sda_00644F00 * 0.01666666753590107f * (0.4f - r) / 0.4f;
        if (cnt != 0) {
            b0[2] = b0[2] + 2.0f;
            func_003886E8(b1, b1, -1.0f);
        }
        func_L39_005CBA68((vu0_v4 *)b0, (vu0_v4 *)b1, D_001DA958_sda_00644F00, D_001DA960_sda_00644F00, D_001DA95C_sda_00644F00, func_L39_005B2498(0xFF) & 0xFF, 0, 0x40, 0);
    }
}
/* localdecomp:end func_L39_00644F00 */
