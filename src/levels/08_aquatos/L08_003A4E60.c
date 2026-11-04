#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_003A4E60);

INCLUDE_ASM("asm/levels", func_L08_003A6F48);

INCLUDE_ASM("asm/levels", func_L08_003A7138);

INCLUDE_ASM("asm/levels", func_L08_003A74A8);

/* localdecomp:start func_L08_003A76C8 */
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                   f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *m, s32 a, s32 b);
extern u8 D_L08_001D66B0[8];

void func_L08_003A76C8(void *m) {
    func_L01_00452310(m, 0x1FFF, D_L08_001D66B0, 1, 0x1E, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_L01_004443E8(m, 0, 3);
}
/* localdecomp:end func_L08_003A76C8 */

INCLUDE_ASM("asm/levels", func_L08_003A7750);
