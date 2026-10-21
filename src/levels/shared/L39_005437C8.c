#include "common.h"

/* localdecomp:start func_L39_005437C8 */
extern s32 D_L39_001DF790;
extern void func_L39_00545498(u8 *a);
extern void func_L39_00545028(u8 *a);
extern void func_L39_0066AA50(int a, u8 *b, int c, void *d);

void func_L39_005437C8(u8 *a0)
{
    int v = *(int *)(*(u8 **)(a0 + 104) + 900);
    func_L39_00545498(a0);
    func_L39_00545028(a0);
    func_L39_0066AA50(v, a0, 6, &D_L39_001DF790);
}
/* localdecomp:end func_L39_005437C8 */

INCLUDE_ASM("asm/levels", func_L39_00543818);

INCLUDE_ASM("asm/levels", func_L39_00543AA8);

INCLUDE_ASM("asm/levels", func_L39_00544580);

INCLUDE_ASM("asm/levels", func_L39_005446C0);

INCLUDE_ASM("asm/levels", func_L39_00544DF8);

INCLUDE_ASM("asm/levels", func_L39_00545028);
