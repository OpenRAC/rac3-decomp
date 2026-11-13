#include "common.h"

/* NTSC-U counterpart of func_L21_003AA258 (src/levels/21_obani_draco/L21_003A8050.c) */
/* localdecomp:start func_L21_003A8808 */
void func_L21_003A8808(u8 *arg0, s32 arg1) {
    u8 *v = *(u8 **)(arg0 + 0x68);
    if (arg1) {
        *(f32 *)(v + 0xEC) = 0.25f;
        *(f32 *)(v + 0xF0) = 0.016666668f;
    } else {
        *(s32 *)(v + 0xEC) = 0;
        *(s32 *)(v + 0xF0) = 0;
    }
}
/* localdecomp:end func_L21_003A8808 */
