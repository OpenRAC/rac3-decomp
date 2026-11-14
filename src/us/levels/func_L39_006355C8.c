#include "common.h"

/* NTSC-U counterpart of func_L39_00637E10 (src/levels/shared/L39_00637E10.c) */
/* localdecomp:start func_L39_006355C8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);

void func_L39_006355C8(u8 *a) {
    f32 f1;
    f32 f0;
    f32 f2;
    f32 g1;
    u128_t q;

    if (a[0x1A14] != 0) {
        if (*(s16 *)(*(u8 **)(*(u8 **)(a + 0x2530) + 0x50) + 0x86) == 0x21) {
            return;
        }
    }
    f1 = *(f32 *)(a + 0x23B8);
    f0 = *(f32 *)(a + 0x3EC);
    q = *(u128_t *)(a + 0x23C0);
    *(f32 *)(a + 0xFD0) = f1;
    *(f32 *)(a + 0xFD4) = f0;
    *(u128_t *)(a + 0xFC0) = q;
    func_L39_00630AC0(a, 0, 0.09f, 0.25f, 0.3781546652317047f);
    g1 = *(f32 *)(a + 0xFD8);
    f2 = *(f32 *)(a + 0xFD4);
    *(f32 *)(a + 0x41C) = g1;
    *(f32 *)(a + 0x3EC) = f2;
    if (g1 == 0.0f) {
        *(s32 *)(a + 0x3FC) = *(s32 *)(a + 0x3FC) + 1;
    } else {
        *(s32 *)(a + 0x3FC) = 0;
    }
}
/* localdecomp:end func_L39_006355C8 */
