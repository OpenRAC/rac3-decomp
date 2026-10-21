#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003AAD60);

INCLUDE_ASM("asm/levels", func_L03_003AC868);

INCLUDE_ASM("asm/levels", func_L03_003AC998);

INCLUDE_ASM("asm/levels", func_L03_003ACAD0);

INCLUDE_ASM("asm/levels", func_L03_003ACB68);

/* localdecomp:start func_L03_003AD030 */
f32 func_L03_003AD030(f32 a, f32 b) {
    a = a + b;
    if (a < 0.0f) {
        a += 360.0f;
    } else if (359.0f < a) {
        a -= 360.0f;
    }
    return a;
}
/* localdecomp:end func_L03_003AD030 */

INCLUDE_ASM("asm/levels", func_L03_003AD098);

/* localdecomp:start func_L03_003AD510 */
extern void func_L03_003ADC48(void);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

s32 func_L03_003AD510(u8 *a0) {
    u8 *v;
    if (*(s16 *)(a0 + 170) != 6880) {
        return 0;
    }
    v = *(u8 **)(a0 + 104);
    if (*(s32 *)(v + 80) >= v[*(s32 *)(v + 44) * 32 + 522]) {
        return 0;
    }
    func_L03_003ADC48();
    func_L01_004450F0(a0, 7, -1);
    return 1;
}
/* localdecomp:end func_L03_003AD510 */

INCLUDE_ASM("asm/levels", func_L03_003AD580);

INCLUDE_ASM("asm/levels", func_L03_003AD740);
