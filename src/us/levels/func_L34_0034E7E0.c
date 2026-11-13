#include "common.h"

/* NTSC-U counterpart of func_L34_0034F4B8 (src/levels/34_vidcomic_3/L34_0034EBE0.c) */
#include "vu0.h"

/* localdecomp:start func_L34_0034E7E0 */
typedef int u128_t __attribute__((mode(TI)));

void func_L34_0034E7E0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    *(u128_t *)(p + 0x50) = *(u128_t *)(a0 + 0x10);
    *(s32 *)(p + 0x84) = 0;
    *(s32 *)(p + 0x88) = 0;
    *(f32 *)(a0 + 0xF8) = -1.57079637050628662109375f;
}
/* localdecomp:end func_L34_0034E7E0 */
