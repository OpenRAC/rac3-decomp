#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_003F4638);

INCLUDE_ASM("asm/levels", func_L40_003F47B0);

/* localdecomp:start func_L40_003F51A0 */
extern u8 D_L40_00249FC0[];
extern void func_L40_003F4080(u8 *, u8 *);
extern s32 func_L40_003F54B8(u8 *, u8 *, u8 *, s32, s32);
extern f32 func_L01_0040E548(u8 *, u8 *);
extern void func_L01_004472C0(u8 *);
void func_L40_003F51A0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *s0 = **(u8 ***)(a0 + 144);
    func_L40_003F4080(s0, a0);
    func_L40_003F54B8(a0, s1 + 304, s0, 0, 0);
    if (a0[49] != 0 && func_L01_0040E548(D_L40_00249FC0, a0 + 16) < 256.0f) {
        func_L01_004472C0(a0);
        a0[111] = 15;
    }
}
/* localdecomp:end func_L40_003F51A0 */

INCLUDE_ASM("asm/levels", func_L40_003F5248);

INCLUDE_ASM("asm/levels", func_L40_003F52E0);

INCLUDE_ASM("asm/levels", func_L40_003F54B8);

INCLUDE_ASM("asm/levels", func_L40_003F5880);
