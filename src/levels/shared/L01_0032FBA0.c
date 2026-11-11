#include "common.h"


/* localdecomp:start func_L01_0032FBA0 */
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032FF68(void *);

void func_L01_0032FBA0(u8 *a) {
    if (((s32 (*)(s32))func_0038CAD0)(*(s32 *)(a + 104) + 68) == 0) {
        func_L01_0032FF68(a);
    }
}
/* localdecomp:end func_L01_0032FBA0 */

INCLUDE_ASM("asm/levels", func_L01_0032FBE0);

INCLUDE_ASM("asm/levels", func_L01_0032FC70);

INCLUDE_ASM("asm/levels", func_L01_0032FF68);

/* localdecomp:start func_L01_00330390 */
void func_L01_00330390(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_00330390 */

LINKER_REMNANT("asm/levels", func_L01_003303B0);

INCLUDE_ASM("asm/levels", func_L01_003303B8);

INCLUDE_ASM("asm/levels", func_L01_00330820);

INCLUDE_ASM("asm/levels", func_L01_00331230);

INCLUDE_ASM("asm/levels", func_L01_00331D28);

INCLUDE_ASM("asm/levels", func_L01_00331DD0);

INCLUDE_ASM("asm/levels", func_L01_00332160);
