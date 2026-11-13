#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00578D30);

/* localdecomp:start func_L39_00578DB8 */
extern s32 D_L39_0024B840[2];
extern void (*D_L39_002577D0[][16])(s32);
/* from rac4-decomp's func_0043A470 */
void func_L39_00578DB8(s32 a) {
    s32 i;
    for (i = 0; i < D_L39_0024B840[a]; i++) D_L39_002577D0[a][i](a);
    D_L39_0024B840[a] = 0;
}
/* localdecomp:end func_L39_00578DB8 */
