#include "common.h"

/* NTSC-U counterpart of func_L07_003AFC10 (src/levels/07_annihilation_nation/L07_003AF398.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003AE398 */
extern void func_00388550(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003D41E0(void *, s32, s32, s32, s32, f32);

void func_L07_003AE398(u8 *a0) {
    f32 m[16] __attribute__((aligned(16)));
    u8 *d;

    d = *(u8 **)(a0 + 0x68);
    *(f32 *)(d + 0xE0) += 0.055f;
    if (*(f32 *)(d + 0xE0) >= 7.0f) {
        *(f32 *)(d + 0xE0) -= 7.0f;
    }
    func_00388550(m, a0 + 0xC0, 0x30);
    *(u128_t *)&m[12] = *(u128_t *)(a0 + 0x10);
    func_003886E8(&m[0], &m[0], 2.2f);
    func_003886E8(&m[4], &m[4], 2.2f);
    func_003886E8(&m[8], &m[8], 2.2f);
    func_003D41E0(m, 0x15, 0x20FF8080, 8, 1, *(f32 *)(d + 0xE0));
    func_003D41E0(m, 0x2B, 0x20FF8080, 8, 1, *(f32 *)(d + 0xE0));
}
/* localdecomp:end func_L07_003AE398 */
