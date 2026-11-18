#include "common.h"

typedef void (*fn_3A2780)(u8 *);

/* localdecomp:start func_L01_003A3EC8 */

extern fn_3A2780 *func_L01_0043B548(s32, s32);
extern void func_L01_003A4810(u8 *);
extern void func_003C2880(u8 *);

void func_L01_003A3EC8(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3A2780 *tbl;
    if (*(s32 *)(pv + 576) != 0) {
        tbl = func_L01_0043B548(6625, 108);
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else if (*(s32 *)(pv + 1052) != 0) {
        func_L01_003A4810(a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003A3EC8 */

INCLUDE_ASM("asm/levels", func_L01_003A3F68);

INCLUDE_ASM("asm/levels", func_L01_003A4180);

INCLUDE_ASM("asm/levels", func_L01_003A4320);


INCLUDE_ASM("asm/levels", func_L01_003A43F8);
