#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3A7DE8;

/* localdecomp:start func_L30_003A98C8 */
extern s32 D_001A71A0[];
extern f32 D_L30_001E9020[];
extern s32 func_003D3CB0(V_3A7DE8 *, V_3A7DE8 *, s32, s32, s32);
f32 func_L30_003A98C8(V_3A7DE8 *p, f32 h) {
    V_3A7DE8 t;
    f32 z;
    t = *p;
    t.z = t.z - h;
    z = p->z;
    if (func_003D3CB0(p, &t, 0, D_001A71A0[0], 0)) {
        z = D_L30_001E9020[2];
    }
    return z;
}
/* localdecomp:end func_L30_003A98C8 */

INCLUDE_ASM("asm/levels", func_L30_003A9928);

/* localdecomp:start func_L30_003A9B00 */
f32 func_L30_003A9B00(f32 a, f32 b, f32 c) {
    return c * -0.5f + c * (1.0f - b) + a;
}
/* localdecomp:end func_L30_003A9B00 */
