#include "common.h"

/* localdecomp:start func_L03_003B1D38 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern f32 D_L03_001DE960;
__asm__(".extern D_L03_001DE960, 4");
extern f32 D_L03_001DE964[];
__asm__(".extern D_L03_001DE964, 16");
extern f32 D_L03_001DE968[];
__asm__(".extern D_L03_001DE968, 16");
extern void func_L01_00450DE8(void *, void *, f32, f32, f32);

void func_L03_003B1D38(u8 *a0) {
    u8 *t = D_L03_001DF99C + (*(s32 *)(*(u8 **)(a0 + 0x68) + 0x290) << 8);
    *(u128_t *)(a0 + 0xF0) = *(u128_t *)(t + 0xF0);
    func_L01_00450DE8(t, a0 + 0x10, D_L03_001DE960, D_L03_001DE964[0], D_L03_001DE968[0]);
}
/* localdecomp:end func_L03_003B1D38 */
