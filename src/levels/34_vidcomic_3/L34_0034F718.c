#include "common.h"

INCLUDE_ASM("asm/levels", func_L34_0034F718);

/* localdecomp:start func_L34_003502C8 */
extern u8 D_001A4BE0[];
extern void func_L01_003A6BB0(void *);
extern s32 func_0038CAD0(void *);
extern f32 fabsf(f32);

s32 func_L34_003502C8(u8 *a0) {
    u8 *p;
    u8 *g;

    p = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(p + 0x270) != 0
        || ((g = D_001A4BE0),
            fabsf(*(f32 *)(g + 0x338) - *(f32 *)(a0 + 0x18)) < 1.0f
            && fabsf(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10)) < *(f32 *)(p + 0x264))) {
        func_L01_003A6BB0(a0);
        return func_0038CAD0(p + 0x274) != 0;
    }
    return 0;
}
/* localdecomp:end func_L34_003502C8 */

INCLUDE_ASM("asm/levels", func_L34_00350360);

INCLUDE_ASM("asm/levels", func_L34_00350710);

INCLUDE_ASM("asm/levels", func_L34_00350768);

INCLUDE_ASM("asm/levels", func_L34_003508A8);
