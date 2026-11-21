#include "common.h"

/* NTSC-U counterpart of func_L13_003C63A8 (src/levels/shared/L13_003C62A8.c) */
/* localdecomp:start func_L13_003C41E0 */
#include "vu0.h"
typedef int u128_t_3C63A8 __attribute__((mode(TI)));
extern u8 D_L13_001D66B0_003C41E0;
__asm__(".extern D_L13_001DEBD8, 4");
__asm__(".extern D_L13_001DEBDC, 4");
__asm__(".extern D_L13_001DEBE0, 4");
extern f32 D_L13_001DEBD8;
extern f32 D_L13_001DEBDC;
extern f32 D_L13_001DEBE0;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90_003C41E0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L13_003C41E0(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0x3F, &D_L13_001D66B0_003C41E0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        *(u128_t_3C63A8 *)&a = 0;
        a.z = D_L13_001DEBD8;
        b = a;
        func_003886E8(&b, &b, t);
        *(u128_t_3C63A8 *)&a = 0;
        a.z = -0.11666667461f;
        func_L02_003E0520(a0, &b, 0.1f, &a, 0x14, 0, 0.15f, D_L13_001DEBE0 * t * *(f32 *)(a0 + 0x2C), 20.0f, 1.0f, 0);
        func_003886E8(&b, &b, *(f32 *)(a0 + 0x2C));
        func_003888C8(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_0032FE90_003C41E0(&b, 0, 0, 0, 0, 2, 5, 0, D_L13_001DEBDC * t * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L13_003C41E0 */
