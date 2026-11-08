#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 pad[6]; s32 f18; s32 f1C; } L24Flags;

/* localdecomp:start func_L24_0042C1C8 */
extern L24Flags D_L24_001E8F40;
extern s32 func_003D3CB0(void *a, void *b, s32 c, void *d, s32 e);

s32 func_L24_0042C1C8(void *a0, void *a1, s32 a2, f32 f12, f32 f13) {
    f32 v1[4] __attribute__((aligned(16)));
    f32 v2[4] __attribute__((aligned(16)));
    s32 r;
    *(u128_t *)v1 = *(u128_t *)a0;
    v1[2] += f12;
    *(u128_t *)v2 = *(u128_t *)a0;
    v2[2] -= f13;
    if (v2[2] < 0.0f)
        v2[2] = 0.0f;
    r = func_003D3CB0(v1, v2, 0x22, a1, 0);
    if (D_L24_001E8F40.f1C <= -1)
        r = 0;
    if (a2 != 0 && D_L24_001E8F40.f18 != 0)
        r = 0;
    return r;
}
/* localdecomp:end func_L24_0042C1C8 */
