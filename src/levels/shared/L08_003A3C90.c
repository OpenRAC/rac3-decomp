#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_003A3C90);

/* localdecomp:start func_L08_003A3E20 */
extern s32 func_L01_00456500(u8 *, s32);

s32 func_L08_003A3E20(u8 *obj, s32 sel) {
    u8 *p = *(u8 **)(obj + 104);
    s32 id;
    if (sel != 0) {
        id = *(s32 *)(p + 752);
    } else {
        id = *(s32 *)(p + 728);
    }
    if (id != -1) {
        if (func_L01_00456500(p + 544, id) != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A3E20 */
