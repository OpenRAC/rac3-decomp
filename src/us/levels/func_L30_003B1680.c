#include "common.h"

/* NTSC-U counterpart of func_L30_003B3358 (src/levels/shared/L30_003B3358.c) */
#include "vu0.h"

/* localdecomp:start func_L30_003B1680 */
extern s32 D_001DECD4_sda;
__asm__(".extern D_001DECD4_sda, 4");
extern f32 D_001DECE0_sda;
__asm__(".extern D_001DECE0_sda, 4");
extern f32 D_001DECE4_sda;
__asm__(".extern D_001DECE4_sda, 4");
extern s32 D_001DECD8_sda;
__asm__(".extern D_001DECD8_sda, 4");
extern s32 D_001DECDC_sda;
__asm__(".extern D_001DECDC_sda, 4");
extern s32 D_001DECB8_sda;
__asm__(".extern D_001DECB8_sda, 4");
extern f32 D_001DECB4_sda;
__asm__(".extern D_001DECB4_sda, 4");
extern s32 D_001DEC9C_sda;
__asm__(".extern D_001DEC9C_sda, 4");
extern s32 D_001DECA8_sda;
__asm__(".extern D_001DECA8_sda, 4");
extern s32 D_001DECA0_sda;
__asm__(".extern D_001DECA0_sda, 4");
extern s32 D_001DECAC_sda;
__asm__(".extern D_001DECAC_sda, 4");
extern s32 D_001DECA4_sda;
__asm__(".extern D_001DECA4_sda, 4");
extern s32 D_001DECB0_sda;
__asm__(".extern D_001DECB0_sda, 4");
extern s32 D_001DECC0_sda;
__asm__(".extern D_001DECC0_sda, 4");
extern s32 D_001DECC8_sda;
__asm__(".extern D_001DECC8_sda, 4");
extern f32 D_001DECCC_sda;
__asm__(".extern D_001DECCC_sda, 4");
extern f32 D_001DECD0_sda;
__asm__(".extern D_001DECD0_sda, 4");
extern s32 D_001DECBC_sda;
__asm__(".extern D_001DECBC_sda, 4");
extern s32 D_001DECC4_sda;
__asm__(".extern D_001DECC4_sda, 4");
extern u8 *D_L30_0021F098[];
extern u8 *D_L30_0021F21C[];
extern u8 *D_L30_0021F204[];
extern u8 *D_L30_0021F208[];
extern void func_0037E2F0(void *, f32, f32);
extern u8 *func_L30_004400E0(void *, s32, s32, f32, f32, s32);

void func_L30_003B1680(u8 *a0) {
    vu0_v4 v;
    s32 i;
    u8 *r;

    for (i = 0; i < D_001DECD4_sda; i++) {
        func_0037E2F0(&v, D_001DECE0_sda, D_001DECE0_sda * 0.5f);
        v.y = -fabs_asm(v.y);
        vec_add_ba(&v, &v, a0);
        r = func_L30_004400E0(&v, D_001DECD8_sda, D_001DECDC_sda, D_001DECE4_sda, D_001DECE4_sda * 0.4f, D_001DECB8_sda);
        if (r != 0) {
            r[2] = D_L30_0021F098[0x16C / 4][2];
        }
    }
    func_L30_004400E0(a0, D_001DEC9C_sda, D_001DECA8_sda, D_001DECB4_sda * 0.65f, D_001DECB4_sda * 0.1f, D_001DECB8_sda);
    r = func_L30_004400E0(a0, D_001DECA0_sda, D_001DECAC_sda, D_001DECB4_sda * 1.75f, D_001DECB4_sda * 0.4f, D_001DECB8_sda);
    if (r != 0) {
        r[2] = D_L30_0021F21C[0][2];
    }
    func_L30_004400E0(a0, D_001DECA4_sda, D_001DECB0_sda, D_001DECB4_sda * 1.35f, D_001DECB4_sda * 0.15f, D_001DECB8_sda);
    r = func_L30_004400E0(a0, D_001DECC0_sda, D_001DECC8_sda, D_001DECCC_sda, D_001DECD0_sda, D_001DECBC_sda);
    if (r != 0) {
        r[2] = D_L30_0021F204[0][2];
    }
    r = func_L30_004400E0(a0, D_001DECC4_sda, D_001DECC8_sda, D_001DECCC_sda * 0.7f, D_001DECD0_sda, D_001DECBC_sda);
    if (r != 0) {
        r[2] = D_L30_0021F208[0][4];
    }
}
/* localdecomp:end func_L30_003B1680 */
