#include "common.h"

/* localdecomp:start func_L20_003EE688 */
extern unsigned int D_00142C58[];
extern void func_003C2880(void *);

void func_L20_003EE688(int a0) {
    if (D_00142C58[0] & 0x2000000)
        func_003C2880((void *)a0);
}
/* localdecomp:end func_L20_003EE688 */

INCLUDE_ASM("asm/levels", func_L20_003EE6B8);

INCLUDE_ASM("asm/levels", func_L20_003EE6E8);

INCLUDE_ASM("asm/levels", func_L20_003EEB40);

INCLUDE_ASM("asm/levels", func_L20_003EF550);

INCLUDE_ASM("asm/levels", func_L20_003EFFE0);

INCLUDE_ASM("asm/levels", func_L20_003F0088);

INCLUDE_ASM("asm/levels", func_L20_003F0418);

/* localdecomp:start func_L20_003F0960 */
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

void func_L20_003F0960(u8 *p)
{
    u8 *a = *(u8 **)(p + 0x68);

    if (func_0038CAD0(a) != 0) {
        func_003C2880(p);
        return;
    }
    p[0x23] = a[0];
}
/* localdecomp:end func_L20_003F0960 */
