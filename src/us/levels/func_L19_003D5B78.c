#include "common.h"

/* NTSC-U counterpart of func_L19_003D7F80 (src/levels/19_thran_asteroid_belt/L19_003D7AE8.c) */
#include "vu0.h"

extern void func_003886E8(void *, void *, f32);
typedef struct { u8 pad[0x28]; f32 x28; f32 x2C; } D_3D7C88;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; D_3D7C88 *x68; u8 pad6C[0x74]; vu0_v4 xE0; } M_3D7C88;
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L19_003D5B78 */
typedef int u128_t_3D7F80 __attribute__((mode(TI)));
extern u8 D_L19_001D66F0_003D5B78;
__asm__(".extern D_L19_001DED38, 4");
__asm__(".extern D_L19_001DED3C, 4");
extern f32 D_L19_001DED38;
extern f32 D_L19_001DED3C;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L19_003D5B78(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0x1F, &D_L19_001D66F0_003D5B78, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        *(u128_t_3D7F80 *)&b = 0;
        func_003886E8(&b, &b, t);
        *(u128_t_3D7F80 *)&a = 0;
        a.z = -0.116666675f;
        func_L02_003E0520(a0, &b, 0.1f, &a, 0x14, 0, 0.15f, D_L19_001DED3C * t * *(f32 *)(a0 + 0x2C), 20.0f, 1.0f, 0);
        func_003886E8(&b, &b, *(f32 *)(a0 + 0x2C));
        func_003888C8(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_0032FE90(&b, 0, 0, 0, 0, 2, 5, 0, D_L19_001DED38 * t * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L19_003D5B78 */
