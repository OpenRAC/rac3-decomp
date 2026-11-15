#include "common.h"

/* localdecomp:start func_L39_00647730 */
#include "vu0.h"
extern f32 D_001DA960_sda;
__asm__(".extern D_001DA960_sda, 4");
extern f32 D_001DA964_sda;
__asm__(".extern D_001DA964_sda, 4");
extern f32 D_001DA968_sda;
__asm__(".extern D_001DA968_sda, 4");
extern f32 D_001DA96C_sda;
__asm__(".extern D_001DA96C_sda, 4");
extern s32 D_001DA970_sda;
__asm__(".extern D_001DA970_sda, 4");
extern f32 D_001DA974_sda;
__asm__(".extern D_001DA974_sda, 4");
extern f32 D_001DA978_sda;
__asm__(".extern D_001DA978_sda, 4");
extern u32 D_001DA958_sda;
__asm__(".extern D_001DA958_sda, 4");
extern s32 D_001DA95C_sda;
__asm__(".extern D_001DA95C_sda, 4");
extern s32 func_L39_00639D90(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void *func_L39_005CDE78(vu0_v4 *pos, vu0_v4 *vel, u32 colour, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f);

void func_L39_00647730(void *obj, void *a1) {
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
        if (func_L39_00639D90(o) == 2) {
            func_0038CE20(b3, *(u8 **)(o + 0x2530) + 0x380, 1.5f);
            vec_add_ab(b1, b3, *(void **)(o + 0x2530));
            qzero(b2);
            for (j = 0; j < 50; j++) {
                func_00382580(b0, 0.0f, 0.75f);
                vec_add_ab(b0, b1, b0);
                b0[2] = b0[2] - 0.4f;
                b2[2] = func_L39_005B4410(D_001DA964_sda, D_001DA968_sda) * 0.020000001f;
                func_L39_005CDE78((vu0_v4 *)b0, (vu0_v4 *)b2, D_001DA958_sda, (D_001DA95C_sda * 5 + 2) / 6, func_L39_005B4398(0xFF) & 0xFF, 0, 0x40, 0, D_001DA960_sda);
            }
        }
    }
    for (i = 0; i < D_001DA970_sda; i++) {
        cnt = func_L39_005B4398(2);
        r = func_L39_005B4410(0.0f, 0.4f);
        ang = func_L39_005B44C8();
        b0[0] = func_0038D098(ang) * r;
        b0[1] = func_0038D0B0(ang) * r;
        b0[2] = 0.0f;
        b0[2] = b0[2] + func_L39_005B4410(D_001DA974_sda, D_001DA978_sda);
        vec_add_ba(b0, b0, a1);
        *(vu0_q *)b2 = 0;
        b2[2] = func_L39_005B4410(D_001DA964_sda, D_001DA968_sda) * 0.020000001f;
        *(vu0_q *)b1 = *(vu0_q *)b2;
        b1[2] = b1[2] + D_001DA96C_sda * 0.020000001f * (0.4f - r) / 0.4f;
        if (cnt != 0) {
            b0[2] = b0[2] + 2.0f;
            func_0038CE20(b1, b1, -1.0f);
        }
        func_L39_005CDE78((vu0_v4 *)b0, (vu0_v4 *)b1, D_001DA958_sda, (D_001DA95C_sda * 5 + 2) / 6, func_L39_005B4398(0xFF) & 0xFF, 0, 0x40, 0, D_001DA960_sda);
    }
}
/* localdecomp:end func_L39_00647730 */
