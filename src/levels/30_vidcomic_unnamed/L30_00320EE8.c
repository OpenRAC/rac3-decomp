#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00320EE8);

/* localdecomp:start func_L30_00321070 */
void func_L30_00321070(void *arg0, f32 fparg0) {
    void *temp_a0;

    if (arg0 != 0) {
        temp_a0 = *(void **)((u8 *)arg0 + 0x68);
        if (temp_a0 != 0) {
            *(f32 *)((u8 *)temp_a0 + 0xF4) = fparg0;
        }
    }
}
/* localdecomp:end func_L30_00321070 */
