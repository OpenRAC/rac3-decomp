#include "common.h"

/* NTSC-U counterpart of func_L13_003AEEB0 (src/levels/shared/L13_003AEB48.c): 0.02 -> 0.0166667 */
#include "vu0.h"
extern f32 D_L13_001DE6DC_003AD0C8, D_L13_001DE6E0_003AD0C8, D_L13_001DE71C;
extern void func_L13_003AD0C8(u8 *, u8 *, f32);
extern void func_L13_003AD0C8(u8 *, u8 *, f32);

/* localdecomp:start func_L13_003AD0C8 */
__asm__(".extern D_L13_001DE718, 4");
__asm__(".extern D_L13_001DE71C, 4");
__asm__(".extern D_L13_001DE714, 4");
__asm__(".extern D_L13_001DE690_003AD0C8, 4");
extern f32 D_L13_001DE718;
extern f32 D_L13_001DE71C;
extern f32 D_L13_001DE714;
extern f32 D_L13_001DE690_003AD0C8;
extern f32 func_00388730(void *, void *);

void func_L13_003AD0C8(u8 *self, u8 *a1, f32 f) {
    f32 g;
    f32 h;
    f32 t;
    f32 u;

    f32 q0 = *(f32 *)(self + 0xF0);
    g = -(D_L13_001DE714 * 0.017453292f);
    *(f32 *)(self + 0xF0) = q0 - f * D_L13_001DE718 * D_L13_001DE71C;
    t = (func_00388730(a1, self + 0xD0) / (D_L13_001DE690_003AD0C8 * 0.0166666675f) < 1.0f)
            ? g * (func_00388730(a1, self + 0xD0) / (D_L13_001DE690_003AD0C8 * 0.0166666675f))
            : g;
    h = D_L13_001DE714 * 0.017453292f;
    *(f32 *)(self + 0xF0) = *(f32 *)(self + 0xF0) * (1.0f - D_L13_001DE71C) + t * D_L13_001DE71C;
    u = (func_00388730(a1, self + 0xC0) / (D_L13_001DE690_003AD0C8 * 0.0166666675f) < 1.0f)
            ? h * (func_00388730(a1, self + 0xC0) / (D_L13_001DE690_003AD0C8 * 0.0166666675f))
            : h;
    *(f32 *)(self + 0xF4) = *(f32 *)(self + 0xF4) * (1.0f - D_L13_001DE71C) + u * D_L13_001DE71C;
}
/* localdecomp:end func_L13_003AD0C8 */
