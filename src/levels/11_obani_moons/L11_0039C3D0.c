#include "common.h"

/* localdecomp:start func_L11_0039C3D0 */
typedef struct { s32 f0; u8 f4; u8 f5; } V_39C3D0;
extern s32 D_L11_001DE000[2];   /* the next $gp slot read in level 11 is 0x1DE008 */
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern void func_003C2880(void *);
extern s32 func_00382380(void *, s32, s32);

void func_L11_0039C3D0(u8 *a0)
{
    V_39C3D0 *v = *(V_39C3D0 **)(a0 + 0x68);
    u8 mask = 1 << v->f5;

    if (D_001426E0[D_L11_001DE000[v->f4]] & mask) {
        func_003C2880(a0);
        return;
    }
    if (func_00382380(D_001A4C60, v->f0, 0) != 0) {
        D_001426E0[D_L11_001DE000[v->f4]] |= mask;
    }
}
/* localdecomp:end func_L11_0039C3D0 */
