#include "common.h"

/* localdecomp:start func_L16_003E8068 */
#include "vu0.h"
/* from func_L14_00354538 (same effect-spawn shape) */
typedef int u128_t_3E8068 __attribute__((mode(TI)));
__asm__(".extern D_L16_001DF600, 4");
__asm__(".extern D_L16_001DF604, 4");
__asm__(".extern D_L16_001DF608, 4");
extern f32 D_L16_001DF600;
extern f32 D_L16_001DF604;
extern f32 D_L16_001DF608;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L16_003E8068(u8 *a0) {
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 b;
    f32 t;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        *(u128_t_3E8068 *)&a = 0;
        a.y = -1.0f;
        a.z = -0.5f;
        func_0038CF68(&a, &a, 0.0800000057f);
        func_0038D000(&a, &a, a0 + 0xC0);
        func_L01_00451FE0(a0, 0x7F, &a, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_003A52A0(0, 0, a0);
        func_L01_00452460(a0, 0x1D25, 0);
        t = 7.61092901f;
        *(u128_t_3E8068 *)&b = 0;
        b.y = D_L16_001DF600;
        b.z = D_L16_001DF604;
        c = b;
        func_0038CE20(&c, &c, t);
        *(u128_t_3E8068 *)&b = 0;
        b.z = -0.14000002f;
        func_L02_003E2E38(a0, &c, 0.1f, &b, 0x14, 0, 0.18f, 1.5f, 20.0f, 1.0f, 0);
        func_0038CE20(&c, &c, *(f32 *)(a0 + 0x2C));
        func_0038D000(&c, &c, a0 + 0xC0);
        vec_add_ab(&c, &c, a0 + 0x10);
        func_L01_003303B8(&c, 0, 0, 0, 0, 2, 5, 0, D_L16_001DF608 * *(f32 *)(a0 + 0x2C) * t, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L16_003E8068 */
