#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_003930D0);

INCLUDE_ASM("asm/levels", func_L28_003941D8);

INCLUDE_ASM("asm/levels", func_L28_00394320);

INCLUDE_ASM("asm/levels", func_L28_00394618);

/* localdecomp:start func_L28_00394768 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L28_00394768(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    u16 value;

    func_0038CAD0(v + 0x32C);
    func_0038CB00(v + 0x33C);
    value = *(u16 *)(self + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(self + 0x96) = value + 1;
    }
    func_L01_00451DF8(self, v + 0x260, 3, 1, 2.5f);
}
/* localdecomp:end func_L28_00394768 */
