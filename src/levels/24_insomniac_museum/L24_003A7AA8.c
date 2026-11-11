#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003A7AA8);

INCLUDE_ASM("asm/levels", func_L24_003A7CE8);

INCLUDE_ASM("asm/levels", func_L24_003A7F58);

INCLUDE_ASM("asm/levels", func_L24_003A7FD8);

INCLUDE_ASM("asm/levels", func_L24_003A8118);

/* localdecomp:start func_L24_003A8400 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_L24_003F6B78(f32);
extern void func_L24_003F6D98(void *, f32);
extern f32 func_L24_003F6B60(f32);
extern void func_L24_003F4C18(void *, s32, s32, s32, s32, f32);

void func_L24_003A8400(u8 *a0, s32 a1, s32 a2, s32 a3, f32 f12) {
    f32 m[16] __attribute__((aligned(16)));
    f32 c = func_L24_003F6B78((f32)(a1 - 0xB4) * 0.017453292f) * 0.1f;
    f32 s;
    f12 = f12 * (3.0f - c);
    func_L24_003F6D98(m, c + 2.0f);
    m[10] = f12;
    *(u128_t *)&m[12] = *(u128_t *)(a0 + 0x10);
    s = func_L24_003F6B60((f32)(a1 % 0x168) * 0.017453292f);
    func_L24_003F4C18(m, a3, ((s32)(s * 16.0f + 32.0f) << 24) | a2, 5, 1, (f32)a1 / 360.0f);
}
/* localdecomp:end func_L24_003A8400 */

/* localdecomp:start func_L24_003A8530 */
extern void func_L24_003A8400(void *, s32, s32, s32, f32);

void func_L24_003A8530(u8 *a0, f32 f12) {
    s32 t;
    func_L24_003A8400(a0, *(u16 *)(a0 + 0x96), 0x401080, 0x22, f12);
    t = *(u16 *)(a0 + 0x96);
    t += 0x28;
    func_L24_003A8400(a0, t >= 0x168 ? t - 0x168 : t, 0x802040, 0x27, f12);
    t = *(u16 *)(a0 + 0x96);
    t += 0xA0;
    func_L24_003A8400(a0, t >= 0x168 ? t - 0x168 : t, 0x40FF, 0x28, f12);
}
/* localdecomp:end func_L24_003A8530 */
