#include "common.h"

/* localdecomp:start func_L31_00346470 */
extern f32 D_001A4C60[];
extern void func_L31_003464C0(f32, f32, f32, f32, f32, f32, f32);

void func_L31_00346470(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    func_L31_003464C0(D_001A4C60[0], a, b, c, d, e, f);
}
/* localdecomp:end func_L31_00346470 */

INCLUDE_ASM("asm/levels", func_L31_003464C0);
