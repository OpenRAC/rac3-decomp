#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);


INCLUDE_ASM("asm/levels", func_L01_0033E0C8);

/* localdecomp:start func_L01_0033E290 */
void func_L01_0033E290(vu0_v4 *a0, s32 a1) {
    vu0_v4 t;

    vec_sub_ab(&t, &a0[a1 - 2], &a0[a1 - 3]);
    vec_add_ab(&a0[a1 - 1], &a0[a1 - 2], &t);
}
/* localdecomp:end func_L01_0033E290 */

INCLUDE_ASM("asm/levels", func_L01_0033E2D0);

LINKER_REMNANT("asm/levels", func_L01_0033E758);

INCLUDE_ASM("asm/levels", func_L01_0033E760);

LINKER_REMNANT("asm/levels", func_L01_0033ED28);

INCLUDE_ASM("asm/levels", func_L01_0033ED30);

INCLUDE_ASM("asm/levels", func_L01_0033EE50);

INCLUDE_ASM("asm/levels", func_L01_0033EF90);
