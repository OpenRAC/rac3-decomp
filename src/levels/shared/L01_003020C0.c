#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_003020C0 */
extern void func_003C5278(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 D_001A4CC0[];
s32 func_L01_003020C0(u8 *m) {
    u128_t v;
    v = *(u128_t *)(m + 16);
    func_003C5278(m + 16, &v, &v, -0.5f);
    return func_003D3CB0(&v, D_001A4CC0, 18, 0, 0) == 0;
}
/* localdecomp:end func_L01_003020C0 */
