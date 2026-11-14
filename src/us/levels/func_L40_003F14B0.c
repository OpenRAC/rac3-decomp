#include "common.h"

/* NTSC-U counterpart of func_L40_003F1958 (src/levels/shared/L40_003F1958.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L40_003F14B0 */
extern f32 D_001DB760_sda;
__asm__(".extern D_001DB760_sda, 4");
extern f32 D_001DB764_sda;
__asm__(".extern D_001DB764_sda, 4");
extern void func_L01_00445168(void *, void *, f32, f32, f32, f32);
extern s32 func_L40_003F1460(void *, void *);

void func_L40_003F14B0(u8 *a0) {
    u128_t v;
    f32 saved;
    u8 *d;
    f32 x;

    saved = *(f32 *)(a0 + 0x18);
    d = *(u8 **)(a0 + 0x68);
    x = D_001DB760_sda * 0.000277777785f;
    func_L01_00445168(a0 + 0x18, d + 0x268, *(f32 *)(d + 0x2E8), x, x, D_001DB764_sda * 0.0166666675f);
    v = *(u128_t *)(a0 + 0x10);
    if (func_L40_003F1460(a0, &v) == 0) {
        *(f32 *)(a0 + 0x18) = saved;
    }
}
/* localdecomp:end func_L40_003F14B0 */
