#include "common.h"

/* NTSC-U counterpart of func_L19_00345E20 (src/levels/shared/L19_00345E20.c) */

/* localdecomp:start func_L19_00345188 */
#include "vu0.h"
extern f32 D_L19_001DD2E8;
__asm__(".extern D_L19_001DD2E8, 4");
extern f32 func_00389380(f32, f32);
extern void func_003BD360(void *);

void func_L19_00345188(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * D_L19_001DD2E8;
    *(f32 *)(s + 8) = *(f32 *)(s + 8) - 0.004166667f;
    vec_add_ba(a0 + 0x10, a0 + 0x10, s);
    vec_add_ab(a0 + 0xF0, a0 + 0xF0, s + 0x10);
    *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), *(f32 *)(s + 0x10));
    *(f32 *)(a0 + 0xF4) = func_00389380(*(f32 *)(a0 + 0xF4), *(f32 *)(s + 0x14));
    *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), *(f32 *)(s + 0x18));
    a0[0xBC]--;
    if (a0[0xBC] == 0) {
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L19_00345188 */
