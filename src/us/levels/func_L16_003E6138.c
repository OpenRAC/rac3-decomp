#include "common.h"

/* NTSC-U counterpart of func_L16_003E8068 (src/levels/16_kerwan/L16_003E8068.c) */
/* localdecomp:start func_L16_003E6138 */
#include "vu0.h"
/* from func_L14_00354538 (same effect-spawn shape) */
typedef int u128_t_3E8068 __attribute__((mode(TI)));
__asm__(".extern D_L16_001DF640_003E6138, 4");
__asm__(".extern D_L16_001DF644_003E6138, 4");
__asm__(".extern D_L16_001DF648_003E6138, 4");
extern f32 D_L16_001DF640_003E6138;
extern f32 D_L16_001DF644_003E6138;
extern f32 D_L16_001DF648_003E6138;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90_003E6138(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
void func_L16_003E6138(u8 *a0) {
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 b;
    f32 t;
    if (func_L01_00444358(a0, -1, 0) != 0) {
        *(u128_t_3E8068 *)&a = 0;
        a.y = -1.0f;
        a.z = -0.5f;
        func_00388830(&a, &a, 0.0666666701f);
        func_003888C8(&a, &a, a0 + 0xC0);
        func_L01_0044ED60(a0, 0x7F, &a, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_0039FE80(0, 0, a0);
        func_L01_0044F1E8(a0, 0x1D25, 0);
        t = 7.61092901f;
        *(u128_t_3E8068 *)&b = 0;
        b.y = D_L16_001DF640_003E6138;
        b.z = D_L16_001DF644_003E6138;
        c = b;
        func_003886E8(&c, &c, t);
        *(u128_t_3E8068 *)&b = 0;
        b.z = -0.1166666746f;
        func_L02_003E0520(a0, &c, 0.1f, &b, 0x14, 0, 0.15f, 1.5f, 20.0f, 1.0f, 0);
        func_003886E8(&c, &c, *(f32 *)(a0 + 0x2C));
        func_003888C8(&c, &c, a0 + 0xC0);
        vec_add_ab(&c, &c, a0 + 0x10);
        func_L01_0032FE90_003E6138(&c, 0, 0, 0, 0, 2, 5, 0, D_L16_001DF648_003E6138 * *(f32 *)(a0 + 0x2C) * t, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L16_003E6138 */
