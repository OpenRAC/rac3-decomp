#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_006B32A8);

/* localdecomp:start func_L39_006B32B0 */
extern void func_L39_00688460(void *a0, void *p1, void *p2, void *p3, void *p4, void *p5, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);

void func_L39_006B32B0(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, v, v, v, v, v, 0.5f, 0.3f, 1.0f, 1.0f, 0.0f);
}
/* localdecomp:end func_L39_006B32B0 */

LINKER_REMNANT("asm/levels", func_L39_006B3300);

INCLUDE_ASM("asm/levels", func_L39_006B3308);

LINKER_REMNANT("asm/levels", func_L39_006B41E0);
