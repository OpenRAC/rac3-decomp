#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_00317D28);

INCLUDE_ASM("asm/levels", func_L02_00318910);

/* localdecomp:start func_L02_003189D8 */
typedef struct { u8 p0[0x2C]; f32 f2C; } V_318528;
typedef struct { u8 p0[0x68]; V_318528 *v; } M_318528;
extern f32 D_L02_001DE2D0;
void func_L02_003189D8(M_318528 *m) {
    f32 f = m->v->f2C;
    if (f > 1.0f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    D_L02_001DE2D0 = 1.0f - f;
}
/* localdecomp:end func_L02_003189D8 */

INCLUDE_ASM("asm/levels", func_L02_00318A28);

INCLUDE_ASM("asm/levels", func_L02_00318CA8);

INCLUDE_ASM("asm/levels", func_L02_00318E78);

INCLUDE_ASM("asm/levels", func_L02_00318F28);

INCLUDE_ASM("asm/levels", func_L02_00319BB0);
