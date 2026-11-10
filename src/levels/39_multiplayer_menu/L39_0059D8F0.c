#include "common.h"

/* localdecomp:start func_L39_0059D8F0 */
extern s32 func_12BF88(s32, s32, s32, void *);
extern s32 func_12C190(s32);

s32 func_L39_0059D8F0(s32 a0) {
    s32 buf[2];
    s32 r = -1;

    if (a0 >= 0) {
        r = func_12BF88(a0, 0, 0, buf);
        if (r >= 0) {
            r = func_12C190(a0);
            if (r >= 0) {
                r = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_0059D8F0 */

/* localdecomp:start func_L39_0059D940 */
s32 func_0012C220();
s32 func_L39_0059D8F0(s32);

/* from rac4-decomp's func_0045F460 */
s32 func_L39_0059D940(void) {
    s32 temp_v0;
    temp_v0 = func_0012C220();
    if (temp_v0 >= 0) {
        return func_L39_0059D8F0(temp_v0);
    }
    return 0;
}
/* localdecomp:end func_L39_0059D940 */

INCLUDE_ASM("asm/levels", func_L39_0059D978);
