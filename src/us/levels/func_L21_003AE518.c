#include "common.h"

/* NTSC-U counterpart of func_L21_003B0068 (src/levels/21_obani_draco/L21_003AEB70.c) */
/* localdecomp:start func_L21_003AE518 */
void func_L21_003AE518(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    if (arg1 != 0) {
        *(f32 *)(p + 0xEC) = 0.25f;
        *(f32 *)(p + 0xF0) = 0.016666668f;
    } else {
        *(s32 *)(p + 0xEC) = 0;
        *(s32 *)(p + 0xF0) = 0;
    }
}
/* localdecomp:end func_L21_003AE518 */
