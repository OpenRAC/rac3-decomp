#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_00307350);

typedef struct { f32 x, y, z, w; } V_3074D8 __attribute__((aligned(16)));

/* localdecomp:start func_L19_003074D8 */
extern f32 D_L19_001E8E68[];
extern s32 func_003D3CB0(V_3074D8 *, V_3074D8 *, s32, s32, s32);

f32 func_L19_003074D8(V_3074D8 *p) {
    V_3074D8 a;
    V_3074D8 b;

    a = *p;
    b = *p;
    a.z = 400.0f;
    b.z = 90.0f;
    if (func_003D3CB0(&a, &b, 18, 0, 0) != 0)
        return D_L19_001E8E68[0];
    return 90.0f;
}
/* localdecomp:end func_L19_003074D8 */

INCLUDE_ASM("asm/levels", func_L19_00307548);
