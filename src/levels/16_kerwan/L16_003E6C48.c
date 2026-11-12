#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L16_003E6C48);

INCLUDE_ASM("asm/levels", func_L16_003E6D40);

/* localdecomp:start func_L16_003E7280 */
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L16_001DFC40;
__asm__(".extern D_L16_001DFC40, 16");
extern s32 D_L16_001DF4D8;

void func_L16_003E7280(u8 *a0, u128_t *a1, u128_t *a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x68);
    *(s32 *)(p + 8) = D_L16_001DFC40 + D_L16_001DF4D8;
    *(u128_t *)(p + 0x20) = *a1;
    *(u128_t *)(p + 0x30) = *a2;
    *(f32 *)(p + 0xC) = func_0038CEA8(a1);
    *(s32 *)(p + 0x10) = a3;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L16_003E7280 */

/* localdecomp:start func_L16_003E7300 */
void func_L16_003E7300(u8 *a0, u128_t *a1, u128_t *a2, f32 f) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (1.0f < f) { *(f32 *)p = f; } else { *(f32 *)p = f; }
    vec_sub_ab(p + 0x20, a1, a0 + 0x10);
    *(u128_t *)(p + 0x30) = *a2;
}
/* localdecomp:end func_L16_003E7300 */
