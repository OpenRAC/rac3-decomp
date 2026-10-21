#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00644D08);

INCLUDE_ASM("asm/levels", func_L39_006461B0);

INCLUDE_ASM("asm/levels", func_L39_00646660);

/* localdecomp:start func_L39_006468F0 */
void func_L39_006468F0(u8 *a, u8 *b) {
    if (b[66] == b[67] && b[66] >= 3 && *(s32 *)(a + 9500) == 0) {
        b[49] = 1;
        *(u16 *)(b + 52) &= 0xFFFE;
    } else {
        b[49] = 0;
        *(u16 *)(b + 52) |= 1;
    }
}
/* localdecomp:end func_L39_006468F0 */

/* localdecomp:start func_L39_00646940 */
void func_L39_00646940(u8 *a, s32 v) {
    s32 i;
    s16 *p = (s16 *)(a + 7600);
    for (i = 0; i < 2; i++) {
        if (p[i] == -1) {
            p[i] = v;
            return;
        }
    }
    *(s16 *)(a + 7602) = v;
}
/* localdecomp:end func_L39_00646940 */
