#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_003622D0);

/* localdecomp:start func_L14_003624B0 */
extern s32 func_L01_004561B8(u8 *a0);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L14_001DD828;
extern s32 D_L14_001DD82C;

s32 func_L14_003624B0(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0)) {
        *(s32 *)(a1 + 0x14) = func_00382498(D_L14_001DD828, D_L14_001DD82C);
    }
    if (func_0038CAD0(a1 + 0x14)) {
        func_L01_004450F0(a0, 2, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_003624B0 */

INCLUDE_ASM("asm/levels", func_L14_00362520);

INCLUDE_ASM("asm/levels", func_L14_00362590);

INCLUDE_ASM("asm/levels", func_L14_00362608);

INCLUDE_ASM("asm/levels", func_L14_00362868);

INCLUDE_ASM("asm/levels", func_L14_00362A50);

INCLUDE_ASM("asm/levels", func_L14_00362B68);

INCLUDE_ASM("asm/levels", func_L14_00362BF8);

INCLUDE_ASM("asm/levels", func_L14_00362C28);

INCLUDE_ASM("asm/levels", func_L14_00362D30);
