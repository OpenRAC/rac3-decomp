#include "common.h"

/* localdecomp:start func_L27_0039F6A8 */
void func_L22_003B6EE8(s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L01_00456230(void *, s32);

void func_L27_0039F6A8(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    if ((arg0 != 0) && (temp_v0 != 0) && ((*(s32 *)((u8 *)temp_v0 + 0x48C)) != 0) && ((*(u8 *)((u8 *)arg0 + 0x95)) != 6)) {
        func_L22_003B6EE8((s32) arg0, 0);
        func_L01_00456230(arg0, 0);
        func_L01_004450F0(arg0, 0x20, 6);
    }
}
/* localdecomp:end func_L27_0039F6A8 */

INCLUDE_ASM("asm/levels", func_L27_0039F718);
