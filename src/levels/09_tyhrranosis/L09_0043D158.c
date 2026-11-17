#include "common.h"
#include "vu0.h"

typedef int s128_0043A1F8 __attribute__((mode(TI)));

/* localdecomp:start func_L09_0043D158 */
/* PAL port of the NTSC-U match src/us/levels/func_L09_0043A1F8.c */
#include "vu0.h"

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
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_004739D8(void *, void *, s32, s32, s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L09_0043D158(s128_0043A1F8 *a0) {
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
        func_0038CF68(&v30, &v20, func_003824E0(D_001D6C0C_sda, D_001D6C10_sda) * 0.020000001f);
        func_003C4C18(&v30, D_001D6C20_sda * 0.020000001f);
        func_0038CF68(&v40, &v20, D_001D6C00_sda);
        vec_add_ab(&v40, &v40, pv);
        func_003C4C18(&v40, D_001D6C1C_sda);
        f19 = func_003824E0(D_001D6C14_sda, D_001D6C18_sda) * 210000.0f;
        func_L01_004739D8(&v40, &v30, D_001D6C04_sda, D_001D6C08_sda, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 0, f19);
    }
    for (j = 0; j < D_001D6BB0_sda; j++) {
        *(s128_0043A1F8 *)&v30 = *(s128_0043A1F8 *)pv;
        func_003C4C18(&v30, D_001D6BCC_sda);
        v30.z += 0.5f;
        ang = func_00382538();
        f20 = func_003824E0(D_001D6BDC_sda, D_001D6BC0_sda);
        f21 = func_003824E0(D_001D6BC4_sda, D_001D6BC8_sda);
        f20 = f20 * 0.020000001f;
        qzero(&v40);
        v40.x += func_0038D098(ang) * f20;
        v40.y += func_0038D0B0(ang) * f20;
        v40.z += f21 * 0.020000001f;
        *(s128_0043A1F8 *)&v50 = *(s128_0043A1F8 *)&v40;
        v50.z -= func_003824E0(D_001D6BBC_sda * 0.7f, D_001D6BBC_sda * 1.3f) * 0.00040000002f * (f32)((D_001D6BB4_sda * 5 + 2) / 6);
        for (k = 0; k < D_001D6BD0_sda; k++) {
            f32 r = func_003824E0(0.5f, 1.5f);
            v40.w = r * D_001D6BE0_sda;
            v50.w = r * D_001D6BE4_sda;
            func_003C4C18(&v30, D_001D6BD4_sda);
            func_003C4C18(&v50, D_001D6BD8_sda * 0.020000001f);
            c1 = func_0038DBD8(D_001D6BE8_sda, D_001D6BF0_sda, func_003824E0(0.0f, 1.0f));
            c2 = func_0038DBD8(D_001D6BEC_sda, D_001D6BF4_sda, func_003824E0(0.0f, 1.0f));
            func_L01_00463378(&v30, &v40, &v50, c1, c2, (D_001D6BF8_sda * 5 + 2) / 6, (D_001D6BB4_sda * 5 + 2) / 6,
                              (s32)((func_003824E0((f32)D_001D6BB8_sda * 0.5f, (f32)D_001D6BB8_sda * 2.5f) * 5.0f + 2.0f) / 6.0f), -1);
        }
    }
}
/* localdecomp:end func_L09_0043D158 */

/* localdecomp:start func_L09_0043D590 */
extern f32 D_L09_001D6C3C;
extern f32 D_L09_001D6C2C;
extern f32 D_L09_001D6C30;
extern s32 D_001D6C24;
extern s32 D_001D6C28;
extern s32 D_L09_001D6C34;
extern s32 D_L09_001D6C38;
__asm__(".extern D_L09_001D6C3C, 4");
__asm__(".extern D_L09_001D6C2C, 4");
__asm__(".extern D_L09_001D6C30, 4");
__asm__(".extern D_001D6C24, 4");
__asm__(".extern D_001D6C28, 4");
__asm__(".extern D_L09_001D6C34, 4");
__asm__(".extern D_L09_001D6C38, 4");
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L09_0043D590(u8 *a0) {
    f32 v[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 n;
    a = func_00382538();
    b = func_003824E0(0.0f, D_L09_001D6C3C);
    c = func_003824E0(0.0f, D_L09_001D6C2C);
    d = func_003824E0(D_L09_001D6C2C, D_L09_001D6C30);
    n = func_00382498(D_L09_001D6C34, D_L09_001D6C38);
    v[0] = func_0038D098(a) * b;
    v[1] = func_0038D0B0(a) * b;
    v[2] = 0.0f;
    vec_add_ab(v, v, a0);
    v[2] = v[2] + 0.025f;
    func_L01_0046B288(c, d, v, D_001D6C24, D_001D6C28, n);
}
/* localdecomp:end func_L09_0043D590 */
