#include "common.h"

/* localdecomp:start func_L39_004B9160 */
extern s32 func_L39_004C3D20(void *, u8 *, s32);
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);

s32 func_L39_004B9160(void *arg0, u8 *arg1, s32 arg2) {
    s32 n;
    s32 r;

    for (n = arg2; n > 0; n -= r, arg1 += r) {
        r = func_L39_004C3D20(arg0, arg1, n);
        if (r < 0) {
            if (*func_L01_003E4008() == 0x71) {
                return func_L39_004B95C0(*func_L01_003E4008());
            }
            return -0x262;
        }
        if (r == 0) {
            break;
        }
    }
    return arg2 - n;
}
/* localdecomp:end func_L39_004B9160 */

INCLUDE_ASM("asm/levels", func_L39_004B9218);

INCLUDE_ASM("asm/levels", func_L39_004B92B8);

INCLUDE_ASM("asm/levels", func_L39_004B9350);

INCLUDE_ASM("asm/levels", func_L39_004B93F8);

INCLUDE_ASM("asm/levels", func_L39_004B9570);

INCLUDE_ASM("asm/levels", func_L39_004B95C0);

INCLUDE_ASM("asm/levels", func_L39_004B9640);

INCLUDE_ASM("asm/levels", func_L39_004B96D0);

INCLUDE_ASM("asm/levels", func_L39_004B9720);

INCLUDE_ASM("asm/levels", func_L39_004B9C78);

INCLUDE_ASM("asm/levels", func_L39_004B9C88);

INCLUDE_ASM("asm/levels", func_L39_004BA208);

INCLUDE_ASM("asm/levels", func_L39_004BA760);

INCLUDE_ASM("asm/levels", func_L39_004BAA78);

INCLUDE_ASM("asm/levels", func_L39_004BB1E8);

/* localdecomp:start func_L39_004BB368 */
extern s32 D_L39_00464798[];
extern s32 D_L39_00464794[];

s32 func_L39_004BB368(void) {
    s32 i;
    s32 n;

    n = D_L39_00464798[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
    n = D_L39_00464794[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
}
/* localdecomp:end func_L39_004BB368 */
