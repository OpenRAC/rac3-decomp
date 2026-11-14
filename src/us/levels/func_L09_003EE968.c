#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003EE968 */
typedef int u128_t_3DC0B0 __attribute__((mode(TI)));
extern u8 D_L09_001D66B0_003EE968[8];
__asm__(".extern D_L09_001D66B0_003EE968, 16");
extern f32 D_001DF568_sda;
__asm__(".extern D_001DF568_sda, 4");
extern f32 D_001DF56C_sda;
__asm__(".extern D_001DF56C_sda, 4");
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

void func_L09_003EE968(u8 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0x1F, D_L09_001D66B0_003EE968, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044F1E8(a0, 0x1EE0, 0);
        *(u128_t_3DC0B0 *)&b = 0;
        b.z = D_001DF568_sda;
        a = b;
        func_003886E8(&a, &a, 8.448086738586426f);
        *(u128_t_3DC0B0 *)&b = 0;
        b.z = -0.11666667461395264f;
        func_L02_003E0520(a0, &a, 0.1f, &b, 0x14, 0, 0, 0.15f, *(f32 *)(a0 + 0x2C) * 12.672130584716797f, 20.0f, 1.0f);
        func_003886E8(&a, &a, *(f32 *)(a0 + 0x2C));
        func_003888C8(&a, &a, a0 + 0xC0);
        vec_add_ab(&a, &a, a0 + 0x10);
        func_L01_0032FE90(&a, 0, 0, 0, 0, 2, 5, 0, D_001DF56C_sda * 8.448086738586426f * *(f32 *)(a0 + 0x2C), 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFF8A, 0xBD66, 0, 0, 0, 0, 0xFF8A, 0xBD66, 0, 0);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L09_003EE968 */
