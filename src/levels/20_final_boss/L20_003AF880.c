#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003AF880);

INCLUDE_ASM("asm/levels", func_L20_003B1E58);

INCLUDE_ASM("asm/levels", func_L20_003B2200);

/* localdecomp:start func_L20_003B24B0 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00451F60(s32, s32, s32);

void func_L20_003B24B0(s32 arg0) {
    func_L01_00451F60(-1, -1, 0);
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L20_003B24B0 */

/* localdecomp:start func_L20_003B24F0 */
/* donor: rac2 func_L06_00443E18 (matched there), renamed and adapted to rac3 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L20_003B24F0(u8 *a0)
{
    u8 *s1 = *(u8 **)(a0 + 0x68);
    u32 v;

    func_0038CAD0(s1 + 0x2D0);
    func_0038CB00(s1 + 0x2D4);
    v = *(u16 *)(a0 + 0x96);
    if (v <= 0xFFFE)
        *(u16 *)(a0 + 0x96) = v + 1;
    func_L01_00451DF8(a0, s1 + 0x240, 0, 1, 2.5f);
}
/* localdecomp:end func_L20_003B24F0 */
