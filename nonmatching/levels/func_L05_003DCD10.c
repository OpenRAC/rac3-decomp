/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_003DA880, the NTSC-U twin of func_L05_003DCD10, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L05_003DCBF0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_003DCD10 (src/levels/shared/L05_003DCBF0.c) */
#include "vu0.h"

/* localdecomp:start func_L05_003DA880 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L05_001D66B0[2];
__asm__(".extern D_L05_001D66B0, 16");
extern f32 D_L05_001DF210_sda;
extern f32 D_L05_001DF214_sda;
__asm__(".extern D_L05_001DF210_sda, 4");
__asm__(".extern D_L05_001DF214_sda, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L05_003DA760(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L05_003DA880(u8 *self) {
    vu0_v4 a, b;
    f32 r;

    if (func_L01_00444358(self, -1, 0) == 0) return;
    func_0039FE80(0, 0, self);
    func_L01_0044ED60(self, 0x7F, D_L05_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_L05_003DA760(self, 0x1EE3, 0);
    r = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    *(u128_t *)&b = 0;
    b.z = D_L05_001DF210_sda;
    a = b;
    func_003886E8(&a, &a, r);
    *(u128_t *)&b = 0;
    b.z = -0.116666675f;
    func_L02_003E0520(self, &a, &b, 0x14, 0, 0, 0.1f, 0.15f, r * 0.5f, 20.0f, 1.0f);
    func_003886E8(&a, &a, *(f32 *)(self + 0x2C));
    func_003888C8(&a, &a, self + 0xC0);
    vec_add_ab(&a, &a, self + 0x10);
    func_L01_0032FE90((u8 *)&a, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF214_sda * r, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
    func_L01_0044EBF8(self, 1, 0.0f);
    func_003BD360(self);
}
/* localdecomp:end func_L05_003DA880 */
