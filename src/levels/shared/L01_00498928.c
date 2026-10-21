#include "common.h"

/* localdecomp:start func_L01_00498928 */
s32 func_L01_00498928(s32 a0, s32 a1) {
    return a1 + 0x4F0048;
}
/* localdecomp:end func_L01_00498928 */

/* localdecomp:start func_L01_00498938 */
s32 func_L01_00498938(s32 a0, s32 a1) {
    return a1 + 0x4F00A9;
}
/* localdecomp:end func_L01_00498938 */

/* localdecomp:start func_L01_00498948 */
extern u8 *func_003B9E30(u8 *a0, s32 a1, s32 a2);
void func_L01_00498948(u8 *a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < *(s32 *)(a0 + 20); i++) {
        *(s32 *)(func_003B9E30(a0, i, a1) + 64) = a2;
    }
}
/* localdecomp:end func_L01_00498948 */
