#include "common.h"

/* localdecomp:start func_L24_0035A970 */
extern f32 func_L01_004395E0(void *);
extern void func_L24_003A4E60(void *, void *, s32, f32);
void func_L24_003A5360(u8 *a0, u8 *a1);

void func_L24_0035A970(void *a0, s32 a1) {
    u8 *v = *(u8 **)((u8 *)a0 + 0x68);

    if (func_L01_004395E0(a0) > 10.0f && func_L01_004395E0(a0) < 23.0f) {
        func_L24_003A4E60(v + 0x1C0, a0, a1, -9999999827968.0f);
    } else {
        func_L24_003A5360(v + 0x1C0, a0);
    }
}
/* localdecomp:end func_L24_0035A970 */

/* localdecomp:start func_L24_0035AA18 */
f32 func_L24_0035AA18(void *a0) {
    u8 *p = *(u8 **)((u8 *)a0 + 0x68);
    s32 k = *((u8 *)a0 + 0x95);

    if (k != 1) {
        if (k != 0) {
            if (k < 4) {
                return *(f32 *)(p + 0x18C);
            }
        }
    }
    return *(f32 *)(p + 0x184);
}
/* localdecomp:end func_L24_0035AA18 */

INCLUDE_ASM("asm/levels", func_L24_0035AA48);
