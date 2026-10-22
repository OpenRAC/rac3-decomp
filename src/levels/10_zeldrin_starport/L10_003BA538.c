#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003BA538);

/* localdecomp:start func_L10_003BA8E0 */
void func_L10_003BA8E0(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x20)) > 0) {
        *(s32 *)((u8 *)temp_v1 + 0x80) = (s32) (arg1 ^ 1);
    }
}
/* localdecomp:end func_L10_003BA8E0 */
