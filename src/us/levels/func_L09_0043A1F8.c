#include "common.h"

/* NTSC-U counterpart of func_L09_0043D158 (src/levels/09_tyhrranosis/L09_0043D158.c) */
#include "vu0.h"

/* localdecomp:start func_L09_0043A1F8 */
typedef int s128_0043A1F8 __attribute__((mode(TI)));
extern s32 D_001D6BFC_sda;
__asm__(".extern D_001D6BFC_sda, 4");
extern f32 D_001D6C0C_sda;
__asm__(".extern D_001D6C0C_sda, 4");
extern f32 D_001D6C10_sda;
__asm__(".extern D_001D6C10_sda, 4");
extern f32 D_001D6C20_sda;
__asm__(".extern D_001D6C20_sda, 4");
extern f32 D_001D6C00_sda;
__asm__(".extern D_001D6C00_sda, 4");
extern f32 D_001D6C1C_sda;
__asm__(".extern D_001D6C1C_sda, 4");
extern f32 D_001D6C14_sda;
__asm__(".extern D_001D6C14_sda, 4");
extern f32 D_001D6C18_sda;
__asm__(".extern D_001D6C18_sda, 4");
extern s32 D_001D6C04_sda;
__asm__(".extern D_001D6C04_sda, 4");
extern s32 D_001D6C08_sda;
__asm__(".extern D_001D6C08_sda, 4");
extern s32 D_001D6BB0_sda;
__asm__(".extern D_001D6BB0_sda, 4");
extern f32 D_001D6BCC_sda;
__asm__(".extern D_001D6BCC_sda, 4");
extern f32 D_001D6BDC_sda;
__asm__(".extern D_001D6BDC_sda, 4");
extern f32 D_001D6BC0_sda;
__asm__(".extern D_001D6BC0_sda, 4");
extern f32 D_001D6BC8_sda;
__asm__(".extern D_001D6BC8_sda, 4");
extern f32 D_001D6BC4_sda;
__asm__(".extern D_001D6BC4_sda, 4");
extern f32 D_001D6BBC_sda;
__asm__(".extern D_001D6BBC_sda, 4");
extern s32 D_001D6BB4_sda;
__asm__(".extern D_001D6BB4_sda, 4");
extern s32 D_001D6BD0_sda;
__asm__(".extern D_001D6BD0_sda, 4");
extern f32 D_001D6BE0_sda;
__asm__(".extern D_001D6BE0_sda, 4");
extern f32 D_001D6BE4_sda;
__asm__(".extern D_001D6BE4_sda, 4");
extern f32 D_001D6BD4_sda;
__asm__(".extern D_001D6BD4_sda, 4");
extern f32 D_001D6BD8_sda;
__asm__(".extern D_001D6BD8_sda, 4");
extern s32 D_001D6BE8_sda;
__asm__(".extern D_001D6BE8_sda, 4");
extern s32 D_001D6BF0_sda;
__asm__(".extern D_001D6BF0_sda, 4");
extern s32 D_001D6BEC_sda;
__asm__(".extern D_001D6BEC_sda, 4");
extern s32 D_001D6BF4_sda;
__asm__(".extern D_001D6BF4_sda, 4");
extern s32 D_001D6BB8_sda;
__asm__(".extern D_001D6BB8_sda, 4");
extern s32 D_001D6BF8_sda;
__asm__(".extern D_001D6BF8_sda, 4");
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00470258(void *, void *, s32, s32, s32, s32, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L09_0043A1F8(s128_0043A1F8 *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 *pv;
    s32 i;
    s32 j;
    s32 k;
    s32 c1;
    s32 c2;
    f32 ang;
    f32 f19;
    f32 f20;
    f32 f21;

    pv = &v10;
    *(s128_0043A1F8 *)pv = *a0;
    *(s128_0043A1F8 *)&v20 = 0;
    v20.z = 1.0f;
    for (i = 0; i < D_001D6BFC_sda; i++) {
        func_00388830(&v30, &v20, func_0037E250(D_001D6C0C_sda, D_001D6C10_sda) * 0.0166666675f);
        func_003BF6A8(&v30, D_001D6C20_sda * 0.0166666675f);
        func_00388830(&v40, &v20, D_001D6C00_sda);
        vec_add_ab(&v40, &v40, pv);
        func_003BF6A8(&v40, D_001D6C1C_sda);
        f19 = func_0037E250(D_001D6C14_sda, D_001D6C18_sda) * 210000.0f;
        func_L01_00470258(&v40, &v30, D_001D6C04_sda, D_001D6C08_sda, (s16)func_0037E208(0x78, 0xF0), 0, f19);
    }
    for (j = 0; j < D_001D6BB0_sda; j++) {
        *(s128_0043A1F8 *)&v30 = *(s128_0043A1F8 *)pv;
        func_003BF6A8(&v30, D_001D6BCC_sda);
        v30.z += 0.5f;
        ang = func_0037E2A8();
        f20 = func_0037E250(D_001D6BDC_sda, D_001D6BC0_sda);
        f21 = func_0037E250(D_001D6BC4_sda, D_001D6BC8_sda);
        f20 = f20 * 0.0166666675f;
        qzero(&v40);
        v40.x += func_00388960(ang) * f20;
        v40.y += func_00388978(ang) * f20;
        v40.z += f21 * 0.0166666675f;
        *(s128_0043A1F8 *)&v50 = *(s128_0043A1F8 *)&v40;
        v50.z -= func_0037E250(D_001D6BBC_sda * 0.7f, D_001D6BBC_sda * 1.3f) * 0.000277777778f * (f32)D_001D6BB4_sda;
        for (k = 0; k < D_001D6BD0_sda; k++) {
            f32 r = func_0037E250(0.5f, 1.5f);
            v40.w = r * D_001D6BE0_sda;
            v50.w = r * D_001D6BE4_sda;
            func_003BF6A8(&v30, D_001D6BD4_sda);
            func_003BF6A8(&v50, D_001D6BD8_sda * 0.0166666675f);
            c1 = func_003894A0(D_001D6BE8_sda, D_001D6BF0_sda, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(D_001D6BEC_sda, D_001D6BF4_sda, func_0037E250(0.0f, 1.0f));
            func_L01_0045FEC8(&v30, &v40, &v50, c1, c2, D_001D6BF8_sda, D_001D6BB4_sda,
                              (s32)func_0037E250((f32)D_001D6BB8_sda * 0.5f, (f32)D_001D6BB8_sda * 2.5f), -1);
        }
    }
}
/* localdecomp:end func_L09_0043A1F8 */
