#include "common.h"

/* NTSC-U counterpart of func_L05_003C3C98 (src/levels/05_daxx/L05_003DBE18.c) */
#include "vu0.h"
/* localdecomp:start func_L10_003C3C98 */
typedef int u128_t_3C3C98 __attribute__((mode(TI)));
extern u8 D_L10_001D66B0_003C3C98[8];
__asm__(".extern D_L10_001D66B0_003C3C98, 16");
extern f32 D_L10_001DE8C8;
__asm__(".extern D_L10_001DE8C8, 4");
extern f32 D_L10_001DE8CC;
__asm__(".extern D_L10_001DE8CC, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L10_003C3C98(u8 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0xF, D_L10_001D66B0_003C3C98, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044F1E8(a0, 0x1EAB, 0);
        *(u128_t_3C3C98 *)&b = 0;
        b.z = D_L10_001DE8C8;
        a = b;
        func_003886E8(&a, &a, 21.81024932861328f);
        *(u128_t_3C3C98 *)&b = 0;
        b.z = -0.11666667461395264f;
        func_L02_003E0520(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.15f, *(f32 *)(a0 + 0x2C) * 32.71537399291992f, 20.0f, 1.0f);
        func_003886E8(&a, &a, *(f32 *)(a0 + 0x2C));
        func_003888C8(&a, &a, a0 + 0xC0);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_0032FE90(&a, 0, 0, 0, 0, 2, 5, 0, D_L10_001DE8CC * 21.81024932861328f * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFF, 0x9090FF, 0, 0, 0, 0, 0x5186FF, 0x2A5CFF, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L10_003C3C98 */
