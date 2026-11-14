#include "common.h"

/* localdecomp:start func_L39_0050C430 */
extern void *func_L39_0050C498(void);
extern s32 func_L39_0050C338(s32, void *, s32, s32, s32, s32);

s32 func_L39_0050C430(s32 a0, s32 a1, s32 a2, s32 a3) {
    return func_L39_0050C338(0, func_L39_0050C498(), a0, a1, a2, a3);
}
/* localdecomp:end func_L39_0050C430 */

/* localdecomp:start func_L39_0050C498 */
extern u8 D_L39_0046F340[];

void *func_L39_0050C498(void) {
    return D_L39_0046F340;
}
/* localdecomp:end func_L39_0050C498 */

INCLUDE_ASM("asm/levels", func_L39_0050C4A4);
