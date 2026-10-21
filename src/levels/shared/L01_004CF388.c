#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004CF388);

/* localdecomp:start func_L01_004CF390 */
void func_L01_004CF390(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_L01_004CF390 */

LINKER_REMNANT("asm/levels", func_L01_004CF398);

/* localdecomp:start func_L01_004CF3A0 */
f32 func_L01_004CF3A0(u8 *a0) {
    f32 f = *(f32 *)(a0 + 24);
    *(s32 *)(a0 + 24) = 0;
    a0[40] = 1;
    return f;
}
/* localdecomp:end func_L01_004CF3A0 */
