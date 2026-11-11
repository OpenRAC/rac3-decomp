#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_00394890);

/* localdecomp:start func_L28_00394988 */
extern s32 func_L01_00456500(u8 *, s32);

s32 func_L28_00394988(u8 *obj, s32 sel) {
    u8 *p = *(u8 **)(obj + 104);
    s32 id;
    if (sel != 0) {
        id = *(s32 *)(p + 784);
    } else {
        id = *(s32 *)(p + 760);
    }
    if (id != -1) {
        if (func_L01_00456500(p + 544, id) != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L28_00394988 */
