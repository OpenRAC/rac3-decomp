#include "common.h"

/* localdecomp:start func_L39_005DC338 */
typedef struct { f32 f[4]; } V_005DC338 __attribute__((aligned(16)));
typedef struct { V_005DC338 lo, hi; } S_005DC338;
extern S_005DC338 D_L39_0049A020[];
extern s32 D_L39_002412DC;

void func_L39_005DC338(f32 *a0, f32 *a1, f32 *a2) {
    V_005DC338 lo, hi;
    s32 i = D_L39_002412DC % 10;
    if (i >= 7) i = 0;
    lo = *(V_005DC338 *)((u8 *)D_L39_0049A020 + i * 32);
    hi = ((V_005DC338 *)((u8 *)D_L39_0049A020 + i * 32))[1];
    *a1 = (a0[0] - lo.f[0]) / (hi.f[0] - lo.f[0]);
    *a2 = (a0[1] - lo.f[1]) / (hi.f[1] - lo.f[1]);
    *a1 = *a1 * 0.8f;
    *a2 = (0.35f - *a2 * 0.7f) + 0.35f;
    *a1 = *a1 + 0.0999999940f;
    *a2 = *a2 + 0.169999987f;
    if (*a1 > 1.0f) *a1 = 1.0f;
    if (*a1 < 0.0f) *a1 = 0.0f;
    if (*a2 > 1.0f) *a2 = 1.0f;
    if (*a2 < 0.0f) *a2 = 0.0f;
}
/* localdecomp:end func_L39_005DC338 */
