#include "common.h"

/* NTSC-U counterpart of func_L16_003E5488 (src/levels/shared/L16_003E5488.c) */
/* localdecomp:start func_L16_003E35D8 */
/* from func_L05_003DC0B0 (src/levels/05_daxx/L05_003DBE18.c), the same code with level 16's values */
#include "vu0.h"
typedef int u128_t_3E5488 __attribute__((mode(TI)));
extern f32 D_L16_001DF4BC;
__asm__(".extern D_L16_001DF4BC, 4");
extern f32 D_L16_001DF4C0;
__asm__(".extern D_L16_001DF4C0, 4");
extern u8 D_L16_001D66B0_003E35D8[8];
__asm__(".extern D_L16_001D66B0_003E35D8, 16");
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90_003E35D8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L16_003E35D8(u8 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0x7F, D_L16_001D66B0_003E35D8, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044F1E8(a0, 0x1CB1, 0);
        *(u128_t_3E5488 *)&b = 0;
        b.z = D_L16_001DF4BC;
        a = b;
        func_003886E8(&a, &a, 5.6500368f);
        *(u128_t_3E5488 *)&b = 0;
        b.z = -0.116666675f;
        func_L02_003E0520(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.15f, 1.5f, 20.0f, 1.0f);
        func_003886E8(&a, &a, *(f32 *)(a0 + 0x2C));
        func_003888C8(&a, &a, a0 + 0xC0);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_0032FE90_003E35D8(&a, 0, 0, 0, 0, 2, 5, 0, D_L16_001DF4C0 * 5.6500368f * 0.17439000f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L16_003E35D8 */
