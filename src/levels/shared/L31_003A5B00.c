#include "common.h"

/* localdecomp:start func_L31_003A5B00 */
f32 func_L31_003A5B00(void *m, f32 *pos) {
    if (pos[0] > *(f32 *)((u8 *)m + 0x10)) {
        return 0.0f;
    }
    return 3.1415927f;
}
/* localdecomp:end func_L31_003A5B00 */

INCLUDE_ASM("asm/levels", func_L31_003A5B30);
