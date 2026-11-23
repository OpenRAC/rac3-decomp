#include "common.h"

/* localdecomp:start func_L03_003B2518 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern f32 D_L03_001DE970;
__asm__(".extern D_L03_001DE970, 4");
extern f32 D_L03_001DE974[];
__asm__(".extern D_L03_001DE974, 16");
extern f32 D_L03_001DE978[];
__asm__(".extern D_L03_001DE978, 16");
extern void func_L01_00450DE8(void *, void *, f32, f32, f32);

void func_L03_003B2518(u8 *a0) {
    u8 *t = D_L03_001DF99C + (*(s32 *)(*(u8 **)(a0 + 0x68) + 0x124) << 8);
    *(u128_t *)(a0 + 0xF0) = *(u128_t *)(t + 0xF0);
    func_L01_00450DE8(t, a0 + 0x10, D_L03_001DE970, D_L03_001DE974[0], D_L03_001DE978[0]);
}
/* localdecomp:end func_L03_003B2518 */
