#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003AF290);

INCLUDE_ASM("asm/levels", func_L01_003B0498);

INCLUDE_ASM("asm/levels", func_L01_003B08A0);

/* localdecomp:start func_L01_003B0BD8 */
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *, s32, s32);
extern u8 D_L01_001D66B0[8];

void func_L01_003B0BD8(void *o) {
    func_L01_00452310(o, 0x1FFF, D_L01_001D66B0, 1, 25, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
    func_L01_004443E8(o, 0, 3);
}
/* localdecomp:end func_L01_003B0BD8 */

INCLUDE_ASM("asm/levels", func_L01_003B0C60);

INCLUDE_ASM("asm/levels", func_L01_003B0D48);

INCLUDE_ASM("asm/levels", func_L01_003B0E00);
