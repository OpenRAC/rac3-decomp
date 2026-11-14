#include "common.h"

/* NTSC-U counterpart of func_L40_003EDA10 (src/levels/shared/L40_003ED980.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L40_003ED570 */
extern s32 D_001DB6A8_sda;
__asm__(".extern D_001DB6A8_sda, 4");
extern u8 D_001DB6B0_sda[8];
__asm__(".extern D_001DB6B0_sda, 8");
extern f32 func_L39_005B2510(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L39_005B2498(s32);
extern void func_L39_005CD310(void *, void *, void *, void *, s32);

void func_L40_003ED570(u8 *a0) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));

    if (a0[0x31] != 0) {
        *(u128_t *)v20 = 0;
        v20[2] = -(func_L39_005B2510(1.0f, 2.0f) * 0.0166666675f);
        *(u128_t *)v10 = *(u128_t *)v20;
        func_003BDA38(a0, D_001DB6A8_sda, v0);
        func_L39_005CD310(a0, v0, v10, D_001DB6B0_sda + (func_L39_005B2498(3) << 4), 1);
    }
}
/* localdecomp:end func_L40_003ED570 */
