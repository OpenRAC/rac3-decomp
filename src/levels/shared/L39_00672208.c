#include "common.h"

/* declared by functions of L39_0066F948.c, which this file was cut from */
extern u8 *D_L39_00241640[];

/* localdecomp:start func_L39_00672208 */
extern u8 *D_L39_00241640[];
extern s32 func_L39_00672118(void);

s32 func_L39_00672208(void) {
    u8 *p = D_L39_00241640[0];
    s32 r = 1;
    if (p != 0) {
        s32 b = p[409];
        r = (b >> func_L39_00672118()) & 1;
    }
    return r;
}
/* localdecomp:end func_L39_00672208 */

INCLUDE_ASM("asm/levels", func_L39_00672248);
