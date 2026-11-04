#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_003BDA60);

/* localdecomp:start func_L11_003BDD28 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004C7D98(void *, void *);
extern void func_L11_003BDA60(void *, s32, void *, s32, s32, s32, s32, s32, u32, f32, f32);

void func_L11_003BDD28(u8 *self) {
    u8 buf[16];

    func_L01_004C7D98(self + 0x10, buf);
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_L11_003BDA60(self, 7, buf, 1, 0x1ED5, 1, 1, 1, 0x80302020, 1.5f, 0.6f);
    }
}
/* localdecomp:end func_L11_003BDD28 */
