#include "common.h"

/* NTSC-U counterpart of func_L04_003EC000 (src/levels/04_marcadia/L04_003EBDB8.c) */
#include "vu0.h"

typedef int u128_t_3EBDB8 __attribute__((mode(TI)));
extern u8 D_L04_001D66B0_003E9EB8[8];
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

/* localdecomp:start func_L04_003E9EB8 */
typedef int u128_t_3EC000 __attribute__((mode(TI)));
extern u8 D_L04_001D66B0_003E9EB8[8];
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L04_003E9EB8(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0xF, D_L04_001D66B0_003E9EB8, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044F1E8(a0, 0x1F25, 0);
        t = *(f32 *)(a0 + 0x2C) / 0.03721f;
        *(u128_t_3EC000 *)&b = 0;
        b.y = -0.3f;
        b.z = t * 0.2f;
        func_003888C8(&b, &b, a0 + 0xC0);
        *(u128_t_3EC000 *)&a = 0;
        a.z = -0.116666675f;
        func_L02_003E0520(a0, &b, 0.1f, &a, 0x50, 3, 0.15f, 2.5f, 20.0f, 1.0f, 0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_0032FE90(&b, 0, 0, 0, 0, 2, 5, 0, t * 0.6f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L04_003E9EB8 */
