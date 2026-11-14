#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A51C8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A51C8;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 D_L31_001E91A0[];

f32 func_L31_003A51C8(V_003A51C8 *pos, s32 a1, void *a2, f32 dz) {
    V_003A51C8 to;
    V_003A51C8 from;

    from = *pos;
    to = from;
    from.z += dz;
    to.z = 0.01f;
    if (func_003D3CB0(&from, &to, a1, a2, 0) != 0) {
        return D_L31_001E91A0[2];
    }
    return 0.0f;
}
/* localdecomp:end func_L31_003A51C8 */

INCLUDE_ASM("asm/levels", func_L31_003A5238);
