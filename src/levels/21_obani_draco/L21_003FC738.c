#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_003FC738);

/* localdecomp:start func_L21_003FC9A8 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_001D6C24, 4");
__asm__(".extern D_001D6C28, 4");

extern void func_L21_003FC738(f32, f32, f32, void *, s32, s32, s32, s32, s32);
extern s32 D_001D6C24;
extern s32 D_001D6C28;

void func_L21_003FC9A8(void) {
    f32 k = 0.005f;

    func_L21_003FC738(-0.0005f, k, 0.1f, &D_001D6C24, 1, 5, 5, 50, 30);
    func_L21_003FC738(-0.0003f, k, 0.5f, &D_001D6C28, 0, 13, 8, 5, 30);
}
/* localdecomp:end func_L21_003FC9A8 */
