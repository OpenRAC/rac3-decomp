#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_003C9768);

INCLUDE_ASM("asm/levels", func_L16_003CB420);

INCLUDE_ASM("asm/levels", func_L16_003CBA28);

/* localdecomp:start func_L16_003CBBF0 */
extern s32 func_0038CAD0(void *);
extern void func_L01_0044E850(void *, void *, f32, f32, s32);
extern f32 D_001DE964;
extern f32 D_001DE968;

void func_L16_003CBBF0(u8 *a0)
{
    u8 *p = a0;
    u8 *q = *(u8 **)(p + 0x68);

    if (*(u16 *)(p + 0x96) <= 0xFFFE) {
        *(u16 *)(p + 0x96) = *(u16 *)(p + 0x96) + 1;
    }
    func_0038CAD0(q + 0x1D4);
    func_0038CAD0(q + 0x1D8);
    *(u32 *)(q + 0x1AC) += 1;
    func_0038CAD0(q + 0x1E4);
    func_L01_0044E850(p, q + 0x270, D_001DE964, D_001DE968, 6);
    func_L01_0044E850(p, q + 0x2F0, D_001DE964, D_001DE968, 7);
}
/* localdecomp:end func_L16_003CBBF0 */

INCLUDE_ASM("asm/levels", func_L16_003CBC88);

INCLUDE_ASM("asm/levels", func_L16_003CBF50);
