#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00597E48);

/* localdecomp:start func_L39_00597E70 */
__asm__(".extern D_L39_0024CAD0_b, 4");
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_00240408, 16");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern void *D_L39_00240408;
extern s32 func_00139D20(const void *packet);

/* from rac2-decomp's func_00284EA8 */
void func_L39_00597E70(void) {
    if (D_L39_0024CAD0 != 0) {
        D_L39_0024CAD0[0] = 0x30000009;
        D_L39_0024CAD0[1] = ((u32)D_L39_00240408 + 0x30) & 0x0FFFFFFF;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000009;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;
    } else {
        func_00139D20((void *)((u32)D_L39_00240408 + 0x30));
    }
}
/* localdecomp:end func_L39_00597E70 */
