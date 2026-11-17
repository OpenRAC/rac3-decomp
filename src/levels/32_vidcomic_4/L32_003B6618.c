#include "common.h"

/* localdecomp:start func_L32_003B6618 */
extern s32 func_00382498(s32, s32);

s32 func_L32_003B6618(void *arg0) {
    s32 i;
    s32 idx;
    f32 *p;
    f32 thr;

    idx = -1;
    thr = *(f32 *)((u8 *)arg0 + 0x10);
    p = (f32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0xB0);
    for (i = 0; i < 16; i++, p++) {
        if (*p <= thr) {
            if (*p > 1.0f) {
                idx = i;
            }
        }
    }
    if (idx == -1) {
        return -2;
    }
    return func_00382498(-1, idx);
}
/* localdecomp:end func_L32_003B6618 */

INCLUDE_ASM("asm/levels", func_L32_003B66A0);

INCLUDE_ASM("asm/levels", func_L32_003B6A58);
