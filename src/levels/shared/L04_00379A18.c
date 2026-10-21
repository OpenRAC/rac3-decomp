#include "common.h"

/* localdecomp:start func_L04_00379A18 */
extern s32 D_L04_001DD988[2];

s32 *func_L04_00379A18(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 8;
        return D_L04_001DD988;
    }
    return 0;
}
/* localdecomp:end func_L04_00379A18 */

INCLUDE_ASM("asm/levels", func_L04_00379A38);

INCLUDE_ASM("asm/levels", func_L04_00379B28);

INCLUDE_ASM("asm/levels", func_L04_00379C68);

INCLUDE_ASM("asm/levels", func_L04_00379CC0);

INCLUDE_ASM("asm/levels", func_L04_00379D10);

INCLUDE_ASM("asm/levels", func_L04_0037A190);

/* localdecomp:start func_L04_0037A5B8 */
typedef struct {
    u8 pad[0x68];
    s32 *w68;
} Moby_003791A0;

extern void func_L01_00456230(Moby_003791A0 *, s32);

void func_L04_0037A5B8(Moby_003791A0 *m, s32 value, s32 force) {
    s32 *p = m->w68;
    if (p == 0) return;
    if (force == 0 && *p != value) return;
    *p = value;
    func_L01_00456230(m, force);
}
/* localdecomp:end func_L04_0037A5B8 */
