#include "common.h"

/* NTSC-U counterpart of func_L01_003CCC20 (src/levels/shared/L01_003C8DE8.c): EXACT (check_native MATCH) with the PAL line's flags
 * (-O2 -G8 -fopt-stack -mno-check-zero-division, @ps2as). Levers: the three w stores as a CHAIN (like the matched func_L23_0032AA28):
 * *(f32*)(obj+0xCC) = *(f32*)(obj+0xDC) = *(f32*)(obj+0xEC) = 0.0f gives retail's mtc1 zero,f0 + three swc1; D_L01_001D66B0_003CB388 as
 * `extern s32 X; .extern X,16` + &X (la macro, no hoisted lui); the vec copy of a2 right after the vec copy of a1 and the s+0x20 store
 * before s+0x24.
 * Loop 3 is retail's UP-counter because `i` is NOT re-initialised: it carries on from loop 2 (i == 4 there), `for (j = 0; i < 7; j++, i++)`.
 * loop.c optimises loop 3 before loop 2, so i's initial value is unknown to it: no iteration count, no reversal to a down-counter, i stays
 * the counter (slti 7) and only the pointer givs are strength-reduced. `i = 4` in the header (tried at every earlier effort level) makes
 * the start constant and gcc reverses the loop. j++ before i++ gives retail's order of the pointer increments (s5 first).
 * Parameters are declared (s32 a0, u8 *a1, u8 *a2, f32 a4, s32 a3): same ABI as (.., s32 a3, f32 a4) (f32 -> $f12, ints a0..a3), only the
 * order of the entry copies changes (retail: mov.s f21,f12 before move s7,a3; callers' prototype order is irrelevant to the bytes). */
/* localdecomp:start func_L01_003CB388 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_001DEFD0_sda;
extern f32 D_001DEFD4_sda;
extern f32 D_001DEFD8_sda;
extern f32 D_001DEFDC_sda;
extern s32 D_001DEFE0_sda;
extern f32 D_001DF000_sda;
extern f32 D_001DF020_sda;
extern s32 D_001DF030_sda;
extern s32 D_001DF040_sda;
__asm__(".extern D_001DF040_sda, 4");
__asm__(".extern D_001DEFD0_sda, 4");
__asm__(".extern D_001DEFD4_sda, 4");
__asm__(".extern D_001DEFD8_sda, 4");
__asm__(".extern D_001DEFDC_sda, 4");
__asm__(".extern D_001DEFE0_sda, 4");
__asm__(".extern D_001DF000_sda, 4");
__asm__(".extern D_001DF020_sda, 4");
__asm__(".extern D_001DF030_sda, 4");
extern s32 D_L01_001D66B0_003CB388;
__asm__(".extern D_L01_001D66B0_003CB388, 16");
extern void func_003BFC18(void *, void *, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_004708F8(f32, f32, f32, f32, void *, void *, s32, s32, s32, s32, s32);
extern u8 *func_L01_00467DA8(f32, f32, f32, void *, s32, s32, s32, s32, void *, s32);
extern u8 *func_L01_0046D570(f32, f32, void *, s32, s32, s32, s32, void *, s32, s32, s32, s32);

u8 *func_L01_003CB388(s32 a0, u8 *a1, u8 *a2, f32 a4, s32 a3) {
    f32 tmp10[4] __attribute__((aligned(16)));
    f32 tmp20[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    u8 *obj;
    u8 *s;
    s32 i, j;

    func_003BFC18(a1, tmp10, 1);
    obj = func_003BCFB0(0x1B33, 0x80);
    if (obj != 0) {
        s = *(u8 **)(obj + 0x68);
        *(s32 *)(s + 0x10) = 0x50;
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0xFF;
        obj[0x20] = 0;
        *(u128_t *)(obj + 0x10) = *(u128_t *)a1;
        *(u128_t *)s = *(u128_t *)a2;
        *(f32 *)(s + 0x1C) = a4;
        *(s32 *)(s + 0x18) = 0;
        *(s32 *)(s + 0x14) = 0;
        func_00388830(tmp20, a2, 1.0f);
        *(u128_t *)(obj + 0xC0) = *(u128_t *)tmp20;
        func_00388758(obj + 0xD0, obj + 0xC0, tmp10);
        func_00388830(obj + 0xD0, obj + 0xD0, 1.0f);
        func_00388758(obj + 0xE0, obj + 0xD0, obj + 0xC0);
        *(f32 *)(obj + 0xCC) = *(f32 *)(obj + 0xDC) = *(f32 *)(obj + 0xEC) = 0.0f;
        *(s32 *)(s + 0x20) = a0;
        *(s32 *)(s + 0x24) = a3;
        for (i = 0; i < 10; i++) {
            func_0037E2F0(vel, 0.083333336f, 0.16666667f);
            func_L01_004708F8(D_001DEFD0_sda, D_001DEFD4_sda, D_001DEFD8_sda, D_001DEFDC_sda, a1, vel, func_0037E208(10, 25), D_001DEFE0_sda, (&D_001DEFE0_sda)[1], 0, 0);
        }
        for (i = 0; i < 4; i++) {
            func_L01_00467DA8((&D_001DF000_sda)[i], (&D_001DF020_sda)[i], 0.0f, a1, 0xE, (&D_001DEFE0_sda)[i], 2, 1, &D_L01_001D66B0_003CB388, 1);
        }
        for (j = 0; i < 7; j++, i++) {
            func_L01_0046D570((&D_001DF000_sda)[i], (&D_001DF020_sda)[i], a1, 0x14, (&D_001DEFE0_sda)[i], 2, 2, &D_L01_001D66B0_003CB388, 0, (&D_001DF040_sda)[j], 6, 1);
        }
    }
    return obj;
}
/* localdecomp:end func_L01_003CB388 */
