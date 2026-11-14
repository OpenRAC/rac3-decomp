#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0035A470);

/* localdecomp:start func_L24_0035A550 */
void func_L24_0035A550(void *arg0, f32 fparg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    *(f32 *)((u8 *)temp_v0 + 0x1BC) = (f32) ((*(f32 *)((u8 *)temp_v0 + 0x1BC)) + fparg0);
    *(f32 *)((u8 *)temp_v0 + 0x1F4) = (f32) ((*(f32 *)((u8 *)temp_v0 + 0x1F4)) - fparg0);
    *(f32 *)((u8 *)temp_v0 + 0x1FC) = (f32) ((*(f32 *)((u8 *)temp_v0 + 0x1FC)) - fparg0);
}
/* localdecomp:end func_L24_0035A550 */

INCLUDE_ASM("asm/levels", func_L24_0035A580);

INCLUDE_ASM("asm/levels", func_L24_0035A908);
