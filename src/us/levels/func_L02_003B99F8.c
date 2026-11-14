#include "common.h"

/* NTSC-U counterpart of func_L02_003BBC98 (src/levels/02_florana/L02_003BBA80.c) */
#include "vu0.h"

void func_L01_004AA7E8_003B99F8(s32, s32);
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18; } T_3BBAC0;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0xF]; u8 f30; u8 pad31[0x37]; T_3BBAC0 *p; } S_3BBAC0;
s32 func_00382380(void *, s32, s32);
void func_L01_0045F1E8_003B99F8(s32, s32);
void func_L01_004450F0_003B99F8(void *, s32, s32);

/* localdecomp:start func_L02_003B99F8 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L02_001D66B0_003B99F8[2];
extern f32 D_L02_001DDFF0;
extern f32 D_L02_001DDFF4;
__asm__(".extern D_L02_001DDFF0, 4");
__asm__(".extern D_L02_001DDFF4, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L02_003B99F8(u8 *self) {
    vu0_v4 a, b;
    f32 inv;

    if (func_L01_00444358(self, -1, 0) == 0) return;
    func_0039FE80(0, 0, self);
    func_L01_0044ED60(self, 0x1F, D_L02_001D66B0_003B99F8, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_L01_0044F1E8(self, 0x1EA2, 0);
    inv = 1.0f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    *(u128_t *)&a = 0;
    func_003886E8(&a, &a, inv);
    *(u128_t *)&b = 0;
    b.z = 0.116666675f;
    func_L02_003E0520(self, &a, &b, 0x14, 0, 0, 0.1f, 0.15f, D_L02_001DDFF4 * inv * *(f32 *)(self + 0x2C), 20.0f, 1.0f);
    func_003886E8(&a, &a, *(f32 *)(self + 0x2C));
    func_003888C8(&a, &a, self + 0xC0);
    vec_add_ab(&a, &a, self + 0x10);
    func_L01_0032FE90((u8 *)&a, 0, 0, 0, 0, 2, 5, 0, D_L02_001DDFF0 * inv * *(f32 *)(self + 0x2C), 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
    func_L01_0044EBF8(self, 1, 0.0f);
    func_003BD360(self);
}
/* localdecomp:end func_L02_003B99F8 */
