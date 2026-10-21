#include "common.h"

/* localdecomp:start func_L03_0034AF98 */
extern s32 D_001D4CF0;
extern s32 D_001D545C;
extern void func_0039EC28(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(u8 *);
void func_L03_0034AF98(u8 *a0) {
    a0[48] = 255;
    func_0039EC28(0, D_001D4CF0);
    if (D_001D545C == 1337 || D_001D545C == 24) {
        func_L01_004450F0(a0, 1, -1);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L03_0034AF98 */

INCLUDE_ASM("asm/levels", func_L03_0034B008);
