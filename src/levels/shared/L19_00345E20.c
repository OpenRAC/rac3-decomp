#include "common.h"

/* localdecomp:start func_L19_00345E20 */
#include "vu0.h"
extern f32 D_L19_001DD2A8;
__asm__(".extern D_L19_001DD2A8, 4");
extern f32 func_0038DAB8(f32, f32);
extern void func_003C2880(void *);

void func_L19_00345E20(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * D_L19_001DD2A8;
    *(f32 *)(s + 8) = *(f32 *)(s + 8) - 0.006f;
    vec_add_ba(a0 + 0x10, a0 + 0x10, s);
    vec_add_ab(a0 + 0xF0, a0 + 0xF0, s + 0x10);
    *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), *(f32 *)(s + 0x10));
    *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), *(f32 *)(s + 0x14));
    *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), *(f32 *)(s + 0x18));
    a0[0xBC]--;
    if (a0[0xBC] == 0) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L19_00345E20 */
