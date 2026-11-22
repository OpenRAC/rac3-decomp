#include "common.h"

/* localdecomp:start func_L22_003E8060 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L22_003E7FC8(u8 *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L02_00426140(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
extern u8 D_L22_001D66B0[8];
__asm__(".extern D_L22_001D66B0, 16");

void func_L22_003E8060(u8 *a0, s32 a1, s16 a2, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3) {
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 *pv;
    func_0039FE80(0, 0, a0);
    func_L01_0044ED60(a0, a1, D_L22_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (a3 != 0) {
        func_L22_003E7FC8(a0, a3);
    }
    *(u128_t *)&v = *(u128_t *)(a0 + 16);
    *(u128_t *)&w = *(u128_t *)(a0 + 192 + a2 * 16);
    pv = &v;
    func_00388830(&w, &w, *(f32 *)(a0 + 44) / *(f32 *)(*(u8 **)(a0 + 36) + 36) * f1);
    v.z += *(f32 *)(a0 + 44) / *(f32 *)(*(u8 **)(a0 + 36) + 36) * f2;
    vec_add_ab(pv, pv, &w);
    func_L02_00426140(a0, pv, 0.5f, 20, 0, D_L22_001D66B0, 20.0f, 0.3f, 0.6f, a4, 0, 90);
    func_L02_003E0520(a0, pv, 1.0f, D_L22_001D66B0, 15, 0, 1, 0.041666668f, 2.5f, 5.0f, 1.0f);
    func_L01_0032FE90(pv, *(f32 *)(a0 + 44) / *(f32 *)(*(u8 **)(a0 + 36) + 36) * f3, 1, 15, 0, 0, 3, 5, 0, 0.0f, 0.0f, 0.0f,
        1, 1, 1, 0, 0, 1, 0x1000000, 0, 0x20408F, 0x5080, 0x3060, 0x202060, 0, 0, 0x7F2080FF, 0x280000FF, 0x5070, 0);
    func_L01_0044EBF8(a0, 1, 0.0f);
    func_003BD360(a0);
}
/* localdecomp:end func_L22_003E8060 */
