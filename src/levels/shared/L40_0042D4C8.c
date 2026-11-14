#include "common.h"

/* localdecomp:start func_L40_0042D4C8 */
extern u8 D_L40_0039FE00[];
__asm__(".extern D_L40_00247940, 4");
__asm__(".extern D_L40_00247944, 4");
__asm__(".extern D_L40_00247948, 4");
extern s32 D_L40_00247940;
extern s32 D_L40_00247944;
extern s32 D_L40_00247948;
extern void func_L01_0039AEB8(void *, s32, s32, s32, f32, f32, f32, s32, s32);

void func_L40_0042D4C8(void) {
    func_L01_0039AEB8(D_L40_0039FE00, 0x32, 0x32, 10, 0.07f, 0.15f, 0.2f, D_L40_00247940, D_L40_00247944);
    func_L01_0039AEB8(D_L40_0039FE00 + 0xA0, 15, 15, 10, 0.03f, 0.09f, 0.2f, D_L40_00247940, D_L40_00247948);
    func_L01_0039AEB8(D_L40_0039FE00 + 0x140, 15, 15, 10, 0.03f, 0.09f, 0.2f, D_L40_00247940, D_L40_00247948);
    func_L01_0039AEB8(D_L40_0039FE00 + 0x1E0, 15, 15, 10, 0.03f, 0.09f, 0.2f, D_L40_00247940, D_L40_00247948);
}
/* localdecomp:end func_L40_0042D4C8 */

INCLUDE_ASM("asm/levels", func_L40_0042D5D8);
