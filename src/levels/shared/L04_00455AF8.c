#include "common.h"

/* localdecomp:start func_L04_00455AF8 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern f32 D_L04_001E95A0[];
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, s32 a3, s32 t0);
f32 func_L04_00455AF8(u128_t *pos) {
    Vec4 a;
    Vec4 b;
    b.q = *pos; a.q = *pos; b.f[2] += 64.01f; a.f[2] -= 0.5f;
    if (func_003D3CB0(&b, &a, 18, 0, 0) != 0) {
        return D_L04_001E95A0[2];
    }
    return b.f[2];
}
/* localdecomp:end func_L04_00455AF8 */
