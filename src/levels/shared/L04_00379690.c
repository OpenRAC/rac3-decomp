#include "common.h"

/* localdecomp:start func_L04_00379690 */
void func_L04_00379690(u8 *a0) {
    a0[35] = 15;
    *(float *)(a0 + 44) = *(float *)(*(u8 **)(a0 + 36) + 36) * 1.5f;
    a0[32] = 1;
    *(float *)(a0 + 72) = 2.5f;
}
/* localdecomp:end func_L04_00379690 */

/* localdecomp:start func_L04_003796C8 */
void func_L04_003796C8(u8 *a0) {
    a0[0x20] = 2;
    a0[0x30] = 255;
}
/* localdecomp:end func_L04_003796C8 */

/* localdecomp:start func_L04_003796E0 */
s32 func_L04_003796E0(u8 *obj) {
    return (u32)(obj[32] - 2) < 2;
}
/* localdecomp:end func_L04_003796E0 */
