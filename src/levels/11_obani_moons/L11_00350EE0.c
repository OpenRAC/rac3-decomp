#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_00350EE0);

INCLUDE_ASM("asm/levels", func_L11_003510D0);

/* localdecomp:start func_L11_003514D8 */
extern char D_001A4CC0[];
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003514D8(void) {
    func_003D9508(D_001A4CC0, 5, 0x3FFF2020, 1, 1.2f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003514D8 */

INCLUDE_ASM("asm/levels", func_L11_00351528);

/* localdecomp:start func_L11_003515E0 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L11_0034F0F0(void *, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L11_003515E0(u8 *a0) {
    if (func_L01_00447490(a0, 0x10000, 0) != 0) {
        func_L11_0034F0F0(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 2.0f, 1, 1, 0x3FFF2020);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L11_003515E0 */
