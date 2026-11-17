#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00397E90);

INCLUDE_ASM("asm/levels", func_L03_00398500);

INCLUDE_ASM("asm/levels", func_L03_00398760);

INCLUDE_ASM("asm/levels", func_L03_00398900);

INCLUDE_ASM("asm/levels", func_L03_00398A78);

INCLUDE_ASM("asm/levels", func_L03_00398BF0);

/* localdecomp:start func_L03_00398D50 */
extern void func_L03_00398DA0(u8 *, s32, s32);

void func_L03_00398D50(u8 *obj) {
    func_L03_00398DA0(obj, 0, -1);
    func_L03_00398DA0(obj, 1, 1);
    *(f32 *)(obj + 20) = 325.0f;
}
/* localdecomp:end func_L03_00398D50 */

/* localdecomp:start func_L03_00398DA0 */
void func_L03_00398DA0(u8 *a0, s32 i, s32 mode) {
    s32 k;
    u8 *b = *(u8 **)(a0 + 0x68);
    f32 *p;
    b += 0x3C0;
    p = (f32 *)((i << 7) + (s32)b);
    for (k = 0; k < 4; k++) {
        if (mode == 1) {
            *p = (f32)k * 0.0047996556f + 0.39269909f;
        } else {
            *p = (f32)k * -0.39269909f;
        }
        p += 8;
    }
}
/* localdecomp:end func_L03_00398DA0 */

INCLUDE_ASM("asm/levels", func_L03_00398E30);

INCLUDE_ASM("asm/levels", func_L03_00399010);

/* localdecomp:start func_L03_00399218 */
f32 func_L03_00399218(s32 a0, s32 a1) {
    if (a1 == 1) {
        return (f32)(a0 - 1) * -0.39269909262657166f + 0.0047996556386351585f;
    }
    return (f32)a0 * -0.39269909262657166f;
}
/* localdecomp:end func_L03_00399218 */
