#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003DCD10 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L05_001D66B0[2];
__asm__(".extern D_L05_001D66B0, 16");
extern f32 D_L05_001DF1D0_sda;
extern f32 D_L05_001DF1D4_sda;
__asm__(".extern D_L05_001DF1D0_sda, 4");
__asm__(".extern D_L05_001DF1D4_sda, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L05_003DCBF0(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L05_003DCD10(u8 *self) {
    vu0_v4 a, b;
    f32 r;

    if (func_L01_00447490(self, -1, 0) == 0) return;
    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, 0x7F, D_L05_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_L05_003DCBF0(self, 0x1EE3, 0);
    r = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    *(u128_t *)&b = 0;
    b.z = D_L05_001DF1D0_sda;
    a = b;
    func_0038CE20(&a, &a, r);
    *(u128_t *)&b = 0;
    b.z = -0.14000001549720764f;
    func_L02_003E2E38(self, &a, &b, 0x14, 0, 0, 0.1f, 0.18f, r * 0.5f, 20.0f, 1.0f);
    func_0038CE20(&a, &a, *(f32 *)(self + 0x2C));
    func_0038D000(&a, &a, self + 0xC0);
    vec_add_ab(&a, &a, self + 0x10);
    func_L01_003303B8((u8 *)&a, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF1D4_sda * r, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
/* localdecomp:end func_L05_003DCD10 */
