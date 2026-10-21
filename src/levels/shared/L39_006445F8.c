#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006445F8);

/* localdecomp:start func_L39_00644820 */
f32 func_L39_00644820(void *a0, f32 *a, f32 *b) {
    f32 s = 0.0f;
    s32 i, j;

    for (i = 0; i < 3; i++) {
        f32 *pa = a + i * 4;
        f32 *pb = b + i * 4;
        for (j = 0; j < 3; j++) {
            s += pa[j] - pb[j];
        }
    }
    return s;
}
/* localdecomp:end func_L39_00644820 */

INCLUDE_ASM("asm/levels", func_L39_00644878);
