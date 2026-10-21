#include "common.h"

/* localdecomp:start func_L01_00425198 */
typedef struct {
    u8 pad0[8];
    s16 x8;
    s16 xA;
    u16 *xC;
    s32 x10;
    u8 pad1[0x1C];
} S_1F1CC0;

extern S_1F1CC0 D_L01_001F1C40[];
extern void func_003D0A08(u16 *, u16 *, s32);

void func_L01_00425198(void) {
    S_1F1CC0 *p = D_L01_001F1C40;
    s32 i;

    for (i = 0; i < 8; i++, p++) {
        if (p->x10 != 0 && p->xC != 0) {
            u16 *a = p->xC + p->x8;
            func_003D0A08(a, a + p->xA, i);
            p->x8 = 0;
            p->xA = 0;
        }
    }
}
/* localdecomp:end func_L01_00425198 */

INCLUDE_ASM("asm/levels", func_L01_00425218);
