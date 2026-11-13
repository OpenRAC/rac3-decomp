#include "common.h"

/* localdecomp:start func_L03_003B97E0 */
extern void func_L01_0040A8C0(u128_3B9760 *a, u128_3B9760 *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 f0, f32 f1, f32 f2);
__asm__(".extern D_L03_001DEAA8, 4");
extern u32 D_L03_001DEAA8;

void func_L03_003B97E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u128_3B9760 v;
    u128_3B9760 w;
    if (*(s32 *)(s + 0x28) == 0) {
        v = *(u128_3B9760 *)(a0 + 0x10);
        func_L03_003B9760((u8 *)&v, 0x80288020);
    }
    v = *(u128_3B9760 *)(s + 0x10);
    func_L03_003B9760((u8 *)&v, 0x80288020);
    v = *(u128_3B9760 *)(s + 0x10);
    w = *(u128_3B9760 *)(a0 + 0x10);
    func_L01_0040A8C0(&v, &w, 0x1C, 1, D_L03_001DEAA8, D_L03_001DEAA8, D_L03_001DEAA8, D_L03_001DEAA8, 0.4f, 1.0f, 0.0f);
}
/* localdecomp:end func_L03_003B97E0 */
