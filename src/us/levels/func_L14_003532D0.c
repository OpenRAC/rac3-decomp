#include "common.h"

/* NTSC-U counterpart of func_L14_003542F0 (src/levels/14_koros/L14_003542F0.c) */
#include "vu0.h"

typedef struct {
    u8 pad_00[0xAA];
    s16 f_AA;
} S_L14_00354B90;

/* localdecomp:start func_L14_003532D0 */
typedef int u128_t_3542F0 __attribute__((mode(TI)));
extern u8 D_L14_001D66B0_003532D0;
extern s32 D_L14_001D67B8_003532D0;
__asm__(".extern D_L14_001DD650, 4");
__asm__(".extern D_L14_001DD654, 4");
__asm__(".extern D_L14_001DD658, 4");
extern f32 D_L14_001DD650;
extern f32 D_L14_001DD654;
extern f32 D_L14_001DD658;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);
void func_L14_003532D0(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;
    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_0039FE80(0, 0, a0);
        func_L01_0044ED60(a0, 0x7F, &D_L14_001D66B0_003532D0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = *(f32 *)(a0 + 0x2C) / D_L14_001DD658;
        *(u128_t_3542F0 *)&a = 0;
        a.z = D_L14_001DD650 * t;
        b = a;
        *(u128_t_3542F0 *)&a = 0;
        a.z = 0.116666675f;
        func_L02_003E0520(a0, &b, 0.1f, &a, 0x14, 3, 0.15f, 2.5f, 20.0f, 1.0f, 0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_0032FE90(&b, 0, 0, 0, 0, 2, 5, 0, D_L14_001DD654 * t, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        D_L14_001D67B8_003532D0 = D_L14_001D67B8_003532D0 + 1;
        if (D_L14_001D67B8_003532D0 >= 100) {
            func_L01_00456960(0x11);
        }
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L14_003532D0 */
